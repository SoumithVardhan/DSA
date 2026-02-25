#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ============= APPROACH 1: return time - 1 =============
class Solution{
public:
    int solvebfs(vector<vector<int>>&grid, queue<pair<int,int>>rottenq, 
                 int cntfreshorg, int time, int n, int m){
        int xcor[4]={-1,1,0,0};
        int ycor[4]={0,0,-1,1};

        while(!rottenq.empty()){
            int sizeq=rottenq.size();
            
            // Process all oranges that rot at current time level
            for(int i=0;i<sizeq;i++){
                pair<int,int> frontele=rottenq.front();
                rottenq.pop();
                int elexcor=frontele.first;
                int eleycor=frontele.second;
                
                // Check all 4 directions
                for(int i=0;i<4;i++){
                    int finalxcor=elexcor+xcor[i];
                    int finalycor=eleycor+ycor[i];
                    
                    if(finalxcor<0 || finalycor<0 ||  finalxcor>=n || finalycor>=m){
                        continue;
                    }
                    if(grid[finalxcor][finalycor]==0)continue;
                    
                    if(grid[finalxcor][finalycor]==1){
                        grid[finalxcor][finalycor]=2;  // Mark as rotten
                        cntfreshorg--;
                        rottenq.push({finalxcor,finalycor});  // Will rot at next time
                    }
                }
            }
            
            // ⚠️ CRITICAL: We increment time AFTER processing each level
            // This causes one EXTRA increment after the last batch
            time++;
            
            /* EXAMPLE:
             * Grid: 2 1    (2=rotten, 1=fresh)
             *       1 1
             * 
             * time=0: queue=[(0,0)], process it, rot (0,1) and (1,0)
             *         time++ → time=1 ✓
             * 
             * time=1: queue=[(0,1),(1,0)], process both, rot (1,1)
             *         time++ → time=2 ✓
             * 
             * time=2: queue=[(1,1)], process it, no fresh neighbors
             *         time++ → time=3 ❌ EXTRA INCREMENT!
             * 
             * Queue becomes empty, exit loop
             * time=3 but answer should be 2
             * So we return time-1 = 3-1 = 2 ✓
             */
        }
        
        if(cntfreshorg>0)return -1;  // Some fresh oranges unreachable
        
        // Return time-1 because we incremented one extra time
        // when the last batch was processed (queue became empty)
        return time-1;
    }
    
    int orangesRotting(vector<vector<int>> &grid) {
        int n=grid.size();
        int m = grid[0].size();

        int cntfreshorg=0;
        queue<pair<int,int>>rottenq;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cntfreshorg++;
                if(grid[i][j]==2){
                    rottenq.push({i,j});   
                }
            }
        }
        
        // Edge case: No fresh oranges to begin with
        if(cntfreshorg == 0) return 0;

        return solvebfs(grid,rottenq,cntfreshorg,0,n,m);
    }
};


// ============= APPROACH 2: Early break when all rotten =============
class Solution{
public:
    int solvebfs(vector<vector<int>>&grid, queue<pair<int,int>>rottenq, 
                 int cntfreshorg, int time, int n, int m){
        int xcor[4]={-1,1,0,0};
        int ycor[4]={0,0,-1,1};

        while(!rottenq.empty()){
            int sizeq=rottenq.size();
            
            // Process all oranges that rot at current time level
            for(int i=0;i<sizeq;i++){
                pair<int,int> frontele=rottenq.front();
                rottenq.pop();
                int elexcor=frontele.first;
                int eleycor=frontele.second;
                
                // Check all 4 directions
                for(int i=0;i<4;i++){
                    int finalxcor=elexcor+xcor[i];
                    int finalycor=eleycor+ycor[i];
                    
                    if(finalxcor<0 || finalycor<0 ||  finalxcor>=n || finalycor>=m){
                        continue;
                    }
                    if(grid[finalxcor][finalycor]==0)continue;
                    
                    if(grid[finalxcor][finalycor]==1){
                        grid[finalxcor][finalycor]=2;
                        cntfreshorg--;  // Decrement happens HERE
                        rottenq.push({finalxcor,finalycor});
                    }
                }
            }
            
            // Increment time after processing this batch
            time++;
            
            /* ✅ KEY OPTIMIZATION: Check if all fresh oranges are now rotten
             * 
             * EXAMPLE:
             * Grid: 2 1
             *       1 1
             * 
             * time=0: queue=[(0,0)], process it
             *         Rot (0,1): cntfreshorg=3→2
             *         Rot (1,0): cntfreshorg=2→1
             *         time++ → time=1
             *         Check: cntfreshorg=1 ≠ 0, continue
             * 
             * time=1: queue=[(0,1),(1,0)], process both
             *         Rot (1,1): cntfreshorg=1→0 ✓ BECOMES ZERO!
             *         time++ → time=2
             *         Check: cntfreshorg=0, BREAK! ✓
             * 
             * Return time=2 directly (no need for time-1)
             * 
             * WHY THIS WORKS:
             * - The LAST fresh orange rots in the SAME iteration where time becomes 2
             * - We increment time THEN check, so time already has the correct value
             * - No extra increment happens because we break immediately
             */
            if(cntfreshorg==0)break;  // All fresh oranges are now rotten!
        }
        
        if(cntfreshorg>0)return -1;
        
        // Return time directly (no -1 needed because we broke early)
        return time;
    }
    
    int orangesRotting(vector<vector<int>> &grid) {
        int n=grid.size();
        int m = grid[0].size();

        int cntfreshorg=0;
        queue<pair<int,int>>rottenq;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cntfreshorg++;
                if(grid[i][j]==2){
                    rottenq.push({i,j});   
                }
            }
        }
        
        if(cntfreshorg == 0) return 0;

        return solvebfs(grid,rottenq,cntfreshorg,0,n,m);
    }
};

/* ==================== SUMMARY ====================
 * 
 * APPROACH 1 (time-1):
 * - Increments time AFTER every batch (even the last one)
 * - Queue becomes empty → loop exits → time has 1 extra
 * - Must subtract 1 to get correct answer
 * 
 * APPROACH 2 (early break):
 * - Checks if all oranges rotten AFTER incrementing time
 * - Breaks immediately when cntfreshorg==0
 * - No extra increment happens → return time directly
 * 
 * BOTH ARE CORRECT! Approach 2 is slightly more intuitive.
 * 
 * ================================================ */
