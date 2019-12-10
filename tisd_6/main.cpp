#include <iostream>
#include "defines.h"
#include "hash.h"
#include "tree.h"
#include "balance_tree.h"

using namespace std;


//9 10 7 9 12 6 14 11 3 4

int main()
{

    // for balansed tree
    rb_tree my_tree;
    my_tree.root = NULL;

    // for hash-table
    List mas_list[ASIZE];
    int h;

    // for basic tree
    tree_Node *head = NULL;

    // global var
    int n;
    cin >> n;
    int dat;
    int sfor = 15;


    for (int i = 0; i < ASIZE; i++)
    {
        Creation(&(mas_list[i]));
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dat;
        h = hash_func(dat);
        Add(&(mas_list[h]), dat); // inserting in hash table
        tree_insert(&head, dat); // inserting in basic tree
        rb_insert(&my_tree, dat); // inserting in balansed_tree
    }
    cout << "Input value we are searching for:";
    cin >> sfor;

    // Output what we have read
    cout << "baisc tree:" << endl;
    printWithLvls(head, 1);
    cout << endl << endl << endl;
    cout << "balansed tree:" << endl;
    printrbtree(my_tree.root, 0);
    for (int i = 0; i < ASIZE; i++)
    {
        cout << "[" << i << "]";
        Queue_output(&(mas_list[i]));
    }

    // searching
    cout << "Hash table search res: " << hash_list_search(mas_list, sfor) << endl;

    tree_Node *ts = get_Node_by_value(head, sfor);
    if (ts == NULL)
    {
        cout << "Tree search res 0";
    }
    else
    {
        cout << "Tree search res 1";
    }

    rb_node *rbts = rb_serch(&my_tree, sfor);
    if (rbts == NULL)
    {
        cout << "Balansed tree search res 0";
    }
    else
    {
        cout << "Balansed tree search res 1";
    }

    return 0;

}