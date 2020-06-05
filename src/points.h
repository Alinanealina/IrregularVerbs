#ifndef ADD_H
#define ADD_H
#include <locale.h>
#include <ncurses.h> //подключаем библиотеку ncurses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
extern char answer[20];
extern int *flag_error, question_number, asked_questions, *line_number, result, x, y, quantity;
extern FILE* verb;
int play_questions();
int random_question(
        int question_number, int asked_questions[], int* line_number);
void print_question(int line_number, int question_number, FILE* verb);
int check_command(char answer[20], int* flag_error);
int check_answer(int result, char answer[], char correct[]);
void write_answer(FILE* verb, int quantity, char answer[], int result);
int enter_answer(FILE* verb, int* result, int quantity);
int fill_table(int result, int quantity);
int check_quantity(int *quantity);
void helper();
#endif