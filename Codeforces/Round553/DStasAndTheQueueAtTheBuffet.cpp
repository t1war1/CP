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
ll n;
vector<pll> arr;

bool comp(pii p1, pii p2)
{
    return (p1.ff-p1.ss)>(p2.ff-p2.ss);

}

class DStasAndTheQueueAtTheBuffet {
public:
	void solve(istream& cin, ostream& cout) {
        cin>>n;
        arr.clear();
        arr.pb({0,0});
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            arr.pb({x,y});
        }
        sort(arr.begin()+1,arr.end(),comp);
        ll curr=0,ans=1e18;
        for(int i=1;i<=n;i++)
        {
            curr+=(arr[i].ff*(i-1))+(arr[i].ss*(n-i));
        }
        cout<<min(ans,curr);
	}
};
