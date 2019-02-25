#include <iostream>
#include <vector>
#include <cstring>

#define INF (1 << 30)

using namespace std;

typedef pair<int,int> ii;

int t, w, n;
vector<ii> treasures;
int memo[30][1001];
int used[30];

void printSack(int id, int remA) {
    if (id == n - 1) {
        used[id] = (remA >= treasures[id].first);
        return;
    }
    if (memo[id+1][remA] == memo[id][remA]) {
        printSack(id+1, remA);
        return;
    }
    used[id] = 1;
    printSack(id+1, remA - treasures[id].first);
    return;
}

/*****
 * @params
 *      id: index for current item under consideration
 *      remA: The air remaining
 * @return
 *      maximum value that can be extracted in gold with remA
 *      after considering item at id and later
 */
int get(int id, int remA) {
    // cout << id << " " << remA << endl;
    if (remA == 0) return 0;
    if (id == n) return 0;
    if (memo[id][remA]) return memo[id][remA];
    if (remA < treasures[id].first) {
        return memo[id][remA] = get(id+1, remA);
    }
    return memo[id][remA] = max(get(id + 1, remA - treasures[id].first) 
                                        + treasures[id].second,
                                get(id + 1, remA));
}

int main(int argc, char **argv) {
    if (!(cin >> t >> w)) return 0;
    while(true) {
        cin >> n;
        treasures.clear();
        memset(memo, 0, sizeof(memo));
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; ++i) {
            treasures.push_back(ii());
            cin >> treasures.back().first >> treasures.back().second;
            treasures.back().first = treasures.back().first * 3 * w;
        }
        int ans = get(0, t); cout << ans << endl;
        printSack(0, t);
        ans = 0;
        for(int i = 0; i < n; ++i)
            if (used[i]) ++ans;
        cout << ans << endl;
        for(int i = 0; i < n; ++i) 
            if (used[i]) 
                cout << treasures[i].first/(3*w)<<" "<< treasures[i].second << endl;
        if (cin >> t >> w) cout << endl;
        else break;
    }
    return 0;
}
