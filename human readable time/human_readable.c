#include <stdio.h>
char *human_readable_time(unsigned sec, char *time_string) {
	int m = sec/60;
	int s = sec%60;
	int h = m/60;
	m  = m/60;
	sprintf(time_string, "%02d:%02d:%02d", h,m,s);
	return time_string;
}
