#include <stdio.h>
#include <stdlib.h>
#include "./PCAP/PcapReader.h"

int main()
{
    FILE *fp = 0;
    fopen_s(&fp, "../data/tcp.pcap", "rb");
    if (fp == 0)
    {
        perror("File open failed...");
        system("pause");
        return 0;
    }

    PFHeader pfh = { 0, };
    if (ParsePCapFile(fp, &pfh) == 0)
    {
        printf("This is not PCAP file...\n");
        fclose(fp);
        system("pause");
        return 0;
    }

    switch (pfh.linktype)
    {
        case LT_ETHER: ParseEthers(fp); break;
        default: printf("Not Supported format \n"); break;
    }
    fclose(fp);
    return 0;
}