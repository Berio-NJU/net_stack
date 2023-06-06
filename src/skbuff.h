#include "syshead.h"
#include <pthread.h>
/*
* sk_buff是通用缓冲区,
* 每个发送或接收的数据包都使用这个数据结构进行处理。
*/

// 为所有网络数据的通用缓冲区结构
struct sk_buff {
    // struct list_head list;
    // struct rtentry *rt;
    // struct netdev *dev;
    int refcnt;
    uint16_t protocol; // 来自驱动程序的包协议
    uint32_t len;   // 缓冲区长度
    uint32_t dlen; 
    uint32_t seq;   // 第一个seq序号
    uint32_t end_seq; // 最后一个seq序号
    uint8_t *end;   // 指向缓冲区尾部
    uint8_t *head;   // 指向skb缓冲区头
    uint8_t *data;  // 指向数据头部的指针
    uint8_t *payload;   // 负载
};
// // sk_buff链表结构
// struct sk_buff_head {
//     struct list_head head;

//     uint32_t qlen;
// };

uint8_t *skb_head(struct sk_buff *skb); 

