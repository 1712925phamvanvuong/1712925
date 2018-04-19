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
			return i+1;
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
int findlen(FILE* f, int pos, wchar_t x)
{
	int i = 0;
	while (fgetwc(f) != x)
	{
		i++;
	}
	return i - 1;
}

void replace(FILE* f, wchar_t s[], int pos, wchar_t x)
{
	if (findlen(f, pos, x) > len(s))
	{
		fseek(f, pos + 1, SEEK_SET);
		while (fgetwc(f) != L'-')
			fputwc(L' ', f);
		fseek(f, pos + 1, SEEK_SET);
		fputws(s, f);
	}
	else
	{
		wchar_t tmp[1000];
		fseek(f, findlen(f, pos, x) + pos, SEEK_SET);
		fgetws(tmp, 1000, f);
		wprintf(L"%ls", tmp);
		fseek(f, pos, SEEK_SET);
		fputws(s, f);
		fputws(tmp, f);
	}
}


void doc(FILE* fIn, sinhvien &x, int &begin)
{
	fseek(fIn, begin, SEEK_SET);
	int a = token(fIn, L',');
	x.mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, begin, SEEK_SET);
	fgetws(x.mssv, a, fIn);
	int b = ftell(fIn);
	wprintf(L"%ls\n", x.mssv);



	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.hovaten, a, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.hovaten);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.khoa, a, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.khoa);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.khoc, a, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.khoc);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.ngaysinh, a, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.ngaysinh);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.hinhcanhan, a, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.hinhcanhan);


	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.mail = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.mail, a, fIn);
	b = ftell(fIn);
	wprintf(L"%ls\n", x.mail);



	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x.motabanthan, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x.motabanthan, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x.motabanthan);



	fseek(fIn, b, SEEK_SET);
	if (fgetwc(fIn) == L','){
		if (fgetwc(fIn) != L'"'){
			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, '\n');
			x.sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x.sothichx, a, fIn);
			b = ftell(fIn);
			begin = b;
		}
		else{
			fseek(fIn, b + 2, SEEK_SET);
			a = token(fIn, '"');
			x.sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 2, SEEK_SET);
			fgetws(x.sothichx, a, fIn);

			b = ftell(fIn) + 1;
			fgetwc(fIn);
			fgetwc(fIn);

		}
		wprintf(L"%ls\n\n", x.sothichx);
		begin = b + 2;
	}
	else{
		begin = b;
	}
}




void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE* fIn;
	_wfopen_s(&fIn, L"ds.csv", L"r, ccs=UTF-8");
	if (fIn == NULL)
	{
		wprintf(L"Không mở được FILE!!!\n");
	}
	else
	{
		int i = 0, begin = 3;
		sinhvien* x;
		x = (sinhvien*)malloc(sizeof(sinhvien)* 11);
		while (!feof(fIn)){
			i++;

			doc(fIn, x[i - 1], begin);
		}
		free(x);
		fclose(fIn);

	}

	_getch();
}