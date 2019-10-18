    
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
#define int     long long

using namespace std;
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
        if(n > 0)
            s << arr[n - 1] ;
        s<< "]";
        return s.str();
    }
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
const int N=1e5+10;

int n,m,k;
vector<int> rows[N],cols[N];


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;

    cin>>n>>m>>k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        rows[x].push_back(y);
        cols[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        sort(all(rows[i]));
    }
    for(int i=0;i<m;i++)
    {
        sort(all(cols[i]));
    } 
    int reqd=n*m-k,count=1;
    int l=0,r=m-1,u=0,d=n-1,x=0,y=0,dir=0,f=0;

    while (l <= r && u <= d) {
        
        if (dir == 0) {
            int nx = r;
            auto it = upper_bound(all(rows[y]), x);
            if (it != rows[y].end()) nx = min(nx, *it - 1);
            if (nx == x) {
                if(f!=0)
                {
                    break;
                }
                f++;
                dir++;
                continue;
            }
            u = max(u, y + 1);
            count += abs(x - nx);
            x = nx;
        } else if (dir == 1) {
            int ny = d;
            auto it = upper_bound(all(cols[x]), y);
            if (it != cols[x].end()) ny = min(ny, *it - 1);
            r = min(r, x - 1);
            if (ny == y) break;
            count += abs(ny - y);
            y = ny;
        } else if (dir == 2) {
            int nx = l;
            auto it = upper_bound(all(rows[y]), x);
            if (it != rows[y].begin()) nx = max(nx, *prev(it) + 1);
            d = min(d, y - 1);
            if (nx == x) break;
            count += abs(x - nx);
            x = nx;
        } else {
            int ny = u;
            auto it = upper_bound(all(cols[x]), y);
            if (it != cols[x].begin()) ny = max(ny, *prev(it) + 1);
            l = max(l, x + 1);
            if (ny == y) break;
            count += abs(y - ny);
            y = ny;
        }
        dir++;
        f++;
        dir %= 4;
    }
    trace(count);
    if(count==reqd)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
