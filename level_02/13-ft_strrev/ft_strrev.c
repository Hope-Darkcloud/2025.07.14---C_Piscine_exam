#include <stdio.h>
char    *ft_strrev(char *str){
int start = 0;
int len = 0;
char temp;
while(str[len])
{len++;
}
len--;
while(start < len){
temp = str[start];
str[start]=str[len];
str[len]=temp;
start++;
len--;
}
return str;
}
int main (void){
char s[] = "hello";
printf("%s\n", ft_strrev(s));
}
