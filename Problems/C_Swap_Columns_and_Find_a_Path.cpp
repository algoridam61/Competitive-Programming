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
 
int log1(int x,int b)
{
	int cnt = 0;
	while (x) {
		x /= b;
		cnt++;
	}
	return cnt;
}

vector<int> bit32_dec_to_binary(int n)
{
    vector<int> ans(32);
    for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
    return ans;
}

unsigned int nextPowerOf2(unsigned int n) {
    if (n == 0)
        return 1; // Smallest power of 2 for n=0 is 1.
    n--; // Subtract 1 to handle cases where n is already a power of 2.
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16; // For 32-bit integers, this handles all bits.
    return n + 1;
}
/*
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
*/
void solve()
{
    ll n;
    cin >> n;

    vl first(n), second(n);
    f(i, n) cin >> first[i];
    f(i, n) cin >> second[i];

    if (n == 1) {
        cout << first[0] + second[0];L;
        // return 0;
    }

    vpl new2(n);
    f(i, n) {
        new2[i].first = first[i] - second[i];
        new2[i].second = i;
    }

    rsortall(new2);

    ll indmax = -1;
    ll maxval = LLONG_MIN;

    f(i, n) {
        ll idx = new2[i].second;
        if (first[idx] + second[idx] > maxval) {
            maxval = first[idx] + second[idx];
            indmax = i;
        }
    }

    ll removeIdx = new2[indmax].second;
    first.erase(first.begin() + removeIdx);
    second.erase(second.begin() + removeIdx);

    vpl adjustedNew2;
    f(i, n) {
        if (i != indmax) {
            ll idx = new2[i].second;
            if (idx > removeIdx) idx--; 
            adjustedNew2.push_back({new2[i].first, idx});
        }
    }

    new2 = adjustedNew2;
    n--;

    vl pref(n, 0), suff(n, 0);
    pref[0] = first[new2[0].second];
    f1(i, 1, n) {
        pref[i] = pref[i - 1] + first[new2[i].second];
    }

    suff[n - 1] = second[new2[n - 1].second];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + second[new2[i].second];
    }

    ll ans = LLONG_MIN;
    f(i, n - 1) {
        ans = max(ans, pref[i] + suff[i + 1]);
    }

    ans = max(ans, max(pref[n - 1], suff[0]));
    cout << ans + maxval;L;


}
/*
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t=1;
    cin>>t;
 
    while(t--)
    {
        solve();
    }
}
