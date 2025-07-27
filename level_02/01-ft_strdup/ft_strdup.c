#include <stdlib.h> 
#include <stdio.h>

char    *ft_strdup(char *src){
    int i = 0;
    char *copy;
    while (src[i])
        i++;
    copy = (char*)malloc(sizeof(char)*(i + 1));
    if(copy == (NULL)){
        return (NULL);}
    i = 0;
    while(src[i]){
        copy[i] = src[i];
        i++;}
    copy[i] = '\0';
    return copy;
    
}

int main(){
    char *orj = "Bonjour";
    char *copy;
    copy = ft_strdup(orj);
    printf("Copy = %s\n", copy);
    return 0;
}
