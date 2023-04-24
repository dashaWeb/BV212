#pragma once
#include <iostream>
//#include <string>
//using namespace std;

using std::string;
using std::cout;
using std::cin;
using std::endl;


// fill
void fillArray(int arr[], size_t length, int min = 1, int max = 20);
void fillArray(double arr[], size_t length, int min = 1, int max = 20);
void fillArray(char arr[], size_t length);
void fillArray(string arr[], size_t length);


// print
void printArray(int arr[], size_t length);
void printArray(double arr[], size_t length);
void printArray(char arr[], size_t length);
void printArray(string arr[], size_t length);


// 