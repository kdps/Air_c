#include <stdio.h>
#include "file_system.h"

int main()
{
  struct file_contents *filecontents; 
  filecontents = get_file_contents("test.txt");

  printf("%s", filecontents->data);
  printf("\n");
  printf("%d", filecontents->size);
  printf("\n");

  file_put_contents("test2.txt", "Hello World");

  filelist *file_list = get_filelist();

  for (int i=0;i<file_list->len;i++) {
    printf(file_list->items[i]);
    printf("\n");
  }

  return 0;
}