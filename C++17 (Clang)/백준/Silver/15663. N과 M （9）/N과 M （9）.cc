#include <bits/stdc++.h>

int n, m;
int arr[10];
int num[10];
int vis[10002];
int len;
using namespace std;

void func(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) {
            cout << num[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < len; i++) {
        if (vis[arr[i]] > 0) {
            vis[arr[i]] -= 1;
            num[k] = arr[i];
            func(k + 1);
            vis[arr[i]] += 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (vis[a] == 0) 
            arr[len++] = a;
        vis[a]++;
    }

    sort(arr, arr + len);
    func(0);

    return 0;
}

