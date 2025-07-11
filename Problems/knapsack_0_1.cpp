#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(int i = 0;i < n;i++)
#define vi vector<int>
// solving the knapsack problem involving having a maximum bag weight of W, each item has a weight wi 
// each item has a value of vi

void solve()
{
    int n;cin>>n;

    ll W; cin>>W;
    vi w(n);
    vi v(n);
    f(i,n)
    {
        cin>>w[i];
    }
    f(i,n)
    {
        cin>>v[i];
    }

    // dp[i,w] = max(dp[i-1,w], dp[i-1,w-w[i]]+v[i])
    // trying to do the array dp
    vector<int> dp(W);
    // f(i,n)
    // {
    //     for(int j = W;j < )
    //     dp[w] = max()
    // }


}

int main()
{
    int t;cin>>t;
    while (t--)
    {
        solve();
    }
}