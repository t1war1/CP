#include <bits/stdc++.h>
#define mod 1000000007ll1
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

string str;
int cache[60][60];

int dp(int l ,int r)
{
    if(l==r)
    {
        return 1;
    }
    if(l>r)
        return 0;

    if(cache[l][r]!=-1)
        return cache[l][r];

    if(str[l]==str[r])
    {
        cache[l][r]=dp(l,r-1)+dp(l+1,r)+1;
        return cache[l][r];
    }
    cache[l][r]=dp(l,r-1)+dp(l+1,r)-dp(l+1,r-1);;
    return cache[l][r];
}

class AgainPalindrome {
public:
	void solve(istream& cin, ostream& cout) {
        int t;
        cin>>t;
        while(t--)
        {
            memset(cache,0, sizeof(cache));
            cin>>str;
            for(int i=1;i<=str.length();i++)
            {
                cache[i][i]=1;
            }
            for(int i=1;i<=str.length();i++)
            {
                for(int j=i+1;j<=str.length();j++)
                {
                    if(str[i-1]==str[j-1])
                    {
                        cache[i][j]=cache[i][j-1]+cache[i+1][j]+1;
                    }
                    else{
                        cache[i][j]=cache[i][j-1]+cache[i+1][j]-cache[i+1][j-1];
                    }
                }
            }
            cout<<cache[1][str.length()]<<endl;
        }
	}
};
