#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define num first
#define count second

int high[500001];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long total = 0;
    int n;
    int pos = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> high[i];
    }

    stack<pair<int, int>> s;
    
    s.push({ high[0] , 1 });

    for (int i = 1; i < n; i++) {
        while (!s.empty() && (s.top().num) < high[i]) {
            total += s.top().count;
            s.pop();
        }
        if (s.empty()) {
            s.push({ high[i],1 });
        }
        else if (!s.empty() && s.top().num == high[i]) {
            total += s.top().count;
            if (s.size() != 1)
                total++;
            s.top().count += 1;
        }
        else if (!s.empty() && s.top().num > high[i]) {
            total += 1;
            s.push({ high[i],1 });
        }

    }
    cout << total;

    return 0;
}