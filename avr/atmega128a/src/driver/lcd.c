#include "lcd.h"

// 데이터 전송
void LCD_Data(uint8_t data) 
{
    LCD_DATA_PORT = data;
}

void LCD_Data_4Bit(uint8_t data)
{
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (data & 0xf0); // 상위 4비트 추출, 전송
    LCD_EnablePin();
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | ((data & 0x0f) << 4);
    LCD_EnablePin();
}

// 명령어/데이터 전송
void LCD_WritePin() 
{
    LCD_RW_PORT &= ~(1 << LCD_RW);      // RW핀을 데이터시트상 0(LOW)으로 설정해서 쓰기모드로 변경 (LCD_RW는 6번핀으로 꼽혀있음)
}

// LCD 동작신호
void LCD_EnablePin() 
{
    LCD_E_PORT &= ~(1 << LCD_E);        // E핀을 LOW로 설정
    LCD_E_PORT |= (1 << LCD_E);         // E핀을 HIGH로 설정
    LCD_E_PORT &= ~(1 << LCD_E);        // 다시 LOW로 설정
    _delay_us(1600);                    // 일정시간 대기
}

// 명령어 전송
void LCD_WriteCommand(uint8_t commandData) 
{
    LCD_RS_PORT &= ~(1 << LCD_RS);      // RS핀을 LOW로 설정해서 명령어 모드
    LCD_WritePin();
    // LCD_Data(commandData);
    LCD_Data_4Bit(commandData);
    // LCD_Data_4Bit에서 Enable해주고있기때문에 밑에줄 주석처리
    // LCD_EnablePin();
}

// 데이터 전송
void LCD_WriteData(uint8_t charData) 
{
    LCD_RS_PORT |= (1 << LCD_RS);       // RS핀을 HIGH로 설정해서 데이터 모드
    LCD_WritePin();
    // LCD_Data(charData);
    LCD_Data_4Bit(charData);
    // LCD_Data_4Bit에서 Enable해주고있기때문에 밑에줄 주석처리
    // LCD_EnablePin();
}

void LCD_GotoXY(uint8_t row, uint8_t col) 
{
    col %= 16;                          // 열 인덱스를 0~15까지 제한 (16개 열)
    row %= 2;                           // 행 인덱스를 0~1까지 제한  (2개 행)
    uint8_t address = (0x40 * row) + col; // 주소 계산 두번째행이 40부터 시작하기떄문에 0x40에 row를 곱하고 col을 더한다
                                          // row가 1, col이 3이 들어온다하면 0x43이 된다.
    uint8_t command = 0x80 + address;     // 주소값을 알리는 커맨드
    LCD_WriteCommand(command);            // 주소를 설정한 커맨드를 LCD로 전송
}

void LCD_WriteString(char *string) 
{
    for(uint8_t i = 0; string[i]; i++) {
        LCD_WriteData(string[i]);
    }
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string) 
{
    LCD_GotoXY(row, col);
    LCD_WriteString(string);
}

void LCD_Init() 
{
    LCD_DATA_DDR = 0xFF;                // 데이터핀 출력 설정
    LCD_RS_DDR |= (1 << LCD_RS);        // RS핀 출력 설정
    LCD_RW_DDR |= (1 << LCD_RW);        // RW핀 출력 설정
    LCD_E_DDR |= (1 << LCD_E);          // Enable핀 출력 설정

    _delay_ms(20);                      // 초기화 대기 시간 (충분한 시간 필요)
    LCD_WriteCommand(0x03);
    _delay_ms(5);
    LCD_WriteCommand(0x03);
    _delay_ms(5);
    LCD_WriteCommand(0x03);
    LCD_WriteCommand(0x02);
    LCD_WriteCommand(COMMAND_4BIT_MODE);
    LCD_WriteCommand(COMMAND_DISPLAY_OFF);
    LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
    LCD_WriteCommand(COMMAND_DISPLAY_ON);       // 데이터시트에서 이부분만 따로 집어넣음
    LCD_WriteCommand(COMMAND_ENTRY_MODE);

    // _delay_ms(20);                      // 초기화 대기 시간 (충분한 시간 필요)
    // LCD_WriteCommand(COMMAND_8BIT_MODE);
    // _delay_ms(5);
    // LCD_WriteCommand(COMMAND_8BIT_MODE);
    // _delay_ms(5);
    // LCD_WriteCommand(COMMAND_8BIT_MODE);
    // LCD_WriteCommand(COMMAND_8BIT_MODE);
    // LCD_WriteCommand(COMMAND_DISPLAY_OFF);
    // LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
    // LCD_WriteCommand(COMMAND_DISPLAY_ON);       // 데이터시트에서 이부분만 따로 집어넣음
    // LCD_WriteCommand(COMMAND_ENTRY_MODE);
}
