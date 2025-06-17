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
    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    
    bool flag = false;
    for (int i = 0; i < n; i++) {
        char value = s[i];
        if (value == '0') flag = true;
    }
 
    if (n == 2) {
        cout << stoi(s) << endl;
        return;
    }
 
    if (n == 3) {
		int val1 = (10 * (s[0] - '0') + (s[1] - '0')) + (s[2] - '0');
        int val2 = (10 * (s[0] - '0') + (s[1] - '0')) * (s[2] - '0');
        int val3 = (10 * (s[1] - '0') + (s[2] - '0')) + (s[0] - '0');
        int val4 = (10 * (s[1] - '0') + (s[2] - '0')) * (s[0] - '0');
 
        int ans = min(min(val1, val2), min(val3, val4));
 
        cout << ans << endl;
        
        return;
    } 
 
    if (flag) {
        cout << 0 << endl;
    } else {
        int ans = 1e9;
        for (int i = 0; i < n - 1; i++) {
            int sum = 0;
            int current = stoi(string(s.begin() + i, s.begin() + i + 2));
            sum += current;
            for (int j = 0; j < n; j++) {
                if (j == i || j == i + 1 || s[j] == '1') continue;
                sum += s[j] - '0';
            }
 
            ans = min(ans, sum);
        }
       
        cout << ans << endl;
    }
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