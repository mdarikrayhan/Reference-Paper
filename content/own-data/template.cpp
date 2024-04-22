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

#define YES cout << "YES" << nl;
#define NO cout << "NO" << nl;

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
#define deb4(a, b, c, d) cout << #a << "=" << a << "," << #b << "=" << b << "," << #c << "=" << c << "," << #d << "=" << d << endl

// Bitwise Sieve
const int pmxsz = 100000000;
int status[(pmxsz / 32) + 2];
int prime[5761455 + 5], noofprime = 0;
inline bool Bit_Check(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int Bit_Set(int N, int pos) { return N = N | (1 << pos); }
inline bool PrimeCheck(int i) { return 1 ^ (bool)(Bit_Check(status[i >> 5], i & 31)); }
inline void PrimeSet(int i) { status[i >> 5] = Bit_Set(status[i >> 5], i & 31); }
inline void Mark(int i, int N)
{
    for (int j = i * i; j <= N; j += (i << 1))
        PrimeSet(j);
}
void sieve(int N = 100000000)
{
    int i, j, sqrtN;
    sqrtN = int(sqrt(N));
    for (i = 5; i <= sqrtN; i += 6)
    {
        if (PrimeCheck(i))
        {
            Mark(i, N);
        }
        if (PrimeCheck(i + 2))
        {
            Mark(i + 2, N);
        }
    }
    prime[noofprime++] = 2;
    prime[noofprime++] = 3;
    for (i = 5; i <= N; i += 6)
    {
        if (PrimeCheck(i))
        {
            prime[noofprime++] = i;
        }
        if (PrimeCheck(i + 2))
        {
            prime[noofprime++] = i + 2;
        }
    }
}

// Single Prime Check using Miller Rabin
ull binpower(ull base, ull e, ull mod)
{
    ull result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(ull n, ull a, ull d, int s)
{
    ull x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool MillerRabin(ull n)
{
    if (n < 2)
        return false;
    int r = 0;
    ull d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

// String Hashing
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

//Trinary Search
double f(double x) {
    //return some value
}
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}

// SPF using Sieve 10^6 in 280ms & 42MB
const int MAXN = 10e6 + 5;
int spf[MAXN];
vector<int> factor[MAXN];
inline vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
void sievefactor()
{
    spf[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        spf[i] = i;
    }
    for (int i = 4; i <= MAXN; i += 2)
    {
        spf[i] = 2;
    }
    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
        }
    }
    for (int i = 1; i <= MAXN; i++)
    {
        factor[i] = getFactorization(i);
    }
}

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static
        const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
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
    /*
    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int NoOfTestCase = 1;
    cin >> NoOfTestCase;
    for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)
    {
        
    }
    return 0;
}