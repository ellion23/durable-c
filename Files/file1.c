#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_COUNTRY_LENGTH 50
#define MAX_PRODUCT_NAME_LENGTH 50

struct Record {
    char country[MAX_COUNTRY_LENGTH];
    char product_name[MAX_PRODUCT_NAME_LENGTH];
    double export_volume;
};

int read_records(char *filename, struct Record *records, int max_records) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Не удалось открыть файл '%s'.\n", filename);
        return 0;
    }

    int i = 0;
    while (i < max_records && fscanf(file, "%s %s %lf", records[i].country, records[i].product_name, &records[i].export_volume) == 3) {
        i++;
    }

    fclose(file);
    return i;
}
