#include <stdio.h>

char board[3][3];  // Global board

// Function to initialize board with numbers 1–9
void initBoard() {
    int count = 1;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '0' + count; // convert int to char
            count++;
        }
    }
}

// Function to display board
void displayBoard() {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        if(i < 2) printf("\n---+---+---\n");
    }
    printf("\n");
}

// Function to check winner
char checkWinner() {
    // Rows & Columns
    for(int i=0; i<3; i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return board[i][0];
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return board[0][i];
    }
    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return board[0][2];

    return ' '; // No winner yet
}

// Main game loop
int main() {
    initBoard();
    int moves = 0;
    char player = 'X';
    char winner = ' ';

    while(moves < 9 && winner==' ') {
        displayBoard();
        int pos;
        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &pos);

        // Convert pos to row/col
        int row = (pos-1)/3;
        int col = (pos-1)%3;

        // Validate move
        if(board[row][col]=='X' || board[row][col]=='O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        winner = checkWinner();
        player = (player=='X') ? 'O' : 'X'; // Switch player
    }

    displayBoard();
    if(winner!=' ')
        printf("🎉 Player %c wins!\n", winner);
    else
        printf("It's a draw!\n");

    return 0;
}
