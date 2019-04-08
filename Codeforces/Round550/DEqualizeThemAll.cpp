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
class DEqualizeThemAll {
    int n;
    vector<pii> arr;
    map<int,int> m;
public:
	void solve(istream& cin, ostream& cout) {
		cin>>n;
		arr.resize(n);
		m.clear();
		repi(i,0,n)
        {
		    cin>>arr[i].ff;
		    arr[i].ss=i;
		    m[arr[i].ff]++;
        }
        int maxfreq=INT_MIN,no=-1,index=-1;
        for(auto p:m)
        {
            if(maxfreq<p.ss)
            {
                maxfreq=p.ss;
                no=p.ff;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i].ff==no)
            {
                index=i;
                break;
            }
        }
        cout<<(n-maxfreq)<<"\n";
//        for(int i=0;i<n;i++)
//        {
//            if(arr[i].ff>no)
//            {
//                cout<<2<<" "<<(i+1)<<" "<<(index+1)<<"\n";
//            }
//            else if(arr[i].ff<no)
//            {
//                cout<<1<<" "<<(i+1)<<" "<<(index+1)<<"\n";
//            }
//        }
        for(int i=index-1;i>=0;i--)
        {
            if(arr[i].ff>no)
            {
                cout<<2<<" "<<(i+1)<<" "<<(i+2)<<"\n";
            }
            else if(arr[i].ff<no)
            {
                cout<<1<<" "<<(i+1)<<" "<<(i+2)<<"\n";
            }
        }
        for(int i=index+1;i<n;i++)
        {
            if(arr[i].ff>no)
            {
                cout<<2<<" "<<(i+1)<<" "<<(i)<<"\n";
            }
            else if(arr[i].ff<no)
            {
                cout<<1<<" "<<(i+1)<<" "<<(i)<<"\n";
            }
        }

	}
};
