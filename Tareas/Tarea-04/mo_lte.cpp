// Problem: MO-LTE
// Contest: HackerRank - aamd23-tarea4
// URL: https://www.hackerrank.com/contests/aamd23-tarea4/challenges/aamd-tarea3
// Memory Limit: 512 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

struct FenwickTree {
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

FenwickTree ft(1000'000);
void remove(int idx) {
    ft.add(arr[idx], -1); // Nos interesa actualizar el valor de arr[idx]
}
void add(int idx) {
    ft.add(arr[idx], 1); // Nos interesa actualizar el valor de arr[idx]
}
int get_answer(int M) { return ft.sum(M); }

int block_size;
struct Query {
    int l, r, idx, M;
    bool operator<(Query &other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
vector<int> mo_s_algorithm(vector<Query> &queries) {
    vector<int> answers(queries.size());

    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer(q.M);
    }
    return answers;
}

int main() {
    int N, Q, l, r, el;
    cin >> N >> Q;
    block_size = sqrt(N);

    arr.reserve(N);
    vector<Query> queries;
    queries.reserve(Q);
    for (int i = 0; i < N; i++) {
        cin >> el;
        arr.push_back(el);
    }
    for (int i = 0; i < Q; i++) {
        cin >> l >> r >> el;
        queries.push_back(Query{l, r, i, el});
    }

    auto ans = mo_s_algorithm(queries);
    for (const auto &el : ans) {
        cout << el << '\n';
    }
    return 0;
}