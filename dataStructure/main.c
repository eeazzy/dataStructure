//
//  main.c
//  day2
//
//  Created by 김현서 on 6/25/24.
//

#include <stdio.h>

typedef struct num{
    int a;
    double pi;
}NUM;

int main() {
    
    int a[5] = {10,20,30,40,50};
    int * ptr = a;
    NUM num1;
    num1.a = 10;
    num1.pi = 3.14;
    
    printf("%d, %f",num1.a,num1.pi);
    
    for(int i=0;i<5;i++){
        printf("%d\n",a[i]);
        printf("%d\n",ptr[i]);
        printf("%d\n",*(ptr+i));
    }
    
    for(int i=0;i<5;i++){
        printf("%d\n",*ptr++);
    }

}
