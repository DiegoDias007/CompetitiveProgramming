#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
template <typename K, typename V> void print_map(const map<K, V>& m) {  cout << "{"; for (auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ": " << it->second; if (next(it) != m.end()) { cout << ", ";}}cout << "}" << endl;}
 
string s;
 
void solve() {
    cin >> s;
    int index = 0; char letter = s[0];
    bool best = false;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) {
            index = i; letter = s[i]; best = true;
        } else if (s[i] != s[i - 1] && !best) {
            index = i; letter = s[i];
        }
    }
 
    string new_string = ""; char new_char = (letter == 'z') ? 'a' : letter + 1;
    if (!best) {
        index = s.size() - 1; new_char = (s.back() == 'z') ? 'a' : letter + 1;
        for (int i = 0; i < (int)s.size(); i++) {
            new_string += s[i];
            if (i == index) {
                new_string += new_char;
            }
        }
    } else {
        for (int i = 0; i < (int)s.size(); i++) {
            if (i == index) {
                new_string += new_char;
            }
            new_string += s[i];
        }
    }
 
    cout << new_string << endl;
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