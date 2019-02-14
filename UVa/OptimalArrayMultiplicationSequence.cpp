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

int n,rows[15],cols[15],cache[15][15],directions[15][15];

int dp(int l, int r)
{
    if(l==r)
        return 0;
    if(cache[l][r]!=-1)
        return cache[l][r];

    int ans=1<<30;
    for(int i=l;i<=r-1;i++)
    {
        int tmp=dp(l,i)+dp(i+1,r)+rows[l]*cols[i]*cols[r];
        if(tmp<ans)
        {
            ans=tmp;
            directions[l][r]=i;
        }
    }
    return ans;
}

void print(int l,int r)
{
    if(l==r)
    {
        cout<<"A"<<l;
        return;
    }
    cout<<"(";
    print(l,directions[l][r]);
    cout<<" x ";
    print(directions[l][r]+1,r);
    cout<<")";
}


class OptimalArrayMultiplicationSequence {
public:
	void solve(istream& cin, ostream& cout) {
	    int t=1;
        while(1)
        {
            memset(cache,-1, sizeof(cache));
            cin>>n;
            if(n==0) break;

            repi(i,1,n+1)
            {
                cin>>rows[i]>>cols[i];
            }

            dp(1,n);
            cout<<"Case "<<t<<": ";
            print(1,n);
            cout<<endl; 
            t++;
        }
	}
};
