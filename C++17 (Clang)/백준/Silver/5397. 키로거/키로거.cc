#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        list<char> L;
        auto cursor = L.begin();

        for (char c : s) {
            if (c == '<' && cursor != L.begin()) {
                cursor--;
            }
            else if (c == '>' && cursor != L.end()) {
                cursor++;
            }
            else if (c == '-' && L.size() != 0 && cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
            else if (isdigit(c) || isalpha(c)) {//알파벳과 숫자의 경우
                L.insert(cursor, c);
               
            }
        }

        for (char c : L) {
            cout << c;
        }
        cout << "\n";
    }
    

}