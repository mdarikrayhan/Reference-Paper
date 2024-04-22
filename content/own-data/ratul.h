/**
 * Author: Md. Arik Rayhan
 * Date: 2023-11-01
 * License: CC0
 * Description: This is a template for creating own data structure.
 * Time: O(n)
 * Status: Tested on codeforces
 */

a, b, c = map(int, input().split())
array = list(map(int, input().split()))
array = []
array.append(x,y/x)
from collections import defaultdict
Hash = defaultdict(int)
dp = [-1] * (n + 1)
specificRange = list(range(n + 1))
my_set = set()
my_set.add(value)
x = pow(a, b, c) //( a * a * a) % c)
x = a ** b 
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
// ordered set
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag,  tree_order_statistics_node_update>;
*(o_set.find_by_order(val), o_set.order_of_key(val) 

// check_if_string_is_a_subseq
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    if (dp[n][m] == a.size()......


// lcs
 string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    // minimum insertion and deletion to make b from a --> delete =  a.size() - dp[n][m]  insert = b.size() - dp[n][m]
    // print the lcs
    int i = n, j = m;
    string ans;
    while (i != 0 && j != 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        } else {
            if (dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }
    }
    reverse(ans.begin(), ans.end());

// lps
string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    int mx = 0;
    int ci, cj;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] > mx) {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }
        }
    }
    string ans;
    while (ci != 0 && cj != 0) {
        if (a[ci - 1] == b[cj - 1]) {
            ans += a[ci - 1];
            ci--;
            cj--;
        } else {
            break;
        }
    }
    reverse(ans.begin(), ans.end());

// lps
string a;
    cin >> a;
    int n = a.size();
    string b = a;
    reverse(b.begin(), b.end());
    int m = b.size();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // minimum deletion and insertion to make palindrome--> delete = b - dp[n][m]   insert =  b - dp[n][m]
    int i = n, j = m;
    string ans;
    while (i != 0 && j != 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        } else {
            if (dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }
    }
    reverse(ans.begin(), ans.end());
// shortest common supersequence
string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << n + m - dp[n][m] << endl; // scs size
    // print section
    int i = n, j = m;
    string ans;
    while (i != 0 && j != 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans += a[i - 1];
            i--;
        } else {
            ans += b[j - 1];
            j--;
        }
    }
    while (i != 0) {
        ans += a[i - 1];
        i--;
    }
    while (j != 0) {
        ans += b[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());