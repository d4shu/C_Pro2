#include <stdio.h>
#include <time.h>

int main() {
    int year, month, day;
    printf("목표 날짜를 입력하세요 (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    struct tm target_date = {0};
    target_date.tm_year = year - 1900;  
    target_date.tm_mon = month - 1;    
    target_date.tm_mday = day;

    time_t now = time(NULL);
    struct tm *current_date = localtime(&now);

    time_t target_time = mktime(&target_date);
    double seconds_diff = difftime(target_time, now);
    int days_diff = (int)(seconds_diff / (60 * 60 * 24)); 

    if (days_diff > 0) {
        printf("D-%d\n", days_diff);
    } else if (days_diff == 0) {
        printf("오늘은 D-day입니다!\n");
    } else {
        printf("D+%d\n", -days_diff);
    }

    return 0;
}
