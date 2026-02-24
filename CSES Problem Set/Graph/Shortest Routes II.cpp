#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

/*
 * FLOYD-WARSHALL ALGORITHM - All-Pairs Shortest Path
 * 
 * INTUITION:
 * - Dynamic programming approach
 * - Try all intermediate nodes k between every pair (i, j)
 * - If path i → k → j is shorter than direct i → j, update it
 * 
 * APPROACH:
 * 1. Initialize: dist[i][j] = edge weight if edge exists, else ∞
 * 2. For each intermediate node k (1 to n):
 *      For each source i (1 to n):
 *        For each destination j (1 to n):
 *          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 * 3. After all iterations, dist[i][j] = shortest path from i to j
 * 
 * WHY IT WORKS:
 * - Considers all possible paths through intermediate nodes
 * - Order of k matters: by processing k=1,2,3... we build paths incrementally
 * - After k iterations, dist[i][j] = shortest path using nodes {1,2,...,k}
 * 
 * TIME: O(N³) - Triple nested loop
 * SPACE: O(N²) - Distance matrix
 * 
 * WHEN TO USE:
 * - N is small (typically ≤ 500)
 * - Need all-pairs shortest paths
 * - Many queries (precompute once, query in O(1))
 * - Can handle negative weights (but not negative cycles)
 */

int main(){
    int n,m;
    long long q;
    cin>>n>>m>>q;

    vector<vector<long long> >vec(n,vector<long long>(n,LLONG_MAX));

    for(int i = 0; i < n; i++){
        vec[i][i] = 0;
    }

    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        u--;v--;
        vec[u][v] = min(vec[u][v], w);
        vec[v][u] = min(vec[v][u], w);
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vec[i][k]!=LLONG_MAX && vec[k][j]!=LLONG_MAX){
                    vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        if(vec[u][v]==LLONG_MAX){
            cout<<-1;
        }
        else{
            cout<<vec[u][v];
        }
        if(i<q-1)cout<<endl;
    }
        



}