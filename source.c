#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    
    FILE *file;
    int array[WIDTH][HEIGHT];
    int size = 0;
    int i = 0;
    int j = 0; //вершины
    int edges = 0; //ребра

    if ((file = fopen("input.txt", "r")) == NULL)
    {
        puts("\noFile not found.\n");
        return 1;
    }

    for (int k = 0; k < HEIGHT; k++)
    {

        for (int l = 0; l < WIDTH; l++)
        {
            fscanf(file, "%d", &array[k][l]);
            printf("%d ", array[k][l]);
        }
        putchar('\n');
    }

    fclose(file);

    FILE *out = fopen("output.dot", "w");

    fputs("graph{", out);

    for (int k = 0; k < WIDTH; k++)
    {
        fprintf(out, "%d;\n", k);
    }

    for (i; i < HEIGHT; i++)
    {
        for (j = i; j < WIDTH; j++)
        {
            if (array[i][j] >= 1 && i != j)
            {
                fprintf(out, "%d -- %d;\n", i, j);
                edges++;
            }
        }
    }
    fputs("}", out);

    fclose(out);

    if(edges >= (( j - 1 )*( j - 2 )/ 2)){
        printf("This is a linked graph. Edges: %d, peaks: %d \n", edges, j);
    }
    else
    {
        printf("This is an unlinked graph. Edges: %d, peaks: %d \n", edges, j);
    }

    system("dot output.dot -Tpng -o image.png");
    return 0;
}

