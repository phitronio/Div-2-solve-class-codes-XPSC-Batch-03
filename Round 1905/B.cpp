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
    vector<int>degree(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        degree[u]++;
        degree[v]++;
    }
    int leaf = 0;
    for(int i=0;i<n;i++)
    {
        if(degree[i]==1)
            leaf++;
    }
    cout<<(leaf+1)/2<<"\n";
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
