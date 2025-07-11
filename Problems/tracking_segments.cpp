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
#define read(a) f(i,n) cin>>a[i];

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

    vi l(m);
    vi r(m);

    f(i,m)
    {
        cin>>l[i]>>r[i];
    }
    
    int q;cin>>q;

    vi x(q);
    // vvi arr(q,vi(n,0));

    f(i,q)
    {
        int ind;cin>>ind;
        x[i] = --ind;
        // ind--;
        
        // if (i==0) arr[i][ind] = 1;
        // else 
        // {
        //     arr[i] = arr[i-1];
        //     arr[i][ind] = 1;
        // }
    }

    int start = 0;
    int end = q-1;
    int ans = -2;
    int mid;

    while (start<=end)
    {
        bool isfound = false;
        mid = (start+end)/2;
        vi prefix(n,0);
        f(i,mid+1)
        {
            prefix[x[i]]=1;
        }
        f1(i,1,n)
        {
            prefix[i]+=prefix[i-1];
        }
        // f1(i,1,n)
        // {
        //     arr[mid][i] += arr[mid][i-1];
        // }
        f(i,m)
        {
            int l1 = l[i];
            int r1 = r[i];
            l1--;r1--;
            if (l1==0) {if (2*(prefix[r1]) > (r1-l1+1)) {isfound = true;break;}}
            else 
            {
                if (2*(prefix[r1] - prefix[l1-1]) > (r1-l1+1)) 
                {
                    isfound = true;break;
                }
            }
        }
        if (isfound) 
        {
            ans = mid;
            end = mid - 1;
        }
        else 
        {
            start = mid + 1;
        }
    }

    cout<<ans+1;L;
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