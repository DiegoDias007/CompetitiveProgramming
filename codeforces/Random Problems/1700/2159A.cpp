#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<int> idxs(2*n);
    iota(idxs.begin(), idxs.end(), 1);

    vector<int> a(2*n);

    auto get_ans = [&](vector<int>& b, vector<int>& ask) {
        for (int i = 0; i < b.size(); i++) {
            ask.push_back(b[i]);
            cout << "? " << ask.size() << " ";
            print_vec(ask);

            int query;
            cin >> query;

            if (query == 0) continue;

            int j = b[i] - 1;
            a[j] = query;
            ask.pop_back();
        }
    };

    vector<int> ask;
    get_ans(idxs, ask);

    idxs.clear();
    ask.clear();
    for (int i = 2*n - 1; i >= 0; i--) {
        if (a[i] == 0) idxs.push_back(i + 1);
        else ask.push_back(i + 1); 
    }
    get_ans(idxs, ask);

    cout << "! ";
    print_vec(a);
}

int main() {    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}