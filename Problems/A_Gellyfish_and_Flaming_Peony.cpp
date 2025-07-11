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

template <class T> class BIT 
{
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, int val) { add(ind, val - arr[ind]); }

	void add(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

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
vi dp(5001, INT_MAX); 
vi a;
int smallest_gcd;
int solve_dp(int num)
{
    if (num == smallest_gcd) {
        return 0;
    }
    if (dp[num] != INT_MAX) {
        return dp[num];
    }
    int ans = INT_MAX;
    f(j, a.size()) {
        ll res = __gcd(num, a[j]);
        if (res < num) { // this was the most crucial step for me as i was thinking of 2 d dp
            ans = min(ans, 1 + solve_dp(res));
        }
    }
    return dp[num] = ans;
}
void solve() {
    int n;cin>>n;
    a.assign(n, 0);
    read(a);
    dp.assign(5001, INT_MAX);
    sortall(a);

    smallest_gcd = a[0];

    f(i, n) {
        smallest_gcd = __gcd(smallest_gcd, a[i]);
    }

    int count = 0;

    f(i, n) {
        if (a[i]!=smallest_gcd) {
            count++;
        }
    }

    if (count < n) {
        cout<<count<<"\n";return;
    } else {
        // f(i, n) {
        //     f1(j, i+1, n) {
        //         if (__gcd(a[i], a[j]) == smallest_gcd) {
        //             cout<<count<<"\n";return;
        //         }
        //     }
        // }
        // what is the minimum number of operations needed to form smallest_gcd
        // dp approach 
        // dp[i] = minimum number of operations needed to form smallest_gcd from a[0] to a[i]
        // dp[i] will denote minimum operations needed to make a[i] equal to smallest_gcd
        int ans = INT_MAX;
        f(i, n) {
            ans = min(ans, solve_dp(a[i]));
        }

        cout<< n - 1 + ans << "\n";
        return;
        
    }
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }
}
