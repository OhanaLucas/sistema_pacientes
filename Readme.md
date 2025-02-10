# Sistema de Gerenciamento de Pacientes

## Descrição do Projeto

Este projeto implementa um sistema para gerenciamento de pacientes, permitindo a inserção, remoção, consulta e listagem de pacientes cadastrados. Os dados dos pacientes são armazenados em uma estrutura de lista encadeada e podem ser salvos e carregados a partir de um arquivo.

## Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

- `paciente.h`: Definição da estrutura `Paciente` e das funções relacionadas.
- `paciente.c`: Implementação das funções de manipulação de pacientes.
- `bd_paciente.h`: Definição da estrutura `BDPaciente` e das funções para manipulação do banco de dados de pacientes.
- `bd_paciente.c`: Implementação das funções para manipulação do banco de dados de pacientes.
- `main.c`: Implementação do menu de interação com o usuário e chamadas das funções de manipulação dos pacientes.
- `Makefile`: Arquivo para compilar o projeto usando `make`.

## Estruturas de Dados

### Paciente

O struct `Paciente` representa um paciente no sistema:

- `int id`: Identificador único do paciente.
- `char cpf[15]`: CPF do paciente.
- `char nome[100]`: Nome completo do paciente.
- `int idade`: Idade do paciente.
- `char data_cadastro[11]`: Data de cadastro no formato `AAAA-MM-DD`.

Funções associadas:

- `Paciente criarPaciente(int id, const char* cpf, const char* nome, int idade, const char* data_cadastro);`
- `void imprimirPaciente(Paciente p);`

### Banco de Dados de Pacientes (BDPaciente)

O banco de dados é armazenado em uma lista encadeada:

- `typedef struct No`: Representa um nó da lista encadeada contendo um paciente.
- `typedef struct { No* inicio; int proximo_id; } BDPaciente;`: Estrutura do banco de dados de pacientes.

Funções associadas:

- `void inicializarBD(BDPaciente* bd);`
- `void carregarBD(BDPaciente* bd, const char* arquivo);`
- `void salvarBD(BDPaciente* bd, const char* arquivo);`
- `void inserirPaciente(BDPaciente* bd, Paciente p);`
- `void removerPaciente(BDPaciente* bd, int id);`
- `Paciente* buscarPacientePorCPF(BDPaciente* bd, const char* cpf);`
- `Paciente* buscarPacientePorNome(BDPaciente* bd, const char* nome);`
- `void listarPacientes(BDPaciente* bd);`

## Compilação e Execução

Para compilar e executar o projeto, siga os passos abaixo:

1. Clone o repositório ou faça o download dos arquivos `paciente.h`, `paciente.c`, `bd_paciente.h`, `bd_paciente.c`, `main.c` e `Makefile`.
2. Abra um terminal no diretório onde os arquivos foram salvos.
3. Execute o comando `make` para compilar o projeto.
4. Execute o comando `./sistema_pacientes` para rodar o programa.

## Principais Decisões de Implementação

- **Uso de lista encadeada**: Optou-se por essa estrutura para permitir fácil inserção e remoção de pacientes, sem a necessidade de alocar um tamanho fixo de armazenamento.
- **Armazenamento em arquivo CSV**: Essa escolha facilita a persistência dos dados e a leitura dos pacientes sem a necessidade de um banco de dados relacional.
- **Identificação única automática**: O ID dos pacientes é gerado automaticamente, garantindo unicidade e evitando conflitos de identificadores.
- **Separação do código em módulos**: As funcionalidades do sistema foram distribuídas em diferentes arquivos (`paciente.c`, `bd_paciente.c`, `main.c`) para melhorar a organização e manutenção do código.

## Funcionalidades do Sistema

O sistema de gerenciamento de pacientes oferece as seguintes funcionalidades:

1. **Consultar paciente**: Busca um paciente pelo nome ou CPF.
2. **Atualizar paciente**: Permite modificar os dados de um paciente existente.
3. **Remover paciente**: Exclui um paciente do banco de dados.
4. **Inserir paciente**: Adiciona um novo paciente ao sistema.
5. **Listar pacientes**: Exibe todos os pacientes cadastrados.
6. **Salvar banco de dados**: Persiste os dados no arquivo `bd_paciente.csv` ao sair do programa.

## Considerações Finais

Este projeto foi desenvolvido para demonstrar conceitos de manipulação de listas encadeadas em C e gerenciamento de dados básico. Ele pode ser expandido para incluir funcionalidades adicionais, como interface gráfica ou suporte a banco de dados relacional.
