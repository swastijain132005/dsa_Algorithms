//tarjans algorithm for finding bridges in undirected graph

class Solution {
public:

void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node]=min(low[node],low[nbr]);
            //check edge is bridge
            if(low[nbr]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);

            }
        }
        else{
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }

    }
}
Tarjans algorithm
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
                  }
                  int timer=0;
                  vector<int>disc(n);
                  vector<int>low(n);

                  int parent=-1;
                  unordered_map<int,bool>vis;
                  for(int i=0;i<n;i++){
                    disc[i]=-1;
                    low[i]=-1;
                  }

                  vector<vector<int>>result;
                  for(int i=0;i<n;i++){
                    if(!vis[i]){
                        dfs(i,parent,timer,disc,low,result,adj,vis);
                    }
                  }
                  return result;


 

 
    }
};

//Tarjans algorithm for finding articulation points 

A node is an articulation point if removing that node (and its edges) increases the number of connected components.

class Solution {
public:

void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,
         unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis,
         vector<bool>&ap){

    vis[node]=true;
    disc[node]=low[node]=timer++;

    int child=0;

    for(auto nbr:adj[node]){

        if(nbr==parent){
            continue;
        }

        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,adj,vis,ap);

            low[node]=min(low[node],low[nbr]);

            // articulation condition
            if(parent!=-1 && low[nbr] >= disc[node]){
                ap[node]=true;
            }

            child++;
        }
        else{
            // back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }

    // root node condition
    if(parent==-1 && child>1){
        ap[node]=true;
    }
}

vector<int> articulationPoints(int n, vector<vector<int>>& connections){

    unordered_map<int,list<int>> adj;

    for(int i=0;i<connections.size();i++){
        int u=connections[i][0];
        int v=connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;

    vector<int> disc(n,-1);
    vector<int> low(n,-1);

    unordered_map<int,bool> vis;

    vector<bool> ap(n,false);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,timer,disc,low,adj,vis,ap);
        }
    }

    vector<int> result;

    for(int i=0;i<n;i++){
        if(ap[i]){
            result.push_back(i);
        }
    }

    return result;
}
};
