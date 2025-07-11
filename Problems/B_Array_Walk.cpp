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

bool checkpresent(vi sorted_vector, int target)
{
int n=size(sorted_vector);
int l=0;int h=n-1;
while(l<=h)
{
    int mid=(l+h)/2;
    if (sorted_vector[mid]==target)
    {return true;}
    else if (sorted_vector[mid]>target)
    {
        l=mid;
    }
    else h=mid;
}
return false;

}
 
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
// ################################################################################
// ################################################################################
// ################################################################################
// ################################################################################
// ################################################################################
// ################################################################################
// */
// const int MAXK = 1000;  // reduced from 5000
// const int MAXZ = 1000;   // reduced from 5000
// ll memo[MAXK+1][MAXZ+1][2];

// void init_memo() {
//     memset(memo, -1, sizeof(memo));
// }

// ll dp(int n, int k, int z, int left_moves, int moves_done, vl& a, bool left_blocked) {
//     if (moves_done == k) return 0;
    
//     int curr_ind = moves_done - 2*left_moves;
//     if (curr_ind < 0 || curr_ind >= n) return 0;
    
//     // Check memo bounds before access
//     if (moves_done <= MAXK && left_moves <= MAXZ && 
//         memo[moves_done][left_moves][left_blocked] != -1)
//         return memo[moves_done][left_moves][left_blocked];
    
//     ll result = 0;
//     if (left_moves == z) {
//         ll sum = 0;
//         for (int i = curr_ind; i < min(curr_ind + k - moves_done, n); i++) {
//             sum += a[i];
//         }
//         result = sum;
//     } else {
//         if (left_blocked) {
//             result = a[curr_ind] + dp(n, k, z, left_moves, moves_done + 1, a, false);
//         } else {
//             result = a[curr_ind] + dp(n, k, z, left_moves, moves_done + 1, a, false);
//             if (curr_ind > 0)
//                 result = max(result, a[curr_ind] + 
//                     dp(n, k, z, left_moves + 1, moves_done + 1, a, true));
//         }
//     }
    
//     // Store in memo only if within bounds
//     if (moves_done <= MAXK && left_moves <= MAXZ)
//         memo[moves_done][left_moves][left_blocked] = result;
    
//     return result;
// }

void solve() {
    int n;cin>>n;
    int k;cin>>k;
    int z;cin>>z;

    vl a(n);read(a);
    
    // dp depends on k and moves to the left

    // cout<<dp(n,k,z,0,2,a,false);L;
    ll ans = 0;
    f(i,z+1)
    {
        // the number of moves to the left
        ll index = k - 2*i;
        if (index<0) continue;
        ll sum = 0;
        ll max1 = 0;
        f(j,index+1)
        {
            sum+=a[j];
            if (j<n-1)
            {
                max1 = max(max1,a[j]+a[j+1]);
            }
        }
        sum+=i*max1;
        ans = max(ans,sum);
    }

    cout<<ans;L;
 
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