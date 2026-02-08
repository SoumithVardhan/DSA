#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Approach1: Sort by value-to-weight ratio and take items greedily
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int,int>> items(n);
        
        for(int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }
        
        // Lambda comparator
        sort(items.begin(), items.end(), [](auto& a, auto& b) {
            return (double)a.first/a.second > (double)b.first/b.second;
        });
        
        double ans = 0;
        for(auto& item : items) {
            if(item.second <= capacity) {
                ans += item.first;
                capacity -= item.second;
            } else {
                ans += ((double)capacity / item.second) * item.first;
                break;
            }
        }
        return ans;
    }

    //...
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double,int>> ratio(n);

        // store ratio and index
        for(int i = 0; i < n; i++) {
            ratio[i] = {(double)val[i] / wt[i], i};
        }

        // sort by ratio descending
        sort(ratio.rbegin(), ratio.rend());

        double ans = 0;
        for(int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            if(wt[idx] <= capacity) {
                ans += val[idx];
                capacity -= wt[idx];
            } else {
                ans += ((double)capacity / wt[idx]) * val[idx];
                break; // capacity exhausted
            }
        }
        return ans;
    }
};