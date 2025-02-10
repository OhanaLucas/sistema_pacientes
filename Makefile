# Compilador e flags de compilação
# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -std=c11  # Ativa alertas de compilação e usa o padrão C11 / Enable warnings and use C11 standard

# Lista de arquivos objeto a serem compilados
# List of object files to be compiled
OBJS = main.o paciente.o bd_paciente.o

# Alvo padrão: compilar o programa
# Default target: compile the program
all: sistema_pacientes

# Compilação do executável principal
# Compile the main executable
sistema_pacientes: $(OBJS)
	$(CC) $(CFLAGS) -o sistema_pacientes $(OBJS)

# Compilar cada módulo separadamente
# Compile each module separately
main.o: main.c bd_paciente.h
	$(CC) $(CFLAGS) -c main.c

paciente.o: paciente.c paciente.h
	$(CC) $(CFLAGS) -c paciente.c

bd_paciente.o: bd_paciente.c bd_paciente.h paciente.h
	$(CC) $(CFLAGS) -c bd_paciente.c

# Alvo para limpar os arquivos compilados
# Target to clean compiled files
clean:
	rm -f *.o sistema_pacientes
