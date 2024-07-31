#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
template <typename K, typename V> void print_map(const map<K, V>& m) {  cout << "{"; for (auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ": " << it->second; if (next(it) != m.end()) { cout << ", ";}}cout << "}" << endl;}
 
 
int n, k;
 
inline bool cmp(int n1, int n2) {
    if ((n1 % k) == (n2 % k)) 
        return n1 < n2;
        
    return (n1 % k) < (n2 % k);
}
 
void solve() {
    cin >> n >> k;
    
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    sort(a.begin(), a.end(), cmp);
 
    
    ll ans = 0;
    int num_odd = 0, index = 0;
    while (index < n) {
        
        vector<int> numbers; int current = a[index] % k;
        while (index < n) {
            int cur = a[index] % k;
            if (cur == current) 
                numbers.push_back(a[index++]);
            else
                break;
        }
 
        int numbers_size = numbers.size();
        
        if (numbers_size % 2 == 1) 
            num_odd++;
        
        if (num_odd > 1) {
            cout << -1 << endl;
            return;
        }
        
        if (numbers_size % 2 == 0) {
            for (int i = 0; i < numbers_size - 1; i+=2) {
                ans += 1ll * (numbers[i + 1] - numbers[i]) / k;
            }
            continue;
        }
 
        if (numbers_size == 1) {
            continue;
        }
 
        vector<int> shifted(numbers_size);
        int sum = 0;
        for (int i = numbers_size - 1; i >= 0; i-=2) {
            shifted[i] = sum;
            if (i > 0)
                sum += numbers[i] - numbers[i - 1];
        }
 
        int best_index = -1, min_sum = (int)1e9;
        int base_case = 0;
        for (int i = 0; i < numbers_size; i+=2) {
            int current_sum = base_case + shifted[i];
            if (current_sum < min_sum) {
                min_sum = current_sum;
                best_index = i;
            }
 
            if (i < n) base_case += numbers[i + 1] - numbers[i];
        }
 
        ans += min_sum / k;
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