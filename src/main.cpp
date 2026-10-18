#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Campanha.hpp"
#include "Exercito.hpp"
#include "Infantaria.hpp"
#include "Veiculo.hpp"
#include "Aeronave.hpp"

int main(){

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

//adicionando exercitos

    Exercito* e1 = new Exercito();
    Exercito* e2 = new Exercito();
    Exercito* e3 = new Exercito();
//exercito 1
//preenchendo com 2 infantarias, 2 veiculos e 1 aeronave

    e1->adicionarUnidade(new Infantaria());
    e1->adicionarUnidade(new Infantaria());
    e1->adicionarUnidade(new Veiculo());
    e1->adicionarUnidade(new Veiculo());
    e1->adicionarUnidade(new Aeronave());

//exercito 2
//preenchendo com 2 infantarias, 2 veiculos e 1 aeronave

    e2->adicionarUnidade(new Infantaria());
    e2->adicionarUnidade(new Infantaria());
    e2->adicionarUnidade(new Veiculo());
    e2->adicionarUnidade(new Veiculo());
    e2->adicionarUnidade(new Aeronave());

//exercito 3
//preenchendo com 2 infantarias, 2 veiculos e 1 aeronave

    e3->adicionarUnidade(new Infantaria());
    e3->adicionarUnidade(new Infantaria());
    e3->adicionarUnidade(new Veiculo());
    e3->adicionarUnidade(new Veiculo());
    e3->adicionarUnidade(new Aeronave());

//adicionando exercitos na campanha criada
    Campanha campanha;
    campanha.addExercito(e1);
    campanha.addExercito(e2);
    campanha.addExercito(e3);

//simular a batalha
    campanha.simularBatalhas();

//exibe a tabela de posicoes
    campanha.gerarTabelaDePosicoes("tabela.txt");
    std::cout << std::endl;
//exibe a unidade mais destrutiba
    campanha.mostrarUnidadeMaisDestrutiva();

//limpa memoria

    delete e1;
    delete e2;
    delete e3;

    return 0;
}

