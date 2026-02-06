#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

int arr[100005];
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string ans;
    stack<int> s;
    
    int n;
    int i = 1;
    int j = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    while(j<n){
        if (s.empty() || s.top() < arr[j]) {
            s.push(i);
            ans.push_back('+');
            i++;
        }   
        else if (s.top() == arr[j]) {
            s.pop();
            ans.push_back('-');
            j++;
        }
        else {
            cout << "NO";
            return 0;
        }
    }       
    
    for (char c : ans) {
        cout << c << "\n";
    }
    return 0;
}