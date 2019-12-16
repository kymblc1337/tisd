#include <iostream>
#include <stdlib.h>
#include "capital.h"
#include "matrix_cdio.h"
#include "matrix_func.h"
#include <stdio.h>


/*
4
0 50 20 0
0 0 0 0
0 30 0 40
0 0 0 0
 */

using namespace std;
int main()
{
    struct matrix mas;
    int n, m;
    bool cycles = false;

    int maxWayLen, maxWayFrom, maxWayTo;

    scanf("%d", &n);
    matrix_crate(&mas, n, n);
    matrix_input(&mas, n, n);
    matrix_painter(mas);

    for (int i = 0 ; i < n; i++)
    {
        color_blind();
        cycleFinder(mas, 0, &cycles);
        if (cycles) {
            cout << "Cycles found!" << endl;
            return 0;
        }
    }
    color_blind();

    for (int i = 0; i < n; i++)
    {
        color[i] = WHITE;
        s[i] = 0;
    }

    dfsMaximalWay(mas, &maxWayLen, &maxWayFrom, &maxWayTo);

    cout << "Max way length is: " << maxWayLen << endl;
    cout << "From point " << maxWayFrom + 1 << " to point " << maxWayTo + 1;

    return 0;
}