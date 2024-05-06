#include <stdio.h>
#include <unistd.h>

void progressBar(int totalTime)
{
    const int barWidth = 50;
    int i;
    float progress;

    for (i = 0; i <= totalTime; i++)
    {
        progress = (float)i / totalTime;
        int pos = (int)(barWidth * progress);

        printf("[");
        int j; // Move the declaration of 'j' outside the loop
        for (j = 0; j < barWidth; j++)
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
    int times[] = {3, 5, 7}; // Different times for progress bars
    int numTimes = sizeof(times) / sizeof(times[0]);

    int i; // Move the declaration of 'i' outside the loop
    for (i = 0; i < numTimes; i++)
    {
        printf("Progress bar for %d seconds:\n", times[i]);
        progressBar(times[i]);
        printf("\n");
    }

    printf("Developed By: Sushank Ghimire\n\n");

    return 0;
}
