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
    {
        PrimeSet(j);
    }
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
long long compute_hash(string const &s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// Trinary Search
double f(double x)
{
    // return some value
}
double ternary_search(double l, double r)
{
    double eps = 1e-9; // set the error limit here
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); // evaluates the function at m1
        double f2 = f(m2); // evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l); // return the maximum of f(x) in [l, r]
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

// number conversion
long long n = stoll(str, nullptr, base);
ans = to_string(n);
string binary = bitset<64>(n).to_string();
stringstream ss;
ss << std::oct << n;
string octal = ss.str();
ans = octal;
stringstream ss;
ss << std::hex << n;
string hexa = ss.str();
transform(hexa.begin(), hexa.end(), hexa.begin(), ::toupper);
ans = hexa;