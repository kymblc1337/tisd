#include <termios.h>
#include <unistd.h>
#include <string>
#include <locale.h>
#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    flat a;
    flat mas[100];
    int n = 1;                   // Длина массива
    a = {};
    strcpy(a.address, "JOPA");
    a.mode = 1;
    mas[0] = a;
    char user_choice = ' ';
    do
    {
        user_choice = menu();
        switch (user_choice)
        {
            case 'p':
                header_output();
                for (int i = 0; i < n; i++)
                {
                    flat_output(mas[i]);
                }
                break;
            case 'a':
                flat_input(&(mas[n]));
                n++;
                break;
            default:
                cout << endl;
                break;
        }
    } while (1);
    return 0;
}

















