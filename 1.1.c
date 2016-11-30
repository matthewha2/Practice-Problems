//Is Unique
//Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
bool is_unique_BRUTE_FORCE(char * unique, int size){  // 0(n^2) runtime -- but no additional space needed
  
  if (size > 128) // assuming ASCII, cannot have unique if more than 128
    return false; 
   
  for (int i=0;i<size;i++) // iterates through whole array
    for (int x=i+1;x<size;x++) // iterates through sub_array - whats already been compared
      if (unique[i] == unique[x])
	return false; // found duplicate -- not unique

  return true; // no duplicates found -- unique
}
*/
/*
void merge (char * array, int left, int middle, int right){ // merge sub arrays -- part of merge sort
  
  char temp_array[right - left + 1];
  int finger = 0;
  int left_finger = left;
  int right_finger = middle + 1;

  while(left_finger <= middle && right_finger <= right)
    {
      if(array[left_finger] <= array[right_finger])
	{
	  temp_array[finger++] = array[left_finger++];
	}
      else
	{
	  temp_array[finger++] = array[right_finger++];
	}
    }
	  
  while(left_finger <= middle)
    {
      temp_array[finger++] = array[left_finger++];
    }
  
  while(right_finger <= right)
    {
      temp_array[finger++] = array[right_finger++];
    }
  
  int clean_up;
  for (clean_up=0;clean_up<finger;clean_up++)
    {
      array[clean_up+left] = temp_array[clean_up];
    }
  return;
}
*/

/*
void merge_sort(char * array, int left, int right){ // merge sort

  if (left < right)
    {
      int middle = (left + right)/2;

      merge_sort(array,left,middle);
      merge_sort(array,middle+1,right);

      merge(array,left,middle,right);
    }
}
*/

/*
bool is_unique_SORT(char * unique) // 0(nlogn) runtime -- extra space needed but modifies original string
{  
  int size = strlen(unique)-1;
  
  if (size > 128) // assuming ASCII, cannot have unique if more than 128
    return false;
  
  merge_sort(unique,0,size);
  
  for (int i=0;i<size;i++) // for the whole array
    if (unique[i] == unique[i+1]) // found duplicate neighbor
      return false; // found duplicate -- not unique

  return true; // no duplicates found -- unique  
}
*/

bool is_unique_HASH(char * unique) // 0(n) runtime -- extra space for 'boolean hash table'
{
  int size = strlen(unique);
  int value; // to store hashed value

  if (size > 128) // assuming ASCII, cannot have unique if more than 128
    return false;

  bool hash[128] = {0}; // hash map for all possible ASCII characters/values

  for(int i=0;i<size;i++) // iterate through whole string
    {
      value = unique[i]; // creates hash value
      if (hash[value])// if already hashed to
	{
	  return false;
	}
	hash[value] = true; // fill hash slot
    }
  return true; 
}

int main(){
  

  char * TEST;
  printf("Enter string to test: \n"); 
  scanf("%s",TEST);

  bool result = is_unique_HASH(TEST);
  
  if (result == true)
    printf("UNIQUE\n");
    else
    printf("NOT UNIQUE\n");
  return 0;

}

