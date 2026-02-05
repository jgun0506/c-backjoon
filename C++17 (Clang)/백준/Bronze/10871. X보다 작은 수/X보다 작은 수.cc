#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, x;

    std::cin >> n >> x;

    int num;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num < x) {
            std::cout << num << " ";
        }
    }
    




}