#ifndef MYLED_H
#define MYLED_H

#include <avr/io.h>  // AVR 레지스터 접근용

// 함수 선언
void myledInit(void);
void segzero(void);
void segone(void);
void segtwo(void);
void segthree(void);
void segfour(void);

#endif /* MYLED_H */