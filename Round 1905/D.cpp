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
    vector<int>a(2*n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i+n] = a[i];
    }
    vector<pii>pMex;
    ll cost = 0;
    ll maxCost = 0;

    //initial build
    vector<bool>vis(n+1);
    int mex = 0;
    for(int i=0;i<n;i++)
    {
        vis[a[i]] = true;
        while(vis[mex])
        {
            mex++;
        }
        if(pMex.empty() || pMex.back().first != mex)
        {
            pMex.push_back({mex, 1});
        }
        else{
            pMex.back().second++;
        }
        cost += mex;
    }

    maxCost = max(cost, maxCost);

    // rotate
    for(int i=1;i<n;i++)
    {
        // remove i-1
        // add i+n-1
        int tot = 0;
        while(pMex.size() && pMex.back().first > a[i-1])
        {
            auto it = pMex.back();
            cost -= it.first * 1ll * it.second;
            cost += a[i-1] * 1ll * it.second;
            tot += it.second;
            pMex.pop_back();
        }

        if(pMex.size() && pMex.back().first == a[i-1])
        {
            pMex.back().second += tot;
        }
        else{
            pMex.push_back({a[i-1], tot});
        }

        if(pMex.size() && pMex.back().first == n)
        {
            pMex.back().second += 1;
        }
        else{
            pMex.push_back({n, 1});
        }
        cost += n;
        maxCost = max(maxCost, cost);
    }

    cout<<maxCost<<"\n";
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
