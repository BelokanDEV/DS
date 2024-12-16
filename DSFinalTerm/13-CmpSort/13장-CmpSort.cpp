#include <time.h>
#include "SortAlgorithms.h"
extern void quickSort2(int v[], int left, int right);

void compareRandomDataSort(int iter) {
	clock_t t0, t1;
	int*	org = new int[MAX_NUM];
	int*	list = new int[MAX_NUM];
	int		n, i;
	double	dSel, dIns, dBub, dShl, dMgr, dHea, dQuk;

	printf("  n      ����     ����     ����      ��      ����     ����     ��\n");
	for (n = 1000; n < MAX_NUM; n += 3000) {
		dSel = dIns = dBub = dShl = dMgr = dHea = dQuk = 0.0;

		for (i = 0; i < iter; i++) {
			initRandom(org, n);
			//printf("���� ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			selectionSort(list, n);
			t1 = clock();
			dSel += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			insertionSort(list, n);
			t1 = clock();
			dIns += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			bubbleSort(list, n);
			t1 = clock();
			dBub += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("�� ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			shellSort(list, n);

			t1 = clock();
			dShl += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			mergeSort(list, 0, n - 1);
			t1 = clock();
			dMgr += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			heapSort(list, n);
			t1 = clock();
			dHea += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("��1 ����:\n");
			copyArray(org, list, n);
			t0 = clock();
			//quickSort(list, 0, n - 1);
			quickSort2(list, 0, n - 1);
			t1 = clock();
			dQuk += (double)(t1 - t0) / CLOCKS_PER_SEC;
		}

		printf("%6d %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f\n", n,
			dSel / iter, dIns / iter, dBub / iter, dShl / iter, dMgr / iter, dHea / iter, dQuk / iter);
	}
	delete[] org;
	delete[] list;
}


void compareWorstDataSort(int iter) {
	clock_t t0, t1;
	int*	org = new int[MAX_NUM];
	int*	list = new int[MAX_NUM];
	int		n, i;
	double	dSel, dIns, dBub, dShl, dMgr, dHea, dQuk;

	printf("  n      ����     ����     ����      ��      ����     ����     ��\n");
	for (n = 1000; n < MAX_NUM; n += 1000) {
		dSel = dIns = dBub = dShl = dMgr = dHea = dQuk = 0.0;

		for (i = 0; i < iter; i++) {
			//initRandom(org, n);
			//printf("���� ����:\n");
			initRandom(list, n);		// ����: ����
			t0 = clock();
			selectionSort(list, n);
			t1 = clock();
			dSel += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			initDescend(list, n);		// ����: ���� �־�
			t0 = clock();
			insertionSort(list, n);
			t1 = clock();
			dIns += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			initDescend(list, n);		// ����: ���� �־�
			t0 = clock();
			bubbleSort(list, n);
			t1 = clock();
			dBub += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("�� ����:\n");
			initRandom(list, n);		// ��: ����
			t0 = clock();
			shellSort(list, n);

			t1 = clock();
			dShl += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			initRandom(list, n);		// ����: ����
			t0 = clock();
			mergeSort(list, 0, n - 1);
			t1 = clock();
			dMgr += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("���� ����:\n");
			initRandom(list, n);		// ����: ����
			t0 = clock();
			heapSort(list, n);
			t1 = clock();
			dHea += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("��1 ����:\n");
			initAscend(list, n);		// ��: ���ĵ� �־�
			t0 = clock();
			quickSort2(list, 0, n - 1);
			//quickSort(list, 0, n - 1);
			//printArray(list, n, "QSort:");
			t1 = clock();
			dQuk += (double)(t1 - t0) / CLOCKS_PER_SEC;
		}

		printf("%6d %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f\n", n,
			dSel / iter, dIns / iter, dBub / iter, dShl / iter, dMgr / iter, dHea / iter, dQuk / iter);
	}
	free(org);
	free(list);
}


void main()
{
	printf("\n[13.(2)] ��� ���� �ð� (Random)\n");
	//compareRandomDataSort(2);
	printf("\n[13.(3)] �־��� ���� �ð�\n");
	compareWorstDataSort(1);
}

