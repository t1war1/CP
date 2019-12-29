#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define triplet pair<int,pair<int,int>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll dp[200001];
int main(){
    ll i,j,t,n,m,p,k;
    cin>>t;
    while(t--)
    {
    cin>>n>>p>>k;
    vector<ll> v(n);
    for(int i =0; i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
 
    //dp[0] = v[0];
    int ans =0;
    for(int i = 0; i < k - 1; i++)
        {dp[i] = v[i] + dp[i-1];if(dp[i] <= p)
            ans = i+1;}
 
    for(int i = k -1 ; i < n ; i++)
    {
        dp[i] = v[i] + dp[i - k];
        if(dp[i] <= p)
            ans = i + 1;
    }
 
    cout<<ans<<'\n';
    }
 
    return 0;
}