#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // Approach 1: Brute force approach
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));

        // Place each element at rotated position
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = temp;
    }

    // Approach 2: Optimal approach using transpose and reverse
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose — swap matrix[i][j] with matrix[j][i]
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // j starts from i+1 to avoid double swap
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};