#include <iostream>
#include <cmath>
using namespace std;
//Camille Cajas 23838473
//1D array solution

void newColumn(int q[],int &c);
void newRow(int q[],int &c);
void print(int q[],int &c);
void backTrack(int q[],int &c);


//Tests
bool okey(int q[], int col){
	for(int i=0;i<col;i++){
		if(q[i]==q[col] || (col-i)==abs(q[col]-q[i])) return false;
	}	
	return true;	
}

void backTrack(int q[],int &c){
	c--;
	if(c== -1){
		cout << "found all solutions";
		exit(0);	
	}
	newRow(q,c);
}



void newColumn (int q[], int &c){
	c++;
	if(c==8) print(q,c);
	q[c]=-1;
	newRow(q,c);
}

void newRow(int q[],int &c) {
	q[c]++;
	if (q[c]==8) {
		//reset
		backTrack(q,c);
	} if (okey(q,c)) newColumn(q,c);
	else newRow(q,c);
	
}



void print(int q[], int &c){
	
	static int solutions=0;
	
	
	//nested forloop to print out the program
	cout<< "solution "<< ++solutions << ": " << endl; // prints out solution number
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
	backTrack(q,c);
}

int main() {
	
	//initializing 
	int q[8]= {0};
	int col=0;
	
	//placing a queen in the top left square
	q[0]=0;
	newColumn(q,col);
	
	return 0;
}
