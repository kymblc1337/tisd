#include <termios.h>
#include <unistd.h>
#include <string>
#include <locale.h>
#include <iostream>
#include <cstring>
using namespace std;
// адрес 20
// площадь 7
// число комнат 13
// цена метра 15
// тип жилья 9
// отделка 9
// год постройки 14
// владельцы 7
// жильцы 7
// животные 8
int _getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
typedef struct flat
{
    int mode;
    char address[20];
    int area;
    int number_of_rooms;
    double cost_per_meter;
    union
    {
        bool is_finish;
        int year_of_build;
        int number_of_owners;
        int number_of_livers;
        bool animals;
    };
} flat;
char all_to_small_register(char ch)
{
    const char* big =   "QWERTYUIOPASDFGHJKLZXCVBNM";
    const char* small = "qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i < int(strlen(big)); i++)
    {
        if (ch == big[i])
        {
            return small[i];
        }
    }
    return ch;
}
char menu()
{
    char user_choice = ' ';
    for (int i = 0; i <= 80; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "L. Загрузить базу данных из памяти" << endl;
    cout << "A. Добавить запись в базу данных" << endl;
    cout << "P. Вывести базу данных на экран" << endl;
    cout << "S. Сохранить базу данных в память" << endl;
    for (int i = 0; i <= 80; i++)
    {
        cout << "-";
    }
    cout << endl << ">>";
    user_choice = _getche();
    cout << endl << endl;
    return all_to_small_register(user_choice);
}
void header_output()
{
    cout << "+--------------------+-------+-------------+---------------+---------+---------+--------------+-------+--------+--------+" << endl;
    cout << "|Address             |Area   |Num of rooms |cost per meter |type     |finish   |year of build |Owners |Tenatns |Animals |" << endl;
    cout << "|                    |       |             |               |         |         |              |       |        |        |" << endl;
    cout << "+--------------------+-------+-------------+---------------+---------+---------+--------------+-------+--------+--------+" << endl;
}
void flat_output(flat fl)
{
    printf("|");
    printf("%-20s|", fl.address);
    printf("%-7d|", fl.area);
    printf("%-13d|", fl.number_of_rooms);
    printf("%-15.2lf|", fl.cost_per_meter);
    if (fl.mode == 1)
    {
        printf("primary  |");
        if (fl.is_finish)
        {
            printf("%-9s|", "yes");
        }
        else
        {
            printf("%-9s|", "no");
        }
        printf("%-14s|", "");
        printf("%-7s|", "");
        printf("%-8s|", "");
        printf("%-8s|\n", "");
    }
    else {
        printf("secondary|");
        printf("%-9s|", " ");
        printf("%-14d|", fl.year_of_build);
        printf("%-7d|", fl.number_of_owners);
        printf("%-8d|", fl.number_of_livers);
        if (fl.animals)
        {
            printf("%-8s|\n", "yes");
        }
        else
        {
            printf("%-8s|\n", "no");
        }
    }
    cout << "+--------------------+-------+-------------+---------------+---------+---------+--------------+-------+--------+--------+" << endl;
}
void flat_input(flat* a)
{
    int type;
    int cur;
    cout << "Input type of flat(1 - primary, 2 - secondary): ";
    cin >> type;
    a->mode = type;
    while (!((type == 1) || (type == 2)))
    {
        cout << "Something went wrong!\nInput type of flat(1 - primary, 2 - secondary: ";
        cin >> type;
    }
    cout << "Input address: ";
    cin >> a->address;
    cout << "Input area: ";
    cin >> a->area;
    cout << "Input number of rooms: ";
    cin >> a->number_of_rooms;
    cout << "Input cost per square meter: ";
    cin >> a->cost_per_meter;
    if (type == 1)
    {
    //##########################################################
    //This is primary
        cout << "Is there a finish in the apartament(1-yes, 2 - no)?: ";
        cin >> cur;
        while (!((cur == 1) || (cur == 0)))
        {
            cin >> cur;
        }
        if (cur == 1)
        {
            a->is_finish = true;
        } else
        {
            a->is_finish = false;
        }
    }
    else
    {
        cout << "Input year of build: ";
        cin >> a->year_of_build;
        cout << "Input number of owners: ";
        cin >> a->number_of_owners;
        cout << "Input number of Tenatns: ";
        cin >> a->number_of_livers;
        cout << "Were there an animals in the apartament(1-yes, 2 - no)?: ";
        cin >> cur;
        while (!((cur == 1) || (cur == 0)))
        {
            cin >> cur;
        }
        if (cur == 1)
        {
            a->animals = true;
        } else
        {
            a->animals = false;
        }
    }
}

