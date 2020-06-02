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
void RandomQuestion(int i, int A[], int* N)
{
    int k, j;
    while (1) {
        k = 0;
        *N = rand() % 206;
        for (j = 0; j < i; j++) {
            if (A[j] == *N)
                k = 1;
        }
        if (k != 1) {
            A[i] = *N;
            break;
        }
    }
}
void PrintQuestion(int N, int i, FILE* verb)
{
    int j;
    char ch;
    for (j = 0; j < N; j++) {
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
}
int WriteAndCheckAnswer(FILE* verb, int* result, int x, int y)
{
    char ch, answer[20], correct[20];
    int len, j = 0;
    int flag_error = 1;
    while (flag_error == 1) {
        getstr(answer);
        if (strncmp(answer, "exit", 4) == 0)
            return 2;
        check(answer, &flag_error);
    }
    refresh();
    attroff(A_BLINK);
    len = strlen(answer);
    while ((ch = getc(verb)) != '!') {
        printw("%c", ch);
        refresh();
    }
    y += 7;

    while ((ch = getc(verb)) != '\n') {
        correct[j] = ch - 4;
        printw("%c", correct[j]);
        refresh();
        j++;
    }
    refresh();
    if (strncmp(correct, answer, len) == 0) {
        *result = *result + 1;
        refresh();
    }
    printw("\t\t%d/10", *result);
    printw("\n\n");
    refresh();
    return 0;
}
int FillTable(int result)
{
    FILE* restab;
    char surname[100];
    printw("Result: %d/10\n\t\t\t\t\tEnter your surname: ", result);
    refresh();
    restab = fopen("result_table.txt", "a");
    getstr(surname);
    if (strncmp(surname, "exit", 4) == 0)
        return 2;
    refresh();
    fputs(surname, restab);
    fprintf(restab, " - %d\n", result);
    refresh();
    fclose(restab);
    return 0;
}
int read_file()
{
    echo();
    keypad(stdscr, false);
    int x = 5, y = 3;
    FILE* verb;
    int i, N = 0, A[10], result = 0;
    srand(time(NULL));
    verb = fopen("verbs.txt", "r");
    for (i = 0; i < 10; i++) {
        RandomQuestion(i, A, &N);
        rewind(verb);
        PrintQuestion(N, i, verb);
        if (WriteAndCheckAnswer(verb, &result, x, y) == 2)
            return 0;
    }
    fclose(verb);
    FillTable(result);
    return 0;
}