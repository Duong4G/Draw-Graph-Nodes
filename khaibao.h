#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <mylib.h>
#include <string.h> 
#define MAXINT 2147483647

using namespace std;
const int MAX = 10;
const int KICHTHUOCNUT = 20;
const int MAUNUT = 2;
const int MAUNUTMOI = 4;
const int MAUVIEN = 15;
const int MAUCUNG = 7;
const int MAUCUNGMOI = 14;
const int so_item1 = 9;
const int so_item2 = 9;
const int so_item3 = 6;
const int so_item4 = 8;
const int Up = 72;
const int Down = 80;
const int MAXX = 620;
const int MAXY = 480;
const int SPACE = 32;
int* chuaxet = new int[MAX];
int* duongdi = new int[MAX*MAX];
int MaTranTam[MAX][MAX];
int* Dist;
int* DuongDi;

struct NODE{
	int dinh_ke;
	NODE* next;
};
typedef struct NODE* NODEPTR;
struct phantu_ke{
	int count;
	NODEPTR pF;
	NODEPTR pL;
};
typedef struct phantu_ke DOTHI[MAX];
DOTHI DANHSACHKE;
typedef int DoThi[MAX][MAX];
struct Nut{
	int x;
	int y;
	char ten;
};
struct node{
	int diachi;
	node* next;
};

typedef node* Node_queue;
int tham[MAX];	
struct Queue{
	Node_queue front;
	Node_queue rear;
};
Queue Q;
Nut dsDinh[MAX];
Nut dsDau[MAX*MAX];
Nut dsNgon[MAX*MAX];
int dsTrongSo[MAX*MAX];
int MaTranTrongSo[MAX][MAX];

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(2);
}
int Getx(int x){
	return (x - MAXX/2);
}
int Gety(int y){
	return (MAXY/2 - y);
}
int GetX(int x){
	return (MAXX/2 + x);
}
int GetY(int y){
	return (MAXY/2 - y);
}
char thucdon1 [so_item1][50] = {{"1.Ve nut                 "},
								{"2.Dieu chinh nut         "},
								{"3.Xoa nut                "},
								{"4.Ve cung                "},
								{"5.Lam moi                "},
								{"6.Load file              "},
								{"7.Save file              "},
								{"8.Cac giai thuat         "},
								{"9.Thoat                  "}};
char thucdon2 [so_item2][50] = {{"1.Thuat toan DFS                  "},
								{"2.Thuat toan BFS                  "},
								{"3.Tinh so thanh phan lien thong   "},
								{"4.Tim duong di ngan nhat          "},
								{"5.Tim dinh tru,dinh that, canh cau"},
								{"6.Chu trinh Hamilton              "},
								{"7.Chu trinh Euler                 "},
								{"8.Thuat toan Topo Sort            "},
								{"9.Thoat                           "}};
char thucdon3 [so_item3][50] = {{"1. File 1                "},
								{"2. File 2                "},
								{"3. File 3                "},
								{"4. File 4                "},
								{"5. File 5                "},
								{"6. File 6                "}};
char thucdon4 [so_item1][50] = {{"1.Ve nut                 "},
								{"2.Dieu chinh nut         "},
								{"3.Xoa nut                "},
								{"4.Ve cung                "},
								{"5.Lam moi                "},
								{"6.Load file              "},
								{"7.Save file              "},
								{"8.Thoat                  "}};
int MenuDong(char td [][50],int item,int dong,int cot,int a){
  	Normal();
 	if(a==1) system("cls");
 	int chon =0;
  	int i,x,y; 
  	for ( i=0; i< item ; i++)
  	{ 	gotoxy(cot, dong +i);
    	cout << td[i];
 	}	
  	HighLight();
  	gotoxy(cot,dong+chon);
  	cout << td[chon];
  	char kytu;
	do {
  		kytu = getch();
  		if (kytu==224) kytu = getch();
  		switch (kytu) {
    		case Up :if (chon >0)
  			  	{
  		        	Normal();
              		gotoxy(cot,dong+chon);cout << td[chon];
              		chon --;
              		HighLight();
              		gotoxy(cot,dong+chon); 	cout << td[chon];  				
  			  	}
  			  	else if(chon==0){
  			  		Normal();
  			  		gotoxy(cot,dong+chon);cout<< td[chon];
  			  		chon = item-1;
  			  		HighLight();
  			  		gotoxy(cot,dong+chon);cout<< td[chon]; 
				}
  			  	break;
  			case Down :if (chon+1 <item)
  			 	{
  		        	Normal();
              		gotoxy(cot,dong+chon);	cout << td[chon];
              		chon ++;
              		HighLight();
              		gotoxy(cot,dong+chon); 	cout << td[chon];
  				
  			  	}
  			  	else if (chon+1==item){
  			  		Normal();
              		gotoxy(cot,dong+chon);	cout << td[chon];
              		chon = 0;
              		HighLight();
              		gotoxy(cot,dong+chon); 	cout << td[chon];
				}
  			  	break;
  			case 13 : return chon+1;
  		}  
  	} while (1);
}

void Insert_queue(Queue& Q,int x){
	Node_queue p;
	p = new node;
	p->diachi=x;
	if(Q.front==NULL) Q.front = p;
	else Q.rear->next = p;
	Q.rear = p;
	p->next = NULL;
}
int Delete_queue(Queue& Q){
	Node_queue p;
	int x;
	if(Q.front==NULL){
		cout<<"Hang doi rong!";
		exit(1);
	}else{
		p=Q.front;
		x = p->diachi;
		Q.front = p->next;
		delete p;
		return x;
	}
}

void veNut(Nut t,int mau){
	if(t.x!=MAXINT){
		char c[2]; c[0] = t.ten;
		setcolor(MAUVIEN);           
		circle(t.x,t.y,KICHTHUOCNUT);
		setfillstyle(1,mau);
		floodfill(t.x+10,t.y+10,MAUVIEN);
		setbkcolor(mau);
		c[1]='\0';
		outtextxy(t.x-5,t.y-6,c);
	}
}
void Depth_traverse(DoThi G,int n, int u){
	int* tham = new int[n];
	int Stack[MAX];
	int sp;
	int i,x;
	for(i=0;i<n;tham[i++]=0);
	sp = 0;
	Stack[sp] = u;
	tham[u] = 1;
	while(sp>-1){
		x = Stack[sp];
		sp--;
		veNut(dsDinh[x],MAUNUTMOI);
		for(i=0;i<n;i++){
			if(G[x][i]!=MAXINT&&tham[i]==0){
				Stack[++sp] = i;
				tham[i] = 1;
			}
		}
		delay(1000);
	}
	delete[] tham;
}
void DFS(DoThi G,int n, int u, int sotplt){
	int Stack[MAX];
	int sp;
	int i,x;
	sp = 0;
	Stack[sp] = u;
	chuaxet[u] = sotplt;
	while(sp>-1){
		x = Stack[sp];
		sp--;
		for(i=0;i<n;i++){
			if(G[x][i]!=MAXINT&&chuaxet[i]==0&&dsDinh[i].x!=MAXINT){
				Stack[++sp] = i;
				chuaxet[i] = sotplt;
			}
		}
	}
}
void Width_traverse(DoThi G,int n,int u){
	int *tham= new int[n];
	int i,x;
	for(i=0;i<n;tham[i++]=0);
	Q.front = NULL;
	Insert_queue(Q,u);
	tham[u] = 1;
	while(Q.front!=NULL){
		x = Delete_queue(Q);
		veNut(dsDinh[x],MAUNUTMOI);
		for(i=0;i<MAX;i++){
			if(G[x][i]!=MAXINT&&tham[i]==0){
				Insert_queue(Q,i);
				tham[i] = 1;
			}
		}
		delay(1000);
	}
	delete[] tham;
}
void Hamilton(DoThi G,int n,int b, int& y){
	int j,k;
	int x=1;Normal();
	for(j=0;j<n;j++){
		if(G[duongdi[b-1]][j]!=MAXINT&&chuaxet[j]==0){
			duongdi[b] = j; chuaxet[j] =1;
			if(b<n) Hamilton(G,n,b+1,y);
			else{
				if(duongdi[b]==duongdi[0]){
					y++;
					gotoxy(x,y);
					for(int k=0;k<n+1;k++){
						gotoxy(x,y);
						cout<<dsDinh[duongdi[k]].ten;
						x+=3;
					}
				}
			}
			chuaxet[j] = 0;
		}
	}
}
int SoBacRa(int a, int n){
	int num=0;
	for(int i=0;i<n;i++){
		if(MaTranTrongSo[a][i]!=MAXINT) num++;
	}
	return num;
}
int SoBacVao(int a, int n){
	int num=0;
	for(int i=0;i<n;i++){
		if(MaTranTrongSo[i][a]!=MAXINT) num++;
	}
	return num;
}
void Euler(DoThi G, int n, int a, int y){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			MaTranTam[i][j] = G[i][j];
		}
	}
	int Stack[MAX];
	int j,e,sp = 0,k=0;
	int x = 1;
	Stack[sp] = a;
	while(sp>-1){
		e = Stack[sp];
		for(j=0;j<n;j++){
			if(MaTranTam[e][j]!=MAXINT) 
				break;
		}
		if(j==n){
			sp--;
			duongdi[k++] = e;
		}else{
			Stack[++sp] = j;
			MaTranTam[e][j] = MAXINT;
		}
	}
	if(duongdi[0]==duongdi[k-1]){
		for(int i=k-1;i>=0;i--){
			gotoxy(x,y);
			cout<<dsDinh[duongdi[i]].ten;
			x+=3;
		}
	}
}
int TinhLienThongCua2Dinh(DoThi G, int n, int a, int b, int c){
	for(int j=0;j<n;chuaxet[j++]=0);
	if(c!=-1) chuaxet[c] = 1;
	int Stack[MAX];
	int sp;
	int i,x;
	sp = 0;
	Stack[sp] = a;
	chuaxet[a] = 1;
	while(sp>-1){
		x = Stack[sp];
		sp--;
		for(i=0;i<n;i++){
			if(G[x][i]!=MAXINT&&chuaxet[i]==0&&dsDinh[i].x!=MAXINT){
				Stack[++sp] = i;
				chuaxet[i] = 1;
				if(i==b) return 1;
			}
		}
	}
	return 0;
}
int TinhSoThanhPhanLienThong(DoThi G, int n,int X,int a, int b,int c){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			MaTranTam[i][j] = G[i][j];
		}
	}
	for(int i=0;i<n;chuaxet[i++]=0);
	if(a!=-1&&b!=-1){
		MaTranTam[a][b] = MAXINT;
	}
	if(c!=-1) chuaxet[c] = 1;
	int sotplt=1;
	DFS(MaTranTam,n,X,sotplt);
	for(int i=0;i<n;i++){
		if(chuaxet[i]==0&&dsDinh[i].x!=MAXINT){
			sotplt++;
			DFS(MaTranTam,n,i,sotplt);
		}
	}
	return sotplt;
}
int IsDoThiLienThongManh(DoThi G, int n){
	int solienthong,num,dem=1;
	solienthong = TinhSoThanhPhanLienThong(G,n,0,-1,-1,-1);
	for(int i=1;i<n;i++){
		num = TinhSoThanhPhanLienThong(G,n,i,-1,-1,-1);
		if(num==solienthong) dem++;
	}
	if(dem==n&&solienthong==1) return 1;
	return 0;
}
int GetViTriNut(Nut* ds, int x, int y){
	int a,b,dx,dy;
	float s;
	Nut d;
	for(int i=0;i<MAX;i++){
		d = ds[i];
		a = d.x;
		b = d.y;
		dx = a - x; dy = b - y;
		s = sqrt(dx*dx + dy*dy);
		if(s<=KICHTHUOCNUT) return i;
	}
	return -1;
}
int GetViTriCung(Nut dau, Nut ngon){	
	for(int i=0;i<MAX*MAX;i++){
		if(dsDau[i].x == dau.x && dsDau[i].y == dau.y 
		&& dsNgon[i].x == ngon.x && dsNgon[i].y == ngon.y){
			return i;		
		}
	}
	return -1;
}
void xoaNut(int vitri){
	Nut rong; rong.x = MAXINT;rong.y= MAXINT;rong.ten = SPACE;
	int vitridau,vitringon;
	if(vitri!=-1){
        for(int i=0;i<MAX*MAX;i++){
        	if((dsDau[i].x==dsDinh[vitri].x&&dsDau[i].y==dsDinh[vitri].y&&dsDau[i].x!=MAXINT)||
			(dsNgon[i].x==dsDinh[vitri].x&&dsNgon[i].y==dsDinh[vitri].y&&dsNgon[i].x!=MAXINT)){
                vitridau = GetViTriNut(dsDinh,dsDau[i].x,dsDau[i].y);
                vitringon = GetViTriNut(dsDinh,dsNgon[i].x,dsNgon[i].y);
                MaTranTrongSo[vitridau][vitringon] = MAXINT;
				dsDau[i] = rong;
                dsNgon[i] = rong;
			}
		}
        dsDinh[vitri].x = MAXINT;
        dsDinh[vitri].y = MAXINT;
        dsDinh[vitri].ten = SPACE;
    }
}
void veTamGiac(int x1,int y1,int x2,int y2,int x3,int y3,int mau){
	setcolor(mau);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
	int x = (x1 + x2 + x3)/3;
	int y = (y1 + y2 + y3)/3;
	setfillstyle(1,mau);
	floodfill(x,y,mau);

}

void veCung(Nut dau,Nut ngon,int mau, char* ts){
	int trongso;
	char ts1[5];
	int vitricung=-1;
	int vitricungcanve = GetViTriCung(dau,ngon);
	int vitridau = GetViTriNut(dsDinh,dau.x,dau.y);
	int vitringon = GetViTriNut(dsDinh,ngon.x,ngon.y);
	for(int i=0;i<MAX*MAX;i++){
		if(dsDau[i].x == ngon.x && dsDau[i].y == ngon.y
			&& dsNgon[i].x == dau.x && dsNgon[i].y == dau.y &&dau.x!=ngon.x){
			vitricung = i;		
			break;
		}
	}
	int xm,ym,x1,x2,y1,y2,dx,dy;
	int a,b,c,A,B;
	int xt1,xt2,yt1,yt2,xt,yt;
	int xgiao,ygiao,x,y,xtrung,ytrung;
	float m,t1,t2,t,d,thams;
	if(dau.x == ngon.x && dau.y==ngon.y){
		xm = dau.x + 27;
		ym = dau.y + 36;
		veTamGiac(xm+26,ym,xm+28,ym-10,xm+16,ym-5,mau);
		circle(xm,ym,26);
		
		setcolor(mau);
		setbkcolor(0);
		outtextxy(xm-29,ym,ts);
	}
	else if(vitricungcanve<vitricung&&vitricung!=-1){
		Nut dau1,ngon1;
		xtrung = (dau.x+ngon.x) / 2;
		ytrung = (dau.y+ngon.y) / 2;
		m = abs(dau.y-ngon.y) / (abs(dau.x-ngon.x)-1.0);
		if(m>1){
			dau1.x = dau.x + 5;
			dau1.y = dau.y;
			ngon1.x = ngon.x + 5;
			ngon1.y = ngon.y;
		}else{
			dau1.x = dau.x;
			dau1.y = dau.y + 5;
			ngon1.x = ngon.x;
			ngon1.y = ngon.y + 5;
		}
		
		x1 = dau1.x; x2 = ngon1.x;
    	y1 = dau1.y; y2 = ngon1.y;
    	dx = x2 - x1;
    	dy = y2 - y1;
    	a = dx*(x1-ngon.x)+dy*(y1-ngon.y);
    	b = dx*dx + dy*dy;
    	c = (x1-ngon.x)*(x1-ngon.x) + (y1-ngon.y)*(y1-ngon.y) - KICHTHUOCNUT*KICHTHUOCNUT;
    	A = y2 - y1;
    	B = -(x2-x1);
    	t1 = (-1*a+sqrt(a*a-b*c))/b;
    	t2 = (-1*a-sqrt(a*a-b*c))/b;
    	if(t1>=0&&t1<=1) t = t1;
    	if(t2>=0&&t2<=1) t = t2;
    	xgiao = x1 + (x2-x1)*t;
    	ygiao = y1 + (y2-y1)*t;
    
    	d = sqrt(dx*dx+dy*dy);
    	thams = (d-6)/d;

		xt = dau1.x + (xgiao - dau1.x)*thams;
		yt = dau1.y + (ygiao - dau1.y)*thams;
	
		xt1 = xt + A*(1-thams);
		yt1 = yt + B*(1-thams);
		xt2 = 2*xt - xt1;
		yt2 = 2*yt - yt1;
    	veTamGiac(xgiao,ygiao,xt1,yt1,xt2,yt2,mau);
    	line(dau1.x,dau1.y,ngon1.x,ngon1.y);
		veNut(dau,MAUNUT);
		veNut(ngon,MAUNUT);
		x = dau1.x + (ngon1.x - dau1.x)*0.5;
		y = dau1.y + (ngon1.y - dau1.y)*0.5;
		setcolor(mau);
		setbkcolor(0);
		if(m>1){
			outtextxy(xtrung+16,ytrung,ts);
		}else{
			outtextxy(xtrung,ytrung+16,ts);
		}
	}
	else if(vitricungcanve>vitricung&&vitricung!=-1){
		Nut dau2,ngon2;
		xtrung = (dau.x+ngon.x) / 2;
		ytrung = (dau.y+ngon.y) / 2;
		m = abs(dau.y-ngon.y) / (abs(dau.x-ngon.x)-1.0);
		
		if(m>1){
			dau2.x = dau.x - 5;
			dau2.y = dau.y;
			ngon2.x = ngon.x - 5;
			ngon2.y = ngon.y;
		}else{
			dau2.x = dau.x;
			dau2.y = dau.y - 5;
			ngon2.x = ngon.x;
			ngon2.y = ngon.y - 5;
		}
		x1 = dau2.x; x2 = ngon2.x;
    	y1 = dau2.y; y2 = ngon2.y;
    	dx = x2 - x1;
    	dy = y2 - y1;
    	a = dx*(x1-ngon.x)+dy*(y1-ngon.y);
    	b = dx*dx + dy*dy;
    	c = (x1-ngon.x)*(x1-ngon.x) + (y1-ngon.y)*(y1-ngon.y) - KICHTHUOCNUT*KICHTHUOCNUT;
    	A = y2 - y1;
    	B = -(x2-x1);
    	t1 = (-1*a+sqrt(a*a-b*c))/b;
    	t2 = (-1*a-sqrt(a*a-b*c))/b;
    	if(t1>=0&&t1<=1) t = t1;
    	if(t2>=0&&t2<=1) t = t2;
    	xgiao = x1 + (x2-x1)*t;
    	ygiao = y1 + (y2-y1)*t;
    
    	d = sqrt(dx*dx+dy*dy);
    	thams = (d-6)/d;

		xt = dau2.x + (xgiao - dau2.x)*thams;
		yt = dau2.y + (ygiao - dau2.y)*thams;
	
		xt1 = xt + A*(1-thams);
		yt1 = yt + B*(1-thams);
		xt2 = 2*xt - xt1;
		yt2 = 2*yt - yt1;
    	veTamGiac(xgiao,ygiao,xt1,yt1,xt2,yt2,mau);
    	line(dau2.x,dau2.y,ngon2.x,ngon2.y);
		veNut(dau,MAUNUT);
		veNut(ngon,MAUNUT);
		x = dau2.x + (ngon2.x - dau2.x)*0.5;
		y = dau2.y + (ngon2.y - dau2.y)*0.5;
		setcolor(mau);
		setbkcolor(0);
		if(m>1){
			outtextxy(xtrung-16,ytrung,ts);
		}else{
			outtextxy(xtrung,ytrung-16,ts);
		}
		
	}
	else{
		x1 = dau.x; x2 = ngon.x;
    	y1 = dau.y; y2 = ngon.y;
    	dx = x2 - x1;
    	dy = y2 - y1;
    	a = dx*(x1-x2)+dy*(y1-y2);
    	b = dx*dx + dy*dy;
    	c = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) - KICHTHUOCNUT*KICHTHUOCNUT;
    	A = y2 - y1;
    	B = -(x2-x1);
    	t1 = (-1*a+sqrt(a*a-b*c))/b;
    	t2 = (-1*a-sqrt(a*a-b*c))/b;

    	if(t1>=0&&t1<=1) t = t1;
    	if(t2>=0&&t2<=1) t = t2;
    	xgiao = x1 + (x2-x1)*t;
    	ygiao = y1 + (y2-y1)*t;
    
    	d = sqrt(dx*dx+dy*dy);
    	thams = (d-6)/d;

		xt = dau.x + (xgiao - dau.x)*thams;
		yt = dau.y + (ygiao - dau.y)*thams;
	
		xt1 = xt + A*(1-thams);
		yt1 = yt + B*(1-thams);
		xt2 = 2*xt - xt1;
		yt2 = 2*yt - yt1;
    	veTamGiac(xgiao,ygiao,xt1,yt1,xt2,yt2,mau);
    	line(dau.x,dau.y,ngon.x,ngon.y);
		veNut(dau,MAUNUT);
		veNut(ngon,MAUNUT);
		x = dau.x + (ngon.x - dau.x)*0.5;
		y = dau.y + (ngon.y - dau.y)*0.5;
		setcolor(mau);
		setbkcolor(0);
		outtextxy(x+A*0.03,y+B*0.03,ts);
	}
}
void VeDoThi(){
	setbkcolor(0);
	cleardevice();
	setcolor(15);
	Nut t,dau,ngon;
	int trongso;
	char ts[30];
	for(int i=0;i<MAX;i++){
		t = dsDinh[i];
		if(t.x!=MAXINT){
			veNut(t,MAUNUT);
		}
	}
	for(int i=0;i<MAX*MAX;i++){
		dau = dsDau[i];
		ngon = dsNgon[i];		
		if(dau.x!=MAXINT&&ngon.x!=MAXINT){
			trongso = dsTrongSo[i];
			sprintf(ts,"%d",trongso);
			veCung(dau,ngon,MAUCUNG,ts);
		}
	}
}
void LamMoiMaTran(int A[MAX][MAX], int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j] = MAXINT;
		}
	}
}
void KhoiTaoDS(Nut* ds,int n){
	for(int i=0;i<n;i++){
		ds[i].x = MAXINT;
		ds[i].y = MAXINT;
		ds[i].ten = SPACE;
	}
}

void ShowMaTranTrongSo(int n){
	Normal();
	int x,y=11;
	for(int i=0;i<n;i++){
		x=35;
		for(int j=0;j<n;j++){
			gotoxy(x+=4,y);
			if(MaTranTrongSo[i][j]!=MAXINT){
				cout<<MaTranTrongSo[i][j];
			}else{
				cout<<"-";
			}
		}
		y+=1;
	}
}
void LamMoiHienThiMaTranTrongSo(){
	Normal();
	int x,y=11;
	for(int i=0;i<MAX;i++){
		x=35;
		for(int j=0;j<MAX;j++){
			gotoxy(x+=4,y);
			cout<<"  ";
		}
		y+=1;
	}
}
void LamMoiHienThiKetQua(int y){
	Normal();
	for(int i=11;i<y;i++){
		gotoxy(0,i);
		cout<<"                                     ";
	}
}
void Wellcome(){
	settextstyle(8,0,5);
	setcolor(5);
	setbkcolor(0);
	outtextxy(30,50,"Chuong Trinh Ve Do Thi");
	line(100,120,500,120);
	settextstyle(8,0,5);
	outtextxy(200,150,"Graph-DH");
	settextstyle(8,0,3);
	outtextxy(30,280,"Tac gia: + Truong Hoang Duong");
	outtextxy(155,320,"+ Dao Duy Trong Hau");
	settextstyle(8,0,1);
	outtextxy(100,380,"Nhan phim bat ky de tiep tuc...");
	outtextxy(450,435,"version 1.0.5");
}
void Dijkstra(DoThi G, int X, int Y, int n){
	DoThi Cost;
	int x=1,y=11;
	Dist = new int[n];
	DuongDi = new int[n];
	for(int i=0;i<n;i++) DuongDi[i] = X;
	int S[n];
	int w,i,j,u,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			Cost[i][j] = G[i][j];
		}
	}
	for(i=0;i<n;S[i]=0, Dist[i]=Cost[X][i],i++);
	S[X] = 1;Dist[X]=0;
	
	k=1;
	while(k<n){
		j=0;
		while(j<n&&S[j]!=0) j++;
		u=j;
		for(j=u;j<n;j++){
			if(S[j]==0&&(Dist[j]<Dist[u])) u=j;
		}
		k++;
		for(w=0;w<n;w++){
			if(S[w]==0){
				if(abs(Dist[u]+Cost[u][w])<Dist[w]&&Cost[u][w]!=MAXINT){
					Dist[w] = Dist[u]+Cost[u][w];
					DuongDi[w] = u;
				}
			}
		}
		S[u] = 1;
	}
}
void KhoiTaoDSKE(DoThi G, int n){
	for(int i=0;i<n;DANHSACHKE[i++].pF=NULL);
	NODEPTR p;
	for(int i=0;i<n;i++){
		DANHSACHKE[i].count=0;
		for(int j=0;j<n;j++){
			if(G[j][i]!=MAXINT) DANHSACHKE[i].count++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(G[i][j]!=MAXINT){
				p = new NODE;
				p->next = NULL;
				p->dinh_ke = j;
				if(DANHSACHKE[i].pF==NULL) DANHSACHKE[i].pF = p;
				else DANHSACHKE[i].pL->next = p;
				DANHSACHKE[i].pL=p;
			}
		}
	}
}
void Topo_Sort(DOTHI DANHSACHKE, int n, int &y){
	Q.front = NULL;
	int x=1,u,k;
	Normal();
	NODEPTR p;
	for(int i=0;i<n;i++){
		if(DANHSACHKE[i].count==0){
			Insert_queue(Q,i);
		}
	}
	for(int i=0;i<n;i++){
		if(Q.front==NULL){
			gotoxy(x,y);
			cout<<"Co chu trinh trong do thi";
			y++;
			return;
		}
		u = Delete_queue(Q);
		gotoxy(x,y++);
		cout<<dsDinh[u].ten;
		xoaNut(u); VeDoThi();
		delay(1000);
		p = DANHSACHKE[u].pF;
		while(p!=NULL){
			k = p->dinh_ke;
			DANHSACHKE[k].count--;
			if(DANHSACHKE[k].count==0){
				Insert_queue(Q,k);
			}
			p = p->next;
		}
	}
	
}


