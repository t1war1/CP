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

ll sumeven(ll x)
{
	return ((x*((x+1)%mod))%mod);
}

ll sumodd(ll x)
{
	return (x*x)%mod;	
}

ll powerr(ll x, ll y)
{
	ll temp; 
    if( y == 0) 
        return 1; 
    temp = powerr(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
}

ll f(ll num)
{
	if(num<1)return 0;
	ll x=0,left=num,odd=0,even=0,turn=0;
	while(left>0)
	{
		ll p=powerr(2,x);
		if(!turn)
		{
			odd=(odd+min(p,left))%mod;
		}
		else{	
			even=(even+min(p,left))%mod;
		}
		left-=min(p,left);
		x++;
		turn^=1;
	}
	return (sumeven(even)+sumodd(odd))%mod;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	fastIO;
	ll l,r;
	cin>>l>>r;
	ll ans=f(r)-f(l-1)+mod;
	cout<<ans%mod;
	return 0;
}
