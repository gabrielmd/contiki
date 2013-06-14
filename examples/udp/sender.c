#include "contiki.h"
#include "contiki-lib.h"
#include "contiki-net.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"

#include "shell.h"
#include "serial-shell.h"
#include "dev/serial-line.h"
#include "dev/uart1.h"

#include <stdio.h>
#include <string.h>

struct etimer udp_periodic_timer;
struct uip_udp_conn *udpconn;
uip_ipaddr_t ipaddr;
uint content_id;

uint16_t time_interval;

PROCESS(shell_send_process, "send");
SHELL_COMMAND(send_command,
	      "send",
	      "send <time>: start sending messages with the time interval in ms",
	      &shell_send_process);

PROCESS(shell_stop_process, "stop");
SHELL_COMMAND(stop_command,
        "stop",
        "stop: stop sending messages",
        &shell_stop_process);

PROCESS(udphandler_process, "udphandler_process");

PROCESS(udp_process_sender, "UDP test sender");
AUTOSTART_PROCESSES(&udp_process_sender);

PROCESS_THREAD(udphandler_process, ev, data)
{
  PROCESS_BEGIN();
  while(1) {
    PROCESS_WAIT_EVENT();
    char string_buffer[4];
    strcpy(string_buffer, "abc");
    string_buffer[3] = '\0';

    char string_tmp[60];
    //sprintf(string_tmp, "Sent to: %u.%u.%u.%u - content %s - nr:%u", uip_ipaddr_to_quad(&ipaddr), string_buffer, content_id);
    //shell_output_str(NULL, string_tmp, "");

    content_id++;

    /* sets timer for 2 seconds */
    etimer_set(&udp_periodic_timer, CLOCK_SECOND * (time_interval / 1000));

    /* visual debug */
    leds_invert(LEDS_RED);

    uip_udp_packet_send(udpconn, string_buffer, 4);
  }

  PROCESS_END();
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(shell_stop_process, ev, data)
{

  PROCESS_BEGIN();
  etimer_stop(&udp_periodic_timer);

  PROCESS_END();
}


/*---------------------------------------------------------------------------*/
PROCESS_THREAD(shell_send_process, ev, data)
{

	PROCESS_BEGIN();

  if(data != NULL) {
    time_interval = shell_strtolong(data, NULL);
  }

	process_post(&udphandler_process, ev, data);

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(udp_process_sender, ev, data)
{

	uip_ipaddr_t ipaddr_this;

	/* WITH_UIP=1 assumes incoming SLIP serial data.
	* We override this assumption by restoring default serial input handler. */
	uart1_set_input(serial_line_input_byte);
	serial_line_init();

	PROCESS_BEGIN();
	//SENSORS_ACTIVATE(button_sensor);

	serial_shell_init();
	shell_power_init();

	time_interval = 1000; // 1000ms = 1 second

	printf("Process test UDP sender started\n");

	/* this ip */
	uip_gethostaddr(&ipaddr_this);
	/* sink node - if the node has id 10X, the sink is 101. if the node is 20Y, the sink is 201 */
	uip_ipaddr(&ipaddr, ipaddr_this.u8[0], ipaddr_this.u8[1], (ipaddr_this.u8[2] - (ipaddr_this.u8[2] % 100)) + 1, ipaddr_this.u8[3]);

	udpconn = udp_new(&ipaddr, uip_htons(50000), NULL);
	/* Bind the UDP 'connection' to the port 50000. That's the port we're listening on. */
	udp_bind(udpconn, uip_htons(50000));

	printf("Created connection with remote peer. \n");

	content_id = 0;
	clock_init();

	shell_register_command(&send_command);
	shell_register_command(&stop_command);


  process_post(&udphandler_process, ev, data);


	PROCESS_END();
}
/*---------------------------------------------------------------------------*/
