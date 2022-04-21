#include <stdio.h>

//nhap mang
void Input(int *Arr ,int &n) {
	int i;
	for( i = 0; i < n; i++) {
		printf("phan tu %d ", i); scanf("%d", &Arr[i]);
	}
}

// tong cac phtu mang
int SumArr(int *Arr, int &n, int &sum) {
	int i;
	for(i = 0; i < n; i++) {
		sum+=Arr[i];
	}
	return sum;
}

// tong cac phtu mang
int tichArr(int *Arr, int &n, int &tich) {
	int i;
	for(i = 0; i < n; i++) {
		tich*=Arr[i];
	}
	return tich;
}

// tim gia tri lon nhat
int maxLeft(int i, int j, int *Arr) {
	int max = Arr[0];
	if (i > j) return max;
	if(max < Arr[i]) {
		max = Arr[i];
		maxLeft(i++, j, Arr);
	}
}
int maxRight(int i, int j, int *Arr) {
	int max = Arr[i];
	if (i > j) return max;
	if(max < Arr[i]) {
		max = Arr[i];
		maxRight(i++, j, Arr);
	}

}
int max(int i, int &n, int *Arr) {
	int m = n/2;
	int ML = maxLeft(0, m, Arr);
	int MR = maxRight(m+1, n, Arr);
	if(ML > MR) return ML;
	if(ML < MR) return MR;
	return MR;
}

void display();
int main() {
	int n;
	printf("kich thuoc mang?"); scanf("%d", &n);
	int Arr[n];
	int sum = 0, tich = 1;
	Input(Arr, n);
	SumArr(Arr,n, sum);
	int Max = max(0,n,Arr);
	tich = tichArr(Arr, n, tich);
//	display(n, Arr, sum, Max, tich);
	display();
}
// in ra man hinh 
void display(/*int n, int *Arr, int sum, int max, int tich*/) {
	printf("mang vua nhap\n");
	for(int i = 0; i < n; i++) {
		printf("phan tu %d\n", Arr[i]);
	}
	printf("\ntong = %d", sum);
	printf("\ntich = %d", tich);
	printf("\nmax = %d", max);
}
