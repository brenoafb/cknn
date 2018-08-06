#include "io.h"

bool read_data(const char * filename, int n, int labels[n], int data[n][ISIZE]) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    // error opening file
    return false;
  }
 
  char *buffer = malloc(BUFSIZE);
  assert(buffer);
  for (int i = 0; i < n; i++) {
    size_t size = BUFSIZE;
    assert(getline(&buffer, &size, fp) > 0);
    char *str;
    int j;
    for (j = 0, str = buffer;; j++, str = NULL) {
      char *token = strtok(str, " "); 
      if (token == NULL) {
        break;
      }
      if (j == 0) {
        // first token is the label
        labels[i] = atoi(token);
      } else {
        // subsequent tokens are pixel values
        data[i][j-1] = atoi(token); 
      }
    } 
  }
  fclose(fp);
  free(buffer);
  return true;
}

