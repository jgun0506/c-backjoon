#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll ans;
ll a, b, c;

int func(ll b) {
    if (b == 0) 
        return 1;
    if (b == 1)
        return a % c;
    
    if (b % 2 == 0) //짝
        return func(b / 2) % c * func(b / 2) % c;
    else //홀
        return func(b / 2) % c * func(b / 2) % c * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    
    ans = func(b);
    cout << ans;
    return 0;
}