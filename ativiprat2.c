#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int expoente(int a, int num){
    if(a == 1){
        return num;
    }
    else if(a == 0){
        return 1;
    }
    else{
        return num * expoente(a-1, num);
    }
}

int log(int a, int num){
    int n = 0;
    if(num % 2 != 0){
            return 0;
        }
    if(num != 1){
        while(num != 1){
            if(num % 2 != 0){
                return 0;
            }
            num = num/2;
            n++;
        }
    }
    return n;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "");
    int variaveis, i, b, c = 0, denomi = 2, cont = 0, a = 0, d = 0, x, y = 0, z, w = 0;
    char letras[23] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    FILE *file;
    file = fopen("numero.txt", "r");
    if(file == NULL){
        printf("não há nada no seu arquivo");
        return 0;
    }
    while(fscanf(file, "%d ", &x) != EOF){
            a++;
        }
    if(log(2,a) == 0){
        printf("quantidade de saídas inválida!");
        return 0;
    }
    int cont_colunas[a-1];
    file = fopen("numero.txt", "r");
    while(fscanf(file, "%d ", &cont_colunas[d]) != EOF){
            d++;
        }
    variaveis = log(2, a);
    int tabela[a][variaveis];
    for(i = 0; i < variaveis; i++){
        for(b = 0; b < a; b++){
            if(cont < a/denomi){
                tabela[b][i] = 0;
                cont++;
            }
            else{
                tabela[b][i] = 1;
                c++;
                if(c == a/denomi){
                    cont -= a/denomi;
                    c = 0;
                }
            }
        }
        cont -= cont;
        denomi *= 2;
    }
    putchar('\t');
    for(i = 0; i < variaveis; i++){
        if(i == variaveis-1){
        printf("%c  S", letras[i]);
        }
        else{
            printf("%c ", letras[i]);
        }
    }
    putchar('\n');
    for(i = 0; i < a; i++){
        printf("%d\t", cont);
        for(b = 0; b < variaveis; b++){
            if(b == variaveis-1){
                printf("%d  %d", tabela[i][b], cont_colunas[i]);
                }
            else{
            printf("%d ", tabela[i][b]);
            }
        }
        cont++;
        putchar('\n');
    }
    putchar('\n');
    for(i = 0; i < a; i++){
        if(cont_colunas[i] == 1){
            if(w != 0){
                printf(" + ");
            }
            for(z = 0; z < variaveis; z++){
                if(tabela[i][z] == 0){
                    printf("%c'", letras[y]);
                }
                else{
                    printf("%c", letras[y]);
                }
                y++;
                w++;
            }
        }
        y = 0;
    }
    fclose(file);
    return 0;
}