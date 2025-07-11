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
    ll k;cin>>k;
    
    vl a(n);read(a);

    ll curr_b = 0;
    f(i, n) {
        curr_b += __builtin_popcountll(a[i]);
    }
    

    vl pref_power_of_2(63);
    pref_power_of_2[0] = 1;
    f1(i, 1, 63) {
        pref_power_of_2[i] = pref_power_of_2[i-1] * 2;
    }

    f1(i, 1, 63)
    {
        pref_power_of_2[i] += pref_power_of_2[i-1];
    }

    vl cost_to_add_ones;
    f(i, n) {
        ll x = a[i];

        // if (x == 0) {
        //     cost_to_add_ones.push_back(1);
        //     continue;
        // }

        int ind = 0;
        while (ind < 63) {
            if (!(x >> ind & 1)) {
                if (ind == 0) {
                    cost_to_add_ones.push_back(1);
                } else {
                    cost_to_add_ones.push_back(pref_power_of_2[ind] - pref_power_of_2[ind-1]);
                }
            }
            ind++;
        }
    
    }

    sortall(cost_to_add_ones);
    // was actually simple 
    // out(cost_to_add_ones);
    bool all_done = true;
    ll curr_cost = 0;
    ll num = 0;
    f(i, size(cost_to_add_ones)) {
        if (curr_cost + cost_to_add_ones[i] <= k) {
            curr_cost += cost_to_add_ones[i];
            num++;
        } else {
            all_done = false;
            break;
        }
        
    }

    cout<<num + curr_b;L;return;

    if (!all_done) {
        cout<<num + curr_b;L;return;
    }
    else {
        ll diff = k - curr_cost;
        // cout<<diff;L;
        ll ans = 0;
        f(i, n) {
            // convert each 0 bit to 1 in a[i]
            ll sm_pow_of_2 = 1;
            ll pow_of_2 = 0;
            ll x = a[i];
            if (x == 0) {
                pow_of_2 = 1;
                a[i] = 1;
            }
            else 
            {
                ll ind = 0;
                while (x >> ind) 
                {
                    ind++;
                }
                pow_of_2 = ind;
                a[i] = ind;
            }
        }
        ll left = a[0];
        ll right = 64;
        ll min_v = a[0];
        ll min_reqd = 0;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll reqd = 0;
            f(i, n) {
                if (a[i] < mid) {
                    reqd += pref_power_of_2[mid-1] - pref_power_of_2[a[i]-1];
                }
            }
            if (reqd <= diff) {
                min_v = mid;
                min_reqd = reqd;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        diff -= min_reqd;
        ll curr = 0;
        f(i, n) {
            if (a[i] <= min_v) {
                if (pref_power_of_2[min_v] - pref_power_of_2[min_v-1] <= diff) {
                    diff -= (pref_power_of_2[min_v] - pref_power_of_2[min_v-1]);
                    curr++;
                }
            }
        }
        ans = curr;
        f(i, n)
        {
            ans += max(min_v, a[i]);
        }
        cout<<ans;L;return;
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
