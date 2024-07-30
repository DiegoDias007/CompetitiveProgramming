#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
template <typename K, typename V> void print_map(const map<K, V>& m) {  cout << "{"; for (auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ": " << it->second; if (next(it) != m.end()) { cout << ", ";}}cout << "}" << endl;}
 
int n;
string first_row, second_row;
 
 
void solve() {
    cin >> n >> first_row >> second_row;
    vector<int> count_first(n), count_second(n);
    int cnt = 0;
    
    for (int i = 0; i <= n; i++) {
        if (i < n && first_row[i] == '.') {
            cnt++;
        } else {
            for (int index = i - 1; index >= i - cnt && index >= 0; index--) {
                count_first[index] = cnt;
            }
            cnt = 0;
        }
    }
 
    for (int i = 0; i <= n; i++) {
        if (i < n && second_row[i] == '.') {
            cnt++;
        } else {
            for (int index = i - 1; index >= i - cnt && index >= 0; index--) {
                count_second[index] = cnt;
            }
            cnt = 0;
        }
    }
 
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (count_first[i] >= 3 && count_second[i] == 1 && (first_row[i - 1] == '.' && first_row[i + 1] == '.')) ans++;
        if (count_first[i] == 1 && second_row[i] >= 3 && (second_row[i - 1] == '.' && second_row[i + 1] == '.')) ans++;
    }
 
    cout << ans << endl;
 
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