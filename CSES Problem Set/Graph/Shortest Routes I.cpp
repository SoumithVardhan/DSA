#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

/*
 * DIJKSTRA'S ALGORITHM - Shortest Path from Single Source
 * 
 * INTUITION:
 * - Greedy approach: Always explore the closest unvisited node first
 * - Like a "spreading wave" from source - closer nodes are guaranteed optimal before farther ones
 * - Once a node is processed, we've found its shortest path (no future path can be shorter)
 * 
 * APPROACH:
 * 1. Initialize: Set source distance = 0, all others = ∞
 * 2. Use min-heap (priority queue) to always get the node with smallest distance
 * 3. For each node, "relax" its neighbors:
 *    - If new path (current + edge weight) is shorter than known path, update it
 * 4. Skip outdated entries in PQ (when we already found a better path)
 * 5. Repeat until all reachable nodes are processed
 * 
 * KEY INSIGHTS:
 * - PQ stores: {distance, node} - sorted by distance
 * - Adjacency list stores: {neighbor_node, edge_weight}
 * - Relaxation: if (dist[u] + weight < dist[v]) → update dist[v]
 * - Multiple PQ entries for same node are possible (keep only best via skip check)
 * 
 * WHY IT WORKS:
 * - Greedy choice is safe: processing closest node first guarantees it's optimal
 * - All paths to farther nodes must go through closer nodes (or be longer)
 * 
 * IMPORTANT - INITIALIZATION:
 * - MUST use LLONG_MAX (not INT_MAX) for long long distance arrays
 * - INT_MAX = 2×10^9, LLONG_MAX = 9×10^18
 * - Edge weights up to 10^9 with multiple edges can exceed INT_MAX
 * - Rule: int variable → INT_MAX, long long variable → LLONG_MAX
 * 
 * TIME COMPLEXITY: O((N + M) log N)
 * - Each edge relaxed once: O(M)
 * - Each relaxation involves PQ operation: O(log N)
 * - Each node extracted from PQ once: O(N log N)
 * 
 * SPACE COMPLEXITY: O(N + M)
 * - Adjacency list: O(N + M)
 * - Distance array: O(N)
 * - Priority queue: O(N) in worst case
 * 
 * USE CASES:
 * - Single-source shortest path in weighted graphs
 * - Non-negative edge weights only (use Bellman-Ford for negative weights)
 */

int main(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,long long> > >adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        long long w;cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back(make_pair(v,w));
    }
    vector<long long>dist(n, LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >pq;
    dist[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        pair<long long,int>currtop=pq.top();
        pq.pop();
        
        int currnode=currtop.second;
        long long currnodedist=currtop.first;

        if(currnodedist > dist[currnode]) continue;

        for(int i=0;i<adj[currnode].size();i++){
            pair<int,long long> adj_to_currnode_ele=adj[currnode][i];
            int besidenode_ele=adj_to_currnode_ele.first;
            long long besidenode_ele_dist=adj_to_currnode_ele.second;

            if(besidenode_ele_dist+currnodedist<dist[besidenode_ele]){
                dist[besidenode_ele] = besidenode_ele_dist + currnodedist;
                pq.push(make_pair(dist[besidenode_ele], besidenode_ele));  
            }
        }
    }

    for(int i=0;i<dist.size();i++){
        cout<<dist[i];
        if(i<n-1)cout<<" ";
    }cout<<endl;
}