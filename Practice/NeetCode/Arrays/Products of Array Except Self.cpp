#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //Approach 1: Using output array to store prefix products and a variable for suffix product
    //TC: O(N) + O(N) = O(N)
    //SC: O(N) for output array, O(1) for suffix product variable
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }

        int suffix=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;
    }

    //Approach 2: Using two arrays for prefix and suffix products
    //TC: O(N) + O(N) + O(N) = O(N)
    //SC: O(N) for prefix, suffix arrays, and output array
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefsum(n,1);
        vector<int>suffixsum(n,1);

        prefsum[0]=nums[0];
        suffixsum[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefsum[i]=prefsum[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffixsum[i]=suffixsum[i+1]*nums[i];
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=suffixsum[i+1];
            }
            else if(i==n-1){
                ans[i]=prefsum[i-1];
            }
            else{
                ans[i]=prefsum[i-1]*suffixsum[i+1];
            }
        }
        return ans;
    }
};
