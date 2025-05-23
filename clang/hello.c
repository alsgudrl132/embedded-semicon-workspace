#include <stdio.h>

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

int main() {
    int arr[5];      // 4바이트인 int타입의 배열 5칸 선언
    int byteArr = 0; // 배열의 바이트 크기를 저장할 변수 선언
    int size = 0;    // 배열의 크기를 지정할 변수

    byteArr = sizeof(arr);
    printf("배열의 바이트 크기 : %d\n", byteArr);

    size = sizeof(arr) / sizeof(arr[0]); //배열의 바이트 크기 : 20
    printf("배열의 크기 : %d\n", size);    //배열의 크기 : 5

    // 배열의 각 요소를 0으로 초기화
    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    
    for(int i = 0; i < size; i++) {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}