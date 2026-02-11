#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#define num first
#define index second
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;

    deque <int> d;
    deque <pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        while (!s.empty() && s.back().num >= c) {
            s.pop_back();
        }
        s.push_back({ c,i });
        d.push_back(s.front().num);
        if ((i - s.front().index+1) == l) 
            s.pop_front();
    }

    while (!d.empty()) {
        cout << d.front() << " ";
        d.pop_front();
    }

    return 0;
}