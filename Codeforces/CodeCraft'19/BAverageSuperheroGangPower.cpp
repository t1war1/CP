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

class BAverageSuperheroGangPower {
public:
	void solve(istream& cin, ostream& cout) {
		int n,k,m;
		cin>>n>>k>>m;
		int arr[n];
		repi(i,0,n)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		double suma[n];
		suma[n-1]=arr[n-1]*1.0;

		for(int i=n-2;i>=0;i--)
		{
			suma[i]=suma[i+1]+arr[i];
		}

		double ans=0;
		for(int i=n;i>=1;i--)
		{
			int j=n-1;
			int tmp=i;
			double sum=0;
			while(tmp>0)
			{
				sum=sum+arr[j]*1.0;
				j--;tmp--;
			}
			sum=sum+min(m-n+i,i*k)*1.0;
			if((sum*1.0/i)>ans)
				ans=(sum*1.0/i);
		}
		cout<<fixed<<setprecision(20)<<ans;
	}
};
