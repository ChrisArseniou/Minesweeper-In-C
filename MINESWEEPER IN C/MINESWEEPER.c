#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>


char game[24][24] , displayed[24][24];/* to 0 shmainei oti den exei apokalyfthei kamia thesh*/


void resetPinakas(int rows){
	int i, j;
	
	for(i = 0; i< rows ; i++){
		for(j=0;j<rows;j++){
			game[i][j] = 0;
		}
	}
}

void displayedPinakas(int rows){
	int i,j; /*metrhtes tou vrongxou for gia thn arxikopoihsh tou pinaka displayed*/
	
	for(i=0;i<rows;i++){
		for(j=0;j<rows;j++){
			displayed[i][j] = 0 + '0';
		}
	}
}
void pinakasLYSH(int rows){ /* einai o pinakas pou tipwnei tin lish sto telos tou programmatos*/
	
	int i=0,l=0; /*metrhtes vrogxou for*/
	
	printf("\n");
	printf("  ");
	for(i=1; i<= rows; i++){/*ousiastika to rows einai columns*/
		printf("%4d" , i);
		}
	printf("\n\n");
	for(i=0;i<rows;i++){
		printf("%2d",i+1);
		for(l=0;l<rows;l++){
			if(i < 10){
				if(l == 0){
						printf("%4c",game[i][l]);
					}
					else{
						printf("%4c" , game[i][l]);
					}
			}
			if(i >= 10){
					if(l == 0){
						printf("%4c",game[i][l]);
					}
					else{
						printf("%4c" , game[i][l]);
					}
				}
				
			}
			printf("\n");
		}
		printf("\n");
	}

void pinakasGame(int rows,int narkes){ /*apofasizei se poies theseis 8a mpoun oi narkes xwris na ginei overlap*/
	
	int counter,randomFact1, randomFact2,i,j,k;/*randomFact1 = seira 'random', randomFact2 = sthlh 'random'*/
	
	counter = 0;
	
	while(counter < narkes){
		randomFact1 = (rand() % rows);
		randomFact2 = (rand() % rows);
		if(game[randomFact1][randomFact2] == '*'){
			continue;
		}
		game[randomFact1][randomFact2] = '*';
		counter++;
	}
	
	k=0; /*edw elegxoume tin girw perioxh kai analogws poses narkes exei tipwnei ton analogo arithmo apo 0-8*/
	for(i=0; i < rows; i++){
		for(j=0; j < rows; j++){
			if(game[i][j] == '*'){
				continue;
			}
			else{ 
				
				if(game[i-1][j-1] == '*' && i-1 >= 0 && j-1 >=0){
					k++;
				}
				if(game[i-1][j] == '*' && i-1>=0){
					k++;
				}
				if(game[i-1][j+1] == '*' && i-1>=0 && j+1 <= rows-1){
					k++;
				}
				if(game[i][j-1] == '*' && j-1 >= 0){
					k++;
				}
				if(game[i][j+1] == '*' && j+1 <= rows-1){
					k++;
				}
				if(game[i+1][j-1] == '*' && i+1 <= rows-1 && j-1 >=0){
					k++;
				}
				if(game[i+1][j] == '*' && i+1 <= rows-1){
					k++;
				}
				if(game[i+1][j+1] == '*' && i+1 <= rows-1 && j+1 <= rows-1){
					k++;
				}
			}
			game[i][j] = k + '0';
			k=0;
		}
	}
}

void kanvas(int rows){ /*tipwnetai o prwtos kamvas*/
	
	int i, l;/*counters*/
	
	printf("\n");
	printf(" ");
	
	printf(" ");
	for(i=1; i<= rows; i++){/*ousiastika to rows einai columns*/
		printf("%4d" , i);
		}
	
	printf("\n\n");
	
	if (rows==6){
		for(i=1 ; i<=6; i++){
			printf("%2d " , i);
		
			printf("  -");
			for(l=0; l<(5); l++){
				printf("   -");
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		if(rows==12){
			
			for(i=1 ; i<=9; i++){
				printf("%2d " , i);
		
				printf("  -");
				for(l=0; l<(11); l++){
					printf("   -");
				}
				printf("\n");
			}
			
			for(i=10; i<=12; i++){
				printf("%2d" , i);
				printf("   -");
				for(l=0; l<11; l++){
					printf("   -");
				}
				printf("\n");
			}
			printf("\n");
		}
			else{
				for(i=1 ; i<=9; i++){
					printf("%2d " , i);
					printf("  -");
					for(l=0; l<(23); l++){
						printf("   -");
					}
					printf("\n");
				}
		
				for(i=10; i<=24; i++){
					
					printf("%2d" , i);
					printf("   -");
					for(l=0; l<23; l++){
						printf("   -");
					}
					printf("\n");
				}
				printf("\n");
			}
			
		}
	
	}

void printLEVEL(void){ /*print to menu*/
	printf("\nChoose difficulty level:\n");
	printf("EASY (E/e)\n");
	printf("MEDIUM (M/m)\n");
	printf("EXPERT (X/x)\n");
	printf("==> ");
}

void clean_stdin(void)/*to xrhsimopoihsame auto giati merika printf ekteloutan 2 fores ston ipologsth pou douleuame*/
{
	int c;
    do {
		c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(int argc, char *argv[]) {                                                  
	
	unsigned int seedNum; /*seed*/
	int seedProg,rows,narkes,row,col,i,l,newElement=0;
	char repeat,difficulty;
	char kanvas1[24][24];/*einai o pinakas pou apokaliptei tis times pou dinei o xrhsths*/
	
		printf("\n");
		printf("Seed? ");
		scanf("%d",&seedNum);
		if (seedNum == 0){
			seedProg = time(NULL);
		}
		else{
			seedProg = seedNum;
		}
		srand(seedProg);
	while(1){
		
		do{
			printLEVEL();
			scanf(" %c",&difficulty);
				
		}while(difficulty!='X' && difficulty!='x' && difficulty!='M' && difficulty!='m' && difficulty!='E' && difficulty!='e');
		
		switch (difficulty){
			case('E'):
			case('e'):{
				rows = 6;
				break;
			}
			case('M'): 
			case('m'):{
				rows = 12;
				break;
			}
			case('X'):
			case('x'):{
				rows = 24;
				break;
			}
		}
		printf("\n#\n");
		for(i=0;i<rows;i++){
			for(l=0;l<rows;l++){
			kanvas1[i][l] = '-';
			}
		}
		narkes = trunc((20 * rows * rows)/100);/*vriskei tis narkes kai tipwnei tis narkes kai me noumera 3ekinwntas to paixnidi*/
		
		pinakasGame(rows,narkes);
		kanvas(rows);
		displayedPinakas(rows);
		
		while(1){
			printf("\nRow> ");
			scanf("%d",&row);
			if(row == 0){
				printf("\nGame interrupted.\n");
				break;
			}
			while(row<0 || row > rows){
				printf("\nInvalid row. Try again!\n");
				printf("\n#\n");
				printf("\nRow> ");
				scanf(" %d",&row);
				
				if(row == 0){
				printf("\nGame interrupted.\n");
				//printf("\n#\n");
				break;
				}
				
				if(row > 0 && row <rows){
					break;
				}
			}
			if(row == 0){
				break;
			}
			printf("\nCol> ");
			scanf("%d",&col);
			while(col<=0 || col > rows){
				printf("\nInvalid column. Try again!\n");
				printf("\n#\n");
				printf("\nCol> ");
				scanf("%d",&col);
				if(col > 0 && col < rows){
					break;
				}
			}
			if(row == 0){
				break;
			}
			if(game[row-1][col-1] != '*'){
				kanvas1[row-1][col-1] = game[row-1][col-1];
			
				if(displayed[row - 1][col - 1] != 1 + '0'){
					displayed[row-1][col-1] = 1 + '0';
					newElement++;
				}
				if(newElement == ((rows * rows) - narkes)){
					printf("\nCongratulations!\n");
					pinakasLYSH(rows);
					break;
				}
				
				printf("\n");
				printf("  ");
				for(i=1; i<= rows; i++){/*ousiastika to rows einai columns*/
				printf("%4d" , i);
				}
				printf("\n\n");
				for(i=0;i<rows;i++){
					if(i < 9){
					printf(" ");
					}
					printf("%d",i+1);
					for(l=0;l<rows;l++){
						//printf(" ");
						if(i < 10){
							if(l == 0){
								printf("%4c",kanvas1[i][l]);
							}
							else{
								printf("%4c" , kanvas1[i][l]);
							}
						}
						if(i >= 10 ){
							if(l == 0){
								printf("%4c",kanvas1[i][l]);
							}
							else{
								printf("%4c" , kanvas1[i][l]);
							}
						}
					}
							printf("\n");
				}
				printf("\n");
			}
			if(game[row-1][col-1] == '*'){
				printf("\nKABOOM!\n");
				pinakasLYSH(rows);
				break;
			}
		
		}
		
		while(1){/*an 8es na pai3eis kai alla*/
			clean_stdin();
			printf("\n#\n");
			printf("Play again? (y/n) ");
			scanf("%c",&repeat);
			if(repeat == 'Y' || repeat == 'y'){
				resetPinakas(rows);
				break;
			}
			else{
				if(repeat == 'N' || repeat == 'n'){
						break;
				}
				else{
					resetPinakas(rows);
					continue;
				}
			}
				
		}
		
		if(repeat == 'N' || repeat == 'n'){
						return(0);
		}
	}
	return (0);
}
