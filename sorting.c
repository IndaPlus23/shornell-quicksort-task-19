#include <stdio.h>
#include <stdlib.h>
int read_num();
int main();
int partition();
int print_arr(int *arr, size_t sz_arr);
void just_sort();
void quick_sort();
void insertion_sort();


int main() {
 int count = read_num();
 int* to_sort = malloc(count * sizeof(int));
//  printf("count: %d", count);
//   printf("\n");
 for(int i = 0; i < count; i++) {
     to_sort[i] = read_num();
 }
// print_arr(to_sort, count);
// printf("\n");


just_sort(to_sort, 0, count);

print_arr(to_sort, count);

}

int read_num() {
    
    char str[50] = "";
    int idx = 0;
    char c;
    while ((c = getchar()) != 0x20 && c != EOF)
    {
        str[idx++] = c;
    }
    str[idx] = '\0';
    //print_arr(str,);
    return atoi(str);
}

int print_arr(int *arr, size_t sz_arr) {
    for(int i = 0; i < sz_arr; i++) {
    printf("%i ", arr[i]);
    } 
}

void print_array (int this_array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%i ", this_array[i]);
    };
    // printf("\n");
}

void insertion_sort(int that_array[], int array_size) {
    for (int sorted = 0; sorted < array_size - 1; sorted++) {
        int migrant = that_array[sorted + 1];
        int this_sorted = sorted;
        while (this_sorted > -1 && that_array[this_sorted] > migrant) {
            that_array[this_sorted + 1] = that_array[this_sorted];
            this_sorted --;
            that_array[this_sorted + 1] = migrant;
            // print_array(that_array, array_size);
        };
      
    };

}


int partition(int that_array[], int first, int last) {

    int mid = (first + last) / 2;
    if (that_array[mid] < that_array[first]) {
        int buffer = that_array[first];
        that_array[first] = that_array[mid];
        that_array[mid] = buffer;
    }
    if (that_array[last] < that_array[first]) {
        int buffer = that_array[first];
        that_array[first] = that_array[last];
        that_array[last] = buffer;
    }
    if (that_array[mid] < that_array[last]) {
        int buffer = that_array[mid];
        that_array[mid] = that_array[last];
        that_array[last] = buffer;
    }
    int pivot_value = that_array[last];

    int last_low = first - 1;
    int exchange_value;
    
    for (int last_high = first - 1; last_high <= last - 1; last_high++) {
        if (that_array[last_high + 1] < pivot_value) {
            last_low ++;
            exchange_value = that_array[last_high + 1];
            that_array[last_high + 1] = that_array[last_low];
            that_array[last_low] = exchange_value;
        }
        //  print_array(that_array, last + 1);
        
    }

    exchange_value = that_array[last_low + 1];
    that_array[last_low + 1] = that_array[last];
    that_array[last] = exchange_value;

    return last_low + 1;
}

void quick_sort(int that_array[], int start, int end) {
    if (start < end) {
        int mitten = partition(that_array, start, end);
        quick_sort(that_array, start, mitten - 1);
        quick_sort(that_array, mitten + 1, end);
    };
}

void just_sort(int that_array[], int start, int array_size) {
    if (array_size < 15) {
        insertion_sort(that_array, array_size);
    } 
    else {
        quick_sort(that_array, start, array_size - 1);
    }
}
