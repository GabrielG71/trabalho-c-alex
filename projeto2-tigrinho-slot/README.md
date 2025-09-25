# 🎰 Tigrinho Slot Machine

Simulador de caça-níquel desenvolvido em C com personalidade brasileira e linguagem descontraída.

## 🎯 Sobre o Projeto

O **Tigrinho** é um simulador de caça-níquel que traz toda a emoção dos cassinos com um toque brasileiro único! Desenvolvido para exercitar conceitos de programação em C, o jogo oferece uma experiência divertida e envolvente com comentários hilários e reações autênticas.

## 📋 Funcionalidades

- **Saldo inicial:** 100 créditos para começar a diversão
- **Sistema de apostas:** De 1 a 10 créditos por rodada
- **6 símbolos únicos:** Cereja, Limão, Sino, Estrela, Trevo e Tigre
- **Sistema de prêmios:** Multiplicadores baseados em combinações
- **Histórico inteligente:** Últimas 10 jogadas salvas automaticamente
- **Validação esperta:** Impede apostas inválidas com humor brasileiro
- **Interface divertida:** Comentários e reações hilárias

## 🎲 Símbolos e Valores

| Número | Símbolo |
| ------ | ------- |
| 0      | Cereja  |
| 1      | Limão   |
| 2      | Sino    |
| 3      | Estrela |
| 4      | Trevo   |
| 5      | Tigre   |

## 🏆 Sistema de Prêmios

- **🎯 JACKPOT (3 iguais):** 5x a aposta - _"JACKPOT, eita porra!"_
- **🎲 Dupla (2 iguais):** 2x a aposta - _"ta podendo em"_
- **💸 Nada igual:** Perde a aposta - _"kkkkkkkkkkkkk"_

## 🚀 Como Jogar

1. **Compile o programa:**

   ```bash
   gcc main.c -o main
   ```

2. **Execute o jogo:**

   ```bash
   ./main
   ```

3. **Instruções do jogo:**
   - Você começa com 100 créditos
   - Digite o valor da aposta (1-10)
   - Veja os símbolos girarem
   - Comemore os ganhos ou ria das perdas
   - Digite 0 para sair quando quiser

## 📖 Exemplo de Execução

```
BEM-VINDO AO TIGRINHO!
Saldo inicial: 100 créditos

Símbolos disponíveis:
0=Cereja | 1=Limão | 2=Sino | 3=Estrela | 4=Trevo | 5=Tigre

Regras de vitória:
• 3 símbolos iguais = 5x a aposta
• 2 símbolos iguais = 2x a aposta
• Nenhum igual = perde a aposta

Saldo atual: 100 créditos
Digite sua aposta (1-10, 0 para sair): 10

[Tigre][Tigre][Tigre]
Números sorteados: [5][5][5]
JACKPOT, eita porra! 3 símbolos iguais → Você ganhou 50 créditos!
Saldo atual: 140 créditos

Digite sua aposta (1-10, 0 para sair): 0
Jogo encerrado. Acabou paezão!

📊 HISTÓRICO DAS ÚLTIMAS 1 JOGADAS:
----------------------------------------------
Jogada 1: [Tigre][Tigre][Tigre] → Ganhou safado(a) 50 créditos
----------------------------------------------

Saldo final: 140 créditos
Parabéns! Você terminou com lucro de 40 créditos, sortudo da porra!
```

## 🔧 Recursos Especiais

### 🛡️ Validação Inteligente

- Impede apostas maiores que o saldo
- Bloqueia valores fora do intervalo (1-10)
- Mensagens divertidas para entradas inválidas

### 📊 Histórico Automático

- Salva automaticamente as últimas 10 jogadas
- Exibe símbolos e resultados de cada rodada
- Sistema de rotação quando passa de 10 jogadas

### 🎭 Personalidade Brasileira

- Comentários hilários em português
- Reações autênticas para vitórias e derrotas
- Linguagem descontraída e divertida

## 🏗️ Estrutura do Código

**Funções principais:**

- `int apostar(int saldo)` - Gerencia apostas com validação
- `void girar(int roleta[])` - Gera números aleatórios
- `int calcularPremio(int roleta[], int aposta)` - Calcula prêmios
- `void obterSimbolo(int numero, char simbolo[])` - Converte números em símbolos
- `void exibirResultado(int roleta[], int premio, int aposta)` - Mostra resultados
- `void adicionarHistorico()` - Gerencia histórico de jogadas
- `void exibirHistorico()` - Exibe últimas jogadas

## 📂 Estrutura do Projeto

```
projeto2-tigrinho-slot/
├── main.c          # Código-fonte completo
└── README.md       # Esta documentação
```

## ⚙️ Tecnologias

- **Linguagem:** C (padrão ANSI)
- **Bibliotecas:** `stdio.h`, `stdlib.h`, `time.h`
- **Compilador:** GCC (ou qualquer compilador C)
- **Plataforma:** Windows, Linux, macOS

## 🎮 Dicas Para Jogar

- **Comece com apostas baixas** para conhecer o jogo
- **Observe o histórico** para ver padrões (ou não!)
- **Defina um limite** antes de começar a jogar
- **Divirta-se** com os comentários hilários do jogo

---

**Desenvolvido por:** Gabriel Gonçalves, Rafael Fontes, Daniel Zanchetta  
**Instituição:** FATEC Ourinhos - ADS 2º Semestre  
**Projeto:** Simulador de Caça-Níquel em C

_"No Tigrinho, a diversão é garantida, mesmo quando você perde!"_ 🐅
