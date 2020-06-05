#include "k.h"
#include <locale.h>
#include <ncurses.h> //подключаем библиотеку ncurses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void menu(int y, int x)
{
    move(y++, x);
    printw("|\\          /|\\");
    move(y++, x);
    printw("| \\        / | |");
    move(y++, x);
    printw("| |\\      / /| |   ________                          ___________");
    move(y++, x);
    printw("| | \\    / / | |  |\\_______\\   |\\       |\\   |\\"
           "     |\\_________|\\");
    move(y++, x);
    printw("| |  \\  / /  | |  | |          | |      | |  | |    | |        | "
           "|");
    move(y++, x);
    printw("| |   \\/ /   | |  | |          | |      | |  | |    | |        | "
           "|");
    move(y++, x);
    printw("| |    \\/    | |  |_|______    | |      | |  |_|____| |        | "
           "|");
    move(y++, x);
    printw("| |          | |  |\\_______\\   |_|______| |  |\\_____| |        "
           "| |");
    move(y++, x);
    printw("| |          | |  | |          |\\_______| |  | |    | |        | "
           "|");
    move(y++, x);
    printw("| |          | |  | |          | |      | |  | |    | |        | "
           "|");
    move(y++, x);
    printw("| |          | |  |_|______    | |      | |  | |    |_|________| "
           "|");
    move(y++, x);
    printw(" \\|           \\|   \\_______\\    \\|       \\|   \\|    "
           "\\___________\\|");
}

void play(int y, int x)
{
    move(y++, x);
    printw("               ___                         ___        __________   "
           "  _");
    move(y++, x);
    printw("|\\     |\\     |\\__\\       |\\     |\\       |\\__\\       "
           "\\___|\\ ___\\   | |");
    move(y++, x);
    printw("| |    | |    | |  \\      | |    | |      | |  \\          | |    "
           "   |_|______");
    move(y++, x);
    printw("|_|____| |    |_|___\\     | |____| |      |_|___\\         | |    "
           "   |\\ ______\\");
    move(y++, x);
    printw("|\\_____| |    |\\ ___ \\     \\|____| |      |\\ ___ \\        | "
           "|       | |      |\\");
    move(y++, x);
    printw("| |    | |    | |     \\          | |      | |     \\       | |    "
           "   |_|_____/\\/");
    move(y++, x);
    printw(" \\|     \\|     \\|      \\          \\|       \\|      \\       "
           "\\|        \\______\\/");
}

void help(int y, int x)
{
    move(y++, x);
    printw(" _________        ______                             ______        "
           "                       _");
    move(y++, x);
    printw("|\\______ |\\      /\\_____\\        |\\       /|\\       "
           "/\\_____\\      |\\   |\\   |\\           | |");
    move(y++, x);
    printw("| |      | |    |\\/      |\\      | \\     / | |     |\\/      "
           "|\\    | |  | |  | |          |_|______");
    move(y++, x);
    printw("| |      | |    | |      | |     | |\\   / /| |     | |      | |   "
           "| |  | |  | |          |\\ ______\\");
    move(y++, x);
    printw("| |      | |    | |      | |     | | \\ / / | |     | |      | |   "
           "| |  | |  | |          | |      |\\");
    move(y++, x);
    printw("| |      | |     \\|_____/\\/      | |  \\ /  | |      "
           "\\|_____/\\/    |_|__|_|__|_|___       |_|_____/\\/");
    move(y++, x);
    printw(" \\|       \\|      \\_____\\/        \\|        \\|       "
           "\\_____\\/      \\|___\\|___\\|___/      \\______\\/");
}

void Exit(int y, int x)
{
    move(y++, x);
    printw(" ____                                           ______       "
           "______");
    move(y++, x);
    printw("|\\ __\\         |\\          |\\    \\     /\\      /\\_____\\    "
           " |\\ _____\\");
    move(y++, x);
    printw("|_|__/_\\       |_|___      | |    \\   / /     |\\/      |\\   | "
           "|      \\");
    move(y++, x);
    printw("|\\______\\      |\\_____\\    | |     \\ / /      | |      | |  | "
           "|       \\");
    move(y++, x);
    printw("| |      |\\    | |     |\\  | |     / \\/       | |      | |  | | "
           "      /\\");
    move(y++, x);
    printw("|_|_____/\\/    |_|____/\\/  | |    / / \\        \\|_____/ \\/"
           "  |_|______/ /");
    move(y++, x);
    printw("\\_______\\/      \\_____\\/    \\|   /_/   \\        \\_____\\/"
           "     \\_______\\/");
}

void drow_all_menu(int x, int y)

{
    attroff(A_BLINK);
    y = 2;
    move(y, x);
    attron(A_BOLD);
    attron(COLOR_PAIR(50));
    menu(y, x);
    y += 20;

    attron(A_BOLD);
    move(y, x);
    attron(COLOR_PAIR(1));
    play(y, x);
    y += 15;

    move(y, x);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    help(y, x);
    y += 15;

    move(y, x);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    Exit(y, x);
    refresh();
}

int init_colors()
{
    init_pair(0, COLOR_CYAN, COLOR_CYAN);
    init_pair(1, COLOR_YELLOW, COLOR_CYAN);
    init_pair(54, COLOR_BLACK, COLOR_CYAN);
    init_pair(49, COLOR_CYAN, COLOR_MAGENTA);
    init_pair(3, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(50, COLOR_WHITE, COLOR_CYAN);
    init_pair(2, COLOR_GREEN, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_CYAN);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_RED, COLOR_CYAN);
    return 0;
}

void Helper()
{
    bkgd(COLOR_PAIR(10));
    refresh();
    FILE* Helper;
    char buffer;
    Helper = fopen("Helper.txt", "r");
    while ((buffer = getc(Helper)) != EOF) {
        printf("%c", buffer);
    }
    fclose(Helper);
}

int main()
{
    initscr();
    start_color();

    int x, y;
    int size_window = getmaxyx(stdscr, y, x);

    init_colors();

    x = size_window / 3 - 20;
    drow_all_menu(x, y);

    int location = 0, button;
    while (1) {
        bkgd(COLOR_PAIR(50));
        refresh();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
        clear();
        y = 22;
        drow_all_menu(x, y);
        button = getch();

        while ((button != 27) && (button != 10) && (y <= 52)
            && (button == 258)) {
            if ((y == 22)) {
                move(y, x);
                attron(A_BLINK);
                attron(COLOR_PAIR(49));
                play(y, x);
                refresh();
                button = getch();
                if (button == 10) {
                    location = 1;
                    break;
                }
                move(y, x);
                attroff(A_BLINK);
                attron(COLOR_PAIR(1));
                play(y, x);
                refresh();
            }

            if ((y == 37)) {
                move(y, x);
                attron(A_BLINK);
                attron(COLOR_PAIR(49));
                help(y, x);
                refresh();
                button = getch();
                if (button == 10) {
                    location = 2;
                    break;
                }
                move(y, x);
                attroff(A_BLINK);
                attron(COLOR_PAIR(1));
                help(y, x);
                refresh();
            }

            if ((y == 52)) {
                move(y, x);
                attron(A_BLINK);
                attron(COLOR_PAIR(49));
                Exit(y, x);
                refresh();
                button = getch();
                if (button == 10) {
                    endwin();
                    return 0;
                }
                move(y, x);
                attroff(A_BLINK);
                attron(COLOR_PAIR(1));
                Exit(y, x);
                refresh();
            }
            y += 15;
        }

        while ((button != 27) && (location != 0)) {
            switch (location) {
            case 1: {
                clear();
                refresh();
                echo();
                attroff(A_BLINK);
                attroff(A_BLINK);
                attron(COLOR_PAIR(50));
                play_questions();
                button = getch();
                break;
            }
            case 2: {
                clear();
                refresh();
                echo();
                attroff(A_BLINK);
                attron(COLOR_PAIR(50));
                Helper();
                refresh();
                button = getch();
                break;
            }
            }
            location = 0;
        }
    }
    endwin(); // завершение работы с ncurses
}
