//
// Created by pulli on 2020-11-11.
//

#ifndef PACKET_TCP_H
#define PACKET_TCP_H

#include "../PCAP/pcapReader.h"


typedef struct _TCPHeader
{
    ushort Sport;
    ushort Dport;
    uint SeqNo;
    uint AckNo;
    uchar headerLength;
    uchar fin : 1;
    uchar syn : 1;
    uchar rst : 1;
    uchar psh : 1;
    uchar ack : 1;
    uchar urg : 1;
    uchar ecn : 1;
    uchar cwr : 1;


    ushort Window;
    ushort Checksum;
    ushort UrgentPointer;
}TCPHeader;

void ParseTCP(uchar *base, uint len);

#endif //PACKET_TCP_H
