#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(0, "");
    FILE *file;
    int array[5][5];
    int size = 0;
    int i = 0;
    int j = 0;

    if ((file = fopen("input.txt", "r")) == NULL)
    {
        printf("\noFile not found.\n");
        return 1;
    }

    for (int k = 0; k < 5; k++)
    {

        for (int l = 0; l < 5; l++)
        {
            fscanf(file, "%d", &array[k][l]);
        }
    }
    for (int k = 0; k < 5; k++)
    {
        for (int l = 0; l < 5; l++)
            printf("%d ", array[k][l]);
        printf("\n");
    }

    fclose(file);

    FILE *out = fopen("output.dot", "w");

    fprintf(out, "graph{\n");

    for (i; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            if (array[i][j] >= 1)
            {
                fprintf(out, "%d -- %d;\n", i, j);
            }
        }
    }
    fprintf(out, "}");

    fclose(out);

    j = j - 1;
    if(j > (( i - 1 )*( i - 2 )/ 2)){
        printf("This is a linked graph. Edges: %d, peaks: %d \n", j, i);
    }else{
        printf("This is an unrelated graph. Edges: %d, peaks: %d \n", j, i);
    }

    system("dot output.dot -Tpng -o image.png");
    return 0;
}
