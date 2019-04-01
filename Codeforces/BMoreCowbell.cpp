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
class BMoreCowbell {
    int n,k,arr[100010];
    bool isValid(int mid)
    {
        int i=0,j=n-1,count=0;
        while(i<=j)
        {
            if(arr[j]>mid)
            {
                return 0;
            }
            if(arr[i]<=(mid-arr[j]))
            {
                i++;
            }
            j--;
            count++;
        }
        return count<=k;
    }

public:
	void solve(istream& cin, ostream& cout) {
		cin>>n>>k;
		repi(i,0,n)
        {
		    cin>>arr[i];
        }
        int beg=1,last=arr[n-1]+((n!=1)?arr[n-2]:0),ans=INT_MAX;
		while(beg<=last)
        {
		    int mid=(beg+last)/2;
		    if(isValid(mid))
            {
                last=mid-1;ans=mid;
            }else{
                beg=mid+1;
		    }
        }
		cout<<ans;
	}
};
