#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>output;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0,total=row*col;
        int startingrow=0;
        int endingrow=row-1;
        int startingcol=0;
        int endingcol=col-1;
       while(count<total){
            for(int i=startingcol;(count<total && i<=endingcol);i++){
                output.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            for(int i=startingrow;(count<total && i<=endingrow);i++){
                output.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            for(int i=endingcol;(count<total && i>=startingcol);i--){
                output.push_back(matrix[endingrow][i]);
                count++;
            }
           endingrow--;
            for(int i=endingrow;(count<total && i>=startingrow);i--){
                output.push_back(matrix[i][startingcol]);
                count++;
            }
           startingcol++;

       }
        return output;
    }
};