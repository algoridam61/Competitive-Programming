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
void fill_primes(vl &primes, ll n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i*i <= n; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i*i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
vl primes;
void solve()
{
    ll n;cin>>n;
    // ll k;cin>>k;
    // ll n = 400000;
    vl a(n);
    read(a);


    // so all elements need to be distinct
    // and the gcd of all should be 1
    // we need the first n primes
    rsortall(a);
    vl prefa(n);
    prefa[0] = a[0];
    f1(i,1,n)
    {
        prefa[i] = prefa[i-1] + a[i];
    }

    
    // cout<<primes.size();L;
    

    vl prefprime(n);
    prefprime[0] = 2;
    f1(i,1,n)
    {
        prefprime[i] = prefprime[i-1] + primes[i];
    }

    // cout<<primes[400000];L;


    // cout<<prefprime[n-1];L;
    // cout<<prefa[n-1];L;

    ll sum = 0;
    f(i,n)
    {
        sum += primes[i];
    }

    ll our_sum = 0;
    f(i,n)
    {
        our_sum += a[i];
    }

    if (sum <= our_sum)
    {
        cout<<0;L;return;
    }
    else 
    {
        ll i = n-1;
        while (i >= 0)
        {
            if (prefa[i] >= prefprime[i])
            {
                cout<<n-i-1;L;return;
            }
            i--;
        }
        cout<<n-1;L;return;
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
    fill_primes(primes, 6000000);
    while(t--)
    {
        solve();
    }
}
