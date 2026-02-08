#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
//Approach1:
bool checkValidString(string s) {
    // CORE CONCEPT: Track the RANGE [leftMin, leftMax] of possible unmatched '(' at each step
    // leftMin = minimum possible unmatched '(' (pessimistic - treat '*' as ')' or empty)
    // leftMax = maximum possible unmatched '(' (optimistic - treat '*' as '(')
    // If a valid interpretation exists, it will fall within this range
    
    int leftMin = 0, leftMax = 0;
    
    for (char c : s) {
        if (c == '(') {
            // Definitely adds 1 unmatched '('
            // Both min and max increase by 1
            leftMin++;
            leftMax++;
        } 
        else if (c == ')') {
            // Definitely closes 1 '('
            // Both min and max decrease by 1
            leftMin--;
            leftMax--;
        } 
        else {  // c == '*'
            // '*' can be ')', '(', or empty
            // Best case (for min): treat as ')' or empty → decreases unmatched '('
            // Worst case (for max): treat as '(' → increases unmatched '('
            leftMin--;  // Treat '*' as ')' to minimize open parens
            leftMax++;  // Treat '*' as '(' to maximize open parens
        }
        
        // CHECK 1: If leftMax < 0, too many ')' exist
        // Even treating ALL '*' as '(', we still have excess ')'
        // Example: "())" → leftMax becomes -1 → impossible to balance
        if (leftMax < 0) return false;
        
        // CHECK 2: If leftMin < 0, reset to 0
        // Negative leftMin means we treated '*' too pessimistically
        // Reset to 0 because we can treat earlier '*' as empty or ')' to balance
        // Example: "*)" → leftMin = -1 after ')' → reset to 0 (valid by treating '*' as '(')
        if (leftMin < 0) leftMin = 0;
    }
    
    // FINAL CHECK: Can all '(' be balanced?
    // leftMin == 0 means there exists a valid interpretation where all '(' are matched
    // leftMin > 0 means too many '(' that can't be balanced even with '*' as ')'
    // Example: "(((" → leftMin = 3 → invalid (3 unmatched '(')
    // Example: "(*)" → leftMin = 0 → valid (can treat '*' as ')')
    return leftMin == 0;
    
    // VALID EXAMPLES:
    // "(*)" → [1,1] → [0,2] → [0,1] → leftMin=0 ✅
    // "(())" → all balanced naturally ✅
    
    // INVALID EXAMPLES:
    // "())" → leftMax=-1 at step 3 ❌ (too many ')')
    // "(((" → leftMin=3 at end ❌ (too many '(')
    // "*(" → leftMin=1 at end ❌ ('*' before '(' can't close it)
}



//Approach2: Two Pass Greedy
bool checkValidString2(string s) {
    int leftp=0,star=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')leftp++;
        else if(s[i]==')'){
            if(leftp==0 && star==0)return false;
            else if(leftp!=0)leftp--;
            else star--;
        }
        else star++;
    }
    int rightp=0; star=0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]==')') rightp++;
        else if(s[i]=='('){
            if(rightp==0 && star==0) return false;
            else if(rightp!=0) rightp--;
            else star--;
        }
        else star++;
    }
    
    return true;
}
};