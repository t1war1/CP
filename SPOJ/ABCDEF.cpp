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

vector<int> arr,s1,s2;
int x;
class ABCDEF {
public:
	void solve(istream& cin, ostream& cout) {
		arr.clear();
		s1.clear();s2.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			arr.pb(x);
		}
		for(int i=0;i<arr.size();i++)
		{
			for(int j=0;j<arr.size();j++)
			{
				for(int k=0;k<arr.size();k++)
				{
					s1.pb(arr[i]*arr[j]+arr[k]);
				}
			}
		}

		for(int i=0;i<arr.size();i++)
		{
			if(arr[i]==0)
			{
				continue;
			}
			for(int j=0;j<arr.size();j++)
			{
				for(int k=0;k<arr.size();k++)
				{
					s2.pb(arr[i]*(arr[j]+arr[k]));
				}
			}
		}
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		ll ans=0;
		for(int i=0;i<s1.size();i++)
		{
			int lo=lower_bound(s2.begin(),s2.end(),s1[i])-s2.begin();
			int hi=upper_bound(s2.begin(),s2.end(),s1[i])-s2.begin();
			ans+=hi-lo;
		}
		cout<<ans;
	}
};
