🎓 Calculadora de Média Acadêmica
Sistema robusto para cálculo de médias de alunos, desenvolvido em C, com ponderação de notas, sistema de bônus e regras de classificação claras.

🎯 Sobre o Projeto
A Calculadora de Média Acadêmica é uma ferramenta projetada para automatizar o processo de avaliação de alunos, conforme especificado no trabalho T1 da FATEC Ourinhos. Desenvolvida como um exercício prático em C, o programa calcula a média ponderada, aplica bônus por bom desempenho e determina a situação final do aluno (Aprovado, Recuperação ou Reprovado) com base em regras de negócio bem definidas.

📋 Funcionalidades

Coleta de dados: Recebe nome, 3 notas, percentual de presença e pontuação de trabalho extra.

Cálculo de média ponderada: Aplica pesos diferentes para cada nota, conforme a regra de negócio.

Sistema de bônus: Adiciona 0.5 ponto à média para alunos com alta frequência e bom desempenho em trabalhos extras.

Validação de entradas: Garante que todos os dados inseridos estejam dentro dos intervalos permitidos e que o nome do aluno não seja vazio.

Classificação automática: Determina a situação do aluno com base em múltiplos critérios, incluindo regras de corte por nota mínima e frequência.

Interface clara: Exibe um relatório final completo com todos os dados e o resultado.

📊 Regras de Negócio
O sistema opera com base nas seguintes regras para avaliação:

1. Cálculo da Média
A média é calculada com base nos seguintes pesos:

Nota 1: 30%

Nota 2: 30%

Nota 3: 40%

Fórmula: `

M 
e
ˊ
 dia=(N1⋅0.3)+(N2⋅0.3)+(N3⋅0.4) 

2. Sistema de Bônus
Um bônus de 

+0.5 ponto é aplicado à média se o aluno atender a ambos os critérios:

Presença: igual ou superior a 90% 

Trabalho Extra: pontuação igual ou superior a 70 

Observação: A média final, mesmo com bônus, é limitada a 10.0. 

3. Critérios de Classificação (Seção Atualizada)
Primeiro, as regras de corte são verificadas:

Reprovado por nota minima: Se qualquer uma das notas (N1, N2 ou N3) for menor que 3.0.

Reprovado por frequencia: Se a presença for inferior a 75%.

Se nenhuma regra de corte for aplicada, a classificação final é baseada na média:

Aprovado: Média final superior a 7.0.

Recuperação: Média final entre 5.0 (incluso) e 7.0 (incluso).

Reprovado: Média final inferior a 5.0.

🚀 Como Usar
Compile o programa:

Bash

gcc main.c -o avaliador
Execute o programa:

Bash

./avaliador
Instruções:

Digite o nome do aluno.

Informe as três notas (de 0.0 a 10.0).

Insira o percentual de presença (de 0 a 100).

Forneça a pontuação do trabalho extra (de 0 a 100).

O sistema exibirá o relatório completo.

📖 Exemplo de Execução (Seção Atualizada e Expandida)

Exemplo 1: Aluno Aprovado com Bônus 

Digite o nome do aluno:Maria
Nota 1: 6.5
Nota 2: 7.0
Nota 3: 8.0
Presenca (%): 92
Trabalho extra (0-100): 80
Aluno: Maria
Notas: N1=6.50 N2=7.00 N3=8.00
Presenca: 92%
Trabalho extra: 80
Media (antes do bonus): 7.35
Media (final): 7.85
Situacao: Aprovado

Exemplo 2: Aluno Reprovado por Nota Mínima 

Digite o nome do aluno: João
Nota 1: 2.9
Nota 2: 8.0
Nota 3: 9.0
Presenca (%): 95
Trabalho extra (0-100): 100
Aluno: João
Notas: N1=2.90 N2=8.00 N3=9.00
Presenca: 95%
Trabalho extra: 100
Media (antes do bonus): 7.67
Media (final): 8.17
Situacao: Reprovado por nota minima

Exemplo 3: Aluno Reprovado por Frequência 

Digite o nome do aluno: Ana
Nota 1: 7.0
Nota 2: 6.0
Nota 3: 6.0
Presenca (%): 70
Trabalho extra (0-100): 65
Aluno: Ana
Notas: N1=7.00 N2=6.00 N3=6.00
Presenca: 70%
Trabalho extra: 65
Media (antes do bonus): 6.30
Media (final): 6.30
Situacao: Reprovado por frequencia
🔧 Recursos Especiais
🛡️ Validação Robusta (Seção Atualizada)
Impede a inserção de notas, presença ou trabalho extra fora do intervalo válido.

Garante que o 

nome do aluno não pode ser vazio, assegurando a integridade dos dados.

Exibe uma mensagem de erro e encerra o programa caso uma entrada inválida seja detectada.