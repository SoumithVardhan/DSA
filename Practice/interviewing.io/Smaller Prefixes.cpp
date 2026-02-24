#include <iostream>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"
bool solve(vector<int>&v){
    if(v.empty()){
      cout << "True" << endl;
    }
    long long currsum=0,prefsum=v[0];
    size_t idx=1;
    for(size_t i=0;i<v.size();i++){
      currsum+=v[i];
      if(i+1==2*idx){
        if(prefsum>=currsum)return false;
        prefsum+=v[idx];
        idx++;
      }
    }
    return true;
}
int main() {
  vector<int>arr={1, 2, 2, -1};
  bool res=solve(arr);
  cout << (res ? "True" : "False") << endl;
  return 0;
}

// Your previous Plain Text content is preserved below:

// Hello! Your interview question is below. Write code in this pad just like you would normally – your AI Interviewer will be able to see it.

// # Smaller Prefixes

// Given an array of integers, `arr`, where the length, `n`, is even, return whether the following condition holds for every `k` in the range `1 ≤ k <= n/2`: "the sum of the first `k` elements is smaller than the sum of the first `2k` elements." If this condition is false for any `k` in the range, return `false`.

// Example 1: arr = [1, 2, 2, -1]
// Output: True. The prefix [1] has a smaller sum than the prefix [1, 2], and the prefix [1, 2] has a smaller sum than the prefix [1, 2, 2, -1]. The other prefixes have length > n/2.

// Example 2: arr = [1, 2, -2, 1, 3, 5]
// Output: False. The prefix [1, 2] has a larger sum than the prefix [1, 2, -2, 1].

// Constraints:

// - len(arr) is even
// - 0 ≤ len(arr) ≤ 10^6
// - -10^9 ≤ arr[i] ≤ 10^9