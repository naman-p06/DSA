#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> prefix(n + 1, 0);
    for (long long i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + (s[i] - '0')) % 9;
    }
    
    for (long long i = 0; i < q; i++) {
        long long a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int sum1 = (prefix[b] - prefix[a - 1] + 9) % 9;
        int sum2 = (prefix[d] - prefix[c - 1] + 9) % 9;
        long long ans = (sum1 * sum2) % 9;

        if (ans == e) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
