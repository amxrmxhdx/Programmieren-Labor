#include <stdio.h>

void bs(int ar[], int l) {
	int i, j, t;

	for (i = 1; i < l; i++) {
		for (j = 0; j < l - 1; j++) {
			if (ar[j] > ar[j + 1]) {
				t = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = t;
			}
		}
	}
}

int main() {
	int ar[10] = {100, 20, 123, 433, 1236, 9853, 222, 999, 134, 58};

	for (int i = 0; i < 10; i++) printf("%d, ", ar[i]);

	printf("\n");

	bs(ar, 10);

	for (int i = 0; i < 10; i++) printf("%d, ", ar[i]);

	return 0;
}

