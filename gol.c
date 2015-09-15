#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VAL 2
#define MIN_RANDOM 30
#define MAX_RANDOM 50

//allocate memory
char *** alloc_memory(int x, int y){
    char *** test;
    test = malloc(VAL * sizeof(char **));
	
    for(int i=0; i<VAL; i++){
        test[i] = malloc(x * sizeof(char *));
    }
    
    for(int i=0; i<VAL; i++){
        for(int p=0; p<x; p++){
            test[i][p] = malloc(y * sizeof(char));
        }
    }
    
    return test;
}


//set memory to 0
void zero_memory(int x, int y, char *** test){
    puts("IN Z");
    for(int i=0; i<VAL; i++){
        for(int p=0; p<x; p++){
            for(int q=0; q<y; q++){
                test[i][p][q]= (char) ' ';
            }
        }
    }
}

//print memory
void print_memory(int x, int y, char *** test){
    for(int i=0; i<VAL; i++){
        for(int p=0; p<x; p++){
            for(int q=0; q<y; q++){
                printf("%c",test[i][p][q]);
            }
            
            printf("\n");
        }
        printf("|------------------|\n");
    }
}

//Set value in frame t to 1
void set_value(int t, int x, int y, char *** test){
   test[t][x][y] = '1'; 
}

//initialize first frame with random seed for game of life
void initialize_random(int x, int y, char *** test){
    time_t t;
    int random_iterations;

    srand((unsigned) time(&t));
    random_iterations = (rand() % (MAX_RANDOM-MIN_RANDOM)) + MIN_RANDOM;
    
    for(int i=0; i<random_iterations; i++){
        set_value(0, rand() % x, rand() % y, test);
    }
}

void mutate(){

}


int main(void) {
    char *** test = alloc_memory(16,32);
    zero_memory(16,32,test);
    
    initialize_random(16,32, test); 

    print_memory(16,32,test);
	
}







