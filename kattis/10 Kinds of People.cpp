#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAX_BASE = 7500;

int char_to_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
    if (c >= 'A' && c <= 'Z') return 36 + (c - 'A');
    return 0;
}

struct BaseVal {
    long long val;
    int base;
};

long long eval_in_base(const string& s, int base) {
    long long res = 0;
    for (char c : s) {
        res = res * base + char_to_val(c);
    }
    return res;
}

vector<BaseVal> generate_pairs(const string& s) {
    int max_d = 0;
    for (char c : s) {
        max_d = max(max_d, char_to_val(c));
    }
    int min_base = max(2, max_d + 1);
    vector<BaseVal> pairs;
    if (min_base > MAX_BASE) {
        return pairs;
    }
    pairs.reserve(MAX_BASE - min_base + 1);
    for (int b = min_base; b <= MAX_BASE; ++b) {
        pairs.push_back({eval_in_base(s, b), b});
    }
    return pairs;
}

void solve_case(const string& s1, const string& s2) {
    vector<BaseVal> p1 = generate_pairs(s1);
    vector<BaseVal> p2 = generate_pairs(s2);

    size_t i = 0, j = 0;
    while (i < p1.size() && j < p2.size()) {
        if (p1[i].val == p2[j].val) {
            cout << p1[i].val << " " << p1[i].base << " " << p2[j].base << "\n";
            return;
        } else if (p1[i].val < p2[j].val) {
            ++i;
        } else {
            ++j;
        }
    }
    cout << "CANNOT MAKE EQUAL\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    for (int tc = 0; tc < n; ++tc) {
        string s1, s2;
        cin >> s1 >> s2;
        solve_case(s1, s2);
    }
    return 0;
}