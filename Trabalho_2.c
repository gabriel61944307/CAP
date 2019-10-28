/*
 * Este programa faz a formatação de um texto que é inserido em linhas de no máximo 80 caracteres.
 *
 * Gabriel Rodrigues Malaquias, 2018.
 * RA:758906.
 * BCC 018.
 *
 * Input: Texto.
 * Output: Texto formatado com quebra de linha em 80 caracteres.
 *
 * Exemplos: Input: Title: Gone With The Wind
 *                  Author: Margaret Mitchell (1900-1949)
 *                  PART ONE
 *                  CHAPTER I
 *                  Scarlett O'Hara was not beautiful, but men seldom realized it when
 *                  caught by her charm as the Tarleton twins were. In her face were
 *                  too sharply blended the delicate features of her mother, a Coast
 *                  aristocrat of French descent, and the heavy ones of her florid
 *                  Irish father. But it was an arresting face, pointed of chin,
 *                  square of jaw. Her eyes were pale green without a touch of hazel,
 *
 *          Output: Title:              Gone               With               The               Wind
 *                  Author:               Margaret               Mitchell                (1900-1949)
 *                  PART                                                                         ONE
 *                  CHAPTER                                                                        I
 *                  Scarlett  O'Hara  was  not  beautiful,  but  men   seldom   realized   it   when
 *                  caught  by  her  charm  as  the  Tarleton  twins  were.   In   her   face   were
 *                  too  sharply  blended  the  delicate   features   of   her   mother,   a   Coast
 *                  aristocrat  of  French   descent,   and   the   heavy   ones   of   her   florid
 *                  Irish   father.   But   it   was   an   arresting   face,   pointed   of   chin,
 *                  square  of  jaw.  Her  eyes  were  pale  green  without  a   touch   of   hazel,
 *
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char linhaI[81], linhaF[81];

    while(fgets(linhaI, sizeof linhaI, stdin) != 0){
        int i=-1,espacos=0,verif=1;
        int espvazio=0, espextra=0, espextraresto=0;

        //Coleta de dados sobre a linha
        while(verif!=0){
            i++;
            if(linhaI[i]==' ')
                espacos++;
            else if(linhaI[i]=='\n')
                verif=0;
        }
        espvazio = 80 - i;
        if(espacos!=0){
            espextra = espvazio/espacos;
            espextraresto = espvazio%espacos;
            //Justificando as linhas
            int cont2=0, contespaco=0;
            for(int cont=0; cont2<80; cont++){
                if(linhaI[cont] != ' '){
                    linhaF[cont2] = linhaI[cont];
                }
                else{
                    contespaco++;
                    for(int aux=0; aux<espextra+1; aux++){
                        linhaF[cont2] = ' ';
                        cont2++;
                    }
                    if(espextraresto+contespaco > espacos){
                        linhaF[cont2] = ' ';
                        cont2++;
                    }
                    cont2--;
                }
                cont2++;
            }
            linhaF[80]='\n';
            linhaF[81]='\0';
            printf("%s", linhaF);
        }
        else{
            printf("%s", linhaI);
        }
            //Exibição das linhas
    }
    return 0;
}
