#include "my-lib.h"

///*
// * my-lib.c
// *
// *  Created on: Nov 16, 2010
// *      Author: user
// */
//
//void statistics(){
//	printf("Network statistics\n");
//
//	printf("My stats: rx:%u tx:%u forwarded:%u\n", total_received_packets, total_sent_packets, total_forwarded_packets);
//
//	printf("IP stats: rx:%d tx:%d dropped:%d\n",uip_stat.ip.recv,uip_stat.ip.sent,uip_stat.ip.drop);
////
////	printf("IP err: vhl:%d hblen:%d lblen:%d frag:%d chk:%d proto:%d\n",uip_stat.ip.vhlerr,uip_stat.ip.hblenerr,uip_stat.ip.lblenerr,uip_stat.ip.fragerr,uip_stat.ip.chkerr,uip_stat.ip.protoerr);
////
////	printf("TCP stats: rx:%d tx:%d dropped:%d\n",uip_stat.tcp.recv,uip_stat.tcp.sent,uip_stat.tcp.drop);
////
////	printf("TCP err: chk:%d ack:%d rst:%d rexmit:%d syndrop:%d synrst:%d\n",	uip_stat.tcp.chkerr,uip_stat.tcp.ackerr,uip_stat.tcp.rst,uip_stat.tcp.rexmit,uip_stat.tcp.syndrop,uip_stat.tcp.synrst);
////
////	printf("UDP rx:%d tx:%d dropped:%d chkerr:%d\n",uip_stat.udp.recv,uip_stat.udp.sent,uip_stat.udp.drop,uip_stat.udp.chkerr);
////
////	printf("ICMP rx:%d tx:%d dropped:%d typeerr:%d\n",uip_stat.icmp.recv,uip_stat.icmp.sent,uip_stat.icmp.drop,uip_stat.icmp.typeerr);
//
//}
//
//void init_statistics(){
//
//	total_sent_packets = 0;
//	total_received_packets = 0;
//	total_forwarded_packets = 0;
//}
