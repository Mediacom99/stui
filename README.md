# Stupid TUI

Exactly what the title says: a stupid text user interface with ncurses.
I will probably use this as a way to learn and implement some sort of
user interface in my noughtyMQ chatroom app.

## Statically link ncurses
gcc -v -o mainstatic ./src/main.c -I./include -static-libgcc -static -lncurses
