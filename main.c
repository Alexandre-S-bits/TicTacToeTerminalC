#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int numero_jogada = 0;
char simbolo_vez = '-';


void imprimirPosicoesTabuleiro(){
    // Imprimir as posições disponiveis do tabuleiro
    int local_imprimir = 1;
        printf("\n Posições para jogar:\n\n");
        for (int j = 0; j < 3; j++){
            for (int i = 0; i < 3; i++){
                printf("%2d ", local_imprimir);
                if (i != 2){
                    printf("|");
                }
                local_imprimir++;
            }
            printf("\n");
            if (j != 2){
                printf("-----------\n");
            }
        }
}


void ImprimirTabuleiroAtualizado(int tabuleiro[][3]){
    // Essa função imprime o tabuleiro atualizado a cada jogada
    printf("\n");
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3; i++){
            printf(" %c ", tabuleiro[i][j]);
            if (i < 2){
                printf("|");
            }
        }
        printf("\n");
        if (j < 2){
            printf("-----------\n");
        }
    }
}


char AlterarSimboloJogada(int numero_jogada){
    // Altera o simbolo do jogador de acordo com o numero da jogada atual e retorna esse simbolo
    char simbolo_atual = '-';
    if (numero_jogada % 2 == 0) {
        printf("\n Vez do Jogador x");
        simbolo_atual = 'x';
    }
    else if (numero_jogada % 2 == 1) {
        printf("\n Vez do Jogador o");
        simbolo_atual = 'o';
    }
    return simbolo_atual;

}


int realizarJogada(int tabuleiro[3][3]){
    // verificar se a jogada é valida, e caso seja valida preenche com o simbolo do jogador na posição escolhida
    int jogada_valida = 0, local = 0;

    simbolo_vez = AlterarSimboloJogada(numero_jogada);

    do{
        printf("\n Escolha uma posição: ");
        scanf("%d", &local);

        if (local == 1 &&  tabuleiro[0][0] != 'x' && tabuleiro[0][0] != 'o'){
                tabuleiro[0][0] = simbolo_vez;
                jogada_valida = 1;
            }

            else if (local == 2 && tabuleiro[1][0] != 'x' && tabuleiro[1][0] != 'o'){
                tabuleiro[1][0] = simbolo_vez;
                jogada_valida = 1;
            }

            else if (local == 3 && tabuleiro[2][0] != 'x' && tabuleiro[2][0] != 'o'){
                tabuleiro[2][0] = simbolo_vez;
                jogada_valida = 1;
            }



            else if (local == 4 && tabuleiro[0][1] != 'x' && tabuleiro[0][1] != 'o'){
                tabuleiro[0][1] = simbolo_vez;
                jogada_valida = 1;
            }

            else if ((local == 5) && tabuleiro[1][1] != 'x' && tabuleiro[1][1] != 'o'){
                tabuleiro[1][1] = simbolo_vez;
                jogada_valida = 1;
            }

            else if ((local == 6) && tabuleiro[2][1] != 'x' && tabuleiro[2][1] != 'o'){
                tabuleiro[2][1] = simbolo_vez;
                jogada_valida = 1;
            }



            else if (local == 7 && tabuleiro[0][2] != 'x' && tabuleiro[0][2] != 'o'){
                tabuleiro[0][2] = simbolo_vez;
                jogada_valida = 1;
            }

            else if (local == 8 && tabuleiro[1][2] != 'x' && tabuleiro[1][2] != 'o'){
                tabuleiro[1][2] = simbolo_vez;
                jogada_valida = 1;
            }

            else if (local == 9 && tabuleiro[2][2] != 'x' && tabuleiro[2][2] != 'o'){
                tabuleiro[2][2] = simbolo_vez;
                jogada_valida = 1;
            }
            else
                printf("\n Jogada Invalida!\n");
        }while (jogada_valida == 0);
}


int VerificarFimJogo(int tabuleiro[][3]){
    int contador_x = 0, contador_o = 0;
    // Essa função verifica se teve vitoria ou derrota em cada jogada, caso tenha ele retorna 0 para finalizar o jogo

    // Verificar EMPATE
    if (numero_jogada == 9){
        printf("\n\tEmpate!");
        return 0;
    }

    // verificar DIAGONAIS
    if ((tabuleiro[0][0] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][2] == 'x') || (tabuleiro[0][0] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][2] == 'o')){
        printf("\n O Jogador '%c' Venceu!", simbolo_vez);
        return 0;
    }

    else if ((tabuleiro[0][2] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][0] == 'x') || (tabuleiro[0][2] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][0] == 'o')){
        printf("\n O Jogador '%c' Venceu!", simbolo_vez);
        return 0;
    }

    // verificar - LINHAS
    for (int j = 0; j < 3; j++){
        contador_x = 0;
        contador_o = 0;
        for (int i = 0; i < 3; i++){
            if (tabuleiro[i][j] == 'x')
                contador_x++;
            else if (tabuleiro[i][j] == 'o')
                contador_o++;
        }
        if (contador_x == 3 || contador_o == 3){
            printf("\n\tO Jogador '%c' Venceu!", simbolo_vez);
            return 0;
        }
    }

    // verificar COLUNAS
    for (int i = 0; i < 3; i++){
        contador_x = 0;
        contador_o = 0;
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == 'x')
                contador_x++;
            else if (tabuleiro[i][j] == 'o')
                contador_o++;
        }
        if (contador_x == 3 || contador_o == 3){
            printf("\n\tO Jogador '%c' Venceu!", simbolo_vez);
            return 0;
        }
    }
}


int main(){
    int verifica_fim_jogo = 1, sair_jogo = 1;
    int tabuleiro[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};


    setlocale(LC_ALL,"Portuguese");
    while(sair_jogo){
        do{
            // Imprimir posicoes para escolher no tabuleiro
            imprimirPosicoesTabuleiro();

            // Mostra o tabuleiro atualizado
            ImprimirTabuleiroAtualizado(tabuleiro);

            // realiza a jogada e verifica se ela é valida
            realizarJogada(tabuleiro);

            // aumenta a quantidade de jogadas feitas pelos jogadores
            numero_jogada++;

            // Verificando se teve vitoria ou empate
            verifica_fim_jogo = VerificarFimJogo(tabuleiro);

        }while(verifica_fim_jogo);
        printf("\n\n Resultado Final Rodada:\n");
        ImprimirTabuleiroAtualizado(tabuleiro);

        printf("\n\n Para jogar novamente escolha '1' ou '0' para sair: ");
        scanf("%d", &sair_jogo);
        // Criando (Zerando) o tabuleiro novamente
        if (sair_jogo != 0){
            for (int i=0; i<3; i++){
                for (int j=0; j<3; j++){
                    tabuleiro[i][j] = ' ';
                }
            }
        }

    }

    return 0;
}
