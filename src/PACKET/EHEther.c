//
// Created by pulli on 2020-11-10.
// from https://ehpub.co.kr/ipv4-protocol-stack-parser-c-language/
//

#include "EHEther.h"
#include "IPv4.h"


void ViewEther(EtherHeader *eh);
void ParseEther(uchar *buffer, uint len)
{
    EtherHeader *eh = (EtherHeader *)buffer;
    uchar *next = buffer + sizeof(EtherHeader);
    len = len - sizeof(EtherHeader);

    ViewEther(eh);
    switch (nthos(eh->l3type))
    {
        case L3_IPv4 : ParseIPv4(next, len); break;
        case L3_ARP : printf("ARP: to be defined\n"); break;
        default: printf("Not support\n");	break;
    }
}

void ViewMac(const char *msg,uchar *base);
void ViewEther(EtherHeader *eh)
{
    printf("=========== Ethernet header ============\n");
    ViewMac("> dest : ", eh->dst_mac);
    ViewMac("> source : ", eh->src_mac);
    printf("> L3Type:%#x\n", nthos(eh->l3type));
    printf("> (IPv4:0x0800 ARP:0x0806)\n");
    printf("========================================\n");
}
void ViewMac(const char *msg, uchar *base)
{
    printf("%s", msg);
    printf("%02x", base[0]);
    for (int i = 1; i < 6; i++)
    {
        printf(":%02x", base[i]);
    }
    printf("\n");
}