Graphs
Dfs
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis);
        }
    }
}

int main() {
    int n = 5;  // number of nodes
    vector<int> adj[n];

    // Example edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    vector<int> vis(n, 0);

    dfs(0, adj, vis);  // Start DFS from node 0
}
Dfs iterative
void dfsIterative(int start, vector<int> adj[], int n) {
    vector<int> vis(n, 0);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (vis[node]) continue;

        vis[node] = 1;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

Bfs
#include <bits/stdc++.h>
using namespace std;
//For distance start to target , make queue of pair , second one for distance , in pushstep put dist

void bfs(int start, vector<int> adj[], int n) {
    vector<int> vis(n, 0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5;
    vector<int> adj[n];

    // Undirected edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    bfs(0, adj, n);
}

Topological sorting (directed acyclic graph)
First childs then me in stack
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs(v, adj, visited, st);
        }
    }

    // push after visiting all neighbours
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}
Kahns algorithm (topo sort using bfs)
//Topo sort ke questions me jo bhi diya hai pehle usse adjacency list banana hi hoga
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    // Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}
Cycle detection in a directed graph using bfs
Count the total no. Of processed nodes ,while pushing in the result  ,if it is less than total nodes at last then cycle exists .
Dijkstra algorithm
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int source) {
 
    // Min heap -> {distance, node}
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
 
    vector<int> dist(V, INT_MAX);
 
    dist[source] = 0;
    pq.push({0, source});
 
    while(!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;
 
            if(currDist + weight < dist[adjNode]) {
                dist[adjNode] = currDist + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
 
    return dist;
}
Bellman ford algorithm
(Works with negative edge weights also)//Helps in detecting neg cycle
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check negative cycle
    for(auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
            return {-1}; // negative cycle
        }
    }

    return dist;
}
Floyd warshall(all pairs shortest path )
void floydWarshall(vector<vector<int>>& dist, int n) {

    for(int k = 0; k < n; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;

                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
            }
        }
    }
}
Prims algorithm
#include <bits/stdc++.h>using namespace std;
int prims(int V, vector<vector<pair<int,int>>>& adj) {
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<int> vis(V, 0);
pq.push({0,0}); // {weight,node}
int sum = 0;
while(!pq.empty())
{ auto it = pq.top();
pq.pop();
int wt = it.first;
int node = it.second;
if(vis[node]) continue;
vis[node] = 1;
sum += wt;
for(auto &edge : adj[node])
{ int adjNode = edge.first;
int edgeWt = edge.second;
if(!vis[adjNode])
{ pq.push({edgeWt, adjNode}); } }}
return sum;
}

Dsu by rank and path compression
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }
    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if(rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if(rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }
};
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if(rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }
};
Dsu by size and path compression
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
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
Kosarajus algorithm for strongly connected components
class Solution {
public:

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st){
    vis[node] = true;

    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr, adj, vis, st);
        }
    }

    st.push(node); // store finishing order
}

void dfs2(int node, vector<vector<int>>& transpose, vector<bool>& vis){
    vis[node] = true;

    for(auto nbr : transpose[node]){
        if(!vis[nbr]){
            dfs2(nbr, transpose, vis);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    stack<int> st;
    vector<bool> vis(V,false);

    // Step 1: DFS and push nodes to stack
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    // Step 2: Transpose graph
    vector<vector<int>> transpose(V);

    for(int i=0;i<V;i++){
        vis[i] = false;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    // Step 3: DFS using stack order
    int count = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!vis[node]){
            dfs2(node,transpose,vis);
            count++;
        }
    }

    return count;
}
};
