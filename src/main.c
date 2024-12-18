#include <stdio.h>

#include "message.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    error_message("Hello!");
  }
  /* printf("Complete!\n"); */
  return 0;
}
