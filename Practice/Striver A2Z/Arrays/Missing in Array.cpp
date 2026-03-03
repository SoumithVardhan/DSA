#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int size=arr.size()+1;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans^=arr[i];
            ans^=(i+1);
        }
        return ans^size;
    }
};
