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
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve()
{
    ll n;cin>>n;ll m;cin>>m;
    ll k;cin>>k;
    
    // vl a(n);read(a);

    // case 1 if k is divisible by m
    // case 2 if k is divisible by n
    // case 3 k has some common factors with n and m

    if (m%k==0)
    {
        for (int var = 0;var < n;var++)
        {
            if (var%2)
            {
                for (int i = 0;i < m / k;i++)
                {
                    for (int j = 0;j < k;j++)
                    {
                        cout<<j+1<<" ";
                    }
                    // cout<<endl;
                }
            }
            else 
            {
                for (int i = 0;i < m / k;i++)
                {
                    for (int j = 0;j < k;j++)
                    {
                        // cout 2,3,...k,1
                        if (j==k-1)
                        {
                            cout<<1<<" ";
                        }
                        else 
                        {
                            cout<<j+2<<" ";
                        }
                    }
                    // cout<<endl;
                }
            }
            cout<<endl;
        }
        return;
    }


    if (n%k==0)
    {
        // cout<<"hello\n";
        // output the transpose of the above matrix
        for (int var = 0;var < n/k;var++)
        {
            for (int j = 0;j < k;j++)
            {
                for (int i = 0;i < m;i++)
                {
                    if (i%2)
                    {
                        cout<<j+1<<" ";
                    }
                    else 
                    {
                        // cout 2,3,...k,1
                        if (j==k-1)
                        {
                            cout<<1<<" ";
                        }
                        else 
                        {
                            cout<<j+2<<" ";
                        }
                    }
                }
                cout<<endl;
            }
        }
        return;
    }


    // handle case 3

    // if (k%n!=0 || k%m!=0)
    {
        ll k1 = gcd(n,k);
        ll k2 = k / k1;

        // cout<<k1<<" "<<k2<<endl;

        for (int var = 0;var < n/k1;var++)
        {
            for (int var2 = 0;var2 < k1;var2++)
            {
                for (int i = 0;i < m/k2;i++)
                {
                    for (int j = 0;j < k2;j++)
                    {
                        cout<<var2*k2+j+1<<" ";
                    }
                }
                cout<<endl;
            }
            
        }
        
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
    cin>>t;
 
    while(t--)
    {
        solve();
    }
}
