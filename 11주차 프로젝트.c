#include <stdio.h>
#include <string.h>
#define MAX_ITEM 5

int item[MAX_ITEM] = {0};
int min[MAX_ITEM] = {0};
int price[MAX_ITEM] = {0};
char strings[MAX_ITEM][10];
int total_item = 0;
int total_sold = 0;
double total_sold_rate = 0.0;
int max_sold = 0, min_sold = 0;
int max_id = 0, min_id = 0;
int menu_num;
int id = 0;

void inputItem();
void outputItem();
void individualStatus();
void itemStatus();
void saveItems();
void loadItems();

int main() {
    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고 2. 판매 3. 개별현황 4. 전체현황 5. 상품정보저장 6. 상품정보가져오기 7. 종료)\n> ");
        scanf("%d", &menu_num);

        if (menu_num == 1) {
            inputItem();
        } else if (menu_num == 2) {
            outputItem();
        } else if (menu_num == 3) {
            individualStatus();
        } else if (menu_num == 4) {
            itemStatus();
         } else if (menu_num == 5) {
            saveItems();
        } else if (menu_num == 6) {
            loadItems();
        } else if (menu_num == 7) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("메뉴를 다시 선택해주세요.\n");
        }
    }
    return 0;
}

void saveItems() {
    FILE* fp = fopen("items.txt", "w");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < MAX_ITEM; i++) {
        if (strlen(strings[i]) > 0) {
            fprintf(fp, "상품 ID : %s\n재고량 : %d\n판매량 : %d\n판매 가격 : %d\n", strings[i], item[i], min[i], price[i]);
        }
    }
    fclose(fp);
    printf("상품 정보가 파일에 저장되었습니다.\n");
}

void loadItems() {
    FILE* fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("저장된 파일이 없습니다.\n");
        return;
    }

    int i = 0;
    while (fscanf(fp, "상품 ID : %s\n재고량 : %d\n판매량 : %d\n판매 가격 : %d\n", strings[i], &item[i], &min[i], &price[i]) != EOF) {
        total_item += item[i];
        total_sold += min[i];
        i++;
    }
    fclose(fp);
    printf("상품 정보를 불러왔습니다.\n");
}


void inputItem() {
    if (id <= 5){
        int num, saleNum;
        char itemName[100];
    

        printf("상품ID (1~%d): ", MAX_ITEM);
        scanf("%d", &id);
         if (id < 1 || id > MAX_ITEM) {
        printf("상품 ID를 다시 입력해주세요.\n");
        return;
        }
        printf("상품명 : ");
        scanf("%s", itemName);
        printf("입고량: ");
        scanf("%d", &num);
        printf("판매가격 : ");
        scanf("%d", &saleNum);

        strcpy(strings[id - 1], itemName);
        item[id - 1] += num;
        price[id - 1] = saleNum;
        total_item += num;

    }
}

void outputItem() {
    int id, num;

    printf("상품ID (1~%d): ", MAX_ITEM);
    scanf("%d", &id);

    if (id < 1 || id > MAX_ITEM || item[id - 1] == 0) {
        printf("잘못된 상품 ID이거나 해당 상품의 재고가 없습니다.\n");
        return;
    }

    printf("판매수량: ");
    scanf("%d", &num);

    if (num > item[id - 1]) {
        printf("재고가 부족합니다.");
    } else {
        item[id - 1] -= num;
        min[id - 1] += num;
        total_sold += num;
    }
    
    if (total_item > 0) {
        total_sold_rate = (double)total_sold / total_item * 100;
    }

    max_sold = min[0];
    min_sold = min[0];
    max_id = min_id = 1;

    for (int i = 1; i < MAX_ITEM; i++) {

        if (min[i] > max_sold) {
            max_sold = min[i];
            max_id = i + 1;
        }

        if (min[i] < min_sold) {
            min_sold = min[i];
            min_id = i + 1;
        }
    }
}

void individualStatus() {
    int id;
    
    printf("상품 ID를 입력하세요 (1~%d): ", MAX_ITEM);
    scanf("%d", &id);

    if (id < 1 || id > MAX_ITEM) {
        printf("잘못된 상품 ID입니다. 다시 입력해주세요.\n");
        return;
    }

    if (strlen(strings[id - 1]) == 0) {
        printf("해당 ID에 등록된 상품이 없습니다.\n");
        return;
    }

    printf("\n상품 ID %d 정보\n", id);
    printf("상품명: %s\n", strings[id - 1]);
    printf("재고 수량: %d\n", item[id - 1]);
    printf("판매된 수량: %d\n", min[id - 1]);
    printf("판매 가격: %d\n", price[id - 1]);

}

void itemStatus() {
    printf("\n재고 수량: ");

    for (int i = 0; i < MAX_ITEM; i++) {
        printf("%d ", item[i]);
    }

    printf("\n총 판매량: %d (판매율 %.2f%%)", total_sold, total_sold_rate);
    printf("\n가장 많이 판매된 상품: ID %d, 상품명 : %s ,판매량 %d", max_id, strings[max_id - 1], max_sold);
    printf("\n가장 적게 판매된 상품: ID %d, 상품명 : %s ,판매량 %d", min_id, strings[min_id - 1], min_sold);

    for (int i = 0; i < MAX_ITEM; i++) {
        if (item[i] <= 2) {
            printf("\n상품 ID %d: 상품명 : %s 재고부족(%d)", i + 1, strings[i], item[i]);
        }
    }

}




