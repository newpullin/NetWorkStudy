//
// Created by pulli on 2020-11-11.
//

#include "TCP.h"

void ParseTCP(uchar *base, uint len)
{
    TCPHeader *tcph = (TCPHeader *)base;
    printf("============= TCP header ==============\n");
    printf(">    Source   Port : %u\n", nthos(tcph->Sport));
    printf("> Destination Port : %u\n", nthos(tcph->Dport));
    printf("> Seq. Number : %u \n", nthos_i(tcph->SeqNo));
    printf("> Ack. Number : %u \n", nthos_i(tcph->AckNo));
    uint header_length = ((tcph->headerLength)>>4)*4;
    printf("header Length : %d\n", header_length);
    printf("> Control Bits Status\n");
    if (tcph->syn) { printf("SYN ON\n"); }
    if (tcph->ack) { printf("ACK ON\n"); }
    if (tcph->fin) { printf("FIN ON\n"); }
    if (tcph->rst) { printf("RST ON\n"); }
    if (tcph->psh) { printf("PSH ON\n"); }
    if (tcph->urg) { printf("URG ON\n"); }
    printf("> Window : %d\n", nthos(tcph->Window));
    printf("> CheckSum : 0x%04x\n", nthos(tcph->Checksum));
    printf("> Urgent Pointer %d\n", tcph->UrgentPointer);

    printf("=============== DATA ================\n");
    uchar buf[8] = {0,};
    uchar index = 0;
    uchar *next = base + header_length;
    for(ushort i = 0; i < len - header_length; i++){
        buf[index] = *(next + i);
        if(++index == 8){
            index = 0;
            for(uchar k = 0; k < 8; k++) {
                printf("0x%02x ", buf[k]);
            }
            printf("\n");
        }
        if(i == 39) {
            break;
        }
    }
    if(index != 0){
        for(uchar k = 0; k < index; k++) {
            printf("0x%02x ", buf[k]);
        }
        printf("\n");
    }
    printf("========================================\n");
}
