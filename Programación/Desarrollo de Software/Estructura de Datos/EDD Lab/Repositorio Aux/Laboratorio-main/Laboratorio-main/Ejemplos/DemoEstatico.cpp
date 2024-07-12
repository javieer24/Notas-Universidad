#include <iostream>
using namespace std;
#include "Estatico.h"

int main(){
    Estatico d1; //Declaración estatica, el objeto se almacena en stack
    Estatico *d2 = new Estatico(); //Declaración dinamica, el objeto se almacena en heap
    //Estatico *d5;
    //cout << "Valor d5: " << d5->valor;
    cout << d1.valor << endl; //Variable 'cuenta' está almacenada en stack
    cout << d2->valor << endl; //Variable 'cuenta' está almacenada en heap
    cout << Estatico::cuenta; //Está almacenada en el segmento Dato
    if (true)
    {
        Estatico d3(88);
        Estatico *d4 = new Estatico(89);
        //d5 = new Estatico(90);
        //cout << "Valor d5: " << d5->valor;
        cout << "\nObjeto estatico: " << Estatico::cuenta << endl;
        cout << d3.valor << endl;
        //delete d4;
    }
    cout << "\nObjeto estatico: " << Estatico::cuenta << endl;

    return 0;
}