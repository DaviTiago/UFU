#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
//Davi Tiago Soares. Numero de matricula: 12211BSI240, Matheus Soares Costa. Numero de matricula: 12211BSI215
//Jogo da velha
int jog , again, l,c,linha, coluna, jogador  , win , jogo[3][3] = {0,0,0,0,0,0,0,0,0};

do{
    jogador = 1; win = 0; jog = 0;
    for(l=0; l<3; l++){
        for(c=0; c<3; c++){
            jogo[l][c] = 0;

        }
    }
        do{
        printf("\n 0   1   2 \n");
        for(l=0; l<3; l++){
            for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");

        }
        do{
            printf("Jogador %d: Digite a linha e a coluna: \n", jogador);
            scanf("%d%d", &linha, &coluna);
            }while(linha<0 || linha>2 || coluna<0 || coluna>2 || jogo[linha][coluna] != 0);

            if (jogador == 1 ){
                jogo[linha][coluna] = 1;
                jogador++;
            }
            else{jogo[linha][coluna] = 2;
                jogador=1;
                }

            jog++;
            if(jogo [0][0] == 1 && jogo[0][1] == 1 && jogo[0][2] ==1 || jogo [1][0] == 1 && jogo[1][1] == 1 && jogo[1][2] ==1 || jogo [2][0] == 1 && jogo[2][1] == 1 && jogo[2][2] ==1){
                for(l=0; l<3; l++){
                for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 1 eh o vencedor por linha\n");
            win = 1;}

            if(jogo [0][0] == 2 && jogo[0][1] == 2 && jogo[0][2] ==2 || jogo [1][0] == 2 && jogo[1][1] == 2 && jogo[1][2] ==2 || jogo [2][0] == 2 && jogo[2][1] == 2 && jogo[2][2] ==2){
                for(l=0; l<3; l++){
                for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 2 eh o vencedor por linha\n");
            win = 1;}

            if(jogo[0][0] == 1 && jogo[1][0] == 1 && jogo[2][0] == 1 || jogo[0][1] == 1 && jogo[1][1] == 1 && jogo[2][1] == 1 || jogo[0][2] == 1 && jogo[1][2] == 1 && jogo[2][2] == 1 ){
              for(l=0; l<3; l++){
              for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 1 eh o vencedor por coluna\n");
            win = 1;}

            if(jogo[0][0] == 2 && jogo[1][0] == 2 && jogo[2][0] == 2 || jogo[0][1] == 2 && jogo[1][1] == 2 && jogo[2][1] == 2 || jogo[0][2] == 2 && jogo[1][2] == 2 && jogo[2][2] == 2 ){
            for(l=0; l<3; l++){
            for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 2 eh o vencedor por coluna\n");
            win = 1;}

            if(jogo[0][0] == 1 && jogo[1][1] == 1 && jogo[2][2] == 1 ){
                for(l=0; l<3; l++){
                for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 1 eh o vencedor pela diagonal principal\n");
                win = 1;}

            if(jogo[0][0] == 2 && jogo[1][1] == 2 && jogo[2][2] == 2){
                for(l=0; l<3; l++){
                for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 2 eh o vencedor pela diagonal principal \n");
                win = 1;}

            if(jogo[0][2] == 1 && jogo[1][1] == 1 && jogo[2][0] == 1){
                for(l=0; l<3; l++){
                for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 1 eh o vencedor pela diagonal secundaria \n");
                win = 1;}

            if(jogo[0][2] == 2 && jogo[1][1] == 2 && jogo[2][0] == 2){
                printf("\n 0   1   2 \n");
                for(l=0; l<3; l++){
                for(c=0; c<3; c++){
                printf(" %d ", jogo[l][c]);
                if(c < 2)
                printf("|");
                if (c == 2)
                printf(" %d ", l);
            }
            if(l <2)
            printf("\n-----------");
            printf("\n");}
            printf("\nO jogador 2 eh o vencedor pela diagonal secundaria \n"); win=1;}


        }while(win == 0 && jog < 9);
        if (win == 0) printf("\n DEU VELHA\n");

        printf("\nDigite 1 para jogar novamente\n");
        scanf("%d", &again);
}while( again == 1);

return 0;
}
