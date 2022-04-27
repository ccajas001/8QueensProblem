#include <iostream>
using namespace std;
//Camille Cajas 23838473

int main() {
	
	//initializing 
	int board[8][8]	= {0};
	int row, col=0;
	int solutions = 0;
	//placing a queen in the top left square
	board[0][0]=1;
nc: 
	col++;
	//if we reach column 8, we have a solution
	//if we have a solution we print
	if (col==8) goto print;
	row=-1;
nr:	
	row++;
	if (row==8) goto backTrack;
	//row test
	for(int i=0;i<col;i++){
		if (board[row][i]==1) goto nr;
	}
	//up diagonal test
	for(int i=0; (row-i)>=0 && (col-i)>=0 ;i++) {
		if (board[row-i][col-i]==1) goto nr;
		//going up the row and toward the left
	}
	// down diagnol test 
	for (int i=0; (row+i)<8 && (col-i)>=0;i++) {
		if (board[row+i][col-i]==1) goto nr;
		//going down the row and toward the left
	}
	//if we pass our tests we place a queen and we go to the next column
	board[row][col]=1;
	goto nc;
	
backTrack:
	col--;
	
	//prints out number of solutions and terminated the program
	if (col==-1) {
		cout << "There are " << solutions << " solutions";
		return 0;
	}
	
	//traverses previous column and takes away queen and
	//continues along the row to see if there is a new stop for it
	for (int i=0; i<8;i++){
		if (board[i][col]==1){
			board[i][col]=0;
			row=i; //set r=i to continue from where queen was taken away in the backTrack
			goto nr;
			
		}
	}
	
print:
	solutions++;
	//nested forloop to print out the program
	cout<< "this is solution  "<< solutions << endl; // prints out solution number
	for (int i=0; i <8; i++){
		for (int j=0; j<8;j++){
			cout << board[i][j] << " "; //prints out solutions
		}
	cout<< endl;
	}

	goto backTrack;

}