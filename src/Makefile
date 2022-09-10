TARGET1=../build/graph
CLEAN=../build/*
SRC1=main_2_stage.c polish.c print.c graph.c stack.c

all:
	gcc -std=c11 -Wall -Werror -Wextra $(SRC1) -o $(TARGET1)

clean:
	rm -rf $(CLEAN)

rebuild: clean all

