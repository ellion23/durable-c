void find_record_by_product_name_and_export_volume(struct Record *records, int num_records, char *product_name, double export_volume) {
    printf("Список для товара %s и объема экспорта %lf:\n", product_name, export_volume);
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].product_name, product_name) == 0 && records[i].export_volume == export_volume) {
            printf("%s %s %lf\n", records[i].country, records[i].product_name, records[i].export_volume);
        }
    }
}
