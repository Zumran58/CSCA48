

#include<stdio.h>
#include<stdlib.h>
#define MAX_STR_LEN 1024

// DO NOT USE the string library <string.h> for this exercise

int getlength(char* string)
{
	int len;
	len = 0;
	for (int i = 0; *(string + i) != '\0'; i++)
	{
		len++;
	}
	return len;
}	

void wordSwapper(char *source, char *destination){
	int length = getlength(source);
	int lengthword = 0;
  int startword = 0;
  int l = 0;

  
	for (int j = length - 1; j >= 0; j--){
    lengthword ++;

		if (*(source + j) == ' '){
			startword = j + 1;
      
      for (int k = startword; k < startword + lengthword - 1; k ++){

        *(destination + l) = *(source + k);
        l++;

      }
      *(destination + l) = ' ';
      l++;
      
      lengthword = 0;
		}

    if (j == 0){
      for (int k = 0; k < lengthword; k ++){
       
        *(destination + l) = *(source + k);
        l++;

      }
      *(destination + l) = '\0';
    }
    
  }
}

  
        


#ifndef __TESTING
int main()
{
    char source[MAX_STR_LEN]="silence .is a looking bird:the turning; edge, of life. e. e. cummings";
    char destination[MAX_STR_LEN]="I am a destination string and I contain lots of junk 1234517265716572@qsajdkuhasdgsahiehwjauhiuiuhdsj!";

    printf("The original string is: \n%s\n",source);

    wordSwapper(&source[0],&destination[0]);
  
    printf("Destination string after swapping: \n%s\n",destination);    
}
#endif
