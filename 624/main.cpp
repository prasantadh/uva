#include <iostream>

using namespace std;

int N, ntracks, duration[20], ans[20] = {-1};

int main(int argc, char **argv) {
    while(cin >> N) {
        cin >> ntracks;
        for(int i = 0; i < ntracks; ++i) 
            cin >> duration[i];

        int ansmask = 0, anstotal = 0;
        for(int mask = 1; mask < (1 << ntracks); ++mask) {
            int total = 0;
            for( int i = 0; i < ntracks; ++i ) {
                if ((1 << i) & mask) {
                    total += duration[i];
                    if (total > N) break;
                    if (total > anstotal) {
                        anstotal = total, ansmask = mask;
                    }
                }
            }
        }
        for(int i = 0; i < ntracks; i += 1) {
            if ((1 << i) & ansmask)
                cout << duration[i] << " ";
        }
        cout << "sum:" << anstotal << endl;
    }
    return 0;
}
