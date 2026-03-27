#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a;
        int st = 0, en = n - 1, mid = n / 2;
         
        cin >> a;
         
        while (st <= en) {
            if (arr[mid] > a) {
                en = mid - 1;
                mid = (st + en) / 2;
            }
            else if (arr[mid] < a) {
                st = mid + 1;
                mid = (st + en) / 2;
            }
            else {//같을경우
                cout << 1 << "\n";
                break;
            }
        }
        if (arr[mid] != a) {
            cout << 0 << "\n";
        }
    }
    

    return 0;
}

