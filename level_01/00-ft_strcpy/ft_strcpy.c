char *ft_strcpy(char *s1, char *s2){
int i = 0;
while(s2[i]){
s1[i] = s2[i];
i++;}
s1[i]='\0';
return s1;
}

#include <stdio.h>
int main(void){
char s1[] = "Pommes";
char s2[] = "Banane";
printf("%s\n", s1);
ft_strcpy(s1,s2);
printf("%s \n", s1);
}
