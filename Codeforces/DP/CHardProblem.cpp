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
ll inf = 0x3f3f3f3f3f3f3f3fll;


using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

ll cache[100005][2],cost[100005];
string arr[100005];
string revi[100005];
ll dp(int i,int rev)
{
    if(i==0 && rev==0)
        return 0;
    if(i==0 && rev==1)
        return cost[i];

    if(cache[i][rev]!=-1)
        return cache[i][rev];

    if(arr[i]>=arr[i-1])
        cache[i][rev]=dp(i-1,rev)+(rev==1?cost[i]:0);
    if(arr[i]>=rev[i-1])
        cache[i][rev]=min(cache[i][rev],dp(i-1,1-rev))+(rev==1?cost[i]:0);
    return cache[i][rev];
}

class CHardProblem {
public:
	void solve(istream& cin, ostream& cout) {
	    memset(cache,-1, sizeof(cache));
		int n;
		cin>>n;
        for(int i=0;i<n;i++)
            cin>>cost[i];

        for(int i=0;i<n;i++) {
            cin >> arr[i];
            rev[i]=arr[i];
            reverse(rev[i].begin(),rev[i].end());
        }

        cout<<min(dp(n-1,0),dp(n-1,1));
	}
};
