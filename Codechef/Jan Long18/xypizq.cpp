/**
 * @author Gaurav Tiwari
 */



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

class APizzaSlice {
	ll gcd(ll a, ll b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}
public:
	void solve(std::istream& cin, std::ostream& cout) {
	    int t;
	    cin>>t;
	    while(t--)
        {
	        ll n,t,x,y,z;
	        cin>>n>>t>>x>>y>>z;
	        ll myY=2*n+1;
	        if(t==1)
			{
	        	if(x==y)
				{
	        		cout<<0<<" "<<1<<"\n";
				}
	        	else if(x==z)
				{
	        		if(y==0)
					{
	        			cout<<1<<" "<<myY<<"\n";
					}
	        		else{
	        			if(x<y)
						{
	        				ll hcf=gcd(y-1,myY);
	        				cout<<(y-1)/hcf<<" "<<(myY/hcf)<<"\n";
						}else{
							ll hcf=gcd(y+1,myY);
							cout<<(y+1)/hcf<<" "<<(myY/hcf)<<"\n";
	        			}
	        		}
				}
	        	else{
	        		if(y==n && z==n)
					{
	        			ll hcf=gcd(n,myY);
	        			cout<<(n/hcf)<<" "<<(myY/hcf)<<"\n";
					}
	        		else{
	        			if(x<y)
						{
	        				ll hcf=gcd(myY-y-1,myY);
	        				cout<<(myY-y-1)/hcf<<" "<<myY/hcf<<"\n";
						}
	        			else{
							ll hcf=gcd(myY-y+1,myY);
							cout<<(myY-y+1)/hcf<<" "<<myY/hcf<<"\n";
	        			}
	        		}
	        	}
			}
	        else if(t==2)
			{
				if(x==z)
				{
					cout<<0<<" "<<1<<"\n";
				}
				else{
					if(y==n)
					{
						cout<<1<<" "<<myY<<"\n";
					}
					else{
						ll hcf=gcd(myY-2*y,myY);
						cout<<(myY-2*y)/hcf<<" "<<myY/hcf<<"\n";
					}
				}
			}
	        else if(t==3)
			{
				if(y==z)
				{
					cout<<0<<" "<<1<<"\n";
				}
				else if(x==z)
				{
					if(y>z)
					{
						ll hcf=gcd(y-1,myY);
						cout<<(y-1)/hcf<<" "<<(myY/hcf)<<"\n";
					}
					else{
						ll hcf=gcd(y+1,myY);
						cout<<(y+1)/hcf<<" "<<(myY/hcf)<<"\n";
					}
				}
				else{
					if(x==n && y==n)
					{
						ll hcf=gcd(n,myY);
						cout<<(n/hcf)<<" "<<(myY/hcf)<<"\n";
					}
					else{
						if(y>z)
						{
							ll hcf=gcd(myY-y-1,myY);
							cout<<(myY-y-1)/hcf<<" "<<myY/hcf<<"\n";
						}
						else{
							ll hcf=gcd(myY-y+1,myY);
							cout<<(myY-y+1)/hcf<<" "<<myY/hcf<<"\n";
						}
					}
				}
			}
	        else
			{
				if(x==z)
				{
					cout<<0<<" "<<1<<"\n";
				}
				else{
					if(y==n)
					{
						cout<<1<<" "<<myY<<"\n";
					}
					else{
						ll hcf=gcd(myY-2*y,myY);
						cout<<(myY-2*y)/hcf<<" "<<myY/hcf<<"\n";
					}
				}
			}
        }
	}
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	APizzaSlice solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
