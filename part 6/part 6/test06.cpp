#include "intarray.hpp"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void addition(IntArray&, int, char*);

void remove_left(IntArray&, int, char*);
void remove_right(IntArray&, int, char*);

void get_low(IntArray&, char*);
void get_high(IntArray&, char*);
void get_size(IntArray&, char*);

void get_element_at_index(IntArray& array, int index, char* name);
void put_element_at_index(IntArray& array, int index, int value, char* name);

void print_array(IntArray& array);

int main (void) {
    
    char name1[] = "parray01";
    char name2[] = "parray02";
    
    IntArray parray01;
    
    printf("IntArray %s\nOK\n", name1);
    
    print_array(parray01);
    
    get_low(parray01, name1);
    
    addition(parray01, 5, name1);
    
    remove_left(parray01, 10, name1);
    
    print_array(parray01);
    
    addition(parray01, 2, name1);
    
    IntArray parray02(5);
    
    printf("IntArray %s(5)\n",name2);
    
    print_array(parray02);
    
    addition(parray02, 1, name2);
    
    get_high(parray02, name2);
    
    get_size(parray02, name2);
    
    put_element_at_index(parray01, 2, 999, name1);
    
    get_element_at_index(parray02, 10, name2);
    
    get_element_at_index(parray01, 1, name1);
    
    parray01.~IntArray();
    
    printf("%s = %s == OK\n", name2, name1);
    
    print_array(parray02);

    return 0;
}


void addition(IntArray& array, int number, char* name) {

    for (int i = 0; i < number; i++) {

        if (i%2) {
                
                try{
                    i + array;
                    printf("%d + %s == OK\n", i, name);
                    print_array(array);
                }
                catch(IntDeque::NoMemory){
                    printf("%d + %s == No Memory!\n", i, name);
                }

        } else {

            try{
                array + i;
                printf("%s + %d == OK\n", name, i);
                print_array(array);
            }
            catch(IntDeque::NoMemory){
                printf("%s + %d == No Memory!\n", name, i);
            }
        }
    }
    printf("\n");

}


void remove_left(IntArray& array, int number, char* name) {

    for (int i = 0; i < number; i++) {

        try{
            printf("--%s == %d\n", name, --array);
            print_array(array);
        }
        catch(IntArray::ArrayIsEmpty){
            printf("--%s == Array is empty!\n", name);
            print_array(array);
        }
    }

    printf("\n");
}

void remove_right(IntArray& array, int number, char* name) {


    for (int i = 0; i < number; i++) {

        try{
            printf("%s-- == %d\n", name, array--);
            print_array(array);
        }
        catch(IntArray::ArrayIsEmpty){
            printf("%s-- == Array is empty!\n", name);
            print_array(array);
        }

    }

    printf("\n");
}


void get_low(IntArray& array, char* name) {
    
    try {
        
        printf("%s.Low() == %d\n", name, array.Low());
        
    } catch (IntArray::ArrayIsEmpty) {
        
        printf("%s.Low() == ArrayIsEmpty\n", name);
        
    }
    print_array(array);
    
}

void get_high(IntArray& array, char* name) {
    
    try {
        
        printf("%s.High() == %d\n", name, array.High());
        
    } catch (IntArray::ArrayIsEmpty) {
        
        printf("%s.High() == ArrayIsEmpty\n", name);
        
    }
    
    print_array(array);
}

void get_size(IntArray& array, char* name) {
    
    printf("%s.Size() == %d\n", name, array.Size());
    print_array(array);
    
}

void get_element_at_index(IntArray& array, int index, char* name) {
    
    try {
        
        printf("%s[%d] == %d\n", name, index, array[index]);
        
    } catch (IntArray::ArrayIsEmpty) {
        
        printf("%s[%d] == ArrayIsEmpty\n", name, index);
        
    } catch (IntArray::WrongIndex) {
        
        printf("%s[%d] == WrongIndex\n", name, index);
        
    }
    print_array(array);
    
    
}

void put_element_at_index(IntArray& array, int index, int value, char* name){
    
    try {
        
        printf("%s[%d] = %d == OK\n", name, index, array[index] = value);
        
    } catch (IntArray::ArrayIsEmpty) {
        
        printf("%s[%d] = %d ArrayIsEmpty\n", name, index, value);
        
    } catch (IntArray::WrongIndex) {
        
        printf("%s[%d] = %d WrongIndex\n", name, index, value);
        
    }
    print_array(array);

    
}


void print_array(IntArray& array) {
    
    if (!array.Size()) {
        printf("++\n!!\n++\n-\n\n");
    } else {
    
        for (int i = array.Low(); i <= array.High(); i++) {
            
            printf("+------");
            
        }
        
        printf("+\n!");
        
        for (int i = array.Low(); i <= array.High(); i++) {
            
            printf("%6d!", array[i]);
            
        }
        
        printf("\n");
        
        for (int i = array.Low(); i <= array.High(); i++) {
            
            printf("+------");
            
        }
        
        printf("+\n");
        
        for (int i = array.Low(); i <= array.High(); i++) {
            
            printf("%7d", i);
        
        }
        
        printf("\n\n");
        
    }
}
