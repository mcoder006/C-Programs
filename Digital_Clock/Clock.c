#include <stdio.h>
#include <time.h>
#include <unistd.h>

struct tm *current_time;

void fill_time(char *bufferTime, int timeFormat) {
    struct tm *current_time;
    time_t raw_time;
    
    while (1) {
        time(&raw_time);
        current_time = localtime(&raw_time);
        
        if (timeFormat == 1) {
            strftime(bufferTime, 100, "%H:%M:%S %p", current_time);
        } else {
            strftime(bufferTime, 100, "%I:%M:%S %p", current_time);
        }
        
        printf("Current Time: %s\r", bufferTime); // \r to overwrite the previous time
        fflush(stdout); // Flush the output buffer to ensure the time is printed immediately
        
        sleep(1); // Wait for 1 second before updating the time
    }
}

void fill_date(char *date) {
    time_t raw_time;
    
    time(&raw_time);
    
    current_time = localtime(&raw_time);
    
    strftime(date, 50, "%A %B %d %Y", current_time);
    
    printf("Current Date: %s\n\n", date);
}

int main()
{
	char time[100], date[50];
	
	int choice;
    
//    fill_time(time);

	printf("Choose the time format : ");
	printf("\n1. 24 Hours format! \n2. 12 Hour Format (default).\n");
	scanf("%d", &choice);
	
	fill_time(&time, choice);
	fill_date(&date);
    
    printf("Developed By: Sushank Ghimire\n\n");
    return 0;
}
