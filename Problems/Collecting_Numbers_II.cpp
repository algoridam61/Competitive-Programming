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
    int n;cin>>n;
    int m;cin>>m;
    
    vi a(n);read(a);

    // vi tails;

    set<int> s;
    // map<int,int> ind;
    vi ind(n+1);
    ll ans = 0;
    f(i,n)
    {
        ind[a[i]] = i;
    }
    // new target, just make the tails out of the array
    f(i,n)
    {
        if (s.find(a[i]-1)==s.end())
        {
            s.insert(a[i]);
            // tails.push_back(a[i]);
            ans++;
        }
        else 
        {
            s.erase(a[i]-1);
            s.insert(a[i]);
        }
    }
    // sortall(tails);
    // int ans = size(tails);
    // cout<<ans<<endl;
    while (m--)
    {
        ll x,y;cin>>x>>y;
        
        x--;y--;
        int l = a[x];
        int r = a[y];
        swap(a[x],a[y]);

        // consider all the cases

        // first consider the changes due to a[y] moving to a[x]
        // if y > x and y is moving backward
        // if because of moving backward, it moves behind where a[x]+1 was then we reduce the number of 
        // tails by 1 

        if (l+1<=n && x < ind[l+1] && y >= ind[l+1]) ans++;
        if (l-1>=1 && x < ind[l-1] && y >= ind[l-1]) ans--;
        if (l-1>=1 && x > ind[l-1] && y <= ind[l-1]) ans++;
        if (l+1<=n && x > ind[l+1] && y <= ind[l+1]) ans--;
        ind[l] = y;

        if (r+1<=n && y > ind[r+1] && x <= ind[r+1]) ans--;
        if (r-1>=1 && y > ind[r-1] && x <= ind[r-1]) ans++;
        if (r-1>=1 && y < ind[r-1] && x >= ind[r-1]) ans--;
        if (r+1<=n && y < ind[r+1] && x >= ind[r+1]) ans++;
        ind[r] = x;

        cout<<ans<<endl;




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
