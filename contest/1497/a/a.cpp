/* Generated by powerful Codeforces Tool
 * Author: czhang
 * Time: 2021-03-17 23:41:42
**/

#include <bits/stdc++.h>
#include <valarray>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    valarray<int> count(120);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int p;
        cin>>p;
        count[p]++;
    }
    for (int i = 0; i < count.size(); ++i) {
        if (count[i]) {
            cout<<i<<' ';
            --count[i];
        }
    }

    for (int i = count.size() - 1; i >= 0; --i) {
        while (count[i]) {
            cout<<i<<' ';
            --count[i];
        }
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin>>tc;
    for (int i = 0; i < tc; ++i) {
        solve();
    }
    return 0;
}