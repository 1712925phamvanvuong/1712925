#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<wchar.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <io.h> 
struct sinhvien
{
	char mssv[20];
	wchar_t hovaten[30];
	wchar_t khoc[30];
	char* khoa;
	char ngaysinh[12];
	char hinhcanhan[16];
	wchar_t* motabanthan;
	wchar_t* sothichx;
};

int token(FILE* f)
{
	wchar_t s[20];
	int i = 0;
	while (!feof(f)){
		if (s[i] != ','){
			s[i] = getc(f);
			i++;

		}
		else
			return fseek(f, 0, SEEK_CUR);
	}
	
	return fseek(f, 0, SEEK_CUR);
}

void docfile(sinhvien x);
void docfile(sinhvien x)
{
	

	FILE* fIn = fopen("C:\\Users\Dell\Desktop\Book1.txt", "rb");
	if (fIn == NULL)
	{
		printf("khong mo duoc FILE!!!\n");
	}
	else
	{
		int p = ftell(fIn);
		int tmp = token(fIn); 


		fgets(x.mssv, tmp-p, fIn);
		fseek(fIn, 4, tmp);


		p = tmp;
		tmp = token(fIn);
		fgetws(x.hovaten, tmp - p, fIn);
		fseek(fIn, 4, tmp);
		p = tmp;
		tmp = token(fIn);
		fgetws(x.khoc, tmp - p, fIn);
		fseek(fIn, 4, tmp);
		p = tmp;
		tmp = token(fIn);
		fgets(x.khoa, tmp - p, fIn);
		fseek(fIn, 4, tmp);
		p = tmp;
		tmp = token(fIn);
		fgets(x.ngaysinh, tmp - p, fIn);
		fseek(fIn, 4, tmp);
		p = tmp;
		tmp = token(fIn);
		fgets(x.hinhcanhan, tmp - p, fIn);
		fseek(fIn, 4, tmp);
		p = tmp;
		tmp = token(fIn);
		fgetws(x.motabanthan, tmp - p, fIn);
		fseek(fIn, 4, tmp);
		wchar_t last = fseek(fIn, 0, SEEK_END);
		fgetws(x.sothichx, last - tmp, fIn);
	}
	fclose(fIn);
}

void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	sinhvien x;
	docfile(x);
	printf("%ls", x.mssv);
	getch();
}