// lab_05_tisd.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "queue_v.h"

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * *
     * oa is an apparat, that service the requests *
     *     requests has two types: vip and basic   *
     *   if it's time to service the vip request   *
     *   we have to do it, no matter is it basic   *
     *   request in oa now. If it is, we have to   *
     *            throw it away                    *
     * * * * * * * * * * * * * * * * * * * * * * * */

int main()
{

    v_init_vip(1000, 5000, 1000, 4000, 0);
    v_init_basic(20000, 3000, 0, 1000, 0);
    //v_output(100, 1);
    worker(5000, 1000, 4000, 0);
    return 0;
}


