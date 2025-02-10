#ifndef BD_PACIENTE_H
#define BD_PACIENTE_H

#include "paciente.h"

// Estrutura de um nó da lista encadeada / Structure of a linked list node
typedef struct No {
    Paciente paciente;    // Dados do paciente / Patient data
    struct No* proximo;   // Ponteiro para o próximo nó / Pointer to the next node
} No;

// Estrutura do banco de dados de pacientes / Patient database structure
typedef struct {
    No* inicio;         // Ponteiro para o primeiro paciente / Pointer to the first patient
    int proximo_id;     // Próximo ID disponível para cadastro / Next available patient ID
} BDPaciente;

// Funções para manipulação do banco de dados / Functions to manage the patient database
void inicializarBD(BDPaciente* bd);
void carregarBD(BDPaciente* bd, const char* arquivo);
void salvarBD(BDPaciente* bd, const char* arquivo);
void inserirPaciente(BDPaciente* bd, Paciente p);
void removerPaciente(BDPaciente* bd, int id);
Paciente* buscarPacientePorCPF(BDPaciente* bd, const char* cpf);
Paciente* buscarPacientePorNome(BDPaciente* bd, const char* nome);
void listarPacientes(BDPaciente* bd);

#endif
