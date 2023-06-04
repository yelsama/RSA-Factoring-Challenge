#include <stdio.h>
#include <stdlib.h>

void factorize(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
			return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line && line[0] != '\n')
            factorize(atoi(line));
    }

    fclose(file);
    return 0;
}
