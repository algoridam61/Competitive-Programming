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

string xorBinarySubstrings(const string& s, int l1, int r1, int l2, int r2) {
    string subStr1 = s.substr(l1 - 1, r1 - l1 + 1);
    string subStr2 = s.substr(l2 - 1, r2 - l2 + 1);
    
    size_t maxLen = max(subStr1.length(), subStr2.length());
    string paddedStr1 = string(maxLen - subStr1.length(), '0') + subStr1;
    string paddedStr2 = string(maxLen - subStr2.length(), '0') + subStr2;
 
    string xorResult;
    for (size_t i = 0; i < maxLen; ++i) {
        xorResult += (paddedStr1[i] == paddedStr2[i]) ? '0' : '1';
    }
 
    return xorResult;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int firstZero = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            firstZero = i;
            break;
        }
    }

    if (firstZero == -1) {
        // All 1s case
        cout << 1 << " " << n << " " << 1 << " " << 1 << "\n";
        return;
    }

    int maxL2 = 0, maxR2 = 0;
    string maxXOR = "";
    int length = n - firstZero;

    for (int j = 0;j < firstZero;j++)
    {
        string xorResult = xorBinarySubstrings(s, 1, n, j+1, j +n-firstZero);
        if (xorResult > maxXOR)
        {
            maxXOR = xorResult;
            maxL2 = j;
            maxR2 = j+length-1;
        }
    }

    cout << 1 << " " << n << " " << maxL2 + 1 << " " << maxR2 + 1 << "\n";
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