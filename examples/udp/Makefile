CONTIKI_PROJECT = udp
CONTIKI = ../..
ifndef TARGET
TARGET=sky
endif

APPS = serial-shell
CFLAGS = -DWITH_UIP=1
SMALL=1

#-I. -DWITH_NULLMAC=1
#DEFINES=UIP_CONF_STATISTICS=1,UIP_CONF_UDP=1
#DEFINES=MY_DEBUG=1
#DEFINES=MAC_DRIVER=cxmac_driver,MAC_CHANNEL_CHECK_RATE=8

all: receiver sender

#%.shell-upload: %.ce
#	(echo; sleep 4; echo "~K"; sleep 4; \
#         echo "dec64 | write $*.ce | null"; sleep 4; \
#	 ../../tools/base64-encode < $<; sleep 4; \
#         echo ""; echo "~K"; echo "read $*.ce | size"; sleep 4) | make login

include $(CONTIKI)/Makefile.include

#receiver.$(TARGET): $(OBJECTDIR)/my-lib.o 
#$(OBJECTDIR)/snomc_logger.o

#sender.$(TARGET): $(OBJECTDIR)/my-lib.o 
#$(OBJECTDIR)/snomc_logger.o

#receiver_tcp.$(TARGET): $(OBJECTDIR)/my-lib.o $(OBJECTDIR)/snomc_logger.o

#sender_tcp.$(TARGET): $(OBJECTDIR)/my-lib.o $(OBJECTDIR)/snomc_logger.o

#my_app.$(TARGET): $(OBJECTDIR)/snomc.o $(OBJECTDIR)/snomc_protocol_receive.o $(OBJECTDIR)/snomc_protocol_send.o $(OBJECTDIR)/snomc_logger.o $(OBJECTDIR)/snomc_groups.o $(OBJECTDIR)/snomc_shell.o $(OBJECTDIR)/snomc_utils.o $(OBJECTDIR)/snomc_buffer.o
