// NOde.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#define MAXSIZE 1000
using namespace std;
struct Node
{
    char data;
    Node* next;
};

struct mstack
{
    char mas[MAXSIZE];
    int n = -1;
};

void mpush(mstack* a, char letter)
{
    a->n++;
    a->mas[a->n] = letter;
}
char mpop(mstack* a)
{
    a->n--;
    return a->mas[a->n + 1];
}
int minit(mstack* a, char* s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        mpush(a, s[i]);
        i++;
    }
    mpop(a);
    int size = i - 1;
    return size;
}
void mcheck(mstack* a, int size, char *s)
{
    int i = 0;
    while ((i < size) && (mpop(a) == s[i]))
    {
        i++;
    }
    cout << "RESULT: ";
    if (i == size)
    {
        cout << "PALINDROME" << endl;
    }
    else
    {
        cout << "NOT A PALINDROME" << endl;
    }
}


int npush(Node** head, char c)
{
    Node* foo = new Node;
    if (foo != NULL)
    {
        foo->data = c;
        foo->next = *head;
        *head = foo;
    }
    else
    {
        return 1;
    }
    
    
}
char npop(Node** head) {
    if (*head == NULL)
    {
        return '\0';
    }
    Node* foo = *head;
    char save = foo->data;
    *head = (*head)->next;
    delete foo;
    return save;
}
int main()
{
    
    mstack a;
    Node* head = NULL;
    char s[MAXSIZE];

    
    
    cout << "'A' and 'a' are different letters, be careful" << endl;
    cout << "Please, input line to check: ";

    // massive method
    fgets(s, MAXSIZE, stdin);
    int size = minit(&a, s);
    mcheck(&a, size, s);
    

    //Node method
    int i = 0;
    while (s[i] != '\0')
    {
        npush(&head, s[i]);
        i++;
    }
    npop(&head);
    i = 0;
    while ((i < size) && (npop(&head) == s[i]))
    {
        i++;
    }
    cout << "RESULT: ";
    if (i == size)
    {
        cout << "PALINDROME" << endl;
    }
    else
    {
        cout << "NOT A PALINDROME" << endl;
    }
    return 0;
}
