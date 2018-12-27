#include <iostream>

#define INF (1 << 29)

using namespace std;

int s, d, ans, acc[12]; // global states

/**
 * @params
 * month:   the current month under consideration
 * balance: the balance for current month (could be s or d)
 * @return: 
 *          the best possible surplus at the end of the year
 */
int solve(int month, int balance) {
    acc[month] = balance;
    int total = 0;
    if (month > 3) {
        for(int i = month - 4; i <= month; ++i)
            total += acc[i];
        if (total > 0) return -INF;
    }
    if (month == 11) {
        for(int i = 0; i < month - 4; ++i) total += acc[i];
        return total;
    }
    
    int withs = solve(month + 1, s);
    int withd = solve(month + 1, d);
    return max(withs, withd);
}

int main(int argc, char **argv) {
    while(cin >> s >> d) {
        d = -d, ans = -1;
        int with_s = solve(0, s);
        int with_d = solve(0, d);
        ans = max(with_s, with_d);
        if (ans < 0)
            cout << "Deficit" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
