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
void solve() {
    ll n;cin>>n;
    ll m;cin>>m;

    vl a(n);read(a);

    sortall(a);

    vpl num_and_freq;
    ll prev = a[0];
    ll freq = 1;
    for (ll i = 1; i < n; i++) {
        if (a[i] == prev) {
            freq++;
        } else {
            num_and_freq.push_back({prev, freq});
            prev = a[i];
            freq = 1;
        }
    }
    num_and_freq.push_back({prev, freq});

    // for (auto p : num_and_freq) {
    //     cout<<p.first<<" "<<p.second<<"\n";
    // }
    // return;

    vpl ind_and_streak;
    ll curr_streak = m-1;
    // we need streaks of length m 
    int i = 0;
    // cout<<num_and_freq.size()<<"\n";
    // return;
    while (i < (int)(num_and_freq.size()) - (int)(m) + 1) {
        // yes
        if (num_and_freq[i].first - num_and_freq[i+m-1].first == 1 - m ) {
            i++;
            curr_streak++;
        } else {
            if (curr_streak >= m) {
                ind_and_streak.push_back({i - (curr_streak - m + 1), curr_streak});
            }
            i++;
            curr_streak = m-1;
        }
    }
    if (curr_streak >= m) {
        ind_and_streak.push_back({i - (curr_streak - m + 1), curr_streak});
    }

    ll ans = 0;
    // cout<<ind_and_streak.size()<<"\n";return;

    for (auto p : ind_and_streak) {
        ll inds = p.first;
        ll inde = p.second - m;

        ll mul = 1;
        for (ll j = inds; j < inds + m; j++) {
            mul = (mul * num_and_freq[j].second) % MOD;
        }
        ans = (ans + mul) % MOD;
        for (ll j = inds + 1; j <= inde; j++) {
            ll newm = num_and_freq[j+m-1].second;
            ll oldm = num_and_freq[j-1].second;
            mul = (mul * modInverse(oldm)) % MOD;
            mul = (mul * newm) % MOD;
            ans = (ans + mul) % MOD;
        }
    }
    cout<<ans<<"\n";
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
