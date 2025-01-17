#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
extern char *tzname[];

int main(){
    time_t now;

    setenv("TZ", "America/Los_Angeles", 1);
    tzset();
    
    struct tm *sp;
    now =  time(NULL);
    printf("%s", ctime( &now ) );
    sp = localtime(&now);
    printf("%d/%d/%02d %d:%02d %s\n",
        sp->tm_mon + 1, sp->tm_mday,
        sp->tm_year -100, sp->tm_hour,
        sp->tm_min, tzname[sp->tm_isdst]);
    exit(0);
}
