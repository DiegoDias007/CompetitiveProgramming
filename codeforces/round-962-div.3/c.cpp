#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
template <typename K, typename V> void print_map(const map<K, V>& m) {  cout << "{"; for (auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ": " << it->second; if (next(it) != m.end()) { cout << ", ";}}cout << "}" << endl;}
 
int n, q;
string a, b;
 
void solve() {
    cin >> n >> q >> a >> b;
    vector<vector<int>> prefix1(n + 1, vector<int>(26, 0));
    vector<vector<int>> prefix2(n + 1, vector<int>(26, 0));
    
    for (int i = 1; i <= n; i++) {
        prefix1[i] = prefix1[i - 1];
        prefix2[i] = prefix2[i - 1];
        
        prefix1[i][a[i - 1] - 'a']++;
        prefix2[i][b[i - 1] - 'a']++;
    }
 
    while (q--) {
        int q1, q2;
        cin >> q1 >> q2;
 
        vector<int> a1 = prefix1[q2], a2 = prefix1[q1 - 1];
        vector<int> b1 = prefix2[q2], b2 = prefix2[q1 - 1];
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int c1 = a1[i] - a2[i];
            int c2 = b1[i] - b2[i];
            if (c2 > c1)
                ans += c2 - c1;
        }
 
        cout << ans << endl;
    }
} 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
