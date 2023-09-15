#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void NhapRangeMaTranVuong(int& range)
{
	do
	{
		printf("Nhap hang, cot ma tran vuong: ");
		scanf("%d", &range);
	} while ((range < 0) || (range > 100));
}

void NhapMang(int matrix[100][100],int range)
{
	for (int i = 0; i <= range; i++)
	{
		for (int j = 0; j <= range; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

void XuatMang(int matrix[100][100], int range)
{
	printf("Ma tran vuong vua nhap: \n");
	for (int i = 0; i <= range; i++)
	{
		for (int j = 0; j <= range; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int KTSoNguyenTo(int n)
{
	int DemUS = 0;
	for (int k = 1; k <= n; k++)
	{
		if (n % k == 0)
		{
			DemUS++;
		}
	}
	if (DemUS == 2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void InDuongCheoPhu(int matrix[100][100], int range)
{
	printf("\nSo nguyen to tren duong cheo phu: \n");
	int DemUS = 0; 
	for (int i = 0; i <= range; i++)
	{
		for (int j = 0; j <= range; j++)
		{
			if (i + j == range)
			{
			int kt = KTSoNguyenTo(matrix[i][j]);
				if (kt == 0)
					printf("%d\n", matrix[i][j]);
			}
		}
	}
}

int SoLonThu1(int matrix[100][100],int range)
{
	int max1 = 0;
	for (int i = 0; i <= range; i++)
	{
		for (int j = 0; j <= range; j++)
		{
			if (matrix[i][j] > max1)
				max1 = matrix[i][j];
		}
	}
	return max1;
}

int SoLonThu2(int matrix[100][100],int range, int max1)
{
	int max2 = 0;
	for (int i = 0; i <= range; i++)
	{
		for (int j = 0; j <= range; j++)
		{
			if ((matrix[i][j] > max2)&& (matrix[i][j]< max1))
				max2 = matrix[i][j];
		}
	}
	return max2;
}

int TachSo(int n, int range)
{
	int temp = n;
	int Tong = 0;
	for (int i = 0; i <= range; i++)
	{
		while (n > 0)
		{
			temp = n % 10;
			Tong += temp;
			n /= 10;
		}
	}
	return Tong;
}

void TongChuSo(int matrix[100][100], int range)
{
	for (int i = 0; i <= range; i++)
	{
		for (int j = 0; j <= range; j++)
		{
			int Tong = TachSo(matrix[i][j], range);
			printf("\nTong chu so o a[%d][%d] = %d", i, j, Tong);
		}
	}
}

void main()
{
	int matrix[100][100];
	int range;
	NhapRangeMaTranVuong(range);
	range -= 1;
	NhapMang(matrix, range);
	XuatMang(matrix, range);
	InDuongCheoPhu(matrix, range);
	int max1 = SoLonThu1(matrix, range);
	int max2 = SoLonThu2(matrix, range, max1);
	printf("\nSo lon thu hai: %d", max2);
	TongChuSo(matrix, range);
}