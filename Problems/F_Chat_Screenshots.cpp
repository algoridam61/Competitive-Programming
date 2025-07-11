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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
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
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2>
using ordered_set_pair = tree<std::pair<T1, T2>, null_type, std::less<std::pair<T1, T2>>, rb_tree_tag, tree_order_statistics_node_update>;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll calculate_nCr_mod_p(int n_val, int r_val) {
    if (r_val < 0 || r_val > n_val) {
        return 0;
    }
    if (r_val == 0 || r_val == n_val) {
        return 1;
    }
    if (r_val > n_val / 2) {
        r_val = n_val - r_val;
    }
    ll res = 1;
    for (int i = 0; i < r_val; ++i) {
        res = (res * (n_val - i)) % MOD;
        res = (res * modInverse(i + 1)) % MOD;
    }
    return res;
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
    int k;cin>>k;
    
    vvi a(k,vi(n));

    f(i,k)
    {
        f(j,n)
        {
            cin>>a[i][j];
        }
    }

    if (k == 1) yes 

    // if (k == 2)
    // {
        int first = a[0][0];
        int second = a[1][0];
        vi o1, o2;
        f(i,n)
        {
            if (a[0][i] != first && a[0][i] != second)
            {
                o1.push_back(a[0][i]);
            }
            if (a[1][i] != first && a[1][i] != second)
            {
                o2.push_back(a[1][i]);
            }
        }
        if (o1 != o2) no
        else if (k == 2) yes 
    // }

    int ind_of_first_in_second;
    int ind_of_second_in_first;
    f(i, n)
    {
        if (a[0][i] == a[1][0])
            ind_of_second_in_first = i;
        if (a[1][i] == a[0][0])
            ind_of_first_in_second = i;
    }

    if (ind_of_first_in_second != ind_of_second_in_first)
    {
        // order fixed by these 2 
        vi order;
        if (ind_of_first_in_second > ind_of_second_in_first) 
        {
            int prev = a[1][ind_of_first_in_second - 1]; 
            f1(i, 1, n)
            {
                order.push_back(a[0][i]);
                if (a[0][i] == prev) order.push_back(a[0][0]);
            }
        }
        else 
        {
            int prev = a[0][ind_of_second_in_first - 1]; 
            f1(i, 1, n)
            {
                order.push_back(a[1][i]);
                if (a[1][i] == prev) order.push_back(a[1][0]);
            }
        }
        // out(order);
        // L;return;
        f1(i, 2, k)
        {
            vi temp;
            temp.push_back(a[i][0]);
            f(j, n)
            {
                if (order[j] != a[i][0])
                    temp.push_back(order[j]);
            }
            if (temp == a[i]) continue;
            else no
        }
        yes 
    }
    else 
    {
        // order not fixed. 
        vl order(n);
        int ind = 0;
        int ind1 = 0;
        int ind2 = 0;
        f1(i, 1, n)
        {
            if (a[0][i] != a[1][0])
            {
                order[ind] = a[0][i];
                ind++;
            }
            else
            {
                ind1 = ind;
                ind2 = ind + 1;
                ind+=2;
            }
        }
        bool first_greater = false;
        vi temp = a[2];
        f1(i,1, n-1)
        {
            if (temp[i] == a[0][0] && temp[i+1] == a[1][0]) {first_greater = false; break;}
            if (temp[i] == a[1][0] && temp[i+1] == a[0][0]) {first_greater = true; break;}
        }
        if (first_greater)
        {
            order[ind1] = a[1][0];
            order[ind2] = a[0][0];
        }
        else 
        {
            order[ind1] = a[0][0];
            order[ind2] = a[1][0];
        }
        // out(order);
        // // debug 
        // cout<< ind1<<" "<<ind2<<" "<<first_greater<<endl;
        f1(i, 2, k)
        {
            vi temp;
            temp.push_back(a[i][0]);
            f(j, n)
            {
                if (order[j] != a[i][0])
                    temp.push_back(order[j]);
            }
            if (temp == a[i]) continue;
            else no
        }
        yes
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
