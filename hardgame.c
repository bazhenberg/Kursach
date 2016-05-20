#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

void Constructor(char a[3][3], char b){//Присваиваем начальные значени
	int i, j;
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			a[i][j] = b;	     	
}


int ResultGame(char a[3][3]){//Результат игры
	int i, j, w;

	for(w = 0; w < 2; w++){
	    char b = 'O';
		if(w == 1)
			b = 'X';	
	 	
		for(i = 0; i < 3; i++){
			if(a[i][0] == b && a[i][1] == b && a[i][2] == b){ //по горизонтали
				if(b == 'X'){
				    printf("\n You win!\n ");
				    return 0;
				}
				if(b == 'O'){
					printf("\n You Looser\n ");
					return 0;
				}
			}
			
			if(a[0][i] == b && a[1][i] == b && a[2][i] == b){ //По вертикали
				if(b == 'X'){
					printf("\n You win!\n");
					return 0;
				}
				
				if(b == 'O'){
					printf("\n You Looser\n");	
					return 0;
				}
			}
			
			j = 2;
			
			if(a[i][j] == b &&  a[1][1] == b && a[j][i] == b){
				if(b == 'X'){
					printf("\ You Win!");
					return 0;
				}
				
				if(b == 'O'){
					printf("\n You Loose");
					return 0;
				}
				j = j - 2;
			}
		}  
	}
}

void Interface(char a[3][3]){
	printf("\n[%c][%c][%c]", a[0][0], a[0][1], a[0][2]);
	printf("\n[%c][%c][%c]", a[1][0], a[1][1], a[1][2]);
	printf("\n[%c][%c][%c]", a[2][0], a[2][1], a[2][2]);
}

void CheckComp(char a[3][3], char b){ //Ставит компьютер случайно
	int i, j;
	
	do{
		srand (time(NULL)); 
		
		 i = rand() % 3;
		 j = rand() % 3;
		
	}while(a[i][j] != ' ');
	
	a[i][j] = b;
}

void Check(char a[3][3], char b){ //Ставишь ты
	int i, j;
	
	do{
		printf("\nVvedite X");
		scanf("%i", &i);
		scanf("%i", &j);
		
	}while(a[i][j] != ' ');
	
	a[i][j] = b;
}




/*СЛОЖНАЯ ТАКТИКА ИГРЫ*/

*

HardCheckYou(char a[3][3], char b){ //ты ставишь
		Check(a, b);
		system("cls"); 
		Interface(a);	
}

void HardCheckComp(char a[3][3], int i, int j){//Ставит компьютер
		a[i][j] = 'X';
		system("cls"); 
		Interface(a);
}
//CАМИ ТАКТИКИ

void GreenLimb1(char a[3][3]){
	if(a[0][2] == 'O'){
		ResultGame(a);		
	}
}

void BlackBlueLimb1(char a[3][3]){
	if(a[1][0] == 'O'){
		HardCheckComp(a, 1, 2);	
		HardCheckYou(a, 'O');
		
		GreenLimb1(a);
		
		if(a[2][0] == 'O'){
			HardCheckComp(a, 0, 2);
			ResultGame(a);	
		}			
	}	
}

void BlueLimb1(char a[3][3]){ //Голубая ветка


	HardCheckYou(a, 'O');	
	
	if(a[2][0] == 'O'){ 
		HardCheckComp(a, 0, 2);
		HardCheckYou(a, 'O');
		
		if(a[0][1] == 'O'){
			HardCheckComp(a, 1, 2);	
			ResultGame(a);		
		}
			
	}
		
}

void RedLimb1(char a[3][3]){
	Interface(a);
	HardCheckComp(a, 0, 0);	
	HardCheckYou(a, 'O');
	
	if(a[1][1] == 'O'){
		HardCheckComp(a, 2, 2);	
		BlueLimb1(a);		
		BlackBlueLimb1(a);	
	}
}




void HardGame(char a[3][3]){
	RedLimb1(a);
}
 	
