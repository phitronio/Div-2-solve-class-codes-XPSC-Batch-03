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
const __int128 INF = 2e18;

int n,q;
vector<pair<int, vector<int> >>all;
vector<ll>sz;

ll add(ll x, ll y)
{
    __int128 ans = x;
    ans += y;
    if(ans > INF)
        ans = INF;
    return (ll) ans;
}
ll gun(ll x, ll y)
{
    __int128 ans = x;
    ans *= y;
    if(ans > INF)
        ans = INF;
    return (ll) ans;
}

void TEST_CASES()
{
    cin>>n>>q;
    all.clear();
    sz.clear();
    sz.push_back(0);
    all.push_back({ 0, {0} });
    for(int i=0;i<n;i++)
    {
        int t,x;
        cin>>t>>x;
        if(t==1)
        {
            if(all.size() && all.back().first==1)
            {
                all.back().second.push_back(x);
            }
            else{
                all.push_back({t,{x}});
            }
        }
        else{
            all.push_back({t,{x}});
        }
    }
    for(int i=1;i<all.size();i++)
    {
        if(all[i].first==1)
        {
            sz.push_back(add((ll)sz.back(), (ll)all[i].second.size()));
        }
        else{
            sz.push_back(gun((ll)sz.back(), (ll)all[i].second[0] + 1ll));
        }
    }
    for(int i=0;i<q;i++)
    {
        ll idx;
        cin>>idx;
        idx--;
        int id = -1;
        for(int j=0;j<sz.size();j++)
        {
            if(idx < sz[j])
            {
                id = j;
                break;
            }
        }
        ll lagbe = idx;
        int ans = -1;
        for(int j=id;j>=1;j--)
        {
            ll prv = sz[j-1];
            if(all[j].first == 2)
            {
                lagbe %= prv;
                continue;
            }
            ll cur = sz[j];
            if(lagbe >= prv)
            {
                ans = all[j].second[lagbe-prv];
                break;
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
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
