#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int s, d, ans;
    while(cin >> s >> d) {
        d = -d, ans = -1;
        for(int mask = 1; mask < (1 << 12); ++mask) {
            int total, i;
            for (i = 4; i < 12; ++i) {
                total = 0;
                for(int j = i - 4; j <= i; ++j)
                    total += ((1 << j) & mask) ? s : d;
                if (total > 0) break;
            }
            if (i == 12) {
                total = 0;
                for(int j = 0; j < 12; ++j)
                    total += ((1 << j) & mask) ? s : d;
                ans = max(total, ans);
            }
        }
        if (ans == -1)
            cout << "Deficit" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
