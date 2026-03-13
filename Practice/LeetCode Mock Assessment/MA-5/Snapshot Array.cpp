#include <iostream>
#include <vector>
using namespace std;

//MLE
class SnapshotArray {
public:
    int snapcnt=0;
    vector<vector<int>> snaparr;
    vector<int>v;
    SnapshotArray(int length) {
        v = vector<int>(length, 0);
    }
    
    void set(int index, int val) {
        v[index]=val;
    }
    
    int snap() {
        snaparr.push_back(v);
        snapcnt++;
        return snapcnt-1;
    }
    
    int get(int index, int snap_id) {
        return snaparr[snap_id][index];
    }
};

//Optimized
class SnapshotArray {
public:
    int snap_id = 0;
    vector<vector<pair<int,int>>> arr;

    SnapshotArray(int length) {
        arr.resize(length);
        for(int i=0;i<length;i++){
            arr[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        arr[index].push_back({snap_id,val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto &v = arr[index];
        
        int l = 0, r = v.size()-1;
        int ans = 0;
        
        while(l <= r){
            int mid = (l+r)/2;
            if(v[mid].first <= snap_id){
                ans = v[mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return ans;
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */