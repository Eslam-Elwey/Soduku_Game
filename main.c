#include "stdio.h"
#include "sudoku.h"


int main()
{
	u32 x_ind , y_ind , value ;
	return_status_t ret_val = done ;
	system("cls");
	cmdGoToXY(70,12);
	cmdSetConsoleColour(TEXT_Green);
	printf("************ Welcome TO Soduku Game ************");
	cmdGoToXY(70,15);
	cmdSetConsoleColour(TEXT_Green);
	printf("Loading*************");
	cmdDelay(10000);
	cmdResetConsoleColour();
	system("cls");
	while(1)
	{
		cmdResetConsoleColour();
		sudoku_print_puzzle();
		cmdGoToXY(5,12);
		cmdSetConsoleColour(TEXT_DYellow);
		printf("Enter Row_Posn & Col_Posn>>(from 1 to 9) : ");
		scanf ("%d%d",&x_ind,&y_ind);
		cmdGoToXY(5,16);
		printf("Enter value you want to enter>>(from 1 to 9) : ");
		scanf("%d",&value);
		ret_val = sudoku_set_blank_value(x_ind-1,y_ind-1,value) ;
		if (ret_val == done)
		{
			cmdGoToXY(5,22);
			cmdSetConsoleColour(TEXT_DYellow);
			printf("Your value (%d) has been entered in position",value);
			sudoku_print_puzzle();
		}
		else if (ret_val==value_over)
		{
			cmdGoToXY(5,22);
			cmdSetConsoleColour(TEXT_Pink);
			printf("Value has to be in range from 1 to 9");
		}
		else if (ret_val==repeated_row)
		{
			cmdGoToXY(5,22);
			cmdSetConsoleColour(TEXT_Pink);
			printf("value you entered is already exsisted in same row ");
		}
		else if (ret_val==repeated_col)
		{
			cmdGoToXY(5,22);
			cmdSetConsoleColour(TEXT_Pink);
			printf("value you entered is already exsisted in same column ");
		}
		else if (ret_val==base_index)
		{
			cmdGoToXY(5,22);
			cmdSetConsoleColour(TEXT_Pink);
			printf("You Can't change in Game Values!!Enter another index ");
		} 
		else {/* Nothing */}
		
		if (soduku_win_game()==1)
		{
			cmdSetConsoleColour(TEXT_Pink);
			cmdGoToXY(80,32);
			printf("********* Congratulations *********");
			cmdGoToXY(80,34);
			printf("********* You won *********");
			cmdDelay(5000);
			cmdGoToXY(80,36);
			printf("Press any key to exit ........");
			getch();
			exit (2) ;
		}
		cmdGoToXY(5,26);
		cmdSetConsoleColour(TEXT_DYellow);
		system("Pause");
		cmdClearScreen();
		cmdResetConsoleColour();
	}
	
	
	return 0 ;
}
