#pragma once

#include <vector>
#include <string>

#include "Batalha.hpp"
#include "Exercito.hpp"

class Campanha{

private:
//vetor de batalhas e ponteiros para os exercitos das campanhas
    std::vector<Batalha*> batalhas;
    std::vector<Exercito*> exercitos;

public:

Campanha();
~Campanha();

void addExercito(Exercito* exercito);

void simularBatalhas();
void gerarTabelaDePosicoes(const std::string& nomeArquivo = "");
void mostrarUnidadeMaisDestrutiva() const


};


