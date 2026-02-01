#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;


vector<vector<long long>> dp;

long long solveRec(vector<int>& arr, int left, int right) {
    // only one element left
    if (left == right) {
        return arr[left];
    }
    
    // two elements left
    if (left + 1 == right) {
        return max(arr[left], arr[right]);
    }
    
    // Take left element, opponent plays optimally on remaining
    long long takeLeft = arr[left] + min(
        solveRec(arr, left + 2, right),  // opponent took left+1
        solveRec(arr, left + 1, right - 1) // opponent took right
    );
    
    // Take right element, opponent plays optimally on remaining
    long long takeRight = arr[right] + min(
        solveRec(arr, left + 1, right - 1), // opponent took left
        solveRec(arr, left, right - 2)      // opponent took right-1
    );
    
    return max(takeLeft, takeRight);
}

long long solvememo(vector<int>& arr, int left, int right) {
    // Base case
    if (left == right) {
        return arr[left];
    }
    
    if (left > right) {
        return 0;
    }
    
    // Check if already computed
    if (dp[left][right] != -1) {
        return dp[left][right];
    }
    
    long long takeLeft = arr[left] + min(
        solvememo(arr, left + 2, right),
        solvememo(arr, left + 1, right - 1)
    );
    
    long long takeRight = arr[right] + min(
        solvememo(arr, left + 1, right - 1),
        solvememo(arr, left, right - 2)
    );
    
    return dp[left][right] = max(takeLeft, takeRight);
}

/*
Final DP Table
j=0   j=1   j=2   j=3
    ┌─────┬─────┬─────┬─────┐
i=0 │  4  │  1  │  0  │  3  │
    ├─────┼─────┼─────┼─────┤
i=1 │  X  │  5  │  4  │  3  │
    ├─────┼─────┼─────┼─────┤
i=2 │  X  │  X  │  1  │  2  │
    ├─────┼─────┼─────┼─────┤
i=3 │  X  │  X  │  X  │  3  │
    └─────┴─────┴─────┴─────┘
*/
long long solvetab(vector<long long>& arr) {
    int n = arr.size();
    
    // Calculate total sum
    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    
    // dp[i][j] = max score difference for range [i, j]
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Base case: single element
    for (int i = 0; i < n; i++) {
        dp[i][i] = arr[i];
    }
    
    // Fill table: i backwards, j forwards becoz of dependency
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // Take left element
            long long takeLeft = arr[i] - dp[i + 1][j];
            
            // Take right element
            long long takeRight = arr[j] - dp[i][j - 1];
            
            dp[i][j] = max(takeLeft, takeRight);
        }
    }
    
    // Calculate first player's score
    // Player1 - Player2 = dp[0][n-1]
    // Player1 + Player2 = totalSum
    // => Player1 = (totalSum + dp[0][n-1]) / 2
    long long firstPlayerScore = (totalSum + dp[0][n - 1]) / 2;
    
    return firstPlayerScore;
}


int main() {
    int n;
    cin >> n;
    
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    
    // Recursion 
    // cout << solveRec(arr, 0, n - 1) << endl;

    // Memoization Approch
    // dp.assign(n, vector<long long>(n, -1));
    // cout << solvememo(arr, 0, n - 1) << endl;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solvetab(arr) << endl;
    return 0;
}