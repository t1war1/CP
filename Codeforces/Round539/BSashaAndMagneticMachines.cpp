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

int n;

class BSashaAndMagneticMachines {
public:
	void solve(istream& cin, ostream& cout) {
	    cin>>n;
        int arr[n],sum=0;
        repi(i,0,n)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        sort(arr,arr+n);
        int ans=sum;
        for(int i=n-1;i>0;i--)
        {
            int j;
            for (j = 2; j <= sqrt(arr[i]); ++j) {
                if(arr[i]%j==0)
                {
                    int r=sum-arr[0]-arr[i]+arr[0]*j+arr[i]/j;
                    ans=min(ans,r);
                }
            }
           
        }
        cout<<ans;


	}
};
