#include "tcpheader.h"
#include <stdio.h>


int getSourcePort(const unsigned char *tcp_hdr)
{
    // ((int) tcp_hdr[0] << 4) | tcp_hdr[1])
    return(((0x00 | tcp_hdr[0]) << 8 ) | tcp_hdr[1]);
}

int getDestinationPort(const unsigned char *tcp_hdr)
{
    return((0x00 | tcp_hdr[2] << 8) | tcp_hdr[3]);
}

void setSourcePort(unsigned char *tcp_hdr, int port)
{
    tcp_hdr[0] = port >> 8;
    tcp_hdr[1] = (port << 8) >> 8;
}

void setDestinationPort(unsigned char *tcp_hdr, int port)
{
    tcp_hdr[2] = port >> 8;
    tcp_hdr[3] = (port << 8) >> 8;
}

int getAckFlag(const unsigned char *tcp_hdr)
{
    return((tcp_hdr[13] & 0x10)/16);
}

void setAckFlag(unsigned char *tcp_hdr, int flag)
{
    if (flag == 1) {
        tcp_hdr[13] = tcp_hdr[13] | 0x10;
    } else {
        tcp_hdr[13] = tcp_hdr[13] & 0xef;
    }
}

int getDataOffset(const unsigned char *tcp_hdr)
{
    return(tcp_hdr[12] >> 4);
}

void setDataOffset(unsigned char *tcp_hdr, int offset)
{
    unsigned char x = offset;
    x = (0x00 | (x * 16));
    unsigned char y = tcp_hdr[12] << 4;
    y = y >> 4;
    tcp_hdr[12] = x | y;
}
