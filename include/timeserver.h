#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <stdint.h>

// Time difference between Unix epoch (1970) and RFC 868 epoch (1900)
#define UNIX_TO_RFC868_OFFSET 2208988800UL

// Function declarations
uint32_t get_rfc868_time(void);
int start_server(int port);

#endif // TIMESERVER_H