#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Export {
    char country[50];
    char name[50];
    char exp[50];
};

void read_file(char *filename, struct Export *exports) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Не удалось открыть файл '%s'.\n", filename);
    }
    int i = 0;
    while (!feof(file)) {

        fscanf(file, "%s %s %s", exports[i].country, exports[i].name, exports[i].exp);
        i++;
    }
    

    fclose(file);
}

int main() {
    int i, j;
    char *filename, *str;


    /* Считываем название файла с данными */
    printf("Input file name: ");
    scanf("%s", filename);

    struct Export exps;

    read_file(filename, )
    
    

  
    return 0;
}

