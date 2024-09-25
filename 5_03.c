#include <stdio.h>
#include <string.h>

int main()
{
    char input[200] = "";
    int count[26] = {0};
    int upper_count[26] = {0};
    int num_count[10] = {0};
    int special_count = 0;
    int ch;
    int i = 0;

    while((ch = getchar()) != EOF){
        input[i++] = ch;
    }

    i = 0;
    while(input[i] != '\0'){
        if(input[i] >= 'a' && input[i] <= 'z'){
            count[input[i] -'a']++;
        }
        else if(input[i] >= 'A' && input[i] <= 'Z'){
            upper_count[input[i] - 'A']++;
        }
        else if (input[i] >= '0' && input[i] <= '9') {
            num_count[input[i] - '0']++;
        }
        else if (input[i] >= 32 && input[i] <= 126) {
            special_count++;
        }
        i++;
    }

    printf("\n입력문자열 : %s\n", input);

    for (int i = 0; i < 26; i++) {
            printf("%c 출현 횟수 : %d\n", 'a' + i, count[i]);
    }
    for (int i = 0; i < 26; i++) {
            printf("%c 출현 횟수 : %d\n", 'A' + i, upper_count[i]);
    }
    for (int i = 0; i < 10; i++) {
            printf("%d 출현 횟수 : %d\n", i, num_count[i]);
    }
    printf("특수문자 출현 횟수 : %d\n", special_count);

    return 0;
}