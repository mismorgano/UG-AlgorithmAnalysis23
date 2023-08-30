// Problem: Alimentos
// Contest: HackerRank - AAMD23-tarea1
// URL:
// https://www.hackerrank.com/contests/aamd23-tarea1/challenges/heapactualizable
// Memory Limit: 512 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>

using namespace std;

template <typename T, typename M> struct Solution {
    void printMax() {
        if (max.empty())
            cout << -1;
        else {
            auto top = max.begin();
            cout << top->second << ' ' << top->first;
        }
        cout << '\n';
    };
    void insert(T food, M value) {
        auto old_rating = db.find(food);
        if (old_rating != db.end()) {
            int old_val = db[food];
            max.erase(make_pair(old_val, food));
        }
        db[food] = value;
        max.insert(make_pair(value, food));
    };
    void eraseMax() {
        if (!max.empty()) {
            auto top = max.begin();
            db.erase(top->second);
            max.erase(top);
        }
    };
    void erase(T food) {
        auto old_food = db.find(food);
        if (old_food != db.end()) {
            auto old_f = make_pair(old_food->second, old_food->first);
            max.erase(old_f);
            db.erase(food);
        }
    };

  private:
    map<T, M> db;
    set<pair<M, T>, greater<pair<M, T>>> max;
};

int main() {
    int N, value;
    string op, food;
    Solution<string, int> s;
    cin >> N;

    while (N--) {
        cin >> op;
        if (op == "P") {
            s.printMax();
        } else if (op == "IU") {
            cin >> food >> value;
            s.insert(food, value);
        } else if (op == "DL") {
            s.eraseMax();
        } else if (op == "D") {
            cin >> food;
            s.erase(food);
        }
    }

    return 0;
}