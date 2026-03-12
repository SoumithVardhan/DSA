#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A') cntA++;
            if(i >= 2 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L')
                return false;
        }
        if(cntA >= 2) return false;
        return true;
    }
};

int main() {
    Solution obj;

    cout << (obj.checkRecord("PPALLP") ? "true" : "false") << "\n";  // true
    cout << (obj.checkRecord("PPALLL") ? "true" : "false") << "\n";  // false
    cout << (obj.checkRecord("AA")     ? "true" : "false") << "\n";  // false
    cout << (obj.checkRecord("A")      ? "true" : "false") << "\n";  // true
    cout << (obj.checkRecord("LLLPP")  ? "true" : "false") << "\n";  // false

    return 0;
}