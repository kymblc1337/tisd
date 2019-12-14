//
// Created by Тимон on 10.12.2019.
//

#ifndef TISD_6_BALANCE_TREE_H
#define TISD_6_BALANCE_TREE_H

#include <stdio.h>
#include <stdlib.h>

struct rb_node
{
    int red;
    int data;
    rb_node *link[2];
};

struct rb_tree
{
    rb_node *root;
    int count;
};

int is_red (rb_node *node )
{
    if (node != NULL && node->red == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct rb_node *make_node ( int data )
{
    rb_node *rn = new rb_node;

    if ( rn != NULL ) {
        rn->data = data;
        rn->red = 1; // red
        rn->link[0] = NULL;
        rn->link[1] = NULL;
    }
    return rn;
}

struct rb_node *rb_single ( struct rb_node *root, int dir )
{
    struct rb_node *save = root->link[!dir];

    root->link[!dir] = save->link[dir];
    save->link[dir] = root;

    root->red = 1;
    save->red = 0;

    return save;
}


struct rb_node *rb_double (rb_node *root, int dir)
{
    root->link[!dir] = rb_single ( root->link[!dir], !dir );
    return rb_single ( root, dir );
}

int rb_insert ( struct rb_tree *tree, int data )
{

    if ( tree->root == nullptr ) {
        tree->root = make_node ( data );
        if ( tree->root == NULL )
            return 0;
    }
    else {
        struct rb_node head = {0};
        struct rb_node *g, *t;     // grand parent and parent
        struct rb_node *p, *q;     // parent
        int dir = 0, last;


        t = &head;
        g = p = NULL;
        q = t->link[1] = tree->root;

        for ( ; ; )
        {
            if ( q == NULL ) {
                // node inserting
                p->link[dir] = q = make_node ( data );
                tree->count ++ ;
                if ( q == NULL )
                    return 0;
            }
            else if ( is_red ( q->link[0] ) && is_red ( q->link[1] ) )
            {
                // color change
                q->red = 1;
                q->link[0]->red = 0;
                q->link[1]->red = 0;
            }
            // equals of 2 red nodes
            if ( is_red ( q ) && is_red ( p ) )
            {
                int dir2 = t->link[1] == g;

                if ( q == p->link[last] )
                    t->link[dir2] = rb_single ( g, !last );
                else
                    t->link[dir2] = rb_double ( g, !last );
            }

            // if root exists => exit
            if ( q->data == data )
            {
                break;
            }

            last = dir;
            dir = q->data < data;

            if ( g != NULL )
                t = g;
            g = p, p = q;
            q = q->link[dir];
        }

        // update root
        tree->root = head.link[1];
    }
    // root is black
    tree->root->red = 0;

    return 1;
}

int rb_serch (rb_tree *tree, int data)
{
    int counter = 0;
    rb_node *tmp;
    tmp = tree->root;
    while (tmp) {
        if (tmp->data > data) {
            tmp = tmp->link[0];
            counter++;
            continue;
        } else if (tmp->data < data) {
            tmp = tmp->link[1];
            counter++;
            continue;
        } else {
            return counter;
        }
    }
    return -1;
}

void printrbtree (rb_node *w, int lvl)
{
// *w - указатель на корень дерева
// lvl - уровень вершины
    if  (w != NULL)
    {
        printrbtree (w->link[1], lvl + 1);
        for (int i = 0; i < lvl; i++)
            cout<< "      ";
        cout << w->data << "\n";
        printrbtree (w->link[0], lvl + 1);
    }
}


#endif //TISD_6_BALANCE_TREE_H
