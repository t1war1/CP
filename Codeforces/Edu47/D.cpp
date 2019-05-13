/**
 *    author: Gaurav Tiwari, Delhi Technological University
 **/
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
#define endl "\n"

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
int oo = 0x3f3f3f3f;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif

	fastIO;

	int n,m;
	cin>>n>>m;
	if(m<n-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	vector<pii> ans;
	int curr=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(!curr)
				break;
			if(__gcd(i,j)==1)
			{
				ans.pb({j,i});
				curr--;
			}
		}
	}
	if(curr>0)
	{
		cout<<"Impossible"<<endl;return 0;
	}
	cout<<"Possible\n";
	for(int i=0;i<m;i++)
	{
		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	}

	return 0;
}
