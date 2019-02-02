#include <stdio.h>

#define FALSE 0
#define TRUE 1

#define NROWS 15
#define MCOLS 25

// Symbols:
// '-' = open
// '#' = blocked
// 'S' = start
// 'G' = goal
// '+' = path
// 'x' = bad path
char maze[NROWS][MCOLS] = {
	"#########################",
	"#-----------------------#",
	"#-#####################-#",
	"#-#-------------------#-#",
	"#-#-#####################",
	"#-#---------#-------#---G",
	"###-#-###############-###",
	"#---#-#-----------#---#-#",
	"#-#-#-#############-#-#-#",
	"#-#-----------------#-#-#",
	"#-###################-#-#",
	"S-#---------------------#",
	"#-#######################",
	"#-----------------------#",
	"#########################",
	};


void display_maze(void);
int find_path(int x, int y);


int
main(void)	
{
	display_maze();		//to display the demo maze 

	if ( find_path(0, 11) == TRUE )		// when from starting point can find the goal
		printf("Success!\n");		// output success
	else					// if not
		printf("Failed\n");		// output no

	display_maze();				// success = display the correct path from starting to the goal ; fail = display back the basic maze

	return 0;
}
// main()


void
display_maze(void)
{
	int i;

	printf("MAZE:\n");
	for ( i = 0; i < NROWS; i++ )
		printf("%.*s\n", MCOLS, maze[i]);
	printf("\n");

	return;
}


int
find_path(int x, int y)
{
	// If x,y is outside maze, return false.
	if ( x < 0 || x > MCOLS - 1 || y < 0 || y > NROWS - 1 ) return FALSE;	//based on location

	// If x,y is the goal, return true.
	if ( maze[y][x] == 'G' ) return TRUE;

	// If x,y is not open, return false.
	if ( maze[y][x] != '-' && maze[y][x] != 'S' ) return FALSE;

	// Mark x,y part of solution path.
	maze[y][x] = '+';

	// If find_path North of x,y is true, return true.
	if ( find_path(x, y - 1) == TRUE ) return TRUE;

	// If find_path East of x,y is true, return true.
	if ( find_path(x + 1, y) == TRUE ) return TRUE;

	// If find_path South of x,y is true, return true.
	if ( find_path(x, y + 1) == TRUE ) return TRUE;

	// If find_path West of x,y is true, return true.
	if ( find_path(x - 1, y) == TRUE ) return TRUE;

	// Unmark x,y as part of solution path.
	maze[y][x] = 'x';

	return FALSE;
}
// find_path()

