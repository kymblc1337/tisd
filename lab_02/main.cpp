#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <locale.h>
#include <iostream>
#include <cstring>
#include "header.h"
#include <ctime>


using namespace std;

int main()
{
	FILE* f;
	f = fopen("db.txt", "w");
	fclose(f);
    setlocale(LC_ALL, "RU");
    flat mas[100];
	int n = 0;
    /*int n = 2;                   // Длина массива
	//####################################################################
    a = {};
    strcpy_s(a.address, "Solovinya_rocha");
    a.mode = 1;
	a.area = 125;
	a.cost_per_meter = 25000;
	a.number_of_rooms = 5;
    mas[0] = a;
	a.mode = 2;
	a.area = 70;
	a.cost_per_meter = 7000;
	a.number_of_rooms = 2;
	a.secondary.animals = true;
	a.secondary.number_of_livers = 2;
	a.secondary.number_of_owners = 5;
	a.secondary.year_of_build = 2007;
	strcpy_s(a.address, "Balashiha");
	mas[1] = a;
	//####################################################################
	*/
    int user_choice = 0;
    do
    {
        user_choice = menu();
        switch (user_choice)
        {
            case 1:
				header_output();
				for (int i = 0; i < n; i++)
				{
					flat_output(mas[i]);
				}
				break;

            case 2:
                flat_input(&(mas[n]));
                n++;
                break;

			case 3:
				mysort(mas, n);
				break;
			case 5:
				f = fopen(dbfilename, "w");
				fprintf(f, "%-3d\n", n);
				for (int i = 0; i < n; i++)
				{
					write_building_in_file(f, mas[i]);
				}
				fclose(f);
				break;
			case 0:
				f = fopen(dbfilename, "r");
				fscanf(f, "%3d", &n);
				for (int i = 0; i < n; i++)
				{
					read_building_from_file(f, &mas[i]);
				}
				fclose(f);
				break;
            default:
                cout << endl;
                break;
        }
    } while (1);
    return 0;
}
















