#include "knn.h"

int dist(int n, int v1[n], int v2[n]) {
  assert(n > 0);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs(v1[i] - v2[i]);
  }
  return sum;
}

int mode(int n, int a[n]) {
  assert(n > 0);
  int max_count = 1;
  int max_elem = a[0];
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == a[i]) {
        count++;
      }
    }
    if (count > max_count) {
      max_count = count;
      max_elem = a[i];
    }
  }
  return max_elem;
}

void swap(void * restrict a, void * restrict b, size_t size) {
  assert(a);
  assert(b);
  char *tmp = malloc(size);
  assert(tmp);
  memcpy(tmp, a, size);
  memcpy(a, b, size);
  memcpy(b, tmp, size);
  free(tmp);
}

void sortk(int n, int k, int dists[n], int labels[n]) {
  assert(k > 0);
  assert(n > 0);
  assert(k < n);
  for (int i = 0; i < k; i++) {
    // find ith smallest element
    int index = i;
    for (int j = i+1; j < n; j++) {
      if (dists[j] < dists[index]) {
        index = j;
      }
    }
    // place smallest element in index'th position
    swap(&dists[i], &dists[index], sizeof(int)); 
    swap(&labels[i], &labels[index], sizeof(int));
  }
}

int classify(int n, int k, int x[ISIZE], int data[n][ISIZE], int labels[n]) {
  assert(k > 0);
  assert(n > 0);
  assert(k < n);
  int d[n];
  int labels_copy[n];
  memcpy(labels_copy, labels, sizeof(int) * n);
  // calculate all the distances
  for (int i = 0; i < n; i++) {
    d[i] = dist(ISIZE, x, data[i]); 
  }
  // get the k smallest
  sortk(n, k, d, labels_copy);
  return mode(k, labels_copy);
}


