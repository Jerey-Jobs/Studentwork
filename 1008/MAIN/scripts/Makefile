CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread
Target := client
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += add sub main mul
AllObjs := $(addsuffix /src/*.o,$(Modules))
