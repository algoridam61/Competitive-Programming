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
    // ll k;cin>>k;
    
    // vl a(n);read(a);
    string s;cin>>s;

    vvl indices(26);
    f(i,n)
    {
        indices[s[i]-'a'].push_back(i);
    }
    
    vpl freqs(26);
    f(i,26)
    {
        freqs[i].first = indices[i].size();
        freqs[i].second = i;
    }
    rsortall(freqs);

    // f(i,26)
    // {
    //     if (size(indices[i]) == 0)
    //     {
    //         continue;
    //     }
    //     cout<<i<<" ";
    //     f(j,size(indices[i]))
    //     {
    //         cout<<indices[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // return;

    // bool flag = false;
    // f(i,n-1)
    // {
    //     if (m[s[i]] != m[s[i+1]])
    //     {
    //         flag = true;
    //         break;
    //     }
    // }

    // if (!flag)
    // {
    //     cout<<0;L;
    //     cout<<s;L;
    //     return;
    // }

    // // the equal frequencies must be divisors of n.
    // // so the number of distinct characters must be n / d;
    // // each character must be repeated d times and n/d distinct characters

    // vl divisors;
    // for (ll i = 1; i <= sqrt(n); i++)
    // {
    //     if (n % i == 0)
    //     {
    //         divisors.push_back(i);
    //         if (i != n / i)
    //             divisors.push_back(n / i);
    //     }
    // }
    // sortall(divisors);
    // ll mini = LLONG_MAX;
    // for (ll d : divisors)
    // {
    //     ll each_freq = d;
    //     ll distinct = n / d;
    //     ll curr1 = 0;
    //     ll curr2 = 0;
    //     f(i,n)
    //     {
    //         if (m[s[i]] == each_freq) continue;
    //         else 
    //         {
    //             if (m[s[i]] > each_freq)
    //             {
    //                 curr1 += m[s[i]] - each_freq;
    //             }
    //             else
    //             {
    //                 curr2 += each_freq - m[s[i]];
    //             }
    //         }
    //     }
    //     if (curr1 > 0 && curr2 > 0)
    //         mini = min(mini, min(curr1,curr2));
    //     else if (curr1 > 0)
    //         mini = min(mini, curr1);
    //     else
    //         mini = min(mini, curr2);
    // }

    // // some will have frequencies equal to required freq.
    // // we do not touch them
    // // but 

    // cout<<mini;L;return;
    ll changes = LLONG_MAX;
    // string curr_string = s;
    string final_string = s;
    f1(k,1,27)
    {
        // k is the number of distinct characters
        if (n % k != 0)
        {
            continue;
        }
        ll each_freq = n / k;
        string curr_string = s;
        f(i,n)
        {
            curr_string[i] = 'A';
        }
        // cout<<each_freq<<" ";L;
        // find the top k characters in s.
        vl empty_indices;
        vpl to_be_filled;
        f(i,k)
        {
            // cout<<freqs[i].first<<" ";L;
            // cout<<each_freq<<" ";L;
            if (freqs[i].first == each_freq)
            {
                for (auto index : indices[freqs[i].second])
                {
                    curr_string[index] = 'a' + freqs[i].second;
                }
            }
            else if (freqs[i].first > each_freq)
            {
                ll j = 0;
                for (auto index : indices[freqs[i].second])
                {
                    j++;
                    if (j > each_freq)
                    {
                        break;
                    }
                    else
                    {
                        curr_string[index] = 'a' + freqs[i].second;
                    }
                }
            }
            else 
            {
                for (auto index : indices[freqs[i].second])
                {
                    curr_string[index] = 'a' + freqs[i].second;
                }

                to_be_filled.push_back({each_freq - freqs[i].first, freqs[i].second});

            }
        }
        // cout<<curr_string;L;
        f(i,n)
        {
            if (curr_string[i] == 'A')
            {
                empty_indices.push_back(i);
            }
        }

        // cout<<empty_indices.size();L;
        // cout<<to_be_filled[0].first;L;
        // return;


        // fill the to_be_filled in the empty indices
        int ind = 0;
        int char_ind = 0;
        while (ind < empty_indices.size())
        {
            char curr = 'a' + to_be_filled[char_ind].second;
            // cout<<curr;L;return;
            ll freq = to_be_filled[char_ind].first;
            ll j = 0;
            while (j < freq)
            {
                curr_string[empty_indices[ind]] = curr;
                j++;
                ind++;
            }
            // cout<<curr_string;L;return;
            char_ind++;
            if (char_ind == to_be_filled.size())
            {
                break;
            }
        }
        if (changes > empty_indices.size())
        {
            changes = empty_indices.size();
            final_string = curr_string; 
        }
    }

    cout<<changes;L;
    cout<<final_string;L;
    return;







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
