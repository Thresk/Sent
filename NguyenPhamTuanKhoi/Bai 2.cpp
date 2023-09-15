#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NgayThangNam
{
	int Ngay, Thang, Nam;
};

struct NhanVien
{
	int MaNhanVien; 
	char TenNhanVien[50];
	NgayThangNam NgaySinh;
	int GioiTinh;
	float Luong;
};

void NhapNgaySinh(NgayThangNam& nt)
{
	printf("Nhap ngay thang nam sinh nhan vien: ");
	scanf("%d%d%d", &nt.Ngay, &nt.Thang, &nt.Nam);
}

void InNgaySinh(NgayThangNam nt)
{
	printf("Ngay thang nam sinh: %02d/%02d/%02d\n", nt.Ngay, nt.Thang, nt.Nam);
}

void NhapThongTinNhanVien(NhanVien& nv)
{
	printf("Ma nhan vien: ");
	scanf("%d", &nv.MaNhanVien);
	getchar();
	printf("Ten nhan vien: ");
	gets_s(nv.TenNhanVien);
	NhapNgaySinh(nv.NgaySinh);
	printf("Gioi tinh (1 la Nam, 0 la Nu): ");
	scanf("%d", &nv.GioiTinh);
	printf("Luong: ");
	scanf("%f", &nv.Luong);
	printf("\n");
	fflush(stdin);
}

void InThongTinNhanVien(NhanVien nv)
{
	printf("Ma nhan vien: %d\n", nv.MaNhanVien);
	printf("Ten nhan vien :%s\n", nv.TenNhanVien);
	InNgaySinh(nv.NgaySinh);
	if (nv.GioiTinh == 1)
		printf("Gioi tinh Nam\n");
	if (nv.GioiTinh == 0)
		printf("Gioi tinh Nu\n");
	printf("Luong: %.02f\n", nv.Luong);
	printf("\n");
}

void NhapMang(NhanVien nv[100], int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf("So thu tu: %d\n", i+1);
		NhapThongTinNhanVien(nv[i]);
	}
}

void XuatMang(NhanVien nv[100], int n)
{
	printf("\n");
	for (int i = 0; i <= n; i++)
	{
		printf("So thu tu: %d\n", i+1);
		InThongTinNhanVien(nv[i]);
	}
}

void NVTren25Tuoi(NgayThangNam nt, NhanVien nv[100], int n)
{
	printf("Danh sach nhung nguoi tren 25 tuoi: \n");
	for (int i = 0; i <= n; i++)
	{
		int Tuoi = 2023 - nv[i].NgaySinh.Nam;
		if (Tuoi > 25)
			printf("%s\n", nv[i].TenNhanVien);
	}
	
}

void NVLuongTren10TR(NhanVien nv[100], int n)
{
	printf("Danh sach nhung nhan vien luong tren 10tr: ");
	for (int i = 0; i <= n; i++)
	{
		if ((nv[i].Luong > 10.00) && (nv[i].GioiTinh == 1))
			printf("%s\n", nv[i].TenNhanVien);
	}
}

void GiamDanLuong(NhanVien nv[100], int n)
{
	printf("Danh sach nhan vien theo thu tu giam dan luong: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nv[i].Luong > nv[j].Luong)
			{
				NhanVien temp = nv[i];
				nv[i] = nv[j];
				nv[j] = temp;
			
			}
		}printf("%s\n", nv[i].TenNhanVien);
	}
}

void main()
{
	NgayThangNam nt{};
	NhanVien nv[100];
	int n;
	printf("So luong nhan vien: ");
	scanf("%d", &n);
	n -= 1;
	NhapMang(nv, n);
	XuatMang(nv, n);
	NVTren25Tuoi(nt, nv, n);
	NVLuongTren10TR(nv, n);
	GiamDanLuong(nv, n);
}

