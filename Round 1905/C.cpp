#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
typedef pair<int,int> pii;


void TEST_CASES()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<int>subseq;
    for(int i=0;i<n;i++)
    {
        while(subseq.size() && s[subseq.back()] < s[i])
        {
            subseq.pop_back();
        }
        subseq.push_back(i);
    }
    string t = s;
    sort(t.begin(),t.end());
    for(int i=0;i<n;i++)
    {
        if(!binary_search(subseq.begin(),subseq.end(),i) && t[i] != s[i])
        {
            cout<<"-1\n";
            return;
        }
    }
    int ans = 0;

    deque<char>canShift;
    for(int i:subseq)
    {
        canShift.push_back(t[i]);
    }

    while(!subseq.empty())
    {
        if(s[subseq[0]] == canShift[0])
        {
            subseq.pop_front();
            canShift.pop_front();
            continue;
        }
        if(s[subseq.back()] == canShift[0])
        {
            subseq.pop_back();
            canShift.pop_front();
            ans++;
            continue;
        }
        ans = -1;
        break;
    }

    cout<<ans<<"\n";
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
