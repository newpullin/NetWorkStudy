//
// Created by pulli on 2020-11-11.
// from https://ehpub.co.kr/ipv4-protocol-stack-parser-c-language/
//

#include "IPv4.h"
#include "UDP.h"

void PrintIPv4(uint addr)
{
    uchar *up = (uchar *)&addr;
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("%d.", up[i]);
    }
    printf("%d", up[i]);

}
void ParseIPv4(uchar *base, uint len)
{
    IPv4Header *iph = (IPv4Header *)base;
    printf("============= IPv4 header ==============\n");
    printf("> version:%d\n", iph->version);
    printf("> hlen:%d bytes\n", iph->hlen * 4);
    printf("> total length :%d bytes\n", nthos(iph->tlen));
    printf("> id:%d\n", nthos(iph->id));

    if (DONT_FRAG(iph->fl_off))
    {
        printf("> Don't Fragment\n");
    }
    if (MORE_FRAG(iph->fl_off))
    {
        printf("> More Fragment\n");
    }
    printf("> offset:%d bytes\n", FRAG_OFF(iph->fl_off));
    printf("> Time To Live:%d\n", iph->ttl);
    printf("> Protocol :%d\n", iph->protocol);
    printf("> ICMP:%d IGMP:%d TCP:%d UDP:%d OSPF:%d\n",
           PRO_ICMPv4, PRO_IGMP, PRO_TCP, PRO_UDP, PRO_OSPF);
    printf("> CheckSum : 0x%04x\n", nthos(iph->checksum));
    printf("> src : ");
    PrintIPv4(iph->srcaddr);
    printf("\n> dst : ");
    PrintIPv4(iph->dstaddr);
    printf("\n");
    uchar *next = base + (iph->hlen * 4);
    len = len - (iph->hlen * 4);
    printf("========================================\n");
    switch (iph->protocol)
    {
        case PRO_ICMPv4: printf("> to be defined\n"); break;
        case PRO_TCP: printf("> to be defined\n");  break;
        case PRO_UDP: ParseUDP(next, len); break;
        default: printf("> Not supported\n"); break;
    }
}