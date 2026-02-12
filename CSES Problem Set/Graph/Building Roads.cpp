#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>

using namespace std;

// ============================================================
// ADJACENCY MATRIX vs ADJACENCY LIST — Quick Reference
// ============================================================

// ADJACENCY MATRIX — stores ALL pairs (even non-edges)
// vector<vector<int>> path(n, vector<int>(n, 0));
//
// Example: 4 cities, edges: 1-2, 3-4
//      1  2  3  4
//  1 [ 0, 1, 0, 0 ]
//  2 [ 1, 0, 0, 0 ]
//  3 [ 0, 0, 0, 1 ]
//  4 [ 0, 0, 1, 0 ]
//
// Space: O(n^2)
// n = 100,000 → 10^10 entries → ~40 GB → CRASH!
// Use when: n is small (< 1000)

// ============================================================

// ADJACENCY LIST — stores ONLY actual edges
// vector<vector<int>> adj(n + 1);
//
// Example: 4 cities, edges: 1-2, 3-4
//  adj[1] → [2]
//  adj[2] → [1]
//  adj[3] → [4]
//  adj[4] → [3]
//
// Space: O(n + 2*m)    (each edge stored twice)
// n = 100,000, m = 200,000 → ~500,000 entries → ~2 MB → FITS!
// Use when: n is large, m is much less than n^2


// My shitty approach initally
// This stores every thing 
// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int> >v(m,vector<int>(2));
//     vector<vector<int> >path(n,vector<int>(n,0));
//     for(int i=0;i<m;i++){
//         cin>>v[i][0]>>v[i][1];
//         int ele1=v[i][0];
//         int ele2=v[i][1];
//         path[ele1][ele2]=1;
//         path[ele2][ele1]=1;
//     }
//     vector<pair<int,int> >res;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(i!=j && path[i][j]==0){
//                 pair<int,int>res1=make_pair(i,j);
//                 res.push_back(res1);
//             }
//         }
//     }
//     cout<<res.size()<<endl;
//     for(int i=0;i<res.size();i++){
//         cout<<res[i].first<<" "<<res[i].second;
//     }cout<<endl;
    
//     return 0;
// }


// Using DFS? really
// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
//     int n, m;
//     scanf("%d %d", &n, &m);
//     vector<vector<int> > adj(n + 1);
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     vector<bool> visited(n + 1, false);
//     vector<int> comp_roots;

//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             comp_roots.push_back(i);
//             // iterative DFS
//             stack<int> st;
//             st.push(i);
//             visited[i] = true;
//             while (!st.empty()) {
//                 int u = st.top(); st.pop();
//                 for (int v : adj[u]) {
//                     if (!visited[v]) {
//                         visited[v] = true;
//                         st.push(v);
//                     }
//                 }
//             }
//         }
//     }

//     printf("%d\n", (int)comp_roots.size() - 1);
//     for (int i = 1; i < (int)comp_roots.size(); i++)
//         printf("%d %d\n", comp_roots[i - 1], comp_roots[i]);
// }



// // My Approach Using (BFS? really)
// // Here BFS and DFS both approaches explore all the nodes
// void bfs(vector<bool>&visited,vector<vector<int> >&v,int m,int n,int i){
//     queue<int>q;
//     q.push(i);
//     visited[i]=true;
//     while(!q.empty()){
//         int frontele=q.front();
//         q.pop();
//         for(auto ngb:v[frontele]){
//             if(visited[ngb]==true)continue;
//             q.push(ngb);
//             visited[ngb]=true;
//         }
//     }
// }
// int main(){
//     int n,m;cin>>n>>m;
//     vector<vector<int> >v(n+1);
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
 
//     vector<bool>visited(n+1,false);
//     int cnt=0;
//     vector<int>ans;
//     for(int i=1;i<=n;i++){
//         if(visited[i]==true)continue;
//         cnt++;
//         ans.push_back(i);
//         bfs(visited,v,m,n,i);
//     }
//     cout<<cnt-1<<endl;
//     for(int i=1;i<ans.size();i++){
//         cout<<ans[i-1]<<" "<<ans[i]<<endl;
//     }cout<<endl;

// }





// Using Union and Find by Rank
// Disjoint Set Union / DSU
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ds.unionByRank(a, b);
    }

    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (ds.findUPar(i) == i) roots.push_back(i);
    }

    cout << (int)roots.size() - 1 << endl;
    for (int i = 1; i < (int)roots.size(); i++) {
        cout << roots[i - 1] << " " << roots[i] << endl;
    }

    return 0;
}