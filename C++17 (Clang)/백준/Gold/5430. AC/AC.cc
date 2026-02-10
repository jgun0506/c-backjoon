#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) {
        string p;
        string arr;
        deque<int> dq;
        int n;
        cin >> p >> n >> arr;

        int i = 0;
        while (n) {//배열 입력받기
            int num = 0;
            while (isdigit(arr[i])) {
                num *= 10;
                num += arr[i] - '0';
                i++;
            }
            if (num > 0) {
                dq.push_back(num);
                n--;
            }
            i++;
        }
        bool error = false;
        int where = 0;//짝수:front_pop(), 홀수:back_pop()
        int size_p = p.size();
        for (int i = 0; i < size_p; i++) {
            if (p[i] == 'R') {//뒤집기
                where++;
            }
            else if (p[i] == 'D') {
                //만약 비어있는dq pop할경우 error
                if (dq.empty()) {
                    error = true;
                    break;
                }
                else if (where % 2 == 0) {//앞에서뽑기
                    dq.pop_front();
                }
                else {//뒤에서뽑기
                    dq.pop_back();
                }
            }
        }

        int size_dq = dq.size();
        if (error) {
            cout << "error" << "\n";
        }
        else {
            cout << '[';
            for (int i = 0; i < size_dq-1; i++) {
                if (where % 2 == 0) {
                    cout << dq.front() << ",";
                    dq.pop_front();
                }
                else {
                    cout << dq.back() << ",";
                    dq.pop_back();
                }
            }
            if (where % 2 == 0&&size_dq>0) {
                cout << dq.front();
                dq.pop_front();
            }
            else if(where % 2 == 1 && size_dq > 0){
                cout << dq.back();
                dq.pop_back();
            }
            cout << "]\n";
        }
    }
    return 0;
}