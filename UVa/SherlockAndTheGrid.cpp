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

int t,n;
char arr[1005][1005];
bool r[1005][1005],d[1005][1005];

class SherlockAndTheGrid {
public:
	void solve(istream& cin, ostream& cout) {
		cin>>t;
		while(t--)
		{
			cin>>n;
			repi(i,0,n)
			{
				repi(j,0,n)
				{
					cin>>arr[i][j];
				}
			}
			memset(r,0, sizeof(r));
			memset(d,0, sizeof(d));
			for(int i=0;i<n;i++)
			{
				for(int j=n-1;j>=0;j--)
				{
					if(r[i][j+1] || arr[i][j]=='#')
					{
						r[i][j]=1;
					}
				}
			}
			for(int i=n-1;i>=0;i--)
			{
				for(int j=0;j<n;j++)
				{
					if(d[i+1][j] || arr[i][j]=='#' )
					{
						d[i][j]=1;
					}
				}
			}
			int ans=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(arr[i][j]=='.' && !r[i][j] && !d[i][j])
					{
						ans++;
					}
				}
			}
			cout<<ans<<"\n";

		}
	}
};
