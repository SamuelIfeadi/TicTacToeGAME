#include <iostream>
#include <string>
using namespace std;



char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row; int col;
char token = 'x';
string p1 = "";
string p2 = "";
bool tie = false;

void FunctionOne() {

	/*Structure of game*/

	/*Adding the elements to the empty space*/
	cout << "     |     |  \n";
	cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
	cout << "_____|_____|_____\n"; 
	cout << "     |     |  \n";
	cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |  \n";
	cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
	cout << "     |     |  \n";

}

void FunctionTwo() {
	int digit;
	if (token == 'x') {
		cout << p1 << ", please enter: ";
		cin >> digit;
	}
	else if (token == 'o') {
		cout << p2 << ", please enter: ";
		cin >> digit;
	}

	if (digit >= 1 && digit <= 9) {
		row = (digit - 1) / 3;
		col = (digit - 1) % 3;

		if (space[row][col] != 'x' && space[row][col] != 'o') {
			space[row][col] = token;

			if (token == 'x')
				token = 'o';
			else
				token = 'x';
		}
		else {
			cout << "Invalid move. The space is already occupied." << endl;
			FunctionTwo();
		}
	}
	else {
		cout << "Invalid input. Please enter a number between 1 and 9." << endl;
		FunctionTwo();
	}
}


/*Setting conditions for players to win*/
bool FunctionThree() {
	for (int i = 0; i < 3; i++) {
		if (space[i][0] == space[i][1] && space[i][0] == space[i][2]
			|| space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
			return true;
		}
	}

	if (space[0][0] == space[1][1] && space[1][1] == space[2][2]
		|| space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
		return true;
	}

	bool allSpacesFilled = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (space[i][j] != 'x' && space[i][j] != 'o') {
				allSpacesFilled = false;
				break;
			}
		}
		if (!allSpacesFilled) {
			break;
		}
	}

	if (allSpacesFilled) {
		tie = true;
		return true;
	}

	return false;
}



int main() {
	cout << "Enter the name of Player 1 {x} : \n";
	getline(cin, p1);

	cout << "Enter the name of Player 2 {o} : \n";
	getline(cin, p2);

	cout << p1 << " will play first" << endl;
	cout << p2 << " will play second" << endl;

	while (!FunctionThree()) {
		FunctionOne();
		FunctionTwo();
	}

	if (tie) {
		cout << "It's a draw!" << endl;
	}
	else {
		if (token == 'x') {
			cout << p2 << " is the winner!" << endl;
		}
		else {
			cout << p1 << " is the winner!" << endl;
		}
	}

	return 0;
}
