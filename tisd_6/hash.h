//
// Created by Тимон on 10.12.2019.
//

#ifndef TISD_6_HASH_H
#define TISD_6_HASH_H

#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    int size;
    Node *first;
    Node *last;
};

void Creation(List *Q)
{
    Q->first=new Node;
    Q->first->next= NULL;
    Q->last=Q->first;
    Q->size=0;
}

void Add(List *Q, int data)
{
    Q->last->next=new Node;
    Q->last=Q->last->next;
    Q->last->data = data;
    Q->last->next=NULL;
    Q->size++;
}

int hash_func(int x)
{
    return x % ASIZE;
}

void Queue_output(List *Q)
{
    if (Q->size == 0)
    {
        cout << " NULL" << endl;
    }
    else
    {
        Node *out = Q->first;
        for (int i = 0; i < Q->size; i++)
        {
            cout << " -> ";
            cout << out->next->data;
            out = out->next;
        }
        cout << endl;
    }
}
bool hash_list_search(List *mas, int data)
{
    int h = hash_func(data);
    Node *nd = mas[h].first;
    while (nd->next != NULL)
    {
        if (nd->next->data == data)
        {
            return true;
        }
        nd = nd->next;
    }
    return false;
}

#endif //TISD_6_HASH_H
