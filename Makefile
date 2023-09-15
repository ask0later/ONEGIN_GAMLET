TARGET = ONEGIN

CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align \
 -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
 -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ \
 -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
 -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
 -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
 -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
 -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

COMPILE = g++ -c $^ $(CFLAGS)

.PHONY: all
all: $(TARGET)

$(TARGET): main.o linebreak.o sort.o
        @g++ $^ -o $(TARGET) $(CFLAGS)

main.o: main.cpp
        @$(COMPILE)

linebreak.o: linebreak.cpp
        @$(COMPILE)

sort.o: sort.cpp
        @$(COMPILE)

.PHONY: clean

clean:
        rm -rf $(TARGET) *.o
        rm -rf *.exe


