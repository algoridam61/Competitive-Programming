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
    ll k;cin>>k;
    
    string s;cin>>s;

    vvl next(k, vl(n,n));

    for (int i = 0; i < k; i++)
    {
        int last = n;
        for (int j = n-1; j >= 0; j--)
        {
            if (s[j] == 'a' + i)
            {
                last = j;
            }
            next[i][j] = last;
            // cout<<i<<" "<<j<<" "<<next[i][j]<<" ";L;
        }
        // L;
    }

    vl dp(n+1, 0);

    // matched till i

    dp[n] = 0;
    dp[n-1] = 1;

    for (int i = n-2; i >= 0; i--)
    {
        ll ans = LLONG_MAX;
        // if (s[i] == s[i+1])
        
            for (int j = 0; j < k; j++)
            {
                // if ('a' + j != s[i])
                // {
                //     ans = min(ans,1 + dp[next[j][i]]);
                // }
                // else 
                // {
                    ans = min(ans, 1 + dp[next[j][i+1]]);
                // }
            }
        
        // else 
        // {
        //     for (int j = 0; j < k; j++)
        //     {
        //         ans = min(ans, 1 + dp[next[j][i+1]]);
        //     }
        // }
        dp[i] = ans;
    }

    ll q;cin>>q;
    // f(i,n+1)
    // {
    //     cout<<i<<" "<<dp[i]<<" ";L;
    // }

    while (q--)
    {
        string t;cin>>t;
        ll ans = 0;
        ll curr_ind = 0;
        bool flag = false;
        for (int i = 0; i < t.size(); i++)
        {
            if (curr_ind >= n)
            {
                cout<<0;L;flag = true;break;
            }

            

            curr_ind = next[t[i] - 'a'][curr_ind];
            curr_ind++;
        }
        if (flag)
            continue;
        ans = dp[curr_ind-1];
        cout<<ans;L;
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
