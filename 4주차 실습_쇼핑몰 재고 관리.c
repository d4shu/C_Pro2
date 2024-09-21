#include <stdio.h> 

void ItemFunc(int PRODUCT_COUNT, int* inputArray);

void ItemFunc(int PRODUCT_COUNT, int* inputArray) {
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        scanf("%d", (inputArray + i));
    }
}

int main() {
    int inputItem[100] = {0}, outputItem[100] = {0}, PRODUCT_COUNT = 5;
    int selItem[100] = {0}, inputManage = 0, inputType = 0, inputNumber = 0, inputID = 0, inputManageEnd = 1;

    float totalItem = 0.0, totalInputItem = 0.0;

    while (inputManageEnd != 0) {
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료) : ");
        scanf("%d", &inputManage);

        if (inputManage == 1) {
            printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2 : ");
            scanf("%d", &inputType);
            if (inputType == 1) {
                printf("상품 별 입고 수량을 입력하여 주세요: ");
                ItemFunc(PRODUCT_COUNT, inputItem);
            } else if (inputType == 2) {
                printf("상품ID (1-%d): ", PRODUCT_COUNT);
                scanf("%d", &inputID);
                if (inputID < 1 || inputID > PRODUCT_COUNT) {
                    printf("유효하지 않은 상품ID입니다.\n");
                    continue;
                }
                printf("입고수량 : ");
                scanf("%d", &inputNumber);
                if (inputNumber < 0) {
                    printf("유효하지 않은 수량입니다.\n");
                    continue;
                }
                inputItem[inputID - 1] += inputNumber; // 기존 재고에 추가
            }
        } else if (inputManage == 2) {
            printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2 : ");
            scanf("%d", &inputType);
            if (inputType == 1) {
                printf("상품 별 판매 수량을 입력하여 주세요(입력 예시 5 5 5 5 5) : ");
                ItemFunc(PRODUCT_COUNT, outputItem);
            } else if (inputType == 2) {
                printf("상품ID (1-%d): ", PRODUCT_COUNT);
                scanf("%d", &inputID);
                if (inputID < 1 || inputID > PRODUCT_COUNT) {
                    printf("유효하지 않은 상품ID입니다.\n");
                    continue;
                }
                printf("판매 수량 : ");
                scanf("%d", &inputNumber);
                if (inputNumber < 0) {
                    printf("유효하지 않은 수량입니다.\n");
                    continue;
                }
                outputItem[inputID - 1] += inputNumber; // 기존 판매 수량에 추가
            }
        } else if (inputManage == 3) {
            totalItem = 0.0;
            totalInputItem = 0.0;

            for (int i = 0; i < PRODUCT_COUNT; i++) {
                selItem[i] = inputItem[i] - outputItem[i];
                totalItem += outputItem[i];
                totalInputItem += inputItem[i];
            }

            printf("재고 수량 : ");
            for (int i = 0; i < PRODUCT_COUNT; i++) {
                printf("%d ", selItem[i]);
            }
            printf("\n");

            if (totalInputItem > 0) {
                printf("총 판매량 : %d (판매율 %.2f%%)\n", (int)totalItem, (totalItem / totalInputItem) * 100);
            } else {
                printf("총 판매량 : %d (판매율 0.00%%)\n", (int)totalItem);
            }

            int maxNumberID = 0, minNumberID = 0;
            int minNumber = outputItem[0], maxNumber = outputItem[0];

            for (int i = 1; i < PRODUCT_COUNT; i++) {
                if (maxNumber < outputItem[i]) {
                    maxNumber = outputItem[i];
                    maxNumberID = i;
                }
                if (minNumber > outputItem[i]) {
                    minNumber = outputItem[i];
                    minNumberID = i;
                }
            }

            printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxNumberID + 1, outputItem[maxNumberID]);
            printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minNumberID + 1, outputItem[minNumberID]);

            for (int i = 0; i < PRODUCT_COUNT; i++) {
                if (selItem[i] < 3) {
                    printf("상품 ID %d : 재고부족 (%d)\n", i + 1, selItem[i]);
                }
            }
        } else if (inputManage == 4) {
            inputManageEnd = 0;
        } else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}
