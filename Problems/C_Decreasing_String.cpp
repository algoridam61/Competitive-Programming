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
    string s;cin>>s;

    ll pos;cin>>pos;

    ll n = s.size();

    vl inv_indices;
    ll pushed = 0;
    ordered_set_pair<char, ll> os;
    vl done(n+1,0);
    f(i,n)
    {
        auto it = os.find_by_order(os.order_of_key({s[i], i}));

        auto it2 = os.find_by_order(size(os) - 1);

        if (it != os.end())
        {
            // cout<<it->first<<" "<<it->second<<" "<<i<<endl;
            // cout<<it2->first<<" "<<it2->second<<" "<<i<<endl;
            // L;
            vl curr;
            auto current_iterator = it; 
            while (current_iterator != os.end()) {
                curr.push_back(current_iterator->second); 
                auto iterator_to_erase = current_iterator;  
                current_iterator++;                         
                os.erase(iterator_to_erase);                
            }
            // for (auto it3 = it; it3 != os.end();)
            // {
            //     os.erase({it3->first,it3->second});
            //     curr.push_back(it3->second);
            // }
            // inv_indices.push_back({it2->second, it->second});
            for (int i = curr.size() - 1; i >= 0; i--)
            {
                inv_indices.push_back(curr[i]);
            }
            // for (int j = it2->second; j >= it->second; j--)
            // {
            //     if (done[j]) continue; // skip if already processed
            //     done[j] = 1; // mark as processed
            //     inv_indices.push_back(j);
            //     pushed++;
            //     os.erase({s[j], j});
            // }

            os.insert({s[i], i});
        }
        else
        {
            os.insert({s[i], i});
        }

        // output the ordered set for debugging
        // cout<<"Ordered Set: ";
        // for (const auto& p : os) {
        //     cout<<"("<<p.first<<", "<<p.second<<") ";
        // }
        // cout<<endl;

    }

    // out(inv_indices);

    // next we remove the inversion indices one by one
    // once we run out of inversion indices, we remove the last character

    // find out which string we want now. and for that string we find out what all inversions will be removed till now
    // we calculate that string only, we know what all will be removed before that and we precisely remove those characters

    ll tot_len = n*(n + 1) / 2; // total number of inversions in the string
    vl poss;
    ll curr_len = 0;
    f(i,n)
    {
        curr_len += (n - i);
        poss.push_back(curr_len);
    }
    ll ind = lower_bound(poss.begin(), poss.end(), pos) - poss.begin();
    ll posi;
  
    if (ind == 0) posi = pos - 1;
    else posi = pos - poss[ind - 1] - 1;

    ll remo_size = inv_indices.size();
    vl remo_ind;
    string ans;
    vl removed(n+1,0);

    f(i,ind)
    {
        if (i < inv_indices.size()) {remo_ind.push_back(inv_indices[i]);removed[inv_indices[i]] = 1;}
        else break;
    }

    string temp;
    f(i,n)
    {
        if (!removed[i])
        {
            temp += s[i];
        }
    }

    string new1;
    if (ind <= inv_indices.size()) {cout<<temp[posi];return;}

    for (int i = 0; i < temp.size() - (ind - remo_ind.size()); i++)
    {
        new1 += temp[i];
    }


    cout<<new1[posi];

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
