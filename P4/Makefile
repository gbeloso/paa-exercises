# Makefile para o Problema 4 - Power2coin

CC      = gcc
CFLAGS  = -Wall -Wextra -O2
SRC     = p4.c

# Detecta o ambiente real.
# No WSL/Linux o shell e /bin/sh mesmo que a variavel OS venha herdada do Windows,
# por isso usamos 'uname' para decidir, com fallback para Windows nativo.
UNAME := $(shell uname 2>/dev/null)

ifeq ($(UNAME),)
    # Windows nativo (cmd/powershell): uname nao existe
    EXE = p4.exe
    RUN = p4.exe
    RM  = del /Q
else
    # Linux, WSL ou macOS
    EXE = p4
    RUN = ./p4
    RM  = rm -f
endif

# Compila o programa
$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)

build: $(EXE)

# Testa os exemplos do enunciado: 8->1, 30->2, 100->3, 999->4
run: $(EXE)
	@echo "Teste 1: entrada 8   esperado 1"
	@printf '8\n'   | $(RUN)
	@echo "Teste 2: entrada 30  esperado 2"
	@printf '30\n'  | $(RUN)
	@echo "Teste 3: entrada 100 esperado 3"
	@printf '100\n' | $(RUN)
	@echo "Teste 4: entrada 999 esperado 4"
	@printf '999\n' | $(RUN)

clean:
	$(RM) $(EXE)

.PHONY: build run clean
