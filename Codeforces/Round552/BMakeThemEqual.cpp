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
class BMakeThemEqual {
    int n;
    int arr[101];

public:
	void solve(istream& cin, ostream& cout) {
        cin>>n;
        repi(i,0,n)
        {
            cin>>arr[i];
        }
        int ans=oo;
        for(int i=1;i<=100;i++)
        {
            int d=-1;
            bool flag=0;
            for(int j=0;j<n;j++)
            {
                int ed=abs(arr[j]-i);
                if(arr[j]!=i)
                {
                    if(d==-1)
                        d=ed;
                    else
                    {
                        if(d!=ed)
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(!flag)
            {
                if(d!=-1)
                ans=min(ans,d);
                else
                    ans=0;
            }
        }
        if(ans==oo)
            cout<<-1;
        else
            cout<<ans;
	}
};
