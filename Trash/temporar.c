#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fatal(const char* msg) {
    fprintf(stderr, "%s", msg);
    exit(1);
}

void value_swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void value_print(FILE* f, const int* v) {
    fprintf(f, "%d", *v);
}

int value_rnd() {
    return rand() % 100;
}

typedef struct {
    int* values;
    int size;
} array_t;

typedef struct {
    double compares;
    double swaps;
} stats_t;

void array_print(FILE* f, array_t* arr) {
    fprintf(f, "[");
    for (int i = 0; i < arr->size; i++) {
        if (i > 0) fprintf(f, ",");
        value_print(f, &arr->values[i]);
    }
    fprintf(f, "]\n");
}

array_t array_create_empty() {
    array_t a = {};
    a.values = NULL;
    a.size = 0;
    return a;
}

void array_append(array_t* arr, int val) {
    int* tmp = realloc(arr->values, (arr->size + 1) * sizeof(int));
    if (tmp == NULL) fatal("out of memory!");
    tmp[arr->size] = val;
    arr->values = tmp;
    arr->size++;
}

void array_reverse(array_t* arr) {
    for (int i = 0; i < arr->size / 2; i++)
        value_swap(&arr->values[i], &arr->values[arr->size - 1 - i]);
}

array_t array_create_random(int size) {
    array_t a = {};
    a.values = calloc(size, sizeof(int));
    a.size = size;
    for (int i = 0; i < size; i++) {
        a.values[i] = value_rnd();
    }
    return a;
}

array_t array_create_copy(array_t* src) {
    array_t a = {};
    a.values = calloc(src->size, sizeof(int));
    a.size = src->size;
    for (int i = 0; i < src->size; i++) {
        a.values[i] = src->values[i];
    }
    return a;
}


void array_free(array_t* arr) {
    free(arr->values);
}

void array_validate_sorted(array_t* arr) {
    for (int i = 1; i < arr->size; i++) {
        if (arr->values[i] < arr->values[i - 1]) {
            array_print(stderr, arr);
            fatal("array was not sorted properly!\n");
        }
    }
}

void do_merge_direct(int* values, int* aux, int left, int mid, int right, stats_t* stats) {
    int k = left;
    int i1 = left;
    int i2 = mid + 1;

    // пока есть элементы в левом и правом прогонах
    while ((++stats->compares && i1 <= mid) && (++stats->compares && i2 <= right)) {
        ++stats->compares;
        if (values[i1] <= values[i2]) {
            aux[k++] = values[i1++];
        } else {
            aux[k++] = values[i2++];
        }
        ++stats->swaps;
    }

    // копируем оставшиеся элементы в левой половине
    while (++stats->compares && i1 <= mid) {
        ++stats->swaps;
        aux[k++] = values[i1++];
    }

    // копируем обратно в исходный массив
    for (int i = left; i <= right; i++) {
        stats->compares++;
        stats->swaps++;
        values[i] = aux[i];
    }
}

void merge_desc_direct_recurse(int* a, int* aux, int l, int r, stats_t* stats) {
    if (r <= l) return;
    int m = (r + l) / 2;
    merge_desc_direct_recurse(a, aux, l, m, stats);
    merge_desc_direct_recurse(a, aux, m + 1, r, stats);
    do_merge_direct(a, aux, l, m, r, stats);
}

void merge_desc_direct(array_t* arr, stats_t* stats) {
    stats->compares = stats->swaps = 0;
    array_t aux = array_create_copy(arr);
    merge_desc_direct_recurse(arr->values, aux.values, 0, arr->size - 1, stats);
    array_free(&aux);
}

#define TEST_FROM 100
#define TEST_TO 10000
#define TEST_STEP 100
#define REPEAT_TIMES 5

int test_user_input_random() {
    int size;
    printf("enter array size: ");
    if (scanf_s("%d", &size) != 1 || size < 1) {
        fatal("bad input!");
    }
    stats_t stats = {0, 0};
    array_t arr = array_create_random(size);
    printf("\nsource:\n");
    array_print(stdout, &arr);
    printf("\nsorted:\n");
    merge_desc_direct(&arr, &stats);
    array_print(stdout, &arr);
    array_free(&arr);
    return 0;
}

int sort_to_file() {
    FILE* output = fopen("out.csv", "w");
    stats_t avg = {0, 0};
    stats_t cur = {0, 0};
    for (int size = TEST_FROM; size <= TEST_TO; size += TEST_STEP) {
        for (int repeat = 0; repeat < REPEAT_TIMES; repeat++) {
            array_t arr = array_create_random(size);
            merge_desc_direct(&arr, &cur);
            avg.compares += cur.compares;
            avg.swaps += cur.swaps;
            array_free(&arr);
        }
        avg.compares /= REPEAT_TIMES;
        avg.swaps /= REPEAT_TIMES;
        fprintf(output, "%d; %d\n", size, (int) (avg.compares + avg.swaps));
        printf("size=%d compares=%d swaps=%d\n", size, (int) avg.compares, (int) avg.swaps);
    }
    fclose(output);
    return 0;
}

void test() {
    array_t arr = array_create_random(10000);
    stats_t stats;
    merge_desc_direct(&arr, &stats);
    array_validate_sorted(&arr);
    printf("size=%d compares=%d swaps=%d\n", arr.size, (int) stats.compares, (int) stats.swaps);
    //array_print(stdout, &arr);
    array_free(&arr);
}

int main() {
    srand(time(NULL));

    //test();
    //sort_to_file();
    test_user_input_random();

    return 0;
}