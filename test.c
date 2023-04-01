#include <stdio.h>
#include "file_system.h"
#include "network_windows.h"
#include <winsock2.h>

int main()
{
  struct file_contents *filecontents; 
  filecontents = get_file_contents("test.txt");

  printf("%s", filecontents->data);
  printf("\n");
  printf("%d", filecontents->size);
  printf("\n");

  file_put_contents("test2.txt", "Hello World");

  filelist *file_list = get_filelist("./");

  for (int i=0;i<file_list->len;i++) {
    printf(file_list->items[i]);
    printf("\n");
  }

  char *http_response;

  http_response = http_send_raw_and_receive(PF_INET, "www.google.co.kr", 80, "GET / HTTP/1.1\r\nHost: www.google.co.kr\r\n\r\n");

  return 0;
}