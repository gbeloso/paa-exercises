# Configurações do Compilador
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = sort.o
SRC = sort.c

.PHONY: all run clean

all: $(TARGET)

# Compilação do código
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Execução automática dos casos de teste
run: $(TARGET)
	@echo "--------------------------------------------------"
	@echo " Executando Testes de Ordenação..."
	@echo "--------------------------------------------------"
	@# Teste 1
	@OUT1=$$(printf "5 3 5 2 4 1\n" | ./$(TARGET)); \
	ESP1="a = [ 1  2  3  4  5 ]"; \
	if [ "$$OUT1" = "$$ESP1" ]; then \
		echo "\033[0;32m[PASSOU]\033[0m Teste 1: Esperado = '$$ESP1' | Obtido = '$$OUT1'"; \
	else \
		echo "\033[0;31m[FALHOU]\033[0m Teste 1: Esperado = '$$ESP1' | Obtido = '$$OUT1'"; \
	fi
	@# Teste 2
	@OUT2=$$(printf "8 6 1 5 8 2 3 4 7\n" | ./$(TARGET)); \
	ESP2="a = [ 1  2  3  4  5  6  7  8 ]"; \
	if [ "$$OUT2" = "$$ESP2" ]; then \
		echo "\033[0;32m[PASSOU]\033[0m Teste 2: Esperado = '$$ESP2' | Obtido = '$$OUT2'"; \
	else \
		echo "\033[0;31m[FALHOU]\033[0m Teste 2: Esperado = '$$ESP2' | Obtido = '$$OUT2'"; \
	fi
	@echo "--------------------------------------------------"

# Limpeza do executável
clean:
	rm -f $(TARGET)
