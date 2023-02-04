#include <iostream>
#include <string>
#include <vector>

int pode_acordar(int periodo, int dias, const std::string &padrao) {
    int dormindo = 0;
    for (int i = 0; i < periodo; i++) {
        if (padrao[i] == 'Z') {
            dormindo++;
        }
    }
    int nao_cansado = (dormindo >= dias) ? 1 : 0;
    for (int i = periodo; i < padrao.size(); i++) {
        if (padrao[i - periodo] == 'Z') {
            dormindo--;
        }
        if (padrao[i] == 'Z') {
            dormindo++;
        }
        if (dormindo >= dias) {
            nao_cansado++;
        }
    }
    return nao_cansado;
}

int cansado(int n, int periodo, int dias, const std::string &padrao) {
    if (periodo == 1) {
        int contador = 0;
        for (char c : padrao) {
            if (c == 'W') {
                contador++;
            }
        }
        return contador;
    }
    return n - pode_acordar(periodo, dias, padrao);
}

int main() {
    int n, periodo, dias;
    std::cin >> n >> periodo >> dias;
    std::string padrao;
    std::cin >> padrao;
    padrao += padrao.substr(0, periodo - 1);
    std::cout << cansado(n, periodo, dias, padrao) << std::endl;
    return 0;
}

