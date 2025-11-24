#include<stdio.h>

int displayGrid(char* grid[]) {

	for (int i = 0; i < 9; i++) {
		if (*grid[i] == 'X') printf("  \033[1;31mX\033[0m  ");
		else if (*grid[i] == 'O') printf("  \033[1;34mO\033[0m  ");
		else printf("  %c  ", *grid[i]);

		if ((i + 1) % 3 == 0) printf("\n\n");
	}
}


int endCondition(char grid[]){
    //checks the end conditions for the game
    if(grid[0] == grid[1] && grid[1] == grid[2]){
        return 1;
    }
    else if(grid[3] ==  grid[4] && grid[4] == grid[5]){
            return 1;
        }
    else if(grid[6] == grid[7] && grid[7] == grid[8]){
            return 1;
        }
    else if(grid[0] == grid[3] && grid[3] == grid[6]){
            return 1;
        }
    
    else if(grid[1] == grid[4] && grid[4] == grid[7]){
            return 1;
        }
    
    else if(grid[2] == grid[5] && grid[5] == grid[8]){
            return 1;
        }
    
        
    else if(grid[0] == grid[4] && grid[4] == grid[8]){
            return 1;
        }

        
    else if(grid[2] == grid[4] && grid[4] == grid[6]){
            return 1;
    }
    else if (grid[0] != '1' && grid[1] != '2' && grid[2] != '3' &&
         grid[3] != '4' && grid[4] != '5' && grid[5] != '6' &&
         grid[6] != '7' && grid[7] != '8' && grid[8] != '9') {
    return 2;
    }
    else{
        return 0;
    }
}

void playerTurn(char playerSymbol, char* playerName, char* grid[]) {
	int gridLocation;

	printf("\033[1;34m%s\033[0m's turn, Choose a location:\n\n", playerName);
	displayGrid(grid);
	scanf("%d", &gridLocation);
	gridLocation--;

	// range validation
	if (gridLocation < 0 || gridLocation > 8) {
		printf("Invalid input! Try again.\n");
		return playerTurn(playerSymbol, playerName, grid);
	}

	// position occupied check
	if (*grid[gridLocation] == 'X' || *grid[gridLocation] == 'O') {
		printf("Spot taken! Please choose another location.\n");
		return playerTurn(playerSymbol, playerName, grid);
	}

	*grid[gridLocation] = playerSymbol;
}


int main() {
	// beginning of main function

	// initializing variables
	char grid[9] = { '1','2','3','4','5','6','7','8','9' };
	char p1[10], p2[10];
	int rematch = 1;

	// making a pointer array for grid
	char* gridpoint[9];
	for (int i = 0; i < 9; i++) {
		gridpoint[i] = &grid[i];
	}

	// start of game logic
	printf("Enter name of player 1: ");
	scanf("%s", p1);
	printf("Enter name of player 2: ");
	scanf("%s", p2);

	printf("player 1: \033[1;31m%s\033[0m \n", p1);
	printf("player 2: \033[1;34m%s\033[0m \n", p2);

	int lastplayer = 1;

	while (rematch) {
		while (1) {
			playerTurn('X', p1, gridpoint);
			if (endCondition(grid)) { lastplayer = 1; break; }

			playerTurn('O', p2, gridpoint);
			if (endCondition(grid)) { lastplayer = 2; break; }
		}

		if (endCondition(grid) == 2) {
			printf("The game is a draw! \n");
			displayGrid(gridpoint);
		}
		else if (lastplayer == 1) {
			printf("\033[1;31m%s\033[0m wins! \n", p1);
			displayGrid(gridpoint);
		}
		else if (lastplayer == 2) {
			printf("\033[1;34m%s\033[0m wins! \n", p2);
			displayGrid(gridpoint);
		}

		while (1) {
			char choice;

			printf("Rematch? y/n\n");
			scanf(" %c", &choice);

			if (choice == 'n' || choice == 'N') {
				printf("Thanks for playing!\n");
				rematch = 0;
				break;
			}
			else if (choice == 'y' || choice == 'Y') {
				printf("\033[1;31m%s\033[0m vs \033[1;34m%s\033[0m \n", p1, p2);

				// Reset grid
				for (int i = 0; i < 9; i++) {
					grid[i] = '1' + i;
				}

				break;
			}
			else {
				printf("Invalid input. Please enter 'y' or 'n'.\n");
			}
		}
	}
}