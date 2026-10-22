# Configurações do Compilador
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = p2.o
SRC = p2.c

.PHONY: all run clean

all: $(TARGET)

# Compilação do código
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Execução automática de todos os casos de teste do PDF
run: $(TARGET)
	@echo "--------------------------------------------------"
	@echo " Executando Testes do Laboratório..."
	@echo "--------------------------------------------------"
	@# Teste 1
	@OUT1=$$(printf "6 6 2\n1 3\n3 5\n2 3\n2 4\n4 6\n6 2\n" | ./$(TARGET)); \
	if [ "$$OUT1" = "3" ]; then \
		echo "\033[0;32m[PASSOU]\033[0m Teste 1: Esperado = 3 | Obtido = $$OUT1"; \
	else \
		echo "\033[0;31m[FALHOU]\033[0m Teste 1: Esperado = 3 | Obtido = $$OUT1"; \
	fi
	@# Teste 2
	@OUT2=$$(printf "6 6 3\n1 2\n2 3\n3 1\n4 5\n5 6\n6 4\n" | ./$(TARGET)); \
	if [ "$$OUT2" = "0" ]; then \
		echo "\033[0;32m[PASSOU]\033[0m Teste 2: Esperado = 0 | Obtido = $$OUT2"; \
	else \
		echo "\033[0;31m[FALHOU]\033[0m Teste 2: Esperado = 0 | Obtido = $$OUT2"; \
	fi
	@# Teste 3
	@OUT3=$$(printf "10 11 2\n1 2\n1 3\n3 2\n3 5\n5 4\n5 6\n9 10\n8 9\n8 7\n6 7\n6 8\n" | ./$(TARGET)); \
	if [ "$$OUT3" = "7" ]; then \
		echo "\033[0;32m[PASSOU]\033[0m Teste 3: Esperado = 7 | Obtido = $$OUT3"; \
	else \
		echo "\033[0;31m[FALHOU]\033[0m Teste 3: Esperado = 7 | Obtido = $$OUT3"; \
	fi
	@echo "--------------------------------------------------"

# Limpeza do executável
clean:
	rm -f $(TARGET)