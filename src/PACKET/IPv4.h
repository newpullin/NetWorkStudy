//
// Created by pulli on 2020-11-11.
// from https://ehpub.co.kr/ipv4-protocol-stack-parser-c-language/
//

#ifndef PACKETMANAGER_IPV4_H
#define PACKETMANAGER_IPV4_H

#include "../PCAP/pcapReader.h"

#define PRO_ICMPv4 0x01
#define PRO_IGMP    0x02
#define PRO_TCP     0x06
#define PRO_UDP     0x11
#define PRO_OSPF    0x59

typedef struct _IPv4Header IPv4Header;
struct _IPv4Header
{
    uchar hlen : 4;
    uchar version : 4;
    uchar tos;
    ushort tlen;
    ushort id;
    ushort fl_off;
#define DONT_FRAG(x) (x&0x40)
#define MORE_FRAG(x) (x&0x20)
#define FRAG_OFF(x) x&0xFF1F
    uchar ttl;
    uchar protocol;
    ushort checksum;
    uint srcaddr;
    uint dstaddr;
};

void ParseIPv4(uchar *base, uint len);

#endif //PACKETMANAGER_IPV4_H
