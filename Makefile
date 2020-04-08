K=kernel
U=user

OBJS = \
  $K/entry.o \
  $K/start.o \
  $K/console.o \
  $K/printf.o \
  $K/uart.o \
  $K/kalloc.o \
  $K/spinlock.o \
  $K/string.o \
  $K/main.o \
  $K/vm.o \
  $K/proc.o \
  $K/swtch.o \
  $K/trampoline.o \
  $K/trap.o \
  $K/syscall.o \
  $K/sysproc.o \
  $K/bio.o \
  $K/fs.o \
  $K/log.o \
  $K/sleeplock.o \
  $K/file.o \
  $K/pipe.o \
  $K/exec.o \
  $K/sysfile.o \
  $K/kernelvec.o \
  $K/plic.o \
  $K/virtio_disk.o

# riscv64-unknown-elf- or riscv64-linux-gnu-
# perhaps in /opt/riscv/bin
#TOOLPREFIX = 

# Try to infer the correct TOOLPREFIX if not set
ifndef TOOLPREFIX
TOOLPREFIX := $(shell if riscv64-unknown-elf-objdump -i 2>&1 | grep 'elf64-big' >/dev/null 2>&1; \
	then echo 'riscv64-unknown-elf-'; \
	elif riscv64-linux-gnu-objdump -i 2>&1 | grep 'elf64-big' >/dev/null 2>&1; \
	then echo 'riscv64-linux-gnu-'; \
	else echo "***" 1>&2; \
	echo "*** Error: Couldn't find an riscv64 version of GCC/binutils." 1>&2; \
	echo "*** To turn off this error, run 'gmake TOOLPREFIX= ...'." 1>&2; \
	echo "***" 1>&2; exit 1; fi)
endif

QEMU = qemu-system-riscv64

CC = $(TOOLPREFIX)gcc
AS = $(TOOLPREFIX)gas
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump

CFLAGS = -Wall -Werror -O -fno-omit-frame-pointer -ggdb
CFLAGS += -MD
CFLAGS += -mcmodel=medany
CFLAGS += -ffreestanding -fno-common -nostdlib -mno-relax
CFLAGS += -I.
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)

# Disable PIE when possible (for Ubuntu 16.10 toolchain)
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]no-pie'),)
CFLAGS += -fno-pie -no-pie
endif
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]nopie'),)
CFLAGS += -fno-pie -nopie
endif

LDFLAGS = -z max-page-size=4096

$K/kernel: $(OBJS) $K/kernel.ld $U/initcode
	$(LD) $(LDFLAGS) -T $K/kernel.ld -o $K/kernel $(OBJS) 
	$(OBJDUMP) -S $K/kernel > $K/kernel.asm
	$(OBJDUMP) -t $K/kernel | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > $K/kernel.sym

$U/initcode: $U/initcode.S
	$(CC) $(CFLAGS) -nostdinc -I. -Ikernel -c $U/initcode.S -o $U/initcode.o
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o $U/initcode.out $U/initcode.o
	$(OBJCOPY) -S -O binary $U/initcode.out $U/initcode
	$(OBJDUMP) -S $U/initcode.o > $U/initcode.asm

tags: $(OBJS) _init
	etags *.S *.c

ULIB = $U/ulib.o $U/usys.o $U/printf.o $U/umalloc.o

# LIBC STUFF
TIME_DIR = ./user/libc/time/

TIME_TEST_DIR = ./user/libc/time/test/

TIME = $(TIME_DIR)time.o\
	$(TIME_DIR)difftime.o\
	$(TIME_DIR)mktime.o\
	$(TIME_DIR)asctime.o\

TIME_SRC = $(TIME_DIR)time.c\
		$(TIME_DIR)difftime.c\
		$(TIME_DIR)mktime.c\
		$(TIME_DIR)asctime.c\

TIME_TEST = $(TIME_TEST_DIR)test_time.o\
			$(TIME_TEST_DIR)test_difftime.o\
			$(TIME_TEST_DIR)test_mktime.o\
			$(TIME_TEST_DIR)test_asctime.o\

TIME_TEST_SRC = $(TIME_TEST_DIR)test_time.c\
				$(TIME_TEST_DIR)test_difftime.c\
				$(TIME_TEST_DIR)test_mktime.c\
				$(TIME_TEST_DIR)test_asctime.c\

TIME_TEST_OBJ_FILES = test_time.o test_difftime.o test_mktime.o test_asctime.o


STDLIB_DIR = ./user/libc/stdlib/

STDLIB_TEST_DIR = ./user/libc/stdlib/test/

SETJMP_DIR = ./libc/setjmp/
SETJMP_TEST_DIR = ./user/libc/setjmp/test/

STDLIB = $(STDLIB_DIR)atoi.o\
	   $(STDLIB_DIR)abs.o\
	   $(STDLIB_DIR)atol.o\
	   $(STDLIB_DIR)bsearch.o\
	   $(STDLIB_DIR)atoll.o\
	   $(STDLIB_DIR)div.o\
	   $(STDLIB_DIR)labs.o\
	   $(STDLIB_DIR)ldiv.o\
	   $(STDLIB_DIR)qsort.o\

STDLIB_SRC = $(STDLIB_DIR)atoi.c\
		   $(STDLIB_DIR)abs.c\
		   $(STDLIB_DIR)abs.c\
		   $(STDLIB_DIR)bsearch.c\
		   $(STDLIB_DIR)atoll.c\
		   $(STDLIB_DIR)atol.c\
		   $(STDLIB_DIR)div.c\
		   $(STDLIB_DIR)labs.c\
		   $(STDLIB_DIR)ldiv.c\
		   $(STDLIB_DIR)qsort.c\

STDLIB_TEST = $(STDLIB_TEST_DIR)test_abs.o\
			$(STDLIB_TEST_DIR)test_bsearch.o\
			$(STDLIB_TEST_DIR)test_atoi.o\
			$(STDLIB_TEST_DIR)test_atol.o\
			$(STDLIB_TEST_DIR)test_atoll.o\
			$(STDLIB_TEST_DIR)test_div.o\
			$(STDLIB_TEST_DIR)test_labs.o\
			$(STDLIB_TEST_DIR)test_ldiv.o\
			$(STDLIB_TEST_DIR)test_qsort.o\

STDLIB_TEST_SRC = $(STDLIB_TEST_DIR)test_abs.c\
				$(STDLIB_TEST_DIR)test_bsearch.c\
				$(STDLIB_TEST_DIR)test_atoi.c\
				$(STDLIB_TEST_DIR)test_atol.c\
				$(STDLIB_TEST_DIR)test_atoll.c\
				$(STDLIB_TEST_DIR)test_div.c\
				$(STDLIB_TEST_DIR)test_labs.c\
				$(STDLIB_TEST_DIR)test_ldiv.c\
				$(STDLIB_TEST_DIR)test_qsort.c\

TEST_OBJ_FILES = test_bsearch.o test_abs.o test_atoi.o test_atol.o test_atoll.o test_div.o test_labs.o test_ldiv.o test_qsort.o


_%: %.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^
	$(OBJDUMP) -S $@ > $*.asm
	$(OBJDUMP) -t $@ | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > $*.sym

$U/usys.S : $U/usys.pl
	perl $U/usys.pl > $U/usys.S

$U/usys.o : $U/usys.S
	$(CC) $(CFLAGS) -c -o $U/usys.o $U/usys.S

$U/_forktest: $U/forktest.o $(ULIB)
	# forktest has less library code linked in - needs to be small
	# in order to be able to max out the proc table.
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $U/_forktest $U/forktest.o $U/ulib.o $U/usys.o
	$(OBJDUMP) -S $U/_forktest > $U/forktest.asm

LIBCTEST_LIBS = $U/libctest.o\
			$U/ulib.o\
			$U/printf.o\
			$U/umalloc.o\
			$(STDLIB_TEST)\
			$(STDLIB)\
			$U/usys.o			

$U/_libctest: $U/libctest.o $(STDLIB)
	# @echo "==== BUILDING TIME ===="
	# $(CC) $(CFLAGS) -c $(TIME_TEST_SRC)
	# mv $(TIME_TEST_OBJ_FILES) $(TIME_TEST_DIR)
	@echo "==== BUILDING STDLIB ===="
	$(CC) $(CFLAGS) -c $(STDLIB_TEST_SRC)
	mv $(TEST_OBJ_FILES)  $(STDLIB_TEST_DIR)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $U/_libctest $(LIBCTEST_LIBS)
	# $(OBJDUMP) -S _libctest > libctest.asm


mkfs/mkfs: mkfs/mkfs.c $K/fs.h
	gcc -Werror -Wall -I. -o mkfs/mkfs mkfs/mkfs.c

# Prevent deletion of intermediate files, e.g. cat.o, after first build, so
# that disk image changes after first build are persistent until clean.  More
# details:
# http://www.gnu.org/software/make/manual/html_node/Chained-Rules.html
.PRECIOUS: %.o

UPROGS=\
	$U/_cat\
	$U/_echo\
	$U/_forktest\
	$U/_grep\
	$U/_init\
	$U/_kill\
	$U/_ln\
	$U/_ls\
	$U/_mkdir\
	$U/_rm\
	$U/_sh\
	$U/_stressfs\
	$U/_usertests\
	$U/_wc\
	$U/_zombie\
	$U/_libctest\

fs.img: mkfs/mkfs README $(UPROGS)
	mkfs/mkfs fs.img README $(UPROGS)

-include kernel/*.d user/*.d

clean: 
	rm -f *.tex *.dvi *.idx *.aux *.log *.ind *.ilg \
	*/*.o */*.d */*.asm */*.sym \
	$U/initcode $U/initcode.out $K/kernel fs.img \
	mkfs/mkfs .gdbinit \
        $U/usys.S \
	$(UPROGS)

# try to generate a unique GDB port
GDBPORT = $(shell expr `id -u` % 5000 + 25000)
# QEMU's gdb stub command line changed in 0.11
QEMUGDB = $(shell if $(QEMU) -help | grep -q '^-gdb'; \
	then echo "-gdb tcp::$(GDBPORT)"; \
	else echo "-s -p $(GDBPORT)"; fi)
ifndef CPUS
CPUS := 3
endif

QEMUEXTRA = -drive file=fs1.img,if=none,format=raw,id=x1 -device virtio-blk-device,drive=x1,bus=virtio-mmio-bus.1
QEMUOPTS = -machine virt -bios none -kernel $K/kernel -m 3G -smp $(CPUS) -nographic
QEMUOPTS += -drive file=fs.img,if=none,format=raw,id=x0 -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0

qemu: $K/kernel fs.img
	$(QEMU) $(QEMUOPTS)

.gdbinit: .gdbinit.tmpl-riscv
	sed "s/:1234/:$(GDBPORT)/" < $^ > $@

qemu-gdb: $K/kernel .gdbinit fs.img
	@echo "*** Now run 'gdb' in another window." 1>&2
	$(QEMU) $(QEMUOPTS) -S $(QEMUGDB)

# CUT HERE
# prepare dist for students
# after running make dist, probably want to
# rename it to rev0 or rev1 or so on and then
# check in that version.

LIBC_EXTRA =  $(STDLIB_TEST_SRC) $(STDLIB_SRC)

EXTRA=\
	mkfs.c ulib.c user.h cat.c echo.c forktest.c grep.c kill.c\
	ln.c ls.c mkdir.c rm.c stressfs.c usertests.c wc.c zombie.c\
	printf.c umalloc.c $(LIBC_EXTRA) libctest.c\
	README dot-bochsrc *.pl \
	.gdbinit.tmpl gdbutil\

dist:
	rm -rf dist
	mkdir dist
	for i in $(FILES); \
	do \
		grep -v PAGEBREAK $$i >dist/$$i; \
	done
	sed '/CUT HERE/,$$d' Makefile >dist/Makefile
	echo >dist/runoff.spec
	cp $(EXTRA) dist

dist-test:
	rm -rf dist
	make dist
	rm -rf dist-test
	mkdir dist-test
	cp dist/* dist-test
	cd dist-test; $(MAKE) print
	cd dist-test; $(MAKE) bochs || true
	cd dist-test; $(MAKE) qemu

# update this rule (change rev#) when it is time to
# make a new revision.
tar:
	rm -rf /tmp/xv6
	mkdir -p /tmp/xv6
	cp dist/* dist/.gdbinit.tmpl /tmp/xv6
	(cd /tmp; tar cf - xv6) | gzip >xv6-rev10.tar.gz  # the next one will be 10 (9/17)

rvemu:
	riscv64-unknown-elf-objcopy -O binary kernel/kernel libc-kernel-$(v).text
	mv libc-kernel-$(v).text ../rvemu/
	mv fs.img ../rvemu/jve-fs-$(v).img

.PHONY: dist-test dist
