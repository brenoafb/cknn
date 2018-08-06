#include "io.h"

#define N 500 // number of images to be read

int main(int argc, char *argv[]) {
  char *filename;
  if (argc < 2) {
    // no filename provided
    return 0;
  } else {
    filename = argv[1];
  }

  int data[N][ISIZE];
  int labels[N];

  if (!read_data(filename, N, labels, data)) {
    printf("Error reading data from \'%s\'.", filename);
    return 1;
  }

  return 0;
}

