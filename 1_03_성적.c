#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SIZE 100

void exec1(){
    
    int number[SIZE];
    int total = 0;
    int max, min;
    float avg = 0.0;
    srand(time(NULL));
    
    for(int i = 0; i<SIZE; i++){
     number[i] = (rand() % 100) + 1;
    }
    
    for(int i = 0; i<SIZE; i++){
        printf("%3d\t" , number[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    
    for(int i = 0; i<SIZE; i++){
     total += number[i];
    }
    
    avg = (float)total / SIZE;        /* (float)total -> 정수인 total을 실수로 취급하도록 하게 함 */
    max = number[0];
    min = number[0];
    
    for(int i = 0; i<SIZE; i++){
        if(max < number[i]) max = number[i];
        if(min > number[i]) min = number[i];
    }
    printf("avg = %f, max = %d, min = %d", avg, max, min);
} // 동영상상
void exec2(){
    int number[SIZE];
    int total = 0;
    int max,min;
    float avg = 0.0;
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        number[i] = (rand() % 100) +1;
    }

    for(int i=0; i<SIZE; i++){
        printf("%3d\t", number[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    
    for(int i=0; i<SIZE; i++){
        total += number[i];
    }
    
    avg = (float)total / SIZE;

    max = 0;
    min = 0;

    for(int i=1; i<SIZE; i++){
        if(number[max] < number[i]) 
            max = i;
        if(number[min] > number[i]) 
            min = i;
    }

    printf("avg = %f, max = %d, min = %d\n", avg, number[max], number[min]);

} // 활용 1
void exec3(){
    int number[SIZE];
    int total = 0;
    int max, min;
    int maxIndex, minIndex;
    float avg = 0.0;
    
    srand(time(NULL));
    for(int i=0; i<SIZE; i++){
        number[i] = (rand() % 100) + 1;
    }
    for(int i=0; i<SIZE; i++){
        printf("%3d\t", number[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    for(int i=0; i<SIZE; i++){
        total += number[i];
    }
    avg = (float)total / SIZE;  /* (float)total -> 정수인 total을 실수로 취급하도록 하게 함 */
    
    max = number[0];
    min = number[0];
    maxIndex = 0;
    minIndex = 0;
    for(int i=1; i<SIZE; i++){
        if(max < number[i]) {
            max = number[i];
            maxIndex = i;
        }
        if(min > number[i]) {
            min = number[i];
            minIndex = i;
        }
    }
    printf("avg = %f, max = %d (index %d), min = %d (index %d)\n", avg, max, maxIndex, min, minIndex);
} // 활용 2

int main(){
    
    exec2();
    
    return 0;
}