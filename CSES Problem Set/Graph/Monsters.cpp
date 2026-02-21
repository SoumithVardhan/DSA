#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<string>grid(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    
    vector<vector<int>>monster_time(n,vector<int>(m,-1));
    pair<int,int>personcordintes;
    queue<pair<int,int>>monsterq;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                personcordintes={i,j};
            }
            if(grid[i][j]=='M'){
                monster_time[i][j]=0;
                monsterq.push({i,j});
            }
        }
    }
    //Monsters time
    int xcor[] = {-1,1,0,0};
    int ycor[] = {0,0,-1,1};
    char dir[] = {'U','D','L','R'};

    while(!monsterq.empty()){
        pair<int,int>frontelemonster=monsterq.front();
        monsterq.pop();
        for(int i=0;i<4;i++){
            int currxcormonster=frontelemonster.first+xcor[i];
            int currycormonster=frontelemonster.second+ycor[i];
            int currdir=dir[i];
            if(currxcormonster<0 || currxcormonster>=n || currycormonster<0 || currycormonster>=m || grid[currxcormonster][currycormonster]=='#' || monster_time[currxcormonster][currycormonster]!=-1){
                continue;
            }
            else{
                monster_time[currxcormonster][currycormonster]=1+monster_time[frontelemonster.first][frontelemonster.second];
                monsterq.push({currxcormonster,currycormonster});
            }
        }
    }
    //Person time to reacht end corner
    queue<pair<int,int>>personq;
    vector<vector<int>>person_time(n,vector<int>(m,-1));
    pair<int,int> goal = {-1, -1};
    vector<vector<tuple<int,int,char>>>parent(n,vector<tuple<int,int,char>>(m,{-1,-1,' '}));
    if (monster_time[personcordintes.first][personcordintes.second] == 0) {
        cout << "NO\n";
        return 0;
    }

    person_time[personcordintes.first][personcordintes.second]=0;
    personq.push({personcordintes});
    while(!personq.empty()){
        pair<int,int>fronteleperson=personq.front();
        personq.pop();
        int frontelex=fronteleperson.first;
        int fronteley=fronteleperson.second;
        if (frontelex == 0 || frontelex == n-1 || fronteley == 0 || fronteley == m-1) {
            goal = {frontelex, fronteley};
            break;
        }
        for(int i=0;i<4;i++){
            int currxcorperson=fronteleperson.first+xcor[i];
            int currycorperson=fronteleperson.second+ycor[i];
            int currdir=dir[i];
            if(currxcorperson < 0 || currxcorperson >= n || 
                currycorperson < 0 || currycorperson >= m) continue;
                if(grid[currxcorperson][currycorperson] == '#') continue;
                if(person_time[currxcorperson][currycorperson] != -1) continue;
            int next_time = person_time[frontelex][fronteley] + 1;

            if(monster_time[currxcorperson][currycorperson] != -1 && 
            monster_time[currxcorperson][currycorperson] <= next_time) continue;

            person_time[currxcorperson][currycorperson] = next_time;
            personq.push({currxcorperson, currycorperson});
            parent[currxcorperson][currycorperson] = {frontelex, fronteley, dir[i]};
        }
    }

    //Path from start to end corner
    if(goal.first==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    string ans="";
    while(get<0>(parent[goal.first][goal.second])!=-1){
        auto [xpos,ypos,direction] = parent[goal.first][goal.second];
        ans+=direction;
        goal.first=xpos;
        goal.second=ypos;
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int main() {

//     int n, m;
//     cin >> n >> m;
    
//     // ── Grid Input ──
//     // Each row is read as a single string (no spaces between characters)
//     // grid[i][j] gives character at row i, column j
//     // Example: grid[1] = "#M..A..#"
//     //          grid[1][1] = 'M', grid[1][4] = 'A'
//     vector<string> grid(n);
//     for (int i = 0; i < n; i++) cin >> grid[i];
    
//     // Find player start and all monster positions
//     pair<int,int> player_start;
//     vector<pair<int,int>> monsters;
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (grid[i][j] == 'A') player_start = {i, j};
//             else if (grid[i][j] == 'M') monsters.push_back({i, j});
//         }
//     }
    
//     // Directions: Up, Down, Left, Right
//     int dr[] = {-1, 1, 0, 0};
//     int dc[] = {0, 0, -1, 1};
//     char dir_char[] = {'U', 'D', 'L', 'R'};
    
//     const int INF = INT_MAX;
    
//     // ── Step 1: Multi-source BFS from ALL monsters simultaneously ──
//     //
//     // WHY MULTI-SOURCE?
//     // All monsters move at the same time, so we start BFS from
//     // ALL monster positions at once with distance 0.
//     // monster_dist[i][j] = minimum steps for ANY monster to reach (i,j)
//     //
//     // WHY BFS GUARANTEES MINIMUM DISTANCE?
//     // BFS explores level by level:
//     //   Level 0: all monster starting positions
//     //   Level 1: all cells reachable in 1 step
//     //   Level 2: all cells reachable in 2 steps ... and so on
//     // First time a cell is visited = shortest distance (never updated again)
//     // The check (monster_dist[nr][nc] == INF) ensures we never overwrite
//     // a shorter distance with a longer one.
//     //
//     // WHY queue AND NOT deque?
//     // This is plain BFS where every edge has weight = 1 (one step)
//     // So simple queue is enough. deque is only needed for 0-1 BFS
//     // where edges have weight 0 or 1 (push_front for 0, push_back for 1)
//     // We can use deque here but queue works perfectly fine too.
//     //
//     // Rule:
//     //   All moves cost 1     → queue   (normal BFS)
//     //   Moves cost 0 or 1    → deque   (0-1 BFS)
//     //   Moves cost any value → priority_queue (Dijkstra)
//     vector<vector<int>> monster_dist(n, vector<int>(m, INF));
//     queue<pair<int,int>> mq;  // simple queue is sufficient here
    
//     for (auto [mi, mj] : monsters) {
//         monster_dist[mi][mj] = 0;
//         mq.push({mi, mj});  // all monsters start at time 0 simultaneously
//     }
    
//     while (!mq.empty()) {
//         auto [r, c] = mq.front();
//         mq.pop();
        
//         for (int d = 0; d < 4; d++) {
//             int nr = r + dr[d];
//             int nc = c + dc[d];
            
//             // Monsters walk on floor cells only (not walls)
//             // INF check ensures minimum distance is never overwritten
//             // First visit via BFS = shortest path (guaranteed)
//             if (nr >= 0 && nr < n && nc >= 0 && nc < m 
//                 && grid[nr][nc] != '#' 
//                 && monster_dist[nr][nc] == INF) {
//                 monster_dist[nr][nc] = monster_dist[r][c] + 1;
//                 mq.push({nr, nc});
//             }
//         }
//     }
    
//     // ── Step 2: BFS from player, only visiting SAFE cells ──
//     //
//     // Safe to enter cell (nr,nc) at time T only if:
//     //   monster_dist[nr][nc] > T
//     // Meaning: monster arrives STRICTLY AFTER us → safe
//     // If monster_dist == T → monster arrives same time → caught!
//     // If monster_dist <  T → monster was already there → caught!
//     vector<vector<int>> player_dist(n, vector<int>(m, INF));
    
//     // ── WHY PARENT ARRAY? ──
//     // BFS only tells us IF we can reach the goal and in HOW MANY steps.
//     // It does NOT record the actual path taken.
//     // We need parent to trace back: goal → ... → start
//     // For each cell we store: where did I come from + what direction
//     //
//     // Alternative 1: Three separate 2D arrays (simplest)
//     //   vector<vector<int>>  par_row, par_col
//     //   vector<vector<char>> par_dir
//     //
//     // Alternative 2: Only store direction (cleanest)
//     //   vector<vector<char>> par_dir
//     //   Reverse direction to find previous cell
//     //
//     // Alternative 3: tuple (used here, packs all 3 into one structure)
//     //   tuple<int,int,char> = {prev_row, prev_col, direction}
//     //
//     // Without parent: we can only say "YES/NO"
//     // With parent:    we can print the actual path
    
//     // Using 3 separate arrays (cleaner than tuple)
//     vector<vector<int>> par_row(n, vector<int>(m, -1));
//     vector<vector<int>> par_col(n, vector<int>(m, -1));
//     vector<vector<char>> par_dir(n, vector<char>(m, ' '));
    
//     auto [sr, sc] = player_start;
    
//     // If a monster already occupies start position → impossible
//     if (monster_dist[sr][sc] == 0) {
//         cout << "NO\n";
//         return 0;
//     }
    
//     player_dist[sr][sc] = 0;
//     queue<pair<int,int>> pq;  // simple queue, not deque (all edges weight 1)
//     pq.push({sr, sc});
    
//     pair<int,int> goal = {-1, -1};
    
//     while (!pq.empty()) {
//         auto [r, c] = pq.front();
//         pq.pop();
        
//         int curr_time = player_dist[r][c];
        
//         // ── BOUNDARY CHECK ──
//         // Goal = any cell on the edge of the grid
//         // row 0, row n-1 = top and bottom edges
//         // col 0, col m-1 = left and right edges
//         if (r == 0 || r == n-1 || c == 0 || c == m-1) {
//             goal = {r, c};
//             break;
//         }
        
//         for (int d = 0; d < 4; d++) {
//             int nr = r + dr[d];
//             int nc = c + dc[d];
//             int next_time = curr_time + 1;
            
//             if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
//             if (grid[nr][nc] == '#') continue;
            
//             // ── KEY SAFETY CHECK ──
//             // We arrive at (nr,nc) at next_time
//             // Monster can reach (nr,nc) in monster_dist[nr][nc] steps
//             // SAFE only if monster arrives STRICTLY AFTER us
//             if (monster_dist[nr][nc] <= next_time) continue;
            
//             // Visit each cell only once (BFS = shortest path guaranteed)
//             if (player_dist[nr][nc] == INF) {
//                 player_dist[nr][nc] = next_time;
                
//                 // ── RECORD PARENT ──
//                 // Store where we came from so we can trace path later
//                 // "I reached (nr,nc) from (r,c) using direction dir_char[d]"
//                 par_row[nr][nc] = r;
//                 par_col[nr][nc] = c;
//                 par_dir[nr][nc] = dir_char[d];
                
//                 pq.push({nr, nc});
//             }
//         }
//     }
    
//     // ── Step 3: Reconstruct path or print NO ──
//     if (goal.first == -1) {
//         cout << "NO\n";
//         return 0;
//     }
    
//     // ── PATH RECONSTRUCTION ──
//     // We trace BACKWARDS from goal → start using parent pointers
//     // Like following breadcrumbs back to where you started
//     //
//     // Example:
//     //   goal (3,7) → came from (2,7) via 'D'  → path = "D"
//     //   (2,7)      → came from (2,6) via 'R'  → path = "DR"
//     //   (2,6)      → came from (1,6) via 'D'  → path = "DRD"
//     //   (1,6)      → came from (1,5) via 'R'  → path = "DRDR"
//     //   (1,5)      → came from (1,4) via 'R'  → path = "DRDRR"
//     //   (1,4)      → par_row = -1 → this is START, stop!
//     //
//     // Since we built path backwards, reverse at the end
//     string path = "";
//     int gr = goal.first, gc = goal.second;
    
//     while (par_row[gr][gc] != -1) {  // -1 means we reached the start cell
//         path += par_dir[gr][gc];     // record direction
//         int pr = par_row[gr][gc];
//         int pc = par_col[gr][gc];
//         gr = pr;                     // move to previous cell
//         gc = pc;
//     }
    
//     // Path was built goal→start, reverse to get start→goal
//     reverse(path.begin(), path.end());
    
//     cout << "YES\n";
//     cout << path.size() << "\n";
//     cout << path << "\n";
    
//     return 0;
// }



// // Approach 2: Used dequeue and vector<vector<tuple<int,int,char>>> parent instead of 3 separate arrays.
// // Cleaner but more complex to understand at first glance. Both approaches are valid and accepted.

// // #include <bits/stdc++.h>
// // using namespace std;

// // int main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
    
// //     int n, m;
// //     cin >> n >> m;
    
// //     vector<string> grid(n);
// //     for (int i = 0; i < n; i++) cin >> grid[i];
    
// //     // Find player start and all monster positions
// //     pair<int,int> player_start;
// //     vector<pair<int,int>> monsters;
    
// //     for (int i = 0; i < n; i++) {
// //         for (int j = 0; j < m; j++) {
// //             if (grid[i][j] == 'A') player_start = {i, j};
// //             else if (grid[i][j] == 'M') monsters.push_back({i, j});
// //         }
// //     }
    
// //     // Directions: Up, Down, Left, Right
// //     int dr[] = {-1, 1, 0, 0};
// //     int dc[] = {0, 0, -1, 1};
// //     char dir_char[] = {'U', 'D', 'L', 'R'};
    
// //     const int INF = INT_MAX;
    
// //     // ── Step 1: Multi-source BFS from ALL monsters simultaneously ──
// //     // monster_dist[i][j] = min steps for any monster to reach cell (i,j)
// //     // If monster_dist[i][j] <= your arrival time → dangerous cell
// //     vector<vector<int>> monster_dist(n, vector<int>(m, INF));
// //     deque<pair<int,int>> mq;
    
// //     for (auto [mi, mj] : monsters) {
// //         monster_dist[mi][mj] = 0;
// //         mq.push_back({mi, mj});
// //     }
    
// //     while (!mq.empty()) {
// //         auto [r, c] = mq.front();
// //         mq.pop_front();
        
// //         for (int d = 0; d < 4; d++) {
// //             int nr = r + dr[d];
// //             int nc = c + dc[d];
            
// //             // Monsters can walk on floor cells only (not walls)
// //             if (nr >= 0 && nr < n && nc >= 0 && nc < m 
// //                 && grid[nr][nc] != '#' 
// //                 && monster_dist[nr][nc] == INF) {
// //                 monster_dist[nr][nc] = monster_dist[r][c] + 1;
// //                 mq.push_back({nr, nc});
// //             }
// //         }
// //     }
    
// //     // ── Step 2: BFS from player, only visiting SAFE cells ──
// //     // Safe to enter cell (nr,nc) at time T only if monster_dist[nr][nc] > T
// //     // i.e., no monster can reach it before or at the same time as us
// //     vector<vector<int>> player_dist(n, vector<int>(m, INF));
    
// //     // parent stores {prev_row, prev_col, direction_char} to reconstruct path
// //     vector<vector<tuple<int,int,char>>> parent(n, vector<tuple<int,int,char>>(m, {-1,-1,' '}));
    
// //     auto [sr, sc] = player_start;
    
// //     // If a monster is already at start (distance 0), impossible
// //     if (monster_dist[sr][sc] == 0) {
// //         cout << "NO\n";
// //         return 0;
// //     }
    
// //     player_dist[sr][sc] = 0;
// //     deque<pair<int,int>> pq;
// //     pq.push_back({sr, sc});
    
// //     pair<int,int> goal = {-1, -1};
    
// //     while (!pq.empty()) {
// //         auto [r, c] = pq.front();
// //         pq.pop_front();
        
// //         int curr_time = player_dist[r][c];
        
// //         // Check if we reached boundary
// //         if (r == 0 || r == n-1 || c == 0 || c == m-1) {
// //             goal = {r, c};
// //             break;
// //         }
        
// //         for (int d = 0; d < 4; d++) {
// //             int nr = r + dr[d];
// //             int nc = c + dc[d];
// //             int next_time = curr_time + 1;
            
// //             if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
// //             if (grid[nr][nc] == '#') continue;
            
// //             // ── KEY SAFETY CHECK ──
// //             // We arrive at next_time, monster arrives at monster_dist[nr][nc]
// //             // Safe ONLY if monster arrives STRICTLY AFTER us
// //             if (monster_dist[nr][nc] <= next_time) continue;
            
// //             // Visit each cell only once (BFS = shortest path)
// //             if (player_dist[nr][nc] == INF) {
// //                 player_dist[nr][nc] = next_time;
// //                 parent[nr][nc] = {r, c, dir_char[d]};
// //                 pq.push_back({nr, nc});
// //             }
// //         }
// //     }
    
// //     // ── Step 3: Reconstruct path or print NO ──
// //     if (goal.first == -1) {
// //         cout << "NO\n";
// //         return 0;
// //     }
    
// //     // Trace back from goal → start using parent pointers
// //     string path = "";
// //     auto [gr, gc] = goal;
// //     while (get<0>(parent[gr][gc]) != -1) {
// //         auto [pr, pc, ch] = parent[gr][gc];
// //         path += ch;
// //         gr = pr;
// //         gc = pc;
// //     }
    
// //     // Path was built backwards, reverse it
// //     reverse(path.begin(), path.end());
    
// //     cout << "YES\n";
// //     cout << path.size() << "\n";
// //     cout << path << "\n";
    
// //     return 0;
// // }
