// lab_05_tisd.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "queue_v.h"

using namespace std;

int main()
{
    v_init_vip(1000, 5000, 1000, 4000, 0);
    v_init_basic(20000, 3000, 0, 1000, 0);
    v_output(100, 1);
    worker(5000, 1000, 4000, 0);
    return 0;
}


