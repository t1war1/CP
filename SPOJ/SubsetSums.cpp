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
int n,a,b;
vector<int> arr,lef,righ;
class SubsetSums {
public:
	void solve(istream& cin, ostream& cout) {
        cin>>n>>a>>b;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;arr.pb(x);
        }
        int sum=0;
        for(int mask=0;mask<(1<<(n/2));mask++)
        {
            sum=0;
            for(int item=0;item<(n/2);item++)
            {
                if(mask&(1<<item))
                {
                    sum+=arr[item];
                }
            }
            lef.pb(sum);
        }

        for(int mask=0;mask<(1<<(n-n/2));mask++)
        {
            sum=0;
            for(int item=0;item<(n-n/2);item++)
            {
                if(mask&(1<<item))
                {
                    sum+=arr[item+n/2];
                }
            }
            righ.pb(sum);
        }

        sort(righ.begin(),righ.end());
        ll ans=0;
        for(int i=0;i<lef.size();i++)
        {
            int lo=lower_bound(righ.begin(),righ.end(),a-lef[i])-righ.begin();
            int hi=upper_bound(righ.begin(),righ.end(),b-lef[i])-righ.begin();
            ans+=hi-lo;
        }
        cout<<ans;
	}
};
