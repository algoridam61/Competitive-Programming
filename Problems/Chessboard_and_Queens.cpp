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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
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
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2>
using ordered_set_pair = tree<std::pair<T1, T2>, null_type, std::less<std::pair<T1, T2>>, rb_tree_tag, tree_order_statistics_node_update>;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll calculate_nCr_mod_p(int n_val, int r_val) {
    if (r_val < 0 || r_val > n_val) {
        return 0;
    }
    if (r_val == 0 || r_val == n_val) {
        return 1;
    }
    if (r_val > n_val / 2) {
        r_val = n_val - r_val;
    }
    ll res = 1;
    for (int i = 0; i < r_val; ++i) {
        res = (res * (n_val - i)) % MOD;
        res = (res * modInverse(i + 1)) % MOD;
    }
    return res;
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
    vector<string> chess1(8);
    f(i, 8) {
        cin >> chess1[i];
    }
    vector<string> chess = chess1;
    ll permutations = 8*7*6*5*4*3*2*1;
    vl perm = {0, 1, 2, 3, 4, 5, 6, 7};
    ll count = 0;
    while (true)
    {
        bool valid = true;
        f(i, 8)
        {
            if (chess[i][perm[i]] == '*') {valid = false;break;}
            chess[i][perm[i]] = 'Q';
        }
        if (valid)
        {
            f(i, 8)
            {
                f(j, 8)
                {
                    if (chess[i][j] == 'Q')
                    {
                        // check row
                        f(k, 8)
                        {
                            if (k != j && chess[i][k] == 'Q') {
                                valid = false;
                            }
                        }
                        // check column
                        f(k, 8)
                        {
                            if (k != i && chess[k][j] == 'Q') {
                                valid = false;
                            }
                        }
                        // check diagonals
                        f(k, 8)
                        {
                            if (i + k < 8 && j + k < 8 && k != 0 && chess[i + k][j + k] == 'Q') {
                                valid = false;
                            }
                            if (i - k >= 0 && j - k >= 0 && k != 0 && chess[i - k][j - k] == 'Q') {
                                valid = false;
                            }
                            if (i + k < 8 && j - k >= 0 && k != 0 && chess[i + k][j - k] == 'Q') {
                                valid = false;
                            }
                            if (i - k >= 0 && j + k < 8 && k != 0 && chess[i - k][j + k] == 'Q') {
                                valid = false;
                            }
                        }
                    }
                }
            }
        }
        if (valid) count++;
        chess = chess1;
        if (!next_permutation(perm.begin(), perm.end())) {
            break;
        }
    }
    cout << count << "\n";
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
    // cin>>t;
 
    while(t--)
    {
        solve();
    }
}
