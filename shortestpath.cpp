How is DAG Shortest Path different from Dijkstra?
Graph
DAG Shortest Path → works only on Directed Acyclic Graphs (DAGs).
Dijkstra → works on general graphs, including graphs with cycles.
Main technique
DAG Shortest Path → uses Topological Sort + Relaxation.
Dijkstra → uses a Priority Queue (Min Heap) + Relaxation.
Negative weights
DAG Shortest Path → can handle negative edge weights as long as there is no cycle.
Dijkstra → cannot handle negative edge weights correctly.
Time Complexity
DAG Shortest Path → O(V + E).
Dijkstra → O((V + E) log V) using a priority queue.
Why DAG is faster
In a DAG, topological order tells us exactly when to process each node.
So each node/edge is essentially processed once.
Dijkstra needs a min heap to repeatedly find the currently closest node.
Interview shortcut

When you see:

"Shortest path in a weighted DAG"

Immediately think:

Topological Sort → Relax Edges → Shortest Path

Whereas:

"Shortest path in a weighted graph with non-negative weights"

Think:

Dijkstra → Min Heap → Relax Edges.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void topoSort(int node, vector<pair<int,int>> adj[],
                  vector<int>& vis, stack<int>& st) {
        
        vis[node] = 1;

        for (auto it : adj[node]) {
            int v = it.first;

            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }

        st.push(node);
    }

public:

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {

        // 1. Create adjacency list
        vector<pair<int,int>> adj[N];

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // 2. Topological Sort
        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // 3. Initialize distances
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // 4. Process nodes in topological order
        while (!st.empty()) {

            int node = st.top();
            st.pop();

            // If node is unreachable, don't process it
            if (dist[node] == 1e9)
                continue;

            for (auto it : adj[node]) {

                int v = it.first;
                int wt = it.second;

                // Relaxation
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        // 5. Convert unreachable nodes to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
  
