#include <stdio.h>
#include "file_system.h"

int main()
{
  struct file_contents *filecontents; 
  filecontents = get_file_contents("test.txt");

  printf("%s", filecontents->data);
  printf("%d", filecontents->size);

  file_put_contents("test2.txt", "Hello World");

  return 0;
}