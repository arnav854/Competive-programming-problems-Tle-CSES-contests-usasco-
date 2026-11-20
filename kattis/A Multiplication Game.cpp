#include <iostream>
using namespace std;

using ll = long long;

void solve_case(ll n) {
    if (n <= 1) {
        cout << "Stan wins.\n";
        return;
    }

    ll p = 1;
    int turn = 0; // 0 = Stan, 1 = Ollie

    while (p < n) {
        if (p * 9 >= n) {
            cout << (turn == 0 ? "Stan wins.\n" : "Ollie wins.\n");
            return;
        }

        if (p * 81 >= n) {
            p *= 2;
        } else {
            p *= 9;
        }

        turn ^= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    while (cin >> n) {
        solve_case(n);
    }

    return 0;
}