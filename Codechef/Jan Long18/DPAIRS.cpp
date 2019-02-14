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

class DistinctPairs {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>> a(n),b(m);
		for(int i=0;i<n;i++)
		{
			cin>>a[i].fi;
			a[i].se=i;
		}
		for(int i=0;i<m;i++)
		{
			cin>>b[i].fi;
			b[i].se=i;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int count=n+m-1,turn=0;
		if(a.size()<b.size())
		{
			turn=1;
			swap(a,b);
		}
		int i=0,j=0;
		while(i<a.size() && j<b.size())
		{
			if(!turn)
			{
				cout<<a[i].se<<" "<<b[i].se<<"\n";
			}else{
				cout<<b[i].se<<" "<<a[i].se<<"\n";
			}
			count--;
			i++;j++;
		}
		if(count)
		{
			i=1;j=0;
			while(i<a.size() && j<b.size())
			{
				if(!turn)
				{
					cout<<a[i].se<<" "<<b[j].se<<"\n";
				}else{
					cout<<b[j].se<<" "<<a[i].se<<"\n";
				}
				count--;
				if(count==0)
				{
					return;
				}
				i++;j++;
			}
			if(count)
			{
				i=b.size()+1;j=b.size()-1;
				while(i<a.size())
				{
					if(!turn)
					{
						cout<<a[i].se<<" "<<b[j].se<<"\n";
					}else{
						cout<<b[j].se<<" "<<a[i].se<<"\n";
					}
					count--;
					if(count==0)
						return;
					i++;
				}

			}
		}
	}
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	DistinctPairs solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
