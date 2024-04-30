#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playRoulette(){
    srand(time(NULL));
    int aposta, decisao, chute, dinheiro = 500, sorteio;

    do {
        printf("Faça a sua aposta(min. $50)\n");
        printf("Saldo disponível: %d\n", dinheiro);
        scanf("%d", &aposta);
        if(aposta < 50){
            printf("A aposta mínima é de $50, tente novamente.\n\n");
            continue;
        } else if(aposta > dinheiro){
            printf("Saldo não disponível.\n\n");
            continue;
        } else {
            dinheiro -= aposta;
            while (1) {
                printf("Escolha a sua aposta:\n");
                printf("1. Pares  2. Ímpares  3. 0 ou 00  4. Escolher número  5. Cancelar\n");
                scanf("%d", &decisao);
                sorteio = rand() % 38;

                if(decisao == 1){
                    if (sorteio != 0 && sorteio % 2 == 0) {
                        printf("Você venceu! O número sorteado foi: %d\n", sorteio);
                        dinheiro += 2 * aposta;
                        break;
                    } else {
                        printf("Você perdeu! O número sorteado foi: %d\n", sorteio);
                        break;
                    }
                } else if (decisao == 2){
                    if(sorteio % 2 != 0 && sorteio != 37){
                        printf("Você venceu! O número sorteado foi: %d\n", sorteio);
                        dinheiro += 2 * aposta;
                        break;
                    } else {
                        printf("Você perdeu! O número sorteado foi: %d\n", sorteio);
                        break;
                    }
                } else if(decisao == 3){
                    if(sorteio == 0 || sorteio == 37){
                        printf("Você venceu! O número sorteado foi: 0\n");
                        dinheiro += 5 * aposta;
                        break;
                    } else {
                        printf("Você perdeu! O número sorteado foi: %d\n", sorteio);
                        break;
                    }
                } else if(decisao == 4){
                    printf("Escolha o seu número (entre 1 e 36): ");
                    scanf("%d", &chute);
                    if(chute == sorteio){
                        printf("Você venceu! O número sorteado foi: %d\n", sorteio);
                        dinheiro += 10 * aposta;
                        break;
                    } else {
                        printf("Você perdeu! O número sorteado foi: %d\n", sorteio);
                        break;
                    }
                } else if(decisao == 5){
                    printf("Saindo...\n");
                    break;
                }
            }
        }
    } while (dinheiro > 0);

    printf("O dinheiro acabou!\nGAME OVER\n");
}

int main(){
    playRoulette();
    return 0;
}
