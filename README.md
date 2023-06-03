# TicTacToeGAME
Tic-Tac-Toe Game
This is a simple implementation of the Tic-Tac-Toe game in C++. The game allows two players to play against each other on a 3x3 grid.

#How to Play
Compile and run the program.
Enter the name of Player 1 (denoted by 'x').
Enter the name of Player 2 (denoted by 'o').
The game will display the initial empty grid.
Players take turns entering a number between 1 and 9 to indicate the position they want to mark.
The game will update the grid and continue until a player wins or the game ends in a draw.
The game will display the winner or indicate a draw.

#Code Explanation
The code consists of the following functions:

FunctionOne(): Prints the current state of the game board.
FunctionTwo(): Handles the input from the players and updates the game board.
FunctionThree(): Checks for winning conditions or a draw.
main(): The entry point of the program. It prompts the players for their names, runs the game loop, and displays the result.
The game board is represented by a 2D array called space. Each cell in the array can hold either 'x' or 'o' to represent the player's mark.

The game loop continues until a winning condition is met or the game ends in a draw. The loop calls FunctionOne() to display the game board, then FunctionTwo() to handle player input.
FunctionThree() is called at the end of each loop iteration to check for a winner or draw.
