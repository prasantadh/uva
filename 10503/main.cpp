#include <iostream>
#include <vector>

using namespace std;

int n, m;
typedef pair<int, int> ii;
vector<ii> pcs;
bool used[14];
ii l, r;

/**
 * @param:
 *  idx:    current space index
 * @return
 *  true if the remaining spaces can be filled with remaining pieces
 *  false otherwise
 */

bool solve(int idx, int last) {
    if (idx == n) return last == r.first;
    for(int i = 0; i < m; ++i) {
        if (used[i] == false) {
            used[i] = true;
            if (pcs[i].first == last) {
                if (solve(idx + 1, pcs[i].second)) return true;
            } else if (pcs[i].second == last) {
                if (solve(idx + 1, pcs[i].first)) return true;
            }
            used[i] = false;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    cin >> n;
    while(n) {
        cin >> m; 
        cin >> l.first >> l.second >> r.first >> r.second;
        pcs.clear(); for(int i = 0; i < m; ++i) used[i] = false;
        for(int i = 0; i < m; ++i) {
            pcs.push_back(ii ());
            cin >> pcs.back().first;
            cin >> pcs.back().second;
        }
        if (solve(0, l.second)) cout << "YES" << endl;
        else cout << "NO" << endl;
        cin >> n;
    }
    return 0;
}
