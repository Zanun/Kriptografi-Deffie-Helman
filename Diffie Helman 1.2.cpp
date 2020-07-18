#include <iostream>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>


using namespace std;

void sender()
{
	int *p = (int *) malloc(sizeof(int)); //value tapi ada address memory
	int *g = (int *) malloc(sizeof(int));
	int *privatekey = (int *) malloc(sizeof(int));
	int *publickeysender = (int *) malloc(sizeof(int));
	int *publickeyreceiver = (int *) malloc(sizeof(int));
	int *k = (int *) malloc(sizeof(int));
	cout << "root@naeun-acer:~# input p : ";
	cin >> *p;
	//cout << &p<<endl;
	cout << "root@naeun-acer:~# input g : ";
	cin >> *g;
	//cout << &p<<endl;
	cout << "root@naeun-acer:~# input Kunci private : ";
	cin >> *privatekey;
	//cout << &privatekey<<endl;
	unsigned long long int a, b; //variabel bantuan pangkat
	a = pow(*g,*privatekey); //g**privatekey%p
	*publickeysender = fmod(a,*p);
	cout << "Kunci Publik : " << *publickeysender << endl;
	//cout << &publickeysender<<endl;
	cout << "root@naeun-acer:~# input kunci publik receiver : ";
	cin >> *publickeyreceiver;
	//cout << &publickeyreceiver<<endl;
	b = pow(*publickeyreceiver,*privatekey); // publickeyreceiver**privatekey%p
	*k = fmod(b,*p);
	cout << "K = " << *k << endl;
	//cout << &k<<endl;
	int *jk = (int *)malloc(sizeof(int));
	int x;
	char *kar1[*jk]={};
	char *kar11 = (char *)calloc(*jk,sizeof(char));//bisa aja buat bantuan untuk mengisi value (pesan memory) pada kar1 diperulangan
	int *kar2[*jk]={};
	int *kar22 = (int *)calloc(*jk,sizeof(int));
	char *kar3[*jk]={};
	char *kar33 = (char *)calloc(*jk,sizeof(char));
	cout << "-------------PROCESSING--------------------\n";
posnan:
	cout << "Masukkan jumlah karakter : ";
	cin >> *jk;
	//cout << &jk << endl;
	for(x = 1; x <= *jk; x++)
	{
		kar1[x-1]= (char *) calloc(kar11[x-1],sizeof(char)); //mesan memory //kar11 diatas mesan memory, lalu memorynya kar11 dipakai kar1 di perulangan
		cout << "Masukkan pesan ke-" << x << ": ";
		cin >> *(kar1[x-1]);
		//cout << *kar1[x-1] <<endl;
		//cout << &kar1[x-1]<<endl; //3 karakter maka setiap karakter punya alokasi memory sendiri2
	}
	for(x = 1; x <= *jk; x++)
	{
		kar2[x-1]= (int *) calloc(kar22[x-1],sizeof(int));
		*(kar2[x-1])=(int) *(kar1[x-1]);
		//cout << *(kar2[x-1]) << endl;
		//cout << &(kar2[x-1]) << endl;
	}
	for(int x = 1; x <= 10; x++)
	{
		cout << "Loading " << x*10 << "%" << endl;
	}
	for(x = 1; x <= *jk; x++)
	{
		*(kar2[x-1]) = *(kar2[x-1])^*(k);
	}
	for(x = 1; x <= *jk; x++)
	{
		kar3[x-1]= (char *) calloc(kar33[x-1],sizeof(char));
		*(kar3[x-1])=(char) *(kar2[x-1]);
		cout << "Hasil : " << "("<< *(kar3[x-1]) << ")" << endl;
		//cout << &(kar3[x-1]) << endl;
	}
	cout << "======================================================\n";
	char *lanjut = (char *)malloc(sizeof(char));
	cout << "Do It Again (y/n) : ";
	cin >> *lanjut;
	//cout << &lanjut;
	if(*lanjut == 'y')
	{
		goto posnan;
	}
	else if(*lanjut == 'n')
	{
		cout << "Thank You *^_^*" << endl;
		cout << "Shutting Down!!!" << endl;
	}
	else
	{
		cout << "Kon milih y/n ra gelem" << endl;
		cout << "Shutting Down!!!" << endl;
	}
}
void receiver()
{
	int *p = (int *) malloc(sizeof(int));
	int *g = (int *) malloc(sizeof(int));
	int *privatekey = (int *) malloc(sizeof(int));
	int *publickeyreceiver = (int *) malloc(sizeof(int));
	int *publickeysender = (int *) malloc(sizeof(int));
	int *k = (int *) malloc(sizeof(int));
	cout << "jeong@eunji-acer:~$ input p : ";
	cin >> *p;
	//cout << &p<<endl;
	cout << "jeong@eunji-acer:~$ input g : ";
	cin >> *g;
	//cout << &g<<endl;
	cout << "jeong@eunji-acer:~$ input kunci private : ";
	cin >> *privatekey;
	//cout << &privatekey<<endl;
	unsigned long long int c, d; //bantuan pangkat
	c = pow(*g,*privatekey);
	*publickeyreceiver = fmod(c,*p);
	cout << "Kunci Publik : " << *publickeyreceiver << endl;
	//cout << &publickeyreceiver<<endl;
	cout << "jeong@eunji-acer:~$ input kunci publik sender : ";
	cin >> *publickeysender;
	//cout << &publickeysender<<endl;
	d = pow(*publickeysender,*privatekey);
	*k = fmod(d,*p);
	cout << "K = " << *k << endl;
	//cout << &k<<endl;
	int *jk1 = (int *) malloc(sizeof(int));
	int y;
	char *lar1[*jk1]={};
	char *lar11 = (char *)calloc(*jk1,sizeof(char));
	int *lar2[*jk1]={};
	int *lar22 = (int *)calloc(*jk1,sizeof(int));
	char *lar3[*jk1]={};
	char *lar33 = (char *)calloc(*jk1,sizeof(char));
	
	cout << "-------------PROCESSING--------------------\n";
citadel:
	cout << "Masukkan jumlah karakter : ";
	cin >> *jk1;
	//cout << &jk1 << endl;
	for(y = 1; y <= *jk1; y++)
	{
		lar1[y-1]= (char *) calloc(lar11[y-1],sizeof(char));
		cout << "Masukkan pesan ke-" << y << ": ";
		cin >> *(lar1[y-1]);
	//	cout << *lar1[y-1] <<endl;
	//	cout << &lar1[y-1]<<endl;
	}
	for(y = 1; y <= *jk1; y++)
	{
		lar2[y-1]= (int *) calloc(lar22[y-1],sizeof(int));
		*(lar2[y-1])=(int) *(lar1[y-1]);
	//	cout << *lar2[y-1] <<endl;
	//	cout << &lar2[y-1]<<endl;
	}
	for(int y = 1; y <= 10; y++)
	{
		cout << "Loading " << y*10 << "%" << endl;
	}
	for(y = 1; y <= *jk1; y++)
	{
		*(lar2[y-1]) = *(lar2[y-1])^*(k);
	}
	for(y = 1; y <= *jk1; y++)
	{
		lar3[y-1]= (char *) calloc(lar33[y-1],sizeof(char));
		*(lar3[y-1])=(char) *(lar2[y-1]);
		cout << "Hasil : " << "("<< *(lar3[y-1]) << ")" << endl;
	//	cout << &(lar2[y-1]) << endl;
	}
	cout << "======================================================\n";
	char *lanjut = (char *)malloc(sizeof(char));
	cout << "Do It Again (y/n) : ";
	cin >> *lanjut;
	//cout << &lanjut << endl;
	if(*lanjut == 'y')
	{
		goto citadel;
	}
	else if(*lanjut == 'n')
	{
		cout << "Thank You *^_^*" << endl;
		cout << "Shutting Down!!!" << endl;
	}
	else
	{
		cout << "Kon milih y/n ra gelem" << endl;
		cout << "Shutting Down!!!" << endl;
	}
}
int main()
{
	int *pilih = (int *)malloc(sizeof(int));
	cout << "IMPLEMENTASI ENKRIPSI SEDERHANA KUNCI PUBLIK DIFFIE HELMAN" << endl;
	cout << "==========================================================" << endl;
	cout << "1. Sender\n";
	cout << "2. Receiver\n";
bunker:	
	cout << "Pilih mode (1/2) : ";
	cin >> *pilih;
	//cout << &pilih << endl;
	if (*pilih == 1)
	{
		cout << "======================================================\n";
		cout << "[][][][][][[][][][][]MODE SENDER[][][][][][][][][][][]" << endl;
		sender();
	}
	else if(*pilih == 2)
	{
		cout << "======================================================\n";
		cout << "[][][][][][][][][][][]MODE RECEIVER[][][][][][][][][][][][]" << endl;
		receiver();
	}
	else
	{
		cout << "Pilih 1/2 ......................" << endl;
		goto bunker;
	}
}
