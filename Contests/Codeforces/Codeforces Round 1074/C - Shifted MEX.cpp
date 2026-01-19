#include <iostream>
#include <vector>
#include <set>
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
        
        set<int> s(v.begin(), v.end());
        int ans = 0;
        
        for(int val : v) {
            int x = -val;  
            int mex = 0;
            while(s.count(mex - x)) {
                mex++;
            }
            ans = max(ans, mex);
        }
        
        int mex = 0;
        while(s.count(mex)) {
            mex++;
        }
        ans = max(ans, mex);
        
        cout << ans << endl;
    }
    
    return 0;
}