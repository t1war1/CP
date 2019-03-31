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

int n,m,arr[105],prefixSum[106],cache[105][20005];

int findSum(int i, int j)
{
	if (i > j) return 0;
	return prefixSum[j]-(i?prefixSum[i-1]:0);
}

int dp(int n, int sum)
{
	if (n==0)
		return cache[n][sum]=(sum==0?0:oo);
	if(n==1)
		return cache[n][sum]=((sum==arr[0])?0:oo);

	if(cache[n][sum]!=-1)
	{
		return cache[n][sum];
	}
	int ans=oo;
	for(int i=0;i<n-1;i++)
	{
		int afterMinus=arr[i+1];
		int tmp=findSum(i+2,n-1);
		afterMinus-=tmp;
		int beforeMinus=dp(i+1,sum+afterMinus);
		if(beforeMinus!=oo)
		{
			ans=i;
			break;
		}
	}
	cache[n][m]=ans;
	return ans;
}

vector<int> printAns(int n, int sum)
{
	int k=dp(n,sum);
	assert(k!=oo);

	if(n==1)
	{
		return {};
	}
	int afterMinus=arr[k+1]-findSum(k+2,n-1);
	vector<int> beforeMinus=printAns(k+1,sum+afterMinus);
	for(int i=k+1;i<(n-1);i++)
	{
		beforeMinus.pb(1);
	}
	beforeMinus.pb(0);
	return beforeMinus;
}


class MinusOperation {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
		{
			memset(cache,-1, sizeof(cache));
			cin>>n>>m;
			repi(i,0,n)
			{
				cin>>arr[i];
			}
			repi(i,0,n)
			{
				prefixSum[i]=arr[i]+(i?prefixSum[i-1]:0);
			}
			dp(n,m);
			vector<int> ans=printAns(n,m);
			for(int i:ans)
			{
				cout<<(i+1)<<"\n";
			}
			cout<<"\n";
		}
	}
};
int main() {
	fastIO;
	MinusOperation solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
