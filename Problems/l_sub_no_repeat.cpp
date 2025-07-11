#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<x<<endl;
int main()
{
    string s;cin>>s;
    // int ans;
    int n = s.size();
    vector<int> lo(26,-1);
    // stores the last occurence of the alphabet

    int start = 0;
    int lenf = 0;
    int len1 = 0;
    int mover = 0;
    while (mover< n)
    {
        if (lo[s[mover]-'a']<start)
        {
            lo[s[mover]-'a'] = mover;
            len1 ++;
            mover ++;
            lenf = max(lenf,len1);
        } 
        else 
        {
            start = lo[s[mover]-'a'] + 1;
            len1 = mover - start;
            lenf = max(lenf,len1);
        }
        // debug(start);debug(mover);debug(lenf);
    }
    cout<<lenf<<endl;
}