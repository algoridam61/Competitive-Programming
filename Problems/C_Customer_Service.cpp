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
void solve()
{
    ll n;cin>>n;
    vvl a(n,vl(n));

    f(i,n)
    {
        f(j,n)
        {
            cin>>a[i][j];
        }
    }
    vpl streak;
    f(i,n)
    {
        ll cnt = 0;
        for (int j = n-1;j>=0;j--)
        {
            // cout<<a[i][j]<<" ";
            if (a[i][j]==1)
            {
                cnt++;
            }
            else 
            {
                break;
            }
        }
        if (cnt>0)
        {
            streak.push_back({cnt,i});
        }
    }



    sortall(streak);
    ll ans = 1;

    ll j = 0;
    vl usedt(n,0);
    vl usedn(n,0);
    // yes
    // for (auto i : streak)
    // {
    //     // yes
    //     cout<<i.first<<" "<<i.second;L;
    // }
    f(k,n-1)
    {
        // find the smallest element in streak that is greater than equal to ans. move the pointer to 
        // the next element and increment ans by 1.
        ll temp = -1;
        for (ll i = 0;i<streak.size();i++)
        {
            if (streak[i].first>=ans && usedt[ans-1]==0 && usedn[streak[i].second]==0)
            {
                temp = i;
                j = i+1;
                usedt[ans-1] = 1;
                usedn[streak[i].second] = 1;
                ans++;
                break;
            }
        }
        if (temp==-1)
        {
            break;
        }
        // ans++;
        // j = temp+1;
    }

    cout<<ans;L;return;


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
