#include<iostream>
using namespace std;
void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		/* code */
		cout << a[i] << " ";
	}
	cout << endl;
}
void Merge(int r[], int rf[], int i, int m, int n) {
	int j = m + 1;
	int k = i;
	while (i <= m&&j <= n) {
		if (r[i]<r[j]) {
			rf[k++] = r[i++];
		}else{
			rf[k++] = r[j++];
		}
	}

	while (j <= n) {
		rf[k++] = r[j++];
	}


	while (i <= m) {
		rf[k++] = r[i++];
	}

	print(rf, n + 1);

}
void MergeSort(int r[], int rf[], int length) {
	int len = 1;
	int *tmp;
	while (len<length) {
		int s = len;
		int i = 0;
		len = 2 * s;
		while (i + len<length) {
			Merge(r, rf, i, i + s - 1, i + len - 1);
			i = i + len;
		}
		if (i + s<length) {
			Merge(r, rf, i, i + s - 1, length - 1);
		}
		tmp = r; r = rf; rf = tmp;//保证每次都是从数组r合向数组rf
	}

}
int main() {
	/* code */
	int a[10] = { 3,1,5,7,2,4,9,6,10,8 };
	int b[10];
	MergeSort(a, b, 10);
	cout << "结果：";
	print(a, 10);
	system("pause");
	return 0;
}
