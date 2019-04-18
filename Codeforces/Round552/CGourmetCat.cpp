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
class CGourmetCat {
    int arr[7]={0,1,2,0,2,1,0};
public:
	void solve(istream& cin, ostream& cout) {
		int a,b,c;
		cin>>a>>b>>c;
		ll ans=0;
		int x=min({a/3,b/2,c/2});
		ans+=x*7;
		a-=x*3;b-=x*2;c-=x*2;
		int w=0;
		for(int i=0;i<7;i++){
		    int ta=a,tb=b,tc=c;
		    x=0;
		    for(int j=i;;j++)
            {
		        if(arr[j%7]==0)
                {
		            if(ta>0)
                    {
		                ta--;x++;
                    }
                    else
                        break;
                }
		        else if(arr[j%7]==1)
                {
		            if(tb>0)
                    {
		                tb--;x++;
                    } else{
		                break;
		            }
                } else{
		            if(tc>0)
                    {
		                tc--;x++;
                    } else{
                        break;
		            }
		        }
            }
		    w=max(w,x);
		}
		cout<<ans+w;
	}
};
