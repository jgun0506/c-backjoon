#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define num first
#define high second


int tower[80001];
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int total = 0;
    int n;
    stack<pair<int,int>> s;

    cin >> n;

    for (int i = n-1; i >= 0; i--) {
        cin >> tower[i];
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().high < tower[i]) {
            s.pop();
        }
        if(s.empty())
            total += i;
        else
            total += i - s.top().num - 1;
        
        s.push({ i, tower[i] });
    }
    
    cout << total;

    return 0;
}