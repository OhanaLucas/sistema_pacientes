#ifndef PACIENTE_H
#define PACIENTE_H

// Definição da estrutura do paciente
// Patient structure definition
typedef struct {
    int id;                // Identificador único do paciente / Unique patient ID
    char cpf[15];          // CPF do paciente (formato brasileiro) / Patient's CPF (Brazilian format)
    char nome[100];        // Nome completo do paciente / Full name of the patient
    int idade;             // Idade do paciente / Patient's age
    char data_cadastro[11];// Data de cadastro no formato AAAA-MM-DD / Registration date in YYYY-MM-DD format
} Paciente;

// Função para criar um novo paciente / Function to create a new patient
Paciente criarPaciente(int id, const char* cpf, const char* nome, int idade, const char* data_cadastro);

// Função para imprimir os dados de um paciente / Function to print a patient's data
void imprimirPaciente(Paciente p);

#endif
