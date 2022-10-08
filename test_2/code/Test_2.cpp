#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AgePerson {
	int number ; 
	char date[ 99 ] ; 
	char name[ 99 ] ; 
} typedef Age ; 

int importdata ( Age [] ) ; 
void presentdata ( Age [], int ) ;

int main(){
	Age person[ 99 ] ; 
	int number ; 
	number = importdata( person ) ;
	presentdata( person, number ) ;
	return 0 ;
}

int importdata ( Age human[] ) {
	FILE *fp ; 
	int count ;
	fp = fopen( "info.txt", "r" ) ;
	fscanf(fp,  "%s\t%s\t\t%s\n", human[ 0 ].name, human[ 0 ].name, human[ 0 ].name ) ;
	strcpy(human[0].name, "\0") ;
	for (int i = 0 ; i < 100 ; i++){
		while (fscanf( fp, "%d\t%s\t\t%s\n", &human[ i ].number, human[ i ].name, human[ i ].date) != EOF ) {
			count++ ;
			break ;
		}//end while
	}//end for
	fclose( fp ) ;
	return count ; 
}

void presentdata ( Age person[], int count) {
	int oldest = -999999999 ; 
	int youngest = 999999999 ; 
	char holdall[ 99 ], hold[ 99 ] ;
	int year, month, day ;
	char *pname ; 
	int allday[ 99 ] ;
	for (int i = 0 ; i < count ; i++) {
		strcpy(holdall, person[i].date ) ;
		for(int j = 0 ; j < 4 ; j++ ) {
			hold[ j ] = holdall[ j ] ;
		}//end for
		hold[ 4 ] = '\0' ;
		year = atoi( hold ) ;
		for(int j = 0 ; j < 2 ; j++ ) {
			hold[ j ] = holdall[ j + 5 ] ;
		}//end for
		hold[ 2 ] = '\0' ;
		month = atoi( hold ) ;
		
		for(int j = 0 ; j < 2 ; j++ ) {
			hold[ j ] = holdall[ j + 8 ] ;
		}//end for
		hold[ 2 ] = '\0' ;
		day = atoi( hold ) ;
		allday[ i ] =  ( 2018 - year ) * 365 + ( 6 - month ) * 30 + ( 21 - day ) ;
		printf("%s %d Years, %d Months\n", person[ i ].name, allday[ i ]/ 365, ( allday[ i ] % 365) / 30 ) ;
	}//end for
	
	for (int c = 0; c < count ; c++ ) {
		while ( allday[ c ] > oldest ) {
			oldest = allday[ c ] ;
			pname = person[ c ].name ;
			break ;
		}//end while
	}//end for
	printf( "\nthe Max : %s [%d Years, %d months]", pname, oldest / 365, (oldest % 365) / 30) ;
	
	for (int c = 0; c < count ; c++ ) {
		while ( allday[ c ] < youngest ) {
			youngest = allday[ c ] ;
			pname = person[ c ].name ;
			break ;
		}//end while
	}//end for
	printf( "\nthe min : %s [%d Years, %d months]", pname, youngest / 365, (youngest % 365)/ 30) ;

}
