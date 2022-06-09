##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

CC =    gcc
CFLAGS =    -W -Wextra -Wall -I./include -Wno-deprecated-declarations -I/opt/homebrew/Cellar/csfml/2.5.1/include
LDFLAGS =    -L/opt/homebrew/Cellar/csfml/2.5.1/lib -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -L./lib/ -lcly -lm

SRC =   $(wildcard src/*.c src/button/*.c src/create/*.c src/destroy/*.c src/update/*.c src/events/*.c src/collisions/*.c)

OBJ =    $(SRC:.c=.o)

BIN_NAME    =    my_rpg

all: make_lib $(BIN_NAME) $(OBJ)

make_lib:
	@ make -C lib/

$(BIN_NAME): $(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34mMY RPG \033[0m"
	@ $(CC) -o $(BIN_NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	@ echo "\033[1;32m[ SUCCESS ] \033[0m\033[1;34mBinary :\033[1;32m MY RPG \033[1;34m created sucesfully.\033[0m"

clean:
	@ echo "\033[3;31mRemoving from MY RPG: \033[0m"
	@ echo "\033[3;31m$(OBJ)\033[0m" | tr ' ' '\n'
	@ rm -f $(OBJ)
	@ make clean -C lib/

fclean: clean
	@ echo "\033[3;31m./$(BIN_NAME)\033[0m"
	@ rm -f $(BIN_NAME)
	@ make fclean -C lib/

re: fclean all