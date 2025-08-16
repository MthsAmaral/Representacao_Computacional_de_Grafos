#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>

#include "Bibliotecas/Grafo.h"
#include "Bibliotecas/Moldura.h"

void LerArquivo(char *arquivo) {
	FILE *arq = fopen(arquivo, "r");

	char caractere;
	clrscr();
	
	if (arq == NULL)
		printf("Erro de abertura");
	else {
		caractere = fgetc(arq);
		while(!feof(arq)) {
			printf("%c", caractere);
			caractere = fgetc(arq);
		}
	}
	
	getch();
	fclose(arq);
}

char Menu(void) {
	MolduraCompleta(1,1,100,30,0,3);
	CaixaTexto(30,3,70,27,0,7,"ESCOLHA O TIPO");
	ExibeTexto(100, 6, 0, 14, "[A] - Matriz de Adjacencia","");
	ExibeTexto(100, 11, 0, 14, "[B] - Matriz de Incidencia", "");
	ExibeTexto(100, 16, 0, 14, "[C] - Lista de Adjacencia", "");
	ExibeTexto(100, 23, 15, 12, "[ESC] - Sair", "");

	return toupper(getch());
}

void ExibirVertices(char *vertices, int tam) {
	int l = 0, i = 0;
	
	for(i=0;i<tam;i++) {
		gotoxy(23, 5+l);
		l+=2;
		printf("[%c]", vertices[i]);
	}
	
}

void ExibirMatriz(char *vertices, char mat[10][10], int tam) {
	int i;
	for(i=65;i<74;i++) {
		vertices[i-65] = i;
	}
	
	CaixaTexto(20,3,80,27,0,7,"MATRIZ DE ADJACENCIA");
	
	ExibirVertices(vertices, tam);
	
	getch();
}


void exibirMA(char vertices[30], int TLv, int mat[30][30], int qtdLin){
	
	system("cls");

	//exibir vertices
	for(int i=0;i<TLv;i++)
		printf("%c ",vertices[i]);
	printf("\n");

	for(int i=0;i<qtdLin;i++){
		for(int j=0;j<TLv;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	getch();
}

void lerTxtMA(char vertices[], int *TLv, int mat[30][30], int *qtdLin){
	char carac;
	int c=0, num;

	FILE *ptr = fopen("MA.txt","r");
	if(ptr != NULL)
	{
		//anda primeira linha do arq e joga
		carac = fgetc(ptr);
		while(carac != '\n' && !feof(ptr))
		{
			if(carac != ' ')
				vertices[(*TLv)++] = carac;
			carac = fgetc(ptr);
		}

		*qtdLin=0;
	
		//Matriz
		while(fscanf(ptr,"%d",&num)== 1)// enquanto ler um número inteiro.
		{
			mat[*qtdLin][c++] = num;
			
			if(c == *TLv)
			{
				c=0;
			(*qtdLin)++;
			}
		}
		fclose(ptr);
	}
}

int main(void) {
	char op, mat[10][10], vertices[10], incidencia[10];
	int qtVertices = 10, qtIncidencias ,i,j;
	
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			mat[i][j] = (i+j+1)*(j+1);
	
	RetiraCursor();
	Dimensao("100","30");

	do {
		op = Menu();

		switch(op) {
			case 'A':
				printf("Matriz de Adjacencia");
				LerArquivo("Arquivos/MA.txt");
				ExibirMatriz(vertices, mat, qtVertices);
				break;
			case 'B':
				printf("Matriz de Incidencia");
				LerArquivo("Arquivos/MI.txt");
				break;
			case 'C':
				printf("Lista");
				LerArquivo("Arquivos/LA.txt");
		}
		
	} while(op != 27);
	
	MsgFim();
	
	return 0;
}
