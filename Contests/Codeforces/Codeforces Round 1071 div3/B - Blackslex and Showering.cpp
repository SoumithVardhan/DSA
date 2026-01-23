#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        int original_sum = 0;
        for(int i = 1; i < n; i++) {
            original_sum += abs(v[i] - v[i-1]);
        }
        
        int max_savings = 0;
        
        for(int k = 0; k < n; k++) {
            int cost_before = 0;
            int cost_after = 0;
 
            if(k > 0) {
                cost_before += abs(v[k] - v[k-1]);
            }
            if(k < n-1) {
                cost_before += abs(v[k+1] - v[k]);
            }
 
            if(k > 0 && k < n-1) {
                cost_after = abs(v[k+1] - v[k-1]);
            }
            
            int savings = cost_before - cost_after;
            max_savings = max(max_savings, savings);
        }
        
        cout << original_sum - max_savings << endl;
    }
    return 0;
}