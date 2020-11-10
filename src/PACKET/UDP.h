//
// Created by pulli on 2020-11-11.
//

#ifndef PACKETMANAGER_UDP_H
#define PACKETMANAGER_UDP_H

#include "../PCAP/pcapReader.h"


typedef struct _UDPHeader
{
    ushort Sport;
    ushort Dport;
    ushort length;
    ushort checksum;
}UDPHeader;

void ParseUDP(uchar *base, uint len);

#endif //PACKETMANAGER_UDP_H
