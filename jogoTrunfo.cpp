#include <iostream>    // Para entrada e saída (cin, cout, printf)
#include <cstdlib>     // Para rand(), srand()
#include <ctime>       // Para time() (gerar números aleatórios diferentes)
#include <windows.h>   // Para Sleep() e system("pause")
#include <cstring>     // Para manipulação de strings (fgets, strcspn)

using namespace std;

class Carta {
public:
    int forca, energia, defesa, fadiga;

    Carta() {
        forca = rand() % 100;
        energia = rand() % 100;
        defesa = rand() % 100;
        fadiga = rand() % 100;
    }

    void mostrarCarta() {
        printf("+-------------------+\n");
        printf("| Forca:   %3d      |\n", forca);
        printf("| Energia: %3d      |\n", energia);
        printf("| Defesa:  %3d      |\n", defesa);
        printf("| Fadiga:  %3d      |\n", fadiga);
        printf("+-------------------+\n");
    }

    //retorna o valor do atributo escolhido
    int getAtributo(int opcao) {
        switch (opcao) {
            case 1: return forca;
            case 2: return energia;
            case 3: return defesa;
            case 4: return fadiga;
            default: return 0;
        }
    }

    //retorna o nome do atributo escolhido
    const char* nomeAtributo(int opcao) {
        switch (opcao) {
            case 1: return "Forca";
            case 2: return "Energia";
            case 3: return "Defesa";
            case 4: return "Fadiga";
            default: return "";
        }
    }
};

class Jogador {
public:
    int pontuacao;
    Carta monteCarta[5];

    Jogador() {
        pontuacao = 0;
        for (int i = 0; i < 5; i++) {
            Sleep(100); // pausa para variação de números
            monteCarta[i] = Carta(); // cria carta com valores aleatórios
        }
    }
};

int main() {

    // srand: serve para inicializar a função rand()
    srand(time(0)); 
    char nomeJogador[50];

    printf("Digite seu nome: ");

    // fgets() serve para ler uma linha de texto (string) digitada pelo usuário — até um limite de caracteres — e guardar na variável.
    fgets(nomeJogador, 50, stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = '\0'; //fgets() também lê o \n, então às vezes a string fica com uma quebra de linha no final. Por isso usamos = '\0'

    printf("\n+------------------------------------------+\n");
    printf("| BEM-VINDO AO SUPER TRUNFO, %s! |\n", nomeJogador);
    printf("+------------------------------------------+\n");

    printf("\nVoce jogara contra o nosso robo chamado Robert!\n");

    printf("\nRegras do jogo:\n");
    printf("- Cada jogador possui 5 cartas.\n");
    printf("- Cada carta tem 4 atributos: Forca, Energia, Defesa e Fadiga.\n");
    printf("- Voce escolhe um atributo por rodada.\n");
    printf("- O valor sera comparado com o da carta do oponente.\n");
    printf("- Quem tiver o valor maior vence a rodada.\n");

    Jogador player;
    Jogador robert;

    for (int i = 0; i < 5; i++) {
        printf("\n------------------- RODADA %d -------------------\n", i + 1);
        printf("\nSua carta:\n");
        player.monteCarta[i].mostrarCarta();

        int escolha;
        printf("\nEscolha um atributo:\n");
        printf("[1] Forca\n[2] Energia\n[3] Defesa\n[4] Fadiga\n> ");
        scanf("%d", &escolha);

        const char* atributo = player.monteCarta[i].nomeAtributo(escolha);
        int valorPlayer = player.monteCarta[i].getAtributo(escolha);
        int valorRobo = robert.monteCarta[i].getAtributo(escolha);

        printf("\nCarta de Robert:\n");
        robert.monteCarta[i].mostrarCarta();

        printf("\nComparando atributo: %s\n", atributo);
        printf("%s: %d  x  Robert: %d\n", nomeJogador, valorPlayer, valorRobo);

        if (valorPlayer > valorRobo) {
            player.pontuacao++;
            printf("-> %s venceu a rodada!\n", nomeJogador);
        } else if (valorRobo > valorPlayer) {
            robert.pontuacao++;
            printf("-> Robert venceu a rodada!\n");
        } else {
            printf("-> Empate!\n");
        }
    }

    printf("\n------------------ FIM DE JOGO ------------------\n");
    printf("Pontuacao final:\n");
    printf("%s: %d pontos\n", nomeJogador, player.pontuacao);
    printf("Robert: %d pontos\n", robert.pontuacao);

    if (player.pontuacao > robert.pontuacao)
        printf("Parabens, %s! Voce venceu o jogo!\n", nomeJogador);
    else if (robert.pontuacao > player.pontuacao)
        printf("Robert venceu! Tente novamente, %s.\n", nomeJogador);
    else
        printf("O jogo terminou empatado!\n");

    system("pause");
    return 0;
}

