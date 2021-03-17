/* Generated by powerful Codeforces Tool
 * Author: czhang
 * Time: 2021-03-09 23:07:33
**/

#include <bits/stdc++.h>
#include <valarray>

using namespace std;
typedef long long ll;

int count(const valarray<int> &imbalance) {
    int c = 0;
    for (auto v : imbalance) {
        c += v;
    }
    return c;
}

void solve() {
    int n, k;
    string s;
    cin>>n>>k>>s;

    if (n % k) {
        cout<<-1<<endl;
        return;
    }

    valarray<int> imbalance(200);
    for (auto c : s) {
        imbalance[c] = (imbalance[c] + k - 1) % k;
    }

    if (count(imbalance) == 0) {
        cout<<s<<endl;
        return;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (char ch = s[i] + 1; ch <= 'z'; ++ch) {
            imbalance[s[i]] = (imbalance[s[i]] + 1) % k;
            imbalance[ch] = (imbalance[ch] + k - 1) % k;

            int sum = count(imbalance);
            if (sum <= n - i - 1 && (n - i - 1 - sum) % k == 0) {
                cout<<s.substr(0, i);
                cout<<ch;
                for (int j = 0; j < (n - i - 1 - sum); ++j) {
                    cout<<'a';
                }
                for (char cc = 'a'; cc <= 'z'; ++cc) {
                    while (imbalance[cc]) {
                        cout<<cc;
                        imbalance[cc]--;
                    }
                }
                cout<<endl;
                return;
            }

            imbalance[ch] = (imbalance[ch] + 1) % k;
            imbalance[s[i]] = (imbalance[s[i]] + k - 1) % k;
        }
        imbalance[s[i]] = (imbalance[s[i]] + 1) % k;
    }
    cout<<-1<<endl;
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