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
#define UPD_SOURCE_PORT_LEN    2
#define UPD_DEST_PORT_LEN      2
#define UPD_LENGTH_LEN         2

// START INDEX of Field
#define IP_HEADER              14
#define IP_TOS                 (IP_HEADER + IP_HEADER_LEN)
#define IP_TL                  (IP_TOS + IP_TOS_LEN)
#define IP_IDENTIFICATION      (IP_TL + IP_TL_LEN)
#define IP_FRAGMENTATION       (IP_IDENTIFICATION + IP_IDE_LEN)
#define IP_TTL                 (IP_FRAGMENTATION + IP_FRAGMENTATION_LEN)
#define IP_PROTOCOL            (IP_TTL + IP_TTL_LEN)
#define IP_HEADER_CHECKSUM     (IP_PROTOCOL + IP_PROTOCOL_LEN)
#define IP_SOURCE_ADDR         (IP_HEADER_CHECKSUM + IP_HEADER_CHECKSUM_LEN)
#define IP_DEST_ADDR           (IP_SOURCE_ADDR + IP_SOURCE_ADDR_LEN)
#define UDP_SOURCE_PORT        (IP_DEST_ADDR + IP_DEST_ADDR_LEN)
#define UDP_DEST_PORT          (UDP_SOURCE_PORT + UDP_SOURCE_PORT_LEN)
#define UDP_LENGTH             (UDP_DEST_PORT + UDP_DEST_PORT_LEN)

// FILED MASK
#define IP_HEADER_MASK 0x0F
#define IP_FRAGMENTATION_MASK 0x1f


#define VAL_LEN 10
#define UDP_LEN 3
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
enum UDPValues {
    source_port,
    dest_port,
    udp_length
};

const char* value_string[] = {"Version", "IHL", "TOS", "TL", "Identification", "Flag", "FragmentOffset", "TTL", "Porotocol", "HeaderChecksum"};
const char* udp_value_string[] = {"source_port", "dest_port", "udp_length"};

const unsigned char netstr[] =
        {0x01, 0x00, 0x5e, 0x7f, 0xff, 0xfa, 0xb0, 0x25, \
0xaa, 0x3a, 0xf5, 0xdb, 0x08, 0x00, 0x45, 0x00, \
0x02, 0xac, 0x43, 0x43, 0x00, 0x00, 0x01, 0x11, \
0x00, 0x00, 0xc0, 0xa8, 0x00, 0xa5, 0xef, 0xff, \
0xff, 0xfa, 0xf6, 0x56, 0x0e, 0x76, 0x02, 0x98, \
0xe2, 0x9b, 0x3c, 0x3f, 0x78, 0x6d, 0x6c, 0x20, \
0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x3d, \
0x22, 0x31, 0x2e, 0x30, 0x22, 0x20, 0x65, 0x6e, \
0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x3d, 0x22, \
0x75, 0x74, 0x66, 0x2d, 0x38, 0x22, 0x3f, 0x3e, \
0x3c, 0x73, 0x6f, 0x61, 0x70, 0x3a, 0x45, 0x6e, \
0x76, 0x65, 0x6c, 0x6f, 0x70, 0x65, 0x20, 0x78, \
0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x73, 0x6f, 0x61, \
0x70, 0x3d, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, \
0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x77, 0x33, \
0x2e, 0x6f, 0x72, 0x67, 0x2f, 0x32, 0x30, 0x30, \
0x33, 0x2f, 0x30, 0x35, 0x2f, 0x73, 0x6f, 0x61, \
0x70, 0x2d, 0x65, 0x6e, 0x76, 0x65, 0x6c, 0x6f, \
0x70, 0x65, 0x22, 0x20, 0x78, 0x6d, 0x6c, 0x6e, \
0x73, 0x3a, 0x77, 0x73, 0x61, 0x3d, 0x22, 0x68, \
0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x73, 0x63, \
0x68, 0x65, 0x6d, 0x61, 0x73, 0x2e, 0x78, 0x6d, \
0x6c, 0x73, 0x6f, 0x61, 0x70, 0x2e, 0x6f, 0x72, \
0x67, 0x2f, 0x77, 0x73, 0x2f, 0x32, 0x30, 0x30, \
0x34, 0x2f, 0x30, 0x38, 0x2f, 0x61, 0x64, 0x64, \
0x72, 0x65, 0x73, 0x73, 0x69, 0x6e, 0x67, 0x22, \
0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x77, \
0x73, 0x64, 0x3d, 0x22, 0x68, 0x74, 0x74, 0x70, \
0x3a, 0x2f, 0x2f, 0x73, 0x63, 0x68, 0x65, 0x6d, \
0x61, 0x73, 0x2e, 0x78, 0x6d, 0x6c, 0x73, 0x6f, \
0x61, 0x70, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0x77, \
0x73, 0x2f, 0x32, 0x30, 0x30, 0x35, 0x2f, 0x30, \
0x34, 0x2f, 0x64, 0x69, 0x73, 0x63, 0x6f, 0x76, \
0x65, 0x72, 0x79, 0x22, 0x3e, 0x3c, 0x73, 0x6f, \
0x61, 0x70, 0x3a, 0x48, 0x65, 0x61, 0x64, 0x65, \
0x72, 0x3e, 0x3c, 0x77, 0x73, 0x61, 0x3a, 0x54, \
0x6f, 0x3e, 0x75, 0x72, 0x6e, 0x3a, 0x73, 0x63, \
0x68, 0x65, 0x6d, 0x61, 0x73, 0x2d, 0x78, 0x6d, \
0x6c, 0x73, 0x6f, 0x61, 0x70, 0x2d, 0x6f, 0x72, \
0x67, 0x3a, 0x77, 0x73, 0x3a, 0x32, 0x30, 0x30, \
0x35, 0x3a, 0x30, 0x34, 0x3a, 0x64, 0x69, 0x73, \
0x63, 0x6f, 0x76, 0x65, 0x72, 0x79, 0x3c, 0x2f, \
0x77, 0x73, 0x61, 0x3a, 0x54, 0x6f, 0x3e, 0x3c, \
0x77, 0x73, 0x61, 0x3a, 0x41, 0x63, 0x74, 0x69, \
0x6f, 0x6e, 0x3e, 0x68, 0x74, 0x74, 0x70, 0x3a, \
0x2f, 0x2f, 0x73, 0x63, 0x68, 0x65, 0x6d, 0x61, \
0x73, 0x2e, 0x78, 0x6d, 0x6c, 0x73, 0x6f, 0x61, \
0x70, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0x77, 0x73, \
0x2f, 0x32, 0x30, 0x30, 0x35, 0x2f, 0x30, 0x34, \
0x2f, 0x64, 0x69, 0x73, 0x63, 0x6f, 0x76, 0x65, \
0x72, 0x79, 0x2f, 0x52, 0x65, 0x73, 0x6f, 0x6c, \
0x76, 0x65, 0x3c, 0x2f, 0x77, 0x73, 0x61, 0x3a, \
0x41, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x3c, \
0x77, 0x73, 0x61, 0x3a, 0x4d, 0x65, 0x73, 0x73, \
0x61, 0x67, 0x65, 0x49, 0x44, 0x3e, 0x75, 0x72, \
0x6e, 0x3a, 0x75, 0x75, 0x69, 0x64, 0x3a, 0x38, \
0x62, 0x63, 0x31, 0x33, 0x66, 0x35, 0x63, 0x2d, \
0x61, 0x38, 0x39, 0x39, 0x2d, 0x34, 0x63, 0x62, \
0x36, 0x2d, 0x61, 0x36, 0x62, 0x37, 0x2d, 0x64, \
0x63, 0x32, 0x37, 0x61, 0x64, 0x33, 0x33, 0x32, \
0x37, 0x36, 0x32, 0x3c, 0x2f, 0x77, 0x73, 0x61, \
0x3a, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, \
0x49, 0x44, 0x3e, 0x3c, 0x2f, 0x73, 0x6f, 0x61, \
0x70, 0x3a, 0x48, 0x65, 0x61, 0x64, 0x65, 0x72, \
0x3e, 0x3c, 0x73, 0x6f, 0x61, 0x70, 0x3a, 0x42, \
0x6f, 0x64, 0x79, 0x3e, 0x3c, 0x77, 0x73, 0x64, \
0x3a, 0x52, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, \
0x3e, 0x3c, 0x77, 0x73, 0x61, 0x3a, 0x45, 0x6e, \
0x64, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x52, 0x65, \
0x66, 0x65, 0x72, 0x65, 0x6e, 0x63, 0x65, 0x3e, \
0x3c, 0x77, 0x73, 0x61, 0x3a, 0x41, 0x64, 0x64, \
0x72, 0x65, 0x73, 0x73, 0x3e, 0x75, 0x72, 0x6e, \
0x3a, 0x75, 0x75, 0x69, 0x64, 0x3a, 0x31, 0x63, \
0x38, 0x35, 0x32, 0x61, 0x34, 0x64, 0x2d, 0x62, \
0x38, 0x30, 0x30, 0x2d, 0x31, 0x66, 0x30, 0x38, \
0x2d, 0x61, 0x62, 0x63, 0x64, 0x2d, 0x66, 0x34, \
0x33, 0x30, 0x62, 0x39, 0x34, 0x35, 0x31, 0x32, \
0x65, 0x30, 0x3c, 0x2f, 0x77, 0x73, 0x61, 0x3a, \
0x41, 0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x3e, \
0x3c, 0x2f, 0x77, 0x73, 0x61, 0x3a, 0x45, 0x6e, \
0x64, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x52, 0x65, \
0x66, 0x65, 0x72, 0x65, 0x6e, 0x63, 0x65, 0x3e, \
0x3c, 0x2f, 0x77, 0x73, 0x64, 0x3a, 0x52, 0x65, \
0x73, 0x6f, 0x6c, 0x76, 0x65, 0x3e, 0x3c, 0x2f, \
0x73, 0x6f, 0x61, 0x70, 0x3a, 0x42, 0x6f, 0x64, \
0x79, 0x3e, 0x3c, 0x2f, 0x73, 0x6f, 0x61, 0x70, \
0x3a, 0x45, 0x6e, 0x76, 0x65, 0x6c, 0x6f, 0x70, 0x65, 0x3e};


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
    result[TL] = netstr[IP_TL] * 256 + netstr[IP_TL+1];
    result[Identification] = netstr[IP_IDENTIFICATION ] * 256 + netstr[IP_IDENTIFICATION +1];
    result[Flag] = netstr[IP_FRAGMENTATION] >> 5 ;
    result[FragmentOffset] = (netstr[IP_FRAGMENTATION] & IP_FRAGMENTATION_MASK)*(256) + netstr[IP_FRAGMENTATION+1];
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

void parsingUDPPacket(int* result, const unsigned char* netstr) {
    result[source_port] = netstr[]
}
int main(void){
    int result[VAL_LEN];
    int udp_result[UDP_LEN];
    // parsing
    parsingIPPacket(result, netstr);
    // print result
    printIPPacket(result, netstr);
    return 0;
}