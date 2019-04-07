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
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
int oo = 0x3f3f3f3f;
class CHamburgers {

    ll nb, ns, nc, pb, ps, pc, r, reqdb=0, reqds=0, reqdc=0;
    string s;

    ll check(ll k)
    {
        ll b=max(0LL, k*reqdb-nb);
        ll s=max(0LL, k*reqds-ns);
        ll c=max(0LL, k*reqdc-nc);
        ll reqd=b*pb + s*ps + c*pc;
        return reqd<=r;
    }

    ll binsearch(ll lo, ll hi)
    {
        while(lo<hi)
        {
            ll mid=(lo+hi+1)>>1;
            if(check(mid))
                lo=mid;
            else
                hi=mid-1;
        }
        return lo;
    }
public:
	void solve(istream& cin, ostream& cout) {

        cin>>s;
        cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;
        for(auto it:s)
        {
            if(it=='B')
                reqdb++;
            if(it=='S')
                reqds++;
            if(it=='C')
                reqdc++;
        }
        ll ans=binsearch(0, 1e15);
        cout<<ans;
        
	}
};
