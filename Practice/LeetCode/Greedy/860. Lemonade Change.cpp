#include <iostream>
#include <vector>   
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntfive=0,cntten=0,cnttwenty=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)cntfive++;
            else if(bills[i]==10){
                if(cntfive==0)return false;
                cntten++;cntfive--;
            }
            else{
                if(cntten>0 && cntfive>0){
                    cntten--;
                    cntfive--;
                }
                else if(cntfive>=3)cntfive-=3;
                else return false;
            }
        }return true;
    }
};