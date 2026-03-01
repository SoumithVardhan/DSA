#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            // Find the delimiter '#'
            int j = i;
            while (s[j] != '#') j++;
            // Parse length
            int length = stoi(s.substr(i, j - i));
            // Extract the string and add to result
            res.push_back(s.substr(j + 1, length));   
            // Move to next encoding
            i = j + 1 + length;
        }
        return res;
    }
};
