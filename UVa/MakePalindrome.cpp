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
int cache[1000][1000];
int dp(int i,int j)
{
	if(cache[i][j]!=-1)
		return cache[i][j];
	if(i==j || i>j)
	{
		cache[i][j]=0;
		return 0;
	}

	if(str[i]==str[j])
	{
		cache[i][j]= dp(i+1,j-1);
		return cache[i][j];
	}

	cache[i][j]= min(dp(i+1,j),dp(i,j-1))+1;
	return cache[i][j];
}

void printPath(int i, int j)
{
	if(i>j)
		return;
	if(i==j)
	{
		cout<<str[i];return;
	}
	
	if(str[i]==str[j])
	{
		cout<<str[i];
		printPath(i+1,j-1);
		cout<<str[j];
		return;
	}
	
	int m=min(cache[i+1][j],cache[i][j-1]);
	if(m==cache[i+1][j])
	{
		cout<<str[i];
		printPath(i+1,j);
		cout<<str[i];
	}
	else if(m==cache[i][j-1])
	{
		cout<<str[j];
		printPath(i,j-1);
		cout<<str[j];
	}
	
}

class MakePalindrome {
public:
	void solve(istream& cin, ostream& cout) {
		while(cin>>str)
        {
			memset(cache,-1,sizeof(cache));
		    int ans=dp(0,str.length()-1);
		    cout<<ans<<" ";
		    printPath(0,str.length()-1);
		    cout<<"\n";
        }
	}
};
