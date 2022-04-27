#include <iostream>
#include <cmath>
using namespace std;
//Camille Cajas 23838473
//1D array solution

int main() {
	
	//initializing 
	int q[8]= {0};
	int col=0;
	int solutions = 0;
	//placing a queen in the top left square
	q[0]=0;
	
nc: 
	col++;
	//if we reach column 8, we have a solution
	//if we have a solution we print
	if (col==8) goto print;
	q[col]=-1;
nr:	
	q[col]++;//value is the the row where the queen resides 
	if (q[col]==8) {
		goto backTrack;
	}

	for(int i=0;i<col;i++){
		if(q[i]==q[col] || (col-i)==abs(q[col]-q[i])) goto nr; 
	}//row test           //diagnoltest
	goto nc;
	
backTrack:
	col--;
	
	//prints out number of solutions and terminated the program
	if (col==-1) {
		return 0;
	}
	
	goto nr;

	
print:
	solutions++;
	
	//nested forloop to print out the program
	cout<< "solution "<< solutions << ": " << endl; // prints out solution number
	for (int i=0; i<8; i++){
		cout << q[i] << " "; //prints out solutions
	}
	cout << endl << endl;
	
	// prints out queens placement on 8x8 grid
	for (int i=0; i<8;i++){
		for (int j=0; j<8;j++){
			if (q[j]==i) cout << "1 ";
			if (q[j]!=i) cout << "0 ";
		}
		cout << endl;
	}
	
	cout << endl;

	goto backTrack;

}
