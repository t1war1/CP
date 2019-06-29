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
#define mp make_pair
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"
#define int long long

using namespace std;

int oo = 0x3f3f3f3f;


int32_t main()
{
    fastIO;
    int q;
    cin>>q;
    while(q--)
    {
        int n,x;
        cin>>n;
        int arr[n+1]={0};
        for(int i=0;i<n;i++)
        {
            cin>>x; arr[x]++;
        }

        sort(arr+1,arr+n+1);
        int ans=arr[n],prev=arr[n];
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]<=0 || prev==0)
                break;
            ans+=min(arr[i],prev-1);
            prev=min(arr[i],prev-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}