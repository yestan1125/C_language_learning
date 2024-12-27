#include <stdio.h>
#include <string.h>
#define MAXLINE 100
void zip(char *p){
  char *p=q;
int n;
while (*p!='\0'){
n=1;
while (*p == *(p+n)){
        n++;
}
    if(n>=10){
    *q++=(n/10)+'0';
    *q++=(n%10)+'0';
    }
    else if(n>=2){
    *q++ = n+'0';
    }
    *q++=*(p+n-1);
    p=p+n;
    }
    *q='\0';
}
int main(void){
  char line [MAXLINE];
  fgets(line,MAXLINE,stdin);
  zip(line);
  puts(line);
  return 0;
}
