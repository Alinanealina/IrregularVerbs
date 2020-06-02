#include "k.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void check(char answer[20], int* flag_error)
{
    for (int i = 0; i < strlen(answer); i++) {
        if (((answer[i] < 97 || answer[i] > 122) && answer[i] != ' ') 
        	|| strlen(answer) > 20) {
            attron(COLOR_PAIR(8));
            printw("Error comand. Enter again: ");
            refresh();
            *flag_error = 1;
            attroff(COLOR_PAIR(8));
            break;
        } else
            *flag_error = 0;
    }
}

int read_file()
{
    echo();
    keypad(stdscr, false);
    int y = 3;
    FILE *verb, *restab;
    char ch, answer[20], correct[20], surname[20];
    int i, N, A[10], j, k, l, result = 0, len;
    srand(time(NULL));
    attron(COLOR_PAIR(4));
    verb = fopen("verbs.txt", "r");
    for (i = 0; i < 10; i++) {
        while (1) {
            k = 0;
            N = rand() % 206;
            for (j = 0; j < i; j++) {
                if (A[j] == N)
                    k = 1;
            }
            if (k != 1) {
                A[i] = N;
                break;
            }
        }
        rewind(verb);
        for (l = 0; l < N; l++) {
            while (ch != '\n') {
                ch = getc(verb);
                refresh();
            }
            ch = getc(verb);
            refresh();
        }
        printw(" %d. ", i + 1);
        refresh();
        while ((ch = getc(verb)) != '*') {
            if (ch != '#')
                printw("%c", ch);
            refresh();
        }
        printw(" ");
        refresh();
        int flag_error = 1;
        while (flag_error == 1) {
            getstr(answer);
            if (strncmp(answer, "exit", 4) == 0)
                return 0;
            check(answer, &flag_error);
        }
        attroff(A_BLINK);
        len = strlen(answer);
        while ((ch = getc(verb)) != '!') {
            printw("%c", ch - 4);
            refresh();
        }
        y += 7;
        if (j == len) {
            if (strncmp(correct, answer, j) == 0)
                result++;
        }
        printw("\t\t%d/10", result);
        printw("\n\n");
        refresh();
    }
    fclose(verb);
    printw("Result: %d/10\n\t\t\t\t\tEnter your surname: ", result);
    refresh();
    restab = fopen("result_table.txt", "a");
    getstr(surname);
    refresh();
    if (strncmp(surname, "exit", 4) == 0)
        return 0;
    fputs(surname, restab);
    fprintf(restab, " - %d\n", result);
    refresh();
    fclose(restab);

    return 0;
}
