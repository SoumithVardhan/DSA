#include <iostream>
#include <vector>       
using namespace std;


class Solution {
  public:
    //Approach1: Brute Force (TLE)
    // The idea is to iterate through each train and for that train,
    // check how many other trains have overlapping timings with it 
    // where current train's arrival time falls between the other train's arrival and departure times.
    // We keep track of this count for each train and continuously update our answer with the maximum count found.
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    //arr[i] should be in the middle when compared to other j trains
                    if (arr[i] >= arr[j] && dep[j] >= arr[i]) {
                        cout<< arr[i] <<" "<<arr[j]<<" "<<dep[j]<<" "<< arr[i]<<" "<<endl;
                        cnt++;
                    }
                
                }
            }
            ans=max(ans,cnt);
        }return ans;
    }

    //Approach2: Sort and Count
    // Sort the arrival and departure times separately.
    // Use two pointers to traverse both sorted arrays:
    // If the arrival time at pointer i is less than or equal to the departure time at pointer j,
    // it means a train has arrived before the previous one departs, so we increment the
    // platform count and move the arrival pointer i to the next train.
    // If the arrival time at pointer i is greater than the departure time at pointer j,
    // it means a train has departed before the next one arrives, so we decrement the platform count and move the departure pointer j to the next train.
    // We keep track of the maximum platform count at each step to find the minimum number of platforms required.

    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        // Sort both arrays
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms_needed = 0;
        int max_platforms = 0;
        int i = 0, j = 0;
        
        // Two pointer approach
        while (i < n) {
            // If next event is arrival
            if (arr[i] <= dep[j]) {
                platforms_needed++;  // Need one more platform
                max_platforms = max(max_platforms, platforms_needed);
                i++;
            }
            // If next event is departure
            else {
                platforms_needed--;  // Free up one platform
                j++;
            }
        }
        
        return max_platforms;
    }
};