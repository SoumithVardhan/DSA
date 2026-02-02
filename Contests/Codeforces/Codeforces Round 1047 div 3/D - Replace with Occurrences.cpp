#include <iostream>
#include <vector>   
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        vector<int> freq(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            freq[b[i]]++;
        }
        
        // Validation: freq[k] must be divisible by k
        bool valid = true;
        for (int k = 1; k <= n; k++) {
            if (freq[k] % k != 0) {
                valid = false;
                break;
            }
        }
        
        if (!valid) {
            cout << -1 << "\n";
            continue;
        }
        
        // Construct answer
        // For each position with b[i]=k, assign values such that
        // each value appears exactly k times
        vector<int> a(n);
        vector<int> count(n + 1, 0); 
        vector<int> label(n + 1, 0);
        int nextLabel = 1;
        
        for (int i = 0; i < n; i++) {
            int k = b[i];
            
            // Every k positions, we need a new label
            if (count[k] % k == 0) {
                label[k] = nextLabel;
                nextLabel++;
            }
            
            a[i] = label[k];
            count[k]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }
    
    return 0;
}