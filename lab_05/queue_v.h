#ifndef LAB_05_QUEUE_V_H
#define LAB_05_QUEUE_V_H

#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

typedef struct list_queue
{
    int time_arrived[30000];
    int time_service[30000];
    int head;
    int tail;
} lq;

lq vip;
lq basic;
void v_init_vip(int size, int t_arrived_max, int t_arrived_min, int t_service_max, int t_service_min)
{
    srand(time(NULL));
    //unsigned long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        vip.time_arrived[i] = rand() % (t_arrived_max - t_arrived_min) + t_arrived_min;
        vip.time_service[i] = rand() % (t_arrived_max - t_service_min) + t_service_min;
        //sum += vip.time_arrived[i];
    }
    for (int i = 1; i < size; i++)
    {
        vip.time_arrived[i] += vip.time_arrived[i - 1];
    }
    vip.head = 0;
    vip.tail = size;
    //cout << sum / size;
}
void v_init_basic(int size, int t_arrived_max, int t_arrived_min, int t_service_max, int t_service_min)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        basic.time_arrived[i] = rand() % (t_arrived_max - t_arrived_min) + t_arrived_min;
        basic.time_service[i] = rand() % (t_service_max - t_service_min) + t_service_min;
        
    }
    for (int i = 1; i < size; i++)
    {
        basic.time_arrived[i] += basic.time_arrived[i - 1];
    }
    basic.head = 0;
    basic.tail = size;
}
void v_output(int size, int mode) // mode: 1 - only vip, 2 - only basic, 3 - all
{
    if (mode == 1)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "vip[" <<  i << "]: ";
            cout << "time arrived: " << vip.time_arrived[i] << " ";
            cout << "time service: " << vip.time_service[i] << endl;
        }
    }
    else if (mode == 2)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "basic[" << i << "]: ";
            cout << "time arrived: " << vip.time_arrived[i];
            cout << "time service: " << vip.time_service[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << "vip[" << i << "]: ";
            cout << "time arrived: " << vip.time_arrived[i];
            cout << "time service: " << vip.time_service[i] << endl;
        }
        cout << endl << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "basic[" << i << "]: ";
            cout << "time arrived: " << vip.time_arrived[i];
            cout << "time service: " << vip.time_service[i] << endl;
        }
    }
}
void avr() //just for debug
{
    unsigned long long sum = 0;
    for (int i = 0; i < vip.tail; i++)
    {
        sum += vip.time_service[i];
    }
    cout << sum / vip.tail;
}

void worker(int t_arrived_max, int t_arrived_min, int t_service_max, int t_service_min)
{
    int timer = 0;
    vip.head = 0;
    basic.head = 0;
    bool is_second_in_oa = false;
    bool is_vip_in_oa = false;
    int throwed = 0;
    int second = 0;
    int succes = 0;
    while (vip.head <= 1000)
    {
        // Если пришла вип заявка
        if (vip.time_arrived[vip.head] <= timer)
        {
            is_vip_in_oa = true;
            if (!(vip.head % 100))
            {
                cout << "time is: " << (double)timer / 1000 << endl;
                cout << "served : " << vip.head << endl;
            }
            if (is_second_in_oa == true)
            {
                // Если вторая заявка в ОА
                // убрать вторую заявку в хвост
                basic.head++;
                throwed++;
            }
            timer += vip.time_service[vip.head];
            vip.head++;
        }
        // Если вип заявки нет
        else
        {   
            if (is_second_in_oa == false) // Если заявки второго типа нет в аппарате
            {
                if (basic.time_arrived[basic.head] <= timer)
                {
                    is_second_in_oa = true; // Вторая заявка в аппарате
                }
            }
            if (is_second_in_oa == true) // Вторая заявка была в аппарате
            {
                basic.time_service[basic.head]--;
                second++;
                /*if (second > 1200)
                {
                    cout << "time is" << timer << endl;
                    cout << "basic " << basic.time_service[basic.head] << endl;
                }*/
                if (basic.time_service[basic.head] <= 0)
                {
                    basic.head++;
                    succes++;
                }
            }
            timer++;
        }
    }
    int result_error;
    if ((t_arrived_max - t_arrived_min) >= (t_service_max - t_service_min))
    {
        result_error = 1000 * (t_arrived_max + t_arrived_min) / 2;
    }
    else
    {
        result_error = 1000 * (t_service_max + t_service_min) / 2;
    }
    cout << "succes            :" << succes << endl;
    cout << "time spend        :" << (double)timer / 1000 << endl;
    cout << "\'throwed\'         :" << throwed << endl;
    cout << "error koeffecient :" << fabs((double)(result_error - timer)) / result_error * 100 << "%";
}

#endif //LAB_05_QUEUE_V_H