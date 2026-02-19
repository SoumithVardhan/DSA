#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  vector<char> v = {'R','W','B','B','W','R','W'};
  int s=0,j=v.size()-1;
  int i=0;
  while(s<=j){
    if(v[s]=='R'){
      swap(v[s],v[i]);
        i++;
        s++;
    }
    else if(v[s]=='B'){
      swap(v[s],v[j]);
        j--;
    }
    else s++;
  }
  for (int i=0;i<v.size();i++) {
    cout << v[i]<<" ";
  }
  return 0;
}

// Your previous Plain Text content is preserved below:

// Hello! Your interview question is below. Write code in this pad just like you would normally – your AI Interviewer will be able to see it.

// # Dutch Flag Problem

// Given an array, `arr`, containing only of the characters 'R' (red), 'W' (white), and 'B' (blue), sort the array in place so that the same colors are adjacent, with the colors in the order red, white, and blue.

// Example 1:
// Input: arr = ['R', 'W', 'B', 'B', 'W', 'R', 'W']
// Output: ['R', 'R', 'W', 'W', 'W', 'B', 'B']

// Example 2:
// Input: arr = ['B', 'R']
// Output: ['R', 'B']

// Constraints:

// - 0 ≤ arr.length ≤ 10^6
// - arr[i] is either 'R', 'W', or 'B'