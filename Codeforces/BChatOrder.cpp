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
int oo = 0x3f3f3f3f;
class BChatOrder {
    int n;
    vector<string> arr;
    map<string,int> m;
public:
	void solve(istream& cin, ostream& cout) {
		m.clear();arr.clear();
		cin>>n;
        repi(i,0,n)
        {
            string str;cin>>str;
            if(m.find(str)==m.end())
            {
                m[str]=arr.size();
                arr.pb(str);
            } else{
                arr[m[str]]="";
                m[str]=arr.size();
                arr.pb(str);
            }
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]!="")
            {
                cout<<arr[i]<<"\n";
            }
        }



	}
};
