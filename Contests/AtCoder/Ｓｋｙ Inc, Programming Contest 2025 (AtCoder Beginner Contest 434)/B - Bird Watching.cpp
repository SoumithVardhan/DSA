#include <iostream>
#include <unordered_map>
using namespace std;

string solve(long long sum, long long cnt, int precision = 20) {
    long long integer = sum / cnt;
    long long rem = sum % cnt;

    string result = to_string(integer);
    result += ".";

    for (int i = 0; i < precision; i++) {
        rem *= 10;
        result += char('0' + (rem / cnt));
        rem %= cnt;
    }

    return result;
}

int main() {
    int n,m;cin>>n>>m;
    unordered_map<int,pair<long long,long long> >mp;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        mp[a].first++;
        mp[a].second+=b;

    }

    for (int type = 1; type <= m; type++) {
        if (mp.count(type)) {
            long long cnt = mp[type].first;
            long long sum = mp[type].second;
            cout << solve(sum,cnt,20) << "\n";
        } else {
            cout << "0.00000000000000000000\n";
        }
    }
}
