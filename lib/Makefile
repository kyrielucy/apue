#
# Makefile for misc library
#

ROOT = ..
PLATFORM = $(shell $(ROOT)/systype.sh)
include $(ROOT)/Makefile.defines.$(PLATFORM)

LIBMISC = libapue.a

OBJS = error.o errorlog.o

all: $(LIBMISC)

$(LIBMISC): $(OBJS)
	$(AR) rv $(LIBMISC) $?
