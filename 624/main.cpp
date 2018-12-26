#include <iostream>

#define INF (1<<29)
using namespace std;

int N, ntracks, duration[20], least_remaining;
bool ans[20], onuse[20];

int solve(int remaining, int idx) {
    if (remaining < 0) return -INF;
    if ( idx > ntracks ) return 0;

    if (remaining < least_remaining) {
        least_remaining = remaining;
        for(int i = 0; i < ntracks; ++i) ans[i] = onuse[i];
    }

    onuse[idx] = true;
    int inclusive = solve(remaining - duration[idx], idx + 1) + duration[idx];
    onuse[idx] = false;
    int exclusive = solve(remaining, idx + 1);
    return max(inclusive, exclusive);
}

int main(int argc, char **argv) {
    while(cin >> N) {
        cin >> ntracks;
        for(int i = 0; i < ntracks; ++i) 
            cin >> duration[i];

        least_remaining = INF; onuse[20] = {false}; ans[20] = {false};
        solve(N, 0);

        for(int i = 0; i < ntracks; ++i) if (ans[i]) cout << duration[i] << " ";
        cout << "sum:" << N - least_remaining << endl;
    }
    return 0;
}
