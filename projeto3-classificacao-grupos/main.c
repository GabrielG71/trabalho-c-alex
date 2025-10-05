#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INTERVALO_MAX 100.0

//declaração da função para numero aleatorio
double numberDouble ();

// Definição do struct para o array da população
typedef struct  {
    double x;
    double y;
    int cluster_id;
} Populacao;

// Definição do struct para o agrupamento
typedef struct  {
    double x;
    double y;
} Agrupamento;



int main(void) {
    srand(time(NULL));

    int qtdEras = 10;

    char nome_populacao[100];
    char nome_centroids[100];
    char gnuplot_command[512];

    //Gera uma quantidade aleatoria entre 1 e 100
    int qtdElementos = (rand() % 100    ) + 1;
    int qtdAgrupamentos = (rand() % 100) + 1;

    //Define o Array de struct
    Agrupamento agrupamento[qtdAgrupamentos];
    Populacao populacao[qtdElementos];

    // Inicializa os grupos.
    for (int i = 0; i < qtdAgrupamentos; i++) {
        agrupamento[i].x = numberDouble();
        agrupamento[i].y = numberDouble();
    }
    for (int i = 0; i < qtdElementos; i++) {
        populacao[i].x = numberDouble();
        populacao[i].y = numberDouble();
    }

    //Processo iterativo
    for (int iteracao = 1; iteracao <= qtdEras; iteracao++) {
        printf("\n--- Iteracao %d ---\n", iteracao);


        for (int e = 0; e < qtdElementos; e++) { // "e" de externo para correr toda a população
            double menorDistancia = 1000;
            int centroProximo;

            for (int i = 0; i < qtdAgrupamentos; i++) { // "i" de interno para correr todos os centros
                double distancia = sqrt( pow( (populacao[e].x - agrupamento[i].x ), 2) + pow( (populacao[e].y - agrupamento[i].y ),2 ));
                if (distancia < menorDistancia) {
                    menorDistancia = distancia;
                    centroProximo = i;
                }
            }
            populacao[e].cluster_id = centroProximo;
        }

        for (int i = 0; i < qtdAgrupamentos; i++) {
            double somaX = 0.0;
            double somaY = 0.0;
            int count = 0;

            for (int e = 0; e < qtdElementos; e++) {
                if (populacao[e].cluster_id == i) {
                    somaX += populacao[e].x;
                    somaY += populacao[e].y;
                    count++;
                }
            }

            if (count > 0) {
                agrupamento[i].x = somaX / count;
                agrupamento[i].y = somaY / count;
            }
        }

    // Cria o nome do arquivo para esta iteração
    sprintf(nome_populacao, "populacao_agrupada_iteracao_%d.txt", iteracao);
    sprintf(nome_centroids, "centroids_iteracao_%d.txt", iteracao);

    // 2. Escrevendo o arquivo da POPULAÇÃO
    FILE *fp_populacao = fopen(nome_populacao, "w");
    if (fp_populacao == NULL) {
        perror("Erro ao abrir arquivo de populacao.");
        return 1; // Encerra o programa em caso de erro
    }

    for (int e = 0; e < qtdElementos; e++) {
        // Escreve X, Y e o ID do Grupo (colunas 1, 2, 3)
        // O cluster_id deve ser >= 1 para cores no gnuplot
        fprintf(fp_populacao, "%.2f %.2f %d\n", populacao[e].x, populacao[e].y, populacao[e].cluster_id + 1);
    }
    fclose(fp_populacao);


    // 3. Escrevendo o arquivo dos CENTROIDS
    FILE *fp_centroids = fopen(nome_centroids, "w");
    if (fp_centroids == NULL) {
        perror("Erro ao abrir arquivo de centroids.");
        return 1; // Encerra o programa em caso de erro
    }

    for (int i = 0; i < qtdAgrupamentos; i++) {
        // Escreve X e Y (colunas 1, 2)
        fprintf(fp_centroids, "%.2f %.2f\n", agrupamento[i].x, agrupamento[i].y);
    }
    fclose(fp_centroids);


    // 4. CHAMANDO GNUPLOT (Automação da Plotagem)
    // A sua string de comando deve ser criada aqui
    snprintf(gnuplot_command, sizeof(gnuplot_command),
        "gnuplot -e \"set terminal png size 800,600; set output 'iteracao_%d.png'; "
        "set title 'Agrupamento Bidimensional - Iteracao %d'; set xlabel 'X'; set ylabel 'Y'; set grid; "
        "set key outside; set palette defined (1 'red', 2 'blue', 3 'green'); "
        "plot '%s' using 1:2:3 with points palette pointtype 7 pointsize 1.5 title 'Populacao', "
        "'%s' using 1:2 with points pointtype 4 pointsize 2 lc rgb 'black' title 'Centroids';\"",
        iteracao, iteracao, nome_populacao, nome_centroids);

    system(gnuplot_command);

    }
    //Fim iteração

    // Bloco FINAL: Geração do agrupamento_final.png
    printf("\n--- Geracao do Grafico Final ---\n");

    // Reusa as variáveis nome_populacao e nome_centroids da ÚLTIMA iteração
    // Mas gera um novo comando Gnuplot para o arquivo final.

    // 1. Definição do nome do arquivo (muda a saída do Gnuplot)
    // Podemos usar o nome do arquivo da última iteração, já que os dados são os finais
    // O Gnuplot usará esses dados para plotar o resultado final.

    // 2. CHAMANDO GNUPLOT PARA O RESULTADO FINAL
    // Observe a mudança no set output e no set title
    snprintf(gnuplot_command, sizeof(gnuplot_command),
        "gnuplot -e \"set terminal png size 800,600; set output 'agrupamento_final.png'; "
        "set title 'Agrupamento Bidimensional Final'; set xlabel 'X'; set ylabel 'Y'; set grid; "
        "set key outside; set palette defined (1 'red', 2 'blue', 3 'green', 4 'orange', 5 'purple'); "
        "plot '%s' using 1:2:3 with points palette pointtype 7 pointsize 1.5 title 'Populacao', "
        "'%s' using 1:2 with points pointtype 4 pointsize 2 lc rgb 'black' title 'Centroids';\"",
        nome_populacao, nome_centroids);

    system(gnuplot_command);
}

//função para número aleatório
double numberDouble () {
    return ((double)rand() / RAND_MAX) * INTERVALO_MAX;
}

