// Problem: Sumas Parciales - Divide y Vencerás
// Contest: HackerRank - aamd23-tarea3
// URL:
// https://www.hackerrank.com/contests/aamd23-tarea3/challenges/sumas-parciales-divide-y-venceras
// Memory Limit: 512 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;

long long merge(vector<int> &v, int left, int middle, int right, long long t) {
    ordered_set or_set;
    long long sum{}, total{};
    for (int i = middle; i >= left; i--) {
        sum += v[i];
        or_set.insert(make_pair(sum, i));
    }
    sum = 0;
    for (int i = middle + 1; i <= right; i++) {
        sum += v[i];
        total += or_set.order_of_key(make_pair(t - sum, -1));
    }
    return total;
}

long long subarrays_sum_less_than(vector<int> &v, int left, int right,
                                  long long t) {
    if (left < right) {
        long long res{};
        int middle = (left + right) / 2;
        res += subarrays_sum_less_than(v, left, middle, t);
        res += subarrays_sum_less_than(v, middle + 1, right, t);
        res += merge(v, left, middle, right, t);
        return res;
    } else if (v[left] < t) {
        return 1;
    } else
        return 0;
}
int main() {
    int n;
    long long t;
    cin >> n >> t;
    vector<int> arr;
    arr.reserve(n);
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        arr.push_back(j);
    }
    cout << subarrays_sum_less_than(arr, 0, arr.size() - 1, t);
    //        cout << merge(arr, 0, 1, arr.size() - 1, t);

    return 0;
}