// https://cses.fi/problemset/task/1667/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> came_from(n);
    vector<int> vis(n);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    bool possible = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == n - 1) {
            possible = true;
            break;
        }

        for (auto child : adj[node]) {
            if (!vis[child]) {
                vis[child] = true;
                came_from[child] = node;
                q.push(child);
            }
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ans;
    ans.push_back(n);
    int cur_node = n - 1;
    while (cur_node != 0) {
        int prev_node = came_from[cur_node];
        ans.push_back(prev_node + 1);
        cur_node = prev_node;
    }   
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    print_vec(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}