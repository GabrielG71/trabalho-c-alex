# 🤖 Agrupamento K-Means em C

Implementação do algoritmo K-Means para agrupamento de pontos bidimensionais ($X$, $Y$) em C, com visualização automática utilizando **Gnuplot**.

## 🎯 Sobre o Projeto

O projeto **Agrupamento K-Means em C** é uma demonstração prática do famoso algoritmo K-Means, uma técnica de *Machine Learning* não supervisionado. Desenvolvido para um trabalho acadêmico, o código simula a distribuição de uma população de pontos em um plano cartesiano e, em seguida, os agrupa iterativamente em *clusters* (agrupamentos) com base na distância.

O diferencial deste projeto é a automação da visualização: a cada iteração, o programa gera arquivos de dados e chama o **Gnuplot** para produzir gráficos PNG, permitindo o acompanhamento visual do processo de convergência do algoritmo.

## 📋 Funcionalidades

  - **Geração Aleatória de Dados:** O programa define automaticamente uma quantidade aleatória de elementos (**Populacao**) e de centros iniciais (**Agrupamento**), com coordenadas aleatórias em um intervalo de **0.0** a **100.0**.
  - **Estruturas de Dados:** Uso de `structs` para representar pontos (coordenada $X$, $Y$) e os centros dos grupos (**centroids**).
  - **Processo Iterativo (Eras):** Executa o algoritmo por um número definido de iterações (`qtdEras = 10`).
  - **Cálculo de Distância:** Utiliza a distância Euclidiana (função `sqrt` e `pow` da biblioteca `math.h`) para atribuir cada ponto ao centro mais próximo.
  - **Recálculo de Centros:** Atualiza a posição de cada centro de grupo para ser a média dos pontos que foram a ele atribuídos.
  - **Exportação de Dados:** Gera arquivos `.txt` (por iteração) com a posição dos pontos e dos centros.
  - **Visualização Automática:** Chama o **Gnuplot** (via `system()`) a cada iteração para plotar os resultados e salvar como arquivos `.png` (ex: **iteracao\_1.png**).
  - **Gráfico Final:** Gera um gráfico consolidado com o resultado final do agrupamento (**agrupamento\_final.png**).

## ⚙️ Regras do Algoritmo

O K-Means é executado em duas fases repetitivas, baseadas na minimização da distância:

### 1\. Atribuição de Cluster (Assignment Step)

Cada ponto da **Populacao** é atribuído ao centro de **Agrupamento** (centroid) que estiver **mais próximo** dele.

$$\text{Cluster ID} = \underset{i}{\arg\min} (\text{distância}(p, c_i))$$

Onde $p$ é o ponto e $c_i$ é o centro do cluster $i$.

### 2\. Atualização de Centros (Update Step)

A posição de cada centro de **Agrupamento** é recalculada, tornando-se o **ponto médio** de todos os pontos que foram atribuídos a ele na etapa anterior.

$$c_i = \frac{1}{|C_i|} \sum_{p \in C_i} p$$

Onde $C_i$ é o conjunto de todos os pontos atribuídos ao cluster $i$.

## 🚀 Como Executar

Para compilar e rodar este projeto, você precisará ter o compilador **GCC** (ou similar) e o utilitário de plotagem **Gnuplot** instalados no seu sistema.

1.  **Compile o programa:**

    ```bash
    gcc main.c -o kmeans -lm
    ```

    *O flag **-lm** é essencial, pois o código utiliza funções matemáticas (como `sqrt` e `pow`) da biblioteca `math.h`.*

2.  **Execute o programa:**

    ```bash
    ./kmeans
    ```

3.  **Verifique os resultados:**

    Após a execução, a pasta do projeto será preenchida com os seguintes arquivos:

      - Arquivos `.txt` contendo os dados (população e centroids) de cada iteração.
      - Arquivos `.png` (ex: **iteracao\_1.png**, **iteracao\_2.png**) mostrando a evolução do agrupamento.
      - O arquivo **agrupamento\_final.png** com o resultado da última iteração.

## 🏗️ Estrutura do Código

**Structs e Funções Chave:**

| Nome da Estrutura/Função | Descrição |
| :--- | :--- |
| `Populacao` | Struct: Contém as coordenadas $x$, $y$ e o `cluster_id` do ponto. |
| `Agrupamento` | Struct: Contém as coordenadas $x$, $y$ do centro do grupo (centroid). |
| `numberDouble()` | Gera um número `double` aleatório dentro do **INTERVALO\_MAX** definido. |
| `main()` | Contém o loop principal (iterações) que executa a atribuição e a atualização dos centroids. |
| `system(gnuplot_command)` | Executa a string de comando para chamar o **Gnuplot** e gerar as imagens. |

## 📂 Estrutura de Arquivos Gerados

Após a execução, você terá uma estrutura semelhante a esta:

```
projeto-k-means-c/
├── main.c           # Código-fonte principal
├── README.md        # Este documento
├── populacao_agrupada_iteracao_1.txt
├── centroids_iteracao_1.txt
├── iteracao_1.png   # Gráfico da primeira iteração
├── populacao_agrupada_iteracao_10.txt
├── centroids_iteracao_10.txt
├── iteracao_10.png  # Gráfico da última iteração
└── agrupamento_final.png  # Resultado consolidado
```

## ⚠️ Dependência

O programa tem uma dependência **obrigatória** do utilitário de plotagem **Gnuplot** para gerar as imagens (`.png`). Certifique-se de que ele esteja instalado e acessível via linha de comando no seu ambiente.

-----

**Desenvolvido por:** Daniel Zanchetta, Gabriel Gonçalves, Rafael Fontes. <br>
**Instituição:** FATEC Ourinhos - ADS 2º Semestre  
**Projeto:** Implementação do Algoritmo K-Means em C

*"Entendendo a convergência dos dados, passo a passo."* 📊
