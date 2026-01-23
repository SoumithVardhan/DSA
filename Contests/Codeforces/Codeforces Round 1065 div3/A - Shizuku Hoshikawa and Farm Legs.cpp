#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        if(n%2!=0){cout<<0<<endl;continue;}
        int y=0,cnt=0,x=0;
        while((n-4*y)>=0){cnt++;y++;}
        cout<<cnt<<endl;
    }
    
    return 0;
}