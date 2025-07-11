#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,a,b) for(int i=a;i<b;i++)
#define vl vector<ll>
#define out(a) f(i,size(a)) {if (i!=size(a)-1) {cout<<a[i]<<" ";} else {cout<<a[i]<<"\n";}}
   

// sort function for vector of pairs, with increasing order of first element
// in case of equality, sort in decreasing order of second element

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    if (a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main()
{
    ll n;cin>>n;

    vl left(n);
    vl right(n);

    f(i,n) cin>>left[i]>>right[i];

    vector<pair<ll,ll>> a(n);

    f(i,n)
    {
        a[i].first = left[i];
        a[i].second = right[i];
    }

    sort(a.begin(),a.end(),sortbysec);

    f(i,n)
    {
        cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
cout<<"\n";
    vl max1(n);

    max1[0] = a[0].second;
    f1(i,1,n)
    {
        max1[i] = max(max1[i-1],a[i].second);
    }

    f1(i,1,n)
    {
        if (a[i].second<=max1[i-1])
        {
            cout<<a[i].first<<" "<<a[i].second<<"\n";
        }
    }


}