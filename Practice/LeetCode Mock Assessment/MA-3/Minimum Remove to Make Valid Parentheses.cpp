#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')')ans+=s[i];
            else{
                if(st.empty() && s[i]==')'){
                    continue;
                }
                else if(!st.empty() && st.top()=='(' && s[i]==')'){
                    ans+=s[i];
                    st.pop();
                }
                else if(s[i]=='('){
                    ans+=s[i];
                    st.push('(');
                }
            }
        }
        int maxsize=st.size();
        string finalres="";
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=='(' && maxsize>0){
                maxsize--;
                continue;
            }
            finalres.push_back(ans[i]);
        }
            reverse(finalres.begin(), finalres.end());
        return finalres;
    }
};
