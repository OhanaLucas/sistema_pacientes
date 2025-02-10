#include <stdio.h>
#include <string.h>
#include "paciente.h"

// Função para criar um novo paciente / Function to create a new patient
Paciente criarPaciente(int id, const char* cpf, const char* nome, int idade, const char* data_cadastro) {
    Paciente p;
    p.id = id;

    // Copia os valores para os campos da estrutura, garantindo terminação correta das strings
    // Copy values to structure fields, ensuring proper string termination
    strncpy(p.cpf, cpf, 14);
    p.cpf[14] = '\0';
    strncpy(p.nome, nome, 99);
    p.nome[99] = '\0';
    p.idade = idade;
    strncpy(p.data_cadastro, data_cadastro, 10);
    p.data_cadastro[10] = '\0';

    return p;
}

// Função para imprimir os dados do paciente / Function to print patient data
void imprimirPaciente(Paciente p) {
    printf("ID: %d, CPF: %s, Nome: %s, Idade: %d, Data Cadastro: %s\n",
           p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
}
