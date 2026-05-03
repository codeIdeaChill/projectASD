#pragma once 
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//init array
void initArray(int arr[], int* size);

// insert and delet and print an array
int insertAt(int arr[], int *size, int index, int value);
int deleteAt(int arr[], int* size, int index);
void printArray(int arr[], int size);

//search functions
int binarySearch(int arr[], int size, int value);
int linearSearch(int arr[], int size, int value);

//sorting functions
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void insertionSort(int arr[], int size);




int findMin(int arr[], int size);
int findMax(int arr[], int size);
double averageArray(int arr[], int size);
int sumArray(int arr[], int size);




