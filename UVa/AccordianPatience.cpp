#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define mp make_pair
#define ll long long
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

class AccordianPatience {
public:
	void solve(istream& cin, ostream& cout) {
        string str;
        while(cin>>str)
        {
            if(str=="#")
            {
                return;
            }
            vector<stack<string>> cards;
            stack<string> st;
            st.push(str);
            cards.pb(st);
            for(int i=1;i<52;i++)
            {
                stack<string> s;
                cin>>str;
                s.push(str);
                cards.pb(s);
            }
            for(int i=1;i<cards.size();i++)
            {
                if(i>=3 && (cards[i].top()[0]==cards[i-3].top()[0]||(cards[i].top()[1]==cards[i-3].top()[1])))
                {
                    cards[i-3].push(cards[i].top());
                    cards[i].pop();
                    if(cards[i].size()==0)
                    {
                        cards.erase(cards.begin()+i);
                    }
                    i-=4;
                }else if(i>=1 && (cards[i].top()[0]==cards[i-1].top()[0] || cards[i].top()[1]==cards[i-1].top()[1]))
                {
                    cards[i-1].push(cards[i].top());
                    cards[i].pop();
                    if(cards[i].size()==0)
                    {
                        cards.erase(cards.begin()+i);
                    }
                    i-=2;
                }
            }
            cout<<cards.size()<<" pile"<<((cards.size()==1)?"":"s")<<" remaining:";
            for(auto i:cards)
                cout<<" "<<i.size();
            cout<<endl;
        }


	}
};
