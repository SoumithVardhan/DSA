#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// TIME COMPLEXITY: O(N + M)
// - We visit every node once → O(N)
// - We visit every edge once (both directions) → O(M)
// - Total → O(N + M)

// SPACE COMPLEXITY: O(N + M)
// - ngb (adjacency list) → O(N + M)  [N lists, M total edges stored]
// - ans array → O(N)
// - visited implicitly via ans → O(1) extra
// - queue at most holds N nodes → O(N)
// - Total → O(N + M)

void bfs(vector<vector<int> >&ngb,queue<int>&q,bool &possible,vector<int>&ans){
    while(!q.empty() && possible){
        int node = q.front();
        q.pop();

        for(int nb : ngb[node]){
            if(ans[nb] == 0){
                ans[nb] = (ans[node] == 1) ? 2 : 1;
                q.push(nb);
            } else if(ans[nb] == ans[node]){
                // neighbor has same color → odd cycle(bipartite) → impossible
                // Imagine coloring nodes as you walk around a cycle, alternating colors:

                // R B R B R B...

                // If cycle has EVEN nodes (say 4):
                // R B R B → last(B) connects back to first(R) ✓ different, no problem

                // If cycle has ODD nodes (say 3):
                // R B R → last(R) connects back to first(R) ✗ same color, IMPOSSIBLE

                // Thats it. Odd cycle always forces two neighbors to share the same color.
                possible = false;
                break;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > ngb(n + 1);
    
    while(m--){
        int a, b;
        cin >> a >> b;
        ngb[a].push_back(b);
        ngb[b].push_back(a); 
    }

    vector<int> ans(n + 1, 0);
    bool possible = true;

    for(int i = 1; i <= n && possible; i++){
        // So checking ans[nb] == 0 is same as checking visited[nb] == false.
        // No need for a separate visited array.
        if(ans[i] != 0) continue;

        queue<int> q;
        q.push(i);
        ans[i] = 1;

        bfs(ngb,q,possible,ans);
    }

    if(!possible){
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i = 1; i <= n; i++){
            cout << ans[i];
            if(i < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}