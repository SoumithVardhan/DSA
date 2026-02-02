#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> memo;

vector<int> solverec(vector<int>& a, vector<int>& b, int i, int j) {
    if (i >= a.size() || j >= b.size()) {
        return vector<int>();
    }
    
    // If elements match, include in LCS
    if (a[i] == b[j]) {
        vector<int> result = solverec(a, b, i + 1, j + 1);
        // prepend
        result.insert(result.begin(), a[i]);
        return result;
    }
    
    // Try both options and return the longer one
    vector<int> skip_a = solverec(a, b, i + 1, j);
    vector<int> skip_b = solverec(a, b, i, j + 1);
    
    return (skip_a.size() >= skip_b.size()) ? skip_a : skip_b;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    // vector<int> result = solverec(a, b, 0, 0);
    
    // cout << result.size() << "\n";
    // for (int i = 0; i < result.size(); i++) {
    //     if (i > 0) cout << " ";
    //     cout << result[i];
    // }
    // if (result.size() > 0) cout << "\n";

    
    return 0;
}