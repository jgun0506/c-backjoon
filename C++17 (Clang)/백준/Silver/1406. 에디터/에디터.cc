#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> lst;
    string s;
    cin >> s;

    for (char c : s) {
        lst.push_back(c);
    }

    auto cursor = lst.end();
    int m;
    cin >> m;

    while (m--) {
        char command;
        cin >> command;

        if (command == 'L' && cursor != lst.begin()) {
            cursor--;
        }
        else if (command == 'D' && cursor != lst.end()) {
            cursor++;
        }
        else if (command == 'B' && cursor != lst.begin()) {
            cursor--;
            cursor = lst.erase(cursor);
        }           
        else if (command == 'P') {
            char x;
            cin >> x;
            lst.insert(cursor, x);
        }           
    }
    for (char a : lst) {
        cout << a;
    }
}