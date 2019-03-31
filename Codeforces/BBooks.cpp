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
class BBooks {
    int n,t;
    vector<int> arr;
public:
	void solve(istream& cin, ostream& cout) {
		arr.clear();
		cin>>n>>t;

        //approach 1
        //repi(i,0,n)
//        {
//		    int x;cin>>x;arr.pb(x);
//        }
//        int ans=0,i=0,j=0,sum=0;
//		while(j<n)
//        {
//		    sum+=arr[j++];
//		    if(sum>t)
//            {
//		        sum-=arr[i++];
//            }
//
//		        ans=max(ans,j-i);
//        }
        //cout<<ans;

        //approach 2
        arr.pb(0);
        repi(i,0,n)
        {
		    int x;cin>>x;arr.pb(x+arr[arr.size()-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=upper_bound(arr.begin()+i,arr.end(),t+arr[i])-(arr.begin()+i)-1;
            ans=max(ans, x);
        }
        cout<<ans;
	}
};
