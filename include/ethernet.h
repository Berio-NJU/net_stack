#include "syshead.h"
#include "skbuff.h"
#define ETH_HDR_LEN sizeof(struct eth_hdr)

struct eth_hdr
{
    uint8_t  dmac[6];   // 目的地址
    uint8_t  smac[6];   // 源地址
    uint16_t ethertype; // 有效负载的长度(隐式类型标定,字段值大于1536则包含有效负载的类型信息，小于则包含有效负载的长度)
    uint8_t  payload[];
};

// 以太网帧是放在skb结构中的,
static inline struct eth_hdr *eth_hdr(struct sk_buff *skb)
{
    struct eth_hdr *hdr = (struct eth_hdr *)skb_head(skb);
    // 把网络字节顺序转换成主机字节顺序
    hdr->ethertype = ntohs(hdr->ethertype);

    return hdr;
}
