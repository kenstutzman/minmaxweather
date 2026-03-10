// today-foco-records.c
// Compile with:
//    gcc -o today-foco-records today-foco-records.c -Wall -O2
//
// Run:
//    ./today-foco-records

#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "focominmax.h"

// ────────────────────────────────────────────────

const FocoDailyRecord *find_record(int month, int day)
{
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return NULL;
    }

    for (int i = 0; i < FOCO_RECORDS_COUNT; i++) {
        const FocoDailyRecord *r = &foco_records[i];
        if (r->month == month && r->day == day) {
            return r;
        }
    }
    return NULL;
}

int main(void)
{
    time_t now = time(NULL);
    if (now == (time_t)-1) {
        fprintf(stderr, "time() failed\n");
        return 1;
    }

    struct tm *lt = localtime(&now);
    if (!lt) {
        fprintf(stderr, "localtime() failed\n");
        return 1;
    }

    int month = lt->tm_mon + 1;     // 0..11 → 1..12
    int day   = lt->tm_mday;        // 1..31
    int year  = lt->tm_year + 1900;

    printf("Fort Collins area temperature records\n");
    printf("Today: %04d-%02d-%02d\n\n", year, month, day);

    const FocoDailyRecord *rec = find_record(month, day);

    if (!rec) {
        printf("No record found for %02d/%02d\n", month, day);
        // Feb 29 will only be found in leap years
        if (month == 2 && day == 29) {
            printf("(Note: February 29 records exist only in leap years)\n");
        }
        return 1;
    }

    printf("Record high:  %3d °F   (%d)\n", rec->record_high, rec->record_high_year);
    printf("Record low:   %3d °F   (%d)\n", rec->record_low,  rec->record_low_year);

    return 0;
}
