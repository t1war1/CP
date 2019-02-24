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

int n,r1,c1,r2,c2;
void clear( std::queue<pii> &q )
{
	std::queue<pii> empty;
	std::swap( q, empty );
}

int arr[51][51],visited[51][51];

class CConnect {
public:
	void solve(istream& cin, ostream& cout) {
		cin>>n>>r1>>c1>>r2>>c2;
		memset(visited,0,sizeof(visited));
		repi(i,1,n+1)
		{
			repi(j,1,n+1)
			{
				char ch;
				cin>>ch;
				arr[i][j]=ch-'0';
			}
		}



		set<pii> hashset1,hashset2;

		queue<pii> q;
		visited[r1][c1]=1;
		q.push({r1,c1});
		while(!q.empty())
		{
			pii curr=q.front();
			hashset1.insert({curr.fi,curr.se});
			q.pop();
			if(curr.fi+1<=n && arr[curr.fi+1][curr.se]==0 && !visited[curr.fi+1][curr.se])
			{
				visited[curr.fi+1][curr.se]=1;
				q.push({curr.fi+1,curr.se});
			}
			 if(curr.fi-1>0 && arr[curr.fi-1][curr.se]==0 && !visited[curr.fi-1][curr.se])
			{
				visited[curr.fi-1][curr.se]=1;
				q.push({curr.fi-1,curr.se});
			}
			 if(curr.se+1<=n && arr[curr.fi][curr.se+1]==0 && !visited[curr.fi][curr.se+1])
			{
				visited[curr.fi][curr.se+1]=1;
				q.push({curr.fi,curr.se+1});
			}
			 if(curr.se-1>0 && arr[curr.fi][curr.se-1]==0 && !visited[curr.fi][curr.se-1])
			 {
				 visited[curr.fi][curr.se-1]=1;
			 	q.push({curr.fi,curr.se-1});
			 }
		}

		if(hashset1.find({r2,c2})!=hashset1.end())
		{
			cout<<0;
			return;
		}

		clear(q);
		visited[r2][c2]=1;
		q.push({r2,c2});
		while(!q.empty())
		{
			pii curr=q.front();
			hashset2.insert({curr.fi,curr.se});
			q.pop();
			if(curr.fi+1<=n && arr[curr.fi+1][curr.se]==0 && !visited[curr.fi+1][curr.se])
			{
				visited[curr.fi+1][curr.se]=1;
				q.push({curr.fi+1,curr.se});
			}
			if(curr.fi-1>0 && arr[curr.fi-1][curr.se]==0 && !visited[curr.fi-1][curr.se])
			{
				visited[curr.fi-1][curr.se]=1;
				q.push({curr.fi-1,curr.se});
			}
			if(curr.se+1<=n && arr[curr.fi][curr.se+1]==0 && !visited[curr.fi][curr.se+1])
			{
				visited[curr.fi][curr.se+1]=1;
				q.push({curr.fi,curr.se+1});
			}
			if(curr.se-1>0 && arr[curr.fi][curr.se-1]==0 && !visited[curr.fi][curr.se-1])
			{
				visited[curr.fi][curr.se-1]=1;
				q.push({curr.fi,curr.se-1});
			}
		}
		int ans=INT_MAX;
		for(set<pii>::iterator itr1=hashset1.begin(); itr1!=hashset1.end() ;itr1++)
		{
			for(set<pii>::iterator itr2=hashset2.begin(); itr2!=hashset2.end() ;itr2++)
			{
				int cost=((itr1->fi)-(itr2->fi))*((itr1->fi)-(itr2->fi));
				cost+=((itr1->se)-(itr2->se))*((itr1->se)-(itr2->se));
				ans=min(ans,cost);
			}
		}
		cout<<ans;
	}
};
