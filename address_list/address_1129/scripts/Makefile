CC := gcc
CFLAGS := -Wall -O3
Libs = -lsqlite3
Target := address_list
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += check_putin my_add my_delete my_display menu main my_strcmp create_list my_search write_to_db db_to_address
AllObjs := $(addsuffix /src/*.o,$(Modules))

