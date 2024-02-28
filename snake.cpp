#include<iostream>
#include "mylib.h"
#include <Windows.h>
#include <conio.h>
#include<time.h>
#define MAX 100
using namespace std;

int toa_doX[MAX] = {0};
int toa_doY[MAX] = {0};
int sl = 4;
int xqua = -1;
int yqua = -1;
int diem = 0;
int c,tt;
int *point;

void ve_tuong();
void khoitaoran();
void ve_ran();
void dichuyen(int x, int y);
bool game_over();
void vequa();
void taoqua();
bool ktanqua();
void anqua();
bool ktrandequa();
bool ktchamthan();
void MainMenu(int tt);
void Chedo(int i);
int TinhDiem();
void InDiem();
void Finish();


void play(){
	Nocurs();
	textcolor(9);
	ve_tuong();
	taoqua();
	vequa();
	khoitaoran();
	int x = toa_doX[0];
	int y = toa_doY[0];
	int check = 2;
	//------play----------
	while(true){
		//----xoa du lieu cu------------
				//system("cls");
				gotoXY(toa_doX[sl], toa_doY[sl]);
				cout<<"  ";
		//---------in----------
		ve_ran();
		//-----dieu khien--------
		if(_kbhit()){
			char c = _getch();
			if(c == -32){
				c = _getch();
				if(c== 72 && check != 0){
					check = 1;
				}
				else if(c == 80 && check !=1){
					check = 0;
				}
				else if(c == 75 && check != 2){
					check = 3;
				}
				else if(c == 77 && check != 3){
					check = 2;
				}		
			}
		}
		//------di chuyen-------
		if(check==0){
			y++;
		}	
		else if(check==1){
			y--;
		}
		else if(check==2){
			x++;
		}
		else if(check==3){
			x--;
		}
		//----------bien---------
		if(game_over()){
			Finish();
		//	InDiem();
			break;
		}
		anqua();
		//--------xu ly ran---------
		dichuyen(x,y);
		//------speed--------
		Sleep(100);
	}
	//InDiem();
}
void khoitaoran(){
	int x_kt = 50;
	int y_kt = 13;
	for(int i=0; i<sl; i++){
		toa_doX[i] = x_kt--;
		toa_doY[i] = y_kt;	
	}
}
void ve_ran(){
	for(int i=0; i<sl; i++){
		gotoXY(toa_doX[i], toa_doY[i]);
		if( i == 0 )
			cout<<"0";
		else
			cout<<"o";
	}
}

bool game_over(){
	if(toa_doX[0] == 10 || toa_doX[0] == 95 || toa_doY[0] == 1 || toa_doY[0] == 25){
		return true;
	}
	return ktchamthan();
	
}

void Finish(){
	while(game_over()){
		gotoXY(48,13);
		cout<<"GAME OVER :(";
		break;
	}
}

void taoqua(){
	do{	
	xqua = rand()%(94 - 11 + 1) + 11;
	yqua = rand()%(24 - 2 + 1) + 2;
	} while (ktrandequa());
}
void vequa(){
	gotoXY(xqua, yqua);
	textcolor(rand()%(12-1+1)+1);
	cout<<"$";
}

bool ktanqua(){
	return (toa_doX[0] == xqua && toa_doY[0] == yqua);
}

void anqua(){
	if(ktanqua()){
		sl++;
		taoqua();
		vequa();
		//TinhDiem();
		diem++;
	}
}

bool ktrandequa(){
	for(int i=0; i<sl; i++){
		if(xqua == toa_doX[i] && yqua == toa_doY[i]){
			return true;
		}
	}
	return false;
}

bool ktchamthan(){
	for(int i = 1; i<sl; i++){
		if(toa_doX[0] == toa_doX[i] && toa_doY[0] == toa_doY[i])
		return true;
	}
	return false;
}
//
//int TinhDiem(){
//	if(ktanqua){
//		diem++;
//	}
//	return diem;
//}

void InDiem(){
	int *point = &diem;
	gotoXY(97,1);
	cout<<"DIEM SO: "<<*point;
	
}

/*void them(int a[], int n, int vt, int x){
	for (int i = n ; i>vt; i--){
		a[i] = a[i-1];
	}
	a[vt] = x;
	n++;
}*/
void dichuyen(int x, int y){
	for(int i = sl; i>0; i--){
		toa_doX[i] = toa_doX[i-1];
		toa_doY[i] = toa_doY[i-1];
	}
	toa_doX[0] = x;
	toa_doY[0] = y;
}

void ve_tuong(){
	for(int x = 10; x<=95; x++){
		gotoXY(x, 1);
		cout<<"+";
		gotoXY(x, 25);
		cout<<"+";
	}
	for(int y = 1; y<=25; y++){
		gotoXY(10, y);
		cout<<"+";
		gotoXY(95, y);
		cout<<"+";
	}
	int *point = &diem;
	gotoXY(97,1);
	cout<<"DIEM SO: "<<*point;
	
}

//void Chedo(int i){
//	if(i==1){
//		cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t      1. EASY       							"<<endl;
//		cout<<"\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
//		}
//	else if(i==2){
//		cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t      2. NORMAL					            "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
//		}
//	else if(i==3){
//		cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t      3. HARDLY		                        "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
//		}
//	else if(i==4){
//		cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t      4. MASTER				                "<<endl;
//		cout<<"\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
//		}
//	}
//
//void MainMenu(int tt){
//	textcolor(63);
//	cout<<endl<<endl;
//	cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//	cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//	cout<<"\t\t\t\t\t\t\t\t       TRO CHOI RAN SAN MOI			        "<<endl;
//	cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//	cout<<"\t\t\t\t\t\t\t\t                                             "<<endl;
//	
//	textcolor(15);
//	for (int i=1; i<=4; i++){
//			if(i==tt){
//				textcolor(31);
//				Chedo(i);
//				textcolor(15);
//			}
//			else{
//				textcolor(240);
//				Chedo(i);
//				textcolor(15);
//			}
//		}
//	}

int main(){
	srand(time(NULL));
	
//		MainMenu(tt);
//		c=getch();
//			if( c==72 ){
//				if(tt!=1)
//					tt--;
//			}
//			if( c==80 ){
//				if(tt!=4)
//					tt++;
//			}
//			if( c==13 ){
//			switch(tt){
//				case 1:	
//					system("cls");
//					play();
//					InDiem();
//					getch();				
//					break;
//				case 2:
//					system("cls");
//					act.XuatDS();
//					cout<<"\n********************************\n";
//					cout<<"\nNhan phim bat ki de quay lai Menu!";
//					getch();
//					break;
//		}
//	}
	play();
	InDiem();
	_getch();
}




