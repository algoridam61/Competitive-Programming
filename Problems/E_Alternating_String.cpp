#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <climits>
 
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,a,b) for(int i=a;i<b;i++)
#define vl vector<ll>
#define vvl vector<vl>
#define vi vector<int>
#define vvi vector<vi>
#define L cout<<"\n"
#define pl pair<ll,ll>
#define INF (unsigned)!((int)0)
#define sortall(a) sort(a.begin(),a.end())
#define rsortall(a) sort(a.begin(), a.end(), [](const auto &x, const auto &y) { return x > y; });
#define max1(a) *max_element(a.begin(), a.end())
#define min1(a) *min_element(a.begin(), a.end())
#define no {cout<<"NO";L;return;}
#define yes {cout<<"YES";L;return;}
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define vvpi vector<vector<pair<int,int>>>
#define vpl vector<pair<ll,ll>>
#define vvpl vector<vector<pair<ll,ll>>>
#define read(a) f(i,size(a)) cin>>a[i];
#define out(a) f(i,size(a)) if (i!=size(a)-1) cout<<a[i]<<" "; else cout<<a[i];L;

const ll MOD = 1000000007;
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vvl suff1(n+1, vl(26, 0));
    vvl pref1(n+1, vl(26, 0));
    vvl suff2(n+1, vl(26, 0));
    vvl pref2(n+1, vl(26, 0));

    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
            pref1[i + 1] = pref1[i];
            pref1[i + 1][s[i] - 'a']++;
            pref2[i + 1] = pref2[i];
            } else {
            pref2[i + 1] = pref2[i];
            pref2[i + 1][s[i] - 'a']++;
            pref1[i + 1] = pref1[i];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) {
                suff1[i] = suff1[i + 1];
                suff2[i] = suff2[i + 1];
            }

            if ((i + 1) < n && (i + 1) % 2 == 0) {
                suff1[i][s[i + 1] - 'a']++;
            } else if ((i + 1) < n) {
                suff2[i][s[i + 1] - 'a']++;
            }
        }

        ll ans = INT_MAX;
        f(i, n) {
            
            auto odds1 = pref1[i];
            auto evens1 = pref2[i];

            auto odds2 = suff2[i];
            auto evens2 = suff1[i];

            ll max1 = 0;
            ll max2 = 0;
            for (int c = 0; c < 26; c++) {
                max1 = max(max1, odds1[c] + odds2[c]);
            }
            for (int c = 0; c < 26; c++) {
                max2 = max(max2, evens1[c] + evens2[c]);
            }

            ans = min(ans, n - max1 - max2);
            
        }
        cout << ans;
        L;
        return;
    } else {
        vl even(26, 0);
        vl odd(26, 0);

        f(i, n) {
            if (i % 2 == 0) {
                even[s[i] - 'a']++;
            } else {
                odd[s[i] - 'a']++;
            }
        }

        ll max1 = 0;
        for (int c = 0; c < 26; c++) {
            max1 = max(max1, odd[c]);
        }
        ll max2 = 0;
        for (int c = 0; c < 26; c++) {
            max2 = max(max2, even[c]);
        }

        cout << n - max1 - max2;
        L;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
}
