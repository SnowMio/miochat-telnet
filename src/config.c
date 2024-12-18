#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#define MAX_LINE_LENGTH 256

int read_config(char *filename, char *key, char *value, int *value_len) {
  /* return value */
  int ret = 0;

  /* file pointer */
  FILE *fp = NULL;

  /* temp pointer*/
  char *p = NULL;

  /* Value start pointer*/
  char *start = NULL;

  /* Value end pointer */
  char *end = NULL;

  /* line buffer */
  char line_buffer[MAX_LINE_LENGTH];

  /* open config file read only */
  fp = fopen(filename, "r");

  /* if file open failed,
   * it means that this file does not exist
   * and exit it.
   */
  if (fp == NULL) {
    ret = -1;
    return ret;
  }

  while (!feof(fp)) {
    /* clear line_buffer */
    memset(line_buffer, 0, sizeof(line_buffer));

    /* get a line of data */
    fgets(line_buffer, MAX_LINE_LENGTH, fp);

    /* find character '=' */
    p = strchr(line_buffer, '=');

    /* if cannot find '='
     * exit, execute next circulate
     */
    if (p == NULL) {
      continue;
    }
  }
}
