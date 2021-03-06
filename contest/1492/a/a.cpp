/* Generated by powerful Codeforces Tool
 * Author: czhang
 * Time: 2021-03-01 22:52:13
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long p, a, b, c;
    cin>>p>>a>>b>>c;

    long long res = min(min(
                p % a > 0 ? a - (p%a) : 0,
                p % b > 0 ? b - (p%b) : 0
                ), 
            p % c > 0 ? c - (p%c) : 0);
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 0;
    cin>>tc;
    for (int i = 0; i < tc; ++i) {
        solve();
    }
    return 0;
}
