CC      := g++
IFLAGS 	:= -I include/
CFLAGS	:= -Wall -Wextra -Wno-unused-parameter -std=c++98 -O3
DFLAGS	:= -g -DDEBUG -O0

LNFLAGS	:= -lsfml-graphics -lsfml-window -lsfml-system -lm $(BOX2D)
EXE 	:= automata

.SUFFIXES=.cpp

SRC 	:= $(shell find 'src' -name '*.cpp' )
OBJ 	:= $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) $(LNFLAGS) -o$(EXE)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

debug:
	@$(MAKE) $(MFLAGS) CFLAGS="$(CFLAGS) $(DFLAGS)"

.PHONY= clean
