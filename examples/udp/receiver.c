#include "contiki.h"
#include "contiki-net.h"

#include "shell.h"
#include "serial-shell.h"
#include "dev/serial-line.h"
#include "dev/uart1.h"

#include "dev/leds.h"

#include <stdio.h>
#include <string.h>

struct etimer udp_periodic_timer;
struct uip_udp_conn *udpconn;

static void udphandler(process_event_t ev, process_data_t data)
{
	
	if(ev == tcpip_event) {

		if (uip_newdata()){

				leds_invert(LEDS_BLUE);
				leds_invert(LEDS_GREEN);
				shell_output_str(NULL, "Received: ", (char*)uip_appdata);
		}
	}
	//else if(ev == sensors_event && data == &button_sensor){
		//snomc_log_print(&snomc_logs.received_data);
		//etimer_set(&udp_periodic_timer, CLOCK_SECOND * 2);
		//snomc_log_print(&snomc_logs.sent_data);
	//}
}

/*---------------------------------------------------------------------------*/
/*
 * We declare the process.
 */
PROCESS(example_udp_server_process, "Example UDP server");
AUTOSTART_PROCESSES(&example_udp_server_process);
/*---------------------------------------------------------------------------*/
/*
 * The definition of the process.
 */
PROCESS_THREAD(example_udp_server_process, ev, data)
{

	uip_ipaddr_t ipaddr;

	PROCESS_BEGIN();

  /* WITH_UIP=1 assumes incoming SLIP serial data.
  * We override this assumption by restoring default serial input handler. */
  uart1_set_input(serial_line_input_byte);
  serial_line_init();

  printf("UDP Echo Server test\n");

	serial_shell_init();
	shell_power_init();

	uip_gethostaddr(&ipaddr);

	printf("This IP: %u.%u.%u.%u\n", uip_ipaddr_to_quad(&ipaddr));

	/* Create a UDP 'connection' with IP 0.0.0.0 and port 0 as remote host.
	 * This means the stack will accepts UDP datagrams from any node. */
	udpconn = udp_new(NULL, uip_htons(0), NULL);

	/* Bind the UDP 'connection' to the port 50000. That's the port we're listening on. */
	udp_bind(udpconn, uip_htons(50000));

	printf("listening on UDP port %u\n", uip_htons(udpconn->lport));

	//SENSORS_ACTIVATE(button_sensor);

	while(1) {
		PROCESS_WAIT_EVENT();
		udphandler(ev, data);
	}

	PROCESS_END();
}
