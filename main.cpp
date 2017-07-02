#include <iostream>
#include <stdio.h>
#include "InputFile.hh"
#include "h264bytestreamparser.h"
#include "h264nalpacket.h"
#include "h264rtppacketizer.h"
#include "udpdatagram.h"
#include "h264stream.h"

using namespace std;

int main()
{
    H264ByteStreamParser parser("C:/Users/Meisma/Desktop/my program/Projects/QStreamer/streaming source/FVDO_Freeway_4cif.264");
    WSADATA     wsaData;

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
    {
        printf("WSAStartup failed with this error %1d\n", WSAGetLastError());
        return 1;
    }

      H264RtpPacketizer p;
      p.set_clock_frequency(9000);
      p.set_destination_addr("239.0.0.1", 4000);
      p.start(parser);
//    H264Stream h264Stream("C:/Users/Meisma/Desktop/my program/Projects/QStreamer/h264_to_rtp-master/FVDO_Freeway_qcif.264");
//    h264Stream.setDestinationAddress("239.0.0.1", 4000);
//    h264Stream.setClockFrequency(9000);
//    h264Stream.sessionDescription();
//    h264Stream.stream();

    if(WSACleanup() != 0)
        printf("Client: WSACleanup() failed!...\n");

    return 0;
}
