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
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>l(n);
    for(int i=1;i<n;i++)
    {
        if(i==n-1 || a[i]-a[i-1] < a[i+1] - a[i])
        {
            l[i] = l[i-1] + 1;
        }
        else{
            l[i] = l[i-1] + a[i] - a[i-1];
        }
    }
    vector<int>r(n);
    for(int i=n-2;i>=0;i--)
    {
        if(i==0 || a[i+1] - a[i] < a[i]-a[i-1])
        {
            r[i] = r[i+1] + 1;
        }
        else{
            r[i] = r[i+1] + a[i+1] - a[i];
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x < y)
        {
            cout<<r[x] - r[y]<<"\n";
        }
        else{
            cout<<l[x] - l[y]<<"\n";
        }
    }
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
