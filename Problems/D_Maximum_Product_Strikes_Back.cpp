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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
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
    ll n;cin>>n;
    // ll k;cin>>k;
    
    vl a(n);read(a);

    // product must be positive, so even number of negs
    
    vpl zero_sep;
    bool new_start = true;

    f(i,n)
    {
        if (a[i] == 0)
        {
            // i++;
            new_start = true;
            continue;
        }
        else if (new_start)
        {
            zero_sep.push_back({i,i});
            new_start = false;
        }
        else 
        {
            zero_sep.back().second = i;
            // cout<<zero_sep.back().first<<" "<<zero_sep.back().second;L;
        }
    }

    // for each of the zero separated, 

    // cout<<zero_sep.size();L;
    // for (auto seg : zero_sep)
    // {
    //     cout<<seg.first<<" "<<seg.second;L;
    // }

    ll ans = 0;
    ll rem_left = 0;
    ll rem_right = n;

    for (auto seg : zero_sep)
    {
        ll start = seg.first;
        ll end = seg.second;
        ll neg_count = 0;

        f1(i,start,end+1)
        {
            if (a[i] < 0)
            {
                neg_count++;
            }
        }

        if (neg_count % 2 == 0)
        {
            ll prod = 0;
            f1(i,start,end+1)
            {
                prod += abs(a[i]) == 2 ? 1 : 0;
            }
            if (prod > ans)
            {
                ans = prod;
                rem_left = start;
                rem_right = n - end - 1;
            }
        }
        else 
        {
            ll left_prod = 0;
            ll right_prod = 0;
            bool start_mul = false;
            ll left_neg = -1;
            ll right_neg = -1;

            f1(i,start,end+1)
            {
                if (a[i] > 0 && !start_mul)
                {
                    continue;
                }
                else if (a[i] < 0 && !start_mul)
                {
                    start_mul = true;
                    left_neg = i;
                }
                else 
                {
                    left_prod += abs(a[i]) == 2 ? 1 : 0;
                }
            }

            start_mul = false;

            for (int i = end; i >= start; i--)
            {
                if (a[i] > 0 && !start_mul)
                {
                    continue;
                }
                else if (a[i] < 0 && !start_mul)
                {
                    start_mul = true;
                    right_neg = i;
                }
                else 
                {
                    right_prod += abs(a[i]) == 2 ? 1 : 0;
                }
            }
            // cout<<left_prod<<" "<<right_prod;L;
            // cout<<left_neg<<" "<<right_neg;L;
            if (left_prod > ans)
            {
                ans = left_prod;
                rem_left = left_neg+1;
                rem_right = n - end - 1;
            }
            
            if (right_prod > ans)
            {
                ans = right_prod;
                rem_left = start;
                rem_right = n - right_neg;
            }
            // cout<<ans;

        }
    }

    cout<<rem_left<<" "<<rem_right;L;


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
