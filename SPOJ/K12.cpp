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
int oo = 0x3f3f3f3f;
class K12 {
    int n;
    vector<int> heights, costs;

    ll find(double height)
    {
        ll sum=0;
        repi(i,0,n)
        {
            sum+=abs(height-heights[i])*costs[i];
        }
        return sum;
    }

public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
        {
            cin>>n;
            heights.clear();costs.clear();

            repi(i,0,n)
            {
                int x;cin>>x;heights.pb(x);
            }

            repi(i,0,n)
            {
                int x;cin>>x;costs.pb(x);
            }

            double l=0.0,r=10010.0;
            while(r-l>1e-9)
            {
                double midl=(2*l+r)/3.0,midr=(2*r+l)/3.0;
                if(find(midl)>find(midr))
                {
                    l=midl;
                }else{
                    r=midr;
                }
            }
            cout<< min(find(floor(l)),find(ceil(l)))<<"\n";
        }
	}
};