
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ordered_multiset = tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

void solve() {
    int n, m, rank;
    cin >> n >> m >> rank;

    vector<string> v(n);
    for (auto &it : v) cin >> it;

    int no_ps = 0;
    vector<int> each_p(n, 0);

    for (int i = 0; i < n; i++) {
        for (char c : v[i]) {
            if (c == 'P') {
                each_p[i]++;
                no_ps++;
            }
        }
    }

    ordered_multiset st;

    // {current rank, original team index}
    for (int i = 0; i < n; i++) {
        st.insert({i + 1, i});
    }

    while (no_ps > 0) {

        pair<int,int> cur;
        bool found = false;

        for (auto it = st.rbegin(); it != st.rend(); ++it) {
            int idx = it->second;

            if (each_p[idx] > 0) {
                cur = *it;
                found = true;
                break;
            }
        }

        if (!found) break;

        int idx = cur.second;

        string a, b;
        cin >> a >> b;

        int calc_y = 0;

        for (char c : b) {
            if (c == 'y') calc_y++;
        }

        each_p[idx]--;
        no_ps--;

        if (calc_y == 0) continue;

        int back = calc_y - 3;

        if (back <= 0) continue;

        int pos = st.order_of_key(cur);

        vector<pair<int,int>> temp;

        for (int i = pos - back; i <= pos; i++) {
            temp.push_back(*st.find_by_order(i));
        }

        for (auto p : temp) {
            st.erase(p);
        }

        for (int i = 0; i < (int)temp.size(); i++) {

            if (i == back) {
                temp[i].first -= back;
            }
            else {
                temp[i].first++;
            }

            st.insert(temp[i]);
        }
    }

    for (auto it : st) {
        if (it.second == rank - 1) {
            cout << it.first << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
