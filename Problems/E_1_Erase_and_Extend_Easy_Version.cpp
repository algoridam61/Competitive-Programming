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
int lexicographic_hash(string& s)
{
    int n = size(s);
    int p = 31;
    int m = 1e9+9;
    int hash_value = 0;
    int p_pow = 1;
    for (int i = 0; i < n; i++)
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
void solve()
{
    int n;cin>>n;int k;cin>>k;
    string s;cin>>s;
    // cout<<'yo';L;
    // string ans = "";
    int add = s.size();
    string temp5 = s;
    while (temp5.size()<k)
    {
        temp5 = temp5.append(s);
    }
    // cout<<temp;L;
    // let's try to make the smallest one of n length n;
    // now we iterate over the prefix of the index 0 to i and 0 to n-i-2
    // i ranges from 0 to n-1 and try to find the smallest lexicographic string
    s = temp5;
    s = s.substr(0,k);
    // cout<<s;L;
    string min1 = s;
    f(i,n)
    {
        string temp = s.substr(0,i+1);
        // cout<<temp;L;
        string temp1 = s.substr(0,k-i-1);
        // cout<<temp1;L;
        string temp2 = temp.append(temp1);
        // cout<<temp2;L;
        if (temp2<min1) {min1 = temp2;}
    }
    
    // cout<<min1;L;
    string min2 = min1;
    f(i,n)
    {
        string temp = min1.substr(0,i+1);
        string temp1 = min1.substr(0,k-i-1);
        string temp2 = temp.append(temp1);
        if (temp2<min2) {min2 = temp2;}
    }
    // cout<<min2;L;
    while (min2!=min1)
    {
        // cout<<min1<<" "<<min2;L;
        min1 = min2;
        min2 = min2;
        f(i,n)
        {
            string temp = min2.substr(0,i+1);
            string temp2 = min2.substr(0,k-i-1);
            string temp1 = temp.append(temp2);
            if (temp1<min2) {min2 = temp1;}
        }
    }

    // cout<<min2;L;
    cout<<min2;L;

    // cout<<temp.substr(0,k);L;


    
 
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