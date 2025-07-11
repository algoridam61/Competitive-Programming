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
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
*/
void segment_tree(vl &a, vl &seg, int n)
{
    f(i,n) seg[n+i] = a[i];
    for (int i = n - 1; i > 0; --i) seg[i] = max(seg[i<<1],seg[i<<1|1]);
}

ll query(vl &seg, int l, int r, int n)
{
    ll res = LLONG_MIN;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res,seg[l++]);
        if (r&1) res = max(res,seg[--r]);
    }
    return res;
}


void solve()
{
    int n;cin>>n;
    
    vl a(n);vl b(n);
    read(a);read(b);
    int m;cin>>m;
    vl x(m);read(x);
    // cout<<"YES";L;
    bool check = true;
    f(i,n)
    {
        if (b[i]>a[i]) {check = false;break;}
    }
    if (!check) no

    vl seg(2*n);

    segment_tree(b,seg,n);
    
    map<ll,int> razors; // has the given number of razors
    f(i,m) razors[x[i]]++;
    // we will maintain a map of minimum required razors
    map<ll,vi> razreq;
    f(i,n) 
    {
        razreq[b[i]].push_back(i);
    }
    // output the razreq
    // cout<<razreq[3][0];L;

    // between 2 occurences of a particular razor, if the maximum is less than that razor, then we wont add 1 to that razor
    // for first razor we add 1
    // for finding the maximum between 2 indices of an array, we can use segment tree
    // we will maintain a segment tree of maximums
    map<ll,int> occured;
    map<ll,int> razors2;

    f(i,n)
    {
        if (b[i]<a[i]&&razors[b[i]]==0) no
    }

    f(i,n) occured[b[i]] = 0;

    int i = 0;
    while (i<n&&!occured[b[i]])
    {
        ll curr_razor = b[i];
        vi indices = razreq[curr_razor];
        occured[curr_razor] = 1;
        int prev_val = -1;
        // cout<<"-----------------";L;
        // out(indices);
        // cout<<"-----------------";L;
        f(j,indices.size())
        {
            if (j==0)
            {
                if (b[indices[j]]<a[indices[j]]) {razors2[curr_razor]++;prev_val=indices[j];}
            }
            else
            {
                if (query(seg,prev_val,indices[j],n)>curr_razor)
                {
                    if(b[indices[j]]<a[indices[j]]) {razors2[curr_razor]++;prev_val=indices[j];}
                }
            }
        }
        i++;
    }
    
    f(i,m)
    {
        // cout<<razors2[x[i]]<<" ";
        // cout<<razors[x[i]]<<endl;
        if (razors2[x[i]]>razors[x[i]]) no
    }
    

    
    yes
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