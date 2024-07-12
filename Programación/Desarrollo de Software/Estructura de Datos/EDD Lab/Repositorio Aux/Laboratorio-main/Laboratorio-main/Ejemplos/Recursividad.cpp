#include <iostream>
using namespace std;

int factorialIterativo(int num)
{
    int resultado = 1;
    for (int i = 2; i <= num; i++)
    {
        cout << "i: " << i << endl;
        resultado = resultado * i;
    }
    return resultado;  
}

int factorialRecursivo(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    else 
    {
        return num * factorialRecursivo(num - 1);
    }
    
}

/*
0! = 1
1! = !
2! = 2 * 1!
3! = 3 * 2!
$! = 4 * 3!
n! = n * (n-1)!
*/

int main()
{
    cout << "Factorial: " << factorialRecursivo(5) << endl;
    return 0;
}