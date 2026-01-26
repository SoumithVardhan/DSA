#include <iostream>
#include <vector>
using namespace std;
 
long long gcd(long long a,long long b) {
    while (b != 0) {
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        long long g=a[0];
        for (int i=1;i<n;i++) {
            g=gcd(g,a[i]);
        }
        
        for(long long x=2; ;x++) {
            if (gcd(g, x) == 1) {
                cout<<x<<endl;
                break;
            }
        }
    }
    
    return 0;
}