#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the number of numbers to sort
    int X = 10;

    // Open the input file for reading
    FILE *input_file;
    input_file = fopen("N_random_numbers_input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!");
        exit(1);
    }

    // Read the numbers from the input file into an array
    int numbers[X];
    for (int i = 0; i < X; i++) {
        fscanf(input_file, "%d", &numbers[i]);
    }
    fclose(input_file);

    // Sort the array of numbers
    for (int i = 0; i < X - 1; i++) {
        for (int j = i + 1; j < X; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Open the output file for writing
    FILE *output_file;
    output_file = fopen("input_sort_output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file!");
        exit(1);
    }

    // Write the sorted numbers to the output file
    for (int i = 0; i < X; i++) {
        fprintf(output_file, "%d\n", numbers[i]);
    }
    fclose(output_file);

    return 0;
}
