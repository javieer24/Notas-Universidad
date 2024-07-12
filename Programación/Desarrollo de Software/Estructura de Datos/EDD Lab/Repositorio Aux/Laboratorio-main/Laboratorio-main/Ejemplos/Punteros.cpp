#include <iostream>
using namespace std;


int main(){
    int num = 7;
    int n;
    int *puntero;
    cout << puntero << endl;
    puntero = &num;
    cout << puntero << endl;
    cout << num << endl;
    cout << *puntero << endl;
    cout << &puntero << endl;
    num = 10;
    cout << *puntero << endl;
    *puntero = 20;
    cout << num << endl; 

    return 0;
}