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

int rec(ll beg, ll last, ll n, ll k)
{
    ll mid=(beg+last)/2;
    if(k>mid)
    {
        return rec(mid+1,last,n-1,k);
    } else if(k<mid){
        return rec(beg,mid-1,n-1,k);
    } else{
        return n;
    }
}

class BChloeAndTheSequence {
public:
	void solve(istream& cin, ostream& cout) {
		int n,k;
		cin>>n>>k;
		ll beg=1,last=(1<<(n))-1;
		cout<<rec(beg,last,n,k);
	}
};
