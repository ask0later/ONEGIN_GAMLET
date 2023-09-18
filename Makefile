TARGET = onegin


CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align \
 -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
 -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ \
 -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
 -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
 -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
 -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
 -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

COMPILE = g++ $(CFLAGS)

all: $(TARGET)

$(TARGET): main.o linebreak.o sort.o
	g++ main.o linebreak.o sort.o -o $(TARGET)

main.o: main.cpp
	$(COMPILE) main.cpp

linebreak.o: linebreak.cpp
	$(COMPILE) linebreak.cpp

sort.o: sort.cpp
	$(COMPILE) sort.cpp


clean:
	del $(TARGET) *.o


