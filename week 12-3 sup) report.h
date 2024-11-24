#ifndef _12_3_REPORT_H
#define _12_3_REPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void week2(int year, int month, int day) {
    time_t current;
    struct tm* timeinfo;

    current = time(NULL);
    timeinfo = localtime(&current);

    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    mktime(timeinfo);

    double diff = difftime(mktime(timeinfo), current);
    int dayDiff = diff / (60 * 60 * 24);

    if (dayDiff > 0) {
        printf("%d %d %d -> 오늘로부터 %d일 후 입니다.\n", year, month, day, dayDiff);
    } else if (dayDiff < 0) {
        printf("%d %d %d -> 오늘로부터 %d일 전 입니다.\n", year, month, day, dayDiff);
    } else {
        printf("오늘입니다 !\n");
    }
}

#endif