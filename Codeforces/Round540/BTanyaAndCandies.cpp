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

int n,arr[1000000];
ll sumOdd[1000000],sumEven[1000000];
class BTanyaAndCandies {
public:
	void solve(istream& cin, ostream& cout) {

		cin>>n;
		for(int i=0;i<1000000;i++)
        {
            sumOdd[i]=0;
            sumEven[i]=0;
        }
        repi(i,1,n+1)
        {
            cin>>arr[i];
            if(i%2)
            {
                sumOdd[i]=sumOdd[i-1]+arr[i];
                sumEven[i]=sumEven[i-1];
            }
            else{
                sumEven[i]=sumEven[i-1]+arr[i];
                sumOdd[i]=sumOdd[i-1];
            }
        }

        ll ans=0;
		for(int i=1;i<=n;i++)
        {
		    ll sec=0,so=0;
		    if(i%2)
            {
		        so=sumOdd[i-1]+sumEven[n]-sumEven[i];
		        sec=sumEven[i-1]+sumOdd[n]-sumOdd[i];
            }
		    else{
		        so=sumOdd[i-1]+sumEven[n]-sumEven[i];
		        sec=sumEven[i-1]+sumOdd[n]-sumOdd[i];
		    }
            if(sec==so)
            {
                ans++;
            }
        }
        cout<<ans;

	}
};
