#include <stdio.h>
#include <stdlib.h>

struct Item {
	int value;
	int weight;
};

int knapsack(struct Item items[], int n, int capacity) {

	int** item = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i <= n; i++) item[i] = (int*)malloc((capacity + 1) * sizeof(int));

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= capacity; w++) {
			if (i == 0 || w == 0) item[i][w] = 0;
			else if (items[i - 1].weight <= w) {
				item[i][w] = (items[i - 1].value + item[i - 1][w - items[i - 1].weight] > item[i - 1][w])
					? items[i - 1].value + item[i - 1][w - items[i - 1].weight] : item[i - 1][w];
			} else item[i][w] = item[i - 1][w];
		}
	}
	int result = item[n][capacity];

	for (int i = 0; i <= n; i++) free(item[i]);

	free(item);
	return result;
}

void main() {

	struct Item items[] = { {10, 5}, {40, 4}, {30, 6}, {50, 3} };
	int n = sizeof(items) / sizeof(items[0]);
	int capacity;

	printf("가방 선택 ( 용량 : 1 ~ 10) : ");
	scanf_s("%d", &capacity);

	printf("최대 가치 : %d\n", knapsack(items, n, capacity));

}