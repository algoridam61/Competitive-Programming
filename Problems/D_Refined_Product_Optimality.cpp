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
using namespace std;
 
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

const ll MOD = 998244353;

// Function to calculate modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Function to calculate modular inverse
ll mod_inv(ll a, ll mod) {
    return mod_exp(a, mod - 2, mod); // Fermat's little theorem
}

void solve()
{
    int n; cin >> n;
    int q; cin >> q;

    vl a(n); read(a);
    vl b(n); read(b);
    vl c = a, d = b;
    sortall(c); sortall(d);

    ll ans = 1;
    f(i, n) {
        ans = (ans * min(c[i], d[i])) % MOD;
    }

    cout << ans << " ";
    while (q--) {
        int o; cin >> o;
        int x; cin >> x;

        if (o == 1) {
            // Element in `a` is increased
            int l = 0, h = n - 1;
            int key = a[x - 1];
            a[x - 1]++;
            int ind = -1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if (c[mid] == key) {
                    ind = mid;
                    l = mid + 1;
                } else if (c[mid] < key) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }

            ll old_min = min(c[ind], d[ind]);
            ll new_min = min(c[ind] + 1, d[ind]);
            ans = (ans * mod_inv(old_min, MOD) % MOD * new_min % MOD + MOD) % MOD;
            c[ind]++;
            cout << ans << " ";
        } else {
            // Element in `b` is increased
            int l = 0, h = n - 1;
            int key = b[x - 1];
            b[x - 1]++;
            int ind = -1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if (d[mid] == key) {
                    ind = mid;
                    l = mid + 1;
                } else if (d[mid] < key) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }

            ll old_min = min(c[ind], d[ind]);
            ll new_min = min(c[ind], d[ind] + 1);
            ans = (ans * mod_inv(old_min, MOD) % MOD * new_min % MOD + MOD) % MOD;
            d[ind]++;
            cout << ans << " ";
        }
    }
    L;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
}
