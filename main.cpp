#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <chrono> 

using namespace std;
using namespace chrono;

// Estrutura para representar um prato
struct Prato {
    int prioridade;
    int tempo;
    string nome;
};

// Função de ordenação Bubble Sort
void bubble_sort(Prato pratos[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (pratos[j].prioridade < pratos[j + 1].prioridade ||  
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo)) {
                swap(pratos[j], pratos[j + 1]);
            }
        }
    }
}

// Função para escolher a mediana de três como pivô
int mediana_de_tres(Prato pratos[], int inferior, int superior) {
    int meio = (inferior + superior) / 2;

    if (pratos[inferior].prioridade > pratos[meio].prioridade)
        swap(pratos[inferior], pratos[meio]);
    if (pratos[inferior].prioridade > pratos[superior].prioridade)
        swap(pratos[inferior], pratos[superior]);
    if (pratos[meio].prioridade > pratos[superior].prioridade)
        swap(pratos[meio], pratos[superior]);

    swap(pratos[meio], pratos[superior]);  // Coloca o pivô na posição correta
    return superior;
}

// Função de particionamento do Quicksort
int particionar(Prato pratos[], int inferior, int superior) {
    int indice_pivo = mediana_de_tres(pratos, inferior, superior);
    Prato pivo = pratos[indice_pivo];
    int i = inferior - 1;

    for (int j = inferior; j < superior; ++j) {
        if (pratos[j].prioridade > pivo.prioridade || 
            (pratos[j].prioridade == pivo.prioridade && pratos[j].tempo < pivo.tempo)) {
            ++i;
            swap(pratos[i], pratos[j]);
        }
    }

    swap(pratos[i + 1], pratos[superior]);
    return i + 1;
}

// Função de ordenação Quicksort
void quicksort(Prato pratos[], int inferior, int superior) {
    if (inferior < superior) {
        int pi = particionar(pratos, inferior, superior);
        quicksort(pratos, inferior, pi - 1);
        quicksort(pratos, pi + 1, superior);
    }
}

// Função para gerar um nome aleatório para os pratos
string gerar_nome(int id) {
    string nomes[] = {
        "fish-and-chips", "poitin", "bubble-and-squeak", "steak-and-ale-pie", 
        "shepherds-pie", "ploughmans-lunch", "bangers-and-mash", "toad-in-the-hole",
        "cornish-pasty", "scotch-egg", "eels-pie", "black-pudding", "jam-roly-poly", 
        "spotted-dick", "mash-and-gravy", "beef-wellington", "chicken-tikka-masala", 
        "liver-and-onions", "cottage-pie", "fish-pie", "chicken-pie", "sausage-roll", 
        "chicken-and-leek-pie", "steak-and-kidney-pie", "ploughmans-lunch", "mutton-pie"
    };
    return nomes[id % 24];
}

int main() {
    srand(time(0));

    int n = 3000; 

    Prato pratos[n];

    for (int i = 0; i < n; ++i) {
        pratos[i].prioridade = rand() % 300000 + 1;
        pratos[i].tempo = rand() % 1000 + 1;
        pratos[i].nome = gerar_nome(i);
    }

    auto inicio_bubble = high_resolution_clock::now();
    Prato pratos_bubble[n];
    copy(pratos, pratos + n, pratos_bubble);
    bubble_sort(pratos_bubble, n);
    auto fim_bubble = high_resolution_clock::now();
    auto duracao_bubble = duration_cast<microseconds>(fim_bubble - inicio_bubble);

    cout << "Tempo de execução do Bubble Sort: " << duracao_bubble.count() << " microssegundos." << endl;

    auto inicio_quick = high_resolution_clock::now();
    Prato pratos_quick[n];
    copy(pratos, pratos + n, pratos_quick);
    quicksort(pratos_quick, 0, n - 1);
    auto fim_quick = high_resolution_clock::now();
    auto duracao_quick = duration_cast<microseconds>(fim_quick - inicio_quick);

    cout << "Tempo de execução do Quicksort: " << duracao_quick.count() << " microssegundos." << endl;

    return 0;
}
