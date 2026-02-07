#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

int arr[1000001];
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int total = 0;
    int n;
    stack<int> s;
    stack<int> ans;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        if (s.empty())
            ans.push(-1);
        else
            ans.push(s.top());
        s.push(arr[i]);
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}