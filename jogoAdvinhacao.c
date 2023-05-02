#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main () {

setlocale(LC_ALL, "Portuguese");

	// Imprime cabecalho do nosso jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinha��o! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
    
    
	// Declarando variaveis que serao usadas mais a frente
    int chute;
    int acertou;
    int nivel;
    int numerodetentativas;
    int tentativas = 1;

    // Definindo a quantidade de pontos inicial
    double pontos = 1000;

    // Gerando um numero secreto aleatorio
    srand(time(0));
    int numerosecreto = rand() % 100;

    // Escolhendo o nivel de dificuldade
    printf("Qual o n�vel de dificuldade?\n");
    printf("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);
	
	switch(nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		
		case 2:
			numerodetentativas = 15;
			break;
		
		default:
			numerodetentativas = 6;
			break;
	}

	// Loop principal do jogo
	for (int i = 1; i <= numerodetentativas; i++ ) {

		printf("Tentativa %d\n", tentativas);
		printf ("Qual o seu chute? ");
		
		scanf ("%d", &chute);
		printf ("Seu chute foi %d\n", chute);
		
		// Tratando chute de numero negativo
		if (chute < 0) {
			printf ("Voc� n�o pode chutar n�meros negativos!\n");
			continue;
		}
		
		// Verifica se acertou , foi maior ou menor 
		acertou = chute == numerosecreto;
		
		if (acertou) {
			break;
		} else if (chute > numerosecreto) {
			printf("Seu chute foi maior que o n�mero secreto\n");
		} else {
				printf("Seu chute foi menor que o n�mero secreto\n");
		}
		
		// Calcula a quantidade de pontos
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
		
		tentativas++;
		
	}
	
    // imprimindo mensagem de vitoria ou derrota
    printf("\n");
    if(acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParab�ns! Voc� acertou!\n");
        printf("Voc� fez %.2f pontos. At� a pr�xima!\n\n", pontos);
    } else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nVoc� perdeu! Tente novamente!\n\n");
    }


}



