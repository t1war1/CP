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

class ChallengeChefAndMatchingGame {
    void print(vector<vector<pair<int,int>>> ans)
    {
        for(auto v:ans)
        {
            cout<<v.size();
            for(auto i:v)
            {
                cout<<" "<<i.fi<<" "<<i.se;
            }
            cout<<"\n";
        }
    }
public:
	void solve(istream& cin,ostream& cout) {
	    int n,m;
	    cin>>n>>m;
	    vector<pair<int,int>> markedNodes;
	    bool mat[n+1][n+1];
	    repi(i,1,n+1)
	        repi(j,1,n+1)
	            mat[i][j]=0;

        repi(i,0,2*m){
            int u,v;
            cin>>u>>v;
            markedNodes.pb({u,v});
            mat[u][v]=1;
        }

        int weights[n+1][n+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>weights[i][j];

        int i=1,flag=0;
        vector<int> costs;
        vector<vector<vector<pair<int,int>>>> answers;


        vector<vector<pair<int,int>>> ans1;
        vector<pair<int,int>> path;
        ll cost1=0;
        while(1)
        {
            repi(j,1,n+1)
            {
                if(mat[i][j] && flag==1)
                {
                    cost1+=weights[i][j];
                    path.pb({i,j});
                    ans1.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost1+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost1+=weights[i][j];
                    path.pb({i,j});
                }
            }
            i++;
            if(i>n)break;

            repd(j,n,0)
            {
                if(mat[i][j] && flag==1)
                {
                    cost1+=weights[i][j];
                    path.pb({i,j});
                    ans1.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost1+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost1+=weights[i][j];
                    path.pb({i,j});
                }
            }
            i++;
            if(i>n)
                break;
        }
        costs.pb(cost1);
        answers.pb(ans1);

        vector<vector<pair<int,int>>> ans2;
        ll cost2=0;
        i=1;flag=0;
        while(1)
        {
            repd(j,n,0)
            {
                if(mat[i][j] && flag==1)
                {
                    cost2+=weights[i][j];
                    path.pb({i,j});
                    ans2.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost2+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost2+=weights[i][j];
                    path.pb({i,j});
                }
            }
            i++;
            if(i>n)
                break;

            repi(j,1,n+1)
            {
                if(mat[i][j] && flag==1)
                {
                    cost2+=weights[i][j];
                    path.pb({i,j});
                    ans2.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost2+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost2+=weights[i][j];
                    path.pb({i,j});
                }
            }
            i++;
            if(i>n)break;

        }
        costs.pb(cost2);
        answers.pb(ans2);

        vector<vector<pair<int,int>>> ans3;
        ll cost3=0;
        int j=1;flag=0;

        while(1)
        {
            for(i=1;i<=n;i++)
            {
                if(mat[i][j] && flag==1)
                {
                    cost3+=weights[i][j];
                    path.pb({i,j});
                    ans3.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost3+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost3+=weights[i][j];
                    path.pb({i,j});
                }
            }
            j++;
            if(j>n)break;

            for(i=n;i>0;i--)
            {
                if(mat[i][j] && flag==1)
                {
                    cost3+=weights[i][j];
                    path.pb({i,j});
                    ans3.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost3+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost3+=weights[i][j];
                    path.pb({i,j});
                }
            }
            j++;
            if(j>n)
                break;
        }
        costs.pb(cost3);
        answers.pb(ans3);

        vector<vector<pair<int,int>>> ans4;
        ll cost4=0;
        j=1;flag=0;

        while(1)
        {
            for(i=n;i>0;i--)
            {
                if(mat[i][j] && flag==1)
                {
                    cost4+=weights[i][j];
                    path.pb({i,j});
                    ans4.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost4+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost4+=weights[i][j];
                    path.pb({i,j});
                }
            }
            j++;
            if(j>n)
                break;

            for(i=1;i<=n;i++)
            {
                if(mat[i][j] && flag==1)
                {
                    cost4+=weights[i][j];
                    path.pb({i,j});
                    ans4.pb(path);
                    flag=0;
                    vector<pair<int,int>> tmp;
                    path=tmp;

                }
                else if(mat[i][j] && flag==0)
                {
                    flag=1;
                    cost4+=weights[i][j];
                    path.pb({i,j});
                }
                else if(flag==1)
                {
                    cost4+=weights[i][j];
                    path.pb({i,j});
                }
            }
            j++;
            if(j>n)break;
        }
        costs.pb(cost4);
        answers.pb(ans4);

        int ind=0,maxCost=INT_MIN;
        for(int k=0;k<costs.size();k++)
        {
            if(costs[k]>maxCost)
            {
                ind=k;
                maxCost=costs[k];
            }
        }

        print(answers[ind]);
	}
};

int main() {
    fastIO;
	ChallengeChefAndMatchingGame solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
