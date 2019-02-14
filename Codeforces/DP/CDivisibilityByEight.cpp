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

string str,output="";
int cache[105][2][8];

int dp(int i,int taken, int rem)
{
	if(i==str.length())
	{
		if(rem==0) {
			cache[i][taken][rem%8]=1;
			return 1;
		}
		cache[i][taken][rem%8]=0;
		return 0;
	}

	if(cache[i][taken][rem]!=-1)
		return cache[i][taken][rem];

	int ans=0;

	ans|=dp(i+1,1,(rem*10 + str[i]-'0')%8);
	ans|=dp(i+1,0,rem);

	cache[i][taken][rem%8]=ans;
	return ans;

}

void getOutput(int i,int taken, int rem)
{
	if(i==str.length()) return;

	if(cache[i+1][1][(rem*10 + str[i]-'0')%8]==1)
	{
		getOutput(i+1,1,rem*10 + str[i]-'0');
		output=str[i]+output;
	}
	else if(cache[i+1][0][rem%8])
	{
		getOutput(i+1,0,rem);
	}

}

class CDivisibilityByEight {
public:
	void solve(istream& cin, ostream& cout) {
		cin>>str;
		memset(cache,-1, sizeof(cache));

		if(!dp(0,0,8))
		{
			cout<<"NO";
			return;
		}
		cout<<"YES\n";
		getOutput(0,0,8);
		cout<<output;
		output="";
	}
};
