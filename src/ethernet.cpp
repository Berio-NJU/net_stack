#include "syshead.h"

// TODO 把MAC地址和data封装成MAC数据帧
struct eth_hdr *eth_send(uint8_t smac[6],uint8_t dmac[6],uint8_t *data){

}

// TODO 字节流转换成MAC数据帧
struct eth_hdr *eth_rcv(uint8_t *data){
    struct eth_hdr *hdr = (struct eth_hdr *)data;
    return hdr;
}