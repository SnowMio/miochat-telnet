#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "message.h"

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

    /* find key value */
    p = strstr(line_buffer, key);
    if (p == NULL) {
      continue;
    }

    p = p + strlen(key);

    p = strchr(p, '=');
    if (p == NULL) {
      continue;
    }

    p = p + 1;

    /* get value start location */
    for (;;) {
      if (*p == ' ') {
        p++;
      } else {
        start = p;
        if (*start == '\n') {
          goto End;
        }
        break;
      }
    }
    for (;;) {
      if ((*p == ' ' || *p == '\n')) {
        break;
      } else {
        p++;
      }
    }
    end = p;

    /* set value len */
    *value_len = end - start;

    /* set value data content */
    memcpy(value, start, end - start);
  }

End:
  if (fp == NULL) {
    fclose(fp);
  }
  return 0;
}

int write_config(char *filename, char *key, char *value, int value_len) {
  int ret = 0;

  int key_exist = 0;

  int file_length = 0;

  FILE *fp = NULL;

  char line_buffer[MAX_LINE_LENGTH];

  char *p = NULL;

  char file_buffer[1024 * 4] = {0};

  /* identify pointer is vaild */
  if (filename == NULL || key == NULL || value == NULL) {
    ret = -1;
    error_message("pointer is invaild");
    goto End;
  }

  fp = fopen(filename, "r+");

  if (fp == NULL) {
    ret = -2;
    error_message("fopen");
  }
}
