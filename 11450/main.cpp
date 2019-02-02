#include <iostream>

using namespace std;

#define INF (1<<30)
int N, C, M, K[20];
int price[20][20];
int state[20][201];

/* @params
 *      money:  amount left to buy garments with
 *      g:      garment number currently attempting to buy
 * @returns
 *      min money left after buying one of garment g and onwards if possible
 *      INF otherwise
 */
int shop(int money, int g) {
    if (money < 0) return INF;
    if (g == C) return money;
    if (state[g][money] != INF) return state[g][money];
    int ans = INF;
    for (int i = 0; i < K[g]; ++i)
        ans = min(ans, shop(money - price[g][i], g+1));
    return (state[g][money] = ans);
}

int main(int argc, char **argv) {
    cin >> N;
    while(N--) {
        cin >> M >> C;
        for (int i = 0; i < C; ++i) {
            cin >> K[i];
            for(int j = 0; j < K[i]; ++j)
                cin >> price[i][j];
        }
        for (int i = 0; i < C; ++i)
            for (int j = 0; j <= M; ++j)
                state[i][j] = INF;
        int ans = shop(M, 0);
        if (ans == INF) cout << "no solution" << endl;
        else cout << M - ans << endl;
    }
    return 0;
}
