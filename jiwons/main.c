//
//  main.c
//  jiwons
//
//  Created by 김태현 on 2020/10/12.
//
//  두 숫자를 입력받고 회문에서 그 두 숫자사이의 범위에서 다시 만들어질 수 있는 회문의 최대 길이를 구하는 프로그램.


#include <stdio.h>
#include <stdlib.h>

//회문크기를 확인하는 함수
int inputPalCount(void);

//회문을 문자열로 입력받아 공백을 기준으로 정수형 배열로 바꾸는 함수
void inputPal(int palSize, int* pal);

//범위를 입력받을 횟수를 입력받는 함수
int inputRangeCount(void);

//범위 하나를 입력받아 저장하는 함수
void inputRange(int palMax, int* range1, int* range2);

//매개변수로 주어진 수열이 회문인지 아닌지 판단하는 함수
int isItPalindrome(int* list, int length);

//수열을 매개변수로 받아 그 중에서 나올 수 있는 회문의 최대 길이를 구하는 함수
int maxPalLength(int* list, int length);

//입력받은 범위의 개수만큼 범위를 묻고 매번 회문의 최대 길이를 출력하는 함수
void palMaxLength(int* pal, int palLength, int rangeCount);

int main(int argc, const char * argv[]) {
    //회문의 크기
    int palLength = 0;
    
    //회문을 저장할 배열 포인터
    int* palList;
    
    //범위의 개수
    int rangeCount = 0;
    
    //회문의 크기를 입력
    palLength = inputPalCount();
    
    //입력받은 회문의 크기만큼 회문을 저장할 배열의 크기를 동적 할당.
    palList = malloc(sizeof(int) * (palLength + 1));
    
    //입력받은 회문의 크기만큼 회문을 입력
    inputPal(palLength, palList);
    
    int i;
    for (i=0; i < palLength + 1; i++){
        printf("%d - ", palList[i]);
    }
    
    
    //입력받을 범위의 개수를 입력
    rangeCount = inputRangeCount();
    
    palMaxLength(palList, palLength, rangeCount);
    
    
    
    //동적할당한 회문을 해제
    free(palList);
    
    return 0;
}


int inputPalCount(){
    int count;
    //입력 받은 회문의 길이가 1보다 작거나 100000보다 크다면 다시 입력 받는다.
    while (1) {
        //getchar();
        scanf("%d", &count);
        //getchar();
        if ((count<1) || (count>2000)){
            printf("입력된 크기의 범위가 잘못되었습니다. 다시 입력하십시오 \n");
            continue;
        }
        else{
            return count;
        }
    }
}

void inputPal(int palSize, int* pal){
    
    char* tempPalList;
    int* palList;
    
    //입력받은 값을 저장할 문자열, 정수형 배열. 동적으로 크기 할당.
    tempPalList = malloc(sizeof(char)*(palSize));
    palList = malloc(sizeof(int)*(palSize));
    
    //회문을 문자열로 입력받음
    getchar();
    gets(tempPalList);
    
    int i, tempNum = 0;
    int j=0;
    
    //공백을 기준으로 문자열에서 정수를 얻어 정수형 배열에 차례대로 저장
    for (i = 0; tempPalList[i] != 0; i++){
        if (tempPalList[i] != ' '){
            tempNum = tempNum * 10 + tempPalList[i] - '0';
        }
        else{
            
            palList[j] = tempNum;
            //printf("%d\n", palList[j]);
            tempNum = 0;
            j++;
        }
    }
    palList[j] = tempNum;
    //printf("%d\n", palList[j]);
    tempNum = 0;
    j++;
    
    //얻은 정수형 배열을 pal에 반환
    for (i = 0; i < palSize; i++){
        pal[i] = palList[i];
        //printf("%d ", palList[i]);
        //printf("%d ", pal[i]);
    }
    
    free(tempPalList);
    free(palList);
    
    //배열의 끝을 정함.
    pal[palSize] = 0;
}

int inputRangeCount(){
    int count = 0;
    scanf("%d", &count);
    if ((count<1) || (count>1000000)){
        return 0;
    }
    else{
        return count;
    }
}

void inputRange(int rangeMax, int* range1, int* range2){
    /*
    char rangeChar[30];
    int tempRange[2];
    
    int i, tempNum, j;
    
    //공백으로 구분된 입력한 범위를 분리하여 저장
    
    while (1) {
        
        tempNum = 0; j = 0;
        gets(rangeChar);
        
        printf("effef\n");
        
        for (i = 0; rangeChar[i] != 0; i++){
            if (rangeChar[i] != ' '){
                tempNum = tempNum * 10 + rangeChar[i] - '0';
            }
            else{
                tempRange[j] = tempNum;
                tempNum = 0;
                j++;
            }
        }
        
        printf("%d *** %d\n", tempRange[0], tempRange[1]);
        //범위의 입력이 올바른지 확인
        if ((((tempRange[0] > tempRange[1]) || (tempRange[0] < 1)) || (tempRange[1] > rangeMax))){
            //범위의 입력이 잘못됨
            continue;
        }
        else{
            break;
        }
         */
    int tempRange1; int tempRange2;
    while (1){
        getchar();
        scanf("%d%d", &tempRange1, &tempRange2);
        //printf("%d *** %d\n", tempRange1, tempRange2);
        if (((tempRange1 > tempRange2) || (tempRange1 < 1)) || (tempRange2 > rangeMax)){
            tempRange1 = 0;
            tempRange2 = 0;
            continue;
        }
        else{
            break;
        }

    }
    
    //범위를 저장
    *range1 = tempRange1;
    *range2 = tempRange2;
}

int isItPalindrome(int* list, int length){
    int i;
    
    for (i = 0; i < length / 2; i++){
        if (list[i] != list[length - i - 1]){
            return 1;
        }
    }
    return 0;
}

int maxPalLength(int* list, int length){
    /*
    int i, j;
    int* checkList;
    for (i=0; i<length; i++){
        checkList = malloc(sizeof(int) * (i + 1));
        for (j=0; j<i; j++){
            
        }
    }
    */
}

void palMaxLength(int* pal, int palLength, int rangeCount){
    
    
    int* currentPal;
    int leftRangeCount;
    int range1; int range2;
    
    int i, j;
    
    //정해진 횟수만큼 범위를 묻는다
    for (leftRangeCount = 0; leftRangeCount < rangeCount; leftRangeCount++) {
        inputRange(palLength, &range1, &range2);
        //입력한 범위 + 1 만큼 동적할당
        currentPal = malloc(sizeof(int) * (range2 - range1 + 2));
        i = 0;
        
        //currentPal 배열에 원하는 범위의 수열을 저장
        for (j = range1-1; j < range2; j++){
            currentPal[i] = pal[j];
            i++;
        }
        
        
        
        free(currentPal);
    }
    
    
}
