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

int cache[10001][10001],arr[10001];

class CreatingPalindrome {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		for(int lo=1;lo<=t;lo++)
		{
			int n,k;
			cin>>n>>k;
			for(int i=1;i<=n;i++)
				cin>>arr[i];

			memset(cache,0, sizeof(cache));
			for(int k=1;k<=n;k++)
			{
				for(int i=1,j=k;j<=n;i++,j++)
				{
					if(arr[i]==arr[j])
					{
						cache[i][j]=cache[i+1][j-1];
					}
					else{
						cache[i][j]=min(cache[i][j-1],cache[i+1][j])+1;
					}
				}
			}
			if(cache[1][n]==0)
			{
				cout<<"Case "<<lo<<": Too easy"<<endl;
			}else if(cache[1][n]>k)
			{
				cout<<"Case "<<lo<<": Too difficult"<<endl;
			}
			else{
				cout<<"Case "<<lo<<": "<<cache[1][n]<<endl;
			}

		}
	}
};
