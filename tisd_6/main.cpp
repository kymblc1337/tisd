#include <iostream>
#include "defines.h"
#include "hash.h"
#include "tree.h"

using namespace std;


int main()
{
    List mas_list[ASIZE];
    int n;
    int dat;
    int h;
    cin >> n;

    // Hash func
    for (int i = 0; i < ASIZE; i++)
    {
        Creation(&(mas_list[i]));
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dat;
        h = hash_func(dat);
        Add(&(mas_list[h]), dat);
    }
    for (int i = 0; i < ASIZE; i++)
    {
        cout << "[" << i << "]";
        Queue_output(&(mas_list[i]));
    }




    // Tree method
    tree_Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> dat;
        tree_insert(&head, dat);
    }
    printWithLvls(head, 1);
    return 0;
}