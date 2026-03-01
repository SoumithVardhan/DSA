#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ============= APPROACH 1: DFS (Recommended) =============
/*
TIME COMPLEXITY: O(N × M)
- Visit each cell at most once
- For each cell, check 4 directions in O(1)
- Total: (N × M) × O(1) = O(N × M)

SPACE COMPLEXITY: O(N × M)
- Recursion stack depth in worst case
- Worst case: All cells same color in snake pattern
  Example: 1→1→1→1
              ↓
           1←1←1←1
  Stack depth = N × M
- Best case: Only starting cell matches → O(1)
- Average: O(√(N×M))

NOTE: No extra visited array needed (modify image in-place)
⚠️ Risk of stack overflow for very large grids
*/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, 
             int originalColor, int n, int m){
        // Mark current cell with new color
        image[sr][sc] = newColor;
        
        // 4-directional movements: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++){
            int newRow = sr + dx[i];
            int newCol = sc + dy[i];
            
            // Check boundaries
            if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m){
                continue;
            }
            
            // Only proceed if cell has original color (not yet visited)
            if(image[newRow][newCol] == originalColor){
                dfs(image, newRow, newCol, newColor, originalColor, n, m);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
                                   int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int originalColor = image[sr][sc];
        
        // Edge case: If original color is same as new color, return as is
        // Without this, we get infinite recursion (cell keeps matching original color)
        if(originalColor == newColor) return image;
        
        dfs(image, sr, sc, newColor, originalColor, n, m);
        
        return image;
    }
};


// ============= APPROACH 2: BFS =============
/*
TIME COMPLEXITY: O(N × M)
- Visit each cell at most once
- For each cell, check 4 directions in O(1)
- Total: (N × M) × O(1) = O(N × M)

SPACE COMPLEXITY: O(N × M)
- Queue size in worst case
- Worst case: All cells same color
  Example: 1 1 1
           1 1 1
           1 1 1
  Queue can hold all N×M cells
- Best case: Only starting cell matches → O(1)
- Average: O(√(N×M))

NOTE: No extra visited array needed (modify image in-place)
✓ No stack overflow risk (uses heap)
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
                                   int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int originalColor = image[sr][sc];
        
        // Edge case: If colors are same, no need to process
        if(originalColor == newColor) return image;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;  // Mark as visited
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            
            // Check all 4 directions
            for(int i = 0; i < 4; i++){
                int newRow = x + dx[i];
                int newCol = y + dy[i];
                
                // Check boundaries
                if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m){
                    continue;
                }
                
                // If cell has original color, fill it and add to queue
                if(image[newRow][newCol] == originalColor){
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
        
        return image;
    }
};


// ============= MAIN FUNCTION FOR TESTING =============
int main(){
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> result1 = sol.floodFill(image1, 1, 1, 2);
    
    cout << "Test 1 Output:" << endl;
    for(auto row : result1){
        for(auto cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }
    
    // Test Case 2
    vector<vector<int>> image2 = {{0, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> result2 = sol.floodFill(image2, 2, 2, 3);
    
    cout << "\nTest 2 Output:" << endl;
    for(auto row : result2){
        for(auto cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}