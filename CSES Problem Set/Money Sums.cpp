#include<iostream>
#include<vector>
#include <climits>
#include <unordered_set>
#include <algorithm>
using namespace std;

void solverec(int n, vector<int>& v, unordered_set<int>& us, int index, int sum) {
    if (index == n) {
        us.insert(sum);
        return;
    }
    // include 
    solverec(n, v, us, index + 1, sum + v[index]);
    // exclude
    solverec(n, v, us, index + 1, sum);
}

void solvememo(int n, vector<int>& v, int index, int sum, vector<vector<int> >& dp, unordered_set<int>& us) {
    if (index == n) {
        if (sum > 0) {
            us.insert(sum);
        }
        return;
    }
    if (dp[index][sum] != -1) {
        return;
    }
    // Mark as visited
    dp[index][sum] = 1;
    solvememo(n, v, index + 1, sum + v[index], dp, us);
    solvememo(n, v, index + 1, sum, dp, us);
}

void solvetab(int n, vector<int>&v,vector<bool>&dp,int maxsum){
    dp[0] = true; // sum 0 is always possible (by selecting no coins)

    for (int i = 0; i < n; i++) {
        // Traverse from right to left to avoid using same coin twice
        // Similar to 0/1 knapsack space opt
        for (int sum = maxsum; sum >= v[i]; sum--) {
            if (dp[sum - v[i]]) {
                dp[sum] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    unordered_set<int> us;

    // Recursive approach
    // solverec(n, v, us, 0, 0);
    // vector<int>res(us.begin(),us.end());
    // sort(res.begin(),res.end());
    // cout<<res.size()-1<<endl;
    // for (int i=1;i<res.size();i++) {
    //     cout << res[i] << " ";
    // }


    // Memoization approach
    // int maxSum = 0;
    // for (int i = 0; i < n; i++) {
    //     cin >> v[i];
    //     maxSum += v[i];
    // }
    // vector<vector<int> > dp(n + 1, vector<int>(maxSum + 1, -1));
    // solvememo(n, v, 0, 0, dp, us);
    // vector<int> res(us.begin(), us.end());
    // sort(res.begin(), res.end());
    
    // cout << res.size() << endl;
    // for (int i = 0; i < res.size(); i++) {
    //     cout << res[i];
    //     if (i < res.size() - 1) cout << " ";
    // }
    // cout << endl;

    // Tabulation approach
    int maxsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxsum += v[i];
    }
    vector<bool> dp(maxsum + 1, false);
    solvetab(n,v,dp,maxsum);
    vector<int> result;
    for (int sum = 1; sum <= maxsum; sum++) {
        if (dp[sum]) {
            result.push_back(sum);
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
    
}