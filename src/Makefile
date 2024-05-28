SRC = ./main.c
BIN = ../bin/main
INC = ../include
LLIB = -lncurses

main: ${SRC}
	@echo " "
	@echo "[LOG] STARTING COMPILATION WITH GCC:"
	gcc -Wall -Wextra --pedantic-errors -I${INC} ${LLIB} ${SRC} -o ${BIN}
	@echo "[LOG] COMPILATION ENDED."

clean: ${BIN}
	@echo "[LOG] Removing ${BIN}"
	rm ${BIN}

run: ${BIN}
	@echo "[LOG] Executing ${BIN}"
	${BIN}
