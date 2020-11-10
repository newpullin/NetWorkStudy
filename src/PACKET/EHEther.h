//
// Created by pulli on 2020-11-10.
// from https://ehpub.co.kr/ipv4-protocol-stack-parser-c-language/
//

#ifndef PACKETMANAGER_EHETHER_H
#define PACKETMANAGER_EHETHER_H

#include "../PCAP/pcapReader.h"

#define L3_IPv4 0x0800
#define L3_ARP 0x0806

typedef struct  _EtherHeader EtherHeader;
struct  _EtherHeader
{
    uchar dst_mac[6];
    uchar src_mac[6];
    ushort l3type;
};

void ParseEther(uchar *buffer, uint len);
#endif //PACKETMANAGER_EHETHER_H
