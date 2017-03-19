#include <iostream>
#include <sstream>
#include <string>

#ifdef _WIN32

#include <cstdlib>
#include <windows.h>

#define sleep Sleep
#define WAIT 3000
#define WAIT2 8000
#define CLEAN "cls"
#define LOCATE system("chcp 65001")
#endif

#ifdef __gnu_linux__
#define WAIT 3
#define WAIT2 8
#define CLEAN "clear"
#include <unistd.h>
#define LOCATE NULL
#endif

using namespace std;

/*
 * Dynamiczne tworzenie i usuwanie tablicy
 * */

void createTable(char **&table, int how) {
    table = new char *[how];
    for (int i = 0; i < how; i++) {
        table[i] = new char[how];
    }
}

void destroyTable(char **&table, int how) {
    for (int i = 0; i < how; i++) {
        delete[]table[i];
    }
    delete[]table;
}


/*
 * Sztuczna inteligencja
 * */

void mediumCPU(int whoFirst, int ile, int &second, int &first, int how, char **table, bool &end, bool hard = 0) {
    int x, y;
    char sign;
    x = 0;
    y = 0;
    for (int k = 0; k < 2; k++) {
        if (k == 0) {
            if (whoFirst == 1) sign = 'x';
            else sign = 'o';

        } else {
            if (whoFirst == 1) sign = 'o';
            else sign = 'x';

        }
        for (int i = 0; i < how; i++) {
            for (int j = 0; j < how; j++) {
                switch (ile) {
                    case 3:
                        if ((x <= (how - ile)) && table[y][x] == sign && table[y][x + 1] == sign &&
                            table[y][x + 2] == '-') {
                            second = x + 3;
                            first = y + 1;
                            return;
                        } else if ((x <= (how - ile)) && table[y][x] == sign && table[y][x + 2] == sign &&
                                   table[y][x + 1] == '-') {
                            second = x + 2;
                            first = y + 1;
                            return;
                        } else if ((x <= (how - ile)) && table[y][x + 1] == sign && table[y][x + 2] == sign &&
                                   table[y][x] == '-') {
                            second = x + 1;
                            first = y + 1;
                            return;
                        } else if ((y <= (how - ile)) && table[y][x] == sign && table[y + 1][x] == sign &&
                                   table[y + 2][x] == '-') {
                            second = x + 1;
                            first = y + 3;
                            return;
                        } else if ((y <= (how - ile)) && table[y][x] == sign && table[y + 2][x] == sign &&
                                   table[y + 1][x] == '-') {
                            second = x + 1;
                            first = y + 2;
                            return;
                        } else if ((y <= (how - ile)) && table[y + 1][x] == sign && table[y + 2][x] == sign &&
                                   table[y][x] == '-') {
                            second = x + 1;
                            first = y + 1;
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign &&
                                   table[y][x] == '-') {
                            second = x + 1;
                            first = y + 1;
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y][x] == sign &&
                                   table[y + 2][x + 2] == sign &&
                                   table[y + 1][x + 1] == '-') {
                            second = x + 2;
                            first = y + 2;
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == '-') {
                            second = x + 3;
                            first = y + 3;
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 2][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y][x + 2] == '-') {
                            second = x + 3;
                            first = y + 1;
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 2][x] == sign &&
                                   table[y][x + 2] == sign &&
                                   table[y + 1][x + 1] == '-') {
                            second = x + 2;
                            first = y + 2;
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y][x + 2] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x] == '-') {
                            second = x + 1;
                            first = y + 3;
                            return;
                        } else if (k == 1 && j == (how - 1) && i == (how - 1) && !hard) {
                            char checked, checked1;
                            if (sign == 'x') {
                                checked = 'o';
                                checked1 = 'x';
                            } else {
                                checked = 'x';
                                checked1 = 'o';
                            }
                            int xyrandom = rand() % 2 + 0;
                            for (int l = 0; l < 2; l++) {
                                for (int d = 0; d < how; d++) {
                                    for (int c = 0; c < how; c++) {
                                        if (table[c][d] == checked) {
                                            if (l == 0) {
                                                if (((c + 2) < how) &&
                                                    (table[c + 1][d] == checked || table[c + 2][d] == checked) &&
                                                    (table[c + 1][d] != checked1 && table[c + 2][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how) &&
                                                           (table[c - 1][d] == checked || table[c + 1][d] == checked) &&
                                                           (table[c - 1][d] != checked1 &&
                                                            table[c + 1][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 &&
                                                            (table[c - 2][d] == checked ||
                                                             table[c - 1][d] == checked) &&
                                                            (table[c - 2][d] != checked1 &&
                                                             table[c - 1][d] != checked1))) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c + 2) < how &&
                                                            (d + 2) < how) &&
                                                           (table[c + 1][d + 1] == checked ||
                                                            table[c + 2][d + 2] == checked) &&
                                                           (table[c + 1][d + 1] != checked1 &&
                                                            table[c + 2][d + 2] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how &&
                                                            (d - 1) >= 0 && (d + 1) < how) &&
                                                           (table[c - 1][d - 1] == checked ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c - 1][d - 1] != checked1 &&
                                                            table[c + 1][d + 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 &&
                                                            (d - 2) >= 0 &&
                                                            (table[c - 2][d - 2] == checked ||
                                                             table[c - 1][d - 1] == checked) &&
                                                            (table[c - 2][d - 2] != checked1 &&
                                                             table[c - 1][d - 1] != checked1))) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c + 2) < how &&
                                                            (d - 2) >= 0 &&
                                                            (table[c + 1][d - 1] == checked ||
                                                             table[c + 2][d - 2] == checked) &&
                                                            (table[c + 1][d - 1] != checked1 &&
                                                             table[c + 2][d - 2] != checked1))) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how &&
                                                            (d - 1) >= 0 && (d + 1) < how) &&
                                                           (table[c - 1][d + 1] == checked ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 1][d + 1] != checked1 &&
                                                            table[c + 1][d - 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;;
                                                } else if (((c - 2) >= 0 &&
                                                            (d + 2) < how) &&
                                                           (table[c - 2][d + 2] == checked ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 2][d + 2] != checked1 &&
                                                            table[c - 1][d + 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;;
                                                }
                                            } else {
                                                if ((d - 1 >= 0) && (d + 1 < how) &&
                                                    (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                    (table[c][d - 1] == '-' || table[c][d - 1] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 3 + d;
                                                    return;
                                                } else if ((d + 2 < how) &&
                                                           (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                           (table[c][d + 2] == '-' || table[c][d + 2] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 2 + (d + 2);
                                                    return;
                                                } else if ((d - 2 >= 0) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked) &&
                                                           (table[c][d - 2] == '-' || table[c][d - 2] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 2 + (d - 1);
                                                    return;
                                                }
                                                if ((c - 1 >= 0) && (c + 1 < how) &&
                                                    (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                    (table[c - 1][d] == '-' || table[c - 1][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 3 + c;
                                                    return;
                                                } else if ((c + 2 < how) &&
                                                           (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                           (table[c + 2][d] == '-' || table[c + 2][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 2 + (c + 2);
                                                    return;
                                                } else if ((c - 2 >= 0) &&
                                                           (table[c - 1][d] == '-' || table[c - 1][d] == checked) &&
                                                           (table[c - 2][d] == '-' || table[c - 2][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 2 + (c - 1);
                                                    return;
                                                }
                                                if ((c - 1 >= 0) && (d - 1 >= 0) && (c + 1 < how) && (d + 1 < how) &&
                                                    (table[c + 1][d + 1] == '-' ||
                                                     table[c + 1][d + 1] == checked) &&
                                                    (table[c - 1][d - 1] == '-' ||
                                                     table[c - 1][d - 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c;
                                                        second = d;
                                                    }
                                                    return;
                                                } else if ((c >= 0) && (d >= 0) && (c + 2 < how) && (d + 2 < how) &&
                                                           (table[c + 1][d + 1] == '-' ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c + 2][d + 2] == '-' ||
                                                            table[c + 2][d + 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 3;
                                                        second = d + 3;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    }
                                                    return;
                                                } else if ((c - 2 >= 0) && (d - 2 >= 0) && (c < how) && (d < how) &&
                                                           (table[c - 1][d - 1] == '-' ||
                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c - 2][d - 2] == '-' ||
                                                            table[c - 2][d - 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 1;
                                                        second = d - 1;
                                                    }
                                                    return;
                                                }
                                                if ((c - 1 >= 0) && (d - 1 >= 0) && (c + 1 < how) && (d + 1 < how) &&
                                                    (table[c - 1][d + 1] == '-' ||
                                                     table[c - 1][d + 1] == checked) &&
                                                    (table[c + 1][d - 1] == '-' ||
                                                     table[c + 1][d - 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 2;
                                                        second = d;
                                                    }
                                                    return;
                                                } else if ((c - 2 >= 0) && (d >= 0) && (c < how) && (d + 2 < how) &&
                                                           (table[c - 1][d + 1] == '-' ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 2][d + 2] == '-' ||
                                                            table[c - 2][d + 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 1;
                                                        second = d + 3;
                                                    }
                                                    return;
                                                } else if ((c >= 0) && (d - 2 >= 0) && (c + 2 < how) && (d < how) &&
                                                           (table[c + 1][d - 1] == '-' ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c + 2][d - 2] == '-' ||
                                                            table[c + 2][d - 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 2;
                                                        second = d;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 3;
                                                        second = d - 1;
                                                    }
                                                    return;
                                                }
                                                if (d == (how - 1) && c == (how - 1) && l == 1) {
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    case 4:
                        if ((y <= (how - ile)) && table[y][x] == sign && table[y + 1][x] == sign &&
                            table[y + 2][x] == sign &&
                            table[y + 3][x] == '-') {
                            second = x + 1;
                            first = y + 4;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && table[y][x] == sign && table[y + 1][x] == sign &&
                                   table[y + 3][x] == sign &&
                                   table[y + 2][x] == '-') {
                            second = x + 1;
                            first = y + 3;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && table[y][x] == sign && table[y + 2][x] == sign &&
                                   table[y + 3][x] == sign &&
                                   table[y + 1][x] == '-') {
                            second = x + 1;
                            first = y + 2;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && table[y + 1][x] == sign && table[y + 2][x] == sign &&
                                   table[y + 3][x] == sign &&
                                   table[y][x] == '-') {
                            second = x + 1;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((x <= (how - ile)) && table[y][x] == sign && table[y][x + 1] == sign &&
                                   table[y][x + 2] == sign &&
                                   table[y][x + 3] == '-') {
                            second = x + 4;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((x <= (how - ile)) && table[y][x] == sign && table[y][x + 1] == sign &&
                                   table[y][x + 3] == sign &&
                                   table[y][x + 2] == '-') {
                            second = x + 3;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((x <= (how - ile)) && table[y][x] == sign && table[y][x + 2] == sign &&
                                   table[y][x + 3] == sign &&
                                   table[y][x + 1] == '-') {
                            second = x + 2;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((x <= (how - ile)) && table[y][x + 1] == sign && table[y][x + 2] == sign &&
                                   table[y][x + 3] == sign &&
                                   table[y][x] == '-') {
                            second = x + 1;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign &&
                                   table[y + 3][x + 3] == sign && table[y][x] == '-') {
                            second = x + 1;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y][x] == sign &&
                                   table[y + 2][x + 2] == sign &&
                                   table[y + 3][x + 3] == sign && table[y + 1][x + 1] == '-') {
                            second = x + 2;
                            first = y + 2;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 3][x + 3] == sign && table[y + 2][x + 2] == '-') {
                            second = x + 3;
                            first = y + 3;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 3][x + 3] == '-') {
                            second = x + 4;
                            first = y + 4;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 3][x] == sign &&
                                   table[y + 2][x + 1] == sign &&
                                   table[y + 1][x + 2] == sign && table[y][x + 3] == '-') {
                            second = x + 4;
                            first = y + 1;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 3][x] == sign &&
                                   table[y + 2][x + 1] == sign &&
                                   table[y + 1][x + 2] == '-' && table[y][x + 3] == sign) {
                            second = x + 3;
                            first = y + 2;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 3][x] == sign &&
                                   table[y + 2][x + 1] == '-' &&
                                   table[y + 1][x + 2] == sign && table[y][x + 3] == sign) {
                            second = x + 2;
                            first = y + 3;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if ((y <= (how - ile)) && i <= (how - ile) && table[y + 3][x] == '-' &&
                                   table[y + 2][x + 1] == sign &&
                                   table[y + 1][x + 2] == sign && table[y][x + 3] == sign) {
                            second = x + 1;
                            first = y + 4;
                            if (k == 0) {
                                end = 1;
                            }
                            return;
                        } else if (k == 1 && j == (how - 1) && i == (how - 1) && !hard) {
                            char checked, checked1;
                            if (sign == 'x') {
                                checked = 'o';
                                checked1 = 'x';
                            } else {
                                checked = 'x';
                                checked1 = 'o';
                            }
                            int xyrandom = rand() % 3 + 0;
                            for (int l = 0; l < 2; l++) {
                                for (int d = 0; d < how; d++) {
                                    for (int c = 0; c < how; c++) {
                                        if ((table[c][d] == checked)) {
                                            if (l == 0) {
                                                if (((c + 1) < how && (c + 2) < how && (c + 3) < how) &&
                                                    (table[c + 1][d] == checked || table[c + 2][d] == checked ||
                                                     table[c + 3][d] == checked) &&
                                                    (table[c + 1][d] != checked1 && table[c + 2][d] != checked1 &&
                                                     table[c + 3][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how && (c + 2) < how) &&
                                                           (table[c - 1][d] == checked || table[c + 1][d] == checked ||
                                                            table[c + 2][d] == checked) &&
                                                           (table[c - 1][d] != checked1 &&
                                                            table[c + 1][d] != checked1 &&
                                                            table[c + 2][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 && (c - 1) >= 0 && (c + 1) < how) &&
                                                           (table[c - 2][d] == checked || table[c - 1][d] == checked ||
                                                            table[c + 1][d] == checked) &&
                                                           (table[c - 2][d] != checked1 &&
                                                            table[c - 1][d] != checked1 &&
                                                            table[c + 1][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0) &&
                                                           (table[c - 3][d] == checked || table[c - 2][d] == checked ||
                                                            table[c - 1][d] == checked) &&
                                                           (table[c - 3][d] != checked1 &&
                                                            table[c - 2][d] != checked1 &&
                                                            table[c - 1][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c + 1) < how && (c + 2) < how && (c + 3) < how &&
                                                            (d + 1) < how && (d + 2) < how && (d + 3) < how) &&
                                                           (table[c + 1][d + 1] == checked ||
                                                            table[c + 2][d + 2] == checked ||
                                                            table[c + 3][d + 3] == checked) &&
                                                           (table[c + 1][d + 1] != checked1 &&
                                                            table[c + 2][d + 2] != checked1 &&
                                                            table[c + 3][d + 3] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how && (c + 2) < how &&
                                                            (d - 1) >= 0 && (d + 1) < how && (d + 2) < how) &&
                                                           (table[c - 1][d - 1] == checked ||
                                                            table[c + 1][d + 1] == checked ||
                                                            table[c + 2][d + 2] == checked) &&
                                                           (table[c - 1][d - 1] != checked1 &&
                                                            table[c + 1][d + 1] != checked1 &&
                                                            table[c + 2][d + 2] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 && (c - 1) >= 0 && (c + 1) < how &&
                                                            (d - 2) >= 0 && (d - 1) >= 0 && (d + 1) < how) &&
                                                           (table[c - 2][d - 2] == checked ||
                                                            table[c - 1][d - 1] == checked ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c - 2][d - 2] != checked1 &&
                                                            table[c - 1][d - 1] != checked1 &&
                                                            table[c + 1][d + 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0 &&
                                                            (d - 3) >= 0 && (d - 2) >= 0 && (d - 1) >= 0) &&
                                                           (table[c - 3][d - 3] == checked ||
                                                            table[c - 2][d - 2] == checked ||
                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c - 3][d - 3] != checked1 &&
                                                            table[c - 2][d - 2] != checked1 &&
                                                            table[c - 1][d - 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c + 1) < how && (c + 2) < how && (c + 3) < how &&
                                                            (d - 3) >= 0 && (d - 2) >= 0 && (d - 1) >= 0) &&
                                                           (table[c + 1][d - 1] == checked ||
                                                            table[c + 2][d - 2] == checked ||
                                                            table[c + 3][d - 3] == checked) &&
                                                           (table[c + 1][d - 1] != checked1 &&
                                                            table[c + 2][d - 2] != checked1 &&
                                                            table[c + 3][d - 3] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how && (c + 2) < how &&
                                                            (d - 2) >= 0 && (d - 1) >= 0 && (d + 1) < how) &&
                                                           (table[c - 1][d + 1] == checked ||
                                                            table[c + 1][d - 1] == checked ||
                                                            table[c + 2][d - 2] == checked) &&
                                                           (table[c - 1][d + 1] != checked1 &&
                                                            table[c + 1][d - 1] != checked1 &&
                                                            table[c + 2][d - 2] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 && (c - 1) >= 0 && (c + 1) < how &&
                                                            (d - 1) >= 0 && (d + 1) < how && (d + 2) < how) &&
                                                           (table[c - 2][d + 2] == checked ||
                                                            table[c - 1][d + 1] == checked ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 2][d + 2] != checked1 &&
                                                            table[c - 1][d + 1] != checked1 &&
                                                            table[c + 1][d - 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0 &&
                                                            (d + 1) < how && (d + 2) < how && (d + 3) < how) &&
                                                           (table[c - 3][d + 3] == checked ||
                                                            table[c - 2][d + 2] == checked ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 3][d + 3] != checked1 &&
                                                            table[c - 2][d + 2] != checked1 &&
                                                            table[c - 1][d + 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                }
                                            } else {
                                                if ((d + 3 < how) &&
                                                    (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                    (table[c][d + 2] == '-' || table[c][d + 2] == checked) &&
                                                    (table[c][d + 3] == '-' || table[c][d + 3] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 3 + (d + 2);
                                                    return;
                                                } else if ((d - 1 >= 0) && (d + 2 < how) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked) &&
                                                           (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                           (table[c][d + 2] == '-' || table[c][d + 2] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 4 + (d);
                                                    return;
                                                } else if ((d - 2 >= 0) && (d + 1 < how) &&
                                                           (table[c][d - 2] == '-' || table[c][d - 2] == checked) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked) &&
                                                           (table[c][d + 1] == '-' || table[c][d + 1] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 4 + (d - 1);
                                                    return;
                                                } else if ((d - 3 >= 0) &&
                                                           (table[c][d - 3] == '-' || table[c][d - 3] == checked) &&
                                                           (table[c][d - 2] == '-' || table[c][d - 2] == checked) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 3 + (d - 2);
                                                    return;
                                                }
                                                if ((c + 3 < how) &&
                                                    (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                    (table[c + 2][d] == '-' || table[c + 2][d] == checked) &&
                                                    (table[c + 3][d] == '-' || table[c + 3][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 3 + (c + 2);
                                                    return;
                                                } else if ((c - 1 >= 0) && (c + 2 < how) &&
                                                           (table[c - 1][d] == '-' || table[c - 1][d] == checked) &&
                                                           (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                           (table[c + 2][d] == '-' || table[c + 2][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 4 + c;
                                                    return;
                                                } else if ((c - 2 >= 0) && (c + 1 < how) &&
                                                           (table[c - 2][d] == '-' || table[c - 2][d] == checked) &&
                                                           (table[c - 1][d] == '-' || table[c - 1][d] == checked) &&
                                                           (table[c + 1][d] == '-' || table[c + 1][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 4 + (c - 1);
                                                    return;
                                                } else if (((c - 3) >= 0) &&
                                                           (table[c - 3][d] == '-' || table[c - 3][d] == checked) &&
                                                           (table[c - 2][d] == '-' || table[c - 2][d] == checked) &&
                                                           (table[c - 1][d] == '-' || table[c - 1][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 3 + (c - 2);
                                                    return;
                                                }
                                                if ((c + 3 < how) && (d + 3 < how) &&
                                                    (table[c + 1][d + 1] == '-' || table[c + 1][d + 1] == checked) &&
                                                    (table[c + 2][d + 2] == '-' || table[c + 2][d + 2] == checked) &&
                                                    (table[c + 3][d + 3] == '-' || table[c + 3][d + 3] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 4;
                                                        second = d + 4;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 3;
                                                        second = d + 3;
                                                    } else {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    }
                                                    return;
                                                } else if ((c + 2 < how) && (d + 2 < how) && (c - 1 >= 0) &&
                                                           (d - 1 >= 0) && (table[c - 1][d - 1] == '-' ||
                                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c + 1][d + 1] == '-' ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c + 2][d + 2] == '-' ||
                                                            table[c + 2][d + 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 3;
                                                        second = d + 3;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    } else {
                                                        first = c;
                                                        second = d;
                                                    }
                                                    return;
                                                } else if ((c + 1 < how) && (d + 1 < how) && (c - 2 >= 0) &&
                                                           (d - 2 >= 0) && (table[c - 2][d - 2] == '-' ||
                                                                            table[c - 2][d - 2] == checked) &&
                                                           (table[c - 1][d - 1] == '-' ||
                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c + 1][d + 1] == '-' ||
                                                            table[c + 1][d + 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c;
                                                        second = d;
                                                    } else {
                                                        first = c - 1;
                                                        second = d - 1;
                                                    }
                                                    return;
                                                } else if ((c - 3 >= 0) && (d - 3 >= 0) &&
                                                           (table[c - 3][d - 3] == '-' ||
                                                            table[c - 3][d - 3] == checked) &&
                                                           (table[c - 2][d - 2] == '-' ||
                                                            table[c - 2][d - 2] == checked) &&
                                                           (table[c - 1][d - 1] == '-' ||
                                                            table[c - 1][d - 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 1;
                                                        second = d - 1;
                                                    } else {
                                                        first = c - 2;
                                                        second = d - 2;
                                                    }
                                                    return;
                                                }
                                                if ((d + 3 < how) && (c - 3 >= 0) &&
                                                    (table[c - 1][d + 1] == '-' || table[c - 1][d + 1] == checked) &&
                                                    (table[c - 2][d + 2] == '-' || table[c - 2][d + 2] == checked) &&
                                                    (table[c - 3][d + 3] == '-' || table[c - 3][d + 3] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c - 2;
                                                        second = d + 4;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 1;
                                                        second = d + 3;
                                                    } else {
                                                        first = c;
                                                        second = d + 2;
                                                    }
                                                    return;
                                                } else if ((c + 1 < how) && (d + 2 < how) && (c - 2 >= 0) &&
                                                           (d - 1 >= 0) && (table[c + 1][d - 1] == '-' ||
                                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 1][d + 1] == '-' ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 2][d + 2] == '-' ||
                                                            table[c - 2][d + 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c - 1;
                                                        second = d + 3;
                                                    } else if (xyrandom == 1) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else {
                                                        first = c + 2;
                                                        second = d;
                                                    }
                                                    return;
                                                } else if ((c + 2 < how) && (d + 1 < how) && (c - 1 >= 0) &&
                                                           (d - 2 >= 0) && (table[c + 2][d - 2] == '-' ||
                                                                            table[c + 2][d - 2] == checked) &&
                                                           (table[c + 1][d - 1] == '-' ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 1][d + 1] == '-' ||
                                                            table[c - 1][d + 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 2;
                                                        second = d;
                                                    } else {
                                                        first = c + 3;
                                                        second = d - 1;
                                                    }
                                                    return;
                                                } else if ((c + 3 < how) &&
                                                           ((d - 3 >= 0) && (table[c + 3][d - 3] == '-' ||
                                                                             table[c + 3][d - 3] == checked) &&
                                                            (table[c + 2][d - 2] == '-' ||
                                                             table[c + 2][d - 2] == checked) &&
                                                            (table[c + 1][d - 1] == '-' ||
                                                             table[c + 1][d - 1] == checked))) {
                                                    if (xyrandom == 0) {
                                                        first = c + 2;
                                                        second = d;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 3;
                                                        second = d - 1;
                                                    } else {
                                                        first = c + 4;
                                                        second = d - 2;
                                                    }
                                                    return;
                                                } else if (d == (how - 1) && c == (how - 1) && l == 1) {
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    case 5:
                        if ((y + 4 < how) && table[y][x] == sign && table[y + 1][x] == sign &&
                            table[y + 2][x] == sign &&
                            table[y + 3][x] == sign && table[y + 4][x] == '-') {
                            second = x + 1;
                            first = y + 5;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((y + 4 < how) && table[y][x] == sign && table[y + 1][x] == sign &&
                                   table[y + 2][x] == sign &&
                                   table[y + 3][x] == '-' && table[y + 4][x] == sign) {
                            second = x + 1;
                            first = y + 4;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((y + 4 < how) && table[y][x] == sign && table[y + 1][x] == sign &&
                                   table[y + 2][x] == '-' &&
                                   table[y + 3][x] == sign && table[y + 4][x] == sign) {
                            second = x + 1;
                            first = y + 3;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((y + 4 < how) && table[y][x] == sign && table[y + 1][x] == '-' &&
                                   table[y + 2][x] == sign &&
                                   table[y + 3][x] == sign && table[y + 4][x] == sign) {
                            second = x + 1;
                            first = y + 2;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((y + 4 < how) && table[y][x] == '-' && table[y + 1][x] == sign &&
                                   table[y + 2][x] == sign &&
                                   table[y + 3][x] == sign && table[y + 4][x] == sign) {
                            second = x + 1;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && table[y][x] == sign && table[y][x + 1] == sign &&
                                   table[y][x + 2] == sign &&
                                   table[y][x + 3] == sign && table[y][x + 4] == '-') {
                            second = x + 5;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && table[y][x] == sign && table[y][x + 1] == sign &&
                                   table[y][x + 2] == sign &&
                                   table[y][x + 3] == '-' && table[y][x + 4] == sign) {
                            second = x + 4;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && table[y][x] == sign && table[y][x + 1] == sign &&
                                   table[y][x + 2] == '-' &&
                                   table[y][x + 3] == sign && table[y][x + 4] == sign) {
                            second = x + 3;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && table[y][x] == sign && table[y][x + 1] == '-' &&
                                   table[y][x + 2] == sign &&
                                   table[y][x + 3] == sign && table[y][x + 4] == sign) {
                            second = x + 2;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && table[y][x] == '-' && table[y][x + 1] == sign &&
                                   table[y][x + 2] == sign &&
                                   table[y][x + 3] == sign && table[y][x + 4] == sign) {
                            second = x + 1;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 3][x + 3] == sign &&
                                   table[y + 4][x + 4] == '-') {
                            second = x + 5;
                            first = y + 5;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 3][x + 3] == '-' &&
                                   table[y + 4][x + 4] == sign) {
                            second = x + 4;
                            first = y + 4;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == '-' && table[y + 3][x + 3] == sign &&
                                   table[y + 4][x + 4] == sign) {
                            second = x + 3;
                            first = y + 3;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y][x] == sign &&
                                   table[y + 1][x + 1] == '-' &&
                                   table[y + 2][x + 2] == sign && table[y + 3][x + 3] == sign &&
                                   table[y + 4][x + 4] == sign) {
                            second = x + 2;
                            first = y + 2;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y][x] == '-' &&
                                   table[y + 1][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 3][x + 3] == sign &&
                                   table[y + 4][x + 4] == sign) {
                            second = x + 1;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y + 4][x] == sign &&
                                   table[y + 3][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 1][x + 3] == sign &&
                                   table[y][x + 4] == '-') {
                            second = x + 5;
                            first = y + 1;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y + 4][x] == sign &&
                                   table[y + 3][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 1][x + 3] == '-' &&
                                   table[y][x + 4] == sign) {
                            second = x + 4;
                            first = y + 2;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y + 4][x] == sign &&
                                   table[y + 3][x + 1] == sign &&
                                   table[y + 2][x + 2] == '-' && table[y + 1][x + 3] == sign &&
                                   table[y][x + 4] == sign) {
                            second = x + 3;
                            first = y + 3;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y + 4][x] == sign &&
                                   table[y + 3][x + 1] == '-' &&
                                   table[y + 2][x + 2] == sign && table[y + 1][x + 3] == sign &&
                                   table[y][x + 4] == sign) {
                            second = x + 2;
                            first = y + 4;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if ((x + 4 < how) && (y + 4 < how) && table[y + 4][x] == '-' &&
                                   table[y + 3][x + 1] == sign &&
                                   table[y + 2][x + 2] == sign && table[y + 1][x + 3] == sign &&
                                   table[y][x + 4] == sign) {
                            second = x + 1;
                            first = y + 5;
                            if (hard) {
                                end = 1;
                            }
                            return;
                        } else if (k == 1 && j == (how - 1) && i == (how - 1) && !hard) {
                            char checked, checked1;
                            if (sign == 'x') {
                                checked = 'o';
                                checked1 = 'x';
                            } else {
                                checked = 'x';
                                checked1 = 'o';
                            }
                            int xyrandom = rand() % 4 + 0;
                            for (int l = 0; l < 2; l++) {
                                for (int d = 0; d < how; d++) {
                                    for (int c = 0; c < how; c++) {
                                        if ((table[c][d] == checked)) {
                                            if (l == 0) {
                                                if (((c + 1) < how && (c + 2) < how && (c + 3) < how &&
                                                     (c + 4) < how) &&
                                                    (table[c + 1][d] == checked || table[c + 2][d] == checked ||
                                                     table[c + 3][d] == checked || table[c + 4][d] == checked) &&
                                                    (table[c + 1][d] != checked1 && table[c + 2][d] != checked1 &&
                                                     table[c + 3][d] != checked1 && table[c + 4][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how && (c + 2) < how &&
                                                            (c + 3) < how) &&
                                                           (table[c - 1][d] == checked || table[c + 1][d] == checked ||
                                                            table[c + 2][d] == checked || table[c + 3][d] == checked) &&
                                                           (table[c - 1][d] != checked1 &&
                                                            table[c + 1][d] != checked1 &&
                                                            table[c + 2][d] != checked1 &&
                                                            table[c + 3][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 && (c - 1) >= 0 && (c + 1) < how &&
                                                            (c + 2) < how) &&
                                                           (table[c - 2][d] == checked || table[c - 1][d] == checked ||
                                                            table[c + 1][d] == checked || table[c + 2][d] == checked) &&
                                                           (table[c - 2][d] != checked1 &&
                                                            table[c - 1][d] != checked1 &&
                                                            table[c + 1][d] != checked1 &&
                                                            table[c + 2][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0 &&
                                                            (c + 1) < how) &&
                                                           (table[c - 3][d] == checked || table[c - 2][d] == checked ||
                                                            table[c - 1][d] == checked || table[c + 1][d] == checked) &&
                                                           (table[c - 3][d] != checked1 &&
                                                            table[c - 2][d] != checked1 &&
                                                            table[c - 1][d] != checked1 &&
                                                            table[c + 1][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 4) >= 0 && (c - 3) >= 0 && (c - 2) >= 0 &&
                                                            (c - 1) >= 0) &&
                                                           (table[c - 4][d] == checked || table[c - 3][d] == checked ||
                                                            table[c - 2][d] == checked || table[c - 1][d] == checked) &&
                                                           (table[c - 4][d] != checked1 &&
                                                            table[c - 3][d] != checked1 &&
                                                            table[c - 2][d] != checked1 &&
                                                            table[c - 1][d] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c + 1) < how && (c + 2) < how && (c + 3) < how &&
                                                            (c + 4) < how &&
                                                            (d + 1) < how && (d + 2) < how && (d + 3) < how &&
                                                            (d + 4) < how) &&
                                                           (table[c + 1][d + 1] == checked ||
                                                            table[c + 2][d + 2] == checked ||
                                                            table[c + 3][d + 3] == checked ||
                                                            table[c + 4][d + 4] == checked) &&
                                                           (table[c + 1][d + 1] != checked1 &&
                                                            table[c + 2][d + 2] != checked1 &&
                                                            table[c + 3][d + 3] != checked1 &&
                                                            table[c + 4][d + 4] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how && (c + 2) < how &&
                                                            (c + 3) < how &&
                                                            (d - 1) >= 0 && (d + 1) < how && (d + 2) < how &&
                                                            (d + 3) < how) &&
                                                           (table[c - 1][d - 1] == checked ||
                                                            table[c + 1][d + 1] == checked ||
                                                            table[c + 2][d + 2] == checked ||
                                                            table[c + 3][d + 3] == checked) &&
                                                           (table[c - 1][d - 1] != checked1 &&
                                                            table[c + 1][d + 1] != checked1 &&
                                                            table[c + 2][d + 2] != checked1 &&
                                                            table[c + 3][d + 3] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 && (c - 1) >= 0 && (c + 1) < how &&
                                                            (c + 2) < how &&
                                                            (d - 2) >= 0 && (d - 1) >= 0 && (d + 1) < how &&
                                                            (d + 2) < how) &&
                                                           (table[c - 2][d - 2] == checked ||
                                                            table[c - 1][d - 1] == checked ||
                                                            table[c + 1][d + 1] == checked ||
                                                            table[c + 2][d + 2] == checked) &&
                                                           (table[c - 2][d - 2] != checked1 &&
                                                            table[c - 1][d - 1] != checked1 &&
                                                            table[c + 1][d + 1] != checked1 &&
                                                            table[c + 2][d + 2] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0 &&
                                                            (c + 1) < how &&
                                                            (d - 3) >= 0 && (d - 2) >= 0 && (d - 1) >= 0 &&
                                                            (d + 1) < how) &&
                                                           (table[c - 3][d - 3] == checked ||
                                                            table[c - 2][d - 2] == checked ||
                                                            table[c - 1][d - 1] == checked ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c - 3][d - 3] != checked1 &&
                                                            table[c - 2][d - 2] != checked1 &&
                                                            table[c - 1][d - 1] != checked1 &&
                                                            table[c + 1][d + 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (
                                                        ((c - 4) >= 0 && (c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0 &&
                                                         (d - 4) >= 0 && (d - 3) >= 0 && (d - 2) >= 0 &&
                                                         (d - 1) >= 0) &&
                                                        (table[c - 4][d - 4] == checked ||
                                                         table[c - 3][d - 3] == checked ||
                                                         table[c - 2][d - 2] == checked ||
                                                         table[c - 1][d - 1] == checked) &&
                                                        (table[c - 4][d - 4] != checked1 &&
                                                         table[c - 3][d - 3] != checked1 &&
                                                         table[c - 2][d - 2] != checked1 &&
                                                         table[c - 1][d - 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c + 1) < how && (c + 2) < how && (c + 3) < how &&
                                                            (c + 4) < how &&
                                                            (d - 4) >= 0 && (d - 3) >= 0 && (d - 2) >= 0 &&
                                                            (d - 1) >= 0) &&
                                                           (table[c + 1][d - 1] == checked ||
                                                            table[c + 2][d - 2] == checked ||
                                                            table[c + 3][d - 3] == checked ||
                                                            table[c + 4][d - 4] == checked) &&
                                                           (table[c + 1][d - 1] != checked1 &&
                                                            table[c + 2][d - 2] != checked1 &&
                                                            table[c + 3][d - 3] != checked1 &&
                                                            table[c + 4][d - 4] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 1) >= 0 && (c + 1) < how && (c + 2) < how &&
                                                            (c + 3) < how &&
                                                            (d - 3) >= 0 && (d - 2) >= 0 && (d - 1) >= 0 &&
                                                            (d + 1) < how) &&
                                                           (table[c - 1][d + 1] == checked ||
                                                            table[c + 1][d - 1] == checked ||
                                                            table[c + 2][d - 2] == checked ||
                                                            table[c + 3][d - 3] == checked) &&
                                                           (table[c - 1][d + 1] != checked1 &&
                                                            table[c + 1][d - 1] != checked1 &&
                                                            table[c + 2][d - 2] != checked1 &&
                                                            table[c + 3][d - 3] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 2) >= 0 && (c - 1) >= 0 && (c + 1) < how &&
                                                            (c + 2) < how &&
                                                            (d - 2) >= 0 && (d - 1) >= 0 && (d + 1) < how &&
                                                            (d + 2) < how) &&
                                                           (table[c - 2][d + 2] == checked ||
                                                            table[c - 1][d + 1] == checked ||
                                                            table[c + 1][d - 1] == checked ||
                                                            table[c + 2][d - 2] == checked) &&
                                                           (table[c - 2][d + 2] != checked1 &&
                                                            table[c - 1][d + 1] != checked1 &&
                                                            table[c + 1][d - 1] != checked1 &&
                                                            table[c + 2][d - 2] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 3) >= 0 && (c - 2) >= 0 && (c - 1) >= 0 &&
                                                            (c + 1) < how &&
                                                            (d - 1) >= 0 && (d + 1) < how && (d + 2) < how &&
                                                            (d + 3) < how) &&
                                                           (table[c - 3][d + 3] == checked ||
                                                            table[c - 2][d + 2] == checked ||
                                                            table[c - 1][d + 1] == checked ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 3][d + 3] != checked1 &&
                                                            table[c - 2][d + 2] != checked1 &&
                                                            table[c - 1][d + 1] != checked1 &&
                                                            table[c + 1][d - 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                } else if (((c - 4) >= 0 && (c - 3) >= 0 && (c - 2) >= 0 &&
                                                            (c - 1) >= 0 &&
                                                            (d + 1) < how && (d + 2) < how && (d + 3) < how &&
                                                            (d + 4) < how) &&
                                                           (table[c - 4][d + 4] == checked ||
                                                            table[c - 3][d + 3] == checked ||
                                                            table[c - 2][d + 2] == checked ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 4][d + 4] != checked1 &&
                                                            table[c - 3][d + 3] != checked1 &&
                                                            table[c - 2][d + 2] != checked1 &&
                                                            table[c - 1][d + 1] != checked1)) {
                                                    ++l;
                                                    --d;
                                                    --c;
                                                }
                                            } else {
                                                if ((d + 4 < how) &&
                                                    (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                    (table[c][d + 2] == '-' || table[c][d + 2] == checked) &&
                                                    (table[c][d + 3] == '-' || table[c][d + 3] == checked) &&
                                                    (table[c][d + 4] == '-' || table[c][d + 4] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 4 + (d + 2);
                                                    return;
                                                } else if ((d + 3 < how) && (d - 1 >= 0) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked) &&
                                                           (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                           (table[c][d + 2] == '-' || table[c][d + 2] == checked) &&
                                                           (table[c][d + 3] == '-' || table[c][d + 3] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 5 + (d);
                                                    return;
                                                } else if ((d + 2 < how) && (d - 2 >= 0) &&
                                                           (table[c][d - 2] == '-' || table[c][d - 2] == checked) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked) &&
                                                           (table[c][d + 1] == '-' || table[c][d + 1] == checked) &&
                                                           (table[c][d + 2] == '-' || table[c][d + 2] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 5 + (d - 1);
                                                    return;
                                                } else if ((d + 1 < how) && (d - 3 >= 0) &&
                                                           (table[c][d - 3] == '-' || table[c][d - 3] == checked) &&
                                                           (table[c][d - 2] == '-' || table[c][d - 2] == checked) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked) &&
                                                           (table[c][d + 1] == '-' || table[c][d + 1] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 5 + (d - 2);
                                                    return;
                                                } else if ((d - 4 >= 0) &&
                                                           (table[c][d - 4] == '-' || table[c][d - 4] == checked) &&
                                                           (table[c][d - 3] == '-' || table[c][d - 3] == checked) &&
                                                           (table[c][d - 2] == '-' || table[c][d - 2] == checked) &&
                                                           (table[c][d - 1] == '-' || table[c][d - 1] == checked)) {
                                                    first = c + 1;
                                                    second = rand() % 4 + (d - 3);
                                                    return;
                                                }
                                                if ((c + 4 < how) &&
                                                    (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                    (table[c + 2][d] == '-' || table[c + 2][d] == checked) &&
                                                    (table[c + 3][d] == '-' || table[c + 3][d] == checked) &&
                                                    (table[c + 4][d] == '-' || table[c + 4][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 4 + (c + 2);
                                                    return;
                                                } else if ((c + 3 < how) && (c - 1 >= 0) &&
                                                           (table[c - 1][d] == '-' || table[c - 1][d] == checked) &&
                                                           (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                           (table[c + 2][d] == '-' || table[c + 2][d] == checked) &&
                                                           (table[c + 3][d] == '-' || table[c + 3][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 5 + c;
                                                    return;
                                                } else if ((c + 2 < how) && (c - 2 >= 0) &&
                                                           (table[c - 2][d] == '-' || table[c - 2][d] == checked) &&
                                                           (table[c - 1][d] == '-' || table[c - 1][d] == checked) &&
                                                           (table[c + 1][d] == '-' || table[c + 1][d] == checked) &&
                                                           (table[c + 2][d] == '-' || table[c + 2][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 5 + (c - 1);
                                                    return;
                                                } else if ((c + 1 < how) && (c - 3 >= 0) &&
                                                           (table[c - 3][d] == '-' || table[c - 3][d] == checked) &&
                                                           (table[c - 2][d] == '-' || table[c - 2][d] == checked) &&
                                                           (table[c - 1][d] == '-' || table[c + 1][d] == checked) &&
                                                           (table[c + 1][d] == '-' || table[c + 1][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 5 + (c - 2);
                                                    return;
                                                } else if ((c - 4 >= 0) &&
                                                           (table[c - 4][d] == '-' || table[c - 3][d] == checked) &&
                                                           (table[c - 3][d] == '-' || table[c - 2][d] == checked) &&
                                                           (table[c - 2][d] == '-' || table[c + 1][d] == checked) &&
                                                           (table[c - 1][d] == '-' || table[c + 1][d] == checked)) {
                                                    second = d + 1;
                                                    first = rand() % 4 + (c - 3);
                                                    return;
                                                }
                                                if ((c + 4 < how) && (d + 4 < 0) &&
                                                    (table[c + 1][d + 1] == '-' || table[c + 1][d + 1] == checked) &&
                                                    (table[c + 2][d + 2] == '-' || table[c + 2][d + 2] == checked) &&
                                                    (table[c + 3][d + 3] == '-' || table[c + 3][d + 3] == checked) &&
                                                    (table[c + 4][d + 4] == '-' || table[c + 4][d + 4] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 5;
                                                        second = d + 5;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 4;
                                                        second = d + 4;
                                                    } else if (xyrandom == 2) {
                                                        first = c + 3;
                                                        second = d + 3;
                                                    } else {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    }
                                                    return;
                                                } else if ((c + 3 < how) && (d + 3 < how) && (c - 1 >= 0) &&
                                                           (d - 1 >= 0) && (table[c - 1][d - 1] == '-' ||
                                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c + 1][d + 1] == '-' ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c + 2][d + 2] == '-' ||
                                                            table[c + 2][d + 2] == checked) &&
                                                           (table[c + 3][d + 3] == '-' ||
                                                            table[c + 3][d + 3] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 4;
                                                        second = d + 4;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 3;
                                                        second = d + 3;
                                                    } else if (xyrandom == 2) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    } else {
                                                        first = c;
                                                        second = d;
                                                    }
                                                    return;
                                                } else if ((c + 2 < how) && (d + 2 < how) && (c - 2 >= 0) &&
                                                           (d - 2 >= 0) && (table[c - 2][d - 2] == '-' ||
                                                                            table[c - 2][d - 2] == checked) &&
                                                           (table[c - 1][d - 1] == '-' ||
                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c + 1][d + 1] == '-' ||
                                                            table[c + 1][d + 1] == checked) &&
                                                           (table[c + 2][d + 2] == '-' ||
                                                            table[c + 2][d + 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 3;
                                                        second = d + 3;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    } else if (xyrandom == 2) {
                                                        first = c;
                                                        second = d;
                                                    } else {
                                                        first = c - 1;
                                                        second = d - 1;
                                                    }
                                                    return;
                                                } else if ((c + 1 < how) && (d + 1 < how) && (c - 3 >= 0) &&
                                                           (d - 3 >= 0) && (table[c - 3][d - 3] == '-' ||
                                                                            table[c - 3][d - 3] == checked) &&
                                                           (table[c - 2][d - 2] == '-' ||
                                                            table[c - 2][d - 2] == checked) &&
                                                           (table[c - 1][d - 1] == '-' ||
                                                            table[c - 1][d - 1] == checked) &&
                                                           (table[c + 1][d + 1] == '-' ||
                                                            table[c + 1][d + 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 2;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c;
                                                        second = d;
                                                    } else if (xyrandom == 2) {
                                                        first = c - 1;
                                                        second = d - 1;
                                                    } else {
                                                        first = c - 2;
                                                        second = d - 2;
                                                    }
                                                    return;
                                                } else if ((c - 4 >= 0) && (d - 4 >= 0) &&
                                                           (table[c - 4][d - 4] == '-' ||
                                                            table[c - 4][d - 4] == checked) &&
                                                           (table[c - 3][d - 3] == '-' ||
                                                            table[c - 3][d - 3] == checked) &&
                                                           (table[c - 2][d - 2] == '-' ||
                                                            table[c - 2][d - 2] == checked) &&
                                                           (table[c - 1][d - 1] == '-' ||
                                                            table[c - 1][d - 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 1;
                                                        second = d - 1;
                                                    } else if (xyrandom == 2) {
                                                        first = c - 2;
                                                        second = d - 2;
                                                    } else {
                                                        first = c - 3;
                                                        second = d - 3;
                                                    }
                                                    return;
                                                }
                                                if ((d + 4 < how) && (c - 4 >= 0) &&
                                                    (table[c - 1][d + 1] == '-' || table[c - 1][d + 1] == checked) &&
                                                    (table[c - 2][d + 2] == '-' || table[c - 2][d + 2] == checked) &&
                                                    (table[c - 3][d + 3] == '-' || table[c - 3][d + 3] == checked) &&
                                                    (table[c - 4][d + 4] == '-' || table[c - 4][d + 4] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c - 3;
                                                        second = d + 5;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 2;
                                                        second = d + 4;
                                                    } else if (xyrandom == 2) {
                                                        first = c - 1;
                                                        second = d + 3;
                                                    } else {
                                                        first = c;
                                                        second = d + 2;
                                                    }
                                                    return;
                                                } else if ((c + 1 < how) && (d + 3 < how) && (c - 3 >= 0) &&
                                                           (d - 1 >= 0) && (table[c + 1][d - 1] == '-' ||
                                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 1][d + 1] == '-' ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 2][d + 2] == '-' ||
                                                            table[c - 2][d + 2] == checked) &&
                                                           (table[c - 3][d + 3] == '-' ||
                                                            table[c - 3][d + 3] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c - 2;
                                                        second = d + 4;
                                                    } else if (xyrandom == 1) {
                                                        first = c - 1;
                                                        second = d + 3;
                                                    } else if (xyrandom == 2) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else {
                                                        first = c + 2;
                                                        second = d;
                                                    }
                                                    return;
                                                } else if ((c + 2 < how) && (d + 2 < how) && (c - 2 >= 0) &&
                                                           (d - 2 >= 0) && (table[c + 2][d - 2] == '-' ||
                                                                            table[c + 2][d - 2] == checked) &&
                                                           (table[c + 1][d - 1] == '-' ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 1][d + 1] == '-' ||
                                                            table[c - 1][d + 1] == checked) &&
                                                           (table[c - 2][d + 2] == '-' ||
                                                            table[c - 2][d + 2] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c - 1;
                                                        second = d + 3;
                                                    } else if (xyrandom == 1) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else if (xyrandom == 2) {
                                                        first = c + 2;
                                                        second = d;
                                                    } else {
                                                        first = c + 3;
                                                        second = d - 1;
                                                    }
                                                    return;
                                                } else if ((c + 3 < how) && (d + 1 < how) && (c - 1 >= 0) &&
                                                           (d - 3 >= 0) && (table[c + 3][d - 3] == '-' ||
                                                                            table[c + 3][d - 3] == checked) &&
                                                           (table[c + 2][d - 2] == '-' ||
                                                            table[c + 2][d - 2] == checked) &&
                                                           (table[c + 1][d - 1] == '-' ||
                                                            table[c + 1][d - 1] == checked) &&
                                                           (table[c - 1][d + 1] == '-' ||
                                                            table[c - 1][d + 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c;
                                                        second = d + 2;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 2;
                                                        second = d;
                                                    } else if (xyrandom == 2) {
                                                        first = c + 3;
                                                        second = d - 1;
                                                    } else {
                                                        first = c + 4;
                                                        second = d - 2;
                                                    }
                                                    return;
                                                } else if ((c + 4 < how) && (d - 4 >= 0) &&
                                                           (table[c + 4][d - 4] == '-' ||
                                                            table[c + 4][d - 4] == checked) &&
                                                           (table[c + 3][d - 3] == '-' ||
                                                            table[c + 3][d - 3] == checked) &&
                                                           (table[c + 2][d - 2] == '-' ||
                                                            table[c + 2][d - 2] == checked) &&
                                                           (table[c + 1][d - 1] == '-' ||
                                                            table[c + 1][d - 1] == checked)) {
                                                    if (xyrandom == 0) {
                                                        first = c + 2;
                                                        second = d;
                                                    } else if (xyrandom == 1) {
                                                        first = c + 3;
                                                        second = d - 1;
                                                    } else if (xyrandom == 2) {
                                                        first = c + 4;
                                                        second = d - 2;
                                                    } else {
                                                        first = c + 5;
                                                        second = d - 3;
                                                    }
                                                    return;
                                                } else if (d == (how - 1) && c == (how - 1) && l == 1) {
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                        }
                        break;
                }
                y++;
            }
            y = 0;
            x++;

        }
        x = 0;
    }
}

void hardCPU(int whoFirst, int ile, int &second, int &first, int how, int h, char **table, bool &block, bool &end) {
    mediumCPU(whoFirst, ile, second, first, how, table, end);
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < how; i++) {
            for (int j = 0; j < how; j++) {
                switch (ile) {
                    case 3:
                        if (h == 0) {
                            int random;
                            random = rand() % 5 + 0;
                            switch (random) {
                                case 0:
                                    second = 1;
                                    first = 1;
                                    break;
                                case 1:
                                    second = how;
                                    first = 1;
                                    break;
                                case 2:
                                    second = 1;
                                    first = how;
                                    break;
                                case 3:
                                    second = how;
                                    first = how;
                                    break;
                                case 4:
                                    second = 2;
                                    first = 2;
                                    break;
                            }
                        }
                        for (int c = 0; c < how; c++) {
                            for (int d = 0; d < how; d++) {
                                if (h == 1) {
                                    if (table[d][c] == 'o') {
                                        if (d == c && c == 1) {
                                            int random = rand() % 4;
                                            switch (random) {
                                                case 0:
                                                    second = first = 1;
                                                    break;
                                                case 1:
                                                    second = first = 3;
                                                    break;
                                                case 2:
                                                    second = 3;
                                                    first = 1;
                                                case 3:
                                                    second = 1;
                                                    first = 3;
                                                    break;
                                            }
                                        } else {
                                            second = 2;
                                            first = 2;
                                        }
                                    }
                                } else if (h == 2) {
                                    if (table[d][c] == 'x') {
                                        if (d == 2) {
                                            int random = rand() % 2;
                                            switch (c) {
                                                case 0:
                                                    if (table[0][0] == 'o') {
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = first = how;
                                                        }
                                                    } else if (table[2][2] == 'o') {
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = first = 1;
                                                        }
                                                    } else if (table[2][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = how;
                                                        } else {
                                                            second = first = 1;
                                                        }
                                                    }
                                                    break;
                                                case 1:
                                                    if (table[0][0] == 'o') {
                                                        random = rand() % 3;
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else if (random == 1) {
                                                            second = first = 2;
                                                        } else {
                                                            second = 3;
                                                            first = 1;
                                                        }
                                                    } else if (table[0][2] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else {
                                                            second = first = 2;
                                                        }
                                                    } else if (table[1][1] == 'o') {
                                                        random = rand() % 4;
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else if (random == 1) {
                                                            second = first = how;
                                                        } else if (random == 2) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = how;
                                                            first = 1;
                                                        }
                                                    } else if (table[2][0] == 'o') {
                                                        random = rand() % 3;
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else if (random == 1) {
                                                            second = first = 2;
                                                        } else {
                                                            second = first = 3;
                                                        }
                                                    } else if (table[2][2] == 'o') {
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = first = 2;
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    if (table[0][2] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else {
                                                            second = how;
                                                            first = 1;
                                                        }
                                                    } else if (table[2][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else {
                                                            second = 1;
                                                            first = how;
                                                        }
                                                    } else if (table[0][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else {
                                                            second = how;
                                                            first = 1;
                                                        }
                                                    }
                                                    break;
                                            }
                                        } else if (d == 1) {
                                            int random;
                                            if (c == 0) {
                                                if (table[0][0] == 'o') {
                                                    random = rand() % 2;
                                                    if (random == 0) {
                                                        second = 1;
                                                        first = how;
                                                    } else {
                                                        second = first = 2;
                                                    }
                                                } else if (table[0][2] == 'o') {
                                                    random = rand() % 3;
                                                    if (random == 0) {
                                                        second = first = 1;
                                                    } else if (random == 1) {
                                                        second = first = 2;
                                                    } else {
                                                        second = first = how;
                                                    }
                                                } else if (table[1][1] == 'o') {
                                                    random = rand() % 4;
                                                    if (random == 0) {
                                                        second = first = 1;
                                                    } else if (random == 1) {
                                                        second = first = how;
                                                    } else if (random == 2) {
                                                        second = 1;
                                                        first = how;
                                                    } else {
                                                        second = how;
                                                        first = 1;
                                                    }
                                                } else if (table[2][0] == 'o') {
                                                    random = rand() % 2;
                                                    if (random == 0) {
                                                        second = first = how;
                                                    } else {
                                                        second = first = 2;
                                                    }
                                                } else if (table[2][2] == 'o') {
                                                    random = rand() % 3;
                                                    if (random == 0) {
                                                        second = 1;
                                                        first = how;
                                                    } else if (random == 1) {
                                                        second = first = 2;
                                                    } else {
                                                        second = how;
                                                        first = 1;
                                                    }
                                                }
                                            } else if (c == 2) {
                                                if (table[0][0] == 'o') {
                                                    random = rand() % 3;
                                                    if (random == 0) {
                                                        second = 1;
                                                        first = how;
                                                    } else if (random == 1) {
                                                        second = how;
                                                        first = 1;
                                                    } else {
                                                        second = first = 2;
                                                    }
                                                } else if (table[0][2] == 'o') {
                                                    random = rand() % 2;
                                                    if (random == 0) {
                                                        second = first = 1;
                                                    } else {
                                                        second = first = 2;
                                                    }
                                                } else if (table[1][1] == 'o') {
                                                    random = rand() % 4;
                                                    if (random == 0) {
                                                        second = first = 1;
                                                    } else if (random == 1) {
                                                        second = first = how;
                                                    } else if (random == 2) {
                                                        second = 1;
                                                        first = how;
                                                    } else {
                                                        second = how;
                                                        first = 1;
                                                    }
                                                } else if (table[2][0] == 'o') {
                                                    random = rand() % 3;
                                                    if (random == 0) {
                                                        second = first = how;
                                                    } else if (random == 1) {
                                                        second = first = 1;
                                                    } else {
                                                        second = first = 2;
                                                    }
                                                } else if (table[2][2] == 'o') {
                                                    random = rand() % 2;
                                                    if (random == 0) {
                                                        second = how;
                                                        first = 1;
                                                    } else {
                                                        second = first = 2;
                                                    }
                                                }
                                            }
                                        } else {
                                            int random = rand() % 2;
                                            switch (c) {
                                                case 0:
                                                    if (table[0][2] == 'o') {
                                                        if (random == 0) {
                                                            second = how;
                                                            first = 1;
                                                        } else {
                                                            second = first = how;
                                                        }
                                                    } else if (table[2][0] == 'o') {
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = first = how;
                                                        }
                                                    } else if (table[2][2] == 'o') {
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = how;
                                                            first = 1;
                                                        }
                                                    }
                                                    break;
                                                case 1:
                                                    if (table[0][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 2;
                                                        } else {
                                                            second = 1;
                                                            first = how;
                                                        }
                                                    } else if (table[0][2] == 'o') {
                                                        random = rand() % 3;
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else if (random == 1) {
                                                            second = first = 2;
                                                        } else {
                                                            second = first = 3;
                                                        }
                                                    } else if (table[1][1] == 'o') {
                                                        random = rand() % 4;
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else if (random == 1) {
                                                            second = first = how;
                                                        } else if (random == 2) {
                                                            second = 1;
                                                            first = how;
                                                        } else {
                                                            second = how;
                                                            first = 1;
                                                        }
                                                    } else if (table[2][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 2;
                                                        } else {
                                                            second = first = how;
                                                        }
                                                    } else if (table[2][2] == 'o') {
                                                        random = rand() % 3;
                                                        if (random == 0) {
                                                            second = 1;
                                                            first = how;
                                                        } else if (random == 1) {
                                                            second = first = 2;
                                                        } else {
                                                            second = how;
                                                            first = 1;
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    if (table[0][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = how;
                                                        } else {
                                                            second = 1;
                                                            first = how;
                                                        }
                                                    } else if (table[2][0] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else {
                                                            second = first = how;
                                                        }
                                                    } else if (table[2][2] == 'o') {
                                                        if (random == 0) {
                                                            second = first = 1;
                                                        } else {
                                                            second = 1;
                                                            first = how;
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (h == 3) {
                            if (table[0][1] == table[1][0] && table[0][1] == 'o') {
                                second = 1;
                                first = 1;
                            } else if (table[0][1] == table[1][2] && table[0][1] == 'o') {
                                second = 3;
                                first = 1;
                            } else if (table[1][2] == table[2][1] && table[2][1] == 'o') {
                                second = first = 1;
                            } else if (table[2][1] == table[1][0] && table[2][1] == 'o') {
                                second = 1;
                                first = 3;
                            } else if (table[0][0] == table[1][2] && table[0][0] == 'o') {
                                second = 3;
                                first = 1;
                            } else if (table[0][0] == table[2][1] && table[0][0] == 'o') {
                                second = 1;
                                first = 3;
                            } else if (table[0][2] == table[1][0] && table[0][2] == 'o') {
                                second = first = 1;
                            } else if (table[0][2] == table[2][1] && table[0][2] == 'o') {
                                second = first = how;
                            } else if (table[2][2] == table[1][0] && table[2][2] == 'o') {
                                second = 1;
                                first = 3;
                            } else if (table[2][2] == table[0][1] && table[0][1] == 'o') {
                                second = 3;
                                first = 1;
                            } else if (table[2][0] == table[0][1] && table[0][1] == 'o') {
                                second = first = 1;
                            } else if (table[2][0] == table[1][2] && table[2][0] == 'o') {
                                second = first = 3;
                            } else if (table[1][1] == 'o' && table[2][2] == 'o' && table[0][0] == 'x') {
                                second = 3;
                                first = 1;
                                return;
                            } else if (table[1][1] == 'o' && table[0][0] == 'o' && table[2][2] == 'x') {
                                second = 1;
                                first = 3;
                                return;
                            } else if (table[1][1] == 'o' && table[0][2] == 'o' && table[2][0] == 'x') {
                                second = first = 1;
                                return;
                            } else if (table[1][1] == 'o' && table[2][0] == 'o' && table[0][2] == 'x') {
                                second = first = 1;
                                return;
                            }
                        } else if (h == 4) {
                            if (((table[0][0] == 'o') && (table[0][0] == table[0][2] || table[0][0] == table[2][0])) ||
                                ((table[2][2] == 'o') && (table[2][2] == table[2][0] || table[2][2] == table[0][2])) &&
                                table[1][1] != 'x') {
                                second = 2;
                                first = 2;
                            }
                        } else {
                            mediumCPU(whoFirst, ile, second, first, how, table, end, 1);
                        }
                        break;
                    case 4:
                        if (h == 0) {
                            second = (how / 2) + 1;
                            first = (how / 2) + 1;
                        } else if (h == 1) {
                            int random = rand() % 2;
                            if (table[j][i] == 'o') {
                                if (i == 0) {
                                    if (j == 0) {
                                        second = 4;
                                        first = 2;
                                    } else if (j > 0 && j < how - 1) {
                                        if (random == 0) {
                                            second = first = 1;
                                        } else {
                                            second = 1;
                                            first = 5;
                                        }
                                    } else {
                                        second = 2;
                                        first = 2;
                                    }
                                } else if (i == 1 || i == 3) {
                                    if (j == 0) {
                                        if (random == 0) {
                                            second = 1;
                                            first = 1;
                                        } else {
                                            second = 5;
                                            first = 1;
                                        }
                                    } else if (j < how - 1 && j > 0) {
                                        second = first = 3;
                                    } else {
                                        if (random == 0) {
                                            second = 1;
                                            first = 5;
                                        } else {
                                            second = 5;
                                            first = 5;
                                        }
                                    }
                                } else if (i == 2) {
                                    if (j == 0) {
                                        if (random == 0) {
                                            second = 1;
                                            first = 1;
                                        } else {
                                            second = 5;
                                            first = 1;
                                        }
                                    } else if (j == 1 || j == 3) {
                                        second = first = 3;
                                    } else if (j == 2) {
                                        random = rand() % 4;
                                        if (random == 0) {
                                            second = first = 2;
                                        } else if (random == 1) {
                                            second = first = 4;
                                        } else if (random == 2) {
                                            second = 4;
                                            first = 2;
                                        } else {
                                            second = 2;
                                            first = 4;
                                        }
                                    } else {
                                        if (random == 0) {
                                            second = 1;
                                            first = 5;
                                        } else {
                                            second = 5;
                                            first = 5;
                                        }
                                    }
                                } else {
                                    if (j == 0) {
                                        second = 4;
                                        first = 4;
                                    } else if (j > 0 && j < how - 1) {
                                        if (random == 0) {
                                            second = first = 5;
                                        } else {
                                            second = 5;
                                            first = 1;
                                        }
                                    } else {
                                        second = 4;
                                        first = 2;
                                    }
                                }
                            }
                        } else if (h == 2) {
                            int random = rand() % 2;
                            if (table[j][i] == 'x') {
                                if ((j == 1 && i == 1) || (j == 3 && i == 3)) {
                                    if (random == 0) {
                                        second = 4;
                                        first = 2;
                                    } else {
                                        second = 2;
                                        first = 4;
                                    }
                                } else if ((j == 1 && i == 3) || (j == 3 && i == 1)) {
                                    if (random == 0) {
                                        second = 4;
                                        first = 4;
                                    } else {
                                        second = 2;
                                        first = 2;
                                    }
                                } else if ((i == 2 && (j == 1 || j == 3))) {
                                    first = 3;
                                    if (random == 0) {
                                        second = 2;
                                    } else {
                                        second = 4;
                                    }
                                } else if (j == 2 && (i == 1 || i == 3)) {
                                    second = 3;
                                    if (random == 0) {
                                        first = 2;
                                    } else {
                                        first = 4;
                                    }
                                } else if (table[0][0] == 'x' || table[4][0] == 'x') {
                                    second = 4;
                                    first = 3;
                                } else if (table[0][4] == 'x' || table[4][4] == 'x') {
                                    second = 2;
                                    first = 3;
                                } else if (i == 0) {
                                    second = 4;
                                    first = 3;
                                } else if (i == 4) {
                                    second = 2;
                                    first = 3;
                                } else if (j == 0) {
                                    second = 3;
                                    first = 4;
                                } else if (j == 4) {
                                    second = 3;
                                    first = 2;
                                }
                            }
                        } else if (h == 3) {
                            if (table[1][1] == 'o') {
                                if (table[2][3] == 'o' && table[3][2] == '-') {
                                    second = 3;
                                    first = 4;
                                    return;
                                } else if (table[3][2] == 'o' && table[2][3] == '-') {
                                    second = 4;
                                    first = 3;
                                    return;
                                } else if (table[2][2] == 'o' && table[3][3] == '-') {
                                    second = first = 4;
                                    return;
                                }
                            } else if (table[3][1] == 'o') {
                                if (table[1][2] == 'o' && table[2][3] == '-') {
                                    second = 4;
                                    first = 3;
                                    return;
                                } else if (table[2][3] == 'o' && table[1][2] == '-') {
                                    second = 3;
                                    first = 2;
                                    return;
                                } else if (table[2][2] == 'o' && table[1][3] == '-') {
                                    second = 4;
                                    first = 2;
                                    return;
                                }
                            } else if (table[1][3] == 'o') {
                                if (table[2][1] == 'o' && table[3][2] == '-') {
                                    second = 3;
                                    first = 4;
                                    return;
                                } else if (table[3][2] == 'o' && table[2][1] == '-') {
                                    second = 2;
                                    first = 3;
                                    return;
                                } else if (table[2][2] == 'o' && table[3][1] == '-') {
                                    second = 2;
                                    first = 4;
                                    return;
                                }
                            } else if (table[3][3] == 'o') {
                                if (table[1][2] == 'o' && table[2][1] == '-') {
                                    second = 2;
                                    first = 3;
                                    return;
                                } else if (table[2][1] == 'o' && table[1][2] == '-') {
                                    second = 3;
                                    first = 2;
                                    return;
                                } else if (table[2][2] == 'o' && table[1][1] == '-') {
                                    second = first = 2;
                                    return;
                                }
                            } else if (table[2][1] == 'o') {
                                if (table[1][2] == 'o') {
                                    second = first = 2;
                                    return;
                                } else if (table[3][2] == 'o') {
                                    second = 2;
                                    first = 4;
                                    return;
                                }
                            } else if (table[2][3] == 'o') {
                                if (table[3][2] == 'o') {
                                    second = 4;
                                    first = 4;
                                    return;
                                } else if (table[1][2] == 'o') {
                                    second = 4;
                                    first = 2;
                                    return;
                                }
                            }

                            int random = rand() % 2;
                            if (table[2][2] == 'o') {
                                if (table[4][4] == 'o' && table[3][3] == 'x') {
                                    if (random == 1) {
                                        second = 2;
                                        first = 4;
                                    } else {
                                        second = 4;
                                        first = 2;
                                    }
                                } else if (table[0][0] == 'o' && table[1][1] == 'x') {
                                    if (random == 1) {
                                        second = 2;
                                        first = 4;
                                    } else {
                                        second = 4;
                                        first = 2;
                                    }
                                } else if (table[4][0] == 'o' && table[3][1] == 'x') {
                                    if (random == 1) {
                                        second = first = 4;
                                    } else {
                                        second = first = 2;
                                    }
                                } else if (table[0][4] == 'o' && table[1][3] == 'x') {
                                    if (random == 1) {
                                        second = first = 4;
                                    } else {
                                        second = first = 2;
                                    }
                                }
                            }

                            if (table[j][i] == 'o') {
                                if (i == 0) {
                                    if (j == 0) {
                                        if (table[1][3] == 'x') {
                                            if (table[0][4] == table[2][2] && table[3][1] == table[4][0]) {
                                                second = first = 3;
                                                return;
                                            } else {
                                                if (table[0][0] == table[0][1] || table[0][0] == table[0][2] ||
                                                    table[0][0] == table[0][3] || table[0][0] == table[0][4]) {
                                                    second = 2;
                                                    first = 4;
                                                } else {
                                                    second = first = 2;
                                                }
                                                return;
                                            }
                                        }
                                    } else if (j > 0 && j < how - 1) {
                                        if (table[0][0] == 'x' || table[4][0] == 'x') {
                                            if (table[2][2] == '-') {
                                                second = first = 3;
                                            } else if (table[0][0] == 'x') {
                                                second = 2;
                                                first = 4;
                                            } else if (table[4][0] == 'x') {
                                                second = first = 2;
                                            }
                                        }
                                    } else {
                                        if (table[1][1] == 'x') {
                                            if (table[4][4] == table[3][3] && table[2][2] == table[0][0]) {
                                                second = first = 3;
                                                return;
                                            } else {
                                                if (table[4][0] == table[3][0] || table[4][0] == table[2][0] ||
                                                    table[4][0] == table[1][0] || table[4][0] == table[0][0]) {
                                                    second = first = 4;
                                                } else {
                                                    second = 4;
                                                    first = 2;
                                                }
                                                return;
                                            }
                                        }
                                    }
                                } else if (i == 1 || i == 3) {
                                    if (j == 0 || j == 4) {
                                        if (table[2][2] == '-') {
                                            second = 3;
                                            first = 3;
                                        } else if (table[2][2] == 'o') {
                                            random = rand() % 4;
                                            if (random == 0) {
                                                second = first = 2;
                                            } else if (random == 1) {
                                                second = first = 4;
                                            } else if (random == 2) {
                                                second = 2;
                                                first = 4;
                                            } else {
                                                second = 4;
                                                first = 2;
                                            }
                                        }
                                    } else if (j == 1 || j == 3) {
                                        if (j + 2 < how && table[j][i] == table[j + 1][i]) {
                                            second = i + 1;
                                            first = j + 3;
                                            return;
                                        } else if (j + 2 < how && table[j][i] == table[j + 2][i]) {
                                            second = i + 1;
                                            first = j + 2;
                                            return;
                                        } else if (i + 2 < how && table[j][i] == table[j][i + 1]) {
                                            second = i + 3;
                                            first = j + 1;
                                            return;
                                        } else if (i + 2 < how && table[j][i] == table[j][i + 2]) {
                                            second = i + 2;
                                            first = j + 1;
                                            return;
                                        } else {
                                            if (table[2][0] == '-' && table[2][1] == '-' && table[2][3] == '-' &&
                                                table[2][4] == '-') {
                                                first = 3;
                                                if (random == 0) {
                                                    second = 2;
                                                } else {
                                                    second = 4;
                                                }
                                                return;
                                            } else if (table[0][2] == '-' && table[1][2] == '-' && table[3][2] == '-' &&
                                                       table[4][2] == '-') {
                                                second = 3;
                                                if (random == 0) {
                                                    first = 2;
                                                } else {
                                                    first = 4;
                                                }
                                                return;
                                            }
                                        }
                                    }
                                } else if (i == 2) {
                                    if (j == 1 || j == 3) {
                                        if (table[j][i] == table[j][i - 1]) {
                                            second = 4;
                                            first = j + 1;
                                        } else if (table[j][i + 1] == table[j][i]) {
                                            second = 2;
                                            first = j + 1;
                                        }
                                    } else if (table[2][2] == '-') {
                                        second = 3;
                                        first = 3;
                                    } else {
                                        if (table[2][2] == 'x') {
                                            if (table[1][2] == 'o') {
                                                if (table[3][0] == table[3][1] && table[3][2] == table[3][3] &&
                                                    table[3][3] == table[3][4] && table[4][0] == table[4][4]) {
                                                    first = 4;
                                                    if (random == 0) {
                                                        second = 2;
                                                    } else {
                                                        second = 4;
                                                    }
                                                } else if (table[4][0] == table[0][0] && table[1][1] == table[3][1]) {
                                                    second = 2;
                                                    if (random == 0) {
                                                        first = 2;
                                                    } else {
                                                        first = 4;
                                                    }
                                                } else if (table[4][4] == table[0][4] && table[3][3] == table[1][3]) {
                                                    second = 4;
                                                    if (random == 0) {
                                                        first = 2;
                                                    } else {
                                                        first = 4;
                                                    }
                                                }
                                            } else if (table[3][2] == 'o') {
                                                if (table[1][0] == table[1][1] && table[1][2] == table[1][3] &&
                                                    table[1][3] == table[1][4] && table[0][0] == table[0][4]) {
                                                    first = 2;
                                                    if (random == 0) {
                                                        second = 2;
                                                    } else {
                                                        second = 4;
                                                    }
                                                } else if (table[4][0] == table[0][0] && table[1][1] == table[3][1]) {
                                                    second = 2;
                                                    if (random == 0) {
                                                        first = 2;
                                                    } else {
                                                        first = 4;
                                                    }
                                                } else if (table[4][4] == table[0][4] && table[3][3] == table[1][3]) {
                                                    second = 4;
                                                    if (random == 0) {
                                                        first = 2;
                                                    } else {
                                                        first = 4;
                                                    }
                                                }
                                            }
                                        } else if (table[2][2] == 'o') {
                                            if (table[2][2] == table[1][1] && table[3][3] == '-') {
                                                second = first = 4;
                                                return;
                                            } else if (table[2][2] == table[3][3] && table[1][1] == '-') {
                                                second = first = 2;
                                                return;
                                            } else if (table[2][2] == table[1][3] && table[3][1] == '-') {
                                                second = 2;
                                                first = 4;
                                                return;
                                            } else if (table[2][2] == table[3][1] && table[1][3] == '-') {
                                                second = 4;
                                                first = 2;
                                                return;
                                            } else if (table[2][2] == table[2][1] && table[2][3] == '-') {
                                                second = 4;
                                                first = 3;
                                                return;
                                            } else if (table[2][2] == table[2][3] && table[2][1] == '-') {
                                                second = 2;
                                                first = 3;
                                                return;
                                            } else if (table[2][2] == table[3][2] && table[1][2] == '-') {
                                                second = 3;
                                                first = 2;
                                                return;
                                            } else if (table[2][2] == table[1][2] && table[3][2] == '-') {
                                                second = 3;
                                                first = 4;
                                                return;
                                            }
                                        }
                                    }
                                } else if (i == 4) {
                                    if (j == 0) {
                                        if (table[1][1] == 'x') {
                                            if (table[4][4] == table[3][3] && table[2][2] == table[0][0]) {
                                                second = first = 3;
                                                return;
                                            } else {
                                                if (table[0][4] == table[1][4] || table[0][4] == table[2][4] ||
                                                    table[0][4] == table[3][4] || table[0][4] == table[4][4]) {
                                                    second = first = 4;
                                                } else {
                                                    second = 4;
                                                    first = 2;
                                                }
                                                return;
                                            }
                                        }
                                    } else if (j > 0 && j < how - 1) {
                                        if (table[0][4] == 'x' || table[4][4] == 'x') {
                                            if (table[2][2] == '-') {
                                                second = first = 3;
                                            } else if (table[0][4] == 'x') {
                                                second = first = 4;
                                            } else if (table[4][0] == 'x') {
                                                second = 4;
                                                first = 2;
                                            }
                                        }
                                    } else {
                                        if (table[1][3] == 'x') {
                                            if (table[0][4] == table[2][2] && table[3][1] == table[4][0]) {
                                                second = first = 3;
                                                return;
                                            } else {
                                                if (table[4][4] == table[3][4] || table[4][4] == table[2][4] ||
                                                    table[4][4] == table[1][4] || table[4][4] == table[0][4]) {
                                                    second = 2;
                                                    first = 4;
                                                } else {
                                                    second = first = 4;
                                                }
                                                return;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (h == 4) {
                            if (table[2][2] == 'o' && table[2][2] == table[3][3] &&
                                (table[1][1] == '-' && table[0][0] == '-' && table[4][4] == '-')) {
                                second = 2;
                                first = 2;
                                return;
                            } else if (table[2][2] == 'o' && table[2][2] == table[1][1] &&
                                       (table[3][3] == '-' && table[0][0] == '-' && table[4][4] == '-')) {
                                second = 4;
                                first = 4;
                                return;
                            } else if (table[2][2] == 'o' && table[2][2] == table[1][3] &&
                                       (table[3][1] == '-' && table[4][0] == '-' && table[0][4] == '-')) {
                                second = 2;
                                first = 4;
                                return;
                            } else if (table[2][2] == 'o' && table[2][2] == table[3][1] &&
                                       (table[1][3] == '-' && table[4][0] == '-' && table[0][4] == '-')) {
                                second = 4;
                                first = 2;
                                return;
                            }
                            int random = rand() % 2;
                            if (table[0][1] == 'x' && table[0][1] == table[0][2]) {
                                second = 4;
                                first = 1;
                            } else if (table[0][1] == 'x' && table[0][1] == table[0][3]) {
                                second = 3;
                                first = 1;
                            } else if (table[0][2] == 'x' && table[0][2] == table[0][3]) {
                                second = 2;
                                first = 1;
                            } else if (table[4][1] == 'x' && table[4][1] == table[4][2]) {
                                second = 4;
                                first = 5;
                            } else if (table[4][1] == 'x' && table[4][1] == table[4][3]) {
                                second = 3;
                                first = 5;
                            } else if (table[4][2] == 'x' && table[4][2] == table[4][3]) {
                                second = 2;
                                first = 5;
                            } else if (table[1][0] == 'x' && table[1][0] == table[2][0]) {
                                second = 1;
                                first = 4;
                            } else if (table[1][0] == 'x' && table[1][0] == table[3][0]) {
                                second = 1;
                                first = 3;
                            } else if (table[2][0] == 'x' && table[2][0] == table[3][0]) {
                                second = 1;
                                first = 2;
                            } else if (table[1][4] == 'x' && table[1][4] == table[2][4]) {
                                second = 5;
                                first = 4;
                            } else if (table[1][4] == 'x' && table[1][4] == table[3][4]) {
                                second = 5;
                                first = 3;
                            } else if (table[3][4] == 'x' && table[2][4] == table[3][4]) {
                                second = 5;
                                first = 2;
                            } else if (table[2][2] == 'o' && table[1][2] == 'o') {
                                if (table[0][2] == 'x' || table[3][2] == 'x' || table[4][2] == 'x') {
                                    if (table[1][1] == 'x' || table[1][3] == 'x') {
                                        first = 3;
                                        if (table[1][1] == 'x') {
                                            second = 4;
                                        } else {
                                            second = 2;
                                        }
                                    } else {
                                        first = 2;
                                        if (random == 0) {
                                            second = 2;
                                        } else {
                                            second = 4;
                                        }
                                    }

                                } else {
                                    second = 3;
                                    first = 4;
                                }
                            } else if (table[2][2] == 'o' && table[3][2] == 'o') {
                                if (table[1][2] == 'x' || table[4][2] == 'x' || table[0][2] == 'x') {
                                    if (table[3][3] == 'x' || table[3][1] == 'x') {
                                        first = 3;
                                        if (table[3][3] == 'x') {
                                            second = 2;
                                        } else {
                                            second = 4;
                                        }
                                    } else {
                                        first = 4;
                                        if (random == 0) {
                                            second = 4;
                                        } else {
                                            second = 2;
                                        }
                                    }
                                } else {
                                    second = 3;
                                    first = 2;
                                }
                            } else if (table[2][2] == 'o' && table[2][1] == 'o') {
                                if (table[2][0] == 'x' || table[2][3] == 'x' || table[2][4] == 'x') {
                                    if (table[1][1] == 'x' || table[3][1] == 'x') {
                                        second = 3;
                                        if (table[1][1] == 'x') {
                                            first = 4;
                                        } else {
                                            first = 2;
                                        }
                                    } else {
                                        second = 2;
                                        if (random == 0) {
                                            first = 2;
                                        } else {
                                            first = 4;
                                        }
                                    }

                                } else {
                                    second = 4;
                                    first = 3;
                                }
                                if (table[0][4] == 'x') {
                                    if (table[2][0] == 'x' || table[2][3] == 'x' || table[2][4] == 'x') {
                                        second = first = 2;
                                    }
                                } else if (table[4][4] == 'x') {
                                    if (table[2][0] == 'x' || table[2][3] == 'x' || table[2][4] == 'x') {
                                        second = 2;
                                        first = 4;
                                    }
                                }
                            } else if (table[2][2] == 'o' && table[2][3] == 'o') {
                                if (table[2][1] == 'x' || table[2][4] == 'x' || table[2][0] == 'x') {
                                    if (table[1][3] == 'x' || table[3][3] == 'x') {
                                        second = 3;
                                        if (table[1][3] == 'x') {
                                            first = 4;
                                        } else {
                                            first = 2;
                                        }
                                    } else {
                                        second = 4;
                                        if (random == 0) {
                                            first = 4;
                                        } else {
                                            first = 2;
                                        }
                                    }
                                } else {
                                    second = 2;
                                    first = 3;
                                }
                                if (table[0][0] == 'x') {
                                    if (table[2][1] == 'x' || table[2][4] == 'x' || table[2][0] == 'x') {
                                        second = 4;
                                        first = 2;
                                    }
                                } else if (table[4][0] == 'x') {
                                    second = first = 4;
                                }
                            } else if (table[j][i] == 'x') {
                                if (i + 1 < how && table[j][i] == table[j][i + 1]) {
                                    if (j < 4 && j != 0) {
                                        if (i == 1) {
                                            second = i + 3;
                                            first = j + 1;
                                            block = 0;
                                            return;
                                        } else if (i == 2) {
                                            second = i;
                                            first = j + 1;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (i + 2 < how && table[j][i] == table[j][i + 2]) {
                                    if (j < 4 && j != 0) {
                                        if (i == 1) {
                                            second = i + 2;
                                            first = j + 1;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (j + 1 < how && table[j][i] == table[j + 1][i]) {
                                    if (i < 4 && i != 0) {
                                        if (j == 1) {
                                            second = i + 1;
                                            first = j + 3;
                                            block = 0;
                                            return;
                                        } else if (j == 2) {
                                            second = i + 1;
                                            first = j;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (j + 2 < how && table[j][i] == table[j + 2][i]) {
                                    if (j < 4 && j != 0) {
                                        if (j == 1) {
                                            second = i + 1;
                                            first = j + 2;
                                            block = 0;
                                            return;
                                        }
                                    }
                                }
                            }
                        } else if (h == 5) {
                            if (table[2][2] == 'x') {
                                if (table[2][1] == 'x') {
                                    if (table[1][3] == 'o' && table[3][3] == 'o' && table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                    } else if (table[1][3] == 'o' && table[2][3] == 'o' && table[3][3] == '-') {
                                        second = 4;
                                        first = 4;
                                    } else if (table[2][3] == 'o' && table[3][3] == 'o' && table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    } else if (table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                    } else if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                    } else if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                    }
                                } else if (table[1][2] == 'x') {
                                    if (table[3][3] == 'o' && table[3][2] == 'o' && table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                    } else if (table[3][3] == 'o' && table[3][2] == '-' && table[3][1] == 'o') {
                                        second = 3;
                                        first = 4;
                                    } else if (table[3][3] == '-' && table[3][2] == 'o' && table[3][1] == 'o') {
                                        second = first = 4;
                                    } else if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                    } else if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                    } else if (table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                    }
                                } else if (table[3][2] == 'x') {
                                    if (table[1][1] == 'o' && table[1][2] == 'o' && table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    } else if (table[1][1] == 'o' && table[1][2] == '-' && table[1][3] == 'o') {
                                        second = 3;
                                        first = 2;
                                    } else if (table[1][1] == '-' && table[1][2] == 'o' && table[1][3] == 'o') {
                                        second = 2;
                                        first = 2;
                                    } else if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                    } else if (table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                    } else if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                    }
                                } else if (table[2][3] == 'x') {
                                    if (table[1][1] == 'o' && table[2][1] == 'o' && table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                    } else if (table[1][1] == 'o' && table[2][1] == '-' && table[3][1] == 'o') {
                                        second = 2;
                                        first = 3;
                                    } else if (table[1][1] == '-' && table[2][1] == 'o' && table[3][1] == 'o') {
                                        second = first = 2;
                                    } else if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                    } else if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                    } else if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                    }
                                } else if (table[1][1] == 'x') {
                                    if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    } else if (table[3][3] == '-') {
                                        second = first = 4;
                                    } else if (table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                    }
                                } else if (table[3][3] == 'x') {
                                    if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    } else if (table[1][1] == '-') {
                                        second = first = 2;
                                    } else if (table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                    }
                                } else if (table[1][3] == 'x') {
                                    if (table[1][1] == '-') {
                                        second = first = 2;
                                    } else if (table[3][3] == '-') {
                                        second = first = 4;
                                    } else if (table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                    }
                                } else if (table[3][1] == 'x') {
                                    if (table[1][1] == '-') {
                                        second = first = 2;
                                    } else if (table[3][3] == '-') {
                                        second = first = 4;
                                    } else if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    }
                                }
                            } else if (table[2][2] == 'o') {
                                if (table[1][1] == 'x' && table[3][3] == 'x') {
                                    if (table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                    } else if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    }
                                } else if (table[3][1] == 'x' && table[1][3] == 'x') {
                                    if (table[1][1] == '-') {
                                        second = first = 2;
                                    } else if (table[3][3] == '-') {
                                        second = first = 4;
                                    }
                                } else if (table[2][1] == 'o' && table[2][3] == '-') {
                                    second = 4;
                                    first = 3;

                                } else if (table[2][3] == 'o' && table[2][1] == '-') {
                                    second = 2;
                                    first = 3;
                                } else if (table[3][2] == 'o' && table[1][2] == '-') {
                                    second = 3;
                                    first = 2;
                                } else if (table[1][2] == 'o' && table[3][2] == '-') {
                                    second = 3;
                                    first = 4;
                                } else if (table[1][1] == 'o' && table[3][3] == '-') {
                                    second = first = 4;
                                } else if (table[3][3] == 'o' && table[1][1] == '-') {
                                    second = first = 2;
                                } else if (table[3][1] == 'o' && table[1][3] == '-') {
                                    second = 4;
                                    first = 2;
                                } else if (table[1][3] == 'o' && table[3][1] == '-') {
                                    second = 2;
                                    first = 4;
                                }
                            } else if (table[2][2] == '-') {
                                second = 3;
                                first = 3;
                            }

                            if (table[0][1] == 'o' && table[0][2] == 'o' && table[0][3] == '-') {
                                second = 4;
                                first = 1;
                            } else if (table[0][1] == 'o' && table[0][3] == 'o' && table[0][2] == '-') {
                                second = 3;
                                first = 1;
                            } else if (table[0][2] == 'o' && table[0][3] == 'o' && table[0][1] == '-') {
                                second = 2;
                                first = 1;
                            } else if (table[4][1] == 'o' && table[4][2] == 'o' && table[4][3] == '-') {
                                second = 4;
                                first = 5;
                            } else if (table[4][1] == 'o' && table[4][3] == 'o' && table[4][2] == '-') {
                                second = 3;
                                first = 5;
                            } else if (table[4][2] == 'o' && table[4][3] == 'o' && table[4][1] == '-') {
                                second = 2;
                                first = 5;
                            } else if (table[1][0] == 'o' && table[3][0] == 'o' && table[2][0] == '-') {
                                second = 1;
                                first = 3;
                            } else if (table[1][0] == 'o' && table[2][0] == 'o' && table[3][0] == '-') {
                                second = 1;
                                first = 4;
                            } else if (table[2][0] == 'o' && table[3][0] == 'o' && table[1][0] == '-') {
                                second = 1;
                                first = 2;
                            } else if (table[1][4] == 'o' && table[3][4] == 'o' && table[2][4] == '-') {
                                second = 5;
                                first = 3;
                            } else if (table[1][4] == 'o' && table[2][4] == 'o' && table[3][4] == '-') {
                                second = 5;
                                first = 4;
                            } else if (table[2][4] == 'o' && table[3][4] == 'o' && table[1][4] == '-') {
                                second = 5;
                                first = 2;
                            }
                        } else if (h == 6) {
                            if ((table[2][1] == table[2][2] && table[2][2] == table[2][3]) ||
                                (table[1][2] == table[2][2] && table[2][2] == table[3][2]) ||
                                (table[1][1] == table[2][2] && table[2][2] == table[3][3]) ||
                                (table[3][1] == table[2][2] && table[2][2] == table[1][3]))
                                return;
                            else if (table[2][2] == table[2][1] &&
                                     (table[2][0] == '-' && table[2][3] == '-' && table[2][4] == '-')) {
                                second = 4;
                                first = 3;
                                return;
                            } else if (table[2][2] == table[2][3] &&
                                       (table[2][0] == '-' && table[2][1] == '-' && table[2][4] == '-')) {
                                second = 2;
                                first = 3;
                                return;
                            } else if (table[2][2] == table[1][2] &&
                                       (table[0][2] == '-' && table[3][2] == '-' && table[4][2] == '-')) {
                                second = 3;
                                first = 4;
                                return;
                            } else if (table[2][2] == table[3][2] &&
                                       (table[0][2] == '-' && table[1][2] == '-' && table[4][2] == '-')) {
                                second = 3;
                                first = 2;
                                return;
                            } else if (table[2][2] == table[1][1] &&
                                       (table[0][0] == '-' && table[3][3] == '-' && table[4][4] == '-')) {
                                second = first = 4;
                                return;
                            } else if (table[2][2] == table[3][3] &&
                                       (table[0][0] == '-' && table[1][1] == '-' && table[4][4] == '-')) {
                                second = first = 2;
                                return;
                            } else if (table[2][2] == table[3][1] &&
                                       (table[1][3] == '-' && table[0][4] == '-' && table[4][0] == '-')) {
                                second = 4;
                                first = 2;
                                return;
                            } else if (table[2][2] == table[1][3] &&
                                       (table[3][1] == '-' && table[0][4] == '-' && table[4][0] == '-')) {
                                second = 2;
                                first = 4;
                                return;
                            }

                            int random = rand() % 2;
                            if (!block) {
                                if (table[1][3] == 'o') {
                                    if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                        return;
                                    } else if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                        return;
                                    }
                                } else if (table[3][3] == 'o') {
                                    if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                        return;
                                    } else if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                        return;
                                    }
                                } else if (table[1][1] == 'o') {
                                    if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                        return;
                                    } else if (table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                        return;
                                    }
                                } else if (table[3][1] == 'o') {
                                    if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                        return;
                                    } else if (table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                        return;
                                    }
                                }
                            } else if (table[2][2] == 'o' && table[2][3] == 'o') {
                                if (table[3][3] == 'o') {
                                    if (table[4][3] == 'x' || table[1][3] == 'x' || table[0][3] == 'x') {
                                        if (table[1][1] == '-') {
                                            second = first = 2;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[4][4] == 'x' || table[1][1] == 'x' || table[0][0] == 'x') {
                                        if (table[1][3] == '-') {
                                            second = 4;
                                            first = 2;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[1][3] == 'o') {
                                    if (table[3][0] == 'x') {
                                        if (table[3][1] == '-') {
                                            second = 2;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[4][0] == 'x') {
                                        if (table[3][3] == '-') {
                                            second = first = 4;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[3][2] == 'o') {
                                    if (table[3][3] == '-') {
                                        second = 4;
                                        first = 4;
                                        block = 0;
                                        return;
                                    }
                                } else if (table[1][2] == 'x') {
                                    if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                        block = 0;
                                        return;
                                    }
                                }
                            } else if (table[2][2] == 'o' && table[2][1] == 'o') {
                                if (table[1][1] == 'o') {
                                    if (table[0][1] == 'x' || table[3][1] == 'x' || table[4][1] == 'x') {
                                        if (table[3][3] == '-') {
                                            second = first = 4;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[0][0] == 'x' || table[3][3] == 'x' || table[4][4] == 'x') {
                                        if (table[1][3] == '-') {
                                            second = 4;
                                            first = 2;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[3][1] == 'o') {
                                    if (table[4][0] == 'x' || table[1][3] == 'x' || table[0][4] == 'x') {
                                        if (table[1][1] == '-') {
                                            second = first = 2;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[4][1] == 'x' || table[1][1] == 'x' || table[0][1] == 'x') {
                                        if (table[3][1] == '-') {
                                            second = 2;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[3][2] == 'o') {
                                    if (table[3][1] == '-') {
                                        second = 2;
                                        first = 4;
                                        block = 0;
                                        return;
                                    }
                                } else if (table[1][2] == 'o') {
                                    if (table[1][1] == '-') {
                                        second = first = 2;
                                        block = 0;
                                        return;
                                    }
                                }
                            } else if (table[2][2] == 'o' && table[1][2] == 'o') {
                                if (table[1][1] == 'o') {
                                    if (table[1][0] == 'x' || table[1][3] == 'x' || table[1][4] == 'x') {
                                        if (table[3][3] == '-') {
                                            second = 4;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[0][0] == 'x' || table[3][3] == 'x' || table[4][4] == 'x') {
                                        if (table[1][3] == '-') {
                                            second = 4;
                                            first = 2;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[1][3] == 'o') {
                                    if (table[1][4] == 'x' || table[1][1] == 'x' || table[1][0] == 'x') {
                                        if (table[3][1] == '-') {
                                            second = 2;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[0][4] == 'x' || table[3][1] == 'x' || table[4][0] == 'x') {
                                        if (table[1][1] == '-') {
                                            second = first = 2;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[2][1] == 'o') {
                                    if (table[1][1] == '-') {
                                        second = first = 2;
                                        block = 0;
                                        return;
                                    }
                                } else if (table[2][3] == 'o') {
                                    if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                        block = 0;
                                        return;
                                    }
                                }
                            } else if (table[2][2] == 'o' && table[3][2] == 'o') {
                                if (table[3][1] == 'o') {
                                    if (table[4][0] == 'x' || table[1][3] == 'x' || table[0][4] == 'x') {
                                        if (table[3][3] == '-') {
                                            second = 4;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[3][0] == 'x' || table[3][3] == 'x' || table[3][4] == 'x') {
                                        if (table[3][1] == '-') {
                                            second = 2;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[3][3] == 'o') {
                                    if (table[3][4] == 'x' || table[3][1] == 'x' || table[3][0] == 'x') {
                                        if (table[1][1] == '-') {
                                            second = first = 2;
                                            block = 0;
                                            return;
                                        }
                                    } else if (table[4][4] == 'x' || table[1][1] == 'x' || table[0][0] == 'x') {
                                        if (table[3][1] == '-') {
                                            second = 2;
                                            first = 4;
                                            block = 0;
                                            return;
                                        }
                                    }
                                } else if (table[1][2] == 'o') {
                                    if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                        block = 0;
                                        return;
                                    }
                                } else if (table[2][3] == 'o') {
                                    if (table[3][3] == '-') {
                                        second = first = 4;
                                        block = 0;
                                        return;
                                    }
                                }
                            }
                            if (table[2][2] == 'o' && table[1][2] == 'o' && block) {
                                if (table[0][2] == 'x' || table[3][2] == 'x' || table[4][2] == 'x') {
                                    first = 2;
                                    if (table[3][1] == 'x') {
                                        second = 2;
                                    } else if (table[3][3] == 'x') {
                                        second = 4;
                                    } else if (random == 0) {
                                        second = 2;
                                    } else {
                                        second = 4;
                                    }
                                } else {
                                    second = 3;
                                    first = 4;
                                }
                            } else if (table[2][2] == 'o' && table[3][2] == 'o' && block) {
                                if (table[1][2] == 'x' || table[4][2] == 'x' || table[0][2] == 'x') {
                                    first = 4;
                                    if (table[1][3] == 'x') {
                                        second = 4;
                                    } else if (table[1][1] == 'x') {
                                        second = 2;
                                    } else if (random == 0) {
                                        second = 4;
                                    } else {
                                        second = 2;
                                    }
                                } else {
                                    second = 3;
                                    first = 2;
                                }
                            } else if (table[2][2] == 'o' && table[2][1] == 'o' && block) {
                                if (table[2][0] == 'x' || table[2][3] == 'x' || table[2][4] == 'x') {
                                    second = 2;
                                    if (table[3][1] == 'x') {
                                        first = 2;
                                    } else if (table[3][3] == 'x') {
                                        first = 4;
                                    } else if (random == 0) {
                                        first = 2;
                                    } else {
                                        first = 4;
                                    }
                                } else {
                                    second = 4;
                                    first = 3;
                                }
                            } else if (table[2][2] == 'o' && table[2][3] == 'o' && block) {
                                if (table[2][1] == 'x' || table[2][4] == 'x' || table[2][0] == 'x') {
                                    second = 4;
                                    if (table[3][1] == 'x') {
                                        first = 4;
                                    } else if (table[1][1] == 'x') {
                                        first = 2;
                                    } else if (random == 0) {
                                        first = 4;
                                    } else {
                                        first = 2;
                                    }
                                }
                            }
                            if ((j + 1 < 5) && (table[j][i] == 'x' && table[j + 1][i] == 'x')) {
                                if (j == 2) {
                                    second = i + 1;
                                    first = 2;
                                    return;
                                } else if (j == 1) {
                                    second = i + 1;
                                    first = 4;
                                    return;
                                }
                            } else if ((i + 1 < 5) && (table[j][i] == 'x' && table[j][i + 1] == 'x')) {
                                if ((i + 1) == 3) {
                                    second = j + 1;
                                    first = 2;
                                    return;
                                } else if (i == 1) {
                                    second = j + 1;
                                    first = 4;
                                    return;
                                }
                            }

                        } else if (h == 7) {
                            if (table[3][1] == 'o' && table[3][3] == 'o' && table[3][2] == '-') {
                                second = 3;
                                first = 4;
                            } else if (table[3][1] == 'o' && table[1][1] == 'o' && table[2][1] == '-') {
                                second = 2;
                                first = 3;
                            } else if (table[1][1] == 'o' && table[1][3] == 'o' && table[1][2] == '-') {
                                second = 3;
                                first = 2;
                            } else if (table[1][3] == 'o' && table[3][3] == 'o' && table[2][3] == '-') {
                                second = 4;
                                first = 3;
                            } else if (table[2][2] == 'x') {
                                if (table[1][1] == 'x' && table[3][3] == '-') {
                                    second = 4;
                                    first = 4;
                                } else if (table[1][3] == 'x' && table[3][1] == '-') {
                                    second = 2;
                                    first = 4;
                                } else if (table[3][1] == 'x' && table[1][3] == '-') {
                                    second = 4;
                                    first = 2;
                                } else if (table[3][3] == 'x' && table[1][1] == '-') {
                                    second = 1;
                                    first = 1;
                                } else if (table[2][1] == 'x') {
                                    if (table[2][3] == 'x' && (table[2][0] == '-' || table[2][4] == '-'));
                                    else if (table[2][3] == '-') {
                                        second = 3;
                                        first = 4;
                                    }
                                } else if (table[1][3] == 'x' && table[3][1] == 'o' && table[1][1] == '-') {
                                    second = first = 2;
                                    block = 0;
                                } else if (table[3][1] == 'x' && table[1][3] == 'o' && table[3][3] == '-') {
                                    second = first = 4;
                                    block = 0;
                                } else if (table[3][3] == 'x' && table[1][1] == 'o' && table[3][1] == '-') {
                                    second = 2;
                                    first = 4;
                                    block = 0;
                                } else if (table[1][1] == 'x' && table[3][3] == 'o' && table[1][3] == '-') {
                                    second = 4;
                                    first = 2;
                                    block = 0;
                                }

                                if (table[1][2] == 'x') {
                                    if (table[3][2] == 'x' && (table[4][2] == '-' || table[0][2] == '-'));
                                    else if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                    }
                                } else if (table[3][2] == 'x') {
                                    if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                    }
                                } else if (table[2][3] == 'x') {
                                    if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                    }
                                }
                                if (table[3][1] == 'o' && table[3][2] == 'o' && table[2][3] == 'o' &&
                                    table[3][3] == '-') {
                                    second = first = 4;
                                    return;
                                } else if (table[3][3] == 'o' && table[3][2] == 'o' && table[2][1] == 'o' &&
                                           table[3][1] == '-') {
                                    second = 2;
                                    first = 4;
                                    return;
                                } else if (table[1][1] == 'o' && table[1][2] == 'o' && table[2][3] == 'o' &&
                                           table[1][3] == '-') {
                                    second = 4;
                                    first = 2;
                                    return;
                                } else if (table[1][3] == 'o' && table[1][2] == 'o' && table[2][1] == 'o' &&
                                           table[1][1] == '-') {
                                    second = first = 2;
                                    return;
                                }
                            } else if (table[2][2] == 'o') {
                                if (table[1][1] == 'o' && table[3][3] == '-') {
                                    second = first = 4;
                                } else if (table[3][3] == 'o' && table[1][1] == '-') {
                                    second = first = 2;
                                } else if (table[1][3] == 'o' && table[3][1] == '-') {
                                    second = 2;
                                    first = 4;
                                } else if (table[3][1] == 'o' && table[1][3] == '-') {
                                    second = 4;
                                    first = 2;
                                } else if (table[2][1] == 'o' && table[2][3] == '-') {
                                    second = 4;
                                    first = 3;
                                } else if (table[2][3] == 'o' && table[2][1] == '-') {
                                    second = 2;
                                    first = 3;
                                } else if (table[3][2] == 'o' && table[1][2] == '-') {
                                    second = 3;
                                    first = 2;
                                } else if (table[1][2] == 'o' && table[3][2] == '-') {
                                    second = 3;
                                    first = 4;
                                }
                            }
                        } else if (h == 8) {
                            if ((table[2][2] == table[2][1] && table[2][2] == table[2][3] &&
                                 (table[2][0] == '-' || table[2][4] == '-')) ||
                                (table[1][1] == 'o' && table[1][1] == table[1][2] && table[1][1] == table[1][3] &&
                                 (table[1][0] == '-' || table[1][4] == '-')) ||
                                (table[3][3] == 'o' && table[3][3] == table[3][2] && table[3][3] == table[3][1] &&
                                 (table[3][0] == '-' || table[3][4] == '-')) ||
                                (table[2][2] == table[2][1] && table[2][2] == table[2][3] &&
                                 (table[2][0] == '-' || table[2][4] == '-')) ||
                                (table[1][1] == 'o' && table[1][1] == table[2][1] && table[1][1] == table[3][1] &&
                                 (table[4][1] == '-' || table[0][1] == '-')) ||
                                (table[3][3] == 'o' && table[3][3] == table[2][3] && table[3][3] == table[1][3] &&
                                 (table[0][3] == '-' || table[4][3] == '-')) ||
                                (table[2][2] == table[1][2] && table[2][2] == table[3][2] &&
                                 (table[4][2] == '-' || table[0][2] == '-')) ||
                                (table[2][2] == table[1][1] && table[2][2] == table[3][3] &&
                                 (table[0][0] == '-' || table[4][4] == '-')) ||
                                (table[2][2] == table[1][3] && table[2][2] == table[3][1] &&
                                 (table[0][4] == '-' || table[4][0] == '-'))) {
                                return;
                            }
                            if (block) {
                                if (table[2][2] == 'o' && table[2][3] == 'o') {
                                    if (table[3][3] == 'o') {
                                        if (table[1][3] == 'x');
                                        else {
                                            if (table[4][3] == 'x' || table[1][3] == 'x' || table[0][3] == 'x') {
                                                second = first = 2;
                                                return;
                                            } else if (table[4][4] == 'x' || table[1][1] == 'x' ||
                                                       table[0][0] == 'x') {
                                                second = 4;
                                                first = 2;
                                                return;
                                            }
                                        }
                                    } else if (table[1][3] == 'o') {
                                        if (table[3][3] == 'x');
                                        else {
                                            if (table[3][0] == 'x') {
                                                second = 2;
                                                first = 4;
                                            } else if (table[4][0] == 'x') {
                                                second = first = 4;
                                            }
                                        }
                                    }
                                } else if (table[2][2] == 'o' && table[2][1] == 'o') {
                                    if (table[1][1] == 'o') {
                                        if (table[3][1] == 'x');
                                        else {
                                            if (table[0][1] == 'x' || table[3][1] == 'x' || table[4][1] == 'x') {
                                                second = first = 4;
                                                block = 0;
                                            } else if (table[0][0] == 'x' || table[3][3] == 'x' ||
                                                       table[4][4] == 'x') {
                                                second = 4;
                                                first = 2;
                                            }
                                        }
                                    } else if (table[3][1] == 'o') {
                                        if (table[1][1] == 'x');
                                        else {
                                            if (table[4][0] == 'x' || table[1][3] == 'x' || table[0][4] == 'x') {
                                                second = first = 2;
                                                block = 0;
                                            } else if (table[4][1] == 'x' || table[1][1] == 'x' ||
                                                       table[0][1] == 'x') {
                                                second = 2;
                                                first = 4;
                                            }
                                        }
                                    }
                                } else if (table[2][2] == 'o' && table[1][2] == 'o') {
                                    if (table[1][1] == 'o') {
                                        if (table[1][3] == 'x');
                                        else {
                                            if (table[1][0] == 'x' || table[1][3] == 'x' || table[1][4] == 'x') {
                                                second = 4;
                                                first = 4;
                                            } else if (table[0][0] == 'x' || table[3][3] == 'x' ||
                                                       table[4][4] == 'x') {
                                                second = 4;
                                                first = 2;
                                            }
                                        }
                                    } else if (table[1][3] == 'o') {
                                        if (table[1][1] == 'x');
                                        else {
                                            if (table[1][4] == 'x' || table[1][1] == 'x' || table[1][0] == 'x') {
                                                second = 2;
                                                first = 4;
                                            } else if (table[0][4] == 'x' || table[3][1] == 'x' ||
                                                       table[4][0] == 'x') {
                                                second = first = 2;
                                            }
                                        }
                                    }
                                } else if (table[2][2] == 'o' && table[3][2] == 'o') {
                                    if (table[3][1] == 'o') {
                                        if (table[3][3] == 'x');
                                        else {
                                            if (table[4][0] == 'x' || table[1][3] == 'x' || table[0][4] == 'x') {
                                                second = 4;
                                                first = 4;
                                            } else if (table[3][0] == 'x' || table[3][3] == 'x' ||
                                                       table[3][4] == 'x') {
                                                second = 2;
                                                first = 4;
                                            }
                                        }
                                    } else if (table[3][3] == 'o') {
                                        if (table[3][1] == 'x');
                                        else {
                                            if (table[3][4] == 'x' || table[3][1] == 'x' || table[3][0] == 'x') {
                                                second = first = 2;
                                            } else if (table[4][4] == 'x' || table[1][1] == 'x' ||
                                                       table[0][0] == 'x') {
                                                second = 2;
                                                first = 4;
                                            }
                                        }
                                    }
                                }
                            } else if (table[2][2] == 'o') {
                                if (table[1][2] == 'o') {
                                    if (table[2][1] == 'o') {
                                        if (table[1][1] == 'o') {
                                            if (table[0][0] == 'x' || table[3][3] == 'x' || table[4][4] == 'x') {
                                                if (table[1][0] == '-' && table[1][3] == '-' &&
                                                    table[1][4] == '-') {
                                                    second = 4;
                                                    first = 2;
                                                }
                                            } else if (table[1][0] == 'x' && table[1][3] == 'x' &&
                                                       table[1][4] == 'x') {
                                                if (table[0][0] == '-' || table[3][3] == '-' ||
                                                    table[4][4] == '-') {
                                                    second = 4;
                                                    first = 2;
                                                }
                                            }
                                        }
                                    } else if (table[2][3] == 'o') {
                                        if (table[1][3] == 'o') {
                                            if (table[0][4] == 'x' || table[3][1] == 'x' || table[4][0] == 'x') {
                                                if (table[1][0] == '-' && table[1][1] == '-' &&
                                                    table[1][4] == '-') {
                                                    second = 2;
                                                    first = 2;
                                                }
                                            } else if (table[1][0] == 'x' && table[1][1] == 'x' &&
                                                       table[1][4] == 'x') {
                                                if (table[0][4] == '-' || table[3][1] == '-' ||
                                                    table[4][0] == '-') {
                                                    second = 2;
                                                    first = 4;
                                                }
                                            }
                                        }
                                    }
                                } else if (table[3][2] == 'o') {
                                    if (table[2][1] == 'o') {
                                        if (table[3][1] == 'o') {
                                            if (table[3][0] == 'x' || table[3][3] == 'x' || table[3][4] == 'x') {
                                                if (table[4][0] == '-' || table[1][3] == '-' ||
                                                    table[0][4] == '-') {
                                                    second = 4;
                                                    first = 2;
                                                }
                                            } else if (table[4][0] == 'x' || table[1][3] == 'x' ||
                                                       table[0][4] == 'x') {
                                                if (table[3][0] == '-' || table[3][3] == '-' ||
                                                    table[3][4] == '-') {
                                                    second = first = 4;
                                                }
                                            }
                                        }
                                    } else if (table[2][3] == 'o') {
                                        if (table[3][3] == 'o') {
                                            if (table[3][0] == 'x' || table[3][1] == 'x' || table[3][4] == 'x') {
                                                if (table[0][0] == '-' || table[1][1] == '-' ||
                                                    table[4][4] == '-') {
                                                    second = 2;
                                                    first = 2;
                                                }
                                            } else if (table[4][4] == 'x' || table[1][1] == 'x' ||
                                                       table[0][0] == 'x') {
                                                if (table[3][0] == '-' || table[3][1] == '-' ||
                                                    table[3][4] == '-') {
                                                    second = 2;
                                                    first = 4;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (!block) {
                                if (table[2][2] == table[2][1] && table[2][3] == '-' && table[2][4] == '-' &&
                                    table[2][0] == '-') {
                                    second = 4;
                                    first = 3;
                                } else if (table[2][2] == table[2][3] && table[2][1] == '-' && table[2][4] == '-' &&
                                           table[2][0] == '-') {
                                    second = 2;
                                    first = 3;
                                } else if (table[2][2] == table[3][2] && table[1][2] == '-' && table[0][2] == '-' &&
                                           table[4][2] == '-') {
                                    second = 3;
                                    first = 2;
                                } else if (table[2][2] == table[1][2] && table[3][2] == '-' && table[0][2] == '-' &&
                                           table[4][2] == '-') {
                                    second = 3;
                                    first = 4;
                                } else {
                                    mediumCPU(whoFirst, ile, second, first, how, table, end);
                                }
                            }
                        } else if (h == 9) {
                            if (!block) {
                                if (table[1][1] == 'x' && table[1][3] == 'x') {
                                    if (table[3][3] == '-') {
                                        second = first = 4;
                                    } else if (table[1][2] == '-') {
                                        second = 3;
                                        first = 2;
                                    }
                                } else if (table[1][1] == 'x' && table[3][1] == 'x') {

                                    if (table[1][3] == '-') {
                                        second = 2;
                                        first = 4;
                                    } else if (table[2][1] == '-') {
                                        second = 2;
                                        first = 3;
                                    }
                                } else if (table[3][1] == 'x' && table[3][3] == 'x') {
                                    if (table[1][3] == '-') {
                                        second = 4;
                                        first = 2;
                                    } else if (table[3][2] == '-') {
                                        second = 3;
                                        first = 4;
                                    }
                                } else if (table[3][3] == 'x' && table[1][3] == 'x') {
                                    if (table[1][1] == '-') {
                                        second = first = 2;
                                    } else if (table[2][3] == '-') {
                                        second = 4;
                                        first = 3;
                                    }
                                }
                            }
                        } else if (h % 2 == 1 && h >= 11) {
                            if (!end) {
                                if (!block) {
                                    if (table[1][1] == 'x' && table[2][1] == 'x' && table[3][1] == 'x' &&
                                        table[0][1] == 'o' && table[4][1] == 'o') {
                                        if (table[2][3] == '-') {
                                            second = 4;
                                            first = 3;
                                            return;
                                        }
                                    } else if (table[1][1] == 'x' && table[1][2] == 'x' && table[1][3] == 'x' &&
                                               table[1][0] == 'o' && table[1][4] == 'o') {
                                        if (table[3][2] == '-') {
                                            second = 3;
                                            first = 4;
                                            return;
                                        }
                                    } else if (table[3][1] == 'x' && table[3][2] == 'x' && table[3][3] == 'x' &&
                                               table[3][4] == 'o' && table[3][0] == 'o') {
                                        if (table[1][2] == '-') {
                                            second = 3;
                                            first = 2;
                                            return;
                                        }
                                    } else if (table[3][3] == 'x' && table[2][3] == 'x' && table[1][3] == 'x' &&
                                               table[0][3] == 'o' && table[4][3] == 'o') {
                                        if (table[2][1] == '-') {
                                            second = 2;
                                            first = 3;
                                            return;
                                        }
                                    } else if (table[1][1] == 'x' && table[2][2] == 'x' && table[3][3] == 'x') {
                                        if (table[1][0] == 'o' && table[2][3] == '-') {
                                            second = 4;
                                            first = 3;
                                            return;
                                        } else if (table[3][4] == 'o' && table[2][1] == '-') {
                                            second = 2;
                                            first = 3;
                                            return;
                                        }
                                    } else if (table[1][3] == 'x' && table[2][2] == 'x' && table[3][1] == 'x') {
                                        if (table[3][0] == 'o' && table[2][1] == '-') {
                                            second = 2;
                                            first = 3;
                                            return;
                                        } else if (table[1][4] == 'o' && table[2][3] == '-') {
                                            second = 4;
                                            first = 3;
                                            return;
                                        }
                                    }
                                } else if ((j == 0 || j == 4) && i + 1 < how && table[j][i] == 'o' &&
                                           table[j][i + 1] == 'o') {
                                    if (i + 2 < how && table[j][i + 2] == '-') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i - 1 >= 0 && table[j][i - 1] == '-') {
                                        second = i;
                                        first = j + 1;
                                        return;
                                    }
                                } else if ((i == 0 || i == 4) && j + 1 < how && table[j][i] == 'o' &&
                                           table[j + 1][i] == 'o') {
                                    if (j + 2 < how && table[j + 2][i] == '-') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j - 1 >= 0 && table[j - 1][i] == '-') {
                                        second = i + 1;
                                        first = j;
                                        return;
                                    }
                                } else if ((i == 0 || i == 4) && j + 2 < how && table[j][i] == 'o' &&
                                           table[j + 2][i] == 'o') {
                                    if (j + 1 < how && table[j + 1][i] == '-') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    }
                                } else if ((j == 0 || j == 4) && i + 2 < how && table[j][i] == 'o' &&
                                           table[j][i + 2] == 'o') {
                                    if (i + 1 < how && table[j][i + 1] == '-') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    }
                                }
                            }
                        } else if (h > 21) {
                            if (table[j][i] == '-') {
                                second = i + 1;
                                first = j + 1;
                                return;
                            }
                        } else if (h % 2 == 0) {
                            if (table[0][0] == table[0][1] && table[0][0] == table[0][2] &&
                                table[0][0] == table[0][3] && table[0][0] == table[0][4]) {
                                second = 3;
                                first = 1;
                            } else if (table[0][0] == table[1][0] && table[0][0] == table[2][0] &&
                                       table[0][0] == table[3][0] && table[0][0] == table[4][0]) {
                                second = 1;
                                first = 3;
                            } else if (table[4][0] == table[4][1] && table[4][0] == table[4][2] &&
                                       table[4][0] == table[4][3] && table[4][0] == table[4][4]) {
                                second = 3;
                                first = 5;
                            } else if (table[4][4] == table[3][4] && table[4][4] == table[2][4] &&
                                       table[4][4] == table[1][4] && table[4][4] == table[0][4]) {
                                second = 5;
                                first = 3;
                            }
                            mediumCPU(whoFirst, ile, second, first, how, table, end, 1);
                            if (j == 0 || j == 4) {
                                if (i + 1 < how && table[j][i] == 'x' && table[j][i + 1] == 'x') {
                                    if (i == 1) {
                                        if (i - 1 >= 0 && table[j][i - 1] == '-') {
                                            if (j == 0) {
                                                first = 1;
                                            } else {
                                                first = 5;
                                            }
                                            second = i;
                                            return;
                                        } else if (i + 2 < how && table[j][i + 2] == '-') {
                                            if (j == 0) {
                                                first = 1;
                                            } else {
                                                first = 5;
                                            }
                                            second = i + 3;
                                            return;
                                        }
                                    } else if (i == 0) {
                                        if (i + 2 < how && table[j][i + 2] == '-') {
                                            if (j == 0) {
                                                first = 1;
                                            } else {
                                                first = 5;
                                            }
                                            second = 3;
                                            return;
                                        }
                                    } else if (i == 2) {
                                        if (i - 1 >= 0 && table[j][i - 1] == '-') {
                                            if (j == 0) {
                                                first = 1;
                                            } else {
                                                first = 5;
                                            }
                                            second = 2;
                                            return;
                                        } else if (i + 2 < how && table[j][i + 2] == '-') {
                                            if (j == 0) {
                                                first = 1;
                                            } else {
                                                first = 5;
                                            }
                                            second = 5;
                                            return;
                                        }
                                    } else if (i == 3) {
                                        if (i - 1 >= 0 && table[j][i - 1] == '-') {
                                            if (j == 0) {
                                                first = 1;
                                            } else {
                                                first = 5;
                                            }
                                            second = 3;
                                            return;
                                        }
                                    }
                                }
                            }
                            if (i == 0 || i == 4) {
                                if (j + 1 < how && table[j][i] == 'x' && table[j + 1][i] == 'x') {
                                    if (j == 1) {
                                        if (table[j - 1][i] == '-') {
                                            if (i == 0) {
                                                second = 1;
                                            } else {
                                                second = 5;
                                            }
                                            first = j;
                                            return;
                                        } else if (j + 2 < how && table[j + 2][i] == '-') {
                                            if (i == 0) {
                                                second = 1;
                                            } else {
                                                second = 5;

                                            }
                                            first = j + 3;
                                            return;
                                        }
                                    } else if (j == 0) {
                                        if (j + 2 < how && table[j + 2][i] == '-') {
                                            if (i == 0) {
                                                second = 1;
                                            } else {
                                                second = 5;
                                            }
                                            first = 3;
                                            return;
                                        }
                                    } else if (j == 2) {
                                        if (j - 1 >= 0 && table[j - 1][i] == '-') {
                                            if (i == 0) {
                                                second = 1;
                                            } else {
                                                second = 5;
                                            }
                                            first = 2;
                                            return;
                                        } else if (j + 2 < how && table[j + 2][i] == '-') {
                                            if (i == 0) {
                                                second = 1;
                                            } else {
                                                second = 5;
                                            }
                                            first = 5;
                                            return;
                                        }
                                    } else if (j == 3) {
                                        if (table[j + 2][i] == '-') {
                                            if (i == 0) {
                                                second = 1;
                                            } else {
                                                second = 5;
                                            }
                                            first = 5;
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    case 5:
                        mediumCPU(whoFirst, ile, second, first, how, table, end, 1);
                        int random = rand() % 3;
                        if (h == 1) {
                            if (table[j][i] == 'o') {
                                if (j == 0 && i == 0) {
                                    if (random == 0) {
                                        second = first = 2;
                                    } else if (random == 1) {
                                        second = 1;
                                        first = 2;
                                    } else {
                                        second = 2;
                                        first = 1;
                                    }
                                } else if (j == 0 && i + 2 < how) {
                                    random = rand() % 5;
                                    if (random == 0) {
                                        first = 1;
                                        second = i;
                                    } else if (random == 1) {
                                        first = 1;
                                        second = i + 2;
                                    } else if (random == 2) {
                                        first = 2;
                                        second = i;
                                    } else if (random == 3) {
                                        first = 2;
                                        second = i + 1;
                                    } else {
                                        first = 2;
                                        second = i + 2;
                                    }
                                } else if (j + 2 < how && i == 0) {
                                    random = rand() % 5;
                                    if (random == 0) {
                                        first = j;
                                        second = 1;
                                    } else if (random == 1) {
                                        first = j + 2;
                                        second = 1;
                                    } else if (random == 2) {
                                        first = j;
                                        second = 2;
                                    } else if (random == 3) {
                                        first = j + 1;
                                        second = 2;
                                    } else {
                                        first = j + 2;
                                        second = 2;
                                    }
                                } else if (j + 2 < how && i == (how - 1)) {
                                    random = rand() % 5;
                                    if (random == 0) {
                                        first = j;
                                        second = how;
                                    } else if (random == 1) {
                                        first = j + 2;
                                        second = how;
                                    } else if (random == 2) {
                                        first = j;
                                        second = how - 1;
                                    } else if (random == 3) {
                                        first = j + 1;
                                        second = how - 1;
                                    } else {
                                        first = j + 2;
                                        second = how - 1;
                                    }
                                } else if (i + 1 < how && j == (how - 1)) {
                                    random = rand() % 5;
                                    if (random == 0) {
                                        first = how;
                                        second = i;
                                    } else if (random == 1) {
                                        first = how;
                                        second = i + 2;
                                    } else if (random == 2) {
                                        first = how - 1;
                                        second = i;
                                    } else if (random == 3) {
                                        first = how - 1;
                                        second = i + 1;
                                    } else {
                                        first = how - 1;
                                        second = i + 2;
                                    }
                                } else if (j == (how - 1) && i == (how - 1)) {
                                    if (random == 0) {
                                        second = first = 9;
                                    } else if (random == 1) {
                                        second = 10;
                                        first = 9;
                                    } else {
                                        second = 9;
                                        first = 10;
                                    }
                                } else {
                                    second = rand() % 3 + i;
                                    first = rand() % 3 + j;
                                }
                            }
                        } else if (h == 0) {
                            second = first = 5;
                        } else {
                            if (h % 2 == 0) {
                                if (!end) {
                                    if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == 'o' &&
                                        table[j][i + 2] == 'o' && table[j][i + 3] == '-' && table[j][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'o') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == 'o' && table[j + 3][i] == '-' &&
                                               table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == 'o' && table[j + 3][i + 3] == '-' &&
                                               table[j + 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' && table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == 'o' && table[j - 3][i + 3] == '-' &&
                                               table[j - 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j - 3;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'o') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' && table[j][i + 3] == '-' &&
                                               table[j][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'x') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == 'x' && table[j + 3][i] == '-' &&
                                               table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == 'x' && table[j + 3][i + 3] == '-' &&
                                               table[j + 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' && table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == 'x' && table[j - 3][i + 3] == '-' &&
                                               table[j - 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j - 3;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'x') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how &&
                                               table[j][i] == 'o' && table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 2] == 'o' && table[j - 2][i + 2] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how &&
                                               table[j][i] == 'o' && table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[i + 1][j + 2] == 'o' && table[i + 2][j + 2] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i - 2 >= 0 &&
                                               table[j][i] == 'o' && table[j][i - 1] == 'o' && table[j][i - 2] == '-' &&
                                               table[j + 1][i - 2] == 'o' && table[j + 2][i - 2] == 'o') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i - 2 >= 0 && j - 2 >= 0 &&
                                               table[j][i] == 'o' && table[j][i - 1] == 'o' && table[j][i - 2] == '-' &&
                                               table[j - 1][i - 2] == 'o' && table[j - 2][i - 2] == 'o') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j - 2 >= 0 && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 2][i] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 1] == 'o' && table[j + 2][i] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j - 2 >= 0 && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 3] == 'o' && table[j - 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j + 2 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' && table[j + 2][i + 2] == '-' &&
                                               table[j + 2][i + 3] == 'o' && table[j + 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 1][i] == 'o' &&
                                               table[j - 2][i + 2] == 'o' && table[j][i + 2] == 'o') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 3] == 'o' && table[j + 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == '-' &&
                                               table[j][i + 1] == 'o' && table[j + 1][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' && table[j + 2][i + 2] == 'o') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j - 2 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 2][i + 2] == '-' &&
                                               table[j - 2][i + 3] == 'o' && table[j - 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how &&
                                               table[j][i] == 'x' && table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 2] == 'x' && table[j - 2][i + 2] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how &&
                                               table[j][i] == 'x' && table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[i + 1][j + 2] == 'x' && table[i + 2][j + 2] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i - 2 >= 0 &&
                                               table[j][i] == 'x' && table[j][i - 1] == 'x' && table[j][i - 2] == '-' &&
                                               table[j + 1][i - 2] == 'x' && table[j + 2][i - 2] == 'x') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i - 2 >= 0 && j - 2 >= 0 &&
                                               table[j][i] == 'x' && table[j][i - 1] == 'x' && table[j][i - 2] == '-' &&
                                               table[j - 1][i - 2] == 'x' && table[j - 2][i - 2] == 'x') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j - 2 >= 0 && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 2][i] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 1] == 'x' && table[j + 2][i] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j - 2 >= 0 && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 3] == 'x' && table[j - 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j + 2 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' && table[j + 2][i + 2] == '-' &&
                                               table[j + 2][i + 3] == 'x' && table[j + 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 1][i] == 'x' &&
                                               table[j - 2][i + 2] == 'x' && table[j][i + 2] == 'x') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 3] == 'x' && table[j + 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == '-' &&
                                               table[j][i + 1] == 'x' && table[j + 1][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' && table[j + 2][i + 2] == 'x') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j - 2 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 2][i + 2] == '-' &&
                                               table[j - 2][i + 3] == 'x' && table[j - 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (k == 1) {
                                        if (i + 1 < how && table[j][i] == 'o' && table[j][i + 1] == 'o') {
                                            if (i + 4 < how && table[j][i + 2] == '-' && table[j][i + 3] == '-' &&
                                                table[j][i + 4] == '-') {
                                                second = i + 3;
                                                first = j + 1;
                                                return;
                                            } else if (i + 3 < how && i - 1 >= 0 && table[j][i + 2] == '-' &&
                                                       table[j][i + 3] == '-' && table[j][i - 1] == '-') {
                                                second = i + 3;
                                                first = j + 1;
                                                return;
                                            } else if (i + 2 < how && i - 2 >= 0 && table[j][i + 2] == '-' &&
                                                       table[j][i - 1] == '-' && table[j][i - 2] == '-') {
                                                second = i + 3;
                                                first = j + 1;
                                                return;
                                            } else if (i - 3 >= 0 && table[j][i - 1] == '-' && table[j][i - 2] == '-' &&
                                                       table[j][i - 3] == '-') {
                                                second = i;
                                                first = j + 1;
                                                return;
                                            }
                                        }
                                        if (j + 1 < how && table[j][i] == 'o' && table[j + 1][i] == 'o') {
                                            if (j + 4 < how && table[j + 2][i] == '-' && table[j + 3][i] == '-' &&
                                                table[j + 4][i] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j + 3 < how && j - 1 >= 0 && table[j + 2][i] == '-' &&
                                                       table[j + 3][i] == '-' && table[j - 1][i] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j + 2 < how && j - 2 >= 0 && table[j + 2][i] == '-' &&
                                                       table[j - 1][i] == '-' && table[j - 2][i] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j - 3 >= 0 && table[j - 1][i] == '-' && table[j - 2][i] == '-' &&
                                                       table[j - 3][i] == '-') {
                                                second = i + 1;
                                                first = j;
                                                return;
                                            }
                                        }
                                        if (j + 1 < how && i + 1 < how && table[j][i] == 'o' &&
                                            table[j + 1][i + 1] == 'o') {
                                            if (j + 4 < how && i + 4 < how && table[j + 2][i + 2] == '-' &&
                                                table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == '-') {
                                                second = i + 3;
                                                first = j + 3;
                                                return;
                                            } else if (j + 3 < how && j - 1 >= 0 && i + 3 < how && i - 1 >= 0 &&
                                                       table[j + 2][i + 2] == '-' && table[j + 3][i + 3] == '-' &&
                                                       table[j - 1][i - 1] == '-') {
                                                second = i + 3;
                                                first = j + 3;
                                                return;
                                            } else if (j + 2 < how && j - 2 >= 0 && i + 2 < how && i - 2 >= 0 &&
                                                       table[j + 2][i + 2] == '-' && table[j - 1][i - 1] == '-' &&
                                                       table[j - 2][i - 2] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j - 3 >= 0 && i - 3 >= 0 && table[j - 1][i - 1] == '-' &&
                                                       table[j - 2][i - 2] == '-' && table[j - 3][i - 3] == '-') {
                                                second = i;
                                                first = j;
                                                return;
                                            }
                                        }
                                        if (j - 1 >= 0 && i + 1 < how && table[j][i] == 'o' &&
                                            table[j - 1][i + 1] == 'o') {
                                            if (j - 4 >= 0 && i + 4 < how && table[j - 2][i + 2] == '-' &&
                                                table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == '-') {
                                                second = i + 3;
                                                first = j - 1;
                                                return;
                                            } else if (j + 1 < how && j - 3 >= 0 && i + 3 < how && i - 1 >= 0 &&
                                                       table[j - 2][i + 2] == '-' &&
                                                       table[j - 3][i + 3] == '-' && table[j + 1][i - 1] == '-') {
                                                second = i + 3;
                                                first = j - 1;
                                                return;
                                            } else if (j + 2 < how && j - 2 >= 0 && i + 2 < how && i - 2 >= 0 &&
                                                       table[j - 2][i + 2] == '-' &&
                                                       table[j + 1][i - 1] == '-' && table[j + 2][i - 2] == '-') {
                                                second = i + 1;
                                                first = j - 1;
                                                return;
                                            } else if (j + 3 < how && i - 3 >= 0 && table[j + 1][i - 1] == '-' &&
                                                       table[j + 2][i - 2] == '-' &&
                                                       table[j + 3][i - 3] == '-') {
                                                second = i;
                                                first = j + 2;
                                                return;
                                            }
                                        }

                                        if (table[j][i] == 'o') {
                                            random = rand() % 8;
                                            if (random == 0) {
                                                if (j + 1 < how && table[j + 1][i] == '-') {
                                                    second = i + 1;
                                                    first = j + 2;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 1) {
                                                if (j - 1 >= 0 && table[j - 1][i] == '-') {
                                                    second = i + 1;
                                                    first = j;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 2) {
                                                if (i - 1 >= 0 && table[j][i - 1] == '-') {
                                                    second = i;
                                                    first = j + 1;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 3) {
                                                if (j - 1 >= 0 && i - 1 >= 0 && table[j - 1][i - 1] == '-') {
                                                    second = i;
                                                    first = j;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 4) {
                                                if (j - 1 >= 0 && i + 1 < how && table[j - 1][i + 1] == '-') {
                                                    second = i + 2;
                                                    first = j;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 5) {
                                                if (j + 1 < how && i >= 0 && table[j + 1][i - 1] == '-') {
                                                    second = i;
                                                    first = j + 2;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 6) {
                                                if (i + 1 < how && table[j][i + 1] == '-') {
                                                    second = i + 2;
                                                    first = j + 1;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 7) {
                                                if (j + 1 < how && i + 1 < how && table[j + 1][i + 1] == '-') {
                                                    second = i + 2;
                                                    first = j + 2;
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    end = 0;
                                }
                            } else {
                                if (!end) {
                                    if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == 'x' &&
                                        table[j][i + 2] == 'x' && table[j][i + 3] == '-' && table[j][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'x' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'x') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'x' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'x' &&
                                               table[j][i + 3] == 'x' && table[j][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == 'x' && table[j + 3][i] == '-' &&
                                               table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'x' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'x' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'x' &&
                                               table[j + 3][i] == 'x' && table[j + 4][i] == 'x') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == 'x' && table[j + 3][i + 3] == '-' &&
                                               table[j + 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' && table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'x' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'x' &&
                                               table[j + 3][i + 3] == 'x' && table[j + 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == 'x' && table[j - 3][i + 3] == '-' &&
                                               table[j - 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == '-' && table[j + 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j - 3;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'x') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'x' &&
                                               table[j - 3][i + 3] == 'x' && table[j - 4][i + 4] == 'x') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' && table[j][i + 3] == '-' &&
                                               table[j][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == 'o' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == '-' && table[j][i + 4] == 'o') {
                                        second = i + 4;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == 'o' &&
                                               table[j][i + 2] == '-' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && table[j][i] == '-' && table[j][i + 1] == '-' &&
                                               table[j][i + 2] == 'o' &&
                                               table[j][i + 3] == 'o' && table[j][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 1;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == 'o' && table[j + 3][i] == '-' &&
                                               table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == 'o' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == '-') {
                                        second = i + 1;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == '-' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == 'o' &&
                                               table[j + 2][i] == '-' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && table[j][i] == '-' && table[j + 1][i] == '-' &&
                                               table[j + 2][i] == 'o' &&
                                               table[j + 3][i] == 'o' && table[j + 4][i] == 'o') {
                                        second = i + 1;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == 'o' && table[j + 3][i + 3] == '-' &&
                                               table[j + 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' && table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j + 5;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 4;
                                        first = j + 4;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == 'o' &&
                                               table[j + 2][i + 2] == '-' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j + 4 < how && i + 4 < how && table[j][i] == '-' &&
                                               table[j + 1][i + 1] == '-' &&
                                               table[j + 2][i + 2] == 'o' &&
                                               table[j + 3][i + 3] == 'o' && table[j + 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j + 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == 'o' && table[j - 3][i + 3] == '-' &&
                                               table[j - 4][i + 4] == '-') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == '-') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == '-') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == '-' && table[j + 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == '-') {
                                        second = i + 5;
                                        first = j - 3;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == 'o') {
                                        second = i + 4;
                                        first = j - 2;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' &&
                                               table[j - 2][i + 2] == '-' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 4 >= 0 && i + 4 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == '-' &&
                                               table[j - 2][i + 2] == 'o' &&
                                               table[j - 3][i + 3] == 'o' && table[j - 4][i + 4] == 'o') {
                                        second = i + 2;
                                        first = j;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how &&
                                               table[j][i] == 'x' && table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 2] == 'x' && table[j - 2][i + 2] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how &&
                                               table[j][i] == 'x' && table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[i + 1][j + 2] == 'x' && table[i + 2][j + 2] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i - 2 >= 0 &&
                                               table[j][i] == 'x' && table[j][i - 1] == 'x' && table[j][i - 2] == '-' &&
                                               table[j + 1][i - 2] == 'x' && table[j + 2][i - 2] == 'x') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i - 2 >= 0 && j - 2 >= 0 &&
                                               table[j][i] == 'x' && table[j][i - 1] == 'x' && table[j][i - 2] == '-' &&
                                               table[j - 1][i - 2] == 'x' && table[j - 2][i - 2] == 'x') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j - 2 >= 0 && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 2][i] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 1] == 'x' && table[j + 2][i] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j - 2 >= 0 && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 3] == 'x' && table[j - 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j + 2 < how && table[j][i] == 'x' &&
                                               table[j + 1][i + 1] == 'x' && table[j + 2][i + 2] == '-' &&
                                               table[j + 2][i + 3] == 'x' && table[j + 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 1][i] == 'x' &&
                                               table[j - 2][i + 2] == 'x' && table[j][i + 2] == 'x') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i + 4 < how && table[j][i] == 'x' &&
                                               table[j][i + 1] == 'x' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 3] == 'x' && table[j + 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == '-' &&
                                               table[j][i + 1] == 'x' && table[j + 1][i + 1] == 'x' &&
                                               table[j][i + 2] == 'x' && table[j + 2][i + 2] == 'x') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j - 2 >= 0 && i + 4 < how && table[j][i] == 'x' &&
                                               table[j - 1][i + 1] == 'x' && table[j - 2][i + 2] == '-' &&
                                               table[j - 2][i + 3] == 'x' && table[j - 2][i + 4] == 'x') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how &&
                                               table[j][i] == 'o' && table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 2] == 'o' && table[j - 2][i + 2] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how &&
                                               table[j][i] == 'o' && table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[i + 1][j + 2] == 'o' && table[i + 2][j + 2] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i - 2 >= 0 &&
                                               table[j][i] == 'o' && table[j][i - 1] == 'o' && table[j][i - 2] == '-' &&
                                               table[j + 1][i - 2] == 'o' && table[j + 2][i - 2] == 'o') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i - 2 >= 0 && j - 2 >= 0 &&
                                               table[j][i] == 'o' && table[j][i - 1] == 'o' && table[j][i - 2] == '-' &&
                                               table[j - 1][i - 2] == 'o' && table[j - 2][i - 2] == 'o') {
                                        second = i - 1;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j - 2 >= 0 && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 2][i] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 1] == 'o' && table[j + 2][i] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j - 2 >= 0 && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j - 1][i + 3] == 'o' && table[j - 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 4 < how && j + 2 < how && table[j][i] == 'o' &&
                                               table[j + 1][i + 1] == 'o' && table[j + 2][i + 2] == '-' &&
                                               table[j + 2][i + 3] == 'o' && table[j + 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 3;
                                        return;
                                    } else if (j - 2 >= 0 && i + 2 < how && table[j][i] == '-' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 1][i] == 'o' &&
                                               table[j - 2][i + 2] == 'o' && table[j][i + 2] == 'o') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j + 2 < how && i + 4 < how && table[j][i] == 'o' &&
                                               table[j][i + 1] == 'o' && table[j][i + 2] == '-' &&
                                               table[j + 1][i + 3] == 'o' && table[j + 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j + 1;
                                        return;
                                    } else if (i + 2 < how && j + 2 < how && table[j][i] == '-' &&
                                               table[j][i + 1] == 'o' && table[j + 1][i + 1] == 'o' &&
                                               table[j][i + 2] == 'o' && table[j + 2][i + 2] == 'o') {
                                        second = i + 1;
                                        first = j + 1;
                                        return;
                                    } else if (j - 2 >= 0 && i + 4 < how && table[j][i] == 'o' &&
                                               table[j - 1][i + 1] == 'o' && table[j - 2][i + 2] == '-' &&
                                               table[j - 2][i + 3] == 'o' && table[j - 2][i + 4] == 'o') {
                                        second = i + 3;
                                        first = j - 1;
                                        return;
                                    } else if (k == 1) {
                                        if (i + 1 < how && table[j][i] == 'x' && table[j][i + 1] == 'x') {
                                            if (i + 4 < how && table[j][i + 2] == '-' && table[j][i + 3] == '-' &&
                                                table[j][i + 4] == '-') {
                                                second = i + 3;
                                                first = j + 1;
                                                return;
                                            } else if (i + 3 < how && i - 1 >= 0 && table[j][i + 2] == '-' &&
                                                       table[j][i + 3] == '-' && table[j][i - 1] == '-') {
                                                second = i + 3;
                                                first = j + 1;
                                                return;
                                            } else if (i + 2 < how && i - 2 >= 0 && table[j][i + 2] == '-' &&
                                                       table[j][i - 1] == '-' && table[j][i - 2] == '-') {
                                                second = i + 3;
                                                first = j + 1;
                                                return;
                                            } else if (i - 3 >= 0 && table[j][i - 1] == '-' && table[j][i - 2] == '-' &&
                                                       table[j][i - 3] == '-') {
                                                second = i;
                                                first = j + 1;
                                                return;
                                            }
                                        }
                                        if (j + 1 < how && table[j][i] == 'x' && table[j + 1][i] == 'x') {
                                            if (j + 4 < how && table[j + 2][i] == '-' && table[j + 3][i] == '-' &&
                                                table[j + 4][i] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j + 3 < how && j - 1 >= 0 && table[j + 2][i] == '-' &&
                                                       table[j + 3][i] == '-' && table[j - 1][i] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j + 2 < how && j - 2 >= 0 && table[j + 2][i] == '-' &&
                                                       table[j - 1][i] == '-' && table[j - 2][i] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j - 3 >= 0 && table[j - 1][i] == '-' && table[j - 2][i] == '-' &&
                                                       table[j - 3][i] == '-') {
                                                second = i + 1;
                                                first = j;
                                                return;
                                            }
                                        }
                                        if (j + 1 < how && i + 1 < how && table[j][i] == 'x' &&
                                            table[j + 1][i + 1] == 'x') {
                                            if (j + 4 < how && i + 4 < how && table[j + 2][i + 2] == '-' &&
                                                table[j + 3][i + 3] == '-' && table[j + 4][i + 4] == '-') {
                                                second = i + 3;
                                                first = j + 3;
                                                return;
                                            } else if (j + 3 < how && j - 1 >= 0 && i + 3 < how && i - 1 >= 0 &&
                                                       table[j + 2][i + 2] == '-' && table[j + 3][i + 3] == '-' &&
                                                       table[j - 1][i - 1] == '-') {
                                                second = i + 3;
                                                first = j + 3;
                                                return;
                                            } else if (j + 2 < how && j - 2 >= 0 && i + 2 < how && i - 2 >= 0 &&
                                                       table[j + 2][i + 2] == '-' && table[j - 1][i - 1] == '-' &&
                                                       table[j - 2][i - 2] == '-') {
                                                second = i + 1;
                                                first = j + 3;
                                                return;
                                            } else if (j - 3 >= 0 && i - 3 >= 0 && table[j - 1][i - 1] == '-' &&
                                                       table[j - 2][i - 2] == '-' && table[j - 3][i - 3] == '-') {
                                                second = i;
                                                first = j;
                                                return;
                                            }
                                        }
                                        if (j - 1 >= 0 && i + 1 < how && table[j][i] == 'x' &&
                                            table[j - 1][i + 1] == 'x') {
                                            if (j - 4 >= 0 && i + 4 < how && table[j - 2][i + 2] == '-' &&
                                                table[j - 3][i + 3] == '-' && table[j - 4][i + 4] == '-') {
                                                second = i + 3;
                                                first = j - 1;
                                                return;
                                            } else if (j + 1 < how && j - 3 >= 0 && i + 3 < how && i - 1 >= 0 &&
                                                       table[j - 2][i + 2] == '-' &&
                                                       table[j - 3][i + 3] == '-' && table[j + 1][i - 1] == '-') {
                                                second = i + 3;
                                                first = j - 1;
                                                return;
                                            } else if (j + 2 < how && j - 2 >= 0 && i + 2 < how && i - 2 >= 0 &&
                                                       table[j - 2][i + 2] == '-' &&
                                                       table[j + 1][i - 1] == '-' && table[j + 2][i - 2] == '-') {
                                                second = i + 1;
                                                first = j - 1;
                                                return;
                                            } else if (j + 3 < how && i - 3 >= 0 && table[j + 1][i - 1] == '-' &&
                                                       table[j + 2][i - 2] == '-' &&
                                                       table[j + 3][i - 3] == '-') {
                                                second = i;
                                                first = j + 2;
                                                return;
                                            }
                                        }

                                        if (table[j][i] == 'x') {
                                            random = rand() % 8;
                                            if (random == 0) {
                                                if (j + 1 < how && table[j + 1][i] == '-') {
                                                    second = i + 1;
                                                    first = j + 2;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 1) {
                                                if (j - 1 >= 0 && table[j - 1][i] == '-') {
                                                    second = i + 1;
                                                    first = j;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 2) {
                                                if (i - 1 >= 0 && table[j][i - 1] == '-') {
                                                    second = i;
                                                    first = j + 1;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 3) {
                                                if (j - 1 >= 0 && i - 1 >= 0 && table[j - 1][i - 1] == '-') {
                                                    second = i;
                                                    first = j;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 4) {
                                                if (j - 1 >= 0 && i + 1 < how && table[j - 1][i + 1] == '-') {
                                                    second = i + 2;
                                                    first = j;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 5) {
                                                if (j + 1 < how && i >= 0 && table[j + 1][i - 1] == '-') {
                                                    second = i;
                                                    first = j + 2;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 6) {
                                                if (i + 1 < how && table[j][i + 1] == '-') {
                                                    second = i + 2;
                                                    first = j + 1;
                                                    return;
                                                } else random++;
                                            }
                                            if (random == 7) {
                                                if (j + 1 < how && i + 1 < how && table[j + 1][i + 1] == '-') {
                                                    second = i + 2;
                                                    first = j + 2;
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    end = 0;
                                }
                            }

                        }
                        break;
                }
            }
        }
    }
}

/*
 * Jak grać?
 * */
void howPlay() {
    system(CLEAN);
    cout << "Witaj w grze kółko i krzyżyk!" << endl;
    cout << "Masz możliwość wybrania 3 planszy:" << endl;
    cout << "1. 3x3 - warunek zwycięstwa to 3 obok siebie kółka lub krzyżyki." << endl;
    cout << "2. 5x5 - warunek zwycięstwa to 4 obok siebie kółka lub krzyżyki." << endl;
    cout << "3. 10x10 - warunek zwycięstwa to 5 obok siebie kółek lub krzyżyków." << endl;
    cout << "Aby wybrać pole podaj współrzędne x(poziomo) oraz y(pionowo)." << endl;
    sleep(WAIT2);
}

/*
 * Wybór pola
 * */

void switched(int enemy, int who, int &first, int &second, int how, int ile, int whoFirst, int h, char **table,
              bool &block, bool &end) {
    string coordinate;
    bool checkThis;
    if (enemy == 1 || who == 0) {
        do {
            second = -1;
            first = -1;
            coordinate = "";
            cout << "Podaj współrzędną x: ";
            do {
                checkThis = true;
                getline(cin, coordinate);
                if (coordinate.size() > 0) {
                    istringstream iss(coordinate);
                    iss >> second;
                }
                if (second > how || second < 1) {
                    cout << "Proszę podać współrzędną x w zakresie od 1 do " << how << ": " << endl;
                    checkThis = false;
                }
            } while (!checkThis);
            cout << "Podaj współrzędną y: ";
            do {
                checkThis = true;
                getline(cin, coordinate);
                if (coordinate.size() > 0) {
                    istringstream iss(coordinate);
                    iss >> first;
                }
                coordinate = "";
                if (first > how || first < 1) {
                    cout << "Proszę podać współrzędną y w zakresie od 1 do " << how << ": " << endl;
                    checkThis = false;
                }
            } while (!checkThis);
            cout << "Wybrane pole: " << second << "," << first << endl;
            first = first - 1;
            second = second - 1;
            if (table[first][second] == 'x' || table[first][second] == 'o') {
                cout << "Podana współrzędna jest już zajęta." << endl;
                checkThis = false;
            }
        } while (!checkThis);
    } else {
        sleep(WAIT);
        do {
            second = -1;
            first = -1;
            do {
                first = rand() % how + 1;
                do {
                    checkThis = true;
                    second = rand() % how + 1;
                    if (enemy == 3) mediumCPU(whoFirst, ile, second, first, how, table, end);
                    else if (enemy == 4) hardCPU(whoFirst, ile, second, first, how, h, table, block, end);

                    if (second > how || second < 1)checkThis = false;
                } while (!checkThis);
                if (first > how || first < 1) checkThis = false;

            } while (!checkThis);
            first = first - 1;
            second = second - 1;
            if (table[first][second] == 'x' || table[first][second] == 'o') checkThis = false;
        } while (!checkThis);
    }
}

/*
 * Sprawdzenie zwycięstwa
 * */

void checkWin(int whoFirst, int who, int how, int ile, int &result, int enemy, int &finish, char **table,
              string player1, string player2) {
    int x, y;
    char win;
    if (whoFirst == 0) {
        win = 'o';
    } else {
        win = 'x';
    }
    x = 0;
    y = 0;
    for (int i = 0; i < how; i++) {
        for (int j = 0; j < how; j++) {
            switch (ile) {
                case 3:
                    if (j == 0
                        && table[y][x] == win
                        && table[y + 1][x] == win
                        && table[y + 2][x] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (table[y][x] == win
                               && table[y][x + 1] == win
                               && table[y][x + 2] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (j == 0
                               && table[y][x] == win
                               && table[y + 1][x + 1] == win
                               && table[y + 2][x + 2] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (j == 0 && table[y + 2][x] == win
                               && table[y + 1][x + 1] == win
                               && table[y][x + 2] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    }
                    break;
                case 4:
                    if (j <= 1
                        && table[y][x] == win
                        && table[y + 1][x] == win
                        && table[y + 2][x] == win
                        && table[y + 3][x] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (table[y][x] == win
                               && table[y][x + 1] == win
                               && table[y][x + 2] == win
                               && table[y][x + 3] == win) {
                        if (who == 0) result = 1;
                        else result = 2;

                        finish = 1;
                    } else if (j <= 1 && table[y][x] == win
                               && table[y + 1][x + 1] == win
                               && table[y + 2][x + 2] == win
                               && table[y + 3][x + 3] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (j <= 1 && table[y + 3][x] == win
                               && table[y + 2][x + 1] == win
                               && table[y + 1][x + 2] == win
                               && table[y][x + 3] == win) {
                        if (who == 0)result = 1;
                        else result = 2;
                        finish = 1;
                    }
                    break;
                case 5:
                    if (j <= 5 && table[y][x] == win
                        && table[y + 1][x] == win
                        && table[y + 2][x] == win
                        && table[y + 3][x] == win
                        && table[y + 4][x] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (table[y][x] == win
                               && table[y][x + 1] == win
                               && table[y][x + 2] == win
                               && table[y][x + 3] == win
                               && table[y][x + 4] == win) {
                        if (who == 0) result = 1;
                        else result = 2;

                        finish = 1;
                    } else if (j <= 5 && table[y][x] == win
                               && table[y + 1][x + 1] == win
                               && table[y + 2][x + 2] == win
                               && table[y + 3][x + 3] == win
                               && table[y + 4][x + 4] == win) {
                        if (who == 0) result = 1;
                        else result = 2;
                        finish = 1;
                    } else if (j <= 5 && table[y + 4][x] == win
                               && table[y + 3][x + 1] == win
                               && table[y + 2][x + 2] == win
                               && table[y + 1][x + 3] == win
                               && table[y][x + 4] == win) {
                        if (who == 0)result = 1;
                        else result = 2;
                        finish = 1;
                    }
                    break;
            }
            if (result == 1) {
                cout << "Wygrał " << player1 << "." << endl;
                return;
            } else if (result == 2) {
                if (enemy == 1) cout << "Wygrał " << player2 << "." << endl;
                else cout << "Wygrał komputer." << endl;
                return;
            }

            y++;
        }
        y = 0;
        x++;
    }
}

/*
 * Główna rozgrywka
 * */

void
playGame(int enemy, int border, int how, int ile, int &result, char **table, string player1, string player2) {
    bool block = 1;
    int first, second, h, who, whoFirst, finish;
    h = finish = 0;
    bool end = 0;
    first = -1;
    second = -1;
    who = rand() % 2;
    if (who == 0) {
        cout << player1 << " rozpoczyna grę." << endl;
        whoFirst = 0;
    } else {
        whoFirst = 0;
        if (enemy == 1) {
            cout << player2 << " rozpoczyna grę." << endl;
        } else {
            cout << "Komputer rozpoczyna grę." << endl;
        }
    }
    do {
        switched(enemy, who, first, second, how, ile, whoFirst, h, table, block, end);
        system(CLEAN);
        for (int k = 0; k < border; k++) {
            if (k == 0) {
                cout << "      -";
            } else if (k != 0 && k != (border - 1) && k < 10) {
                cout << k << "---";
            } else if (k != 0 && k != (border - 1) && k >= 10) {
                cout << k << "--";
            } else if (k == (border - 1)) {
                cout << k << "-  " << endl;
            }
        }
        for (int i = 0; i < how; i++) {
            for (int j = 0; j < how; j++) {
                if (j == 0) {
                    if (i >= 0 && i < 9) {
                        cout << "  " << i + 1 << " | ";
                    } else if (i >= 9 && i < 99) {
                        cout << " " << i + 1 << " | ";
                    } else if (i >= 99) {
                        cout << i + 1 << " | ";
                    }
                }
                if ((i != 0 || i != (how - 1))) {
                    if (first == i && second == j && whoFirst == 0) {
                        table[i][j] = 'o';
                    } else if (first == i && second == j && whoFirst == 1) {
                        table[i][j] = 'x';
                    }
                    cout << " " << table[i][j] << "  ";

                    if (j == (how - 1)) {
                        cout << "|" << endl;
                    }
                }
            }
        }
        for (int k = 0; k < border; k++) {
            if (k == 0) {
                cout << "      -";
            } else if (k != 0 && k != (border - 1) && k < 10) {
                cout << "----";
            } else if (k != 0 && k != (border - 1) && k >= 10) {
                cout << "---";
            } else if (k == (border - 1)) {
                cout << "--  " << endl;
            }
        }
        h++;
        checkWin(whoFirst, who, how, ile, result, enemy, finish, table, player1, player2);
        if (finish) break;
        if (who == 0 && h < (how * how) && enemy == 1) {
            who = 1;
            if (whoFirst == 0) {
                whoFirst = 1;
            } else {
                whoFirst = 0;
            }
            cout << "Teraz ruch gracza " << player2 << "." << endl;
        } else if (who == 0 && h < (how * how) && enemy != 1) {
            who = 1;
            if (whoFirst == 0) {
                whoFirst = 1;
            } else {
                whoFirst = 0;
            }
            cout << "Teraz ruch komputera." << endl;
        } else if (who == 1 && h < (how * how)) {
            who = 0;
            if (whoFirst == 0) {
                whoFirst = 1;
            } else {
                whoFirst = 0;
            }
            cout << "Teraz ruch gracza " << player1 << "." << endl;
        }
    } while ((h < (how * how)));
    if (finish == 1 && enemy == 1) {
        cout << "Gratulacje dla zwycięzcy!" << endl;
    } else if (finish == 1 && enemy != 1) {
        if (who == 1 && result == 2) {
            cout << "Spróbuj ponownie :)" << endl;
        } else if (who == 0 && result == 1) {
            cout << "Gratulacje!" << endl;
        } else {
            cout << "Remis." << endl;
            result = 0;
        }
    } else {
        result = 0;
        cout << "Remis." << endl;
    }
    sleep(WAIT);
}

/*
 * Wypisanie pierwszej planszy
 * */

void ticTacToe(int how, int &border, char **table) {
    system(CLEAN);
    border = how + 1;
    for (int k = 0; k < border; k++) {
        if (k == 0) {
            cout << "      -";
        } else if (k != 0 && k != (border - 1) && k < 10) {
            cout << k << "---";
        } else if (k != 0 && k != (border - 1) && k >= 10) {
            cout << k << "--";
        } else if (k == (border - 1)) {
            cout << k << "-  " << endl;
        }
    }
    for (int i = 0; i < how; i++) {
        for (int j = 0; j < how; j++) {
            if (j == 0) {
                if (i >= 0 && i < 9) {
                    cout << "  " << i + 1 << " | ";
                } else if (i >= 9 && i < 99) {
                    cout << " " << i + 1 << " | ";
                } else if (i >= 99) {
                    cout << i + 1 << " | ";
                }
            }
            if ((i != 0 || i != (how - 1))) {
                table[i][j] = '-';
                cout << " " << table[i][j] << "  ";

                if (j == (how - 1)) {
                    cout << "|" << endl;
                }
            }
        }
    }
    for (int k = 0; k < border; k++) {
        if (k == 0) {
            cout << "      -";
        } else if (k != 0 && k != (border - 1) && k < 10) {
            cout << "----";
        } else if (k != 0 && k != (border - 1) && k >= 10) {
            cout << "---";
        } else if (k == (border - 1)) {
            cout << "--  " << endl;
        }
    }
}

/*
 * Wybór czy ma grać gracz vs gracz lub gracz vs sztuczna inteligencja oraz nazwanie graczy
 * */
void namePlayers(string &player1, string &player2) {
    system(CLEAN);
    cin.ignore();
    bool checkThis;
    do {
        checkThis = true;
        cout << "Wprowadź nazwę gracza nr 1: ";
        getline(cin, player1);
        if (player1 == "") {
            cout << "Podaj nazwę gracza!" << endl;
            checkThis = false;
        }
    } while (!checkThis);
    system(CLEAN);
    do {
        checkThis = true;
        cout << "Wprowadź nazwę gracza nr 2: ";
        getline(cin, player2);
        if (player2 == "") {
            cout << "Podaj nazwę gracza!" << endl;
            checkThis = false;
        } else if (player1 == player2) {
            cout << "Podaj inną nazwę gracza!" << endl;
            checkThis = false;
        }
    } while (!checkThis);
}

void namePlayers(string &player1) {
    system(CLEAN);
    cin.ignore();
    bool checkThis;
    do {
        checkThis = true;
        cout << "Wprowadź nazwę gracza nr 1: ";
        getline(cin, player1);
        if (player1 == "") {
            cout << "Podaj nazwę gracza!" << endl;
            checkThis = false;
        }
    } while (!checkThis);

}

void firstChoose(int how, int ile) {

    int enemy, border, result;
    char size, **table;
    string player1, player2;
    createTable(table, how);
    system(CLEAN);
    cout << "Wybierz przeciwnika" << endl;
    cout << "1. Gracz vs gracz." << endl;
    cout << "2. Łatwy komputer." << endl;
    cout << "3. Średni komputer." << endl;
    cout << "4. Trudny komputer." << endl;
    cout << "0. Powrót do menu gry." << endl;
    cout << "Wybierz opcję: ";
    do {
        cin >> size;
        switch (size) {
            case '1':
                enemy = 1;
                namePlayers(player1, player2);
                ticTacToe(how, border, table);
                playGame(enemy, border, how, ile, result, table, player1, player2);
                break;
            case '2':
                enemy = 2;
                namePlayers(player1);
                ticTacToe(how, border, table);
                playGame(enemy, border, how, ile, result, table, player1, player2);
                break;
            case '3':
                enemy = 3;
                namePlayers(player1);
                ticTacToe(how, border, table);
                playGame(enemy, border, how, ile, result, table, player1, player2);
                break;
            case '4':
                enemy = 4;
                namePlayers(player1);
                ticTacToe(how, border, table);
                playGame(enemy, border, how, ile, result, table, player1, player2);
                break;
            case '0':
                break;
            default:
                cout << "Proszę wybrać jedną z 5 opcji" << endl;
        }
        if (size >= '0' && size <= '4') break;
    } while (size == '0');
    destroyTable(table, how);
}

/*
 * Menu w grze kółko i krzyżyk
 * */

void menuInTicTacToe() {
    int how, ile;
    char size;
    do {
        system(CLEAN);
        cout << "Kółko i krzyżyk" << endl;
        cout << "1. Plansza 3x3" << endl;
        cout << "2. Plansza 5x5" << endl;
        cout << "3. Plansza 10x10" << endl;
        cout << "4. Jak grać?" << endl;
        cout << "0. Koniec" << endl;
        cout << "Wybierz opcję: ";
        do {
            cin >> size;
            switch (size) {
                case '1':
                    how = 3;
                    ile = 3;
                    firstChoose(how, ile);
                    break;
                case '2':
                    how = 5;
                    ile = 4;
                    firstChoose(how, ile);
                    break;
                case '3':
                    how = 10;
                    ile = 5;
                    firstChoose(how, ile);
                    break;
                case '4':
                    howPlay();
                    break;
                case '0':
                    break;
                default:
                    cout << "Proszę wybrać jedną z 5 opcji:";
            }
            if (size >= '0' && size <= '4') break;
        } while (true);
    } while (size != '0');
}

int main (){
    LOCATE;
    menuInTicTacToe();
}