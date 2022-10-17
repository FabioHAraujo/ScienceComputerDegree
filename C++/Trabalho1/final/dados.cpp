#include <iomanip>
#include <iostream>

using namespace std;
/*
void getBagagemInfo (bagagem array[], int selectBag)
{
    std::cout << "Numeracao da Bagagem: " << array[selectBag].numBagagem << std::endl;
    std::cout << "Tipo da mala: " << array[selectBag].tipoMala << std::endl;

    return;
}
*/
// void é utilizado para retornar nada ao fim de uma operação. O Void tem prioridade inforior à uma função int, por isso sempre será executado após a função inteira.

int atributos(int forca, int destreza, int magia, int vida, int velocidade)
{
    int atributosGerais;
    atributosGerais = forca+destreza+magia+vida+velocidade;
    return atributosGerais;
}