#pragma once

#include <string>

class Date {
  public:
    Date(int dia, int mes, int ano);

    std::string formatarData();

  private:
    int dia;
    int mes;
    int ano;
};
