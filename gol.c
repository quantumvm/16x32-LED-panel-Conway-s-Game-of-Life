#include <stdio.h>
#include <stdlib.h>

#define VAL 15

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
                test[i][p][q]= (char) '0';
            }
        }
    }
}

//print memory
void print_memory(int x, int y, char *** test){
    //print memory
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

void set_value(int t, int x, int y, char *** test){
   test[t][x][y] = '1'; 
}

int main(void) {
    char *** test = alloc_memory(16,32);
    zero_memory(16,32,test);
    
    for(int i=0; i<VAL; i++){
        set_value(i, 11, 11, test);
    }
    
    zero_memory(16,32,test);

    print_memory(16,32,test);
	
}







