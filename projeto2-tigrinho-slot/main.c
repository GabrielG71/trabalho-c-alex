#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int apostar(int saldo) {
    int aposta;

    printf("\nSaldo atual: %d créditos\n", saldo);
    printf("Digite sua aposta (1-10, 0 para sair): ");
    scanf("%d", &aposta);

    while (aposta < 0 || aposta > 10 || (aposta > saldo && aposta != 0)) {
        if (aposta > saldo && aposta != 0) {
            printf("Aposta maior que o saldo disponível! Você é burro por acaso?: ");
        } else if (aposta < 0 || aposta > 10) {
            printf("Aposta deve estar entre 1-10 créditos ou 0 para sair. Você é burro por acaso?\n Tente Novamente: ");
        }
        scanf("%d", &aposta);
    }

    return aposta;
}

void girar(int roleta[]) {
    for (int i = 0; i < 3; i++) {
        roleta[i] = rand() % 6;
    }
}

int calcularPremio(int roleta[], int aposta) {
    int premio = 0;

    if (roleta[0] == roleta[1] && roleta[1] == roleta[2]) {
        premio = 5 * aposta;
    }
    else if (roleta[0] == roleta[1] || roleta[0] == roleta[2] || roleta[1] == roleta[2]) {
        premio = 2 * aposta;
    }

    return premio;
}

void obterSimbolo(int numero, char simbolo[]) {
    switch (numero) {
        case 0: sprintf(simbolo, "Cereja"); break;
        case 1: sprintf(simbolo, "Limão"); break;
        case 2: sprintf(simbolo, "Sino"); break;
        case 3: sprintf(simbolo, "Estrela"); break;
        case 4: sprintf(simbolo, "Trevo"); break;
        case 5: sprintf(simbolo, "Tigre"); break;
    }
}

void exibirResultado(int roleta[], int premio, int aposta) {
    char simbolo1[20], simbolo2[20], simbolo3[20];

    obterSimbolo(roleta[0], simbolo1);
    obterSimbolo(roleta[1], simbolo2);
    obterSimbolo(roleta[2], simbolo3);

    printf("\n[%s][%s][%s]\n", simbolo1, simbolo2, simbolo3);
    printf("Números sorteados: [%d][%d][%d]\n", roleta[0], roleta[1], roleta[2]);

    if (roleta[0] == roleta[1] && roleta[1] == roleta[2]) {
        printf("JACKPOT, eita porra! 3 símbolos iguais → Você ganhou %d créditos!\n", premio);
    } else if (roleta[0] == roleta[1] || roleta[0] == roleta[2] || roleta[1] == roleta[2]) {
        printf("2 símbolos iguais, ta podendo em → Você ganhou %d créditos!\n", premio);
    } else {
        printf("Nenhum símbolo igual kkkkkkkkkkkkk → Você perdeu %d créditos!\n", aposta);
    }
}

void adicionarHistorico(int historico[][4], int* totalJogadas, int roleta[], int premio) {
    if (*totalJogadas < 10) {
        historico[*totalJogadas][0] = roleta[0];
        historico[*totalJogadas][1] = roleta[1];
        historico[*totalJogadas][2] = roleta[2];
        historico[*totalJogadas][3] = premio;
        (*totalJogadas)++;
    } else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 4; j++) {
                historico[i][j] = historico[i + 1][j];
            }
        }
        historico[9][0] = roleta[0];
        historico[9][1] = roleta[1];
        historico[9][2] = roleta[2];
        historico[9][3] = premio;
    }
}

void exibirHistorico(int historico[][4], int totalJogadas) {
    if (totalJogadas == 0) {
        printf("\nNenhuma jogada foi realizada.\n");
        return;
    }

    printf("\n📊 HISTÓRICO DAS ÚLTIMAS %d JOGADAS:\n", totalJogadas > 10 ? 10 : totalJogadas);
    printf("----------------------------------------------\n");

    int inicio = totalJogadas > 10 ? 0 : 0;
    int fim = totalJogadas > 10 ? 10 : totalJogadas;

    for (int i = inicio; i < fim; i++) {
        char simbolo1[20], simbolo2[20], simbolo3[20];
        obterSimbolo(historico[i][0], simbolo1);
        obterSimbolo(historico[i][1], simbolo2);
        obterSimbolo(historico[i][2], simbolo3);

        printf("Jogada %d: [%s][%s][%s] → ", i + 1, simbolo1, simbolo2, simbolo3);
        if (historico[i][3] > 0) {
            printf("Ganhou safado(a) %d créditos\n", historico[i][3]);
        } else {
            printf("Perdeu a aposta kkkkkkkkkkkkkkkkk\n");
        }
    }
    printf("----------------------------------------------\n");
}

int main() {
    int saldo = 100;
    int aposta;
    int roleta[3];
    int premio;

    int historico[10][4];
    int totalJogadas = 0;

    srand(time(NULL));

    printf("BEM-VINDO AO TIGRINHO!\n");
    printf("Saldo inicial: %d créditos\n", saldo);
    printf("\nSímbolos disponíveis:\n");
    printf("0=Cereja | 1=Limão | 2=Sino | 3=Estrela | 4=Trevo | 5=Tigre\n");
    printf("\nRegras de vitória:\n");
    printf("• 3 símbolos iguais = 5x a aposta\n");
    printf("• 2 símbolos iguais = 2x a aposta\n");
    printf("• Nenhum igual = perde a aposta\n");

    while (saldo > 0) {
        aposta = apostar(saldo);

        if (aposta == 0) {
            printf("\nJogo encerrado. Acabou paezão!\n");
            break;
        }

        saldo -= aposta;

        girar(roleta);

        premio = calcularPremio(roleta, aposta);

        saldo += premio;

        exibirResultado(roleta, premio, aposta);

        adicionarHistorico(historico, &totalJogadas, roleta, premio);

        printf("Saldo atual: %d créditos\n", saldo);

        if (saldo == 0) {
            printf("\n💸 Seu saldo zerou! Otario kkkkkkkkkkk Game Over!\n");
            break;
        }
    }

    exibirHistorico(historico, totalJogadas);

    printf("\nSaldo final: %d créditos\n", saldo);
    if (saldo > 100) {
        printf("Parabéns! Você terminou com lucro de %d créditos, sortudo da porra!\n", saldo - 100);
    } else if (saldo < 100) {
        printf("Você perdeu seu merda kkkkkkkkkkkkkkkk%d créditos.\n", 100 - saldo);
    } else {
        printf("Você terminou com o mesmo saldo inicial, ta suave carai!\n");
    }

    return 0;
}