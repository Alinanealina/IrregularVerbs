#define CTEST_MAIN
#include "k.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctest.h>

CTEST(random_question, uniqueness_question)
{
    int asked_questions[5], line_number, i;
    for (i = 0; i < 5; i++) {
        asked_questions[i] = 0;
    }
    asked_questions[0] = 1;
    asked_questions[1] = 2;
    asked_questions[2] = 3;
    line_number = 1;
    int result = random_question(4, 
    	asked_questions, &line_number);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_answer, result_great)
{
	char answer[20], correct[20];
	int results = 2;
	strcpy(answer, "was");
	strcpy(correct, "was");
    int result = check_answer(results, answer, correct);
    int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_answer, result_error)
{
	char answer[20], correct[20];
	int results = 2;
	strcpy(answer, "was");
	strcpy(correct, "be");
    int result = check_answer(results, answer, correct);
    int expected = 2;
    ASSERT_EQUAL(expected, result);
}


CTEST(check_command, error_enter)
{
    char answer[20];
    int flag_error = 1;
    strcpy(answer,"1E");
    int result = check_command(answer, &flag_error);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_command, great_enter)
{
    char answer[20];
    int flag_error = 0;
    strcpy(answer,"was");
    int result = check_command(answer, &flag_error);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_quantity, great_intput)
{
    int  quantity = 10;
    int result = check_quantity(&quantity);
	int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_quantity, error_intput)
{
    int  quantity = 1000;
    int result = check_quantity(&quantity);
	int expected = 1;
    ASSERT_EQUAL(expected, result);
}


// CTEST(init_colors, have_color)
// {
//     int result = init_colors();
// 	int expected = 0;
//     ASSERT_EQUAL(expected, result);
// }



int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
