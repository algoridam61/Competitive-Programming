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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
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

template<typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
// struct linked_list
// {
//     ll data;
//     linked_list *next;
// };
// int josephus(int n, int k) {
//     int res = 0;
//     for (int i = 1; i <= n; ++i)
//       {res = (res + k) % i;
//       cout<<res + 1<<" ";} // +1 to convert from 0-based index to 1-based index
//     return res + 1;
// }
void solve()
{
    ll n;cin>>n;
    ll k1;cin>>k1;

    // josephus(n, k1);
    // cout<<endl;
    // return;

    // linked_list *head = new linked_list;
    // linked_list *tail = head;
    // f1(i, 1, n+1)
    // {
    //     linked_list *new_node = new linked_list;
    //     new_node->data = i;
    //     new_node->next = nullptr;
    //     tail->next = new_node; // Link the new node to the list
    //     tail = new_node; // Move the tail pointer to the new node
    // }

    // tail->next = head->next; // Make it circular by linking the last node to the first node
    // linked_list *current = head->next; // Start from the first node
    // linked_list *prev = tail; // Keep track of the previous node
    // while (current != current->next)
    // {
    //     ll k = k1;
    //     k = (k + n) % n;

        

    // }

    indexed_set<ll> s;
    f1(i, 1, n + 1)
    {
        s.insert(i);
    }
    ll idx = 0;
    while (s.size() > 1)
    {
        ll k = k1;
        k = (k + s.size()) % s.size(); // if k >= size of set, we can just take k % size
        idx = (idx + k) % s.size(); // update idx for the next round
        auto it = s.find_by_order(idx); // get the element at index idx
        cout << *it << " "; // print the element
        s.erase(it); // remove the element from the set
    }
    if (!s.empty())
    {
        cout << *s.begin() << " "; // print the last remaining element
    }
    cout << endl;


    // deque<ll> q;

    // f1(i,1,n+1)
    // {
    //     q.push_back(i);
    // }

    // while (q.size()>1)
    // {
    //     ll k = k1;
    //     k = (k+q.size()) % q.size(); // if k >= size of queue, we can just take k % size
        
    //     f(i,k)
    //     {
    //         ll x = q.front();
    //         q.pop_front();
    //         q.push_back(x);
    //     }
    //     cout<<q.front()<<" ";
    //     q.pop_front();
    // }
    // while (!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop_front();
    // }
    // cout<<endl;
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
