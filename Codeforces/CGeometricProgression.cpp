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

ll n,k,arr[1000000];
ll cache[1000000][2];

class CGeometricProgression {
public:
	void solve(istream& cin, ostream& cout) {
		memset(cache,0, sizeof(cache));

        cin>>n>>k;
        repi(i,0,n)
		{
        	cin>>arr[i];
		}
		map<ll,ll> m1,m2;

        repi(i,0,n)
		{
        	double x=arr[i]/(k*1.0);
        	if(floor(x)==x)
			{
        		if(m1.find((int)x)!=m1.end())
				{
        			cache[i][0]=m1[(int)x];
				} else{
					cache[i][0]=0;
        		}
        		if(m2.find((int)x)!=m2.end())
				{
					cache[i][1]=m2[(int)x];
				}else{
					cache[i][1]=0;
        		}
				m2[arr[i]]+=m1[(int)x];
			}

        	m1[arr[i]]++;

		}

		ll ans=0;
        repi(i,0,n)
		{
        	ans+=cache[i][1];
		}
		cout<<ans;



	}
};
