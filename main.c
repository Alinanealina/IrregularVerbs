#include <curses.h> //подключаем библиотеку ncurses
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


void menu(int y, int x) {

    move(y++, x); printw("|\\          /|\\                                                                ");
    move(y++, x); printw("| \\        / | |                                                               ");
    move(y++, x); printw("| |\\      / /| |   ________                          ___________               ");
    move(y++, x); printw("| | \\    / / | |  |\\_______\\   |\\       |\\   |\\     |\\ ________|\\              ");
    move(y++, x); printw("| |  \\  / /  | |  | |          | |      | |  | |    | |        | |             ");
    move(y++, x); printw("| |   \\/ /   | |  | |          | |      | |  | |    | |        | |             ");
    move(y++, x); printw("| |    \\/    | |  |_|______    | |      | |  |_|____| |        | |             ");
    move(y++, x); printw("| |          | |  |\\_______\\   |_|______| |  |\\_____| |        | |           ");
    move(y++, x); printw("| |          | |  | |          |\\_______| |  | |    | |        | |              ");
    move(y++, x); printw("| |          | |  | |          | |      | |  | |    | |        | |              ");
    move(y++, x); printw("| |          | |  |_|______    | |      | |  | |    |_|________| |             ");
    move(y++, x); printw(" \\|           \\|   \\_______\\    \\|       \\|   \\|    \\___________\\|     ");
}

void play(int y, int x)
{
	move(y++, x); printw("               ___                         ___        __________     _            ");
    move(y++, x); printw("|\\     |\\     |\\__\\       |\\     |\\       |\\__\\       \\___|\\ ___\\   | |           ");
    move(y++, x); printw("| |    | |    | |  \\      | |    | |      | |  \\          | |       |_|______     ");
    move(y++, x); printw("|_|____| |    |_|___\\     | |____| |      |_|___\\         | |       |\\ ______\\    ");
    move(y++, x); printw("|\\_____| |    |\\ ___ \\     \\|____| |      |\\ ___ \\        | |       | |      |\\   ");
    move(y++, x); printw("| |    | |    | |     \\          | |      | |     \\       | |       |_|_____/\\/   ");
    move(y++, x); printw(" \\|     \\|     \\|      \\          \\|       \\|      \\       \\|        \\______\\/    ");
 
}

void help(int y, int x)
{
	move(y++, x); printw(" _________        ______                             ______                               _              ");
    move(y++, x); printw("|\\______ |\\      /\\_____\\        |\\       /|\\       /\\_____\\      |\\   |\\   |\\           | |             ");
    move(y++, x); printw("| |      | |    |\\/      |\\      | \\     / | |     |\\/      |\\    | |  | |  | |          |_|______       ");
    move(y++, x); printw("| |      | |    | |      | |     | |\\   / /| |     | |      | |   | |  | |  | |          |\\ ______\\      ");
    move(y++, x); printw("| |      | |    | |      | |     | | \\ / / | |     | |      | |   | |  | |  | |          | |      |\\     ");
    move(y++, x); printw("| |      | |     \\|_____/\\/      | |  \\ /  | |      \\|_____/\\/    |_|__|_|__|_|___       |_|_____/\\/     ");
    move(y++, x); printw(" \\|       \\|      \\_____\\/        \\|        \\|       \\_____\\/      \\|___\\|___\\|___/      \\______\\/       ");
  
}


void Exit(int y, int x)
{
	
    move(y++, x); printw(" ____                                           ______       ______          ");
    move(y++, x); printw("|\\ __\\         |\\          |\\    \\     /\\      /\\_____\\     |\\ _____\\        ");
    move(y++, x); printw("|_|__/_\\       |_|___      | |    \\   / /     |\\/      |\\   | |      \\       ");
    move(y++, x); printw("|\\______\\      |\\_____\\    | |     \\ / /      | |      | |  | |       \\      ");
    move(y++, x); printw("| |      |\\    | |     |\\  | |     / \\/       | |      | |  | |       /\\     ");
    move(y++, x); printw("|_|_____/\\/    |_|____/\\/  | |    / / \\        \\|_____/\\/   |_|______/ /     ");
    move(y++, x); printw("\\_______\\/      \\_____\\/    \\|   /_/   \\        \\_____\\/     \\_______\\/      ");
 
}

void drow(int x, int y)

{
	attroff ( A_BLINK );
	y = 2;
	move(y,x);
	attron(A_BOLD);
	attron(COLOR_PAIR(50));
	menu( y,  x);
	y+=20;
	
	attron(A_BOLD);
	move(y,x);
	attron(COLOR_PAIR(1));
	play( y,  x);
	y+=15;

	move(y,x);
	attron(A_BOLD);
	attron(COLOR_PAIR(1));
	help( y,  x);
	y+=15;

	move(y,x);
	attron(A_BOLD);
	attron(COLOR_PAIR(1));
	Exit( y,  x);
	refresh();

}

void init_col()
{
	init_pair(1,  COLOR_YELLOW, COLOR_CYAN);
    init_pair(54, COLOR_BLACK,  COLOR_CYAN);
    init_pair(49,COLOR_CYAN, COLOR_MAGENTA);
    init_pair(3,COLOR_WHITE, COLOR_MAGENTA);
    init_pair(50, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_GREEN, COLOR_YELLOW);
}

int main()
{
	initscr();
	start_color();
	
	int x , y;
	int size = getmaxyx(stdscr,y,x);
	bkgd (COLOR_PAIR(50));

	init_col();
	if (!has_colors())
	{
	  endwin();
	  printw("Цвета не поддерживаются");
	  exit(1);
	}
	x = size/3-20;
	drow( x, y);

	// move(20,x);
	// attron(A_BOLD);
	// attron(COLOR_PAIR(1));
	// printw("Нажите любую клавишу чтобы начать");
	// refresh();
 // 	int key = getch();
 // 	printw("key = %d",key);
	// refresh();
	int f = 0, key;
	while (1)
	{
        noecho();
		curs_set(0);
		keypad(stdscr, TRUE);
        clear();
        y = 22;
        drow( x, y);
        key = getch();  
			
        while((key !=27)&&(key !=10)&&(y<=52)&&(key==258)) 
        {	
        	if( (y == 22) )
        	{
        		
        		move(y,x);
        		attron(A_BLINK );
				attron(COLOR_PAIR(49));
				play( y,  x);
				refresh(); 
				key=getch();
				if (key == 10)
				{
					f = 1;
					break;
				}
				// sleep(1);
				move(y,x);
				attroff ( A_BLINK );
				attron(COLOR_PAIR(1));
				play( y,  x);
				refresh(); 
        	}
        	if( (y == 37) )
        	{
        		move(y,x);
        		attron(A_BLINK );
				attron(COLOR_PAIR(49));
				help( y,  x);
				refresh(); 
				key=getch();
				if (key == 10)
				{
					f = 2;
					break;
				}
				move(y,x);
        		attroff ( A_BLINK );
				attron(COLOR_PAIR(1));
				help( y,  x);
				refresh(); 
        	}
        	if( (y == 52) )
        	{
				move(y,x);
        		attron(A_BLINK );
				attron(COLOR_PAIR(49));
				Exit( y,  x);
				refresh(); 
				key=getch();
				if (key == 10)
				{
					endwin();
					return 0;
				}
				move(y,x);
        		attroff ( A_BLINK );
				attron(COLOR_PAIR(1));
				Exit( y,  x);
				refresh(); 
       		}
       		y+=15; 
        }
        while((key !=27)&&(f!=0)) 
        {
			// clear();
		 //    move(20,size/2 );
			// printw("f = %d",f);
			// refresh();
			// getch();
			switch(f)
		    {
		    	case 1: 
		    	{	
			    	clear();
			    	refresh(); 
                    move(20,size/2 );
			    	printw ("Play");
			    	refresh(); 
			    	key = getch();
		    		break;
		    	}
		    	case 2:
		    	{
			    	clear();
			    	move(20,size/2 );
			    	printw ("Help");
			    	refresh(); 
			    	key = getch();
			    	break;
		    	} 
		    	
		    }
        f =0; 
        }	
    }

	// getch(); // ждём нажатия символа
	  
	endwin(); // завершение работы с ncurses
}
//echo() отменяет действие noecho().
