#include "heapsort.cpp"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  // int n = size(arr);

  heap_short_min(arr, arr.size());
  for (size_t i = 0; i < arr.size(); i++) {
    cout << arr[i] << ' ';
  }
cout << '\n';
  vector<int> arr2 = {7, 10, 20, 3, 4, 49, 50};
  max_heapify(arr2, arr2.size(), 2);
  for (size_t i = 0; i < arr2.size(); i++) {
    cout << arr2[i] << ' ';
  }

  vector<int> arr3 = {9,8,7,6,5,4,3,2,1};
  build_min_heap(arr3, arr3.size());
  for (size_t i = 0; i < arr3.size(); i++) {
    cout << arr3[i] << ' ';
  }


  return 0;
}
