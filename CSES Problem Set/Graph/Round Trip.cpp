#include <iostream>
#include <vector>
using namespace std;

// WHAT THIS FUNCTION DOES:
// DFS from 'node', tracking current path
// If cycle found, store it in 'ans' and return true
// If no cycle, backtrack (pop_back) and return false

bool dfs(int node, int par, vector<vector<int> >& ngb,
         vector<bool>& visited, vector<int>& path, vector<int>& ans) {
    
    // mark current node visited
    // add to current active path
    // eg: visiting node 1 → path = [1]
    visited[node] = true;
    path.push_back(node);
    
    for(int nbr : ngb[node]) {
        
        if(!visited[nbr]) {
            // neighbour not visited → go deeper
            // eg: from 1, go to 3 → path becomes [1, 3]
            if(dfs(nbr, node, ngb, visited, path, ans))
                return true; // cycle found deeper, bubble up immediately
        }
        
        else if(nbr != par) {
            // neighbour is visited AND not our parent
            // this means we found a BACK EDGE = CYCLE!
            
            // eg: path = [1, 3, 5], we are at node 5
            //     neighbour 1 is visited and 1 != par(3)
            //     so cycle exists between 1 and 5
            
            // STEP 1: find where cycle starts in path
            // eg: find index of node 1 in [1, 3, 5] → idx = 0
            int idx = 0;
            for(int i = 0; i < (int)path.size(); i++) {
                if(path[i] == nbr) { idx = i; break; }
            }
            
            // STEP 2: slice path from idx to end
            // eg: path[0..2] = [1, 3, 5] → ans = [1, 3, 5]
            // why slice? path could be [2, 7, 1, 3, 5]
            // cycle is only [1, 3, 5], not the nodes before 1
            for(int i = idx; i < (int)path.size(); i++)
                ans.push_back(path[i]);
            
            // STEP 3: close the round trip by appending start node again
            // eg: ans = [1, 3, 5] → append 1 → ans = [1, 3, 5, 1]
            // this satisfies the problem: start and end at same city
            ans.push_back(nbr);
            
            return true;
        }
        
        // NOTE: if nbr == par, we simply skip it
        // eg: at node 3, parent is 1, neighbour 1 appears again
        // that is just the undirected edge going back, NOT a cycle
    }
    
    // BACKTRACK: no cycle found from this node
    // remove current node from path so path stays clean
    // eg: path = [1, 2, 3], node 3 is dead end
    //     pop → path = [1, 2]
    //     now when we explore next branch from 1, path is correct
    // WITHOUT pop_back: path = [1, 2, 3, 4, 5] (stale nodes)
    // WITH pop_back:    path = [1, 4, 5]        (correct!)
    path.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // build adjacency list
    // eg: edge 1-3 → ngb[1]=[3], ngb[3]=[1]
    vector<vector<int> > ngb(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ngb[a].push_back(b);
        ngb[b].push_back(a);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> path, ans;
    
    // try DFS from every unvisited node
    // needed because graph might be disconnected
    // eg: nodes 1-3 form one component, nodes 4-5 another
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, ngb, visited, path, ans))
                break; // cycle found, stop searching
        }
    }
    
    if(ans.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        // ans = [1, 3, 5, 1]
        // size = 4, print 4 then the path
        cout << ans.size() << "\n";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}

// If after DFS you wanted to reconstruct the path from parent to child for every node. 
// But in our case we already have the path array doing that job.
// So we replaced parent array with just a single integer passed in recursion. Cleaner and simpler!