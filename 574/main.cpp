#include <iostream>
#include <vector>

using namespace std;

int numbers[12];
bool onuse[12];
int t, n, count;
vector<vector<int>> ans;

/**
 * @params
 *  idx:    current item the under consideration
 *  total:  the total so far
 */
void solve(int idx, int total) {
    if (total > t) return;
    if (idx == n) return;

    if (total + numbers[idx] == t) {
        ans.push_back({});
        for(int i = 0; i < idx; ++i)
            if (onuse[i]) ans.back().push_back(numbers[i]);
        ans.back().push_back(numbers[idx]);
    }
    onuse[idx] = true; solve(idx + 1, total + numbers[idx]);
    onuse[idx] = false; solve(idx + 1, total);
    return;
}

int main(int argc, char **argv) {
    cin >> t >> n;
    while(t != 0 && n!= 0) {
        for(int i = 0; i < n; ++i) cin >> numbers[i], onuse[i] = false;
        count = 0; ans.clear();
        cout << "Sums of " << t << ":" << endl;
        solve(0, 0);
        if (ans.size() == 0)
            cout << "NONE" << endl;
        else {
            for(int i = 0; i < ans[0].size() - 1; ++i)
                cout << ans[0][i] << "+";
            cout << ans[0].back() << endl;
            for(int i = 1; i < ans.size(); ++i) {
                bool isdup = false;
                for(int j = 0; j < i; ++j) {
                    if (ans[i] == ans[j]) { isdup = true; break; }
                }
                if (!isdup) {
                    for(int j = 0; j < ans[i].size() - 1; ++j)
                        cout << ans[i][j] << "+";
                    cout << ans[i].back() << endl;
                }
            }
        }
        cin >> t >> n;
    }
    return 0;
}
