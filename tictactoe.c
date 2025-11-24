#include<stdio.h>


void displayGrid(char grid[]){
    //displays the tictactoe grid
    for (int i=0; i < 9; ++i){
        if (grid[i] == 'X')
        {
            printf("  \033[1;31mX\033[0m  ");
        }
        else if (grid[i] == 'O')
        {
            printf("  \033[1;34mO\033[0m  ");
        }
        
        else{
            printf("  %c  ", grid[i]);
        }

        if ((i+1)%3 == 0){
            printf("\n\n");

        }
    }

}

int winCondition(char grid[]){
    //checks the end conditions for the game
    if(grid[0] == grid[1] && grid[1] == grid[2]){
        return 0;
    }
    else if(grid[3]==  grid[4] && grid[4] == grid[5]){
            return 0;
        }
    else if(grid[6]== grid[7] && grid[7] == grid[8]){
            return 0;
        }
    else if(grid[0]== grid[3] && grid[3] == grid[6]){
            return 0;
        }
    
    else if(grid[1]== grid[4] && grid[4] == grid[7]){
            return 0;
        }
    
    else if(grid[2]== grid[5] && grid[5] == grid[8]){
            return 0;
        }
    
        
    else if(grid[0]== grid[4] && grid[4] == grid[8]){
            return 0;
        }

        
    else if(grid[2]== grid[4] && grid[4] == grid[6]){
            return 0;
    }
    else if (grid[0] != '1' && grid[1] != '2' && grid[2] != '3' &&
         grid[3] != '4' && grid[4] != '5' && grid[5] != '6' &&
         grid[6] != '7' && grid[7] != '8' && grid[8] != '9') {
    return 0;
    }
    else{
        return 1;
    }
}


int main(){
    //beginning of main function

    //initialising variables
    int gameIsRunning = 1;
    char grid[9] = {'1','2','3','4','5','6','7','8','9'};
    char p1[10], p2[10];
    int gridLocation;
    char rematch;

    //making a pointer array for grid
    char* gridpoint[9];
    for(int i=0; i<9;i++){
        gridpoint[i]=&grid[i];
    }
    //start of game logic
    printf("Enter name of player 1: ");
    fgets(p1, sizeof(p1), stdin);
    printf("Enter name of player 2: ");
    fgets(p2, sizeof(p2), stdin);
    size_t len = strlen(p1);
        if (len > 0 && p1[len - 1] == '\n') {
            p1[len - 1] = '\0';
        }
    len = strlen(p2);
        if (len > 0 && p2[len - 1] == '\n') {
            p2[len - 1] = '\0';
        }
    printf("player 1: \033[1;31m%s\033[0m \n", p1);
    printf("player 2: \033[1;34m%s\033[0m \n", p2);
    int currentPlayer = 1;

    //start of loop
    
    while (1){
        while (gameIsRunning){
        if (currentPlayer == 1){
            printf("\033[1;31m%s\033[0m's turn, Choose a location \n \n", p1);
            displayGrid(grid);
            scanf("%d", &gridLocation);
            gridLocation--;
            if (grid[gridLocation] == 'X' || grid[gridLocation] == 'O'){
                printf("please enter a valid location \n");
                continue;
            }
            else if (gridLocation > 9 || gridLocation < 0) {
                printf("please enter a valid location \n");
                continue;
            }
            else{
                grid[gridLocation] = 'X';
                gameIsRunning = winCondition(grid);
                
                if (!gameIsRunning)
                {
                    break;
                }
                    
                currentPlayer=2;
                   
            }  
            
        }
        if (currentPlayer == 2){
            printf("\033[1;34m%s\033[0m's turn, Choose a location \n \n", p2);
            displayGrid(grid);
            scanf("%d", &gridLocation);
            gridLocation--;
            if (grid[gridLocation] == 'X' || grid[gridLocation] == 'O'){
                printf("please enter a valid location \n");
                continue;
            }
            else if (gridLocation > 9 || gridLocation < 0) {
                printf("please enter a valid location \n");
                continue;
            }
            else{
                grid[gridLocation] = 'O';
                gameIsRunning = winCondition(grid);
                
                if (!gameIsRunning)
                {
                    break;
                }
                    
                
                currentPlayer=1;
                
                }

            }

        }
        if (grid[0] != '1' && grid[1] != '2' && grid[2] != '3' &&
            grid[3] != '4' && grid[4] != '5' && grid[5] != '6' &&
            grid[6] != '7' && grid[7] != '8' && grid[8] != '9') {
            printf("The game is a draw! \n");
            displayGrid(grid);
        }
        else if (currentPlayer == 1){
            printf("\033[1;31m%s\033[0m wins! \n", p1);
            displayGrid(grid);
        }
        else if (currentPlayer == 2){
            printf("\033[1;34m%s\033[0m wins! \n", p2);
            displayGrid(grid);
        }

        //feature for rematch
        rematchChecker:
            printf("Rematch? y/n \n");
            scanf(" %c",&rematch);
            if (rematch == 'n'){
                printf("Thanks for playing! \n");
                break;
            }
            else if (rematch == 'y'){
                printf("\033[1;31m%s\033[0m vs \033[1;34m%s\033[0m \n", p1,p2);
                for (int i = 0; i < 9; i++) {
                grid[i] = '1' + i;
                }

                gameIsRunning = 1;
            }
            else{
                printf("Enter valid input \n");
                goto rematchChecker; 
            }

    }

    return 0;

}