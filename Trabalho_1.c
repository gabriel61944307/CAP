/*  Processamento de imagens.
    Esse programa recebe um comando, as dimensões de uma imagens e os valores RGB de seus pixels, ele aplica "filtros"
    a esses valores mudando o valor dos pixels.

    Gabriel Rodrigues Malaquias, 2018.
    RA: 758906.
    BCC 018.

    Input: Comando do filtro, dimensões da imagem, valores RGB dos pixels.
    Output: Dimensões da imagem, novos valores RGB dos pixels.

    Exemplo:
    Input:  CIN
            2 2
            100 110 120 130 140 150 160 170 180 190 200 210

    Output: 2 2
            108 108 108 138 138 138 168 168 168 198 198 198
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int matI[500][500];   //Matriz inicial
    int matF[500][500];   //Matriz final
    char comando[3];            //Comando do que fazer com a imagem
    int limiar=0;
    float contraste=0, brilho=0;
    int qtd_L=0, C=0, qtd_C=0;
    int i=0, j=0;

    scanf("%s",comando);

    if(strcmp(comando,"LIM")==0)
        scanf("%d",&limiar);
    else if(strcmp(comando,"CON")==0)
        scanf("%f",&contraste);
    else if(strcmp(comando,"BRI")==0)
        scanf("%f",&brilho);

    scanf("%d %d", &qtd_L, &C);
    qtd_C = C * 3;              //quantidade de colunas incluindo RGB

    //Leitura matriz inicial
    for(i=0;i<qtd_L;i++){
        for(j=0;j<qtd_C;j++){
            scanf("%d",&matI[i][j]);
        }
    }

	//NIVEIS DE CINZA
    if(strcmp(comando,"CIN")==0){
        int g=0, aux = -1; //aux serve como verificador, ele é usado para verificar se ja se passaram 3 posiçoes de leitura RGB.
        printf("%d %d\n", qtd_L, C);
        for(i=0;i<qtd_L;i++){
            aux = -1; //aux é resetado aqui pois o seu valor havia sido alterado dentro do for abaixo.
            for(j=0;j<qtd_C;j++){
                if(j > aux){ //verifica se ja se passaram 3 posiçoes (colunas).
                    aux = j + 2; //essa alteração faz com que esse if só execute novamente após o j estar nos proximos valores RGB.
                    g = (0.2126*matI[i][j] + 0.7152*matI[i][j+1] + 0.0722*matI[i][j+2]);
                    matF[i][j] = g;
                    printf("%d ",matF[i][j]);
                    matF[i][j+1] = g;
                    printf("%d ",matF[i][j+1]);
                    matF[i][j+2] = g;
                    printf("%d ",matF[i][j+2]);
                }
            }
            //printf("\n");
        }
    }

    //INVERSAO
    else if(strcmp(comando,"INV")==0){
        printf("%d %d\n", qtd_L, C);
        for(i=0;i<qtd_L;i++){
            for(j=0;j<qtd_C;j++){
                matF[i][j] = 255 - matI[i][j];
                printf("%d ", matF[i][j]);
            }
        }
            //printf("\n");
    }

    //LIMIAR
    else if(strcmp(comando,"LIM")==0){
        int glimiar=0, aux=-1, g=0;
        printf("%d %d\n",qtd_L, C);
        for(i=0;i<qtd_L;i++){
            aux = -1;
            for(j=0;j<qtd_C;j++){
                if(j > aux){
                    aux = j + 2;
                    g = (0.2126*matI[i][j]) + (0.7152*matI[i][j+1]) + (0.0722*matI[i][j+2]);
                    if(g<limiar)
                        glimiar = 0;
                    else if (g>=limiar)
                        glimiar = 255;
                    matF[i][j] = glimiar;
                    printf("%d ",matF[i][j]);
                    matF[i][j+1] = glimiar;
                    printf("%d ",matF[i][j+1]);
                    matF[i][j+2] = glimiar;
                    printf("%d ",matF[i][j+2]);
                }
            }
            //printf("\n");
        }
    }

    //SUAVIZACAO
    else if(strcmp(comando,"MED")==0){
        printf("%d %d\n",qtd_L, C);
        for(i=0;i<qtd_L;i++){
            for(j=0;j<qtd_C;j++){
                if(i<=0 || i>=qtd_L-1|| j<=2 || j>=qtd_C-3)
                    printf("%d ",matI[i][j]);
                else{
                    matF[i][j] = (matI[i-1][j-3] + matI[i-1][j] + matI[i-1][j+3] + matI[i][j-3] + matI[i][j] + matI[i][j+3] + matI[i+1][j-3] + matI[i+1][j] + matI[i+1][j+3]) / 9;
                    printf("%d ",matF[i][j]);
                }
            }
           // printf("\n");
        }
    }

    //CONTRASTE
    else if(strcmp(comando,"CON")==0){
        printf("%d %d\n",qtd_L, C);
        for(i=0;i<qtd_L;i++){
            for(j=0;j<qtd_C;j++){
                matF[i][j] = matI[i][j] * contraste;
                if (matF[i][j]>255) matF[i][j]=255;
                else if (matF[i][j]<0) matF[i][j]=0;
                printf("%d ",matF[i][j]);
            }
            //printf("\n");
        }
    }

    //BRILHO
    else if(strcmp(comando,"BRI")==0){
        printf("%d %d\n",qtd_L, C);
        for(i=0;i<qtd_L;i++){
            for(j=0;j<qtd_C;j++){
                matF[i][j] = matI[i][j] + brilho;
                if (matF[i][j]>255) matF[i][j]=255;
                else if (matF[i][j]<0) matF[i][j]=0;
                printf("%d ",matF[i][j]);
            }
            //printf("\n");
        }
    }

    //SEPIA
    else if(strcmp(comando,"SEP")==0){
        int aux=-1;
        printf("%d %d\n",qtd_L, C);
        for(i=0;i<qtd_L;i++){
            aux=-1;
            for(j=0;j<(qtd_C);j++){
                if(j > aux){
                    aux = j + 2;
                    matF[i][j] = (0.393*matI[i][j]) + (0.769*matI[i][j+1]) + (0.189*matI[i][j+2]);
            	    if (matF[i][j]>255) matF[i][j]=255;
                    else if (matF[i][j]<0) matF[i][j]=0;
                    printf("%d ",matF[i][j]);
                    matF[i][j+1] = (0.349*matI[i][j]) + (0.686*matI[i][j+1]) + (0.168*matI[i][j+2]);
            	    if (matF[i][j+1]>255) matF[i][j+1]=255;
                    else if (matF[i][j+1]<0) matF[i][j+1]=0;
                    printf("%d ",matF[i][j+1]);
                    matF[i][j+2] = (0.272*matI[i][j]) + (0.534*matI[i][j+1]) + (0.131*matI[i][j+2]);
                    if (matF[i][j+2]>255) matF[i][j+2]=255;
                    else if (matF[i][j+2]<0) matF[i][j+2]=0;
                    printf("%d ",matF[i][j+2]);
                }
            }
            //printf("\n");
        }
    }
    return 0;
}
