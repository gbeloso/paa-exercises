CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11
TARGET  = p3
OBJ     = p3.o
SRC     = p3.c
TESTDIR = tests

.PHONY: all run clean

all: $(TARGET)

# Liga o objeto no executavel
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compila o fonte para objeto
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Roda as quatro entradas e compara com a saida esperada
run: all
	@pass=0; fail=0; \
	for i in 1 2 3 4; do \
		printf "== Teste %s ==\n" "$$i"; \
		got=$$(./$(TARGET) < $(TESTDIR)/$$i.in); \
		exp=$$(cat $(TESTDIR)/$$i.out); \
		if [ "$$got" = "$$exp" ]; then \
			printf "  OK\n"; \
			pass=$$((pass+1)); \
		else \
			printf "  FALHOU\n"; \
			printf "  --- esperado ---\n%s\n" "$$exp"; \
			printf "  --- obtido   ---\n%s\n" "$$got"; \
			fail=$$((fail+1)); \
		fi; \
	done; \
	printf "\nResultado: %s passou(ram), %s falhou(aram)\n" "$$pass" "$$fail"

clean:
	rm -f $(TARGET) $(OBJ)
