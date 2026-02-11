#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        stack <char> s;
        string a;
        getline(cin, a);
        bool right = true;
        if (a == ".")//종료조건
            break;
        int size = a.size();

        for (int i = 0; i < size; i++) {
            if (a[i] == '(') {
                s.push('(');
            }
            else if (a[i] == '[') {
                s.push('[');
            }
            else if (a[i] == ')') {//1.짝짝이 맞아야함
                if (s.empty() || s.top() != '(') {
                    right = false;
                    break;
                }
                s.pop();
            }
            else if (a[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    right = false;
                    break;
                }
                s.pop();
            }
        }

        if (right && s.empty())
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }


    return 0;
}