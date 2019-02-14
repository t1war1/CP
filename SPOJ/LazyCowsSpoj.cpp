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
int t,n,k,b;
vector<pii> arr2[2];
vector<pii> arr1;
int cache[1005][1005];

bool comparePairs(pii p1, pii p2)
{
    return (p1.se<p2.se)?1:((p1.se>p2.se)?0:(p1.fi<p2.fi));
}

int dp(int ind, int k)
{

    if(k<0)
    {
        return oo;
    }

    if(k==0)
    {
        if(ind==arr2[0].size())
            return 0;
        return oo;
    }


    if(cache[ind][k]!=-1)
        return cache[ind][k];

//    int sum1=0,sum2=0;
    bool f1=0,f2=0;
    int l1=-1,r1=-1,l2=-1,r2=-1,ans=oo;
    for(int i=ind;i<arr2[0].size();i++)
    {
        if(arr2[0][i].se)
        {
            f1=1;
            if(l1==-1)
            {
                l1=arr2[0][i].fi;
            }else{
                r1=arr2[0][i].fi;
            }
        }
        if(arr2[1][i].se)
        {
            f2=1;
            if(l2==-1)
            {
                l2=arr2[1][i].fi;
            }else{
                r2=arr2[1][i].fi;
            }
        }
//        sum1+=arr2[0][i].se;
//        sum2+=arr2[1][i].se;

        if(f1 && f2)
        {
            ans=min(ans,(arr2[0][i].fi-arr2[0][ind].fi+1)*2 + dp(i+1,k-1));
            int x=((r1==-1)?1:(r1-l1+1));
            x+=((r2==-1)?1:r2-l2+1);
            x+=dp(i+1,k-2);
            ans=min(ans,x);
        }
        else if(f1 && !f2)
        {
             ans=min(ans,((r1==-1)?1:r1-l1+1)+dp(i+1,k-1));
        }
        else
        {
             ans=min(ans,((r2==-1)?1:r2-l2+1)+dp(i+1,k-1));
        }
    }
    cache[ind][k]=ans;
    return ans;

}

class LazyCowsSpoj {
public:
	void solve(istream& cin, ostream& cout) {
        cin>>t;
        while(t--)
        {
            memset(cache,-1, sizeof(cache));
            arr1.clear();
            arr2[0].clear();
            arr2[1].clear();
            cin>>n>>k>>b;
            repi(i,0,n)
            {
                int x,y;
                cin>>x>>y;
                arr1.pb({x,y});
            }
            sort(arr1.begin(),arr1.end(),comparePairs);
            int i=0;
            while(i<n)
            {
                arr2[0].pb({0,0});
                arr2[1].pb({0,0});
                if(arr1[i].fi==1)
                {
                    arr2[0][arr2[0].size()-1].fi=arr1[i].se;
                    arr2[0][arr2[0].size()-1].se=1;
                    arr2[1][arr2[1].size()-1].fi=arr1[i].se;
                    if(arr1[i+1].se==arr1[i].se)
                    {
                        arr2[1][arr2[1].size()-1].se=1;
                        i+=2;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    arr2[0][arr2[1].size()-1].fi=arr1[i].se;
                    arr2[1][arr2[1].size()-1].fi=arr1[i].se;
                    arr2[1][arr2[1].size()-1].se=1;
                    i++;
                }
            }

            cout<<dp(0,k)<<"\n";
        }

	}
};
