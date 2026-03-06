#include <bits/stdc++.h>
using namespace std;
int n, l;

int isin(int k) {//k가 l이포함되잇으면 true
    while (k > 0) {
        if (k % 10 == l) {
            return 1;
        }
        k /= 10;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num = 0;
    cin >> n >> l;
    int i = 1;
    while (num < n) {
        if (!isin(i)) {//만약 i가 ㅣ이포함x
            i++;
            num++;
            continue;
        }
        else {
            i++;
        }
    }

    cout << i-1 ;
    return 0;
}

