################################################################################
# Makefile for Project
################################################################################

-include ../initial.mk

INC:=../hdr
RES:=release
OBJ_DIR:=../objs
SRC:=$(wildcard ../src/*.c)

CFLAGS:=-Wall -Wextra -O3 -g3 -I$(INC)
CC:=gcc
GCCINFO:=gcc -E -P -v -dD src/specs.c

obj:=$(patsubst %.c,%.o,$(notdir $(SRC)))
objs:=$(addprefix $(OBJ_DIR)/,$(obj))

deps:=$(patsubst %.c,%.d,$(notdir $(SRC)))
-include $deps

all: edit #tags

-include tags.mk

edit: $(obj)
	$(CC) -o edit $(objs)

$(obj): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $(OBJ_DIR)/$@

main.o: defs.h
	$(CC) -c $(CFLAGS) $< -o $(OBJ_DIR)/$@

.PHONY: all docs clean

docs:
	-doxygen

clean:
	-$(RM) edit $(objs)

