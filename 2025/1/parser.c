#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 5000
#define COLS 2
#define STEP 99

// Function to process the data array and return a password
int password(int data[][COLS], int row_count) {
    int result = 0;
    int pos = 50;  // Start position

    for (int i = 0; i < row_count; i++) {
        int step = data[i][1] % 100;
        int cross = 0;

        // Handle rotation based on direction
        if (data[i][0] == 0) {
            // Left rotate
            if (step > pos) {
                cross = (pos != 0);
                pos = STEP - (step - pos) + 1;
            } else {
                pos -= step;
            }
        } else {
            // Right rotate
            if (pos + step > STEP) {
                pos = pos + step - (STEP + 1);
                cross = (pos != 0);
            } else {
                pos += step;
            }
        }

        // Check if landed on position 0
        cross = (pos == 0) ? 1 : cross;
        result += cross + data[i][1] / 100;

        printf("%d\t%d\t%d\n", i, result, pos);
    }

    return result;
}

int main() {
    int data[MAX_ROWS][COLS];
    int row_count = 0;

    FILE *file = fopen("input", "r");
    if (!file) {
        printf("Error: Could not open file 'input'\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) && row_count < MAX_ROWS) {
        line[strcspn(line, "\n")] = 0;  // Remove newline

        if (strlen(line) == 0) continue;

        // Parse direction: L = 0, R = 1
        if (line[0] == 'L') {
            data[row_count][0] = 0;
        } else if (line[0] == 'R') {
            data[row_count][0] = 1;
        } else {
            printf("Warning: Invalid character '%c' at row %d\n", line[0], row_count + 1);
            continue;
        }

        data[row_count][1] = atoi(&line[1]);
        row_count++;
    }

    fclose(file);

    int pwd = password(data, row_count);
    printf("\nresult: %d\n", pwd);

    return 0;
}
