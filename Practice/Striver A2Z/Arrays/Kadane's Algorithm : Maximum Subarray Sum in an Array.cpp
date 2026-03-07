#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    //Approach 1 : Brute Force
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }

    // Approach 2: Better 
    int maxSubArraybetter(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];        
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
    // Approach 3: Optimal
    int maxSubArrayOptimal(vector<int>& nums) {
        long long maxi = LLONG_MIN;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);  
            if (sum < 0) sum = 0;
        }
        return (int)maxi;
    }

    // Print the subarray with the maximum sum
    int maxSubArrayPrint(vector<int>& nums) {
        long long maxi = LLONG_MIN;
        long long sum = 0;
        int start = 0, ansStart = -1, ansEnd = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) start = i;

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                ansStart = start;      
                ansEnd = i;            
            }

            if (sum < 0) sum = 0;
        }

        cout << "Subarray: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i];
            if (i != ansEnd) cout << ", ";
        }
        cout << "]\n";

        return (int)maxi;
    }
};

