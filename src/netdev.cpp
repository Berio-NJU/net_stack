#include "syshead.h"
#include "ethernet.h"

// 调用虚拟网卡接口发送以太网帧
int tap_send(struct eth_hdr *eth,int len){
    int fp = open("/dev/tap",O_WRONLY);
    return write(fp,eth,len);
}

// 从虚拟网卡接口获取以太网帧数据
struct eth_hdr *tap_rcv(){
    int fp = open("/dev/tap",O_RDONLY);
    int len = 1600;
    struct eth_hdr *eth = (struct eth_hdr *)malloc(sizeof(struct eth_hdr)+len);
    read(fd,eth,sizeof(struct eth_hdr)+len);
    return eth;
}