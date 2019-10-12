#include <termios.h>
#include <unistd.h>
#include <string>
#include <locale.h>
#include <iostream>
#include <cstring>

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

using namespace std;
typedef struct flat
{
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
    for (int i = 0; i <= 80; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "L. Загрузить базу данных из памяти" << endl;
    cout << "A. Добавить запись в базу данных" << endl;
    cout << "S. Сохранить базу данных в память" << endl;
    for (int i = 0; i <= 80; i++)
    {
        cout << "-";
    }
    cout << endl << ">>";
    char user_choice = _getche();
    cout << endl << endl;
    return all_to_small_register(user_choice);
}
void data_output()
{
    cout << "+--------------------+-------+-------------+---------------+---------+---------+--------------+-------+--------+--------+" << endl;
    cout << "|Address             |Area   |Num of rooms |cost per meter |type     |finish   |year of build |Owners |Tenatns |Animals |" << endl;
    cout << "|                    |       |             |               |         |         |              |       |        |        |" << endl;
    cout << "+--------------------+-------+-------------+---------------+---------+---------+--------------+-------+--------+--------+" << endl;
    cout << endl;

}
void flat_input(flat* a)
{
    int type;
    char fin;
    cout << "Input type of flat(1 - primary, 2 - secondary: ";
    cin >> type;
    while (!((type == 1) || (type == 2)))
    {
        cout << "Something went wrong!\nInput type of flat(1 - primary, 2 - secondary: ";
        cin >> type;
    }
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
            cout << "Is there an finish in the apartment?(Y/N)";
            cin >> fin;
            fin = all_to_small_register(fin);
            while (!((fin == 'y') || (fin == 'n')))
            {
                cout << "Something went wrong!\nIs there an finish in the apartment?(Y/N)";
                cin >> fin;
                fin = all_to_small_register(fin);
            }
            if (fin == 'y')
            {
                a->is_finish = true;
            }
            else
            {
                a->is_finish = false;
            }
    }
    else
    {
        int a = 3;
        a++;
    }
}

// адрес 19
// площадь 7
// число комнат 12
// цена метра 10
// тип жилья 9
// отделка 7
// год постройки 13
// владельцы 9
// жильцы 6
// животные 8
int main()
{
    setlocale(LC_ALL, "RUS");
    flat a;
    flat_input(&a);
    data_output();
    //primary_output(a);
    /*
    char user_choice = ' ';
    user_choice = menu();
    do
    {
        user_choice = menu();
    } while (1);
    */
    return 0;
}
