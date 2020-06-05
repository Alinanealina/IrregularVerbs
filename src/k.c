#include "k.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int random_question(
    int question_number, int asked_questions[], int* line_number)
{
    int flag_repeat,
        i; // flag_repeat - флаг для распознания повторяющихся вопросов
    int max_questions = 206;
    while (1) {
        flag_repeat = 0;
        *line_number = rand() % max_questions;
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
    return flag_repeat;
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

int check_command(char answer[20], int* flag_error)
{
    int max_lenght = 20, i;
    for (i = 0; i < strlen(answer); i++) {
        if (((answer[i] < 'a' || answer[i] > 'z') && answer[i] != ' ')
            || strlen(answer) > max_lenght) {
            attron(COLOR_PAIR(8));
            *flag_error = 1;
        } else {
            *flag_error = 0;
        }
    }
       return *flag_error; 
}

int check_answer(int result, char answer[], char correct[])
{
    int lenght_line = strlen(answer);
    if (strncmp(correct, answer, lenght_line) == 0) {
        result = result + 1;
        refresh();
    }
    return result;
}

void write_answer(FILE* verb, int quantity, char answer[], int result)
{
    int encoding = 4, i = 0;
    char correct[20], symbol;
    while ((symbol = getc(verb)) != '!') {
        printw("%c", symbol);
        refresh();
    }
    while ((symbol = getc(verb)) != '\n') {
        correct[i] = symbol - encoding;
        printw("%c", correct[i]);
        refresh();
        i++;
    }
    refresh();
    printw("\t\t%d/%d", check_answer(result, answer, correct), quantity);
    printw("\n\n");
    refresh();
}

int enter_answer(FILE* verb, int* result, int quantity)
{
    char  answer[20];
    int flag_error = 1; // flag_error - ошибка ввода

    while (flag_error == 1) {
        getstr(answer);
        if (strncmp(answer, "exit", 4) == 0) {
            return 2;
        }
        check_command(answer, &flag_error);
        if (flag_error == 1) {
            printw("Error comand. Enter again: ");
            refresh();
            attroff(COLOR_PAIR(8));
        }
    }
    refresh();
    write_answer( verb, quantity, answer, *result);
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

int check_quantity(int *quantity)
{
    int max_questions = 206, min_questions = 1;
    if (*quantity < min_questions || *quantity > max_questions) {
        return 1;
    }
    return 0;
}

int play_questions()
{
    echo();
    keypad(stdscr, false);
    FILE* verb;
    int* asked_questions;
    int question_number, line_number = 0, quantity, result = 0;
    srand(time(NULL));
    verb = fopen("verbs.txt", "r");
    int x = 5, y = 3;
    move(y, x);
    printw("Enter the number of questions (206 questions limit): ");
    refresh();
    scanw("%d", &quantity);
    refresh();
    clear();
    while( check_quantity(&quantity)) {
        move(y, x);
        attron(COLOR_PAIR(8));
        printw("Incorrect entry, drive correctly!: ");
        refresh();
        attroff(COLOR_PAIR(8));
        scanw("%d", &quantity);
        refresh();
        clear();
    }
    
    asked_questions = (int*)malloc(quantity * sizeof(int));
    for (question_number = 0; question_number < quantity; question_number++) {
        random_question(question_number, asked_questions, &line_number);
        rewind(verb);
        print_question(line_number, question_number, verb);
        if (enter_answer(verb, &result, quantity) == 2) {
            return 0;
        }
        getch();
        clear();
    }
    fclose(verb);
    fill_table(result);
    free(asked_questions);
    asked_questions = NULL;
    return 0;
}
