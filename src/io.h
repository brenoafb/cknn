#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define ISIZE 784
#define BUFSIZE 4096

// reads mnist data in csv format
// stores the labels and the data in the respective arrays
bool read_data(const char * filename, int n, int labels[n], int data[n][ISIZE]);

