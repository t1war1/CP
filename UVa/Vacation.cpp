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

string str1,str2;
int dp[105][105];

int lcs(int l1,int l2)
{
	if(l1==0 || l2==0)
		return 0;
	if(dp[l1][l2]!=-1)
		return dp[l1][l2];
	if(str1[l1-1]==str2[l2-1]) {
		dp[l1][l2]=lcs(l1 - 1, l2 - 1) + 1;
		return dp[l1][l2];
	}
	dp[l1][l2]=max(lcs(l1-1,l2),lcs(l1,l2-1));
	return dp[l1][l2];

}

class Vacation {
public:
	void solve(istream& cin, ostream& cout) {
		int t=1;
		while(1)
        {
			memset(dp,-1, sizeof(dp));
		    cin>>str1;
		    if(str1=="#")
		        break;
		    cin>>str2;
		    int k=lcs(str1.length(),str2.length());
		    cout<<"Case #"<<t<<": you can visit at most "<<k<<" cities.\n";
			t++;
        }

	}
};
