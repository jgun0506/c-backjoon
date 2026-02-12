#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    stack<int> pare;
    int size = s.size();
    int ans = 0;
    int right = true;
    int k = 1;
    for (int i = 0; i < size; i++) {
        if (s[i] == '(') {
            pare.push(2);
            k *= 2;
        }
        else if (s[i] == '[') { 
            pare.push(3);
            k *= 3;
        }
        else if (s[i] == ')') {
            if (pare.empty() || pare.top() != 2) {
                right = false;
                break;
            }
            pare.pop();
            if (s[i - 1] != ')' && s[i - 1] != ']')
                ans += k;
            k /= 2;
        }
        else if (s[i] == ']') {
            if (pare.empty() || pare.top() != 3) {
                right = false;
                break;
            }
            pare.pop();
            if (s[i - 1] != ')' && s[i - 1] != ']')
                ans += k;
            k /= 3;
        }
    }
    if (!pare.empty() || !right)
        cout << 0;
    else
        cout << ans;


    return 0;
}