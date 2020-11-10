//
// Created by pulli on 2020-11-11.
//


#include "UDP.h"

void ParseUDP(uchar *base, uint len)
{
    UDPHeader *udph = (UDPHeader *)base;
    printf("============= UDP header ==============\n");
    printf(">    Source   Port : %d\n", nthos(udph->Sport));
    printf("> Destination Port : %d\n", nthos(udph->Dport));
    ushort data_length = nthos(udph->length);
    printf("> total length : %d bytes\n", data_length);
    printf("> CheckSum : 0x%04x\n", nthos(udph->checksum));

    uchar *next = base + 8;
    printf("=============== DATA ================\n");
    uchar buf[8] = {0,};
    uchar index = 0;

    for(ushort i = 0; i < data_length-8; i++){
        buf[index] = *(next + i);
        if(++index == 8){
            index = 0;
            for(uchar k = 0; k < 8; k++) {
                printf("0x%02x ", buf[k]);
            }
            printf("\n");
        }
        if(i == 79) {
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