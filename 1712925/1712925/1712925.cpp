#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<wchar.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <io.h> 


struct sinhvien
{
	wchar_t mssv[30];
	wchar_t hovaten[30];
	wchar_t khoc[30];
	wchar_t khoa[30];
	wchar_t ngaysinh[30];
	wchar_t hinhcanhan[30];
	wchar_t motabanthan[30];
	wchar_t sothichx[30];
};

int token(FILE* f, wchar_t h)
{
	wchar_t ch;
	int i = 0;
	while (!feof(f)){
		ch = fgetwc(f);
		if (ch != h)
		{
			i++;
		}
		else
			return i;
	}
	return i;
}

void docfile(FILE* fIN, sinhvien &x);
void docfile(FILE* fIn, sinhvien &x)
{

	int a = token(fIn, L',');

	fseek(fIn, 3, SEEK_SET);
	fgetws(x.mssv, a + 1, fIn);
	int b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.mssv);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	fseek(fIn, b, SEEK_SET);
	fgetws(x.hovaten, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.hovaten);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	fseek(fIn, b, SEEK_SET);
	fgetws(x.khoa, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.khoa);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	fseek(fIn, b, SEEK_SET);
	fgetws(x.khoc, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.khoc);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	fseek(fIn, b, SEEK_SET);
	fgetws(x.ngaysinh, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.ngaysinh);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	fseek(fIn, b, SEEK_SET);
	fgetws(x.hinhcanhan, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.hinhcanhan);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	fseek(fIn, b, SEEK_SET);
	fgetws(x.motabanthan, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.motabanthan);

	if (fgetwc(fIn) == L',')
	{
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, NULL);
		fseek(fIn, b, SEEK_SET);
		fgetws(x.sothichx, 100, fIn);
		wprintf(L"%ls\n", x.sothichx);
	}

}
void wmain()
{
	sinhvien x[5];
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input

	FILE* fIn;
	_wfopen_s(&fIn, L"test.txt", L"r, ccs=UTF-8");
	if (fIn == NULL)
	{
		wprintf(L"khong mo duoc FILE!!!\n");
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			docfile(fIn, x[i]);
		}

	}
	fclose(fIn);
	_getch();
}
