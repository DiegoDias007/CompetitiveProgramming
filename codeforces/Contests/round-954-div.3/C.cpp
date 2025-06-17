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
    int n, m;
    cin >> n >> m;
    cin.ignore();
    
    string s1;
    cin >> s1;
    
    set<int> indexes;
    for (int i = 0; i < m; i++) {
        int cur;
        cin >> cur;
        indexes.insert(cur);
    }
    
    cin.ignore();
    
    string s2;
    cin >> s2;
 
    sort(s2.begin(), s2.end());
    int pointer = 0;
    for (int num : indexes) {
        s1[num - 1] = s2[pointer++];
    }
 
    cout << s1 << endl;
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