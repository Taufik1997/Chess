#include <iostream>
#include <string>
#include "position.hpp"
#include "piece.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include <fstream>
using namespace std;

Piece*** crearTablero(int rows, int cols);
void destruirTablero(Piece*** tablero, int rows, int cols);
void imprimir(Piece*** tablero);
void chessInit(Piece*** tablero);
int charToInt(char coordenada);
bool ganar(Piece*** tablero);

int main(int argc, char const *argv[]){
	const int ROWS = 8;
	const int COLS = 8;
	Piece*** tablero = crearTablero(ROWS,COLS);
	string ficha;
	ifstream man;
	man.open("board.txt");
	while(!man.eof()){
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				getline(man,ficha,' ');
				if(ficha == "-"){
					tablero[i][j] = NULL;
				}
				if(ficha == "p"){
					tablero[i][j] = new Pawn('p',i,j);
				}
				if(ficha == "P"){
					tablero[i][j] = new Pawn('P',i,j);
				}
				if(ficha == "t"){
					tablero[i][j] = new Rook('t',i,j);
				}
				if(ficha == "T"){
					tablero[i][j] = new Rook('T',i,j);
				}
				if(ficha == "a"){
					tablero[i][j] = new Bishop('t',i,j);
				}
				if(ficha == "A"){
					tablero[i][j] = new Bishop('T',i,j);
				}
				if(ficha == "q"){
					tablero[i][j] = new Queen('q',i,j);
				}
				if(ficha == "Q"){
					tablero[i][j] = new Queen('Q',i,j);
				}
				if(ficha == "r"){
					tablero[i][j] = new King('k',i,j);
				}
				if(ficha == "R"){
					tablero[i][j] = new King('K',i,j);
				}
				if(ficha == "c"){
					tablero[i][j] = new Knight('k',i,j);
				}
				if(ficha == "C"){
					tablero[i][j] = new Knight('K',i,j);
				}

			}
		}
		
	} //Carga el tablero al programa, por cada pieza se valida cual es del texto y despues la importa a la matriz.
	ofstream file;
	string nombre1,nombre2;
	cout<<"Jugador 1 ingrese su nombre: "<<endl;
	cin>>nombre1;
	cout<<"Jugador 2 ingrese su nombre: "<<endl;
	cin>>nombre2;
	int turno=0;
	bool gano=false;
	char coordenada1, coordenada2;	
	while(!gano){
		bool valid = false;//variable de validacion
		imprimir(tablero);
		turno++;
		int x=0,y=0,x1=0,y1=0;
		if (turno % 2 == 1) {
			while(!valid){//ciclo de validacion
				do{
					cout<<"Turno de: "<<nombre1<<endl;
					cout<<"Ingrese columna de la pieza que desea mover: ";
					cin>>x;
					x--;
				}while(x<9 && x<0);//Validacion que no se salga de rango
				do{
					cout<<"Ingrese fila de la pieza que desea mover: ";
					cin >> coordenada1;
					y = charToInt(coordenada1);
				}while(y<9 && y<0);//Validacion que no se salga de rango
				do{
					cout<<"Ingrese columna a donde la desea mover la pieza: ";//Falta donde
					cin>>x1;
					x1--;
				}while(x1<9 && x1<0);//Validacion que no se salga de rango
				do{
					cout<<"Ingrese fila a donde la desea mover la pieza: : ";//Falta donde
					cin >> coordenada2;
					y1 = charToInt(coordenada2);
				}while(y1<9 && y1<0);//Validacion que no se salga de rango
				Position pos(x1,y1);
				if (tablero[y][x]->getColor()=='B' && tablero[y][x] != NULL){//validacion de mover
					if(tablero[y][x]->moveTo(tablero,pos))
						valid = true;//variable de validacion
					else
						valid = false;
				}else{
					cerr << "No se puede mover las piezas del jugador opuesto" << endl;//Jugador escrito mal
				}
				file.open("board.txt");
				for (int i = 0; i < 8; ++i){
					for (int j = 0; j < 8; ++j)	{
						if(tablero[i][j] != NULL)
						{
							file << tablero[i][j]->toString() << " ";
						}
						else
						{
							file << "- ";
						}
					}
					file<<endl;
				}
				file.close();

			}

		}else{
			while(!valid){//ciclo de validacion
				do{
					cout<<"Turno de: "<<nombre2<<endl;
					cout<<"Ingrese columna de la pieza que desea mover: ";
					cin>>x;
					x--;
				}while(x<9 && x<0);//Validacion que no se salga de rango
				do{
					cout<<"Ingrese fila de la pieza que desea mover: ";
					cin >> coordenada1;
					y = charToInt(coordenada1);
				}while(y<9 && y<0);//Validacion que no se salga de rango
				do{
					cout<<"Ingrese columna a donde la desea mover la pieza: ";//Falta donde
					cin>>x1;
					x1--;
				}while(x1<9 && x1<0);//Validacion que no se salga de rango
				do{
					cout<<"Ingrese fila a donde la desea mover la pieza: : ";//Falta donde
					cin >> coordenada2;
					y1 = charToInt(coordenada2);
				}while(y1<9 && y1<0);//Validacion que no se salga de rango
				Position pos(x1,y1);
				if (tablero[y][x]->getColor()=='N' && tablero[y][x] != NULL){//validacion de mover
					if(tablero[y][x]->moveTo(tablero,pos))
						valid = true;//variable de validacion
					else
						valid = false;
				}else{
					cerr << "No se puede mover las piezas del jugador opuesto" << endl;
				}
				file.open("board.txt");
				for (int i = 0; i < 8; ++i){
					for (int j = 0; j < 8; ++j)	{
						if(tablero[i][j] != NULL)
						{
							file << tablero[i][j]->toString() << " ";
						}
						else
						{
							file << "- ";
						}
					}
					file<<endl;
				}
				file.close();
			}
		}
		gano = ganar(tablero);
	}

	destruirTablero(tablero,ROWS,COLS);
	return 0;
}
Piece*** crearTablero(int rows, int cols){
	Piece*** retval = new Piece**[rows];
	for (int i = 0; i < rows; ++i)	{
		retval[i] = new Piece*[cols];
	}
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			retval[i][j] = NULL;
		}
	}
	chessInit(retval);
	return retval;
}
void destruirTablero(Piece*** tablero, int rows, int cols){
	for (int i = 0; i < cols; ++i)	{
		delete[] tablero[i];
	}
	delete[] tablero;
}
void imprimir(Piece*** tablero){//imprimir tablero
	char letras[] = "ABCDEFGH";
	int numeros[] = {1,2,3,4,5,6,7,8};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j)	{
			if(tablero[i][j] != NULL)
			{
				cout << "[" << tablero[i][j]->toString() << "]";
			}
			else
			{
				cout << "[ ]";
			}
		}
		cout << letras[i] << endl;
	}
	for (int i = 0; i < 8; ++i)	{
		cout << " " << numeros[i] << " ";
	}
	cout << endl;
}
void chessInit(Piece*** tablero){//Inicializar tablero
	//piezas blancas
	//torres
	tablero[0][0] = new Rook('B',0,0);
	tablero[0][7] = new Rook('B',7,0);
	//caballos
	tablero[0][1] = new Knight('B',1,0);
	tablero[0][6] = new Knight('B',6,0);
	//alfiles
	tablero[0][2] = new Bishop('B',2,0);
	tablero[0][5] = new Bishop('B',5,0);
	//rey
	tablero[0][3] = new King('B',3,0);
	//reina
	tablero[0][4] = new Queen('B',4,0);
	//peones
	for (int i = 0; i < 8; ++i){
		tablero[1][i] = new Pawn('B',i,1);
	}
	//piezas negras
	//torres
	tablero[7][0] = new Rook('N',0,7);
	tablero[7][7] = new Rook('N',7,7);
	//caballos
	tablero[7][1] = new Knight('N',1,7);
	tablero[7][6] = new Knight('N',6,7);
	//alfiles
	tablero[7][2] = new Bishop('N',2,7);
	tablero[7][5] = new Bishop('N',5,7);
	//rey
	tablero[7][3] = new King('N',3,7);
	//reina
	tablero[7][4] = new Queen('N',4,7);
	//peones
	for (int i = 0; i < 8; ++i){
		tablero[6][i] = new Pawn('N',i,6);
	}
}
int charToInt(char coordenada){
	switch (coordenada){
		case 'a':
			return 0;
		case 'b':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'e':
			return 4;
		case 'f':
			return 5;
		case 'g':
			return 6;
		case 'h':
			return 7;
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'F':
			return 5;
		case 'G':
			return 6;
		case 'H':
			return 7;
		default:
			return -1;
	}
}
bool ganar(Piece*** tablero){
	int cont=0;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if(dynamic_cast<King*>(tablero[i][j]) != NULL){
				King* king = dynamic_cast<King*>(tablero[i][j]);
				cont++;
			}
		}
	}
	if (cont==1)
	{
		return true;
	}
	return false;
}