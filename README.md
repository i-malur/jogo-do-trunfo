# 🃏 Super Trunfo (Versão Console em C++)

Um jogo de cartas simples estilo **Super Trunfo**, feito em **C++**, onde você joga contra um robô chamado **Robert**. Cada carta contém 4 atributos: **Força**, **Energia**, **Defesa** e **Fadiga**, e vence quem tiver o valor mais alto no atributo escolhido.

---

## 🎮 Demonstração do Jogo

```
Digite seu nome: Maria

+------------------------------------------+
| BEM-VINDO AO SUPER TRUNFO, Maria!        |
+------------------------------------------+

Voce jogara contra o nosso robo chamado Robert!

Regras do jogo:
- Cada jogador possui 5 cartas.
- Cada carta tem 4 atributos: Forca, Energia, Defesa e Fadiga.
- Voce escolhe um atributo por rodada.
- O valor sera comparado com o da carta do oponente.
- Quem tiver o valor maior vence a rodada.

------------------- RODADA 1 -------------------

Sua carta:
+-------------------+
| Forca:   56       |
| Energia: 84       |
| Defesa:  73       |
| Fadiga:  21       |
+-------------------+

Escolha um atributo:
[1] Forca
[2] Energia
[3] Defesa
[4] Fadiga
> 2

Carta de Robert:
+-------------------+
| Forca:   43       |
| Energia: 65       |
| Defesa:  78       |
| Fadiga:  37       |
+-------------------+

Comparando atributo: Energia
Maria: 84  x  Robert: 65
-> Maria venceu a rodada!
```

---

## 🧠 Como Funciona

### Objetivo
Ganhar o maior número de rodadas possíveis, escolhendo o melhor atributo da sua carta para vencer a carta do robô.

### Regras

- O jogo tem **5 rodadas**.
- A cada rodada, o jogador escolhe um dos 4 atributos da sua carta.
- O mesmo atributo será comparado com o da carta de Robert.
- O jogador com o maior valor vence a rodada.
- Ao final das 5 rodadas, quem tiver mais vitórias, vence o jogo.

---

## 🛠️ Tecnologias e Bibliotecas Usadas

- `iostream` – Entrada e saída padrão.
- `cstdlib` – Geração de números aleatórios (`rand()`).
- `ctime` – Semente para aleatoriedade (`srand(time(0))`).
- `windows.h` – `Sleep()` e `system("pause")` (somente no Windows).
- `cstring` – Para tratamento de strings com `fgets()`.

---

## 🗂️ Estrutura do Código

### 1. Classe `Carta`
- Gera valores aleatórios para 4 atributos.
- Métodos:
  - `mostrarCarta()` – exibe a carta formatada.
  - `getAtributo(int)` – retorna o valor do atributo escolhido.
  - `nomeAtributo(int)` – retorna o nome do atributo escolhido.

### 2. Classe `Jogador`
- Contém 5 cartas e a pontuação.
- As cartas são geradas com valores aleatórios ao criar o jogador.

### 3. Função `main`
- Solicita o nome do jogador.
- Mostra as regras do jogo.
- Executa 5 rodadas:
  - Mostra a carta do jogador.
  - Solicita escolha de atributo.
  - Compara com a carta do robô.
  - Exibe resultado e atualiza pontuação.
- Mostra o vencedor ao final.

---

## 🚀 Como Rodar

### Pré-requisitos:
- Ter um compilador C++ instalado (Ex: MinGW, GCC, Dev-C++, Code::Blocks ou VS Code com extensão C++).
- Sistema operacional **Windows** (por usar `windows.h`).

### Passo a passo:
1. Copie o código-fonte para um arquivo.
2. Compile o arquivo com seu compilador C++.
3. Execute o programa.
4. Digite seu nome e jogue!

---

## 💡 Dicas

- Para rodar em sistemas **Linux/macOS**:
  - Substitua `Sleep(100);` por `usleep(100000);` (necessário incluir `#include <unistd.h>`).
  - Remova ou substitua `system("pause");` por algo como `cin.get();`.

---

## ✍️ Autor

Desenvolvido por **Maria Luiza** 🖥️  
Matéria: Linguagem de Programação
Foco: desenvolvimento de jogos simples, lógicos e didáticos em C++

---
