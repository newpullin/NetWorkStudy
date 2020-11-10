//
// Created by pulli on 2020-11-10.
// from https://ehpub.co.kr/ipv4-protocol-stack-parser-c-language/
//

#ifndef PACKETMANAGER_PCAPREADER_H
#define PACKETMANAGER_PCAPREADER_H
#include <stdio.h>
#include "../BIT/DefType.h"
#include "../BIT/BitFunction.h"

typedef struct _PFHeader PFHeader;
struct _PFHeader //패킷 파일 헤더
{
    uint magic;//0xA1B2C3D4
    ushort major;
    ushort minor;
    uint gmt_to_local;
    uint timestamp;
    uint max_caplen;
    uint linktype;
};

typedef struct _PACKETHEADER PackHeader;
struct _PACKETHEADER //패킷 헤더
{
    uint captime;//second
    uint caputime;//u second
    uint caplen;
    uint packlen;
};

#define PF_MAGIC 0xA1B2C3D4
#define LT_ETHER   0x01
void ParseEthers(FILE *fp);
int ParsePCapFile(FILE *fp, PFHeader *pfh);

#endif //PACKETMANAGER_PCAPREADER_H
