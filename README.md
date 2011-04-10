# automata
Written in C++, using SFML for graphics.
This is an experiment for cellular automata. The 
implementation is painfully inefficient, and will probably
devour one of your cores.

There are four different cells, blank, red, green, and blue. 

## Rules
* Any color can eat a blank cell
* A Red cell will eat a green cell
* A Green cell will eat a blue cell
* A Blue cell will eat a red cell

## Building
SMFL is required for building. Once that's installed, this can be
built by typing `make` for a regular build, or `make debug` for a
debug build.
