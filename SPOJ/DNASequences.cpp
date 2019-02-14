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

int cache[1005][1005];

class DNASequences {
public:
	void solve(istream& cin, ostream& cout) {
	    while(1)
        {
	        int k;
	        cin>>k;
	        if(!k)
	            return;

	        string str1,str2;
	        cin>>str1>>str2;
	        memset(cache,0, sizeof(cache));

	        for(int i=0;i<=str1.length();i++)
			{
	        	cache[0][i]=0;
			}
			for(int i=0;i<=str2.length();i++)
			{
				cache[i][0]=0;
			}

			for(int i=1;i<=str1.length();i++)
			{
				for(int j=1;j<=str2.length();j++)
				{

					int c = 1;
					while(i-c>=0 && j-c>=0 && str1[i-c]==str2[j-c]){
						if(c>=k)
							cache[i][j] = max(cache[i][j], c+cache[i-c][j-c]);
						c++;
					}
					cache[i][j] = max(cache[i][j], cache[i-1][j]);
					cache[i][j] = max(cache[i][j], cache[i][j-1]);
				}
			}
			cout<<cache[str1.length()][str2.length()]<<"\n";
        }

	}
};
