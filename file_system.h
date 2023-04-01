#ifndef _FILE_SYSTEM_H_
#define _FILE_SYSTEM_H_

struct file_contents {
    int size;
    void *data;
};

extern int *is_regular_file(char *path);

extern int *is_fifo(char *path);

extern int *is_directory(char *path);

extern int *is_block_device(char *path);

extern struct file_contents *get_file_contents(char *path);

extern int *file_put_contents(char *path, char *text);

#endif