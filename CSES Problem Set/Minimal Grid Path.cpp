#include<iostream>
#include<vector>
using namespace std;


//Mistake in this approach :

// Example Trace (2x2 grid):
// A B
// C D
// Execution Flow:

// Call 1: solve(0, 0, "", ...)

// Calls solve(1, 0, "A", ...) → returns "ACD"
// Calls solve(0, 1, "A", ...) → returns "ABD"
// Stores dp[0][0] = min("ACD", "ABD") = "ABD" ✓


// Later in recursion: solve(0, 1, "A", ...)

// Checks: dp[0][1] != "" ?
// Let's say dp[0][1] was already computed as "BD" from a different path
// Returns "BD" (from cache)
// But wait! You wanted "A" + "BD" = "ABD", not just "BD"!


// string solve(vector<vector<char> >&grid, int n, int x, int y, string path,vector<vector<string> >&dp,vector<string>&ans){
//    if(x>=n || y>=n){
//        return "";
//    }
//    if(dp[x][y]!=""){
//        return dp[x][y];
//    }
//    if(x==n-1 && y==n-1){
//         path+=grid[x][y];
//         ans.push_back(path);
//         return path;
//    }
//    string down=solve(grid,n,x+1,y,path+grid[x][y],dp,ans);
//    string right=solve(grid,n,x,y+1,path+grid[x][y],dp,ans);
//    if(down=="" ) return right;
//    if(right=="") return down;
//    return dp[x][y]=min(down,right);

// }


string solverec(vector<vector<char> >&grid, int n, int x, int y, string path){
   if(x>=n || y>=n){
       return "";
   }
   if(x==n-1 && y==n-1){
        path+=grid[x][y];
        return path;
   }
   string down=solverec(grid,n,x+1,y,path+grid[x][y]);
   string right=solverec(grid,n,x,y+1,path+grid[x][y]);
 
   if(down=="" ) return right;
   if(right=="") return down;
   return min(down,right);
 

}
string solvememo(vector<vector<char> >& grid, int n, int x, int y, vector<vector<string> >& dp) {
    if(x >= n || y >= n) {
        return "~"; 
    }
    
    if(dp[x][y] != "") {
        return dp[x][y];
    }
    
    if(x == n-1 && y == n-1) {
        return dp[x][y] = string(1, grid[x][y]);
    }
    
    string down = grid[x][y]+solvememo(grid, n, x+1, y, dp);
    string right = grid[x][y]+solvememo(grid, n, x, y+1, dp);
    
    return dp[x][y] =  min(down, right);
}

//Got run time error due to memory limit exceeded 
//When n = 3000:

// You have 3000 × 3000 = 9,000,000 cells
// Each cell stores a string of average length ~3000 characters
// Total memory: 9,000,000 × 3000 = 27 billion characters
// That's approximately 27 GB of memory!

// The memory limit is only 512 MB.
// Tabulation
string solvetab(vector<vector<char> >& grid, int n) {
    
    vector<vector<string> >dp(n,vector<string>(n,""));

    dp[0][0]=string(1,grid[0][0]);

    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    
    return dp[n-1][n-1];
}

// Opt Tabulation - Still O(n^3) due to string operations
string solvetabopt(vector<vector<char> >& grid, int n) {
    vector<string> dp(n, "");

    dp[0] = string(1, grid[0][0]);
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + grid[0][i];
    }

    for(int i = 1; i < n; i++) {
        dp[0] = dp[0] + grid[i][0];
        for(int j = 1; j < n; j++) {
            string from_top = dp[j] + grid[i][j];
            string from_left = dp[j-1] + grid[i][j];
            dp[j] = min(from_top, from_left);
        }
    }

    return dp[n-1];
}

// TRUE O(n^2) solution using diagonal greedy/BFS approach
// Key insight: We don't need to store full paths!
// Process diagonal by diagonal, keeping only cells with minimum character

//Approach:
// WHY DIAGONALS?
// - Each diagonal represents one "step" in the path
// - Path length = 2n-1, same as number of diagonals
// - Every path visits exactly one cell per diagonal
// - Processing diagonal-by-diagonal = processing step-by-step

// WHY TRACK REACHABILITY INSTEAD OF FULL PATHS?
// - String DP: O(n³) because storing/comparing full paths
// - This approach: O(n²) because only tracking boolean reachability

// WHY GREEDY WORKS?
// - At each step, choosing minimum character gives lexicographically smallest result
// - By tracking reachability, we ensure we only consider valid paths

// REACHABILITY ARRAY MEANING:
// For diagonal d, reachable[i] = true means:
// - Cell (i, d-i) can be reached from (0,0)
// - Using a path that has been lexicographically optimal so far

// NEXT DIAGONAL REACHABILITY LOGIC:
// From cell (i,j) on diagonal d:
// - Move DOWN: (i+1, j) → diagonal (i+1)+j = d+1 → nextReachable[i+1]
// - Move RIGHT: (i, j+1) → diagonal i+(j+1) = d+1 → nextReachable[i]
// Note: On next diagonal, row index determines the cell position


// Example: n=4, Grid:
//   0 1 2 3
// 0 A A C A
// 1 B A B C
// 2 A B D A
// 3 A A C A

// d=0: Diagonal 0, cells where i+j=0
//   iStart=0, iEnd=0 → only (0,0)
//   reachable=[T,F,F,F] → (0,0) reachable
//   minChar='A', result="A"
//   Mark next: from (0,0) → (1,0) and (0,1) reachable

// d=1: Diagonal 1, cells where i+j=1
//   iStart=0, iEnd=1 → (0,1) and (1,0)
//   reachable=[T,T,F,F] → both reachable
//   (0,1)='A', (1,0)='B' → minChar='A', result="AA"
//   Mark next: only (0,1) has 'A' → (1,1) and (0,2) reachable

// d=2: Diagonal 2, cells where i+j=2
//   iStart=0, iEnd=2 → (0,2), (1,1), (2,0)
//   reachable=[T,T,F,F] → (0,2) and (1,1) reachable
//   (0,2)='C', (1,1)='A' → minChar='A', result="AAA"
//   Mark next: only (1,1) has 'A' → (2,1) and (1,2) reachable

// d=3: Diagonal 3, cells where i+j=3
//   reachable=[F,T,T,F] → (1,2) and (2,1) reachable
//   (1,2)='B', (2,1)='B' → minChar='B', result="AAAB"
//   Mark next: both have 'B' → (2,2), (1,3), (3,1) reachable

// d=4: Diagonal 4, cells where i+j=4
//   reachable=[F,T,T,T] → (1,3), (2,2), (3,1) reachable
//   (1,3)='C', (2,2)='D', (3,1)='A' → minChar='A', result="AAABA"
//   Mark next: only (3,1) has 'A' → (3,2) reachable

// d=5: Diagonal 5, cells where i+j=5
//   reachable=[F,F,F,T] → only (3,2) reachable
//   (3,2)='C' → minChar='C', result="AAABAC"
//   Mark next: (3,3) reachable

// d=6: Diagonal 6, cells where i+j=6
//   (3,3)='A' → minChar='A', result="AAABACA" ✓
//   d == 2*4-2 → DONE

// Time: O(n²) - process n cells per diagonal, 2n-1 diagonals
// Space: O(n) - only track reachability array and result string


string solveDiagonalGreedy(vector<vector<char> >& grid, int n) {
    string result = "";

    // reachable[i] = true means cell (i, diag-i) is reachable with optimal path
    vector<bool> reachable(n, false);
    reachable[0] = true; // Start at (0,0)

    // Process each diagonal (diagonal d has cells where i+j = d)
    for(int d = 0; d < 2*n - 1; d++) {
        // Find minimum character on this diagonal among reachable cells
        char minChar = 'Z' + 1;

        // Valid range: i from max(0, d-n+1) to min(d, n-1)
        int iStart = max(0, d - n + 1);
        int iEnd = min(d, n - 1);

        for(int i = iStart; i <= iEnd; i++) {
            int j = d - i;
            if(reachable[i]) {
                minChar = min(minChar, grid[i][j]);
            }
        }

        result += minChar;

        // If this is the last diagonal, we're done
        if(d == 2*n - 2) break;

        // Prepare reachable array for next diagonal
        // Next diagonal has cells where i+j = d+1
        // Cell (i, j) on next diagonal is reachable if:
        //   - (i-1, j) was reachable on current diagonal, OR
        //   - (i, j-1) was reachable on current diagonal
        // AND current cell had the minimum character

        vector<bool> nextReachable(n, false);

        for(int i = iStart; i <= iEnd; i++) {
            int j = d - i;
            if(reachable[i] && grid[i][j] == minChar) {
                // Can go down to (i+1, j) if valid
                if(i + 1 < n) {
                    nextReachable[i + 1] = true;
                }
                // Can go right to (i, j+1) if valid
                if(j + 1 < n) {
                    nextReachable[i] = true;
                }
            }
        }

        reachable = nextReachable;
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    int n;cin>>n;
    cin.ignore(); 
    vector<vector<char> >grid(n,vector<char>(n));
    vector<vector<string> > dp(n, vector<string>(n,""));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];    
        }
    }
    // cout<<solverec(grid,n,0,0,"")<<endl;
    // cout<<solvememo(grid,n,0,0,dp)<<endl;
    // cout<<solvetab(grid,n)<<endl;
    // cout<<solvetabopt(grid,n)<<endl;
    cout<<solveDiagonalGreedy(grid,n)<<endl;
    return 0;
}