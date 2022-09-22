#include <iostream>
#include <iomanip>
#include <string>

struct bagagem
{
    int numBagagem;
    std::string tipoMala;
};

void getBagagemInfo (bagagem array[], int selectBag)
{
    std::cout << "Numeracao da Bagagem: " << array[selectBag].numBagagem << std::endl;
    std::cout << "Tipo da mala: " << array[selectBag].tipoMala << std::endl;

    return;
}


int main ()
{
    int selectBag, qtdBagagem, count=0, tipo;
    std::cout << "Ola senhor, quantas bagagens esta trazendo? ";
    std::cin >> qtdBagagem;
    bagagem arrayBagagem[qtdBagagem];
    while (count<qtdBagagem)
    {
        std::cout << "O senhor esta inserindo os dados de sua bagagem numero: " << count+1 << std::endl;
        std::cout << "Qual o tipo desta bagagem? \n" << "1 - De mao\n" << "2 - De Carga\n";
        std::cin >> tipo;
        if (tipo==1)
        {
            arrayBagagem[count].tipoMala = "De Mao";
        }
        else if (tipo==2)
        {
            arrayBagagem[count].tipoMala = "De Carga";
        }
        arrayBagagem[count].numBagagem=count+1;
        count++;
    }

    std::cout << "Agora que inseriu os dados, qual bagagem gostaria de levar consigo? (eh permitido carregar apenas uma pelo hotel)" << std::endl;
    std::cin >> selectBag;
    selectBag-=1;

    getBagagemInfo(arrayBagagem, selectBag);

    return 0;
}