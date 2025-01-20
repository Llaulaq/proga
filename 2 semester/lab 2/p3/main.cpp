#include <iostream>
#include <fstream>

/* Var 1
Вам дано поле размерами NхM (2<=N,M<=100). В каждой клетке поля находятся символы:
‘.’ - можно пройти;
‘#’ - нельзя пройти;
‘S’ - начальная клетка;
‘E’ - конечная клетка;
Напишите алгоритм, который определит минимальное количество шагов для перемещения из начальной клетки в конечную. 
Если это сделать невозможно, выведите -1. Ходить во все соседние клетки, которые отмечены ‘.’ 
(в том числе и по диагонали).
*/

const int MAX_SIZE{ 100 };

void search(int i, int j, int step, 
            int n, int m, char field[MAX_SIZE][MAX_SIZE], int table[MAX_SIZE][MAX_SIZE]) {
    if (step >= table[i][j]) {
        return;
    }

    table[i][j] = step;

    if(field[i][j] == 'E') {
        return;
    }
        
    if (i + 1 < n && field[i + 1][j] != '#')
        search(i + 1, j, step + 1, n, m, field, table);
    if (i - 1 >= 0 && field[i - 1][j] != '#')
        search(i - 1, j, step + 1, n, m, field, table);
    if (j + 1 < m && field[i][j + 1] != '#')
        search(i, j + 1, step + 1, n, m, field, table);
    if (j - 1 >= 0 && field[i][j - 1] != '#')
        search(i, j - 1, step + 1, n, m, field, table);
    if (i + 1 < n && j + 1 < m && field[i + 1][j + 1] != '#') 
        search(i + 1, j + 1, step + 1, n, m, field, table);
    if (i - 1 >= 0 && j - 1 >= 0 && field[i - 1][j - 1] != '#')
        search(i - 1, j - 1, step + 1, n, m, field, table);
    if (i + 1 < n && j - 1 >= 0 && field[i + 1][j + 1] != '#') 
        search(i + 1, j - 1, step + 1, n, m, field, table);
    if (i - 1 >= 0 && j + 1 < m && field[i + 1][j + 1] != '#') 
        search(i - 1, j + 1, step + 1, n, m, field, table);
}



bool read(char field[MAX_SIZE][MAX_SIZE], int table[MAX_SIZE][MAX_SIZE], 
            int& n, int& m, int& is, int& js, int& ie, int& je) {
    std::ifstream in("input.txt");
    in >> n >> m;

    if (n < 2 || n > MAX_SIZE || 
        m < 2 || m > MAX_SIZE) {
        std::cerr << "Error: The number of items exceeds the allowed maximum." << '\n';
        return false;
    }

    int s{ 0 };
    int e{ 0 };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            table[i][j] = INT_MAX;
            in >> field[i][j];
            if (field[i][j] == 'S') {
                is = i;
                js = j;
                s++;
            }
            else if (field[i][j] == 'E') {
                ie = i;
                je = j;
                e++;
            }
            else if (field[i][j] != '.' && field[i][j] != '#') {
                std::cerr << "Error: Invalid character." << '\n';
                return false;
            }
        } 
    }

    if (s != 1) {
        std::cerr << "Error: Multiple starting points or lack thereof." << '\n';
        return false;
    }
    if (e != 1) {
        std::cerr << "Error: Multiple finish points or lack thereof." << '\n';
        return false;
    }

    return true;
}




int main() {
    int n{ 0 };
    int m{ 0 };
    char field[MAX_SIZE][MAX_SIZE];
    int table[MAX_SIZE][MAX_SIZE];

    int is{ 0 };
    int js{ 0 };
    int ie{ 0 };
    int je{ 0 };

    if (!read(field, table, n, m, is, js, ie, je)) {
        return -1;
    }

    search(is, js, 0, n, m, field, table);

    std::cout << table[ie][je] << '\n';

    return 0;
}