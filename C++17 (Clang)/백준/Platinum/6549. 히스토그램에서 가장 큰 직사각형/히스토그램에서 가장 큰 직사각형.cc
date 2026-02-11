#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

int s[100005][2];//0:num,1:index

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int n;
        int pos = 0;
        long long max = 0;
        cin >> n;
        if (n == 0)
            break;

        int num;
        int i = 0;
        while (n--) {
            cin >> num;
            int b = i;
            while (pos > 0 && s[pos - 1][0] > num) {
                pos--;
                b = s[pos][1];
            }
            if (pos == 0 || s[pos - 1][0] != num) {//같지않으면 push
                s[pos][0] = num;
                s[pos][1] = b;
                pos++;
            }
         
            for (int j = 0; j < pos; j++) {
                if (max < (long long)(i - s[j][1] + 1) * s[j][0])
                    max = (long long)(i - s[j][1] + 1) * s[j][0];
            }
            i++;
        }
        cout << max << "\n";
    }

    return 0;
}