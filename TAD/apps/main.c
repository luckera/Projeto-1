/*

Lucas Lima Romero 13676325
Luciano Gonçalves Lopes Filho 13676520
Marco Antonio Gaspar Garcia 11833581

*/

// ------- TAD ------- //
#include "lista.h"

#define REP 10 // Numero de repeticoes para calcular o tempo medio de execucao

// cada funcao dessas recebe um modo, que diz respeito ao tipo de vetor utilizado
// nelas serao calculados os tempos de execucao 

void bubble_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, tempo; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= 100000; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {   
        double array_tempos[REP];

        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_bubble_sort(l); // chama funcao que ordena
            tempo = clock() - tempo_ini;// salva o tempo de duracao do ciclo
           
            array_tempos[i] = (double)tempo/CLOCKS_PER_SEC; // guarda os tempos em um array
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }

        double x = media(array_tempos, REP);
        double DP = desvio_padrao(array_tempos, REP, x);

        printf("Tamanho da entrada: %.0f\tTempo medio: %0.10fs\tDesvio padrao: %0.10f\n", pow(10, ordem), x, DP); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}

void bubble_sort_aprimorado(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, tempo; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= 100000; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {   
        double array_tempos[REP];

        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_bubble_sort_aprimorado(l); // chama funcao que ordena
            tempo = clock() - tempo_ini;// salva o tempo de duracao do ciclo
           
            array_tempos[i] = (double)tempo/CLOCKS_PER_SEC; // guarda os tempos em um array
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }

        double x = media(array_tempos, REP);
        double DP = desvio_padrao(array_tempos, REP, x);

        printf("Tamanho da entrada: %.0f\tTempo medio: %0.10fs\tDesvio padrao: %0.10f\n", pow(10, ordem), x, DP); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}

void quick_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, tempo; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= 100000; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {   
        double array_tempos[REP];

        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_quick_sort(l); // chama funcao que ordena
            tempo = clock() - tempo_ini;// salva o tempo de duracao do ciclo
           
            array_tempos[i] = (double)tempo/CLOCKS_PER_SEC; // guarda os tempos em um array
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }

        double x = media(array_tempos, REP);
        double DP = desvio_padrao(array_tempos, REP, x);

        printf("Tamanho da entrada: %.0f\tTempo medio: %0.10fs\tDesvio padrao: %0.10f\n", pow(10, ordem), x, DP); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}

void radix_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, tempo; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; (long)pow(10, ordem) <= TAM; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {   
        double array_tempos[REP];

        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, (long)pow(10, ordem));
            l->tamanho = (long)pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_radix_sort(l); // chama funcao que ordena
            tempo = clock() - tempo_ini;// salva o tempo de duracao do ciclo
           
            array_tempos[i] = (double)tempo/CLOCKS_PER_SEC; // guarda os tempos em um array
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }

        double x = media(array_tempos, REP);
        double DP = desvio_padrao(array_tempos, REP, x);

        printf("Tamanho da entrada: %.0ld\tTempo medio: %0.10fs\tDesvio padrao: %0.10f\n", (long)pow(10, ordem), x, DP); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}

void heap_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, tempo; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= TAM; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {   
        double array_tempos[REP];

        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_heap_sort(l); // chama funcao que ordena
            tempo = clock() - tempo_ini;// salva o tempo de duracao do ciclo
           
            array_tempos[i] = (double)tempo/CLOCKS_PER_SEC; // guarda os tempos em um array
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }

        double x = media(array_tempos, REP);
        double DP = desvio_padrao(array_tempos, REP, x);

        printf("Tamanho da entrada: %.0f\tTempo medio: %0.10fs\tDesvio padrao: %0.10f\n", pow(10, ordem), x, DP); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}


int main(){

    lista *l;

    // cada funcao eh chamada tres vezes, uma para cada tipo de vetor
    // a diferenca entre elas eh o algoritmo de ordenacao utilizado

    printf("\tBubble Sort\n\n");
    for (int i = 1; i <= 3; i++)
        bubble_sort(l, i);

    printf("\n\tBubble Sort Aprimorado\n\n");
    for (int i = 1; i <= 3; i++)
        bubble_sort_aprimorado(l, i);
    
    printf("\n\tQuick Sort\n\n");
    for (int i = 1; i <= 3; i++)
        quick_sort(l, i);

    printf("\n\tRadix Sort\n\n");
    for (int i = 1; i <= 3; i++)
        radix_sort(l, i);

    printf("\n\tHeap Sort\n\n");
    for (int i = 1; i <= 3; i++)
        heap_sort(l, i);

    return 0;
}