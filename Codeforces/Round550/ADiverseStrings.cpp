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
class ADiverseStrings {
    int arr[26];
public:
	void solve(istream& cin, ostream& cout) {
		int n;
		cin>>n;
		while(n--)
        {
		    string str;
		    cin>>str;
		    memset(arr,0, sizeof(arr));
		    int start=-1,end=-1;
		    bool flag1=0,flag2=0;
		    for(int i=0;i<str.length();i++)
            {
		        arr[str[i]-'a']++;
            }
		    for(int i=0;i<26;i++)
            {
		        if(arr[i]>1)
                {
		            flag2=1;
                    break;
                }
                if(arr[i]!=0)
                {
                    if(start==-1)
                    {
                        start=i;end=i;
                        flag1=1;
                    }
                    else
                    {
                        if(!flag1)
                        {
                            flag2=1;
                            break;
                        }
                        else{
                            end=i;
                        };
                    }
                }
                else{
                    flag1=0;
                }
            }
            if(flag2)
            {
                cout<<"No"<<"\n";
                continue;
            }
            cout<<"Yes"<<"\n";
        }
	}
};
