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

ll power(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n, ll mod = MOD) {
    return power(n, mod - 2);
}

ll calculate_nCr_mod_p(int n_val, int r_val, ll mod = MOD) {
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
        res = (res * (n_val - i)) % mod;
        res = (res * modInverse(i + 1)) % mod;
    }
    return res;
}

struct DisjointSet {
    vector<ll> parent, size;
    ll num_components;

    DisjointSet(ll n) : parent(n + 1), size(n + 1, 1), num_components(n) {
        for (ll i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void union_sets(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
            num_components--;
        }
    }
};
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
vl primes;
void sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

unordered_map<ll, unordered_map<ll, ll>> memo;
const int MEMO_LIMIT = 200000;
int memo_size = 0;

ll cal(ll x, ll k){
	vl div;
	for(ll i=1;i*i<=x;++i){
		if(x%i==0){
			div.emplace_back(i);
			if(i*i<x) div.emplace_back(x/i);
		}
	}
	sortall(div);
	vl dp(div.size(),INT_MAX);
	dp[0]=0;
	f1(i,1,div.size()){
		f1(j,0,i){
			if(div[i]%div[j]==0 && div[i]/div[j]<=k) dp[i]=min(dp[i],dp[j]+1);
		}
	}
	return dp[div.size()-1]<INT_MAX?dp[div.size()-1]:-1;
}

void solve() {
    ll x; cin >> x;
    ll k; cin >> k;
    ll maxi; cin >> maxi;
    vl bag1;
    vl bag2;

    ll gcd_ = __gcd(x, k);
    x /= gcd_;
    k /= gcd_;
    ll x1 = x;
    ll k1 = k;


    if (memo.count(x) && memo[x].count(maxi) && memo.count(k) && memo[k].count(maxi)) {
        cout << memo[x][maxi] + memo[k][maxi] << "\n";
        return;
    }

    for (ll prime : primes) {
        if (prime > x1) break;
        while (x1 % prime == 0) {
            x1 /= prime;
            bag1.push_back(prime);
        }
    }

    for (ll prime : primes) {
        if (prime > k1) break;
        while (k1 % prime == 0) {
            k1 /= prime;
            bag2.push_back(prime);
        }
    }

    if (bag1.size() == 0 && bag2.size() == 0) {
        cout << "0\n";
        return;
    }
    if ((bag1.size() && bag1.back() > maxi) || (bag2.size() && bag2.back() > maxi)) {
        cout << "-1\n";
        return;
    }

    cout<<cal(x, maxi) + cal(k, maxi)<<"\n";return;


    sortall(bag1);
    sortall(bag2);



    ll ans1 = 0;
    ll ans2 = 0;

    {
        int n1 = bag1.size();
        vpl best(1 << n1);
        best[0] = {1, 1};
        f1(mask, 1, (1 << n1)) {
            best[mask] = {n1 + 1, 1};
            f(i, n1) {
                if (mask & (1 << i)) {
                    pl prev = best[mask ^ (1 << i)];
                    if (prev.second * bag1[i] <= maxi)
                        best[mask] = min(best[mask], {prev.first, prev.second * bag1[i]});
                    else
                        best[mask] = min(best[mask], {prev.first + 1, bag1[i]});
                }
            }
        }
        if (n1) ans1 = best[(1 << n1) - 1].first;
    }

    {
        int n2 = bag2.size();
        vpl best2(1 << n2);
        best2[0] = {1, 1};
        f1(mask, 1, (1 << n2)) {
            best2[mask] = {n2 + 1, 1};
            f(i, n2) {
                if (mask & (1 << i)) {
                    pl prev = best2[mask ^ (1 << i)];
                    if (prev.second * bag2[i] <= maxi)
                        best2[mask] = min(best2[mask], {prev.first, prev.second * bag2[i]});
                    else
                        best2[mask] = min(best2[mask], {prev.first + 1, bag2[i]});
                }
            }
        }
        if (n2) ans2 = best2[(1 << n2) - 1].first;
    }

    if (memo_size < MEMO_LIMIT) {
        memo[x][maxi] = ans1;
        memo[k][maxi] = ans2;
        memo_size += 2;
    }

    cout << ans1 + ans2 << "\n";
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
    // dp.assign(1000001, -1);

    sieve(1000000);

    while(t--) {
        solve();
    }
}
