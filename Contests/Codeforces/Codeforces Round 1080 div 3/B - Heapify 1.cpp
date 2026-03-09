#include <iostream>
#include <vector>
using namespace std;
 
int oddPart(int x) {
    while (x % 2 == 0) x /= 2;
    return x;
}
 
int main() {
 
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (oddPart(i) != oddPart(a[i])) {
                ok = false;
                break;
            }
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}