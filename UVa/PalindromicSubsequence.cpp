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

string str;
string cache[1000][1000];

string dp(int i, int j)
{
	if(i>j)
		return "";
	if(i==j)
		return string(1,str[i]);
	if(cache[i][j]!="")
		return cache[i][j];

	string tmp1=dp(i+1,j);
	cache[i][j]=tmp1;

	string tmp2=dp(i,j-1);
	if(cache[i][j].length()<tmp2.length())
	{
		cache[i][j]=tmp2;
	}
	else if(cache[i][j].length()==tmp2.length())
	{
		if(cache[i][j]>tmp2)
		{
			cache[i][j]=tmp2;
		}
	}

	if(str[i]==str[j])
	{
		string tmp3=dp(i+1,j-1);
		if(cache[i][j].length()<(tmp3.length()+2))
		{
			cache[i][j]=str[i]+tmp3+str[j];
		}
		else if(cache[i][j].length()==(tmp3.length()+2))
		{
			string tmp=str[i]+tmp3+str[j];
			if(tmp<cache[i][j])
			{
				cache[i][j]=tmp;
			}
		}
	}
	return cache[i][j];

}

class PalindromicSubsequence {
public:
	void solve(istream& cin, ostream& cout) {
		while(cin>>str)
		{
			for(int i=0;i<1000;i++)
			{
				for(int j=0;j<1000;j++)
				{
					cache[i][j]="";
				}
			}
			cout<<dp(0, str.length()-1)<<"\n";
		}
	}
};
