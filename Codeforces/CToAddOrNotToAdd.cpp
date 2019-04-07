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
class CToAddOrNotToAdd {
public:
    ll n,k;
    vector<ll> arr,prefixSums;
    
    bool isValid(ll mid, ll i)
    {
        if(arr[i]*mid-(prefixSums[i-1]-prefixSums[i-1-mid])<=k)
            return 1;
        return 0;
    }
    
	void solve(istream& cin, ostream& cout) {
        cin>>n>>k;
        arr.resize(n+1,0);
        prefixSums.resize(n+1);
        repi(i,1,n+1)
        {
            cin>>arr[i];
        }
        sort(arr.begin()+1,arr.end());
        prefixSums[0]=0;
        for(int i=1;i<=n;i++)
        {
            prefixSums[i]=prefixSums[i-1]+arr[i];
        }

        ll maxOccurence=1,minNo=arr[1];
        for(ll i=2;i<=n;i++)
        {
            ll beg=1,last=i-1,ans=INT_MIN;
            while(beg<=last)
            {
                ll mid=(beg+last)/2;
                if(isValid(mid,i))
                {
                    ans=mid;
                    beg=mid+1;
                } else{
                    last=mid-1;
                }
            }
            if(ans+1>maxOccurence)
            {
                maxOccurence=ans+1;
                minNo=arr[i];
            }
        }
        
        cout<<maxOccurence<<" "<<minNo;


	}
};
