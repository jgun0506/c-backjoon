#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
int ans[500005];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int num = 1;
    cin >> n;
    stack<int> stack_high;
    stack<int> stack_num;

    while (n--) {
        int a;
        cin >> a;

        while (!stack_high.empty() && stack_high.top() < a) {
            //스택이 비엇거나 입력한 높이보다 더 높은 탑이나올때까지
            stack_high.pop();
            stack_num.pop();
        }
        if (stack_num.empty()) 
            cout << 0 << " ";
        else
            cout << stack_num.top() << " ";

        stack_high.push(a);
        stack_num.push(num);
        num++;
    }


    return 0;
}