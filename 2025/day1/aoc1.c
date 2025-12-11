// figure out how many times does the dial turn to 0
// open the input file
// cicle through the input file until you get to the end of file
//
// How does the dial works?
// it's clock like, goes from 99 to 0, turning it to the right will increase the numbers, turning it to the left will decrease the numbers
// the objective is to figure out how many times does the dial reach 0

#define INPUT "input"
#define DEFAULT_START 50

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start = DEFAULT_START;
    printf("The dial starts by pointing at %d\n", start);
    int reached_zero = 0;
    char line[8]; // R001\n
    FILE *file = fopen(INPUT, "r");
    while (fgets(line,sizeof(line), file))
    {
        int num = atoi(line+1);
        if (line[0] == 'R')
        {
            start = (start + num) % 100;
        }
        else if (line[0] == 'L')
        {
           start = (start - num + 100) % 100;
        }
        if (start == 0)
        {
            reached_zero++;
        }
        printf("The dial is rotated %c%d to point at %d.\n", line[0], num ,start);
    }
    printf("Times reached 0: %d\n", reached_zero);

    return 0;
}
