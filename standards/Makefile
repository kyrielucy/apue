ROOT = ..
PLATFORM = $(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)


PROGS =conf option

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

conf:	conf.c

option: option.c

conf.c: makeconf.awk sysconf.sym pathconf.sym
	$(AWK) -f makeconf.awk >conf.c
option.c: makeopt.awk sysopt.sym pathopt.sym
	$(AWK) -f makeopt.awk >option.c

sysconf.sym: sysconf-lim.sym
	grep -v "^#" sysconf-lim.sym >sysconf.sym

pathconf.sym: pathconf-lim.sym
	grep -v "^#" pathconf-lim.sym >pathconf.sym

sysopt.sym: sysconf-opt.sym
	grep -v "^#" sysconf-opt.sym >sysopt.sym

pathopt.sym: pathconf-opt.sym
	grep -v "^#" pathconf-opt.sym >pathopt.sym

clean:
	rm -f  $(PROGS) $(TMPFILES) *.o conf.c option.c \
		pathconf.sym sysconf.sym \
		pathopt.sym sysopt.sym

include $(ROOT)/Make.libapue.inc
