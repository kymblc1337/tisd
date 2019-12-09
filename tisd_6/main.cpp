#include <iostream>
#include "defines.h"
#include "hash.h"
#include "tree.h"

using namespace std;


//9 10 7 9 12 6 14 11 3 4

int main()
{
    List mas_list[ASIZE];
    int n;
    int dat;
    int h;
    cin >> n;
    int sfor = 15;
    tree_Node *head = NULL;

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
        tree_insert(&head, dat);
    }
    for (int i = 0; i < ASIZE; i++)
    {
        cout << "[" << i << "]";
        Queue_output(&(mas_list[i]));
    }
    cout << "Hash table search res: " << hash_list_search(mas_list, sfor) << endl;




    // Tree method

//    for (int i = 0; i < n; i++)
//    {
//        cin >> dat;
//        tree_insert(&head, dat);
//    }
    printWithLvls(head, 0);
    tree_Node *test = get_Node_by_value(head, sfor);
    if (test == NULL)
    {
        cout << "Tree search res 0";
    }
    else
    {
        cout << "Tree search res 1";
    }

    return 0;
}