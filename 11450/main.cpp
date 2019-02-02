#include <iostream>

using namespace std;

#define INF (1<<30)
int N, C, M, K[20];
int price[20][20];
int state[20][201];

int main(int argc, char **argv) {
    cin >> N;
    while(N--) {
        cin >> M >> C;
        for (int i = 0; i < C; ++i) {
            cin >> K[i];
            for(int j = 0; j < K[i]; ++j)
                cin >> price[i][j];
        }
        // initialize state table
        for (int i = 0; i < C; ++i)
            for (int j = 0; j <= M; ++j) 
                state[i][j] = 0;

        // fill in the pre-reqs
        for (int i = 0; i < K[0]; ++i) {
            if (price[0][i] <= M)
                state[0][price[0][i]] = 1;
        }
        // fill up the table
        for (int g = 0; g < C - 1; ++g) {
            for(int m = 0; m < M; ++m) {
                if (state[g][m] == 1) {
                    for(int k = 0; k < K[g+1]; ++k) {
                        if (m + price[g+1][k] <= M)
                            state[g+1][m + price[g+1][k]] = 1;
                    }}}}
        // extract the answer
        int ans = 0;
        for (int i = 0; i <= M; ++i)
            if (state[C-1][i]) ans = i;

        if (ans == 0) cout << "no solution" << endl;
        else cout << ans << endl;
    }
    return 0;
}
