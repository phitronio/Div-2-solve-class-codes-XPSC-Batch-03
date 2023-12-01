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
    vector<vector<int> >a(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        int andd = (1<<30) - 1;
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            andd &= a[i][j];
        }
        ans[i] = andd;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(a[i][j]!= (ans[i] | ans[j]))
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    for(int i:ans)
        cout<<i<<" ";
    cout<<"\n";
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
