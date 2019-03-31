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

int n,f;
vector<long double> arr;

bool isValid(long double mid)
{
    if(mid==0)
        return 0;
    int a=0;
    repi(i,0,n)
    {
        a+=(int)(arr[i]/mid);
    }
    if(a>=f)
        return 1;
    return 0;
}

class Pie {
public:
	void solve(istream& cin, ostream& cout) {
		//Clear global variables
		int t;
		cin>>t;
		while(t--)
        {
		    cin>>n>>f;f++;
		    arr.clear();
            repi(i,0,n)
            {
                long double x;cin>>x;
                arr.pb(x);
            }
            sort(arr.begin(),arr.end());
            repi(i,0,n)
            {
                arr[i]=arr[i]*arr[i]*PI;
            }
            long double beg=0,last=arr[n-1];
            while(last-beg>=1e-6)
            {
                long double mid=(beg+last)/2;
                if(isValid(mid))
                {
                    beg=mid;
                }
                else{
                    last=mid;
                }
            }
            printf("%.4Lf\n",beg);
        }
	}
};
