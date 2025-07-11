#include <bits/stdc++.h>
using namespace std;

long long N = 1000000;
vector<long long> segment_tree(4*N);

// function to build the segment tree
void build_tree(long long ind, long long low, long long high, vector<long long> &a)
{
    if (low == high)
    {
        segment_tree[ind] = a[high];
        return;
    } 
    else 
    {
        long long mid = (low+high) / 2;
        build_tree(2*ind+1, low, mid, a);
        build_tree(2*ind+2, mid+1, high, a);
        segment_tree[ind] = max(segment_tree[2*ind+1], segment_tree[2*ind+2]);
        return;
    }
}

// function to query the segment tree
long long query(long long ql, long long qh, long long low, long long high, long long ind, vector<long long> &a)
{
    if (ql <= low && qh >= high)
    {
        return segment_tree[ind];
    }
    else if (ql > high || qh < low)
    {
        return LONG_LONG_MIN;
    }
    else
    {
        // overlap so check both
        long long mid = (low + high) / 2;
        long long left_val = query(ql, qh, low, mid, 2*ind + 1, a);
        long long right_val = query(ql, qh, mid+1, high, 2*ind + 2, a);
        return max(left_val, right_val);
    }
}

void update(long long num, long long ind, long long ql, long long qh, long long low, long long high, vector<long long>&a)
{
    // we need to update the range from ql to qh.
    // do this using lazy propagation
    
    if (ql > high || qh < low) return;
    else if (ql <= low && qh >= high)
    {
        segment_tree[ind] += (high - low + 1) * num;
    }
    else 
    {
        
    }


}


int main()
{
    vector<long long> a(N);
    for (long long i = 0; i < N; i++)
    {
        a[i] = i;
    }
    build_tree(0, 0, N-1, a); 
    for (int qh = 0; qh < N; qh++)
    {
        query(0, qh, 0, N-1, 0, a);
    }
    
    return 0;
}