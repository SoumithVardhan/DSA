#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//int (32-bit signed):
// Range: -2,147,483,648 to 2,147,483,647
//        -2.1 × 10^9   to  2.1 × 10^9

// Constraint: -10^9 ≤ arr[i] ≤ 10^9
//            -1 × 10^9  to  1 × 10^9

// 10^9 = 1,000,000,000
// 2.1 × 10^9 = 2,100,000,000

// ✅ 10^9 < 2.1 × 10^9 → int is SAFE!

// If constraint was: -10^10 ≤ arr[i] ≤ 10^10
// vector<int> arr;   ❌ int too small!
// vector<long long> arr;   ✅ Needed!
// To execute C++, please define "int main()"
vector<int> mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
  int n=arr1.size(),m=arr2.size();
  vector<int>ans;
  int i=0,j=0;
  while(i<n && j<m){
    if(arr1[i]<arr2[j]){
      ans.push_back(arr1[i]);
      i++;
    }else{
      ans.push_back(arr2[j]);
      j++;
    }
  }
  while(i<n){
    ans.push_back(arr1[i]);
    i++;
  }
  while(j<m){
    ans.push_back(arr2[j]);
    j++;
  }
  return ans;
}
int main() {
  vector<int>arr1={1, 3, 4, 5};
  vector<int>arr2={2, 4, 4};
  int n=arr1.size();
  int m=arr2.size();
  vector<int>ans;
  ans=mergeTwoSortedArrays(arr1,arr2);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i];
    if(i<ans.size()-1){
      cout<<" ";
    }
  }cout<<endl;
  return 0;
}

// Your previous Plain Text content is preserved below:

// Hello! Your interview question is below. Write code in this pad just like you would normally – your AI Interviewer will be able to see it.

// # Merge Two Sorted Arrays

// Given two sorted arrays of integers, `arr1` and `arr2`, return a new array that contains all the elements in `arr1` and `arr2` in sorted order, including duplicates.

// Example 1:
// Input:
// arr1 = [1, 3, 4, 5]
// arr2 = [2, 4, 4]
// Output: [1, 2, 3, 4, 4, 4, 5]
// Explanation: All elements are merged in sorted order.

// Example 2:
// Input:
// arr1 = [-1]
// arr2 = []
// Output: [-1]
// Explanation: When one array is empty, the result is just the other array.

// Example 3:
// Input:
// arr1 = [1, 3, 5]
// arr2 = [2, 4, 6]
// Output: [1, 2, 3, 4, 5, 6]

// Constraints:

// - arr1 and arr2 are sorted in ascending order
// - 0 ≤ arr1.length, arr2.length ≤ 10^6
// - -10^9 ≤ arr1[i], arr2[i] ≤ 10^9