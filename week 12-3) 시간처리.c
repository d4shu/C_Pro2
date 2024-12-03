//입력한 날짜의 해당 요일을 출력 / 입력한 날짜가 오늘로부터 며칠 남았는지(전인지) 출력

void_exec1(){
    
#include <stdio.h>
#include <time.h>
#include "report.h"

int main(int argc, char* argv[]){
    time_t current;
    struct tm* timeinfo;

    int year, month, day;
    char* WEEK[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};

    printf("Enter YYY MM DD : ");
    scanf("%d %d %d", &year, &month, &day);

    current = time(NULL);
    timeinfo= localtime(&current);

    timeinfo->tm_year = year-1900;
    timeinfo->tm_mon = month-1;
    timeinfo->tm_mday = day;

    mktime(timeinfo);

    printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);

    return 0;

}

}

void_exec2(){
    
#include <stdio.h>
#include <time.h>
#include "report.h"

int main(int argc, char* argv[]){
    week2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
}

}
