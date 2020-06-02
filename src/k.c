#include "k.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void random_question(
        int question_number, int asked_questions[], int* line_number)
{
    int flag_repeat,
            i; // flag_repeat - флаг для распознания повторяющихся вопросов
    while (1) {
        flag_repeat = 0;
        *line_number = rand() % 206;
        for (i = 0; i < question_number; i++) {
            if (asked_questions[i] == *line_number) {
                flag_repeat = 1;
            }
        }
        if (flag_repeat != 1) {
            asked_questions[question_number] = *line_number;
            break;
        }
    }
}

void print_question(int line_number, int question_number, FILE* verb)
{
    int i;
    char symbol;
    for (i = 0; i < line_number; i++) {
        while (symbol != '\n') {
            symbol = getc(verb);
            refresh();
        }
        symbol = getc(verb);
        refresh();
    }
    printw(" %d. ", question_number + 1);
    refresh();
    while ((symbol = getc(verb)) != '*') {
        if (symbol != '#') {
            printw("%c", symbol);
        }
        refresh();
    }
    printw(" ");
    refresh();
}

int write_and_check_answer(FILE* verb, int* result, int x, int y)
{
    char symbol, answer[20], correct[20];
    int lenght_line, i = 0;
    int flag_error = 1;

    while (flag_error == 1) {
        getstr(answer);
        if (strncmp(answer, "exit", 4) == 0) {
            return 2;
        }
        check(answer, &flag_error);
    }
    refresh();

    while ((symbol = getc(verb)) != '!') {
        printw("%c", symbol);
        refresh();
    }

    y += 7;

    while ((symbol = getc(verb)) != '\n') {
        correct[i] = symbol - 4;
        printw("%c", correct[i]);
        refresh();
        i++;
    }
    refresh();

    lenght_line = strlen(answer);
    if (strncmp(correct, answer, lenght_line) == 0) {
        *result = *result + 1;
        refresh();
    }
    printw("\t\t%d/10", *result);
    printw("\n\n");
    refresh();
    return 0;
}

int fill_table(int result)
{
    FILE* result_table;
    char surname[100];
    printw("Result: %d/10\n\t\t\t\t\tEnter your surname: ", result);
    refresh();
    result_table = fopen("result_table.txt", "a");
    getstr(surname);
    if (strncmp(surname, "exit", 4) == 0) {
        return 2;
    }
    refresh();
    fputs(surname, result_table);
    fprintf(result_table, " - %d\n", result);
    refresh();
    fclose(result_table);
    return 0;
}

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
        } else {
            *flag_error = 0;
        }
    }
}

int read_file()
{
    echo();
    keypad(stdscr, false);
    int x = 5, y = 3;
    FILE* verb;
    int question_number, line_number = 0, asked_questions[10], result = 0;
    srand(time(NULL));
    verb = fopen("verbs.txt", "r");
    for (question_number = 0; question_number < 10; question_number++) {
        random_question(question_number, asked_questions, &line_number);
        rewind(verb);
        print_question(line_number, question_number, verb);
        if (write_and_check_answer(verb, &result, x, y) == 2)
            return 0;
    }
    fclose(verb);
    fill_table(result);
    return 0;
}
