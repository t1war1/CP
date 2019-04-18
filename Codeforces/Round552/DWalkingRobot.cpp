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
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
int oo = 0x3f3f3f3f;
class DWalkingRobot {
    int n,b,a,amax;
    int arr[200005];
public:
	void solve(istream& cin, ostream& cout) {
        cin>>n>>b>>amax;
        a=amax;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int i=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                if(a>0)
                    a--;
                else if(b>0)
                    b--;
                else
                    break;
            } else{
                if(a==amax)
                {
                    a--;
                }
                else if(b>0)
                {
                    b--;a=min(amax,a+1);
                } else if(a>0){
                    a--;
                } else{
                    break;
                }
            }
        }
        cout<<i;
	}
};
