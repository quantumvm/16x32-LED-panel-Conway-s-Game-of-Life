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


//set memory to char '0'
void zero_memory(int x, int y, char *** test){
    puts("IN Z");
    for(int i=0; i<VAL; i++){
        for(int p=0; p<x; p++){
            for(int q=0; q<y; q++){
                test[i][p][q]= (char) '0';
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
void set_value(int t, int x, int y, char c, char *** test){
   test[t][x][y] = c; 
}

//initialize first frame with random seed for game of life
void initialize_random(int x, int y, char *** test){
    time_t t;
    int random_iterations;

    srand((unsigned) time(&t));
    random_iterations = (rand() % (MAX_RANDOM-MIN_RANDOM)) + MIN_RANDOM;
    
    for(int i=0; i<random_iterations; i++){
        set_value(0, rand() % x, rand() % y, '1', test);
    }
}

int check_surrounding_neighbors(int x, int y, int i, int x_max, int y_max, char *** test){
    puts("CHECK SURROUNDING");
    int neighbors = 0;

    if(test[i][(x-1) % x_max][(y-1) % y_max]){
        neighbors++;
    }
    if(test[i][x % x_max][(y-1) % y_max]){
        neighbors++;
    }
    if(test[i][(x+1) % x_max][(y-1) % y_max]){
        neighbors++;
    }
    if(test[i][(x-1)%x_max][(y)%y_max]){
        neighbors++;
    }
    if(test[i][(x+1)%x_max][y%y_max]){
        neighbors++;
    }
    if(test[i][(x-1)%x_max][(y+1)%y_max]){
        neighbors++;
    }
    if(test[i][x%x_max][(y+1)%y_max]){
        neighbors++;
    }
    if(test[i][(x+1)%x_max][(y+1)%y_max]){
        neighbors++;
    }
    
    return neighbors;
}

void mutate(int x, int y, char *** test){
    puts("MUTATE");
    int neighbors;
    int is_alive;

    //iterate through frame
    for(int i=0; i<(VAL-1); i++){
        for(int x_i=0; x_i<x; x_i++){
            for(int y_i=0; y_i<y; i++){
                neighbors = check_surrounding_neighbors(x_i, y_i, i, x, y, test);
                is_alive = ('1'==test[i][x_i][y_i]) ? 1:0;
                
                if(is_alive){
                    if(neighbors<2){
                        set_value(i+1, x_i, y_i, '0', test);
                    }
                    else if(neighbors==2 || neighbors==3){
                        set_value(i+1, x_i, y_i, '1', test);
                    }
                    else if(neighbors > 3){
                        set_value(i+1, x_i, y_i, '0', test);
                    }
                }else{
                    if(neighbors == 3){
                        set_value(i+1, x_i, y_i, '1', test);
                    }
                }
            }
        }
    }


}


int main(void) {
    char *** test = alloc_memory(16,32);
    zero_memory(16,32,test);
    
    initialize_random(16,32,test); 
    mutate(16,32,test);

    print_memory(16,32,test);
	
}







