#include <stdint.h>
#include "ip.h"



struct udp_hdr;

struct udp_hdr{
    // 源端口
    uint16_t sport;
    // 目的端口
    uint16_t dport;
    // 长度
    uint16_t len;
    // 检验和
    uint16_t csum;
    // udp数据部分
    uint8_t data[];
};


static inline struct udp_hdr *udp_hdr(const struct sk_buff *skb){
    return (struct udp_hdr *)(skb->head + ETH_HDR_LEN + IP_HDR_LEN);
}