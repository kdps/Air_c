#ifndef _NETWORK_WINDOWS_H_
#define _NETWORK_WINDOWS_H_

extern int *is_socket_available(int family);

extern int *is_pf_socket_available();

extern int *is_af_socket_available();

extern int *http_send_raw(int family, char *name, int port, char *data);

extern char *http_send_raw_and_receive(int family, char *name, int port, char *data);

#endif