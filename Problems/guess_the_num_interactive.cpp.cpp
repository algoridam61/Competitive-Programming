#include <bits/stdc++.h>
using namespace std;

int main()
{
    int start = 1;
    int end = 1000000;
    int mid;

    while (start != end)
    {
        mid = (start + end + 1) / 2;
        cout << mid << endl; 
        cout.flush();        

        string response;
        cin >> response; 

        if (response == "<")
        {
            end = mid - 1; 
        }
        else if (response == ">=")
        {
            start = mid; 
        }
    }

    cout << "! " << start << endl;
    cout.flush();
}


