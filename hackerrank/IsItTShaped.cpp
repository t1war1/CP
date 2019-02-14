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

string yo(vector<vector<int>> grid) {
    bool mat[3][3];
    memset(mat,0, sizeof(mat));
    for(int i=0;i<grid.size();i++)
    {
        int x=grid[i][0];
        int y=grid[i][1];
        mat[x%3][y%3]=1;
    }
    if(mat[1][0] && mat[1][1]&&mat[1][2]&&mat[0][2]&&mat[2][2])
        return "Yes";
    if(mat[0][1] && mat[1][1]&&mat[2][0]&&mat[2][1]&&mat[2][2])
        return "Yes";
    if(mat[0][0] && mat[1][0]&&mat[2][0]&&mat[1][1]&&mat[1][2])
        return "Yes";
    if(mat[0][0] && mat[0][1]&&mat[0][2]&&mat[1][1]&&mat[2][1])
        return "Yes";
    return "No";
}

class IsItTShaped {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
        {
		    vector<vector<int>> grid;
		    for(int i=0;i<5;i++)
            {
                int x,y;
                cin>>x>>y;
                vector<int> a;
                a.pb(x);
                a.pb(y);
                grid.pb(a);
            }
		    cout<<yo(grid)<<endl;
        }
	}
};
