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

int n,m,cache[105][10005];
vector<int> arr;

int dp(int ind, int pages)
{

	if(pages<=0)
		return 0;

	if(ind<0)
		return oo;

	if(cache[ind][pages]!=-1)
		return cache[ind][pages];
	int ans=oo,sum=0,count=1;
	for(int i=0,j=ind;j>=0;j--)
	{
		sum+=arr[j];
		ans=min(ans,dp(j-1,pages-(sum-i))+1);
		i+=count;
		count++;
	}
	cache[ind][pages]=ans;
	return ans;
}

class D1CoffeeAndCourseworkEasyVersion {
public:
	void solve(istream& cin, ostream& cout) {
		cin>>n>>m;
		arr.clear();
		memset(cache,-1, sizeof(cache));
		repi(i,0,n)
		{
			int x;
			cin>>x;
			arr.pb(x);
		}
		sort(arr.begin(),arr.end());
		int ans=dp(n-1,m);
		if(ans>=oo)
		{
			cout<<-1;
		} else
			cout<<ans;
	}

};
