#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;cin>>n;

    vector<int> a(n);
    for (int i = 0;i < n;i++) cin>>a[i];

    int ans = 0;

    int dp2odd[n];
    int dp1odd[n];
    int dp2eve[n];
    int dp1eve[n];

    if (a[0] % 2 == 0) dp1eve[0] = 1;
    else dp1odd[0] = 1;

    for (int i = 0;i < n;i++) {
        if (a[i]%2 == 0) {
            dp2eve[i] += dp1eve[i-1];
            dp1eve[i] += dp1odd[i-1] + dp2odd[i-1];
        } else {
            dp2odd[i] += dp1odd[i-1];
            dp1odd[i] += dp2eve[i-1] + dp1eve[i-1];
        }
    }




}

