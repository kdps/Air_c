#include <stdio.h>
#include "file_system.h"

int main()
{
  struct file_contents *filecontents; 
  filecontents = get_file_contents("test.txt");

  printf("%s", filecontents->data);
  printf("%d", filecontents->size);
  return 0;
}