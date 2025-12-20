// figure out how many times does the dial turn to 0
// open the input file
// cicle through the input file until you get to the end of file
//
// How does the dial works?
// it's clock like, goes from 99 to 0, turning it to the right will increase the numbers, turning it to the left will decrease the numbers
// the objective is to figure out how many times does the dial reach 0

#define INPUT "input.txt"
#define DEFAULT_START 50
#define MAX_DIAL 99
#define MIN_DIAL 0
#define DIAL_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int dial = DEFAULT_START;
    printf("The dial starts by pointing at %d\n", dial);
    int move;
    int hit_zero = 0;
    char line[12]; // R001\n
    FILE *file = fopen(INPUT, "r");
    if (file  == NULL)
    {
        printf("Input file absent or corrupted.");
        return 1;
    }

    while (fgets(line,sizeof(line), file))
    {
        line[strcspn(line, "\n")] = '\0';
        move = atoi(line+1);

        for (int i = 0; i < move; i++)
        {
            if (line[0] == 'L')
            {
                dial -= 1;
            }
            else
            {
                dial += 1;
            }
            printf("Rotation: %c%d. Dial points to %d.\n", line[0], 1 ,dial % 100);

            if ((dial % 100) == 0)
            {
                hit_zero++;
            }
        }
    }
    printf("How many times the dial hit 0: %d\n", hit_zero);
    fclose(file);

    return 0;
}
