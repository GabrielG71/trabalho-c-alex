# 🎓 Calculadora de Média Acadêmica

Sistema para cálculo de médias de alunos, desenvolvido em C, com ponderação de notas, sistema de bônus e regras de classificação claras.

## 🎯 Sobre o Projeto

A **Calculadora de Média Acadêmica** é uma ferramenta projetada para automatizar o processo de avaliação de alunos. Desenvolvida como um exercício prático em C, o programa calcula a média ponderada, aplica bônus por bom desempenho e determina a situação final do aluno (Aprovado, Recuperação ou Reprovado) com base em regras de negócio bem definidas.

## 📋 Funcionalidades

  - **Coleta de dados:** Recebe nome, 3 notas, percentual de presença e pontuação de trabalho extra.
  - **Cálculo de média ponderada:** Aplica pesos diferentes para cada nota.
  - **Sistema de bônus:** Adiciona 0.5 ponto à média para alunos com alta frequência e bom desempenho em trabalhos extras.
  - **Validação de entradas:** Garante que todos os dados inseridos estejam dentro dos intervalos permitidos (notas de 0-10, presença de 0-100%).
  - **Classificação automática:** Determina a situação do aluno (Aprovado, Recuperação, Reprovado) com base em múltiplos critérios.
  - **Interface clara:** Exibe um resumo completo com todos os dados e o resultado final.

## 📊 Regras de Negócio

O sistema opera com base nas seguintes regras para avaliação:

### 1\. Cálculo da Média

A média final é calculada com base nos seguintes pesos:

  - **Nota 1:** 30%
  - **Nota 2:** 30%
  - **Nota 3:** 40%

Fórmula: `Média = (N1 * 0.3) + (N2 * 0.3) + (N3 * 0.4)`

### 2\. Sistema de Bônus

Um bônus de **+0.5 ponto** é aplicado à média se o aluno atender a **ambos** os critérios:

  - **Presença:** igual ou superior a 90%
  - **Trabalho Extra:** pontuação igual ou superior a 70

*Observação: A média final, mesmo com bônus, é limitada a 10.0.*

### 3\. Critérios de Classificação

  - **Reprovado (imediatamente):**

      - Se qualquer uma das notas (N1, N2 ou N3) for **menor que 3.0**.
      - OU se a **presença for inferior a 75%**.

  - **Aprovado:**

      - Se a média final for **igual ou superior a 7.0** (e não se enquadrar nos critérios de reprovação imediata).

  - **Recuperação:**

      - Se a média final for **entre 5.0 e 6.99**.

  - **Reprovado (por média):**

      - Se a média final for **inferior a 5.0**.

## 🚀 Como Usar

1.  **Compile o programa:**

    ```bash
    gcc main.c -o main
    ```

2.  **Execute o programa:**

    ```bash
    ./main
    ```

3.  **Instruções:**

      - Digite o nome do aluno.
      - Informe as três notas (de 0.0 a 10.0).
      - Insira o percentual de presença (de 0 a 100).
      - Forneça a pontuação do trabalho extra (de 0 a 100).
      - O sistema exibirá o relatório completo.

## 📖 Exemplo de Execução

**Exemplo 1: Aluno Aprovado com Bônus**

```
Digite o nome do aluno:Rafael Fontes
Nota 1:8.0
Nota 2:9.5
Nota 3:9.0
Presenca (%):95
Trabalho extra (0-100):80
Aluno: Rafael Fontes
Notas: N1=8.00 N2=9.50 N3=9.00
Presenca: 95%
Trabalho extra (0-100): 80
Media (antes do bonus): 8.85
Media (final): 9.35
Situacao: Aprovado
```

**Exemplo 2: Aluna em Recuperação sem Bônus**

```
Digite o nome do aluno:Ana Clara
Nota 1:5.0
Nota 2:6.5
Nota 3:7.0
Presenca (%):80
Trabalho extra (0-100):60
Aluno: Ana Clara
Notas: N1=5.00 N2=6.50 N3=7.00
Presenca: 80%
Trabalho extra (0-100): 60
Media (antes do bonus): 6.25
Media (final): 6.25
Situacao: Recuperacao
```

## 🔧 Recursos Especiais

### 🛡️ Validação Robusta

  - Impede a inserção de notas ou percentuais fora do intervalo válido.
  - Garante a integridade dos dados antes de realizar os cálculos.
  - Exibe a mensagem "Valor invalido" e encerra o programa se uma entrada incorreta for detectada.

### 🧮 Lógica de Ponderação e Bônus

  - O sistema utiliza uma média ponderada que valoriza mais a última avaliação, um cenário comum em muitas instituições.
  - O mecanismo de bônus incentiva o bom desempenho contínuo e a assiduidade.

## 🏗️ Estrutura do Código

**Funções principais:**

  - `int validarIntervaloFloat(float v, float min, float max)`: Valida se um valor float está dentro de um intervalo.
  - `int validarIntervaloInt(int v, int min, int max)`: Valida se um valor inteiro está dentro de um intervalo.
  - `float calcularMedia(float n1, float n2, float n3)`: Calcula a média ponderada das notas.
  - `float aplicarBonus(float media, int presenca, int extra)`: Verifica e aplica o bônus de 0.5 ponto.
  - `void classificar(float media, float n1, float n2, float n3, int presenca)`: Analisa todos os critérios e imprime a situação final do aluno.

## 📂 Estrutura do Projeto

```
projeto1-media-alunos/
├── main.c      # Código-fonte completo do programa
└── README.md   # Esta documentação
```

## ⚙️ Tecnologias

  - **Linguagem:** C (padrão ANSI)
  - **Bibliotecas:** `stdio.h`, `math.h`, `string.h`
  - **Compilador:** GCC (ou qualquer compilador C padrão)
  - **Plataforma:** Windows, Linux, macOS

-----

**Desenvolvido por:** Gabriel Gonçalves, Rafael Fontes, Daniel Zanchetta
**Instituição:** FATEC Ourinhos - ADS 2º Semestre  
**Projeto:** Calculadora de Média Acadêmica em C

*"A ferramenta ideal para transformar notas em resultados claros e precisos."* 📈
