// https://codeforces.com/contest/2103/problem/C

#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool possible = false;
    int end_idx;
    int sum_left = 0, sum_right = 0;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] <= k) sum_left++;
        else sum_left--;
        if (sum_left >= 0) {
            end_idx = i;
            break;
        }
    }

    for (int i = n - 1; i > end_idx + 1; i--) {
        if (a[i] <= k) sum_right++;
        else sum_right--;
        if (sum_right >= 0) {
            break;
        }
    }

    possible |= (sum_right >= 0) && (sum_left >= 0);

    vector<int> pmx(n), smx(n);
    for (int i = n - 2; i >= 1; i--) {
        pmx[i] = max(0, pmx[i + 1]);
        pmx[i] += (a[i] <= k ? 1 : -1);
    }

    for (int i = 1; i < n - 1; i++) {
        smx[i] = max(0, smx[i - 1]);
        smx[i] += (a[i] <= k ? 1 : -1);
    }

    sum_left = 0; sum_right = 0;
    for (int i = 0; i < n - 2; i++) {
        sum_left += (a[i] <= k ? 1 : -1);
        if (sum_left >= 0) {
            possible |= pmx[i + 1] >= 0;
        }
    }

    for (int i = n - 1; i >= 2; i--) {
        sum_right += (a[i] <= k ? 1 : -1);
        if (sum_right >= 0) {
            possible |= smx[i - 1] >= 0;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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