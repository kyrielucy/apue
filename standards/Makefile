ROOT = ..
PLATFORM = $(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)


PROGS =conf

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

conf:	conf.c

conf.c: makeconf.awk sysconf.sym pathconf.sym
	$(AWK) -f makeconf.awk >conf.c

sysconf.sym: sysconf-lim.sym
	grep -v "^#" sysconf-lim.sym >sysconf.sym

pathconf.sym: pathconf-lim.sym
	grep -v "^#" pathconf-lim.sym >pathconf.sym

clean:
	rm -f  $(PROGS) $(TMPFILES) *.o conf.c \
		pathconf.sym sysconf.sym

include $(ROOT)/Make.libapue.inc
