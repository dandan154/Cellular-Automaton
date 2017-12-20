####CFLAGS = -Wall -Wextra -pedantic

all:
			cc -o cellauto cell_manager.c cellauto.c menu.c

clean:
			rm ./cellauto
