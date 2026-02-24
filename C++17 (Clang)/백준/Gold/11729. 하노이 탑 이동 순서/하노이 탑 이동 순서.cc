#include <bits/stdc++.h>

using namespace std;
void func(int n, int st, int ed) {
    if (n == 1) {
        cout << st << ' ' << ed << "\n";
        return;
    }
    func(n - 1, st, 6 - st - ed);
    func(1, st, ed);
    func(n - 1, 6 - st - ed, ed);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k = 0;
    int n;
    cin >> n;

    k = pow(2, n) - 1;

    cout << k << "\n";
    func(n, 1, 3);

    return 0;
}