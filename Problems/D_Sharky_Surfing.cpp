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
    ll n;cin>>n;
    ll m;cin>>m;

    ll l;cin>>l;

    vl right(n);vl left(n);;

    vl x(m);vl v(m);

    f(i,n) cin>>left[i]>>right[i];

    f(i,m) cin>>x[i]>>v[i];

    ll my_powerup_sum = 1;
    priority_queue<ll> pq;

    // vpl array;

    vector<pair<pair<ll,ll>,ll>> array;

    f(i,n)
    {
        array.push_back({{left[i],right[i]},0});
    }
    // 1 is for powerup 0 is for shark
    f(i,m)
    {
        array.push_back({{x[i],v[i]},1});
    }

    sortall(array);
    ll sum = 0;

    f(i,size(array))
    {
        // cout<<array[i].first<<" "<<array[i].second;L;
        if (array[i].second == 1)
        {
            pq.push(array[i].first.second);
        }
        else 
        {
            // we encountered a shark
            ll len = array[i].first.second - array[i].first.first + 2;
            while (my_powerup_sum<len)
            {
                if (pq.empty())
                {
                    cout<<-1;L;
                    return;
                }
                my_powerup_sum += pq.top();
                sum++;
                pq.pop();
            }
        }
    }

    cout<<sum;L;


        
     


    
 
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