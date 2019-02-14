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

struct BigInteger {
	static const int BASE = 1000000000; // 10^9

	vector<ll> digits;

	BigInteger() {
		digits.clear();
		digits.pb(0);
	}
	BigInteger(ll number) {
		digits.clear();
		do {
			digits.pb(number % BASE);
			number /= BASE;
		} while (number);
	}

	BigInteger operator + (const BigInteger &b) const {
		BigInteger res = BigInteger();
		res.digits.resize(max(b.digits.size(), digits.size()));
		ll remainder = 0;
		repi(i,0, res.digits.size()) {
			if (i < digits.size()) remainder += digits[i];
			if (i < b.digits.size()) remainder += b.digits[i];
			res.digits[i] = remainder % BASE;
			remainder /= BASE;
		}
		while (remainder) {
			res.digits.pb(remainder % BASE);
			remainder /= BASE;
		}
		return res;
	}

	BigInteger operator * (const BigInteger &b) const {
		BigInteger res = BigInteger();
		res.digits = vector<ll>(b.digits.size() + digits.size() - 1, 0);
		repi(i,0, digits.size()) repi(j,0, b.digits.size())
		res.digits[i + j] += digits[i] * (ll)b.digits[j];
		ll remainder = 0;
		repi(i,0, res.digits.size()) {
			remainder += res.digits[i];
			res.digits[i] = remainder % BASE;
			remainder /= BASE;
		}
		while (remainder) {
			res.digits.pb(remainder % BASE);
			remainder /= BASE;
		}
		return res;
	}

	void print() {
		printf("%lld", digits.back());
		repd(i, (int)digits.size() - 2,-1) printf("%09lld", digits[i]);
	}

	static BigInteger power(const BigInteger &b, ll k) {
		if (k == 0) return BigInteger(1);
		if (k == 1) return b;
		BigInteger res = power(b, k / 2);
		res = res * res;
		if (k & 1) return res * b;
		return res;
	}
};

BigInteger ways[1001];
class Counting {
public:
	void solve(istream& cin, ostream& cout) {

		ways[0] = BigInteger(1);
		repi(i,1,1001)
		{
			ways[i] = ways[i - 1] + ways[i - 1];
			if (i - 2 >= 0) ways[i] = ways[i] + ways[i - 2];
			if (i - 3 >= 0) ways[i] = ways[i] + ways[i - 3];
		}
		int n;
		while (cin>>n) {
			ways[n].print(); puts("");
		}


	}
};
