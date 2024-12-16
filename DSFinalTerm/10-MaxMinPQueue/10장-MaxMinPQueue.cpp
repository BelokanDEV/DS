#include "MaxPriorityQueue.h"
#include "MinPriorityQueue.h"
#define MAXELEM		20

int isMinHeapRecur(int* list, int len, int id) {
	int iLeft = id * 2;
	int iRight= id * 2 + 1;
	if (id >= len) return 1;
	if (iLeft <= len && list[iLeft] < list[id]) return 0;
	if (iRight<= len && list[iRight]< list[id]) return 0;
	if (isMinHeapRecur(list, len, iLeft) == 0) return 0;
	if (isMinHeapRecur(list, len, iRight)== 0) return 0;
	return 1;
}
int isMinHeapIter(int* list, int len) {
	int i, iLeft, iRight;
	for (i = 1; i < len; i++) {
		iLeft = i * 2;
		iRight= i * 2 + 1;

		if (iLeft <= len && list[iLeft] < list[i]) return 0;
		if (iRight<= len && list[iRight]< list[i]) return 0;
	}
	return 1;
}

int isMaxHeapIter(int* list, int len) {
	int i, iLeft, iRight;
	for (i = 1; i < len; i++) {
		iLeft = i * 2;
		iRight = i * 2 + 1;

		if (iLeft <= len && list[iLeft] > list[i]) return 0;
		if (iRight <= len && list[iRight]> list[i]) return 0;
	}
	return 1;
}

int isMaxHeapRecur(int* list, int len, int id) {
	int iLeft = id * 2;
	int iRight = id * 2 + 1;
	if (id >= len) return 1;
	if (iLeft <= len && list[iLeft]  > list[id]) return 0;
	if (iRight <= len && list[iRight]> list[id]) return 0;
	if (isMaxHeapRecur(list, len, iLeft) == 0) return 0;
	if (isMaxHeapRecur(list, len, iRight) == 0) return 0;
	return 1;
}


void main()
{
	int i, val, lMax[100], lMin[100];
	MaxPriorityQueue qMax;
	MinPriorityQueue qMin;


	//========================================================
	printf("(1) MaxHeap (���ĵ��� ���� �迭)\n");
	printf("(2) MinHeap (���ĵ� ���� ����Ʈ)\n");
	for (i = 0; i < MAXELEM; i++) {
		val = rand() % 100;
		qMax.insert(val);
		qMin.insert(val);
	}
	qMax.display();
	qMin.display();

	lMin[0] = lMax[0] = -1;
	for (i = 1; i <= MAXELEM; i++) {
		val = qMin.remove();
		printf("%2d %2d\n", val, qMax.remove());

		lMin[i] = val;
		lMax[MAXELEM-i+1] = val;
	}

	//========================================================
	printf("(3) �� ���� �˻�\n");
	printf(" MIN LIST: ");
	for (i = 0; i <= MAXELEM; i++)
		printf("%2d ", lMin[i]);
	printf("\n");

	val = isMinHeapRecur(lMin, MAXELEM, 1);
	printf(" �ּ��� ������ %s(��ȯ)\n", (val == 0) ? "Ʋ��" : "����");
	val = isMinHeapIter(lMin, MAXELEM);
	printf(" �ּ��� ������ %s(�ݺ�)\n", (val == 0) ? "Ʋ��" : "����");
	val = isMaxHeapRecur(lMin, MAXELEM, 1);
	printf(" �ִ��� ������ %s(��ȯ)\n", (val == 0) ? "Ʋ��" : "����");
	val = isMaxHeapIter(lMin, MAXELEM);
	printf(" �ִ��� ������ %s(�ݺ�)\n", (val == 0) ? "Ʋ��" : "����");

	printf("\n MAX LIST: ");
	for (i = 0; i <= MAXELEM; i++)
		printf("%2d ", lMax[i]);
	printf("\n");

	val = isMinHeapRecur(lMax, MAXELEM, 1);
	printf(" �ּ��� ������ %s(��ȯ)\n", (val == 0) ? "Ʋ��" : "����");
	val = isMinHeapIter(lMax, MAXELEM);
	printf(" �ּ��� ������ %s(�ݺ�)\n", (val == 0) ? "Ʋ��" : "����");
	val = isMaxHeapRecur(lMax, MAXELEM, 1);
	printf(" �ִ��� ������ %s(��ȯ)\n", (val == 0) ? "Ʋ��" : "����");
	val = isMaxHeapIter(lMax, MAXELEM);
	printf(" �ִ��� ������ %s(�ݺ�)\n", (val == 0) ? "Ʋ��" : "����");

}
