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
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
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

class LuckyNumberGame {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		int t;
		cin>>t;
		while(t--)
        {
		    int n,a,b,ca=0,cb=0,cboth=0;
		    cin>>n>>a>>b;
		    while(n--)
            {
		        int num;
		        cin>>num;
		        if(num%a==0 && num%b==0)
                {
		            cboth++;
                }
		        else if(num%a==0)
		            ca++;
                else if(num%b==0)
                    cb++;
            }
		    if(b%a==0)
            {
		    	if(cboth || ca)
		        	cout<<"BOB\n";
		    	else
		    		cout<<"ALICE\n";
		        continue;
            }

		    if(a%b==0)
			{
		    	if(cb)
		    		cout<<"ALICE\n";
		    	else
		    		cout<<"BOB\n";
		    	continue;
			}
            
             if(cboth>0)
                ca++;
            
		    if(ca>cb)
		    	cout<<"BOB\n";
			else
				cout<<"ALICE\n";

        }
	}
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	LuckyNumberGame solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
