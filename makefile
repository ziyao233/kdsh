# 	kdsh
#	makefile
#	By Mozilla Public License Version 2.0
#	Copyright (c) 2023 Yao Zi. All rights reserved.

CROSS_COMPILE	=
TARGET_CC	= $(CROSS_COMPILE)gcc
ARCH		= $(shell uname -m)
CONFIG_$(ARCH)	= yes

NATIVE_FLAGS_$(CONFIG_x86_64)		= -DTARGET_x86_64
ARCH_FLAGS	= $(NATIVE_FLAGS_yes)

ifeq ($(RELEASE),1)
DEBUG_FLAGS	= -O2
else
DEBUG_FLAGS	= -g -O0
endif

CFLAGS		= $(ARCH_FLAGS) $(DEBUG_FLAGS) -nostdlib -fno-builtin -static

SRCS		= $(wildcard src/*.c) $(wildcard src/*.S)
OBJS		= $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRCS)))

OUTPUT		= kdsh

kdsh: $(OBJS)
	$(TARGET_CC) $(OBJS) -o $(OUTPUT) $(CFLAGS)

%.o: %.c
	$(TARGET_CC) $(CFLAGS) $< -c -o $@

%.o: %.S
	$(TARGET_CC) $(CFLAGS) $< -c -o $@

.PHONY: clean

clean:
	-rm $(OBJS)