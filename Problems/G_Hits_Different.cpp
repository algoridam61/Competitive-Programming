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
// int dp[2047277];
// map<int,int> dp;
// int level[2047277];
// int index_within_level[2047277];
// map<pi,int> mp;
vl bounds;
// ll dp[2047277];

// ll solvedp(ll i,bool valid)
// {
//     if (dp[i]!=-1&&valid) {return dp[i];}
//     if (i == 1) 
//     {
//         dp[1] = 1ll;
//         return 1ll;
//     }
    
//     // dp[i] = 1;
//     ll ans = i*i;
//     // cout<<ans;L;
//     // find the index with value just less 
//     // than i
//     int left = 0;
//     int right = size(bounds) - 1;
//     int ind = -1;
//     while (left <= right)
//     {
//         int mid = ( left + right ) / 2;
//         if (bounds[mid]<=i)
//         {
//             left = mid + 1;
//             ind = mid;
//         }
//         else 
//         {
//             right = mid - 1;
//         }
//     }
//     int curr_level = ind+2;
//     int curr_index = i - bounds[ind];
//     if (curr_index == 0)
//     {
//         curr_level--;
//         curr_index = curr_level;
//     }

//     // cout<<curr_level<<" "<<curr_index;L;

//     if (curr_index == 1)
//     {
//         int new_index = curr_index;
//         int new_level = curr_level - 1;

//         int i1 = new_level*(new_level-1)/2 + new_index;
//         // cout<<i1;L;
//         // if (!dp[i1]) 
//         // {
//             return dp[i] = solvedp(i1,1)+ans;
//         // }
//         // else 
//         // {
//         //     return ans;
//         // }
//     }
//     else if (curr_index == curr_level)
//     {
//         int new_index = curr_index - 1;
//         int new_level = curr_level - 1;
//         int i1 = new_level*(new_level-1)/2 + new_index;
//         // if (!dp[i1]) 
//         // {
//         //     return solvedp(i1)+ans;
//         // }
//         // else 
//         // {
//         if (valid)
//             return dp[i] = ans + solvedp(i1,1);
            
//         return ans;
//         // }
//     }
//     else 
//     {
//         int new_index1 = curr_index;
//         int new_index2 = curr_index - 1;
//         int new_level = curr_level - 1;
//         int i1 = new_level*(new_level-1)/2 + new_index1;
//         int i2 = new_level*(new_level-1)/2 + new_index2;
//         if (valid)
//         {
//             return dp[i] = solvedp(i1,0) + solvedp(i2,1) + ans;
//         }
//         else 
//         {
//             return solvedp(i1,0) + ans;
//         }
//         // if (!dp[i1] && !dp[i2])
//         // {
//         //     return solvedp(i1) + solvedp(i2) + ans;
//         // }
//         // else if (!dp[i1])
//         // {
//         //     return solvedp(i1) + ans;
//         // }
//         // else if (!dp[i2])
//         // {
//         //     return solvedp(i2) + ans;
//         // }
//         // else return ans;
//     }

// }

// void solve()
// {
//     int n;cin>>n;
    
//     // dp.clear();
//     // cout<<dp[1];L;return;

//     cout<<solvedp(n,1);L;

// }
// Global definition of memo for both valid states.
// We'll use dp2[i][0] for valid==false and dp2[i][1] for valid==true.
const int MAXN = 2047277; 
ll dp2[MAXN][2];  

void init_dp2() {
    memset(dp2, -1, sizeof(dp2));
}

ll solvedp(ll i, bool valid) {
    int v = valid ? 1 : 0;
    if (dp2[i][v] != -1) {
        return dp2[i][v];
    }
    if (i == 1) {
        dp2[1][1] = 1ll; 
        return 1ll;
    }
    
    ll ans = i * i;
    int left = 0, right = (int)bounds.size() - 1;
    int ind = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (bounds[mid] <= i) {
            left = mid + 1;
            ind = mid;
        } else {
            right = mid - 1;
        }
    }
    
    int curr_level = ind + 2;
    int curr_index = i - bounds[ind]; 
    if (curr_index == 0) {
        curr_level--;
        curr_index = curr_level;
    }
    
    ll ret;
    if (curr_index == 1) {
        int new_index = curr_index;
        int new_level = curr_level - 1;
        int i1 = new_level * (new_level - 1) / 2 + new_index;
        ret = solvedp(i1, true) + ans;
    }
    else if (curr_index == curr_level) {
        int new_index = curr_index - 1;
        int new_level = curr_level - 1;
        int i1 = new_level * (new_level - 1) / 2 + new_index;
        if (valid)
            ret = ans + solvedp(i1, true);
        else
            ret = ans;
    }
    else {
        int new_index1 = curr_index;
        int new_index2 = curr_index - 1;
        int new_level = curr_level - 1;
        int i1 = new_level * (new_level - 1) / 2 + new_index1;
        int i2 = new_level * (new_level - 1) / 2 + new_index2;
        if (valid)
            ret = solvedp(i1, false) + solvedp(i2, true) + ans;
        else
            ret = solvedp(i1, false) + ans;
    }
    
    dp2[i][v] = ret;
    return ret;
}

void solve() {
    int n; cin >> n;
    
    cout << solvedp(n, true) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    init_dp2();
    bounds.clear();
    bounds.push_back(1);
    ll prev = 1;
    for (int i = 2; i < 2026; i++) {
        ll curr = i + prev;
        bounds.push_back(curr);
        prev = curr;
    }
    
    while (t--) {
        solve();
    }
    return 0;
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
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
 
//     int t=1;
//     cin>>t;
//     f(i,2047277) dp[i] = -1ll;

//     // level[1] = 1;
//     // index_within_level[1] = 1;
//     // int i = 2;
//     // int curr_level = 2;
//     // int curr_ele = 0;
//     // while (curr_level<=2023)
//     // {
//     //     curr_ele++;
//     //     if (curr_ele > curr_level)
//     //     {
//     //         curr_ele = 0;
//     //         curr_level++;
//     //         continue;
//     //     }
//     //     else 
//     //     {
//     //         level[i] = curr_level;
//     //         index_within_level[i] = curr_ele;
//     //         i++;
//     //     }
//     // }

//     // for (int i = 1; i <= 2047276; i++)
//     // {
//     //     mp[{index_within_level[i],level[i]}] = i;
//     // }
//     // cout<<i-1;L;
//     bounds.push_back(1);
//     ll prev = 1;
//     f1(i,2,2026)
//     {
//         ll curr = i + prev;
//         bounds.push_back(curr);
//         prev = curr;
//     }
//     // cout<<bounds[4];return 1;

//     while(t--)
//     {
//         solve();
//     }
// }
