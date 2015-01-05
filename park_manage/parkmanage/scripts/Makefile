CC := gcc
CFLAGS := -Wall -O3
Libs = -lsqlite3
Target := park_manage
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += check_putin main add_car display_park park_to_way way_to_park get_car queue_to_park create_stack my_strcmp menu write_to_file db_to_park
AllObjs := $(addsuffix /src/*.o,$(Modules))

