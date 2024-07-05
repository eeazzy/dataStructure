//
//  no2.c
//  day2
//
//  Created by 김현서 on 6/25/24.
//

#include <stdio.h>

struct person{
    int a;
    double pi;
};

int main() {
    // struct person ps = {10, 3.14};
    struct person ps, ps2; //구조체 변수
    struct person * p = &ps2;
    
    ps.a = 10;
    ps.pi = 3.14;
    
    p->a = 20;
    p->pi = 5.14;
    
    printf("%d, %f\n",ps.a,ps.pi);
    printf("%d, %f\n",p->a,p->pi);

}
