/**
 * Author: Md. Arik Rayhan
 * Date: 2023-11-01
 * License: CC0
 * Description: This is a template for creating own data structure.
 * Time: O(n)
 * Status: Tested on codeforces
 */

//Bellman Ford Algorithm
#include <bits/stdc++.h>

using namespace std;
int n, e;
class Edge {
    public: int u;
    int v;
    int w;
    Edge(int u, int v, int w) {
        this -> u = u;
        this -> v = v;
        this -> w = w;
    }
};

void bellman_ford(int source, vector < Edge > & g) {
    int dis[n + 1];
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[source] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < g.size(); j++) {
            Edge ed = g[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;
    vector < Edge > g;
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        g.push_back(ed);
    }
    int source = 1;
    bellman_ford(source, g);

    return 0;
}


//BFS 2D 
#include <bits/stdc++.h>

using namespace std;
using pii = pair < int, int > ;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n, m;
vector< pii > direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ) {
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m) return true;
    else return false;
}
void bfs(int si, int sj) {
    queue < pii > q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty()) {
        pii parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (pii p: direction) {
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ) && !vis[cI][cJ]) {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//cycle detection using using dfs
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector < int > g[N];
bool visited[N];

bool dfs(int source, int p = -1) {
    bool cycleExists = false;
    visited[source] = true;
    for (int child: g[source]) {
        if (child == p) continue;
        if (visited[child]) return true;
        cycleExists = cycleExists | dfs(child, source);
    }
    return cycleExists;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool isCycle = false;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        isCycle |= dfs(i);
    }

    if (isCycle)
        cout << "Cycle Detected!\n";
    else
        cout << "No Cycles!\n";

    return 0;

}

//dfs depth height
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector < int > g[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int source) {
    visited[source] = true;
    //cout << "Visiting node: " << u << endl;
    for (int child: g[source]) {
        if (visited[child] == true) continue;
        depth[child] = depth[source] + 1;
        dfs(child);
        height[source] = max(height[source], height[child] + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << "Depth of Node " << i << ": " << depth[i] << endl;
    }
    cout << "***************\n";
    for (int i = 1; i <= n; i++) {
        cout << "Height of Node " << i << ": " << height[i] << endl;
    }

    return 0;

}

//distra
#include<bits/stdc++.h>

using namespace std;
using pii = pair < int, int > ;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector < pii > g[N];
vector < int > dist(N, INF);
vector < bool > visited(N);
vector < int > par(N, -1);
vector < int > path;

void dijkstra(int source) {
    priority_queue < pii, vector < pii > , greater < pii >> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int parent = pq.top().second;
        pq.pop();
        visited[parent] = true;

        for (pii child_pair: g[parent]) {
            int child_node = child_pair.first;
            int child_cost = child_pair.second;

            if (!visited[child_node] and dist[child_node] > dist[parent] + child_cost) {
                dist[child_node] = dist[parent] + child_cost;
                pq.push({dist[child_node], child_node});
                par[child_node] = parent;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int source = 1;
    dijkstra(source);
    // all sources distance
    for (int i = 1; i <= n; i++) {
        cout << "Distance of node " << i;
        cout << " : " << dist[i] << endl;
    }
    // printing path from source to end
    if (dist[n] == INF) {
        cout << "-1" << '\n';
        return 0;
    } else {

        for (int parent = n; parent != -1; parent = par[parent]) {
            path.push_back(parent);
        }
        reverse(path.begin(), path.end());
        for (auto x: path) cout << x << " ";
    }

    return 0;

}

//floyd warshall
#include <bits/stdc++.h>

using namespace std;
const int INF = 1e7;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    int dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = INF;
            if (i == j) dis[i][j] = 0;
        }
    }
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (dis[i][j] == INF) cout << "INF"<< " ";
    //         else cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    cout << "Updated" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INF) cout << "INF" << " ";
            else cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//Kruskal
#include <bits/stdc++.h>

using namespace std;
class Edge {
    public: int a, b, w;
    Edge(int a, int b, int w) {
        this -> a = a;
        this -> b = b;
        this -> w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentSize[leaderA] > parentSize[leaderB]) {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        } else {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    vector < Edge > v;
    vector < Edge > ans;
    dsu_set(n);
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    for (Edge val: v) {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        dsu_union(a, b);
    }
    for (Edge val: ans) {
        cout << val.a << " " << val.b << " " << val.w << endl;
    }
    return 0;
}

//negative cycle detection using bellman ford
// #include <bits/stdc++.h>
// using namespace std;

// class Edge {
// public:
//     int u;
//     int v;
//     int w;
//     Edge(int u, int v, int w) {
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };

// int32_t main() {
//     ios_base::sync_with_stdio(false); 
//     cin.tie(nullptr); 

//     int n, e;
//     cin >> n >> e;
//     vector<Edge> g;
//     while (e--) {
//         int a, b, w;
//         cin >> a >> b >> w;
//         Edge ed(a, b, w);
//         g.push_back(ed);
//     }
//     int dis[n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     dis[1] = 0;
//     for (int i = 1; i <= n - 1; i++) {
//         for (int j = 0; j < g.size(); j++) {
//             Edge ed = g[j];
//             int a = ed.u;
//             int b = ed.v;
//             int w = ed.w;
//             if (dis[a] + w < dis[b]) {
//                 dis[b] = dis[a] + w;
//             }
//         }
//     }
//     bool cycle = false;
//     for (int j = 0; j < g.size(); j++) {
//         Edge ed = g[j];
//         int a = ed.u;
//         int b = ed.v;
//         int w = ed.w;
//         if (dis[a] + w < dis[b]) {
//             cycle = true;
//             break;
//             dis[b] = dis[a] + w;
//         }
//     }
//     if (cycle) {
//         cout << "Cycle Exist" << endl;
//     }
//     else {
//         for (int i = 1; i <= n; i++) {
//             cout << "Node " << i << ": " << dis[i] << endl;
//         }
//     }
//     return 0;
// }

// using pair

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair < ll, ll > ;
const char nl = '\n';

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define minimum(x) * min_element(x.begin(), x.end())
#define maximum(x) * max_element(x.begin(), x.end())

const int N = 1e5 + 7;
const ll INF = 1e18 + 7;
vector < pii > g[N];
vector < pair < pii, ll >> list_of_edges;
ll d[N];
int n, m;
bool cycle = false;
void bellman_ford(int source) {
    for (int i = 1; i <= n; i++) d[i] = INF;

    d[source] = 0;

    for (int i = 1; i < n; i++) {
        for (auto edge: list_of_edges) {
            ll u = edge.first.first;
            ll v = edge.first.second;
            ll w = edge.second;

            if (d[u] != INF && d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
    }
    for (auto edge: list_of_edges) {
        ll u = edge.first.first;
        ll v = edge.first.second;
        ll w = edge.second;

        if (d[u] != INF && d[v] > d[u] + w) {
            cycle = true;
            break;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        list_of_edges.push_back({{u, v}, w});
    }
    int source;
    cin >> source;

    bellman_ford(source);

    int q, flag = 0;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        if (cycle) {
            flag = 1;
            continue;
        }
        if (d[x] == INF) cout << "Not Possible" << '\n';
        else cout << d[x] << endl;
    }
    if (flag and cycle) cout << "Negative Cycle Detected" << '\n';

    return 0;

}

//prims
#include <bits/stdc++.h>

using namespace std;
using pi = pair < int, int > ;
const int N = 1e5 + 5;
vector < pi > g[N];
bool vis[N];
class Edge {
    public: int a, b, w;
    Edge(int a, int b, int w) {
        this -> a = a;
        this -> b = b;
        this -> w = w;
    }
};
class cmp {
    public: bool operator()(Edge a, Edge b) {
        return a.w > b.w;
    }
};
void prims(int s) {
    priority_queue < Edge, vector < Edge > , cmp > pq;
    vector < Edge > edgeList;
    pq.push(Edge(s, s, 0));
    while (!pq.empty()) {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if (!vis[b]) {
            vis[b] = true;
            edgeList.push_back(parent);
            for (int i = 0; i < g[b].size(); i++) {
                pi child = g[b][i];
                if (!vis[child.first]) {
                    pq.push(Edge(b, child.first, child.second));
                }
            }
        }

    }
    edgeList.erase(edgeList.begin());
    for (Edge val: edgeList) {
        cout << val.a << " " << val.b << " " << val.w << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    prims(1);
    return 0;
}

//segment tree
#include <bits/stdc++.h>

using namespace std;

vector < int > v;
vector < int > seg_tree;

void build_seg_tree(int node, int begin, int end) {

    if (begin == end) {
        seg_tree[node] = v[begin];
        return;
    }
    int left, right, mid;
    left = node * 2;
    right = (node * 2) + 1;
    mid = begin + ((end - begin) / 2);
    build_seg_tree(left, begin, mid);
    build_seg_tree(right, mid + 1, end);
    // as per condition
    seg_tree[node] = min(seg_tree[left], seg_tree[right]); // min case
    // seg_tree[node] = seg_tree[left] + seg_tree[right]; // for addition case
}

int query(int node, int begin, int end, int i, int j) {

    if (end < i or j < begin) return INT_MAX;
    // if(end < i or j < begin) return 0; // for addition case

    if (i <= begin and end <= j) return seg_tree[node];

    int left, right, mid, q1, q2;
    left = node * 2;
    right = (node * 2) + 1;
    mid = begin + ((end - begin) / 2);
    q1 = query(left, begin, mid, i, j);
    q2 = query(right, mid + 1, end, i, j);
    // operation of the query
    // here the query is to find minimum in given range
    // return q1 + q2; // for addition case
    return min(q1, q2);
}
void update(int node, int begin, int end, int i, int newvalue) {
    if (i > end or i < begin)
        return;
    if (begin >= i and end <= i) {
        seg_tree[node] = newvalue; // single update
        return;
    }
    // if (begin == i and end == i) { 
    //     seg_tree[node] += newvalue; // for addition in that element
    //     return;
    // }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (begin + end) / 2;
    update(Left, begin, mid, i, newvalue);
    update(Right, mid + 1, end, i, newvalue);
    seg_tree[node] = seg_tree[Left] + seg_tree[Right];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v.assign(n + 2, 0);
    seg_tree.assign((4 * n) + 2, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    build_seg_tree(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << query(1, 1, n, i + 1, j + 1) << "\n";
    }

    return 0;
}


//shortest path using bfs
#include <bits/stdc++.h>

using namespace std;

//bfs
const int N = 1e5 + 5;
vector < int > g[N];
bool visited[N];
int dis[N];
int par[N];

void bfs(int s) {
    queue < int > q;
    q.push(s);
    dis[s] = 0;
    par[s] = -1;
    visited[s] = true;
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        for (int child: g[parent]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                par[child] = parent;
                dis[child] = dis[parent] + 1;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // undirected
    }
    bfs(1);

    // for any specific node source
    int source;
    cin >> source;
    if (visited[source]) {
        vector < int > path;
        int search = source;
        while (search != -1) {
            path.push_back(search);
            search = par[search];
        }
        reverse(path.begin(), path.end());

        for (int val: path) cout << val << " ";
        cout << '\n';
    } else cout << "NO PATH\n";

    return 0;
}