/*
 * types.h
 *
 *  Created on: Nov 15, 2010
 *      Author: user
 */
#include "contiki.h"
#include "contiki-lib.h"
#include "contiki-net.h"
#include "dev/button-sensor.h"

#ifndef TYPES_H_
#define TYPES_H_

#ifdef MY_DEBUG
	#define PRINTF(...) printf(__VA_ARGS__)
#else
	#define PRINTF(...)
#endif /* MY_DEBUG */

#define DATA_BUFFER_LENGTH 60 /* Maximum is 75 */
#define STRING_BUFFER_LENGTH 1040

#define MIN(x,y) ((x)<(y) ? (x):(y))
#define MAX(x,y) ((x)>(y) ? (x):(y))
#define CEIL(x) ( ((x) <= (u8_t)(x)) ? (u8_t)(x) : ((u8_t)(x))+1 )

#define UDP_HDR ((struct uip_udpip_hdr *)&uip_buf[UIP_LLH_LEN])

#define U8_ARRAY_TO_U16(u8, u16) \
		(u16) = (u8)[0]; \
		(u16) <<= 8; \
		(u16) |= (u8)[1];


#define U16_TO_U8_ARRAY(u16, u8) \
		(u8)[1] = (u8_t)(u16); \
		(u8)[0] = (u8_t)((u16) >> 8);



enum{
	PACK,
	DATA
};

typedef struct message_pack_t{
	u8_t type;
	u8_t content_id;
	u8_t fragment_nr;
}message_pack_t;

typedef struct message_content_t{
	u8_t type;
	u8_t content_id;
	u8_t total_fragments;
	u8_t fragment_nr;
	u8_t content[DATA_BUFFER_LENGTH + 1];
}message_content_t;

//struct uip_stats uip_stat;
//u16_t total_sent_packets;
//u16_t total_received_packets;
//u16_t total_forwarded_packets;
//
//void statistics();
//void init_statistics();

#endif /* TYPES_H_ */
