#include <stdio.h>
#include <string.h> // Necessário para strcmp

int main()
{
    char escolha;
    int opcao, todas;
    char formula[20]; // Declaração da variável para a fórmula

    printf("Voce vai querer uma tabela verdade com V ou F?\n");
    printf("Escreva S (sim) ou N (nao): \n");
    scanf(" %c", &escolha);

    if (escolha == 'S' || escolha == 's')
    {
        printf("Você escolheu a tabela verdade com V ou F.\n");

        // Pergunta qual proposição lógica o usuário deseja calcular
        printf("Escolha a proposiçao lógica que deseja calcular:\n");
        printf("1 - P\n");
        printf("2 - P or Q\n");
        printf("3 - P and Q\n");
        printf("4 - P iff Q (P se somente se Q)\n");
        printf("5 - ~P\n");
        printf("6 - ~Q\n");
        printf("7 - ~P and ~Q\n");
        printf("8 - ~P or ~Q\n");
        printf("9 - ~P then ~Q\n");
        printf("10 - ~P iff ~Q (~P se somente se ~Q)\n");
        printf("11 - Todos\n");
        printf("Digite o numero da formula que deseja ver: ");
        scanf(" %d", &opcao);

        if (opcao == 11)
        {
            // Exibe todas as proposições lógicas na tabela
            printf("+---+---+---+---+---+-------+-----+-----+-------+-------+-------+---------+\n");
            printf("| P | Q | P+Q | P*Q | P<=>Q | ~P  | ~Q  | ~P*~Q | ~P+~Q | ~P->~Q| ~P<=>~Q |\n");
            printf("+---+---+-----+-----+-------+-----+-----+-------+-------+-------+---------+\n");

            for (int P = 0; P <= 1; P++)
            {
                for (int Q = 0; Q <= 1; Q++)
                {
                    printf("| %c | %c |  %c  |  %c  |   %c   |  %c  |  %c  |   %c   |   %c   |   %c   |    %c    |\n",
                           (P == 1) ? 'V' : 'F',
                           (Q == 1) ? 'V' : 'F',
                           (P || Q) ? 'V' : 'F',       // P+Q
                           (P && Q) ? 'V' : 'F',       // P*Q
                           (P == Q) ? 'V' : 'F',       // P<=>Q
                           (!P) ? 'V' : 'F',           // ~P
                           (!Q) ? 'V' : 'F',           // ~Q
                           ((!P) && (!Q)) ? 'V' : 'F', // ~P*~Q
                           ((!P) || (!Q)) ? 'V' : 'F', // ~P+~Q
                           ((!P) || Q) ? 'V' : 'F',    // ~P->~Q
                           ((!P == !Q) ? 'V' : 'F')    // ~P<=>~Q
                    );
                }
            }

            printf("+---+---+-----+-----+-------+-----+-----+-------+-------+-------+---------+\n");
        }
        else
        {
            // Cabeçalho com bordas para a tabela de resultados
            printf("+---+---+-----------+\n");
            printf("| P | Q | Resultado |\n");
            printf("+---+---+-----------+\n");

            for (int P = 0; P <= 1; P++)
            {
                for (int Q = 0; Q <= 1; Q++)
                {
                    int resultado = 0;

                    switch (opcao)
                    {
                    case 1:
                        resultado = P;
                        break;
                    case 2:
                        resultado = P || Q;
                        break;
                    case 3:
                        resultado = P && Q;
                        break;
                    case 4:
                        resultado = (P == Q);
                        break;
                    case 5:
                        resultado = !P;
                        break;
                    case 6:
                        resultado = !Q;
                        break;
                    case 7:
                        resultado = (!P) && (!Q);
                        break;
                    case 8:
                        resultado = (!P) || (!Q);
                        break;
                    case 9:
                        resultado = (!P) || Q;
                        break;
                    case 10:
                        resultado = (!P == !Q);
                        break;
                    default:
                        printf("Opção inválida!\n");
                        return 1;
                    }

                    // Exibe o resultado
                    printf("| %c | %c |     %c     |\n",
                           (P == 1) ? 'V' : 'F',
                           (Q == 1) ? 'V' : 'F',
                           (resultado == 1) ? 'V' : 'F');
                }
            }

            printf("+---+---+-----------+\n");
        }
    }
    else if (escolha == 'N' || escolha == 'n')
    {
   printf("Digite 1 para calcular todas as formulas ou 2 para uma formula uma especifica:\n");
    scanf("%d", &todas);

    // Se o usuário escolher todas as fórmulas
    if (todas == 1)
    {
        printf("\nTabela Verdade para TODAS as formulas:\n");
        printf("+---+---+-----+-----+-----+-----+-------+-------+-------+-------+\n");
        printf("| A | B | A*B | A+B | !A  | !B  | !A+!B | !A*!B | !A*B  | A*!B  |\n");
        printf("+---+---+-----+-----+-----+-----+-------+-------+-------+-------+\n");

        for (int A = 0; A <= 1; A++)
        {
            for (int B = 0; B <= 1; B++)
            {
                printf("| %d | %d |  %d  |  %d  |  %d  |  %d  |   %d   |   %d   |   %d   |   %d   |\n",
                       A, B,
                       A && B,                // A*B
                       A || B,                // A+B
                       !A,                    // !A
                       !B,                    // !B
                       (!A) || (!B),          // !A+!B
                       (!A) && (!B),          // !A*!B
                       (!A) && B,             // !A*B
                       A && (!B));            // A*!B
            }
        }
        printf("+---+---+-----+-----+-----+-----+-------+-------+-------+-------+\n");
    }
    else if (todas == 2) // Se o usuário quiser calcular apenas uma fórmula específica
    {
        printf("Digite a fórmula lógica que desejar\n([A*B], [A+B], [!A], [!B], [!A+!B], [!A*!B], [!A+B], [A+!B], [!A*B], [A*!B]):\n");
        scanf("%s", formula); // Lê a fórmula fornecida pelo usuário

        printf("\nTabela Verdade para a fórmula %s:\n", formula);

        // Cabeçalho com bordas para a tabela de resultados
        printf("+---+---+-----------+\n");
        printf("| A | B | Resultado |\n");
        printf("+---+---+-----------+\n");

        for (int A = 0; A <= 1; A++)
        {
            for (int B = 0; B <= 1; B++)
            {
                int resultado = 0;

                // Avaliando a fórmula fornecida pelo usuário
                if (strcmp(formula, "A*B") == 0)
                    resultado = A && B; // AND lógico
                else if (strcmp(formula, "A+B") == 0)
                    resultado = A || B; // OR lógico
                else if (strcmp(formula, "!A") == 0)
                    resultado = !A; // Negação de A
                else if (strcmp(formula, "!B") == 0)
                    resultado = !B; // Negação de B
                else if (strcmp(formula, "!A+!B") == 0)
                    resultado = (!A) || (!B); // OR dos negados
                else if (strcmp(formula, "!A*!B") == 0)
                    resultado = (!A) && (!B); // AND dos negados
                else if (strcmp(formula, "!A+B") == 0)
                    resultado = (!A) || B; // OR de !A com B
                else if (strcmp(formula, "A+!B") == 0)
                    resultado = A || (!B); // OR de A com !B
                else if (strcmp(formula, "!A*B") == 0)
                    resultado = (!A) && B; // AND de !A com B
                else if (strcmp(formula, "A*!B") == 0)
                    resultado = A && (!B); // AND de A com !B
                else
                {
                    printf("Fórmula inválida! Use uma das seguintes: [A*B], [A+B], [!A], [!B], [!A+B], [A+!B], [!A*B], [A*!B]\n");
                    return 1; // Saída com erro
                }

                printf("| %d | %d |     %d     |\n", A, B, resultado);
            }
        }
        printf("+---+---+-----------+\n");
    }
    }
    else
    {
        printf("Opção inválida! Por favor, escolha S ou N.\n");
    }

    return 0;
}