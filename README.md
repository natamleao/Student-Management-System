# Student Management System

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-doubly_linked_list-yellow)
![Persistence](https://img.shields.io/badge/storage-binary_file-purple)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Sobre o projeto

> [!NOTE]
> Este projeto implementa um sistema de gerenciamento de alunos utilizando **lista duplamente encadeada em C**, com suporte a **persistência em arquivo binário**.

O sistema permite:

* cadastrar alunos
* remover registros
* buscar informações
* visualizar dados armazenados
* salvar e carregar dados automaticamente de um arquivo `.bin`

Além disso, cada aluno possui um **livro favorito**, armazenado como estrutura associada.

---

> [!IMPORTANT]
> ## Tecnologias utilizadas
>
> * **C (padrão C11)**
> * **GNU Make**
> * Estrutura de dados: **lista duplamente encadeada**
> * Persistência: **arquivo binário (`.bin`)**

---

## Conceitos aplicados

Este projeto cobre conceitos fundamentais e intermediários de C:

* Alocação dinâmica (`malloc`, `free`)
* Gerenciamento manual de memória
* **Deep copy (`strdup`)**
* Manipulação de ponteiros
* Estruturas compostas (`struct`)
* Lista duplamente encadeada
* Encapsulamento com `.h`
* Modularização do código
* Separação entre interface e implementação
* Leitura e escrita de arquivos binários (`fread`, `fwrite`)
* Serialização manual de dados

---

## Funcionalidades

### Cadastrar aluno

Permite inserir um novo aluno informando:

* nome
* idade
* matrícula
* livro favorito:

  * título
  * número de páginas
  * preço

---

### Cancelar matrícula

Remove um aluno com base na matrícula.

---

### Buscar aluno

Busca um aluno específico e exibe:

* dados pessoais
* livro favorito

---

### Atualização de dados

(Estrutura preparada para expansão)

---

### Visualizar quantidade

Exibe o número total de alunos cadastrados.

---

### Listar alunos

Mostra todos os alunos registrados na lista.

---

### Persistência automática

Os dados são:

* carregados ao iniciar o programa (`data/data.bin`)
* salvos após alterações

---

## Estrutura de dados

A lista duplamente encadeada:

```
_begin
  ↓
NULL ← [Aluno 1] ⇄ [Aluno 2] ⇄ [Aluno 3] → NULL
                                            ↑
                                           _end
```

Cada nó:

```c
struct _student{
    char *_name;
    size_t _registration, _age;
    Book *_favorityBook;
    struct _student *_prev, *_next;
};
```

Livro associado:

```c
struct _book{
    char *_title;
    size_t _pagesNumber;
    float _price;
};
```

---

## Formato do arquivo binário

Os dados são armazenados manualmente em formato binário:

```
[len_nome][nome]
[registration][age]
[len_titulo][titulo]
[pages][price]
```

Isso garante:

* maior desempenho
* menor uso de memória
* controle total da serialização

---

## Estrutura do projeto

```
Student-Management-C/
│
├── app/            # Arquivo principal (main)
├── src/            # Implementação (.c)
├── include/        # Interfaces (.h)
├── obj/            # Arquivos objeto (.o)
├── bin/            # Executável final
├── data/           # Persistência (arquivo binário)
│
├── exemples.txt    # Arquivo de exemplos
│
├── Makefile        # Automação da compilação
├── README.md       # Documentação
└── LICENSE         # Licença do projeto
```

---

## Exemplo de execução

Exemplo de execução do programa no terminal:

```
+---------------------------------------------------------------------------+
+-------------------------------- BEM-VINDO --------------------------------+
+---------------------------------------------------------------------------+
+------------------------------ MENU PRINCIPAL -----------------------------+
+---------------------------------------------------------------------------+
+ 1 - MATRÍCULAR ALUNO(A) --------------------------------------------------+
+---------------------------------------------------------------------------+
+ 2 - CANCELAR MATRÍCULA DO ALUNO(A) ---------------------------------------+
+---------------------------------------------------------------------------+
+ 3 - BUSCAR ALUNO(A) ------------------------------------------------------+
+---------------------------------------------------------------------------+
+ 4 - ATUALIZAR DADOS DO ALUNO(A) ------------------------------------------+
+---------------------------------------------------------------------------+
+ 5 - VISUALIZAR NÚMERO DE ALUNOS MATRÍCULADO ------------------------------+
+---------------------------------------------------------------------------+
+ 6 - VISUALIZAR ALUNOS MATRICULADOS ---------------------------------------+
+---------------------------------------------------------------------------+
+ 0 - SAIR -----------------------------------------------------------------+
+---------------------------------------------------------------------------+
+ ESCOLHA UMA OPÇÃO: 
```

---

> [!IMPORTANT]
> ## Requisitos
>
> * GCC ou Clang
> * GNU Make
> * Linux ou macOS

---

## Instalação

Clone o repositório:

```bash
git clone git@github.com:natamleao/Student-Management-System.git
cd Student-Management-System
```

---

## Compilação

Compile o projeto com:

```bash
make
```

---

## Execução

Execute o programa com:

```bash
make run
```

---

## Limpeza do projeto

Remover arquivos compilados:

```bash
make clean
make cleanapp
```
---

## Observações

> [!IMPORTANT]
> Este projeto enfatiza o controle manual de memória e manipulação de estruturas dinâmicas em C.

> [!WARNING]
> O uso incorreto de ponteiros pode causar:
>
> * vazamentos de memória
> * comportamento indefinido

---

> [!WARNING]
> ## Licença
> 
> Este projeto está licenciado sob a **MIT License**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---
