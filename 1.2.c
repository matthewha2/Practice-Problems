// Check Permutation
// Given two strings, write a method to decide if one is a permutation of the other.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_permutation(char * first, char * second){

  if(strlen(first) != strlen(second)) //checking if same length -- if not then can't be permutation                                                                                  
    return false;

  int hash_table[128]; // all possible chars assuming ASCII                                                                                                                          

  for(int a=0;a<128;a++){ // setting all char frequencies to 0                                                                                                                       
    hash_table[a] = 0;
  }

  int size = strlen(first);

  for(int i=0;i<size;i++){
    int temp = first[i]; // 'hash' each char into its ASCII/int value                                                                                                                
    hash_table[temp]++; // indicate how many of each char has been seen                                                                                                              
  }
  for(int j=0;j<size; j++){
    int temp_2 = second[j];
    hash_table[temp_2]--; // decrement the char frequency                                                                                                                            
  }

  for(int k=0;k<128;k++){
    if (hash_table[k] != 0) // if each char has been incremented and decremented the same amount (if all 0's then permutation)                                                       
      return false;
  }

  return true; // all 0's in char 'hash-table' -- is a permutation                                                                                                                   
}

int main(){

  char * first = NULL;
  char * second = NULL;
  size_t len = 0;

  printf("Please use all lower-case!\n");
  printf("Enter string 1: ");
  getline(&first,&len,stdin);
  printf("Enter string 2: ");
  getline(&second,&len,stdin);

  bool result = is_permutation(first,second);

  if (result == true)
    printf("Yes, it is a permutation!\n");
  else
    printf("No, it is not a permutation!\n");



  return 0;
}

