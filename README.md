# 🏫 Sistema de Gerenciamento Escolar Avançado (SGE)

Este é o meu primeiro projeto de software de grande escopo, desenvolvido de forma totalmente autônoma ao longo de 3 dias intensos de codificação, pesquisa e refinamento lógico. O sistema consiste em um CRUD (Create, Read, Update, Delete) em terminal para controle pedagógico de turmas e alunos.

## 📖 Descrição do Projeto
O sistema foi projetado para simular o controle de uma secretaria escolar. Ele gerencia fichas completas de alunos (dados pessoais e de contato dos responsáveis), registra notas de **3 unidades para 7 disciplinas distintas**, calcula médias ponderadas automaticamente e gera relatórios de desempenho estatísticos da turma.

O grande diferencial técnico do projeto é a incorporação de um algoritmo avançado de ordenação (**Merge Sort**) adaptado para ordenar estruturas complexas de dados (`struct`), permitindo classificar os alunos da maior para a menor média geral de forma extremamente eficiente ($O(n \log n)$).

## 🚀 Funcionalidades Atuais
- **Cadastro Dinâmico:** Registro de alunos com geração automática de matrícula incremental baseada no ano corrente.
- **Matriz de Notas Bidimensional:** Armazenamento individualizado para 7 disciplinas (Português, Matemática, Ciências, História, Geografia, Física e Filosofia) divididas em 3 unidades letivas.
- **Sistema de Busca Inteligente (Polimórfico):** Localização de fichas de alunos por 3 chaves de pesquisa diferentes: Nome Completo, Número de Matrícula ou Nome do Responsável.
- **Lançamento Dinâmico de Notas:** Reutilização das funções de busca para abrir o diário de classe e lançar/atualizar notas de unidades específicas com validação de entrada (apenas notas entre `0` e `10`).
- **Módulos de Relatório e Desempenho:**
  - Visualização de médias individuais por matéria.
  - Exibição de pódio (Top 3 alunos da turma).
  - Estatísticas gerais da turma (média geral escolar, maior nota, menor nota, contagem de alunos acima e abaixo da média estipulada).
- **Ordenação por Divisão e Conquista:** Menu dedicado que reorganiza todo o banco de dados dinâmico de alunos em ordem de desempenho utilizando o **Merge Sort**.

## 🛠️ Tecnologias e Conceitos Aplicados
- **Linguagem:** C++ moderno.
- **Estruturas de Dados:** `std::vector` para armazenamento dinâmico de objetos e `struct` para encapsulamento de dados heterogêneos.
- **Matrizes e Vetores Multidimensionais:** Uso de arrays multidimensionais nativos para mapear a relação Disciplinas x Notas.
- **Algoritmos Avançados:** Implementação customizada do **Merge Sort** aplicando o paradigma de Divisão e Conquista em objetos estruturados.
- **Tratamento de Fluxo e Loops:** Uso estratégico de `std::cin.ignore()`, loops `while(true)` combinados com diretivas `break`/`continue` e menus construídos com `switch-case`.
- **Biblioteca `<cmath>`:** Aplicação de funções matemáticas (`std::round`) para formatação decimal estrita das médias obtidas.

## 📁 Estrutura de Arquivos
- `main.cpp`: Código-fonte centralizado contendo a declaração do tipo estruturado, sub-rotinas de gerenciamento, lógica de ordenação e o laço principal do menu interativo.

## 🚀 Como Executar
1. Certifique-se de possuir um compilador C++ configurado no seu ambiente (g++ recomendável).
2. Realize a compilação via terminal:
   ```bash
   g++ main.cpp -o sistema_escolar
3. Execute o binário gerado:
   ```bash
   ./sistema_escolar

# 👤 Autor
Cauê Vieira Lopes - [Perfil no Git-Hub](https://github.com/cauevieiraLopes)

Este projeto marca o meu primeiro grande marco na programação estruturada em C++, consolidando algumas de minhas habilidades de arquitetar soluções completas ligando lógica, matemática e estruturas de dados.
