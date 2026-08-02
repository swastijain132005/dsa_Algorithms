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

//detect cycle in an undirected graph using dfs
//leetcode 1559 do implement not just see code
(agar koi node vis hai aur parent bhi nhi h to wo back edge form karega ,hence cycle exists)
class Solution {
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;

        for (int neigh : adj[node]) {

            if (!vis[neigh]) {
                if (dfs(neigh, node, adj, vis))
                    return true;
            }
            else if (neigh != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

//for directed graph 

class Solution {
public:
    bool dfs(int node, vector<int> adj[],
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int neigh : adj[node]) {

            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[neigh]) {
                return true;
            }
        }

        pathVis[node] = 0;   // Backtracking
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};



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
lc 3996

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

//detect cycle in undirected graph using bfs


class Solution {
public:
    bool bfs(int src, vector<int> adj[], vector<int>& vis) {

        queue<pair<int, int>> q;   // {node, parent}

        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty()) {

            auto [node, parent] = q.front();
            q.pop();

            for (int neigh : adj[node]) {

                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push({neigh, node});
                }
                else if (neigh != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

//0-1 bfs tc o(v+e) 

deque<int> dq;

    vector<int> dist(n, 1e9);

    dist[src] = 0;

    dq.push_front(src);

    while(!dq.empty()) {

        int node = dq.front();
        dq.pop_front();

        for(auto [adjNode, wt] : adj[node]) {
            if(wt<=maxi){
                wt=0;
            }
            else{
                wt=1;
            }

            if(dist[node] + wt < dist[adjNode]) {

                dist[adjNode] = dist[node] + wt;

                if(wt == 0) {
                    dq.push_front(adjNode);
                }
                else {
                    dq.push_back(adjNode);
                }
            }
        }
    }
    if (dist[target]<=k){
        return true;
    }
    return false;
}


Topological sorting (directed acyclic graph)
First childs then me in stack
multiple topo sorts are possible 
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
//jiska indegree jitna kam hoga wo utna pehle aaega 
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
lc 4003(dijkstra based)
Dijkstra algorithm
#include <bits/stdc++.h>
using namespace std;
O((V+E)logV)

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

if we have to also find no. of ways to dest using shortes dist make another ways array just like dist array ,initialize with 0 ways[src]=1;
and if we d+w==dist[v]  ways[v]=(ways[u]+ways[v])%mod; lc 1976

O((V+E)logV)

    The set version of Dijkstra is used when you want to efficiently update the shortest distance of a node by removing its old entry and inserting the new one. It uses a balanced BST (std::set) instead of a priority queue.

    class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int S) {

        vector<int> dist(V, INT_MAX);

        set<pair<int,int>> st;

        dist[S] = 0;
        st.insert({0, S});

        while (!st.empty()) {

            auto it = *st.begin();
            st.erase(st.begin());

            int dis = it.first;
            int node = it.second;

            for (auto &edge : adj[node]) {

                int adjNode = edge.first;
                int wt = edge.second;

                if (dis + wt < dist[adjNode]) {

                    if (dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + wt;

                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
Bellman ford algorithm
//used for finding shortest path from source to all vertices in graph 
(Works with negative edge weights also)//Helps in detecting neg cycle
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            //relaxation should be done in order in which edges are given 

            if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
//v-1 times relax karne ke baad bhi relax ho raha hai then neg cycle present 
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

for (int i = 0; i < n; i++) {
    if (dist[i][i] < 0) {
        cout << "Negative Cycle Exists\n";
        return;
    }
}

cout << "No Negative Cycle\n";
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


class Solution {
public:

    int prims(int V, vector<vector<pair<int,int>>>& adj) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> mst(V, false);

        key[0] = 0;
        pq.push({0, 0});   // {key,node}

        while(!pq.empty()) {

            int node = pq.top().second;
            pq.pop();

            if(mst[node]) continue;

            mst[node] = true;

            for(auto &edge : adj[node]) {

                int adjNode = edge.first;
                int wt = edge.second;

                if(!mst[adjNode] && wt < key[adjNode]) {

                    key[adjNode] = wt;
                    parent[adjNode] = node;

                    pq.push({key[adjNode], adjNode});
                }
            }
        }

        int sum = 0;

        cout << "Edges in MST:\n";
        for(int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i
                 << " (wt = " << key[i] << ")\n";
            sum += key[i];
        }

        return sum;
    }
};

(disjoints sets have their intersaction as null)
operations -combine two given sets,test if two members belong to same set or not 


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
    int findParent(int node,vector<int>&parent) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node],parent); // path compression
    }
//agar do ko merge kar rahe hai aur dono ka rank same hai to kisi ek ko parent bana do aur parent ke rank ko badha do 
//in case of different rank the one have higher rank will become parent 
//if not then it will form skewed tree leading to inc in tc 
    void unionByRank(int u, int v,vector<int>&parent,vector<int>&rank) {
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);
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


class DSU {
public:
    vector<int> parent, size;

    // Constructor
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        // Initially every node is its own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find ultimate parent
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]); // Path Compression
    }

    // Union by Size
    void Union(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        // Already in same component
        if (pu == pv) return;

        // Attach smaller tree to larger tree
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

//no. of islands 2


class Solution {
public:

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        DSU ds(n * m);

        // Keeps track of which cells are land
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> ans;

        int islands = 0;

        // 4 Directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (auto it : operators) {

            int row = it[0];
            int col = it[1];

            // If already land, answer remains same
            if (vis[row][col]) {
                ans.push_back(islands);
                continue;
            }

            // Make this cell land
            vis[row][col] = 1;
            islands++;

            // Convert current cell to node number
            int node = row * m + col;

            // Check all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                // Ignore invalid cells
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Ignore water cells
                if (vis[nr][nc] == 0)
                    continue;

                // Convert neighbour to node number
                int adjNode = nr * m + nc;

                // If they belong to different islands
                if (ds.findParent(node) != ds.findParent(adjNode)) {

                    // Merge them
                    ds.Union(node, adjNode);

                    // Two islands become one
                    islands--;
                }
            }

            ans.push_back(islands);
        }

        return ans;
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


//how to find the given subset of nodes is connected graph or not

class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             unordered_set<int>& nodes,
             unordered_set<int>& vis) {

        vis.insert(node);

        for(auto nei : adj[node]) {

            if(nodes.count(nei) && !vis.count(nei)) {
                dfs(nei, adj, nodes, vis);
            }
        }
    }

    bool isConnectedSubset(vector<vector<int>>& adj,
                           vector<int>& subset) {

        unordered_set<int> nodes(subset.begin(),
                                 subset.end());

        unordered_set<int> vis;

        dfs(subset[0], adj, nodes, vis);

        return vis.size() == subset.size();
    }
};
