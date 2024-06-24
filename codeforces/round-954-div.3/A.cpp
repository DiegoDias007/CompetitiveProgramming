#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
void print_vec(const vector<int>& vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if(i != vec.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
 
template <typename K, typename V>
void print_map(const map<K, V>& m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second;
        if (next(it) != m.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}
 
void solve() {
    vector<int> a(3);
    for (auto & i : a) {
        cin >> i;
    }
 
    int min_answer = 999;
    for (int num1 : a) {
        int ans = 0;
        for (int num2 : a) {
            ans += abs(num1 - num2);
        }
 
        min_answer = min(min_answer, ans);
    }
 
    cout << min_answer << endl;
 } 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
 
    return 0;
}