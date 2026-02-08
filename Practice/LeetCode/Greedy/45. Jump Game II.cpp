#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Greedy Approach: Track the current range of reachable indices and expand it iteratively
    int jump(vector<int>& nums) {
        int cnt=0,cm=0;
        int n=nums.size()-1,s=0,e=0;
        //Ranging of arrays
        //[2,3,1,1,4]
        //first loop : intially [2]
        //jump1[3,1] jump2[1,1,4] reached end of array
        while(e<n){
            for(int i=s;i<=e;i++){
                cm=max(cm,i+nums[i]);
            }
            cnt++;
            s=e+1;
            e=cm;
        }return cnt;
    }

    //Approach2: Memoization(Memory Limit Exceeded)
    long long int solvememo(vector<int> nums , int curr, int dest,vector<int>&dp)
    {       
            if(curr>=dest) return 0; 
            if(dp[curr]!=-1)return dp[curr];
            long long int tmp=INT_MAX;
			//eg: the lets say ele is 3 so that your loop will be for ele 1,1,4
            for(int i=1;i<=nums[curr];i++)
            {
                tmp=min(tmp,1+solvememo(nums,curr+i,dest,dp));  
            } 
         return dp[curr]=tmp;  
    }
    
    int jump(vector<int>& nums) { 
        int n=nums.size();
        vector<int>dp(n,-1);
        return solvememo(nums,0,n-1,dp);
    }

    //Approach3: Recursion (TLE)
    long long int solve(vector<int> nums , int curr, int dest)
    {       
            if(curr>=dest) return 0; 
            long long int tmp=INT_MAX;
			//eg: the lets say ele is 3 so that your loop will be for ele 1,1,4
            for(int i=1;i<=nums[curr];i++)
            {
                tmp=min(tmp,1+solve(nums,curr+i,dest));  
            } 
         return tmp;  
    }
    
    int jump(vector<int>& nums) { 
        int n=nums.size();
        return solve(nums,0,n-1);
    }

    //Approach4: Greedy (Airtribe)
    int jump(vector<int>& nums) {
        
        if(nums.size()<2) return 0;   //base case
        
        //initialize jump=1 , we are taking jump from 0th index to the range mxjump
        //currjump, we can take jump from particular  index
		//mxjump , we cango up to maximum
		// jump to count no. of jump
        int jump=1,n=nums.size(),currjmp=nums[0],mxjmp=nums[0];
        
        int i=0;
		
		//till we reach last index, NOTE: Not necessary to cross last index
        while(i<n-1)
        {
            mxjmp=max(mxjmp,i+nums[i]);
             
            if(currjmp==i) //we have to take jump now because our currjump now ends.
            {
                jump++;//increment in jump
                currjmp=mxjmp; //assign new maxjmp to currjmp
            }
            i++;
        }
        return jump;
    }
};