#include "cmd_Handler.h"

/*********************Function Prototypes******************************/
#define ROW_SIZE   9
#define COL_SIZE   9
#define BLANK_SPACE  38

/* defined_data_types */

typedef enum 
{
	repeated_row ,
	repeated_col ,
	base_index ,
	done,
	value_over
}return_status_t ;

/********************* FUNCTION_PROTOTYPE ******************************/

void sudoku_print_puzzle(void);

return_status_t sudoku_set_blank_value(u32 row_ind , u32 col_ind , u32 value) ;

u8 soduku_win_game (void);