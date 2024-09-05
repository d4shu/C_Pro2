#include <stdio.h>

#define MAX_ITEMS 100

int main() {
    int numItems;          // 상품 종류의 개수
    int stock[MAX_ITEMS];  // 입고 수량
    int sales[MAX_ITEMS];  // 판매 수량
    int inventory[MAX_ITEMS]; // 재고 수량
    int i,ID;

    printf("상품 개수(종류) 입력: ");
    scanf("%d", &numItems);

    if (numItems < 1 || numItems > MAX_ITEMS) {
        printf("상품 개수는 1~100 사이여야 합니다.\n");
        return 1;
    }

    printf("상품 별 입고 수량 입력: ");
    for (i = 0; i < numItems; i++) {
        scanf("%d", &stock[i]);
    }

    printf("상품 별 판매 수량 입력: ");
    for (i = 0; i < numItems; i++) {
        scanf("%d", &sales[i]);
    }

    for (i = 0; i < numItems; i++) {
        inventory[i] = stock[i] - sales[i];
    }

    printf("상품의 고유ID 입력 : ");
    scanf("%d", &ID);

    if (ID < 1 || ID > numItems) {
        printf("고유 ID는 1에서 %d 사이여야 합니다.\n", numItems);
        return 1;
    }

    printf("- 입력한 고유ID '%d'에 해당하는 제품의 재고 수량 -\n %d\n", ID, inventory[ID - 1]);
    
    printf("- 모든 상품의 재고 수량 - \n");
    for (i = 0; i < numItems; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    return 0;
}