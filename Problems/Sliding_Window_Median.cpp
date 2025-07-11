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
    ll k;cin>>k;
    
    vl a(n);read(a);

    // maintaining 2 multisets
    multiset<ll> left, right;
    vl first_k_elements;
    f(i,k)
    {
        first_k_elements.push_back(a[i]);
    }
    sortall(first_k_elements);
    f(i,ceil(double(k)/double(2)))
    {
        left.insert(first_k_elements[i]);
    }
    f1(i,ceil(double(k)/double(2)),k)
    {
        right.insert(first_k_elements[i]);
    }

    cout<<*left.rbegin()<<" ";
    f1(i,k,n)
    {
        // we need to add a new element and remove an old one
        ll ele_add = a[i];
        ll ele_remove = a[i-k];

        // remove the ele_remove from left multiset.
        // add the ele_add to the right multiset
        // add the smallest element from right multiset to left multiset
        // output the largest element from left multiset

        if (left.find(ele_remove) != left.end())
        {
            left.erase(left.find(ele_remove));
            right.insert(ele_add);
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }
        else 
        {
            right.erase(right.find(ele_remove));
            left.insert(ele_add);
            auto it = left.rbegin();
            right.insert(*it);
            left.erase(--left.end());
        }
        cout<<*left.rbegin()<<" ";
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
