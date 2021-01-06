
//
//  main.cpp
//  PrimsMinSpanningTree
//
//  Created by SAID BENAISSA on 06/01/2021.
//

#include <iostream>

int32_t I = INT_MAX;
using namespace std;

int cost[][8] = {{I, I,  I,  I,  I,  I,  I,  I},
                 {I, I,  25, I,  I,  I,  15, I},
                 {I, 25, I,  12, I,  I,  I,  10},
                 {I, I,  12, I,  8,  I,  I,  I},
                 {I, I,  I,  8,  I,  16, I,  14},
                 {I, I,  I,  I,  16, I,  20, 18},
                 {I, 5,  I,  I,  I,  20, I,  I},
                 {I, I,  10, I,  14, 18, I,  I}};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][7];


int main() {
    int i, j, k, u, v, n = 7, min = I;

    //    This part detect the minimum cost edge in the matrix cost
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                /* Min edge has been detected then set indices of min vertices (u,v) = (i,j)  min */
                u = i;
                v = j;

            }
        }
    }

    //    Now we have to store this min edge value in the spanning matrix t
    t[0][0] = u;
    t[1][0] = v;
    //    Update near array in order to not check it another time, because we have already include the solution for those vertices
    near[u] = near[v] = 0;

    //    initialise near array by checking the minimum

    for (i = 1; i <= n; i++) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }


    //    REPEATING PART
    for (i = 1; i < n - 1; i++) {
        min = I;
        for (j = 1; j <= n; j++) {
            if ((near[j] != 0) && (cost[j][near[j]] < min)) {
                // We get k with the minimum value
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; j++) {
            if ((near[j] != 0) && (cost[j][k] < cost[j][near[j]]))
                near[j] = k;
        }
    }

    for (i = 0; i < n - 1; i++) {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;

    }
}


// git commit a - rebase test
// git commit b - rebase test