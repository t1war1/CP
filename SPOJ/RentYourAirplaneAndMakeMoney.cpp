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

int n;
ll cache[10005];
vector<pair<ll,pair<ll,ll>>> arr;

bool compareInterval(pair<ll,pair<ll,ll>> p1, pair<ll,pair<ll,ll>> p2)
{
    if(p1.fi<p2.fi)
        return 1;
    if(p1.fi>p2.fi)
        return 0;
    return p1.se.fi<p2.se.fi;
}

int binary_search(int start, ll key)
{
    int end=n-1;
    int ans=-1;
    if(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid].fi>=key)
        {
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

class RentYourAirplaneAndMakeMoney {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
        {
		    memset(cache,0, sizeof(cache));
		    cin>>n;
		    repi(i,0,n)
            {
		        ll s,d,p;
		        cin>>s>>d>>p;
		        arr.pb({s,{d,p}});
            }
            sort(arr.begin(),arr.end(),compareInterval);
		    cache[n-1]=arr[n-1].se.se;
		    for(int i=n-2;i>=0;i--)
            {
				cache[i]=max(cache[i+1],arr[i].se.se);
		        if(arr[n-1].fi>arr[i].fi+arr[i].se.fi)
                {
                    ll finishTime=arr[i].fi+arr[i].se.fi;
                    int findInd=binary_search(i+1,finishTime);
                    if(findInd!=-1)
                    {
                        cache[i]=max(cache[i], cache[findInd]+arr[i].se.se );
                    }
                }
            }
		    cout<<cache[0]<<"\n";
        }
	}
};

int main() {
	fastIO;
	RentYourAirplaneAndMakeMoney solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
