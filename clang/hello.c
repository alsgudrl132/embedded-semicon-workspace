#include <stdio.h>
#include <string.h>

// sizeof() 연산자 <- 함수아님
// int main() {

//     // C언어에서 변수의 사용과 선언
//     // 영문자, 숫자, 언더바로만 사용가능
//     // 첫글자는 반드시 영문자,특수문자만 가능
//     // 대소문자 구별

//     // 카멜 표기법 
//     // int manAge : 첫단어는 소문자 결합되는 단어는 대문자로 시작
    
//     // 스네이크 표기법
//     // int man_age : 단어사이는 언더스코어로 연결

//     // 파스칼 표기법
//     // int ManAge : 모든 단어를 대문자로 시작

//     // 헝가리안표기법
//     // int IManAge : 변수명앞에 데이터형의 약자를 넣어줌


//     char ch;
//     int num;
//     double x;

//     printf("char 형의 바이트 크기 : %d \n", sizeof(char)); // 1
//     printf("short 형의 바이트 크기 : %d \n", sizeof(short)); // 2
//     printf("long 형의 바이트 크기 : %d \n", sizeof(long)); // 8
//     printf("float 형의 바이트 크기 : %d \n", sizeof(float)); // 4
    
//     printf("ch 형의 바이트 크기 : %d \n", sizeof(ch)); // 1
//     printf("num 형의 바이트 크기 : %d \n", sizeof(num)); // 4
//     printf("x 형의 바이트 크기 : %d \n", sizeof(x)); // 8

//     return 0;
// }

// int g; // 전역변수

// int main() {
//     // 변수의 초기화
//     // 변수를 선언하고 초기화 하지 않으면 지연변수는 쓰레기값이다
//     //int price; // 지역변수(Local variable)
//                // 전역변수, 정적변수
//                // main이라는 함수 안에 들어와있기때문에 price는 지역변수이다
//     int price = 0;
//     static int num; // 정적변수

//     printf("%d\n", price); // 알수없는숫자 32767
//     printf("%d\n", g); // 0
//     printf("%d\n", num); // 0
// }

// int main() {
//     // 모두 0 으로 지역변수 초기화
//     int amount = 0;
//     int price = 0;
//     int totalPrice = 0;

//     printf("amount = %d, price = %d\n", amount, price);
//     printf("수량을 넣으시오 : ");
//     scanf("%d", &amount); // scanf로 데이터를 입력받아서 amount에 값을 넣음

//     price = 100;

//     totalPrice = amount * price;

//     printf("합계 : %d\n\n\n", totalPrice); // 10을 넣었다고 치면 1000출력
// }

// // 산술연산자
// // +, -, *, /, %, ++, --
// int main() {
//     int a = 39;
//     int b = 17;
//     int result; // 지역변수인데 초기화 안함

//     result = a + b;
//     printf("a + b = %d\n", result); // 56

//     result = a - b;
//     printf("a - b = %d\n", result); // 22

//     result = a * b;
//     printf("a * b = %d\n", result); // 663

//     result = a / b;
//     printf("a / b = %d\n", result); // 정수이기때문에 소수를 날리고 2만 출력

//     result = a % b;
//     printf("a %% b = %d\n", result); // 5
// }

// 대입연산자
// = : 우측에 있는것을 좌측으로 대입
// +=, -+, *=, /=, %=
// a += b 이것은 a = a + b 와 동일하다 즉 a의 값을 a와 b를 더한값으로 변경한다.

// 논리연산자
// && 두개의 값이 true 일때만 true (and게이트)
// || 두개의 값중 하나만 true -> true (or게이트)
// ! true이면 false, false이면 true (not게이트)

// int main() {
//     int month;
//     printf("몇 월? : ");
//     scanf("%d", &month);

//     if(month >= 6 && month <= 8){ // 만약 month가 6보다 같거나 크고 8보다 작거나 같다면 (6,7,8) AND연산
//         printf("성수기 요금 적용\n");
//     };

//     if(month < 6 || month > 8) { // else대신 6보다 작거나 8보다 크다면 OR연산
//         printf("일반 요금 적용\n");
//     };
// }


// int main() {
//     int n1 = 15;            // 0b00000000 00000000 00000000 00001111 (4바이트 기준 이와같이 표현가능하다.)
//     int n2 = 20;            // 0b00000000 00000000 00000000 00010100
//     int result = n1 ^ n2;   // 0b00000000 00000000 00000000 00011011

//     printf("n1 = %d\n", n1);           // 15
//     printf("n2 = %d\n", n2);           // 20
//     printf("result = %d\n", result);   // 27
// }

// int main() {
//     int n1 = 1;             // 0b0000000 00000000 00000000 00000001
//     int s1 = n1 << 1;       // 0b~~~                       00000010
//     int s2 = n1 << 2;       // 0b~~~                       00000100
//     int s3 = n1 << 3;       // 0b~~~                       00001000
//     int s4 = n1 << 4;       // 0b~~~                       00010000

//     printf("n1 = %d\n", n1);// 1
//     printf("s1 = %d\n", s1);// 2
//     printf("s2 = %d\n", s2);// 4
//     printf("s3 = %d\n", s3);// 8
//     printf("s4 = %d\n", s4);// 16
// }

// int main() {
//     unsigned char a;
//     a = 255;
//     printf("%d\n", a);

//     a += 1;
//     printf("%d\n", a); // 오버플로우
// }

// 비트마스크 -> 특정 비트를 조작
// int main() {
//     unsigned short data = 0x0000;   // 0000 0000 0000 0000

//     unsigned short msk1 = 0xf000;   // 1111 0000 0000 0000
//     unsigned short msk2 = 0x0f00;   // 0000 1111 0000 0000
//     unsigned short msk3 = 0x00f0;   // 0000 0000 1111 0000
//     unsigned short msk4 = 0x000f;   // 1111 0000 0000 1111
    
//     printf(" 결과값 1 = %#.4x \n", data | msk1);    // 결과값 1 = 0xf000  
//     printf(" 결과값 2 = %#.4x \n", data | msk2);    // 결과값 2 = 0x0f00  
//     printf(" 결과값 3 = %#.4x \n", data | msk3);    // 결과값 3 = 0x00f0  
//     printf(" 결과값 4 = %#.4x \n", data | msk4);    // 결과값 4 = 0x000f  
// }

// int main() {
//     // 0b10101 -> 0b11101 만들고 싶다면
//     // 10101
//     // |
//     // 1 << 3 => 01000
//     //   10101
//     // | 01000
//     // --------
//     //   11101

//     // 삭제
//     // 11101 => 3번째 자리의 1을 삭제하고싶다면
//     // 1 << 3 => 01000
//     //   11101
//     // & 10111
//     // --------
//     //   10101

//     // 바꾸고싶을 자리수만큼 << 왼쪽으로 밀어주고 반전을 걸고 ~ 앤드를 먹여주면 원하는값이 나온다.
// }

// // 묵시적 형변환
// int main() {
//     int a,b,c;
//     double average;
//     printf("정수 3개를 입력하세요 : ");
//     scanf("%d %d %d", &a, &b, &c);

// //     average = (a + b + c) / 3;
// //     printf("평균은 : %f\n", average); // 2,2,3을 넣었다고 가정하고했을때 2.333333이 나와야하지만 2.000000 이 출력된다.

//     average = (double)(a + b + c) / 3;
//     printf("평균은 : %f\n", average);
// }

// int main() {
//     int num = 0;
//     printf("숫자를 입력하세요 \n");
//     scanf("%d", &num);

//     if(num < 5) {
//         printf("입력한 숫자는 5보다 작다\n");
//     }
//     if(num == 5) {
//         printf("입력한 숫자는 5하고 같다\n");
//     }
//     if(num > 5) {
//         printf("입력한 숫자는 5보다 크다\n");
//     }
// }

// int main() {
//     int num;
//     printf("미세먼지 농도를 선택하시오\n");
//     printf("1 : 좋음\n");
//     printf("2 : 보통\n");
//     printf("3 : 나쁨\n");
//     scanf("%d", &num);

//     switch (num)
//     {
//     case 1:
//         printf("미세먼지 농도가 좋으니까 마스크 안써도됨\n");
//         break;
//     case 2:
//         printf("미세먼지 농도가 보통이니까 마스크 써도되고 안써도됨\n");
//         break;
//     case 3:
//         printf("미세먼지 농도가 나쁘니까 마스크 쓰는걸 권장\n");
//         break;
//     default:
//         printf("1,2,3 중에 선택해주세요.");
//         break;
//     }
// }

// int main() {
//     int weight = 80;
//     int count = 0;

//     while(weight > 60) {
//         printf("매일 운동해서 1kg을 뺀다.\n");
//         weight--;
//         count++;
//     }
//     printf("축하합니다. 운동 안해도됨\n");
//     printf("%d 일 운동 했음\n\n", count);
// }

// int main() {
//     int weight;
//     int count = 0;

//     // weight--를 for 조건문에 넣고 count++을 for문 안에 넣어도됨
//     for(weight = 80; weight > 60; count++) {
//         printf("운동 했음\n");
//         weight--;
//     }

//     printf("축하합니다. 운동 안해도됨\n");
//     printf("%d 일 운동 했음\n\n", count);
// }

// int main() {
//     int i,j;
//     for(i = 0; i < 5; i++) {
//         for(j = 0; j <= i; j++) {
//             printf("*");
//         }
//         printf("\n");
//     }
//     for(i = 4; i > 0; i--) {
//         for(j = 0; j < i; j++) {
//             printf("*");
//         }
//         printf("\n");
//     }
// }

// int printHello(); // 함수의 원형 ( 해당 소스파일중 어딘가 printHello라는 함수가 있다고 컴파일러에게 알림 )

// int main() {
//     printHello();
// }

// int printHello() {
//     printf("Hello World\n");
//     return 0;
// }

// int add(int a, int b);

// int main() {
//     int x, y, z;
//     printf("정수 2개를 입력하세요 : ");
//     scanf("%d %d", &x, &y);

//     z = add(x, y);
//     printf("%d\n", z);
// }

// int add(int a, int b) {
//     int sum;
//     sum = a + b;
//     return sum;
// }

// {} 중괄호 내에서 선언된 변수
// 중괄호 내에서만 유효, 중괄호가 종료되면 메모리에서 사라짐
// 메모리영역내의 stack(스택)영역에 저장, 초기화하지 않으면 쓰레기값
// 함수의 매개변수도 함수내에서는 지역변수로 취급
// 프로그램이 실행될때 메모리공간 확보
// void local(void);

// int main() {
//     int i = 5;      // local variable
//     int var = 10;   // local variable

//     printf("main()함수내의 지역변수 var의 값 : %d\n", var);

//     if(i < 10) {
//         local();        // 함수 호출
//         int var = 30;   // if문 내의 local variable
//         printf("if문 내에서의 var의 값 : %d\n", var);
//     }

//     printf("현재 지역변수 var의 값 : %d\n", var);
// }

// void local(void) {
//     int var = 20;       // local()내의 local variable
//     printf("local() 함수 내에서의 지역변수 : %d\n", var);
// }

// 정적변수
// static(키워드)로 정의된 변수 ex) static int a;
// 전역변수와 지역변수의 특징을 모두 가지고있다.
// 함수내에서 선언된 정적변수는 단 한번만 초기화 가능
// 프로그램이 종료되어야 메모리에서 삭제됨
// 위에처럼 선언된 정적변수는 지역변수처럼 해당 함수(블록)에서만 접근 가능
// 전역변수처럼 초기화하지 않으면 0으로 초기화됨

// void local();
// void staticVar();

// int main() {
//     for(int i = 0; i < 3; i++) {
//         local();
//         staticVar();
//     }
// }

// void local(){
//     int count = 1;
//     printf("local() 함수가 %d 번째 호출됨\n", count);
//     count++;
// };
// void staticVar(){
//     static int staticCount = 1;
//     printf("staticVar() 함수가 %d 번째 호출됨\n", staticCount);
//     staticCount++;
// };

/*
    전역변수
    전역변수란 함수의 외부에 선언된 변수(main)
    프로그램의 어디에서나 접근이 가능, 프로그램이 종료되어야 메모리에서 삭제
    data 영역에 저장, 컴파일할때 메모리 확보
    초기화하지 않아도 자동으로 0으로 초기화됨
*/

// void local();   // 함수의 원형 선언
// int var;        // var이라는 전역변수 선언

// int main() {
//     printf("전역변수 var값 : %d\n", var);
//     int var = 10;   // 지역변수
//     printf("main() 내에서의 지역변수 var 값 : %d\n", var);

//     if(1) {
//         local();
//         printf("현재 변수 var의 값 : %d\n", var);
//     }
//     printf("더이상 main()함수에서는 전역변수 var이 접근 불가\n");
// }

// void local(){
//     var = 20;
//     printf("Local()함수내에서 접근한 var 값은 : %d\n", var);
// }

/*
    배열
    같은 데이터타입의 변수들로 이루어진 유한집합
    배열을 구성하는 각각의 값 -> 배열요소(element)
    요소의 위치를 가르키는 것 -> 인덱스(index)
    인덱스의 값은 언제나 0부터 시작, 양의정수값만 가질수 있다.
    배열의 모든 요소는 항상 연속된 메모리에 저장된다.

    예: int num[0]; 이것은 불가능하다.
    예: int size = 100;
        int data[size]; 이것도 불가능하다.

        #define MAX 5
        int data[MAX];  이것은 가능하다
*/

// int main() {
//     int arr[5];      // 4바이트인 int타입의 배열 5칸 선언
//     int byteArr = 0; // 배열의 바이트 크기를 저장할 변수 선언
//     int size = 0;    // 배열의 크기를 지정할 변수

//     byteArr = sizeof(arr);
//     printf("배열의 바이트 크기 : %d\n", byteArr);

//     size = sizeof(arr) / sizeof(arr[0]); //배열의 바이트 크기 : 20
//     printf("배열의 크기 : %d\n", size);    //배열의 크기 : 5

//     // 배열의 각 요소를 0으로 초기화
//     for(int i = 0; i < size; i++) {
//         arr[i] = 0;
//     }
    
//     for(int i = 0; i < size; i++) {
//         printf("arr[%d] : %d\n", i, arr[i]);
//     }
// }

// #define ARR_SIZE 5       // 매크로 상수로 지정

// int add(int a, int b);

// int main() {
//     int arr[ARR_SIZE] = {0}; // 배열 전체를 0으로 초기화

//     arr[0] = 5;
//     arr[1] = arr[0] + 10;
//     arr[2] = add(arr[0], arr[1]); // 함수의 인자로 사용

//     printf("정수 2개를 입력 하세요 : ");
//     scanf("%d %d", &arr[3], &arr[4]);

//     for(int i = 0; i < ARR_SIZE; i++) {
//         printf(" %d ", arr[i]);
//     }
//     printf("\n\n");
// }

// int add(int a, int b) {
//     return a + b;
// }

// int main() {
//     int i = 5;
//     char c = 'A';

//     printf(" 변수 i  의 주소값 : %p\t 변수 i의 값 : %d\n", &i, i);
//     printf(" 변수 c  의 주소값 : %p\t 변수 c의 값 : %d\n", &c, c);
// }

// int main() {
//     int arr[4];
//     arr[0] = 1;
//     arr[1] = 3;
//     arr[2] = 5;
//     arr[3] = 7;
//     printf("arr 배열의 첫번째 주소값 : %p\t 요소값 : %d\n", &arr[0], arr[0]);
//     printf("arr 배열의 두번째 주소값 : %p\t 요소값 : %d\n", &arr[1], arr[1]);
//     printf("arr 배열의 세번째 주소값 : %p\t 요소값 : %d\n", &arr[2], arr[2]);
//     printf("arr 배열의 네번째 주소값 : %p\t 요소값 : %d\n", &arr[3], arr[3]);
// }

// int main() {
//     // 2차원 배열
//     int arr[3][3] = {
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };

//     // int arr[3][3] = {1,2,3,4,5,6,7,8,9}; // 해당 2차원배열은 위와 동일하다.

//     // printf("1행 1열 : %d | ", arr[0][0]);
//     // printf("1행 2열 : %d | ", arr[0][1]);
//     // printf("1행 3열 : %d\n ", arr[0][2]);
//     // printf("2행 1열 : %d | ", arr[1][0]);
//     // printf("2행 2열 : %d | ", arr[1][1]);
//     // printf("2행 3열 : %d\n ", arr[1][2]);
//     // printf("3행 1열 : %d | ", arr[2][0]);
//     // printf("3행 2열 : %d | ", arr[2][1]);
//     // printf("3행 3열 : %d | ", arr[2][2]);

//     for(int i = 0; i < 3; i++) {
//         for(int j = 0; j < 3; j++) {
//             printf("%d행 %d열 : %d", i+1, j+1, arr[i][j]);
//             if(j < 2) printf(" | ");
//             if(j == 2) printf("\n");
//         }
//     }

//     // 1행 1열 : 1 | 1행 2열 : 2 | 1행 3열 : 3
//     // 2행 1열 : 4 | 2행 2열 : 5 | 2행 3열 : 6
//     // 3행 1열 : 7 | 3행 2열 : 8 | 3행 3열 : 9
// }

// int main() {
//     int arr[3][3] = {
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };

//     for(int i = 0; i < 3; i++) {
//         for(int j = 0; j < 3; j++) {
//             printf("%d행 %d열 : %d | 주소 : %p\n", i+1, j+1, arr[i][j], &arr[i][j]);
//         }
//     }
// }

// int main() {
//     // 포인터 선언
//     // 데이터형 *변수명 또는 데이터형 변수명*
//     // int *ptr 또는 ptr* 이런식
//     // 포인터의 크기는 일정
//     // 포인터의 크기는 플랫폼에 따라서 결정
//     // 32bit : 4byte, 64bit : 8byte

//     int *pi;        // int 타입의 포인터 변수 선언
//     double *pd;     // 더블 타입의 포인터 변수 선언
//     char *pc;       // 캐릭터 타입의 포인터 변수 선언

//     // 64비트 운영체제이기때문에 모두 8의 크기를 보여줌
//     printf("int형의 포인터 크기 : %d\n", sizeof(pi));
//     printf("double형의 포인터 크기 : %d\n", sizeof(pd));
//     printf("char형의 포인터 크기 : %d\n", sizeof(pc));
// }

// int main() {
//     int a;
//     a = 2;
//     printf("%p\n", &a); // 0x7fffffffd9f4 <- 개인마다 틀림
// }

// int main() {
//     int *ptr;    
//     int a;

//     ptr = &a; // a라는 변수의 주소값을 ptr이라는 주소에 위치시킨다.
//     printf("포인터 변수 ptr에 들어있는 것(값) : %p\n", ptr);        //포인터 변수 ptr에 들어있는 것(값) : 0x7fffffffd9ec
//     printf("포인터 변수 ptr에 들어있는 것(값) : %p\n", &ptr);       //포인터 변수 ptr에 들어있는 것(값) : 0x7fffffffd9f0
//     printf("int a변수의 메모리 주소값 : %p\n : ", &a);             //int a변수의 메모리 주소값 : 0x7fffffffd9ec
// }

// int main() {
//     int *ptr;
//     int a = 2;

//     ptr = &a;
    
//     printf("a의 값 : %d\n", a);
//     printf("a의 주소값 : %p\n", &a); // a의 주소 0x7fffffffd9ec

//     printf("*ptr의 값 : %d\n", *ptr); // a의 주소에 가지고있는 값을 반환 2
//     printf("ptr의 가리키는 주소 : %p\n", ptr); // ptr이 가리키는 주소, 즉 a의 값이 저장되어있는 주소를 반환 0x7fffffffd9ec
// }

// int main() {
//     int a, b; // 일반 변수 선언
//     int *ptr; // 여기에서 int의 의미는 포인터가 가리키는 곳의 데이터 타입

//     ptr = &a; // 포인터 ptr 변수에 a의 주소값으로 저장
//     *ptr = 2; // 포인터 ptr이 가리키는곳에 데이터를 2로 저장
//     ptr = &b; // 포인터 ptr 변수에 b의 주소값으로 변경 저장 (변수니까 변경 가능)
//     *ptr = 3; // 포인터 ptr이 가리키는곳에 데이터를 3으로 저장

//     printf(" a의 값 : %d\n", a); // 2
//     printf(" b의 값 : %d\n", b); // 3
// }

// int main() {
//     int a, b;
//     int *const ptr = &a; // const로 한것은 반드시 선언과 동시에 초기화 해야함
    
//     *ptr = 3; // 정상 (포인터가 가리키는곳의 값을 변경가능)
//     ptr = &b; // 오류 (포인터가 가리키는곳은 변경 불가)
// }

// // 포인터의 주소값 덧셈
// int main() {
//     int a;
//     char b;
//     double c;

//     int *pa = &a;
//     char *pb = &b;
//     double *pc = &c;
    
//     printf("pa의 값 : %p\n", pa);               // pa의 값 : 0x7fffffffd9d4
//     printf("pa + 1의 값 : %p\n", pa + 1);       // pa + 1의 값 : 0x7fffffffd9d8
//      printf("pb의 값 : %p\n", pb);              // pb의 값 : 0x7fffffffd9d3
//     printf("pb + 1의 값 : %p\n", pb + 1);       // pb + 1의 값 : 0x7fffffffd9d4
//      printf("pc의 값 : %p\n", pc);              // pc의 값 : 0x7fffffffd9d8
//     printf("pc + 1의 값 : %p\n", pc + 1);       // pc + 1의 값 : 0x7fffffffd9e0
// }

// int main() {
//     int a;
//     int *pa = &a;
//     int *pb;

//     *pa = 3;
//     pb = pa;

//     printf("pa가 가리키는 것의 값 : %d\n", *pa);
//     printf("pb가 가리키는 것의 값 : %d\n", *pa);
// }

// // 배열과 포인터 관계
// int main() {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};

//     for(int i = 0; i < 10; i++) {
//         printf("arr[%d]의 주소값 : %p\n", i , &arr[i]);
//     }
// }

// arr[0]과 주소값의 관계
// int main() {
//     int arr[3] = {1,2,3};

//     int *parr = arr;
//     printf("sizeof(arr) : %d\n", sizeof(arr));      // sizeof(arr) : 12
//     printf("sizeof(parr) : %d\n", sizeof(parr));    // sizeof(parr) : 8
//     // C언어에서 배열의 이름이 sizeof, &(주소값)연산자 등과 같이 사용할때를 제외하면
//     // 배열의 이름이 암묵적으로 첫번째 원소를 가리키는 포인터 타입으로 변환된다
// }

// int main() {
//     int arr[3] = {1,2,3};

//     int *parr;
//     parr = arr; // parr = &arr[0];
//     // arr[i] --> (arr+i) << 컴파일러가 이렇게 해석한다
//     printf("arr[1] : %d\n", arr[1]);
//     printf("parr[1] : %d\n", parr[1]);
// }

// int main() {
//     int arr[10] = {100,99,87,67,78,78,56,56,78,90};
//     int *parr = arr;    // 포인터변수 선언과 동시에 배열을 가르킴 (0번 인덱스)
//     int sum;

//     while(parr - arr <= 9) {
//         sum += (*parr); // sum = sum + (*parr);
//         parr++;
//     }
//     printf("평균은 : %d\n", sum / 10);

//     printf("parr - arr : %d\n", parr - arr);
// }

// int main() {
//     int *a;
//     int *pa;
//     int **ppa;

//     pa = &a;
//     ppa = &pa;

//     a = 3;

//     printf("a의 값 : %d || *pa : %d || **ppa : %d \n", a, *pa, **ppa);
//     printf("a의 주소 : %p || pa가리키는 주소 : %p || *ppa의 저장값 : %p\n", &a, pa, *ppa);
//     printf("pa의 주소 : %p || ppa가리키는 주소 : %p \n", &pa, ppa);
// }

// int main() {
//     int arr[2][3];
//     printf("arr[0] : %p\n", arr[0]);            // arr[0] : 0x7fffffffd9e0
//     printf("&arr[0][0] : %p\n", &arr[0][0]);    // &arr[0][0] : 0x7fffffffd9e0
//     printf("arr[1] : %p\n", arr[1]);            // arr[1] : 0x7fffffffd9ec
//     printf("&arr[1][0] : %p\n", &arr[1][0]);    // &arr[1][0] : 0x7fffffffd9ec
// }

// struct human    // human 이라는 구조체 정의
// {
//     int age;    // 나이 -> 멤버변수
//     int height; // 키 -> 멤버변수
//     int weight; // 몸무게 -> 멤버변수
// };

// int main() {
//     struct human info;  // struct human 이라는 데이터형, info라는 변수명

//     // 변수를 초기화
//     info.age = 29;
//     info.height = 177;
//     info.weight = 72;

//     printf("info의 멤버변수 키는? : %d\n", info.height);    // info의 멤버변수 키는? : 177
// }

// struct contact
// {
//     char name[20];
//     char phone[20];
//     int ringtone;
// };


// int main() {
//     struct contact ct = {"김석진", "01011112222", 0};
//     struct contact ct1 ={0}, ct2 = {0};
//     struct contact ct2 = ct;
    
//     ct.ringtone = 5;
//     strcpy(ct.phone, "01033334444"); // 01033334444를 ct.phone으로 카피해서 넣는다는 함수
//     printf("이름 : %s\n", ct.name);
//     printf("전번 : %s\n", ct.phone);
//     printf("벨소리 : %d\n", ct.ringtone);

//     printf("이름 : %s\n", ct1.name);
//     printf("전번 : %s\n", ct1.phone);
//     printf("벨소리 : %d\n", ct1.ringtone);

//     printf("이름 : %s\n", ct2.name);
//     printf("전번 : %s\n", ct2.phone);
//     printf("벨소리 : %d\n", ct2.ringtone);
// }

// // C언어는 문자열이없다.
// // 문자열 표현방법은 배열에 저장(char)
// // 배열의 마지막인덱스에 \0 NULL 자리가 있어야한다.

// typedef unsigned int myunsignedInteger // 자료형 재 정의

// typedef struct food
// {
//     char name[10];
//     int price;
//     int cookTime;
//     int preperence;
// } FOOD;

// int main() {
//     FOOD good = {"test", 30, 50, 100};
//     printf("name: %s\n", good.name);
// }

typedef struct test {
    int a; // 0x1234(예시주소)
    int b; // 0x1238(예시주소)
} TEST;

int main() {
    TEST st = {0}; // st.a , st.b를 0으로 초기화
    TEST *ptr; // struct test 타입의 구조체를 가리키는 포인터 변수(구조체 아님)

    ptr = &st;

    // 아래의 두가지는 같다고 볼 수있다
    // 멤버변수의 값을 변경 즉 st.a = 1, st.b = 2를 하는것과같다.
    // *ptr은 &st니까 st의 주소값에 들어있는 데이터를 의미하고 *ptr.a = 1 로 될수있다고 생각할수있는데 괄호를 입혀주거나 ->로 대체해줘야한다.
    (*ptr).a = 1;
    ptr->b = 2;
}