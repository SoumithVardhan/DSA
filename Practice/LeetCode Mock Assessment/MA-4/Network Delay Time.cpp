#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int solvebfs(vector<vector<int>>& times, int n, int k,
                  vector<vector<pair<int,int>>>& ngb) {

        // {node, distance}
        queue<pair<int,int>> q;
        vector<int> dist(n + 1, INT_MAX);

        q.push({k, 0});
        dist[k] = 0;

        while(!q.empty()) {
            int currentelement = q.front().first;
            int currentdist    = q.front().second;
            q.pop();

            for(int i = 0; i < ngb[currentelement].size(); i++) {
                int ngbele_of_curr_ele = ngb[currentelement][i].first;
                int weight             = ngb[currentelement][i].second;

                if(currentdist + weight < dist[ngbele_of_curr_ele]) {
                    dist[ngbele_of_curr_ele] = currentdist + weight;
                    q.push({ngbele_of_curr_ele, dist[ngbele_of_curr_ele]});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> ngb(n + 1);

        for(int i = 0; i < times.size(); i++) {
            int ele1 = times[i][0];  // source
            int ele2 = times[i][1];  // destination
            int ele3 = times[i][2];  // travel time
            ngb[ele1].push_back({ele2, ele3});
        }

        return solvebfs(times, n, k, ngb);
    }
};

int main() {
    Solution obj;

    // Example 1
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    cout << obj.networkDelayTime(times1, 4, 2) << "\n"; // 2

    // Example 2
    vector<vector<int>> times2 = {{1,2,1}};
    cout << obj.networkDelayTime(times2, 2, 1) << "\n"; // 1

    // Example 3: unreachable node
    vector<vector<int>> times3 = {{1,2,1}};
    cout << obj.networkDelayTime(times3, 2, 2) << "\n"; // -1

    return 0;
}