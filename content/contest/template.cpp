#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const char nl = '\n';

typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<ll, ll, greater<ll>> mllg;
typedef map<char, int> mci;
typedef map<string, int> msi;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

#define ins insert
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= a; i--)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

ull rangesum(ll L, ll R) { return ((L + R) * (abs(R - L) + 1)) / 2; }
bool isPalindrome(string S)
{
	string P = S;
	reverse(P.begin(), P.end());
	return S == P ? true : false;
}
bool isPowerof(ll num, ll base) { return (num > 0 && num % base == 0) ? isPowerof(num / base, base) : num == 1; }
bool isPowerofTwo(ll num) { return (num > 0 && (num & (num - 1)) == 0) ? true : false; }
int isSubstring(string main, string sub) { return main.find(sub) != string::npos ? main.find(sub) : -1; }

// 128 bit input output
__int128 read()
{
	__int128 x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(__int128 x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

// Custom Hash
struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
						 rb_tree_tag, tree_order_statistics_node_update>;
// *(o_set.find_by_order(val), o_set.order_of_key(val)

// cout<<"2^15 =                     32,768\n2^16 =                     65,536"<<endl;
// cout<<"2^31 =              2,147,483,648\n2^32 =              4,294,967,296"<<endl;
// cout<<"2^63 =  9,223,372,036,854,775,808 \n2^64 = 18,446,744,073,709,551,616"<<endl;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		
	}
	return 0;
}
