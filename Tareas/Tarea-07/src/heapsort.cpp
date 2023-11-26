#ifndef HEAPSORT
#define HEAPSORT
#include <vector>
using namespace std;

size_t parent(size_t i) { return i / 2; }
// size_t left(size_t i) { return 2 * i; }
// size_t right(size_t i) { return 2 * i + 1; }

// Consideramos todo el vector
void min_heapify(vector<int> &A, int n, int i) {
  int shortest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && A[left] < A[shortest])
    shortest = left;
  if (right < n && A[right] < A[shortest])
    shortest = right;

  if (shortest != i) {
    swap(A[i], A[shortest]);
    min_heapify(A, n, shortest);
  }
}

void build_min_heap(vector<int>& A, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    min_heapify(A, n, i);
  }
}

void heap_short_min(vector<int> &A, int n) {
  build_min_heap(A, n);

  for (int i = n - 1; i >= 0; i--) {
    swap(A[0], A[i]);
    min_heapify(A, i, 0);
  }
}

// Codigo para el problema 2
void max_heapify(vector<int> &A, int n, int i) {
  int largest = i;
  do {
    i = largest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
      largest = left;
    if (right < n && A[right] > A[largest])
      largest = right;
    swap(A[i], A[largest]);
  } while (largest != i);
}

#endif