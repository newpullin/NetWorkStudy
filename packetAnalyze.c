#include <stdio.h>

// Length of Field
#define IP_HEADER_LEN          1
#define IP_TOS_LEN             1
#define IP_TL_LEN              2
#define IP_IDE_LEN             2
#define IP_FRAGMENTATION_LEN   2
#define IP_TTL_LEN             1
#define IP_PROTOCOL_LEN        1
#define IP_HEADER_CHECKSUM_LEN 2
#define IP_SOURCE_ADDR_LEN     4
#define IP_DEST_ADDR_LEN       4

// INDEX of Field
#define IP_HEADER              0
#define IP_TOS                 (IP_HEADER + IP_HEADER_LEN)
#define IP_TL                  (IP_TOS + IP_TOS_LEN)
#define IP_IDENTIFICATION      (IP_TL + IP_TL_LEN)
#define IP_FRAGMENTATION       (IP_IDENTIFICATION + IP_IDE_LEN)
#define IP_TTL                 (IP_FRAGMENTATION + IP_FRAGMENTATION_LEN)
#define IP_PROTOCOL            (IP_TTL + IP_TTL_LEN)
#define IP_HEADER_CHECKSUM     (IP_PROTOCOL + IP_PROTOCOL_LEN)
#define IP_SOURCE_ADDR         (IP_HEADER_CHECKSUM + IP_HEADER_CHECKSUM_LEN)
#define IP_DEST_ADDR           (IP_SOURCE_ADDR + IP_SOURCE_ADDR_LEN)

// FILED MASK
#define IP_HEADER_MASK 0x0F
#define IP_FRAGMENTATION_MASK 0x1f


#define VAL_LEN 10
enum Values {
    Version = 0,
    IHL,
    TOS,
    TL,
    Identification,
    Flag,
    FragmentOffset,
    TTL,
    Porotocol,
    HeaderChecksum,
};
const char* value_string[] = {"Version", "IHL", "TOS", "TL", "Identification", "Flag", "FragmentOffset", "TTL", "Porotocol", "HeaderChecksum"};

const unsigned char netstr[] = {0x45, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x40, 0x00, 0x35, 0x11, 0xbf, 0x3a, 0xac, 0xd9, 0x18, 0x42, 0x00, 0x10, 0xc0, 0xa8, 0x00, 0xa5};


void printIP(const unsigned char* arr, int start){
    for(int i = 0; i < 3; i ++) {
        printf("%d.", *(arr+start+i));
    }
    printf("%d\n", *(arr+start+3));
}

void parsingIPPacket(int* result, const unsigned char* netstr) {
    result[Version] = netstr[IP_HEADER ]>>4; 
    result[IHL] = ((netstr[IP_HEADER ]) & IP_HEADER_MASK ) * 4;
    result[TOS] = netstr[IP_TOS] >> 4;
    result[TL] = netstr[IP_TL] * 0xf + netstr[IP_TL+1];
    result[Identification] = netstr[IP_IDENTIFICATION ] * 0xf + netstr[IP_IDENTIFICATION +1];
    result[Flag] = netstr[IP_FRAGMENTATION] >> 5 ;
    result[FragmentOffset] = (netstr[IP_FRAGMENTATION] & IP_FRAGMENTATION_MASK)*(0xff) + netstr[IP_FRAGMENTATION+1];
    result[TTL] = netstr[IP_TTL];
    result[Porotocol] = netstr[IP_PROTOCOL];
    result[HeaderChecksum] = netstr[IP_HEADER_CHECKSUM]; 
}

void printIPPacket(int* result, const unsigned char* netstr){

    printf("\n########## Packet #############\n\n");
    printf("\n------- Packet Info ---------\n\n");
    for(int i = 0; i < VAL_LEN; i++) {
        printf("* %s : %d \n", value_string[i], result[i]);
    }
    printf("\n---------- IP Info ----------\n\n");
    printf("* Source IP: ");
    printIP(netstr, IP_SOURCE_ADDR);
    printf("* Dest   IP: ");
    printIP(netstr, IP_DEST_ADDR);
    printf("\n-----------------------------\n\n");

    printf("\n\n###############################\n\n");

}

int main(void){
    int result[VAL_LEN];
    // parsing
    parsingIPPacket(result, netstr);
    // print result
    printIPPacket(result, netstr);
    return 0;
}