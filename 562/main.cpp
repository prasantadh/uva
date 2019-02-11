#include <iostream>
#include <string.h>


#define INF (2 << 30)

using namespace std;

int N, M[100];
bool memo[100 * 500 + 1];

int main(int argc, char **argv) {
    cin >> N;
    while (N--) {
        int m, total = 0;
        cin >> m;
        for (int i = 0; i < m; ++i) { cin >> M[i]; total += M[i]; }
        memset((void *) memo, 0, sizeof(memo));
        // iterate through all possible sums
        // that can be made with the coins
        for (int i = 0; i < m; ++i) {
            for (int j = total; j > M[i]; --j)
                if (memo[j - M[i]]) memo[j] = true;
            memo[M[i]] = true;
        }
        // find the ans
        int i = total / 2;
        while (memo[i] == false and i > 0) --i;
        cout << total - (i * 2) << endl;

    }
    return 0;
}
