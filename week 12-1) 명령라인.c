void_exec1(){

#include <stdio.h>

int main(int argc, char* argv[]){
    for(int i=0; i<argc; i++){
        puts(argv[i]);
    }
    return 0;
}

    
}

void_exec2(){
    
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int a, b; 

    a = atoi(argv[1]); //atoi -> 숫자형식 문자를 숫자로 바꿈
    b = atoi(argv[2]);

    printf("a+b = %d", a+b);
    return 0;
}

}