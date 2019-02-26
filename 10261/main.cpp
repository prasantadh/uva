#include <iostream>
#include <vector>
#include <cstring>

#define INF (1 << 30)

using namespace std;

typedef pair<int, int> ii;

int T, capacity; 
vector<int> cars;
int memo[200][10001];

void printSoln(int id, int lspace, int rspace) {
    if (id == cars.size()) return; // for 0 cars on the queue
    if (id == cars.size() - 1) {
        if (lspace >= cars[id]) cout << "port" << endl;
        else if (rspace >= cars[id]) cout << "starboard" << endl;
    } else {
        if (!memo[id][lspace]) return; // reached the end of loaded cars
        if (memo[id][lspace] - 1 == memo[id+1][lspace]) {
            cout << "starboard" << endl;
            printSoln(id + 1, lspace, rspace - cars[id]);
        } else if (memo[id][lspace] - 1 == memo[id+1][lspace-cars[id]]) {
            cout << "port" << endl;
            printSoln(id + 1, lspace - cars[id], rspace);
        }
    }
}

/**
 * @params:
 *  id: the current car under consideration
 *  lspace: space left on the left "port" side
 *  total : total space that has been occupied on both sides already
 * @returns:
 *  maximum numbers of cars that can be loaded considering
 *  car at position id and beyond
 */
int ncars(int id, int lspace, int total) {
    if (id == cars.size()) return 0;
    if (memo[id][lspace] != -1) return memo[id][lspace];

    int rspace = 2 * capacity - total - lspace;
    if (lspace >= cars[id] && rspace >= cars[id]) {
        int use_left = ncars(id + 1, lspace - cars[id], total + cars[id]);
        int use_right= ncars(id + 1, lspace, total + cars[id]);
        return memo[id][lspace] = 1 + max(use_left, use_right);
    } else if (lspace >= cars[id])
        return memo[id][lspace] = 1+ncars(id+1, lspace - cars[id], total + cars[id]);
    else if (rspace >= cars[id])
        return memo[id][lspace] = 1 + ncars(id+1, lspace, total + cars[id]);
    return memo[id][lspace] = 0;
}

int main(int argc, char **argv) {
    cin >> T;
    while(T--) {
        cin >> capacity; capacity *= 100;
        cars.clear(); 
        memset((void *) memo, -1, sizeof(memo));
        int car; cin >> car;
        while(car != 0) {
            if (cars.size() < 200)
                cars.push_back(car);
            cin >> car;
        }
        cout << ncars(0, capacity, 0) << endl;
        // print out the solution
        printSoln(0, capacity, capacity);
        if (T) cout << endl;
    }
    return 0;
}
