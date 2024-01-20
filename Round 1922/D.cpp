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
    vector<int>d(n);
    for(int i=0; i<n; i++)
    {
        cin>>d[i];
    }
    set<int> cur;
    set<int> baki;
    for(int i=0; i<n; i++)
    {
        cur.insert(i);
        baki.insert(i);
    }
    for(int i=0; i<n; i++)
    {
        set<int> new_cur;
        set<int> to_rem;
        for(int j:cur)
        {
            auto prv_it = baki.lower_bound(j);
            int prv_idx = -1;
            if(prv_it != baki.begin())
            {
                prv_it--;
                prv_idx = *prv_it;
            }

            auto nxt_it = baki.lower_bound(j);
            nxt_it++;
            int nxt_idx = -1;
            if(nxt_it != baki.end())
            {
                nxt_idx = *nxt_it;
            }

            int prv_val = (prv_idx==-1? 0: a[prv_idx]);
            int nxt_val = (nxt_idx==-1? 0: a[nxt_idx]);
            if(prv_val + nxt_val > d[j])
            {
                to_rem.insert(j);
                if(prv_idx!=-1)
                    new_cur.insert(prv_idx);
                if(nxt_idx!=-1)
                    new_cur.insert(nxt_idx);
            }
        }

        for(int j:to_rem){
            baki.erase(j);
            new_cur.erase(j);
        }

        cur = new_cur;

        cout<<to_rem.size()<<" ";
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
