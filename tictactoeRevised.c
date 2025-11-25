#include<stdio.h>

int displayGrid(char* grid) {
	//This function displays the tictactoe grid
	for (int i = 0; i < 9; i++) {
		printf("  %c  ", grid[i]);
		if ((i + 1) % 3 == 0) printf("\n\n");
	}
}


int endCondition(char grid[]){
    //checks the end conditions for the game
    if(grid[0] == grid[1] && grid[1] == grid[2]) return 1;
    else if(grid[3] ==  grid[4] && grid[4] == grid[5]) return 1;
    else if(grid[6] == grid[7] && grid[7] == grid[8]) return 1;
    else if(grid[0] == grid[3] && grid[3] == grid[6]) return 1;
    else if(grid[1] == grid[4] && grid[4] == grid[7]) return 1;
    else if(grid[2] == grid[5] && grid[5] == grid[8]) return 1;
    else if(grid[0] == grid[4] && grid[4] == grid[8]) return 1;
    else if(grid[2] == grid[4] && grid[4] == grid[6]) return 1;

    else if (grid[0] != '1' && grid[1] != '2' && grid[2] != '3' &&
         grid[3] != '4' && grid[4] != '5' && grid[5] != '6' &&
         grid[6] != '7' && grid[7] != '8' && grid[8] != '9')
    return 2;

    else{
        return 0;
    }
}

void playerTurn(int player, char* playerName, char* grid) {
	
	int gridLocation;
	char playerSymbol;

	if(player==1) {playerSymbol='X';} 
	else {playerSymbol='O';} 

	printf("%s, Choose a location:\n\n", playerName);
	displayGrid(grid);
	scanf("%d", &gridLocation);
	gridLocation--;

	// range validation
	if (gridLocation < 0 || gridLocation > 8) {
		printf("Invalid input! Try again.\n");
		return playerTurn(player, playerName, grid);
	}

	// position occupied check
	if (grid[gridLocation] == 'X' || grid[gridLocation] == 'O') {
		printf("Spot taken! Please choose another location.\n");
		return playerTurn(player, playerName, grid);
	}

	grid[gridLocation] = playerSymbol;
}
void displayScore(int* winCount, char* p1, char* p2){
			//This function prints the score of the players
			printf("Score: \n");
			printf("%s: %d\n",p1,winCount[0]);
			printf("%s: %d\n",p2,winCount[1]);


}

int main() {
	// beginning of main function

	// initializing variables
	char grid[9] = { '1','2','3','4','5','6','7','8','9' };
	char p1[10], p2[10];
	int rematch = 1;
	int winCount[2]={0,0};

	// start of game logic
	printf("Enter name of player 1: ");
	scanf("%s", p1);
	printf("Enter name of player 2: ");
	scanf("%s", p2);

	printf("player 1: %s \n", p1);
	printf("player 2: %s \n", p2);

	int lastplayer = 1;

	while (rematch) {
		while (1) {
			playerTurn(1, p1, grid);
			if (endCondition(grid)) { lastplayer = 1; break; }

			playerTurn(2, p2, grid);
			if (endCondition(grid)) { lastplayer = 2; break; }
		}
		if (endCondition(grid) == 2) {
			printf("The game is a draw! \n");
			displayGrid(grid);
		}
		else if (lastplayer == 1) {
			printf("%s wins! \n", p1);
			displayGrid(grid);
			winCount[0]++;
			displayScore(winCount,p1,p2);
		}
		else if (lastplayer == 2) {
			printf("%s \n", p2);
			displayGrid(grid);
			winCount[1]++;
			displayScore(winCount,p1,p2);
		}

		while (1) {
			char choice;

			printf("Rematch? y/n\n");
			scanf(" %c", &choice);

			if (choice == 'n' || choice == 'N') {
				printf("Thanks for playing!\n");
				displayScore(winCount,p1,p2);
				rematch = 0;
				break;
			}
			else if (choice == 'y' || choice == 'Y') {
				printf("%s  vs %s \n", p1, p2);

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