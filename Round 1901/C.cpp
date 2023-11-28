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
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>ans;
    while(a[0] != a.back())
    {
        int x = 0;
        if(a[0]%2==0 && a.back()%2==0)
        {
            ans.push_back(0);
            x = 0;
        }
        else if(a[0]%2==0 && a.back()%2==1)
        {
            ans.push_back(0);
            x = 0;
        }
        else if(a[0]%2==1 && a.back()%2==0)
        {
            ans.push_back(1);
            x = 1;
        }
        else if(a[0]%2==1 && a.back()%2==1)
        {
            ans.push_back(0);
            x = 0;
        }
        a[0] = (a[0] + x) / 2;
        a.back() = (a.back() + x) / 2;
    }
    cout<<ans.size()<<"\n";
    if(ans.size()<=n)
    {
        for(int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
