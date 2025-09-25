#include <stdio.h>
#include <math.h>
#include <string.h>

int validarIntervaloFloat(float v, float min, float max);

int validarIntervaloInt(int v, int min, int max);

float calcularMedia(float n1, float n2, float n3);

float aplicarBonus(float media, int presenca, int extra);

void classificar(float media, float n1, float n2, float n3, int presenca);

int main() {
    char nome[31];
    float n1, n2, n3, media;
    int presenca, trabalhoExtra;

    //Input das informações
    printf("Digite o nome do aluno:");
    fgets(nome, 31, stdin);
    nome[strcspn(nome, "\n")] = 0;
    if (strlen(nome) == 0) {
        printf("Nome do aluno nao pode ser vazio.\n");
        return 1;
    }
    printf("Nota 1:");
    scanf("%f", &n1);
    if (validarIntervaloFloat(n1,0.0,10.0) == 1){
        return 1;
    }

    printf("Nota 2:");
    scanf("%f", &n2);
    if (validarIntervaloFloat(n2,0.0,10.0) == 1){
        return 1;
    }

    printf("Nota 3:");
    scanf("%f", &n3);
    if (validarIntervaloFloat(n3,0.0,10.0) == 1){
        return 1;
    }

    printf("Presenca (%):");
    scanf("%d", &presenca);
    if (validarIntervaloInt(presenca,0,100) == 1){
        return 1;
    }

    printf("Trabalho extra (0-100):");
    scanf("%d", &trabalhoExtra);
    if (validarIntervaloInt(trabalhoExtra,0,100) == 1){
        return 1;
    }

    media = calcularMedia(n1, n2, n3);

    //Output das informações

    printf("Aluno: %s", nome);
    printf("Notas: N1=%.2f N2=%.2f N3=%.2f\n", n1, n2, n3);
    printf("Presenca: %d%\n", presenca);
    printf("Trabalho extra (0-100): %d\n", trabalhoExtra);
    printf("Media (antes do bonus): %.2f\n", media);
    printf("Media (final): %.2f\n", aplicarBonus(media, presenca, trabalhoExtra));
    printf("Situacao: ");
    classificar(aplicarBonus(media, presenca, trabalhoExtra), n1, n2, n3, presenca);

}

int validarIntervaloFloat(float v, float min, float max) {
    if (v >= min && v <= max) {
        return 0;
    }
    else {
        printf("Valor invalido\n");
        return 1;
    }
}

int validarIntervaloInt(int v, int min, int max) {
    if (v >= min && v <= max) {
        return 0;
    }
    else {
        printf("Valor invalido\n");
        return 1;
    }
}

float calcularMedia(float n1, float n2, float n3) {
    return(0.30 * n1) + (0.30 * n2) + (0.40 * n3);
}

float aplicarBonus(float media, int presenca, int extra) {
    if (presenca>=90 && extra >= 70) {
        return fmin(media+0.5,10.0);
    }
    else {
        return media;
    }
}

void classificar(float media, float n1, float n2, float n3, int presenca) {
    if (n1 < 3.0 || n2 < 3.0 || n3 < 3.0 || presenca < 75) {
        printf("Reprovado\n");
    }
    else if (media >= 7.0) {
        printf("Aprovado\n");
    }
    else if (media < 7.0 && media >= 5) {
        printf("Recuperacao\n");
    }
    else{
        printf("Reprovado\n");
    }
}