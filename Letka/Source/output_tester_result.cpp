#include "stdio.h"
#include "TXLib.h"

#include "output_tester_result.h"

/*!
    @brief Function to create wingow with result

    @param result result (-1 if wrong, 1 if right)
    @param number_test number test with error (count test if all right)
*/
void output_tester_result(int result, int number_test) {
    if(result == 0) return ;
    txCreateWindow (300, 200);

    RECT result_rect = {100, 70, 200, 120};
    POINT name_text = {150, 30};
    POINT result_text = {150, 100};
    POINT num_text = {150, 160};
    txSetTextAlign();

    txSelectFont ("Comic Sans MS", 40);
    txSetColor(RGB(200, 200, 200));
    txTextOut (name_text.x, name_text.y, "Quadratic solver");
    txSelectFont ("Times new roman", 20);

    if(result == 1) {
        txSetFillColor(RGB(0, 200, 0));
        txSetColor(RGB(0, 255, 0));
        txRectangle (result_rect.left, result_rect.top, result_rect.right, result_rect.bottom);
        txSetColor (RGB(20, 20, 20));
        txTextOut (result_text.x, result_text.y, "All right!");
    }
    else{
        txSetFillColor(RGB(200, 0, 0));
        txSetColor(RGB(255, 0, 0));
        txRectangle (result_rect.left, result_rect.top, result_rect.right, result_rect.bottom);
        txSetColor (RGB(20, 20, 20));
        txTextOut (result_text.x, result_text.y, "Wrong!");
    }

    txSetColor(RGB(200, 200, 200));
    char text_number_test[32] = "";
    sprintf(text_number_test, "Number test: %d", number_test);
    txTextOut (num_text.x, num_text.y, text_number_test);
}

/*!
    @brief Function to print result test in console

    @param num_right massive with right test
    @param cnt_right count right test
    @param num_wrong massive with wrong test
    @param cnt_wrong count wrong test
*/
void output_tester_result_console(int num_right[], int cnt_right, int num_wrong[], int cnt_wrong){
    printf("Right tests:\n\t");

    if(cnt_right == 0) printf("No wrong test!");
    else{
        txSetConsoleAttr(FOREGROUND_GREEN | BACKGROUND_BLACK);
        for(int i = 0; i < cnt_right; i++) {
            printf("%d", num_right[i]);
            if(i+1 < cnt_right) printf(", ");
        }
    }

    txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);
    printf("\nWrong tests:\n\t");

    if(cnt_wrong == 0) printf("No wrong test!");
    else{
        txSetConsoleAttr(FOREGROUND_RED | BACKGROUND_BLACK);
        for(int i = 0; i < cnt_wrong; i++) {
            printf("%d", num_wrong[i]);
            if(i+1 < cnt_wrong) printf(", ");
        }
    }
    printf("\n");

    if(cnt_wrong == 0){
        txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_GREEN);
        printf(" All right!");
    }
    else{
        txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_RED);
        printf(" Wrong!");
    }
    txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);
    printf("\n");
}

