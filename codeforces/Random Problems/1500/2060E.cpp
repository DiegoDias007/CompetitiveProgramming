// https://codeforces.com/problemset/problem/2060/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int find(vector<int>& parent, int node) {
    if (parent[node] != node) parent[node] = find(parent, parent[node]);
    return parent[node];
}

void uni(vector<int>& parent, int u, int v) {
    int parent_u = find(parent, u);
    int parent_v = find(parent, v);
    parent[parent_u] = parent_v;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> parent1(n), parent2(n), parent_removal(n);;
    for (int i = 0; i < n; i++) {
        parent1[i] = i;
        parent2[i] = i;
        parent_removal[i] = i;
    }
    
    vector<set<int>> adj(n);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uni(parent1, u, v);
        adj[u].insert(v);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uni(parent2, u, v);
    }

    int ans = 0;
    for (int node = 0; node < n; node++) {
        vector<int> remove;
        for (auto child : adj[node]) {
            if (find(parent2, node) != find(parent2, child)) {
                ans++;
                remove.push_back(child);
            } else {
                uni(parent_removal, node, child);
            }
        }
        for (auto r : remove) adj[node].erase(r);
    }

    map<int, set<int>> mp;
    for (int i = 0; i < n; i++) mp[find(parent2, i)].insert(find(parent_removal, i));
    
    for (auto [parent, nodes] : mp) ans += nodes.size() - 1;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}