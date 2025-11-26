#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	while(n--){
	    int cnt=0;
	    int num;cin>>num;
	    if(num<=2)cout<<0<<endl;
	    else{
	        cout<<(num-2)*(num-2)/4<<endl;
	    }
	}
}
