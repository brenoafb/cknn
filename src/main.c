#include <stdio.h>
#include "io.h"
#include "knn.h"

#define NTRAIN 2000
#define NTEST 500
#define K 5

int main(int argc, char *argv[]) {
  char *train_filename, *test_filename;
  if (argc < 3) {
    // insufficient arguments
    printf("Insufficent arguments.\nUsage: %s [training data] [test data]\n",
        argv[0]);
    return 1;
  } else {
    train_filename = argv[1];
    test_filename = argv[2];
  }
  
  int train_data[NTRAIN][ISIZE];
  int train_labels[NTRAIN];
  int test_data[NTEST][ISIZE];
  int test_labels[NTEST];
  
  if (!read_data(train_filename, NTRAIN, train_labels, train_data)) {
    printf("Error reading training data from %s.\n", train_filename);
    return 2;
  }

  if (!read_data(test_filename, NTEST, test_labels, test_data)) {
    printf("Error reading test data from %s.\n", test_filename);
    return 3;
  }

  // classify test data
  int correct = 0;
  for (int i = 0; i < NTEST; i++) {
    printf("Classifying: %d / %d\r", i+1, NTEST);
    int x = classify(NTRAIN, K, test_data[i], train_data, train_labels);
    if (x == test_labels[i]) {
      correct++;
    }
  }
  double pct = 100 * (double) correct / (double) NTEST;
  printf("\n%.2f%% correct.\n", pct);
  return 0;
}

