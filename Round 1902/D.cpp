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

struct PT
{
    int x, y;
    PT()
    {
        x = 0, y = 0;
    }
    PT(int x, int y) : x(x), y(y) {}
    PT operator + (const PT &a) const
    {
        return PT(x + a.x, y + a.y);
    }
    PT operator - (const PT &a) const
    {
        return PT(x - a.x, y - a.y);
    }
    bool operator < (PT a) const
    {
        return a.x == x ? y < a.y : x < a.x;
    }
};
map<char, PT>dirs;

void TEST_CASES()
{
    dirs['U'] = PT(0,1);
    dirs['D'] = PT(0,-1);
    dirs['L'] = PT(-1,0);
    dirs['R'] = PT(1,0);

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    map<PT,vector<int> >mp;
    vector<PT>pos;
    PT cur(0,0);

    mp[cur].push_back(0);
    pos.push_back(cur);

    for(int i=0; i<s.size(); i++)
    {
        cur = cur + dirs[s[i]];
        mp[cur].push_back(i+1);
        pos.push_back(cur);
    }
    while(q--)
    {
        PT need;
        int l,r;
        cin>>need.x>>need.y>>l>>r;

        bool found = false;
        if(mp.count(need))
        {
            int first = mp[need][0];
            int last = mp[need].back();
            if(first <= l-1 || last > r)
                found = true;
        }
        PT need2 = pos[r] + pos[l-1] - need;
        if(mp.count(need2))
        {
            vector<int>&idx = mp[need2];
            int id = lower_bound(idx.begin(),idx.end(),l-1) - idx.begin();
            if(id < idx.size() && idx[id] >= l-1 && idx[id] <= r-1)
            {
                found = true;
            }
        }

        cout<<(found?"YES\n":"NO\n");
    }
}


int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
//    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
