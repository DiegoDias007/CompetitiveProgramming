#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

int ask(int x1, int x2) {
    cout << x1 + 1 << " " << x2 + 1 << endl;
    int y;
    cin >> y;
    return y;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> groups;

    for (int i = 0; i < n; i++) groups.push_back({i});

    auto merge_groups = [&]() -> void {
        int m = groups.size();
        vector<vector<int>> new_groups;
        for (int i = 0; i < m - 1; i+=2) {
            new_groups.push_back({});
            for (auto x : groups[i]) new_groups.back().push_back(x);
            for (auto x : groups[i+1]) new_groups.back().push_back(x);
        }

        if (m % 2 == 1) new_groups.push_back(groups.back());

        groups = new_groups;
    };

    while (true) {
        for (int i = 0; i < groups.size() - 1; i+=2) {
            int m1 = groups[i].size();
            int m2 = groups[i+1].size();
            for (int k1 = 0; k1 < m1; k1++) {
                for (int k2 = 0; k2 < m2; k2++) {
                    int a = ask(groups[i][k1], groups[i+1][k2]);
                    if (a) return;
                }
            }
        }
        merge_groups();
        if (groups.size() == 1) break;
    }
}

int main() {

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}