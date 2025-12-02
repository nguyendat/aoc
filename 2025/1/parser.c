#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 5000
#define COLS 2
#define STEP 99

// Function to process the data array and return a password
int password(int data[][COLS], int row_count) {
    // TODO: Implement your password logic here
    // This is a placeholder implementation
    int result = 0;
    // Always start at 50
    int current_index = 50; 
    int actual = 0;

    // Example: Sum all values in the array
    for (int i = 0; i < row_count; i++) {
        actual = data[i][1] % 100;

        if (data[i][0] == 0) {
            // Left rorate
            if (actual > current_index) {
                current_index = STEP - ((actual - current_index)) + 1;
            } else {
                current_index = current_index - actual;
            }
        } else {
            // Right rotate
            if (actual + current_index > STEP) {
                current_index = actual + current_index - (STEP + 1); 
            } else {
                current_index = current_index + actual;
            }
        }

        if (current_index == 0) {
            result += 1;
        }

    }

    return result;
}

int main() {
    // 2D array to store the data
    int data[MAX_ROWS][COLS];
    int row_count = 0;

    // Open the input file
    FILE *file = fopen("input", "r");
    if (file == NULL) {
        printf("Error: Could not open file 'input'\n");
        return 1;
    }

    char line[100];

    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL && row_count < MAX_ROWS) {
        // Remove trailing newline if present
        line[strcspn(line, "\n")] = 0;

        // Check if line is not empty
        if (strlen(line) > 0) {
            // First character: L = 0, R = 1
            if (line[0] == 'L') {
                data[row_count][0] = 0;
            } else if (line[0] == 'R') {
                data[row_count][0] = 1;
            } else {
                printf("Warning: Invalid first character '%c' at row %d\n", line[0], row_count + 1);
                continue;
            }

            // Parse the remaining number
            int number = atoi(&line[1]);
            data[row_count][1] = number;

            row_count++;
        }
    }

    fclose(file);

    // // Print the results
    // printf("Successfully parsed %d rows\n\n", row_count);
    // printf("Sample of first 10 rows:\n");
    // printf("Row\tDirection\tValue\n");
    // printf("---\t---------\t-----\n");

    // for (int i = 0; i < (row_count < 10 ? row_count : 10); i++) {
    //     printf("%d\t%d (=%c)\t\t%d\n",
    //            i + 1,
    //            data[i][0],
    //            (data[i][0] == 0 ? 'L' : 'R'),
    //            data[i][1]);
    // }

    // if (row_count > 10) {
    //     printf("...\n");
    //     printf("Last row:\n");
    //     printf("%d\t%d (=%c)\t\t%d\n",
    //            row_count,
    //            data[row_count-1][0],
    //            (data[row_count-1][0] == 0 ? 'L' : 'R'),
    //            data[row_count-1][1]);
    // }

    // Call the password function
    int pwd = password(data, row_count);
    printf("\nresult: %d\n", pwd);

    return 0;
}
