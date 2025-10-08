#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> longest_depth_from_here(n + 1);
    int mx_depth = 0;
    for (int node = 1; node <= n; node++) {
        cout << "?" << " " << node << " " << n << " ";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl << flush;
        int depth;
        cin >> depth;
        mx_depth = max(mx_depth, depth);
        longest_depth_from_here[depth].push_back(node);
    }

    vector<int> path;
    path.push_back(longest_depth_from_here[mx_depth][0]);
    for (int cur_depth = mx_depth - 1; cur_depth >= 1; cur_depth--) {
        for (auto node : longest_depth_from_here[cur_depth]) {
            path.push_back(node);
            cout << "?" << " " << path[0] << " " << path.size() << " ";
            print_vec(path);
            cout << flush;
            int depth;
            cin >> depth;
            if (depth == path.size()) break;
            else path.pop_back();
        }
    }

    cout << "!" << " " << path.size() << " ";
    print_vec(path);
    cout << flush;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}