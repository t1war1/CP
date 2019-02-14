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

ll n,sevPay,monthlySalary,hiringCost,cache[26][35];
int arr[26];

ll dp(int ind, int prev)
{
	if(cache[ind][prev]!=-1)
	{
		return cache[ind][prev];
	}

	if(ind==n)
	{
		return cache[ind][prev]=0;
	}

	ll ans=0;
	if(arr[ind]>=prev)
	{
		ans+=(arr[ind]-prev)*(hiringCost)+ arr[ind]*monthlySalary +dp(ind+1,arr[ind]);
	}
	else if(arr[ind]<prev)
	{
		ans=oo;
		for(int i=prev;i>=arr[ind];i--)
		{
			ans=min(ans,i*monthlySalary+(prev-i)*sevPay+dp(ind+1,i));
		}
	}

	cache[ind][prev]=ans;
	return ans;

}

class MakingABudget {
public:
	void solve(istream& cin, ostream& cout) {
		int t=0;
		while(1)
		{
			t++;
			cin>>n;
			if(!n)
				break;
			memset(cache,-1,sizeof(cache));
			cin>>hiringCost>>monthlySalary>>sevPay;
			repi(i,0,n)
			{
				cin>>arr[i];
			}
			cout<<"Case "<<t<<", cost = $"<<dp(0,0)<<"\n";
		}
	}
};