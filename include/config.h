#ifndef __MIO_CONFIG_H__
#define __MIO_CONFIG_H__

/* get config */
extern int read_config(char *filename, char *key, char *value, int *value_len);

/* write or update config */
extern int write_config(char *filename, char *key, char *value, int *value_len);

#endif /* __MIO_CONFIG_H__ */
