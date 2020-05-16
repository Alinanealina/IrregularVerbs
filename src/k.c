#include <ncurses.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include "k.h"

int read_file ()
{
    echo();
    keypad(stdscr, false);
    int x = 5, y = 3;
    FILE *verb, *restab;
    char ch, answer[20], correct[20], surname[20];
    int i, N, A[10], j, k, l, result=0, len;
    srand(time(NULL));
    verb=fopen("verbs.txt","r");
    for (i=0;i<10;i++)
    {
        while (1)
        {
            k=0;
            N=rand()%206;
            for (j=0;j<i;j++)
            {
                if (A[j]==N)
                    k=1;
            }
            if (k!=1)
            {
                A[i]=N;
                break;
            }
        }
        rewind(verb);
        for (l=0;l<N;l++)
        {
            while (ch!='\n')
            {
                ch=getc(verb);
                refresh(); 
            }
            ch=getc(verb);
            refresh(); 
        }
        printw(" %d. ", i+1);
        refresh(); 
        while ((ch=getc(verb))!='*')
        {
            if (ch!='#')
                printw("%c", ch);
                refresh(); 
        }
        printw(" ");
        refresh(); 
        getstr(answer);        
        refresh(); 
        attroff(A_BLINK );
        len=strlen(answer);
        while ((ch=getc(verb))!='!')
        {

            printw("%c", ch);
            refresh();
        }
        j=0;
        while ((ch=getc(verb))!='\n')
        {
            correct[j]=ch;
            j++;
            move(y,x);
            printw("%c", ch);
            refresh(); 
        }
        y+=4;
        if (j==len)
        {
            if (strncmp(correct,answer,j)==0)
                result++;
        }
        printw("\t\t%d/10", result);
        printw("\n\n");
        refresh(); 
    }
    fclose(verb);
    return 0;
}
