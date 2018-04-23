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
int token(FILE* f, wchar_t h);
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
			return i + 1;
	}
	return i;
}
void doc(FILE* fIn, sinhvien *x, int &begin);
void doc(FILE* fIn, sinhvien *x, int &begin)
{

	int a, b;
	fseek(fIn, begin, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, begin, SEEK_SET);
		a = token(fIn, L',');
		x->mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, begin, SEEK_SET);
		fgetws(x->mssv, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, begin + 1, SEEK_SET);
		a = token(fIn, L'"');
		x->mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, begin + 1, SEEK_SET);
		fgetws(x->mssv, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->mssv);

	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x->hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x->hovaten, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x->hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x->hovaten, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->hovaten);


	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x->khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x->khoa, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x->khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x->khoa, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->khoa);


	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x->khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x->khoc, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x->khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x->khoc, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->khoc);


	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x->ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x->ngaysinh, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x->ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x->ngaysinh, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->ngaysinh);


	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x->hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x->hinhcanhan, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x->hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x->hinhcanhan, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->hinhcanhan);



	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x->motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x->motabanthan, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x->motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x->motabanthan, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"%ls\n", x->motabanthan);



	fseek(fIn, b, SEEK_SET);
	if (fgetwc(fIn) == L','){
		if (fgetwc(fIn) != L'"'){
			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, '\n');
			x->sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x->sothichx, a, fIn);
			b = ftell(fIn);
			begin = b;
		}
		else{
			fseek(fIn, b + 2, SEEK_SET);
			a = token(fIn, '"');
			x->sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 2, SEEK_SET);
			fgetws(x->sothichx, a, fIn);

			b = ftell(fIn) + 1;

		}
		wprintf(L"%ls\n\n", x->sothichx);
		begin = b + 2;
	}
	else{
		begin = b;
	}
}
int len(wchar_t s[]);
int len(wchar_t s[])
{
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	return i;
}
void saochepchuoi(wchar_t* str, wchar_t* s);
void saochepchuoi(wchar_t* str, wchar_t* s)
{
	int a = len(s);
	for (int i = 0; i < a; i++)
	{
		str[i] = s[i];
	}
	str[a] = '\0';
}
void ghepchuoi(wchar_t* str, wchar_t* s);
void ghepchuoi(wchar_t* str, wchar_t* s)
{ 
	int a = len(str);
	int m = len(str) + len(s);
	for (int i = 0; i < m; i++)
	{
		if (i == a)
		{
			for (int j = 0; j < len(s); j++)
			{
				str[i] = s[j];
				i++;
			}
		}
	}
	str[m] = '\0';
}
void ghifile(sinhvien* x);
void ghifile(sinhvien* x)
{
	wchar_t filename[50];
	saochepchuoi(filename, x->mssv);
	ghepchuoi(filename, L".html");
	FILE* f;
	_wfopen_s(&f, filename, L"wt,ccs=UTF-8");
	_setmode(_fileno(f), _O_U8TEXT);
	if (f == NULL)
	{
		wprintf(L"Tạo file lỗi!!!\n");
	}
	else
	{
		fwprintf(f, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"	<head>\n");
		fwprintf(f, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
		fwprintf(f, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
		fwprintf(f, L"		<title>HCMUS - %ls</title>\n", x->hovaten);
		fwprintf(f, L"	</head>\n");
		fwprintf(f, L"	<body>\n");
		fwprintf(f, L"		<div class=\"Layout_container\">\n");
		fwprintf(f, L"			<!-- Begin Layout Banner Region -->\n");
		fwprintf(f, L"			<div class=\"Layout_Banner\" >\n");
		fwprintf(f, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(f, L"				<div class=\"Header_Title\">TRƯỜNG ÐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
		fwprintf(f, L"			</div>\n");
		fwprintf(f, L"			<!-- End Layout Banner Region -->\n");
		fwprintf(f, L"			<!-- Begin Layout MainContents Region -->\n");
		fwprintf(f, L"			<div class=\"Layout_MainContents\">\n");
		fwprintf(f, L"				<!-- Begin Below Banner Region -->\n");
		fwprintf(f, L"				<div class=\"Personal_Main_Information\">\n");
		fwprintf(f, L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
		fwprintf(f, L"					<div class=\"Personal_Location\"> \n");
		fwprintf(f, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(f, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", x->hovaten, x->mssv);
		fwprintf(f, L"						<div class=\"Personal_Department\">%ls</div>\n", x->khoa);
		fwprintf(f, L"						<br />\n");
		fwprintf(f, L"						<div class=\"Personal_Phone\">\n");
		fwprintf(f, L"						Email: \n");
		fwprintf(f, L"						</div>\n");
		fwprintf(f, L"						<br />\n");
		fwprintf(f, L"						<br />\n");
		fwprintf(f, L"					</div>\n");
		fwprintf(f, L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
		fwprintf(f, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
		fwprintf(f, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", x->hinhcanhan);
		fwprintf(f, L"					</div>\n");
		fwprintf(f, L"				</div>\n");
		fwprintf(f, L"				<!-- End Below Banner Region -->\n");
		fwprintf(f, L"				<!-- Begin MainContents Region -->\n");
		fwprintf(f, L"				<div class=\"MainContain\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"					<!-- Begin Top Region -->\n");
		fwprintf(f, L"					<div class=\"MainContain_Top\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f, L"                       <div>\n");
		fwprintf(f, L"                            <ul class=\"TextInList\">\n");
		fwprintf(f, L"                              <li>Họ và tên: %ls </li>\n", x->hovaten);
		fwprintf(f, L"								 <li>MSSV: %ls </li>\n", x->mssv);
		fwprintf(f, L"								 <li>Sinh viên khoa: %ls </li>\n", x->khoa);
		fwprintf(f, L"								 <li>Khóa Học: %ls </li>\n", x->khoc);
		fwprintf(f, L"								 <li>Ngày sinh: %ls </li>\n", x->ngaysinh);
		fwprintf(f, L"							 </ul>\n");
		fwprintf(f, L"						</div>\n");
		fwprintf(f, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(f, L"                       <div>\n");
		fwprintf(f, L"                            <ul class=\"TextInList\">\n");
		fwprintf(f, L"                              <li>%ls</li>\n", x->sothichx);
		fwprintf(f, L"							 </ul>\n");
		fwprintf(f, L"						</div>\n");
		fwprintf(f, L"						<div class=\"InfoGroup\">Mô tả bản thân</div>\n");
		fwprintf(f, L"						<div>\n");
		fwprintf(f, L"							<ul class=\"Description\">\n");
		fwprintf(f, L"                            <li>%ls</li>\n", x->motabanthan);
		fwprintf(f, L"							</ul>\n");
		fwprintf(f, L"						</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"					</div>\n");
		fwprintf(f, L"				</div>\n");
		fwprintf(f, L"			</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"			<!-- Begin Layout Footer -->\n");
		fwprintf(f, L"			<div class=\"Layout_Footer\">\n");
		fwprintf(f, L"				<div class=\"divCopyright\">\n");
		fwprintf(f, L"					<br />\n");
		fwprintf(f, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
		fwprintf(f, L"					<br />\n");
		fwprintf(f, L"				@2018</br>\n");
		fwprintf(f, L"				Ðồ án giữa kì</br>\n");
		fwprintf(f, L"				Kĩ thuật lập trình</br>\n");
		fwprintf(f, L"				TH2018/04</br>\n");
		fwprintf(f, L"				1712925 - phạm văn vương</br>\n");
		fwprintf(f, L"				</div>\n");
		fwprintf(f, L"			</div>\n");
		fwprintf(f, L"			<!-- End Layout Footer -->\n");
		fwprintf(f, L"		</div>\n");
		fwprintf(f, L"	</body>\n");
		fwprintf(f, L"</html>");
		fclose(f);
	}
}
void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE* fIn;
	_wfopen_s(&fIn, L"ThongTin.csv", L"r, ccs=UTF-8");
	if (fIn == NULL)
	{
		wprintf(L"Không mở được FILE!!!\n");
	}
	else
	{
		int n = 0, begin = 3;
		sinhvien* x;
		while (!feof(fIn))
		{
			if (fgetwc(fIn) == L'\n')
			{
				n++;
			}
		}
		x = (sinhvien*)malloc(sizeof(sinhvien)* n);
		for (int i = 0; i <n;i++)
		{
			doc(fIn, &x[i], begin);
			ghifile(&x[i ]);

		}
		free(x);
		fclose(fIn);

	}

	_getch();
}