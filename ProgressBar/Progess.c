#include <stdio.h>
#include <unistd.h>

void progressBar(int totalTime)
{
    const int barWidth = 50;
    int i;
    for (i = 0; i <= totalTime; i++)
    {
        float progress = (float)i / totalTime;
        int pos = (int)(barWidth * progress);

        printf("[");
        for (int j = 0; j < barWidth; j++)
        {
            if (j < pos)
                printf("=");
            else if (j == pos)
                printf(">");
            else
                printf(" ");
        }
        printf("] %d%%\r", (int)(progress * 100));
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int main()
{
    int times[] = {3, 5, 7}; 
    int numTimes = sizeof(times) / sizeof(times[0]);

    for (int i = 0; i < numTimes; i++)
    {
        printf("Progress bar for %d seconds:\n", times[i]);
        progressBar(times[i]);
        printf("\n");
    }

    return 0;
}
