#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#define ISIZE 784

// calculates L1 distance of two vectors of length n
int dist(int n, int v1[n], int v2[n]);

// computes the mode in the array
int mode(int n, int a[n]);

// generic swap function
void swap(void *a, void *b, size_t size);

// sorts smallest k elements in dists 
// rearranges elements in labels accordingly
void sortk(int n, int k, int dists[n], int labels[n]);

// classifies the image
// n: number of traning elements to be considered
// k: k nearest neighbors
// x: image to be classified
// data: training data
// labels: training labels
int classify(int n, int k, int x[ISIZE], int data[n][ISIZE], int labels[n]);
