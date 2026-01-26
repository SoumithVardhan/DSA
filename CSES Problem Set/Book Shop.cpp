#include<iostream>
#include<vector>
using namespace std;

int solverec(vector<int>&prices,vector<int>&pages,int maxprice, int index){
    if(index>=prices.size())return 0;
    if(maxprice<=0)return 0;
    //incl
    int include=0;
    if(maxprice>=prices[index])
        include=pages[index]+solverec(prices,pages,maxprice-prices[index],index+1);
    int exclude=solverec(prices,pages,maxprice,index+1);
    return max(include,exclude);
}

int solvememo(vector<int>&prices,vector<int>&pages,int maxprice, int index, vector<vector<int> >&dp){
    if(index>=prices.size())return 0;
    if(maxprice<=0)return 0;
    if(dp[maxprice][index]!=-1)return dp[maxprice][index];
    //incl
    int include=0;
    if(maxprice>=prices[index])
        include=pages[index]+solvememo(prices,pages,maxprice-prices[index],index+1,dp);
    int exclude=solvememo(prices,pages,maxprice,index+1,dp);
    dp[maxprice][index]=max(include,exclude);
    return max(include,exclude);
}

// Why dp[n+1][x+1] instead of dp[n][x]?
// - Row 0 (dp[0][...]): Base case representing "0 books processed" → 0 pages for any budget
// - Col 0 (dp[...][0]): Base case representing "0 budget" → 0 pages with any books
// - Avoids index out of bounds when computing dp[1][...] which needs dp[0][...]
// - Clean indexing: dp[i][price] = max pages using first i books (books 0 to i-1)
// - Final answer: dp[n][x] (all n books considered with full budget x)
// - Without +1: messy special cases needed for first book/zero budget


// dp[index][maxprice]:

// index   price : 0   1   2   3   4   5   6   7   8   9  10
//   0             0   0   0   0   5   5   5   5   5   5   5
//   1             0   0   0   0   5   5   5   5  12  12  12
//   2             0   0   0   0   5   8   8   8  12  13  13
//   3             0   0   0   1   5   8   8   8  12  13  13
int solvetab(vector<int>&prices,vector<int>&pages,int maxprice){
    int n=prices.size();
    vector<vector<int> >dp(n+1,vector<int>(maxprice+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxprice;j++){
            dp[i][j]=dp[i-1][j]; //exclude book of ith
            if(j>=prices[i-1])   //can afford book of ith
                // we choose prices[i-1] and pages[i-1] to match the index of vector
                dp[i][j]=max(dp[i][j],dp[i-1][j-prices[i-1]]+pages[i-1]);
        }
    }
    return dp[n][maxprice];

}

//Tabulation Opt1
//In here order of j loop works left to right as we are maintaining previous row
//i loop changes from 0 -> n-1 
int solvetabopt1(vector<int>&prices,vector<int>&pages,int maxprice){
    int n=prices.size();
    vector<int>dp(maxprice+1,0);

    for(int i=0;i<n;i++){
        vector<int>temp=dp;
        for(int j=prices[i];j<=maxprice;j++){ // LEFT to RIGHT is OK now!
            dp[j]=max(temp[j],temp[j-prices[i]]+pages[i]);
        }
    }
    return dp[maxprice];
}

//double buffer
int solvetabopt2(vector<int>&prices, vector<int>&pages, int maxprice){
    vector<int> prev(maxprice+1, 0);  
    vector<int> curr(maxprice+1, 0);  
    
    for(int i = 0; i < prices.size(); i++){
        for(int j = 0; j <= maxprice; j++){  // LEFT to RIGHT is OK now!
            curr[j] = prev[j];  // Don't take book i
            if(j >= prices[i]) // If you take book i
                curr[j] = max(curr[j], prev[j - prices[i]] + pages[i]);
        }
        swap(prev, curr);  // Swap: curr becomes prev for next iteration
    }
    return prev[maxprice];
}


//Tabulation Opt2

// Why right to left why not left to right?
// dp[5] = max(dp[5], dp[0] + 10) = max(0, 0+10) = 10
// dp = [0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10]
//       ↑              ↑
//    j-5=0           j=5  ← Updated LAST
// ```

// **Final result:** `dp[10] = 10` ✓ (correct - used book only once)

// ---

// ## Visual Comparison:

// ### Left-to-Right Problem:
// ```
// j=5:  dp[5] = 10   (book added)
//       ↓
// j=10: dp[10] = dp[5] + 10 = 10 + 10 = 20  ← Uses UPDATED dp[5]!
//                    ↑↑↑
//               This already has the book!
//               So we're adding it AGAIN!
// ```

// ### Right-to-Left Solution:
// ```
// j=10: dp[10] = dp[5] + 10 = 0 + 10 = 10   ← Uses OLD dp[5]
//                        ↑↑↑
//                    Still 0 (not updated yet)
//       ↓
// j=5:  dp[5] = 10   (book added)  ← Updated AFTER j=10

int solvetabopt3(vector<int>&prices,vector<int>&pages,int maxprice){
    int n=prices.size();
    vector<int>dp(maxprice+1,0);
    
    for(int i = 0; i < prices.size(); i++){
        for(int j = maxprice; j >= prices[i]; j--){
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    
    return dp[maxprice];
}
int main(){
    int totalbooks,maxprice;
    cin>>totalbooks>>maxprice;
    int n=totalbooks;
    vector<int>prices(totalbooks,0);
    for(int i=0;i<totalbooks;i++){
        cin>>prices[i];
    }
    vector<int>pages(totalbooks,0);
    for(int i=0;i<totalbooks;i++){
        cin>>pages[i];
    }
    vector<vector<int> >dp(maxprice+1,vector<int>(n,-1));
    // cout<<solverec(prices,pages,maxprice,0)<<endl;

    // cout<<solvememo(prices,pages,maxprice,0,dp)<<endl;
    
    // cout<<solvetab(prices,pages,maxprice);
    // cout<<solvetabopt1(prices,pages,maxprice);
    cout<<solvetabopt2(prices,pages,maxprice);
    // cout<<solvetabopt3(prices,pages,maxprice);
    return 0;
}