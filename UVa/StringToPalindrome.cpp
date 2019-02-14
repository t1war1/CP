#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("   %s", x)
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
int cache[1005][1005];

class StringToPalindrome {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		repi(z,1,t+1)
        {
		    memset(cache,0, sizeof(cache));
            cin>>str;
            repi(k,0,str.length())
            {
                for(int i=0,j=k;j<=str.length()-1;i++,j++)
                {
                    if(str[i]==str[j])
                    {
                        if(i==0 && j==0)
                        {
                            cache[i][j]=0;
                            continue;
                        }
                        cache[i][j]=cache[i+1][j-1];
                    }
                    else{
                        cache[i][j]=min({cache[i+1][j],cache[i][j-1],cache[i+1][j-1]})+1;
                    }
                }
            }
            cout<<"Case "<<z<<": "<<cache[0][str.length()-1]<<endl;
        }

	}
};
