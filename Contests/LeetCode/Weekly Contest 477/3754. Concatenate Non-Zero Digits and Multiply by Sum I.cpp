#include <iostream>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        int valueofsum=0;
        string result="";
        while(n>0){
            int rem=n%10;
            if(rem!=0){
                result=to_string(rem)+result;
                valueofsum+=rem;
            }
            n/=10;
        }return stoll(result)*valueofsum;
    }
};