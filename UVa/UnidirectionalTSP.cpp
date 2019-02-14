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

int n,m,arr[15][110],cache[15][110];
string dir[15][110];

int dp(int i,int j);

class UnidirectionalTSP {
public:
	void solve(istream& cin, ostream& cout) {
        while(cin>>n>>m)
        {
            memset(cache,-1,sizeof(cache));
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    cin>>arr[i][j];

            for(int i=0;i<15;i++)
            {
                for(int j=0;j<110;j++)
                    dir[i][j]="";
            }

            int ans=INT_MAX,s=-1;

            for(int i=0;i<n;i++) {
                int x = dp(i, 0);
                if(x<ans) {
                    ans = x;
                    s=i;
                }
            }

            cout<<dir[s][0];

            cout<<"\n"<<ans<<"\n";
        }
	}
};
int dp(int i,int j)
{
    if(cache[i][j]!=-1)
        return cache[i][j];

    if(j>=m) {
        cache[i][j]=0;
        return 0;
    }
    int ans=INT_MAX;

    int val1=dp(i,j+1);
    if(ans>(val1+arr[i][j]))
    {
        ans=val1+arr[i][j];
        dir[i][j]=to_string(i+1)+" "+dir[i][j+1];
    }
    else if(ans==(val1+arr[i][j]))
    {
        ans=val1+arr[i][j];
        if((to_string(i+1)+" "+dir[i][j+1])<dir[i][j])
        {
            dir[i][j]=to_string(i+1)+" "+dir[i][j+1];
        }
    }

    int val2=dp((i-1+n)%n,j+1);
    if(ans>(val2+arr[i][j]))
    {
        ans=val2+arr[i][j];
        dir[i][j]=to_string(i+1)+" "+dir[(i-1+n)%n][j+1];
    }
    else if(ans==(val2+arr[i][j]))
    {
        ans=val2+arr[i][j];
        if((to_string(i+1)+" "+dir[(i-1+n)%n][j+1])<dir[i][j])
        {
            dir[i][j]=to_string(i+1)+" "+dir[(i-1+n)%n][j+1];
        }
    }

    int val3=dp((i+1)%n,j+1);

    if(ans>(val3+arr[i][j]))
    {
        ans=val3+arr[i][j];
        dir[i][j]=to_string(i+1)+" "+dir[(i+1)%n][j+1];
    }
    else if(ans==(val3+arr[i][j]))
    {
        ans=val3+arr[i][j];
        if((to_string(i+1)+" "+dir[(i+1)%n][j+1])<dir[i][j])
        {
            dir[i][j]=to_string(i+1)+" "+dir[(i+1)%n][j+1];
        }
    }
    return ans;

}

