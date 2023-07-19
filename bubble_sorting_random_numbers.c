#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int *arr, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int P,Q,N,D;
    printf("Enter the range of numbers\n");
    scanf("%d %d",&P,&Q);
    printf("Enter the number of random numbers to be generated between %d and %d\n",P,Q);
    scanf("%d",&N);
    srand(time(NULL));
    int random_numbers[N];
    for (int i=0; i<N; i++)
        random_numbers[i]=rand()%(Q-P+1)+P;
    FILE *fp;
    fp=fopen("input_file.txt","w");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    for (int i=0; i<N; i++)
        fprintf(fp,"%d\n",random_numbers[i]);
    printf("Random numbers generated and stored in input file.\n\n\n");
    fclose(fp);





    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubbleSort(random_numbers, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    FILE *output_file;
    output_file = fopen("bubble_sorted_output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file!");
        exit(1);
    }

    // Write the sorted numbers to the output file
    for (int i = 0; i < N; i++) {
        fprintf(output_file, "%d\n", random_numbers[i]);
    }
    printf("Numbers sorted and stored in Output_file.\n");
    fclose(output_file);
    printf("\n\n\nCPU time used: %f seconds\n", cpu_time_used);
    return 0;
}
