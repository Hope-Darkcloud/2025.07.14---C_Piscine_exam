#include <unistd.h>
int main (int argc, char **argv){
int i = 0;
if (argc != 2){
write(1, "a", 1);}else{
while(argv[1][i]){
if(argv[1][i] == 'a'){
write(1, "a", 1);
break;}
i++;}
}
write(1, "\n", 1);
return 0;
}
