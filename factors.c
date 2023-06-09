#include <stdio.h>
#include <stdlib.h>

void factorize(long long int n) {
    long long int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%lld=%lld*%lld\n", n, n / i, i);
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

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        if (line[0] > '0' && line[0] <= '9' && line[0] != '\n')
            factorize(atoll(line));
        else
            break;
    }

    fclose(file);
    return 0;
}
