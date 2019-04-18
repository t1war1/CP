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
class Marcus {
    int m,n;
    char arr[10][10];
    int sx=-1,sy=-1,dx=-1,dy=-1;
    string str="IEHOVA#";
    vector<string > ans;

    void dfs(int sx,int sy, vector<string > &ans,int i)
    {
        if(arr[sx][sy]=='#')
        {
            return;
        }
        if(arr[sx-1][sy]==str[i])
        {
            ans.pb("forth");
            dfs(sx-1,sy,ans,i+1);
        } 
        else if(arr[sx][sy-1]==str[i])
        {
            ans.pb("left");
            dfs(sx,sy-1,ans,i+1);
        }
        else if(arr[sx][sy+1]==str[i])
        {
            ans.pb("right");
            dfs(sx,sy+1,ans,i+1);
        }
        
    }

public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
        {
		    ans.clear();
            cin>>m>>n;
            repi(i,0,m)
            {
                repi(j,0,n)
                {
                    cin>>arr[i][j];
                    if(arr[i][j]=='@')
                    {
                        sx=i;sy=j;
                    }
                    if(arr[i][j]=='#')
                    {
                        dx=i;dy=j;
                    }
                }
            }
            dfs(sx,sy,ans,0);
            repi(i,0,ans.size())
            {
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
	}
};
