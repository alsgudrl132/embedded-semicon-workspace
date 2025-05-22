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

int main() {
    int n1 = 1;             // 0b0000000 00000000 00000000 00000001
    int s1 = n1 << 1;       // 0b~~~                       00000010
    int s2 = n1 << 2;       // 0b~~~                       00000100
    int s3 = n1 << 3;       // 0b~~~                       00001000
    int s4 = n1 << 4;       // 0b~~~                       00010000

    printf("n1 = %d\n", n1);// 1
    printf("s1 = %d\n", s1);// 2
    printf("s2 = %d\n", s2);// 4
    printf("s3 = %d\n", s3);// 8
    printf("s4 = %d\n", s4);// 16
}