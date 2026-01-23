#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
//Memoization approach
/*
WHY THIS CODE FAILS (CSES – Minimizing Coins):

1) Extremely deep recursion:
   - The recursive call solve(m - v[j], j) can go as deep as O(m).
   - For constraints like m ≈ 10^8, this leads to ~10^8 recursive calls.
   - Each recursive call consumes stack memory → STACK OVERFLOW.

2) Stack memory is the real bottleneck:
   - CSES provides a total memory limit of 512 MB.
   - Recursion stack + DP calls together exceed this limit.
   - Stack space grows with recursion depth and is NOT affected by:
       • using vector vs map
       • changing heap-based DP storage

3) Changing vector → map does NOT fix the issue:
   - DP container (vector/map) is allocated on the HEAP.
   - Recursion depth is allocated on the STACK.
   - Hence, switching vector to map only changes HEAP usage,
     but STACK usage remains dangerously high.

4) Additional inefficiency:
   - dp is passed BY VALUE instead of reference.
   - This causes a full copy of the DP table on every recursive call,
     increasing both time and memory overhead.
   - Using &dp only avoids copying the DP table and reduces HEAP usage.
   - Recursion depth and STACK usage remain unchanged.
   - Hence, stack overflow still occurs even with &dp.

CONCLUSION:
   - This recursive memoized solution is not suitable for large m.
   - The correct approach is an ITERATIVE (bottom-up) DP solution
     to avoid deep recursion and stack overflow.
*/

int solvememo(int m,vector<int>v,int j,vector<vector<int>>dp){
    if(m==0)return 0;
    if(j<0)return INT_MAX;
    if(dp[j][m]!=-1)return dp[j][m];
	//incl
	int ans1=INT_MAX,ans2=INT_MAX;
 
	if(m>=v[j]){
		int temp=solvememo(m-v[j],v,j,dp);
		if(temp!=INT_MAX)ans1=1+temp;
	}
	//excl
	ans2=solvememo(m,v,j-1,dp);
	dp[j][m]=min(ans1,ans2);
	return dp[j][m];
	
}

//Tabulation approach 
int solvetab(int m, vector<int>& v, int n){
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = v[i]; j <= m; j++){
            if(dp[j - v[i]] != INT_MAX){
                dp[j] = min(dp[j], dp[j - v[i]] + 1);
            }  
        }
    }
    return (dp[m] == INT_MAX ? -1 : dp[m]);	
}
 
int main(){
	int n,m;cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	// vector<vector<int>> dp(n, vector<int>(m+1, -1));
	// int res=solvememo(m,v,v.size()-1,dp);
	// if(res==INT_MAX){
	//     cout<< -1<<endl;
	// }
	// else cout<<res<<endl;



    //Tabulation approach
    cout << solvetab(m, v, n) << endl; 
    return 0;
}