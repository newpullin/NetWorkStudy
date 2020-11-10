//
// Created by pulli on 2020-11-10.
// https://ehpub.co.kr/ipv4-protocol-stack-parser-c-language/
//
#include <time.h>
#include "pcapReader.h"
#include "../PACKET/EHEther.h"
char buffer[0x100000];
void ViewPCapFile(PFHeader *pfh);
void ViewPacketHeaderInfo(PackHeader *ph,int pno);

void ParseEthers(FILE *fp)
{
    PackHeader ph = { 0 };
    int pno=0;
    while (fread(&ph,sizeof(PackHeader),1,fp)==1)
    {
        pno++;
        ViewPacketHeaderInfo(&ph, pno);
        fread(buffer, sizeof(uchar), ph.caplen, fp);
        ParseEther(buffer, ph.caplen);
    }
}

int ParsePCapFile(FILE *fp, PFHeader *pfh)
{
    fread(pfh, sizeof(PFHeader), 1, fp);
    if (pfh->magic != PF_MAGIC)
    {
        return 0;
    }
    ViewPCapFile(pfh);
    return 1;
}
void ViewPCapFile(PFHeader *pfh)
{
    printf("=========== PCAP File Header Info ============\n");
    printf("> Version : %d.%d\n", pfh->major, pfh->minor);
    printf("> Max Capture Length : %d bytes\n", pfh->max_caplen);
    printf("==============================================\n");
}
void ViewPacketHeaderInfo(PackHeader *ph, int pno)
{
    printf("============== Frame Info ===============\n");
    printf("Frame No : %05d\n", pno);

    time_t t = (time_t *) ph->captime;
    struct tm tm = *localtime(&t);

    printf("Time    : %d-%d-%d %d:%d:%d \n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Packet  :%6d bytes \nCapture :%6d bytes\n", ph->packlen, ph->caplen);
    printf("========================================\n");
}