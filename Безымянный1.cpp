#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "hardgame.c"




/*void GameHistory(int a[], int x, int y, int increment){ //������� ����
	int i , j;
	
	a[increment] = x;
	a[increment+1] = y;
	
	for(i = 0; i <= increment; i++){
			printf("\n%i. You: %i", i+1, a[i]);
			printf("\n%i. Computer: %i", i+2, a[i+1]);

	}
}*/



int main(){
	char KN[3][3]; 
	int Tackt[10];//������ ��� ������ �����
	int x, y;//���������� ��� ���
	int a; //���������� ������
 //	int i = 0;
	back:
		
	Constructor(KN, ' ');
	
	printf("XXXXXXXXXXGAME0000000000");//������� ����
	printf("\n          MENU          ");
	printf("\n 1. One Player");
	printf("\n 2. Two Player");
    printf("\n 3. Exit\n ");
	
	scanf("%i", &a);
	
	
	switch(a){
		case 1:{	
			system("cls");
			printf(" 1. Easy Game");
			printf("\n 2. Hard Game");
			printf("\n 3. Back");
			
			scanf("%i", &a);
			
			system("cls");	
			switch(a){	
				case 1:{ 
					
					printf("XXXXXXXXXXEASY_GAME0000000000\n\n");
					
					while(ResultGame(KN) != 0){ //���� ����� �� �������

						Check(KN, 'X');//������ X
						system("cls"); 
						Interface(KN); //��������� �����
						
						if(ResultGame(KN) != 0){ 
							CheckComp(KN, 'O');
						    system("cls");
							Interface(KN);
						}
						else
							break;
					}
					
				break;
				}  
				
				case 2:{
					printf("XXXXXXXXXXHARD_GAME0000000000");
						HardGame(KN);	
					break;
				}	
				
				case 3:
					goto back;
					break;		
			break;
		}
	}
	return 0;
	system("PAUSE");
}
}
