#include "points.h"
#include <locale.h>
#include <ncurses.h> //подключаем библиотеку ncurses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void drow_all_menu(int x, int y)

{
  attroff(A_BLINK);
  y = 2;
  move(y, x);
  attron(A_BOLD);
  attron(COLOR_PAIR(50));
  printw("Menu");
  y++;

  attron(A_BOLD);
  move(y, x);
  attron(COLOR_PAIR(1));
  printw("Play");
  y++;

  move(y, x);
  attron(A_BOLD);
  attron(COLOR_PAIR(1));
  printw("Help");
  y++;

  move(y, x);
  attron(A_BOLD);
  attron(COLOR_PAIR(1));
  printw("Exit");
  refresh();
}

int init_colors() {
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

int main() {
  initscr();
  start_color();

  int x, y;
  int size_window = getmaxyx(stdscr, y, x);

  init_colors();

  x = size_window / 2;
  drow_all_menu(x, y);

  int location = 0, button;
  while (1) {
    bkgd(COLOR_PAIR(50));
    refresh();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    clear();
    y = 3;
    drow_all_menu(x, y);
    button = getch();

    while ((button != 27) && (button != 10) && (y <= 52) && (button == 258)) {
      if ((y == 3)) {
        move(y, x);
        attron(A_BLINK);
        attron(COLOR_PAIR(49));
        printw("Play");
        refresh();
        button = getch();
        if (button == 10) {
          location = 1;
          break;
        }
        move(y, x);
        attroff(A_BLINK);
        attron(COLOR_PAIR(1));
        printw("Play");
        refresh();
        y++;
      }

      if ((y == 4)) {
        move(y, x);
        attron(A_BLINK);
        attron(COLOR_PAIR(49));
        printw("Help");
        refresh();
        button = getch();
        if (button == 10) {
          location = 2;
          break;
        }
        move(y, x);
        attroff(A_BLINK);
        attron(COLOR_PAIR(1));
        printw("Help");
        refresh();
        y++;
      }

      if ((y == 5)) {
        move(y, x);
        attron(A_BLINK);
        attron(COLOR_PAIR(49));
        printw("Exit");
        refresh();
        button = getch();
        if (button == 10) {
          endwin();
          return 0;
        }
        move(y, x);
        attroff(A_BLINK);
        attron(COLOR_PAIR(1));
        printw("Exit");
        refresh();
        y++;
      }
      y++;
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
        helper();
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
