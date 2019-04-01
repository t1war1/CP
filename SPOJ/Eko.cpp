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
class Eko {
    int n,m;
    vector<int> arr;
    bool isValid(int mid)
    {
        int wood=0;
        repi(i,0,n)
        {
            wood+=(arr[i]-mid)*(((arr[i]-mid)<0)?0:1);
        }
        if(wood>=m)
            return 1;
        return 0;
    }
public:
	void solve(istream& cin, ostream& cout) {
		cin>>n>>m;
		arr.clear();
		int beg=0,last=0;
		repi(i,0,n)
        {
		    int x;cin>>x;arr.pb(x);
		    last=max(last,x);
        }
        int ans=0;
        while(beg<=last)
        {
            int mid=(beg+last)/2;
            if(isValid(mid))
            {
                ans=mid;
                beg=mid+1;
            }else{
                last=mid-1;
            }
        }
        cout<<ans;
	}
};
