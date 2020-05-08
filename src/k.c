#include "k.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int read_file() {
  echo();
  keypad(stdscr, false);
  int x = 5, y = 3;
  FILE *verb;
  char ch, answer[20];
  int i, N, A[10], j, k, l;
  srand(time(NULL));
  verb = fopen("verbs.txt", "r");
  for (i = 0; i < 3; i++) {
    ch = getc(verb);
    refresh();
  }
  for (i = 0; i < 10; i++) {
    move(y, x);
    while (1) {
      k = 0;
      N = rand() % 206;
      for (j = 0; j < i; j++) {
        if (A[j - 1] == N) {
          k = 1;
        }
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
      // move(y+2,x);
      if (ch != '#') {
        // move(y,x);
        printw("%c", ch);
        refresh();
      }
    }
    printw(" ");
    y += 2;
    refresh();
    getstr(answer);
    refresh();
    attroff(A_BLINK);
    // move(y+2,x+2);
    // printw("asfdf1");
    // refresh();
    while ((ch = getc(verb)) != '#') {
      // move(y,x+2);
      // printw("asfdf2");
      // refresh();
      move(y + 2, x + 2);
      printw("%c", ch);
      refresh();
    }
    y += 4;
  }
  fclose(verb);
  return 0;
}