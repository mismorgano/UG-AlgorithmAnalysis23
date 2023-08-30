// Problem: Flechas y Zombies
// Contest: HackerRank - AAMD23-tarea1
// URL:
// https://www.hackerrank.com/contests/aamd23-tarea1/challenges/flechas-y-zombies
// Memory Limit: 512 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, val;
    char in;
    // greater<int> para que el menor aparezca en el top
    priority_queue<int, vector<int>, greater<int>> flechas;

    cin >> N;
    while (N--) {
        cin >> in;
        if (in == 'Z') { // usamos flecha
            if (flechas.empty())
                cout << -1 << '\n'; // no hay flechas
            else {
                auto top = flechas.top();
                cout << top << '\n'; // la flecha mas pequña
                flechas.pop();       // queda inservible
            }
        } else { // encontramos flecha
            cin >> val;
            flechas.push(val);
        }
    }
    return 0;
}