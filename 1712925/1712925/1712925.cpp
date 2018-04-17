#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<wchar.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <io.h> 

struct sinhvien
{
	wchar_t* mssv;
	wchar_t* hovaten;
	wchar_t* khoc;
	wchar_t* khoa;
	wchar_t* ngaysinh;
	wchar_t* hinhcanhan;
	wchar_t* mail;
	wchar_t* motabanthan;
	wchar_t* sothichx;
};

int len(wchar_t s[])
{
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	return i;
}

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
int finding(FILE* f, wchar_t s[])
{
	int j, pos = 0;
	while (!feof(f)){
		j = 0;
		fseek(f, pos, SEEK_SET);
		for (int i = 0; i < len(s); i++){
			if (fgetwc(f) == s[i]){
				j++;
			}
			else{
				break;
			}
		}
		if (j == len(s) - 1){
			return ftell(f);
		}
		else{
			fseek(f, pos + 1, SEEK_SET);
		}
		pos++;
	}
	return -1;
}



void doc(FILE* fIn, sinhvien &x, int &begin)
{
	int a = token(fIn, L',');
	x.mssv = (wchar_t*)malloc(sizeof(wchar_t)*(a - 5));
	fseek(fIn, begin, SEEK_SET);
	fgetws(x.mssv, a + 2, fIn);
	int b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.mssv);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b, SEEK_SET);
	fgetws(x.hovaten, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.hovaten);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b, SEEK_SET);
	fgetws(x.khoa, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.khoa);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b, SEEK_SET);
	fgetws(x.khoc, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.khoc);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b, SEEK_SET);
	fgetws(x.ngaysinh, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.ngaysinh);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b, SEEK_SET);
	fgetws(x.hinhcanhan, a + 2, fIn);
	b = ftell(fIn) + 1;
	wprintf(L"%ls\n", x.hinhcanhan);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b, SEEK_SET);
	fgetws(x.motabanthan, a + 2, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.motabanthan);

	if (fgetwc(fIn) == L','){
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, NULL);
		x.sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x.sothichx, 100, fIn);
		wprintf(L"%ls\n", x.sothichx);
	}
	else{
		fseek(fIn, b, SEEK_SET);
	}


	begin = ftell(fIn);
}

void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE* fIn;
	_wfopen_s(&fIn, L"Book123.csv", L"r, ccs=UTF-8");
	if (fIn == NULL)
	{
		wprintf(L"Không mở được FILE!!!\n");
	}
	else
	{
		int i = 0, begin = 3;
		sinhvien* x;
		fgetwc(fIn);
		while (!feof(fIn)){
			i++;
			x = (sinhvien*)malloc(sizeof(sinhvien)*i);
			doc(fIn, x[i - 1], begin);
			fgetwc(fIn);
		}
		for (int j = 0; j < i; j++){
			free(x[j].mssv);
			free(x[j].hovaten);
			free(x[j].khoa);
			free(x[j].khoc);
			free(x[j].ngaysinh);
			free(x[j].motabanthan);
			free(x[j].sothichx);
		}
		free(x);
		fclose(fIn);

	}

	_getch();
}