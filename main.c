#include <stdio.h>
#include <string.h>
#include "bd_paciente.h"

// Função para exibir o menu principal
// Function to display the main menu
void exibirMenu() {
    printf("\n--- Sistema de Gerenciamento de Pacientes ---\n");
    printf("1. Consultar paciente\n");
    printf("2. Atualizar paciente\n");
    printf("3. Remover paciente\n");
    printf("4. Inserir paciente\n");
    printf("5. Listar pacientes\n");
    printf("Q. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para consultar um paciente pelo nome ou CPF
// Function to search for a patient by name or CPF
void consultarPaciente(BDPaciente* bd) {
    int modo;
    printf("Escolha o modo de consulta:\n");
    printf("1 - Por nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Retornar ao menu principal\n");
    if (scanf("%d", &modo) != 1) {
        printf("Erro ao ler a opcao.\n");
        return;
    }
    getchar(); // Limpar o buffer do teclado / Clear keyboard buffer

    if (modo == 1) {
        char nome[100];
        printf("Digite o nome: ");
        if (scanf(" %[^"]", nome) != 1) {
            printf("Erro ao ler o nome.\n");
            return;
        }
        Paciente* p = buscarPacientePorNome(bd, nome);
        if (p) {
            imprimirPaciente(*p);
        } else {
            printf("Paciente nao encontrado.\n");
        }
    } else if (modo == 2) {
        char cpf[15];
        printf("Digite o CPF: ");
        if (scanf(" %[^"]", cpf) != 1) {
            printf("Erro ao ler o CPF.\n");
            return;
        }
        Paciente* p = buscarPacientePorCPF(bd, cpf);
        if (p) {
            imprimirPaciente(*p);
        } else {
            printf("Paciente nao encontrado.\n");
        }
    }
}

// Função para atualizar os dados de um paciente
// Function to update a patient's data
void atualizarPaciente(BDPaciente* bd) {
    int id;
    printf("Digite o ID do paciente a ser atualizado: ");
    if (scanf("%d", &id) != 1) {
        printf("Erro ao ler o ID.\n");
        return;
    }
    getchar(); // Limpar o buffer do teclado / Clear keyboard buffer

    No* atual = bd->inicio;
    while (atual != NULL && atual->paciente.id != id) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Paciente com ID %d nao encontrado.\n", id);
        return;
    }

    char cpf[15], nome[100], data_cadastro[11];
    int idade;

    printf("Digite o novo CPF (ou '-' para manter o atual): ");
    if (scanf(" %[^"]", cpf) != 1) {
        printf("Erro ao ler o CPF.\n");
        return;
    }
    if (strcmp(cpf, "-") != 0) {
        strncpy(atual->paciente.cpf, cpf, 14);
        atual->paciente.cpf[14] = '\0';
    }

    printf("Digite o novo nome (ou '-' para manter o atual): ");
    if (scanf(" %[^"]", nome) != 1) {
        printf("Erro ao ler o nome.\n");
        return;
    }
    if (strcmp(nome, "-") != 0) {
        strncpy(atual->paciente.nome, nome, 99);
        atual->paciente.nome[99] = '\0';
    }

    printf("Digite a nova idade (ou -1 para manter a atual): ");
    if (scanf("%d", &idade) != 1) {
        printf("Erro ao ler a idade.\n");
        return;
    }
    if (idade != -1) {
        atual->paciente.idade = idade;
    }

    printf("Digite a nova data de cadastro (ou '-' para manter a atual): ");
    if (scanf(" %[^"]", data_cadastro) != 1) {
        printf("Erro ao ler a data de cadastro.\n");
        return;
    }
    if (strcmp(data_cadastro, "-") != 0) {
        strncpy(atual->paciente.data_cadastro, data_cadastro, 10);
        atual->paciente.data_cadastro[10] = '\0';
    }

    printf("Paciente atualizado com sucesso.\n");
}

// Função para inserir um novo paciente
// Function to insert a new patient
void inserirPacienteMenu(BDPaciente* bd) {
    char cpf[15], nome[100], data_cadastro[11];
    int idade;

    printf("Digite o CPF: ");
    if (scanf(" %[^"]", cpf) != 1) {
        printf("Erro ao ler o CPF.\n");
        return;
    }

    printf("Digite o nome: ");
    if (scanf(" %[^"]", nome) != 1) {
        printf("Erro ao ler o nome.\n");
        return;
    }

    printf("Digite a idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Erro ao ler a idade.\n");
        return;
    }

    printf("Digite a data de cadastro (AAAA-MM-DD): ");
    if (scanf(" %[^"]", data_cadastro) != 1) {
        printf("Erro ao ler a data de cadastro.\n");
        return;
    }

    Paciente p = criarPaciente(bd->proximo_id, cpf, nome, idade, data_cadastro);
    inserirPaciente(bd, p);

    printf("Paciente inserido com sucesso.\n");
}

// Função principal do programa
// Main function of the program
int main() {
    BDPaciente bd;
    inicializarBD(&bd);
    carregarBD(&bd, "bd_paciente.csv");

    char opcao;
    do {
        exibirMenu();
        if (scanf(" %c", &opcao) != 1) {
            printf("Erro ao ler a opcao.\n");
            break;
        }
        getchar(); // Limpar o buffer do teclado / Clear keyboard buffer

        switch (opcao) {
            case '1':
                consultarPaciente(&bd);
                break;
            case '2':
                atualizarPaciente(&bd);
                break;
            case '3': {
                int id;
                printf("Digite o ID do paciente a ser removido: ");
                if (scanf("%d", &id) != 1) {
                    printf("Erro ao ler o ID.\n");
                    break;
                }
                removerPaciente(&bd, id);
                break;
            }
            case '4':
                inserirPacienteMenu(&bd);
                break;
            case '5':
                listarPacientes(&bd);
                break;
            case 'Q':
            case 'q':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 'Q' && opcao != 'q');

    salvarBD(&bd, "bd_paciente.csv");
    return 0;
}