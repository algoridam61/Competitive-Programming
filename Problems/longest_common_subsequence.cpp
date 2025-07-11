#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1000,vector<int>(1000,-1));

int longest_subsequence(string s1, int start1, string s2, int start2)
{
    if (dp[start1][start2]!=-1) return dp[start1][start2];
    if (start1 == s1.length()||start2 == s2.length()) return 0;
    if (s1[start1]==s2[start2]) {int ans = 1 + longest_subsequence(s1, start1 + 1, s2, start2 + 1); dp[start1][start2] = ans;return ans;}
    else {int ans = max(longest_subsequence(s1, start1 + 1, s2, start2), longest_subsequence(s1, start1, s2, start2 + 1));dp[start1][start2] = ans;return ans;}
}

int main()
{
    string s1,s2;
    
    cin>>s1>>s2;
    
    cout<<longest_subsequence(s1,0,s2,0)<<"\n";
}
