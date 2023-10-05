#include "sudoku.h"

u8 sudoku[ROW_SIZE][COL_SIZE] = 
	{
		{8,0,0,4,0,0,1,0,7},	
		{0,1,3,8,6,7,0,4,9},	
		{4,7,0,5,0,3,2,6,0},	
		{0,2,0,0,5,0,9,8,1},	
		{0,6,8,9,0,0,0,0,3},	
		{7,0,1,3,4,0,0,2,0},	
		{6,0,0,0,7,0,3,0,4},	
		{1,0,7,0,0,9,0,0,6},	
		{0,3,0,0,8,0,0,1,2},	
	};
	
u8 data_index[BLANK_SPACE][2]=
{
	{0,1},{0,2},{0,4},{0,5},{0,7},{1,0},{1,6},{2,2},{2,4},{2,8},{3,0},{3,2},{3,3},{3,5},{4,0},{4,4},
	{4,5},{4,6},{4,7},{5,1},{5,5},{5,6},{5,8},{6,1},{6,2},{6,3},{6,5},{6,7},{7,1},{7,3},{7,4},
	{7,6},{7,7},{8,0},{8,2},{8,3},{8,5},{8,6}
};	 

 
/* 
//Solution
u8 sudoku[ROW_SIZE][COL_SIZE] = 
	{
		{8,5,6,4,9,2,1,3,7},	
		{2,1,3,8,6,7,5,4,9},	
		{4,7,9,5,1,3,2,6,8},	
		{3,2,4,7,5,6,9,8,1},	
		{5,6,8,9,2,1,4,7,3},	
		{7,9,1,3,4,8,6,2,5},	
		{6,8,2,1,7,5,3,9,4},	
		{1,4,7,2,3,9,8,5,6},	
		{9,3,5,6,8,4,7,1,2},	
	};  */


static u8 check_blink_colour (u8 x , u8 y)
{
	u8 i , j=0 ;
	for (i=0;i<37;i++)
	{
		if ((data_index[i][j]==x)&&(data_index[i][j+1]==y))
		{
			return 1 ; 
		}
	}
	return 0 ;
}

void sudoku_print_puzzle(void)
{
	u8 i , j , y =0 ;
	
	cmdSetConsoleColour(TEXT_Green);
	cmdGoToXY(80,10+y);
	printf("_____________________________________\n");
	cmdResetConsoleColour();
	y++;
	for (i=0;i<ROW_SIZE;i++)
	{
		cmdGoToXY(80,10+y);
		cmdSetConsoleColour(TEXT_Green);
		printf("| ");
		cmdResetConsoleColour();
		for (j=0;j<COL_SIZE;j++)
		{
			if (sudoku[i][j]==0)
			{
				printf("  ");
				
			}
			else if (check_blink_colour(i,j)==1)
			{
				cmdSetConsoleColour(TEXT_Pink);
				printf("%d ",sudoku[i][j]);
			}
			else 
			{
				cmdSetConsoleColour(TEXT_DWhite);
				printf("%d ",sudoku[i][j]);
			}
			cmdSetConsoleColour(TEXT_Green);
			printf("| ");
			cmdResetConsoleColour();
		}
		printf("\n");
		cmdSetConsoleColour(TEXT_Green);
		y++;
		cmdGoToXY(80,10+y);
		printf("_____________________________________");
		cmdResetConsoleColour();
		y++;
	}
}	

static u8 sudoku_is_repeated_same_row(u32 row_ind ,u32 col_ind, u32 value)
{
	u8 i ; 
	for (i=0;i<COL_SIZE;i++)
	{
		if ((sudoku[row_ind][i]==value)&&(i!=col_ind))
		{
			return 1 ; 
		}
	}
	return 0 ; 
}

static u8 sudoku_is_repeated_same_col(u32 row_ind ,u32 col_ind, u32 value)
{
	u8 i ; 
	for (i=0;i<ROW_SIZE;i++)
	{
		if ((sudoku[i][col_ind]==value)&&( i!= row_ind ))
		{
			return 1 ; 
		}
	}
	return 0 ;
}

static u8 sudoku_is_blank_one (u32 row_ind , u32 col_ind)
{
	u8 i , j=0 ;
	for (i=0;i<BLANK_SPACE;i++)
	{
		if ((data_index[i][j]==row_ind)&&(data_index[i][j+1]==col_ind))
		{
			return 1 ; 
		}
	}
	return 0 ;
}

return_status_t sudoku_set_blank_value(u32 row_ind , u32 col_ind , u32 value )
{
	if ((value>9)||(value<1))
	{
		return value_over ; 
	}
	if (sudoku_is_blank_one(row_ind,col_ind)==0)
	{
		return base_index;
	}
	if (sudoku_is_repeated_same_row(row_ind,col_ind,value)==1)
	{
		return repeated_row ;
	}
	if (sudoku_is_repeated_same_col(row_ind,col_ind,value)==1)
	{
		return repeated_col ;
	}
	
	sudoku[row_ind][col_ind] = value ; 
	
	return done ;
	
}

u8 soduku_win_game (void )
{
	u8 i , j ;
	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
		{
			if (sudoku[i][j]==0)
			{
				return 0 ;
			}
			if (sudoku_is_repeated_same_row(i,j,sudoku[i][j])||
				sudoku_is_repeated_same_col(i,j,sudoku[i][j]))
			{
				return 0;
			}
		}
	}
	return 1 ;
}