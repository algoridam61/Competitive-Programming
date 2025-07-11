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
void solve()
{
    int n;cin>>n;
    vl a(n);read(a);

    vpl suff_smallest(n);

    suff_smallest[n-1] = {a[n-1],n-1};

    for (int i = n-2; i >= 0; i--)
    {
        if (a[i]<=suff_smallest[i+1].first)
        {
            suff_smallest[i] = {a[i],i};
        }
        else suff_smallest[i] = suff_smallest[i+1];
    }

    // print suff smallest

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<suff_smallest[i].first<<" "<<suff_smallest[i].second;L;
    // }
    // L;return;
    ll currsmallest = suff_smallest[0].first;
    int currsmallest_ind = suff_smallest[0].second;
    vi unchanged_indices;
    unchanged_indices.push_back(suff_smallest[0].second);
    // find the smallest index element greater than curr smallest element.
    while (currsmallest!=a[n-1])
    {
        // cout<<currsmallest<<" ";L;
        int left = 0;
        int right = n-1;

        int mid;
        int ind = -1;
        while (left<=right)
        {
            mid = left + (right - left)/2;
            if (a[mid]>=currsmallest&&mid > currsmallest_ind)
            {
                ind = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        if (ind!=-1&&ind!=n-1)
        {
            // cout<<ind;L;
            unchanged_indices.push_back(suff_smallest[ind].second);
            currsmallest = suff_smallest[ind].first;
            currsmallest_ind = suff_smallest[ind].second;
        }
        else 
        {
            break;
        }
    }
    // return;

    // f(i,size(unchanged_indices))
    // {
    //     cout<<a[unchanged_indices[i]]<<" ";
    // }
    int n1 = size(unchanged_indices);
    ll sm = INT_MAX;
    f(i,unchanged_indices[n1-1])
    {
        if (a[i]>a[unchanged_indices[n1-1]])
        {
            sm = min(sm,a[i]);
        }
    }
    
    sm+=1;
    int n2 = unchanged_indices[n1-1];
    f1(i,n2+1,n)
    {
        if (a[i]<=sm)
        {
            unchanged_indices.push_back(i);
        }
    }
    // L;
    f(i,size(unchanged_indices))
    {
        cout<<a[unchanged_indices[i]]<<" ";
    }

    vi not_unchanged;
    f(i,n)
    {
        // find i in unchanged_indices
        // using binary search
        // write using scratch
        // dont use check present functin
        int l=0;
        int h=size(unchanged_indices)-1;
        int mid;
        int ind = -1;

        while (l<=h)
        {
            mid = l + (h-l)/2;
            if (unchanged_indices[mid]==i)
            {
                ind = mid;
                break;
            }
            else if (unchanged_indices[mid]>i)
            {
                h = mid-1;
            }
            else l = mid+1;
        }

        if (ind==-1)
        {
            not_unchanged.push_back(a[i]+1);
        }
    }

    sortall(not_unchanged);

    out(not_unchanged);
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