#include "Campanha.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>


Campanha::Campanha() {}

Campanha::~Campanha(){
    for(Batalha* b : batalhas){
        delete b;
    }
    for (Exercito* e : exercitos){
        delete e;
    }
}

void Campanha::addExercito(Exercito* exercito){
    if(exercito != nullptr){
        exercitos.push_back(exercito);
    }
}

void Campanha::simularBatalhas(){
    if(exercitos.size() < 2){
        std::cout << "Nao existem exercitos suficientes para a batalha.\n";
        return;
    }
    int diaAtual = 1;
    int mesAtual = 1;
//gerar partidas ida e volta
    for(size_t i = 0; i <exercitos.size(); ++i){
        for(size_t j = 0; j < exercitos.size(); ++j){
            if( i == j) continue;
            
            Date data(diaAtual,mesAtual, 2026);

            Batalha* batalha = new Batalha(data, exercitos[i], exercitos[j]);

            batalha->ataqueExercitoA();
            batalha->ataqueExeecitoB();

            batalhas.push_back(batalha);

            diaAtual++;
            if( diaAtual > 28){
                diaAtual = 1;
                mesAtual++;
            }
        }
    }
}

void Campanha::gerarTabelaDePosicoes(const std::string& arquivo){
//ordena os exercitos por numero de vitorias
    std::vector <Exercito*> tabela = exercitos;
    std::sort(tabela.begin(),tabela.end(), [](Exercito* a, Exercito* b){
        return a->getVitorias() > b->getVitorias();
    });

    // Escolhe a saida: tela ou arquivo
    std::ofstream saida;
    if (!arquivo.empty()) {
        saida.open(arquivo);
    }
    std::ostream& out = arquivo.empty() ? std::cout : saida;
 
    out << "------- Tabela de Posicoes -------" << std::endl;
    int posicao = 1;
    for (Exercito* e : tabela) {
        out << posicao << ". " << e->getNome() << " - " << e->getPontos()
            << " pontos - " << e->getResultados() << std::endl;
        posicao++;
    }
}

void Campanha::mostrarUnidadeMaisDestrutiva() const {
    const Unidade* melhor = nullptr;
    
    std::string nomeExercito;
 
    for (const Exercito* e : exercitos) {
        for (const Unidade* u : e->getUnidades()) {
            if (melhor == nullptr || u->getDestruicoes() > melhor->getDestruicoes()) {
                melhor = u;
                nomeExercito = e->getNome();
            }
        }
    }
 
    if (melhor != nullptr) {
        std::cout << "Unidade mais destrutiva: " << melhor->getTipo()
                  << " do exercito " << nomeExercito << " com "
                  << melhor->getDestruicoes() << " destruicoes" << std::endl;
    }
}