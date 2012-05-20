// How many Sundays fell on the first of the month during the twentieth century?

#include <stdio.h>

struct date {
  int year;
  int month;
  int day;
};

int main () {
  void incrementDate(struct date *d);
  void incrementDayOfWeek(int *i);
  
  char day_strs[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday",
    "Friday", "Saturday", "Sunday"};
  
  struct date d = {1901, 1, 1};
  int sunday_on_first_count = 0;
  
  // 0 = Monday, and increments every day (6 = Sunday)
  int day_of_week = 1;

  while (d.year < 2001) {
    if (day_of_week == 6 /* sunday */ && d.day == 1) {
      sunday_on_first_count++;
    }
    incrementDate(&d);
    incrementDayOfWeek(&day_of_week);
  }
  
  printf("%i/%i/%i is a %s\n", d.year, d.month, d.day, day_strs[day_of_week]);
  printf("Number of Sundays: %i\n", sunday_on_first_count);
  
  return 0;
}

void incrementDate(struct date *d) {
  // Last day of month (index 0 is null)
  int last_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  // Check for leap year
  if (d->month == 2) {
    if ( (d->year % 4 == 0) && (d->year % 100 != 0) ||
         (d->year % 400 == 0) ) {
      last_day[2] = 29;
    }
  }
  
  if (d->day == last_day[d->month]) {
    if (d->month == 12) {
      d->year++;
      d->month = 1;
    } else {
      d->month++;
    }
    
    d->day = 1;
    return;
  }
  
  d->day++;
}

void incrementDayOfWeek(int *i) {
  if (*i == 6) {
    *i = 0;
  } else {
    *i += 1;
  }
}