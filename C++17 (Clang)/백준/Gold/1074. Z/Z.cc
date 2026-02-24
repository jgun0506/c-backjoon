#include <bits/stdc++.h>

int ans = 0;
int r, c;
using namespace std;

void func(int n, int x, int y) {
    if (n == 0) {
        if (x == r && y == c) {
            cout << ans;
        }
        return;
    }

    int a = pow(2, n - 1);

    if (r / (a+x) == 1) {
        ans += pow(2, 2*n-1);
        x += a;
    }
    if (c / (a+y) == 1) {
        ans += pow(2, 2 * n - 2);
        y += a;
    }
    func(n - 1, x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n >> r >> c;
    
    func(n, 0, 0);

    return 0;
}