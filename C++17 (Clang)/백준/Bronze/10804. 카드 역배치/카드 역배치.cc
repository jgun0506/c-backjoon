#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
int num[21];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 20; i++) {
        num[i] = i;
    }

    int a, b;
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverse(num + a, num + b + 1);
    }
    for (int i = 1; i <= 20; i++) {
        cout << num[i] << ' ';
    }
}