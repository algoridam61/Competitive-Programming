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
void solve() {
    int n;
    cin >> n;
    map<ll,ll> mp;
    // ll count = 0;
    vpl a11(n);
    f(i, n) {
        cin >> a11[i].first;
        mp[a11[i].first]++;
        a11[i].second = i;
    }

    vpl a;
    vpl b;
    // map<int,int> visited;
    f(i,n)
    {
        if (mp[a11[i].first]>=2)
        {
            // if (!visited[a1[i].first]) {visited[a1[i].first]=1;count++;}
            // count++;
            a.push_back({a11[i].first,i});
            b.push_back({-a11[i].first,i});
        }
    } 
    map<ll,ll> mp2 = mp;
    ll count = 0;
    f(i,n)
    {
        if (mp2[a11[i].first]>=2)
        {
            count+=2;mp2[a11[i].first]-=2;
        }
    }
    // cout<<count;L;return;
    rsortall(a);
    rsortall(b);
    
    // Top candidates from a and b
    vector<pair<ll, ll>> top_a, top_b;
    for (int i = 0; i < a.size() && top_a.size() < 4; i++) {
        top_a.push_back(a[i]);
    }
    for (int i = 0; i < b.size() && top_b.size() < 4; i++) {
        top_b.push_back(b[i]);
    }
    
    // Maximize the expression
    ll max_value = LLONG_MIN;
    // cout<<count;L;
    // cout<<a.size();L;
    ll i1, j1, i2, j2;
    if (count<8)
    {
        no
    }

    cout<<"YES";L;
    for (auto [a1, idx1] : top_a) {
        for (auto [b1, idx2] : top_b) {
            for (auto [a2, idx3] : top_a) {
                for (auto [b2, idx4] : top_b) {
                    // cout<<"---------------------------------------";L;
                    // cout<<idx1<<" "<<a1<<" "<<mp[a1];L;
                    // cout<<idx2<<" "<<b1<<" "<<mp[b1];L;
                    // cout<<idx3<<" "<<a2<<" "<<mp[a2];L;
                    // cout<<idx4<<" "<<b2<<" "<<mp[b2];L;
                    if (idx1 == idx2 || idx1 == idx3 || idx1 == idx4 || idx2 == idx3 || idx2 == idx4 || idx3 == idx4) continue;
                    
                    ll current_value = (a1 + b1) * (a2 + b2);
                    if (mp[a1]>=2) mp[a1]-=2; else continue;
                    if (mp[a2]>=2) mp[a2]-=2;else {mp[a1]+=2;continue;}
                    if (mp[-b1]>=2) mp[-b1]-=2;else {mp[a1]+=2;mp[a2]+=2;continue;}
                    if (mp[-b2]>=2) mp[-b2]-=2;else {mp[a1]+=2;mp[a2]+=2;mp[-b1]+=2;continue;}
                    mp[a1]+=2;mp[a2]+=2;mp[-b1]+=2;mp[-b2]+=2;
                    if (current_value > max_value) {
                        max_value = current_value;
                        i1 = idx1;
                        j1 = idx2;
                        i2 = idx3;
                        j2 = idx4;
                    }
                }
            }
        }
    }
    // cout<<max_value<<" ";L;


    // Output the result
    // cout << "Max value: " << max_value << endl;
    cout<<a11[i1].first<<" "<<a11[i2].first<<" "<<a11[j1].first<<" "<<a11[j2].first<<" "<<a11[j1].first<<" "<<a11[i2].first<<" "<<a11[i1].first<<" "<<a11[j2].first;L;
    // cout << "Indices: i1=" << i1 << ", j1=" << j1 << ", i2=" << i2 << ", j2=" << j2 << endl;
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