# 	kdsh
#	makefile
#	By Mozilla Public License Version 2.0
#	Copyright (c) 2023 Yao Zi. All rights reserved.

CROSS_COMPILE	=
CC		= gcc
TARGET_CC	= $(CROSS_COMPILE)$(CC)
ARCH		= $(shell uname -m)
CONFIG_$(ARCH)	= yes

NATIVE_FLAGS_$(CONFIG_x86_64)		= -DTARGET_x86_64
NATIVE_FLAGS_$(CONFIG_riscv64)		= -DTARGET_riscv64 # -mno-relax
NATIVE_FLAGS_$(CONFIG_aarch64)		= -DTARGET_aarch64
ARCH_FLAGS	= $(NATIVE_FLAGS_yes)

ifeq ($(RELEASE),1)
DEBUG_FLAGS	= -O2
else
DEBUG_FLAGS	= -g -O0
endif

CFLAGS		= $(ARCH_FLAGS) $(DEBUG_FLAGS) -nostdlib -fno-builtin -static \
		  -std=gnu99 -Wall -Wextra -pedantic

SRCS		= $(wildcard src/*.c) $(wildcard src/*.S)
OBJS		= $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRCS)))

OUTPUT		= kdsh

kdsh: $(OBJS)
	$(TARGET_CC) $(OBJS) -o $(OUTPUT) $(CFLAGS)

%.o: %.c
	$(TARGET_CC) $(CFLAGS) $< -c -o $@

%.o: %.S
	$(TARGET_CC) $(CFLAGS) $< -c -o $@

.PHONY: clean initramfs

clean:
	-rm $(OBJS)
initramfs: initramfs.gz
initramfs.gz: kdsh
	mkdir -p init						&& \
	cd init							&& \
	cp ../kdsh init						&& \
	find . | cpio -ov -H newc | gzip -9 > ../initramfs.gz
	rm -rf init
