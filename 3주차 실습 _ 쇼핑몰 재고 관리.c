#include <stdio.h>

#define MAX_ITEMS 100

int main() {
    int numItems;          // 상품 종류의 개수
    int stock[MAX_ITEMS];  // 입고 수량
    int sales[MAX_ITEMS];  // 판매 수량
    int inventory[MAX_ITEMS]; // 재고 수량
    int i;
    int totalSales = 0;
    int maxSales = 0;
    int minSales = MAX_ITEMS + 1;
    int maxSalesID = 0
    int minSalesID = 0;
    float totalStock = 0.0;
    float salesRate = 0.0;
    int ID;

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
        totalSales += sales[i];
        totalStock += stock[i];
    }

    for (i = 0; i < numItems; i++) {
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxSalesID = i + 1;
        }
        if (sales[i] < minSales) {
            minSales = sales[i];
            minSalesID = i + 1;
        }
    }

    salesRate = (totalSales / totalStock) * 100;

    // 결과 출력: 전체 상품의 재고와 판매 통계
    printf("모든 상품의 재고 수량: ");
    for (i = 0; i < numItems; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSales, salesRate);
    printf("가장 많이 판매된 상품: ID%d, 판매량 %d\n", maxSalesID, maxSales);
    printf("가장 적게 판매된 상품: ID%d, 판매량 %d\n", minSalesID, minSales);

    for (i = 0; i < numItems; i++) {
        if (inventory[i] <= 2) {
            printf("상품 ID %d: 재고 부족 (%d)\n", i + 1, inventory[i]);
        }
    }

    // 상품 고유 ID 입력 및 재고 출력
    printf("상품의 고유ID 입력: ");
    scanf("%d", &ID);

    if (ID < 1 || ID > numItems) {
        printf("고유 ID는 1에서 %d 사이여야 합니다.\n", numItems);
        return 1;
    }

    printf("- 입력한 고유ID '%d'에 해당하는 제품의 재고 수량 -\n %d\n", ID, inventory[ID - 1]);

    return 0;
}