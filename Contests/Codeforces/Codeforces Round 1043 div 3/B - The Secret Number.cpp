#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long d = 11;
        vector<long long> ans;
        while(n >= d) {
            if(n % d == 0) {
                ans.push_back(n / d);
            }
            d = (d - 1) * 10 + 1;
        }
        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i];
            if(i > 0) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}