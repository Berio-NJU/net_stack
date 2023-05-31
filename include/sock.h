#include <stdint.h>
struct sock;

struct sock {
    int protocol;
    uint16_t sport;
    uint16_t dport;
    uint32_t saddr;
    uint32_t daddr;
};