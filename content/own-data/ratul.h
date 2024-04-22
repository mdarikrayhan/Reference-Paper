/**
 * Author: Md. Arik Rayhan
 * Date: 2023-11-01
 * License: CC0
 * Description: This is a template for creating own data structure.
 * Time: O(n)
 * Status: Tested on codeforces
 */

// FASTIO
import sys
ONLINE_JUDGE = __debug__
if ONLINE_JUDGE:
    import io,os
    input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

// binary to demical
x = '1000'
y = int(x, 2)
print(y)
// decimal to binary
n = 100
binary = format(n, 'b')
print(binary)

// 2D array
rows, cols = (5, 5)
arr = [[0]*cols]*rows
matrix = []
print("Enter the entries rowwise:")
R, C = map(int, input().split())
# matrix = [[int(input()) for x in range (C)] for y in range(R)]
matrix = []
for i in range(R):
    array = list(map(int, input().split()))
    matrix.append(array)
# For printing the matrix
for i in range(R):
    for j in range(C):
        print(matrix[i][j], end = " ")
    print()
// sorting
array.sort()
array.sort(reverse=True)

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

    
// ## deBUG
// divisible by 0
// array bound
// constraints
// pre calculation
// generate max and min cases 
// check TLE
// check overflow
// anything uninitialized 
// vector might fail
// check consecutive case
// check output format whitespace
// Check all cases provided in problem
// Check for overflow (long long case)
// TLE:
// Check constraint
// how many times are you using loop? or nested loop?
// If it is a math problem and you are getting TLE then loop won't work. Check for a equation
// Runtime error:
// Check if you are doing division by zero
// array out of bound (al)
// Check if you are running loop outside your array limit or string limit
// Wrong Answer:
// Check for constraint. Are you thinking for the highest & lowest constraint?
// Does it need long long?
// Any corner case you are not thinking?
// Facing overflow? check if needs long long
// Garbage? Any uninitialized varible you are using?
// Which case you are skipping ? don't skip check that
// // life is  hard? think with python