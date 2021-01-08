// Zumran Nain excercise 2

#define max_str_len 1024
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void square_array(int array[10]){
	for(int j = 0; j< 10; j++){
		array[j] = array[j] * array[j];
	}
}
int main()
{
	int my_array[10];
	
	for(int z = 0; z< 10; z++){
		my_array[z] = z;
		
	}
	square_array(my_array);
	
	for(int i= 0; i< 10; i++){
		printf("The value of the array is %d\n", my_array[i]);
		
	}
	return 0;
	
	
}
	










