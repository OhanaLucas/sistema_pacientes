#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_paciente.h"

// Inicializa a estrutura do banco de dados / Initialize the database structure
void inicializarBD(BDPaciente* bd) {
    bd->inicio = NULL;
    bd->proximo_id = 1;
}

// Carrega os pacientes de um arquivo CSV / Load patients from a CSV file
void carregarBD(BDPaciente* bd, const char* arquivo) {
    FILE* file = fopen(arquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return;
    }

    char linha[256];
    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        return;
    }

    while (fgets(linha, sizeof(linha), file)) {
        int id, idade;
        char cpf[15], nome[100], data_cadastro[11];

        if (sscanf(linha, "%d,%[^,],%[^,],%d,%s", &id, cpf, nome, &idade, data_cadastro) != 5) {
            continue;
        }

        Paciente p = criarPaciente(id, cpf, nome, idade, data_cadastro);
        inserirPaciente(bd, p);
    }

    fclose(file);
}

// Salva os pacientes no arquivo CSV / Save patients to a CSV file
void salvarBD(BDPaciente* bd, const char* arquivo) {
    FILE* file = fopen(arquivo, "w");
    if (!file) {
        return;
    }

    fprintf(file, "ID,CPF,Nome,Idade,Data_Cadastro\n");

    No* atual = bd->inicio;
    while (atual) {
        fprintf(file, "%d,%s,%s,%d,%s\n",
                atual->paciente.id, atual->paciente.cpf, atual->paciente.nome,
                atual->paciente.idade, atual->paciente.data_cadastro);
        atual = atual->proximo;
    }

    fclose(file);
}

// Insere um novo paciente no banco de dados / Insert a new patient into the database
void inserirPaciente(BDPaciente* bd, Paciente p) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        return;
    }

    novo->paciente = p;
    novo->proximo = bd->inicio;
    bd->inicio = novo;
    bd->proximo_id++;
}

// Remove um paciente pelo ID / Remove a patient by ID
void removerPaciente(BDPaciente* bd, int id) {
    No* atual = bd->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->paciente.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return;
    }

    if (anterior == NULL) {
        bd->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

// Busca um paciente pelo CPF / Search for a patient by CPF
Paciente* buscarPacientePorCPF(BDPaciente* bd, const char* cpf) {
    No* atual = bd->inicio;
    while (atual != NULL) {
        if (strcmp(atual->paciente.cpf, cpf) == 0) {
            return &(atual->paciente);
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Busca um paciente pelo nome / Search for a patient by name
Paciente* buscarPacientePorNome(BDPaciente* bd, const char* nome) {
    No* atual = bd->inicio;
    while (atual != NULL) {
        if (strcmp(atual->paciente.nome, nome) == 0) {
            return &(atual->paciente);
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Lista todos os pacientes cadastrados / List all registered patients
void listarPacientes(BDPaciente* bd) {
    No* atual = bd->inicio;
    if (atual == NULL) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Pacientes ---\n");
    printf("ID | CPF          | Nome               | Idade | Data Cadastro\n");
    printf("--------------------------------------------------------------\n");
    while (atual != NULL) {
        printf("%-3d| %-12s | %-18s | %-5d | %s\n",
               atual->paciente.id, atual->paciente.cpf, atual->paciente.nome,
               atual->paciente.idade, atual->paciente.data_cadastro);
        atual = atual->proximo;
    }
}
