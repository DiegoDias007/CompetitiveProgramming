// https://codeforces.com/problemset/problem/2111/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int floor(string& s) {
    string f = "";
    for (int i = 0; i < s.size() - 2; i++) f += s[i];
    return stoi(f);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), [&](string x, string y) {
        return floor(x) < floor(y);
    });
    
    map<string, int> cnt;
    vector<pair<string, string>> ans(n);
    int l = 0, r = m - 1;
    for (int i = 0; i < n; i++) {
        if (cnt[a[l]] == 2) l++;
        if (cnt[a[r]] == 2) r--;
        string left = a[l];
        string right = a[r];
        cnt[left]++;
        cnt[right]++;
        ans[i].first = left;
        ans[i].second = right;
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (flag) swap(ans[i].first, ans[i].second);
        for (int j = 0; j < 3; j++) {
            cout << ans[i].first << " " << ans[i].second << " ";
        }
        cout << endl;
        flag = !flag;
    }
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