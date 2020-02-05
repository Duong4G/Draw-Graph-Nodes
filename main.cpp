/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/

#include <winbgim.h> 
#include "khaibao.h"

int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(MAXX, MAXY);			// init window graphics
	setbkcolor(0);					// set background
   	cleardevice();
	setcolor(15);					// set text color
//	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	
	int mau,chon1,chon2,chon3,x,y,vitri,check,sonut=0,kiemtra=0;
	char n[255];
	char trongso[5],kytu;
	Nut t;
	Nut rong; rong.x = MAXINT;rong.y= MAXINT;rong.ten = SPACE;
	char c[2];
	KhoiTaoDS(dsDinh,MAX);
	KhoiTaoDS(dsDau,MAX*MAX);
	KhoiTaoDS(dsNgon,MAX*MAX);
	LamMoiMaTran(MaTranTrongSo,MAX);
	for(int j=0;j<MAX*MAX;j++){
		dsTrongSo[j] = MAXINT;
	}
	Wellcome();
	getch();
	cleardevice();
	settextstyle(0,0,1);
	while(true){
		if(kiemtra==0){
			chon1 = MenuDong(thucdon4,so_item4,1,5,1);
		}else{
			chon1 = MenuDong(thucdon1,so_item1,1,5,1);
		}
		if(chon1==9&&kiemtra==1){
			break;
		} 
		for(int j=0;j<MAX;j++){
			if(dsDinh[j].x!=MAXINT) sonut = j + 1;
		}
		LamMoiHienThiMaTranTrongSo();
        ShowMaTranTrongSo(sonut);
		if(chon1==1){
			kiemtra=1;
			gotoxy(1,11); Normal();
			cout<<" Chuot phai de thoat";
			while(true){
				delay(0.01);
		    	if (ismouseclick(WM_LBUTTONDOWN)){
                	getmouseclick(WM_LBUTTONDOWN, t.x, t.y);
                	for(int j=0;j<MAX;j++){
                		if(dsDinh[j].x==MAXINT){
                			t.ten = 65 + j;
                			dsDinh[j] = t;
                			veNut(dsDinh[j],MAUNUT);
                			break;
						}
					}
					for(int j=0;j<MAX;j++){
						if(dsDinh[j].x!=MAXINT) sonut = j + 1;
					}
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);
				}
	                
            	if (ismouseclick(WM_RBUTTONDOWN)){
                	clearmouseclick(WM_RBUTTONDOWN);
                	break;
            	}
			}	
		}
		if(chon1==2){
			clearmouseclick(WM_LBUTTONUP);
			gotoxy(1,11); Normal();
			cout<<" Chuot phai de thoat";
			while(true){
				delay(0.01);
				if(ismouseclick(WM_LBUTTONDOWN)){
					getmouseclick(WM_LBUTTONDOWN, x, y);
					vitri = GetViTriNut(dsDinh,x,y);
				}
				if(ismouseclick(WM_LBUTTONUP)&&vitri!=-1){
					getmouseclick(WM_LBUTTONUP, x, y);
					for(int i=0;i<MAX*MAX;i++){
						if(dsDau[i].x==dsDinh[vitri].x&&dsDau[i].y==dsDinh[vitri].y){
							dsDau[i].x = x;
							dsDau[i].y = y;
						}
						if(dsNgon[i].x==dsDinh[vitri].x&&dsNgon[i].y==dsDinh[vitri].y){
							dsNgon[i].x = x;
							dsNgon[i].y = y;
						}
					}
					dsDinh[vitri].x = x;
					dsDinh[vitri].y = y;										
					VeDoThi();
				}
				if (ismouseclick(WM_RBUTTONDOWN)){
                	clearmouseclick(WM_RBUTTONDOWN);
                	break;
            	}
			}	
		}
		if(chon1==3){
			int vitridau,vitringon;
			gotoxy(1,11); Normal();
			cout<<" Chuot phai de thoat";
			while(true){
				delay(0.01);
		    	if (ismouseclick(WM_LBUTTONDOWN)){
                	getmouseclick(WM_LBUTTONDOWN, x, y);
                	vitri = GetViTriNut(dsDinh,x,y);
                	if(vitri!=-1){
                		xoaNut(vitri);
                		VeDoThi();
                		for(int j=0;j<MAX;j++){
							if(dsDinh[j].x!=MAXINT) sonut = j + 1;
						}
                		LamMoiHienThiMaTranTrongSo();
                		ShowMaTranTrongSo(sonut);
					}
				}
	                
            	if (ismouseclick(WM_RBUTTONDOWN)){
                	clearmouseclick(WM_RBUTTONDOWN);
                	break;
            	}
			}	
		}
		if(chon1==4){
			clearmouseclick(WM_LBUTTONUP);
			Nut dau,ngon;
			int vitridau,vitringon,vitricung;
			int vx = 1,vy=11,num;
			Normal();
			gotoxy(vx,vy);
			cout<<"Keo tha chuot trai de ve cung\n Keo tha chuot phai de xoa cung\n Esc de thoat";
			vy+=3;
			while(true){
				delay(0.01);
		    	if (ismouseclick(WM_LBUTTONDOWN)){
                	getmouseclick(WM_LBUTTONDOWN, x, y);
                	vitridau = GetViTriNut(dsDinh,x,y);
                	if(vitridau!=-1){
                		dau = dsDinh[vitridau];
					}
				}
	            if (ismouseclick(WM_LBUTTONUP)){
                	getmouseclick(WM_LBUTTONUP, x, y);
                	vitringon = GetViTriNut(dsDinh,x,y);
                	if(vitringon!=-1){
                		ngon = dsDinh[vitringon];
                		vitricung = GetViTriCung(dsDinh[vitridau],dsDinh[vitringon]);
                		if(MaTranTrongSo[vitridau][vitringon]!=MAXINT){
								gotoxy(vx,vy++);
								cout<<"Nhap trong so moi vao: ";
								fflush(stdin); gets(trongso);
								num = atoi(trongso);
								dsTrongSo[vitricung] = num;
								MaTranTrongSo[vitridau][vitringon] = dsTrongSo[vitricung];
								VeDoThi();		
						}else{
							for(int j=0;j<MAX*MAX;j++){
                				if(dsDau[j].x==MAXINT){
                					gotoxy(vx,vy++);
                					Normal();
                					cout<<"Nhap trong so vao: ";
									fflush(stdin); gets(trongso);
									num = atoi(trongso);
                					dsDau[j] = dau;
									dsNgon[j] = ngon;
									dsTrongSo[j] = num;
									MaTranTrongSo[vitridau][vitringon] = dsTrongSo[j];
									VeDoThi();
									break;								
								}
							}
						}
                		
						LamMoiHienThiMaTranTrongSo();
						ShowMaTranTrongSo(sonut);			
					}
				} 
				if (ismouseclick(WM_RBUTTONDOWN)){
                	getmouseclick(WM_RBUTTONDOWN, x, y);
                	vitridau = GetViTriNut(dsDinh,x,y);
                	if(vitridau!=-1){
                		dau = dsDinh[vitridau];
					}
				}
	            if (ismouseclick(WM_RBUTTONUP)){
                	getmouseclick(WM_RBUTTONUP, x, y);
                	vitringon = GetViTriNut(dsDinh,x,y);
                	if(vitringon!=-1){
                		ngon = dsDinh[vitringon];
                		for(int j=0;j<MAX*MAX;j++){
                			if(dsDau[j].x==dau.x&&dsDau[j].y==dau.y){
                				if(dsNgon[j].x==ngon.x&&dsNgon[j].y==ngon.y){
									dsDau[j] = rong;
									dsNgon[j] = rong;
									dsTrongSo[j] = MAXINT;
									MaTranTrongSo[vitridau][vitringon] = dsTrongSo[j];
									VeDoThi();
									break;
								}
							} 		
						}
                		LamMoiHienThiMaTranTrongSo();
						ShowMaTranTrongSo(sonut);	
					}
				} 
				if(kbhit()){
					kytu = getch();
					if(kytu==27) break;
				}  
			}	
		}
		if(chon1==5){
			kiemtra=0;
			cleardevice();
			KhoiTaoDS(dsDinh,MAX);
			KhoiTaoDS(dsDau,MAX*MAX);
			KhoiTaoDS(dsNgon,MAX*MAX);
			for(int j=0;j<MAX*MAX;j++){
				dsTrongSo[j] = MAXINT;
			}
			for(int i=0;i<MAX;i++){
				for(int j=0;j<MAX;j++){
					MaTranTrongSo[i][j] = MAXINT;
				}
			}
			sonut = 0;
			VeDoThi();
		}
		if(chon1==6){
			kiemtra=1;
			KhoiTaoDS(dsDinh,MAX);
			KhoiTaoDS(dsDau,MAX*MAX);
			KhoiTaoDS(dsNgon,MAX*MAX);
			for(int j=0;j<MAX*MAX;j++){
				dsTrongSo[j] = MAXINT;
			}
			LamMoiMaTran(MaTranTrongSo,MAX);
			int num,toadox,toadoy,trongso;
			char name;
			FILE* fptr;
			chon3 = MenuDong(thucdon3,so_item3,11,5,-1);
			if(chon3==1){
				if((fptr=fopen("demo1.txt","r"))==NULL){
					gotoxy(5,17); Normal();
					printf("File nay khong the mo\n");				
				}else{
					fscanf(fptr,"%s",n);
					num = atoi(n);
					for(int i=0;i<num;i++){
						fscanf(fptr,"%s",n);
						name = n[0];
						fscanf(fptr,"%s",n);
						toadox = atoi(n);
						fscanf(fptr,"%s",n);
						toadoy = atoi(n);
						t.x = toadox;
						t.y = toadoy;
						if(name==33) t.ten = SPACE;
						else
							t.ten = name;
						dsDinh[i] = t;
					}
					int k = 0;
					for(int i=0;i<num;i++){
						for(int j=0;j<num;j++){
							fscanf(fptr,"%s",n);
							trongso = atoi(n);
							MaTranTrongSo[i][j] = trongso;
							if(trongso!=MAXINT){
								dsDau[k] = dsDinh[i];
								dsNgon[k] = dsDinh[j];
								dsTrongSo[k] = trongso;
								k++;
							}
						}
					}
					sonut = num;
					VeDoThi();
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);				
				}
			}
			if(chon3==2){
				if((fptr=fopen("demo2.txt","r"))==NULL){
					gotoxy(5,17); Normal();
					printf("File nay khong the mo\n");				
				}else{
					fscanf(fptr,"%s",n);
					num = atoi(n);
					for(int i=0;i<num;i++){
						fscanf(fptr,"%s",n);
						name = n[0];
						fscanf(fptr,"%s",n);
						toadox = atoi(n);
						fscanf(fptr,"%s",n);
						toadoy = atoi(n);
						t.x = toadox;
						t.y = toadoy;
						if(name==33) t.ten = 32;
						else
							t.ten = name;
						dsDinh[i] = t;
					}
					int k = 0;
					for(int i=0;i<num;i++){
						for(int j=0;j<num;j++){
							fscanf(fptr,"%s",n);
							trongso = atoi(n);
							MaTranTrongSo[i][j] = trongso;
							if(trongso!=MAXINT){
								dsDau[k] = dsDinh[i];
								dsNgon[k] = dsDinh[j];
								dsTrongSo[k] = trongso;
								k++;
							}
						}
					}
					sonut = num;
					VeDoThi();
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);				
				}
			}
			if(chon3==3){
				if((fptr=fopen("demo3.txt","r"))==NULL){
					gotoxy(5,17); Normal();
					printf("File nay khong the mo\n");				
				}else{
					fscanf(fptr,"%s",n);
					num = atoi(n);
					for(int i=0;i<num;i++){
						fscanf(fptr,"%s",n);
						name = n[0];
						fscanf(fptr,"%s",n);
						toadox = atoi(n);
						fscanf(fptr,"%s",n);
						toadoy = atoi(n);
						t.x = toadox;
						t.y = toadoy;
						if(name==33) t.ten = 32;
						else
							t.ten = name;
						dsDinh[i] = t;
					}
					int k = 0;
					for(int i=0;i<num;i++){
						for(int j=0;j<num;j++){
							fscanf(fptr,"%s",n);
							trongso = atoi(n);
							MaTranTrongSo[i][j] = trongso;
							if(trongso!=MAXINT){
								dsDau[k] = dsDinh[i];
								dsNgon[k] = dsDinh[j];
								dsTrongSo[k] = trongso;
								k++;
							}
						}
					}
					sonut = num;
					VeDoThi();
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);				
				}
			}
			if(chon3==4){
				if((fptr=fopen("demo4.txt","r"))==NULL){
					gotoxy(5,17); Normal();
					printf("File nay khong the mo\n");				
				}else{
					fscanf(fptr,"%s",n);
					num = atoi(n);
					for(int i=0;i<num;i++){
						fscanf(fptr,"%s",n);
						name = n[0];
						fscanf(fptr,"%s",n);
						toadox = atoi(n);
						fscanf(fptr,"%s",n);
						toadoy = atoi(n);
						t.x = toadox;
						t.y = toadoy;
						if(name==33) t.ten = 32;
						else
							t.ten = name;
						dsDinh[i] = t;
					}
					int k = 0;
					for(int i=0;i<num;i++){
						for(int j=0;j<num;j++){
							fscanf(fptr,"%s",n);
							trongso = atoi(n);
							MaTranTrongSo[i][j] = trongso;
							if(trongso!=MAXINT){
								dsDau[k] = dsDinh[i];
								dsNgon[k] = dsDinh[j];
								dsTrongSo[k] = trongso;
								k++;
							}
						}
					}
					sonut = num;
					VeDoThi();
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);				
				}
			}
			if(chon3==5){
				if((fptr=fopen("demo5.txt","r"))==NULL){
					gotoxy(5,17); Normal();
					printf("File nay khong the mo\n");				
				}else{
					fscanf(fptr,"%s",n);
					num = atoi(n);
					for(int i=0;i<num;i++){
						fscanf(fptr,"%s",n);
						name = n[0];
						fscanf(fptr,"%s",n);
						toadox = atoi(n);
						fscanf(fptr,"%s",n);
						toadoy = atoi(n);
						t.x = toadox;
						t.y = toadoy;
						if(name==33) t.ten = 32;
						else
							t.ten = name;
						dsDinh[i] = t;
					}
					int k = 0;
					for(int i=0;i<num;i++){
						for(int j=0;j<num;j++){
							fscanf(fptr,"%s",n);
							trongso = atoi(n);
							MaTranTrongSo[i][j] = trongso;
							if(trongso!=MAXINT){
								dsDau[k] = dsDinh[i];
								dsNgon[k] = dsDinh[j];
								dsTrongSo[k] = trongso;
								k++;
							}
						}
					}
					sonut = num;
					VeDoThi();
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);				
				}
			}
			if(chon3==6){
				if((fptr=fopen("demo6.txt","r"))==NULL){
					gotoxy(5,17); Normal();
					printf("File nay khong the mo\n");				
				}else{
					fscanf(fptr,"%s",n);
					num = atoi(n);
					for(int i=0;i<num;i++){
						fscanf(fptr,"%s",n);
						name = n[0];
						fscanf(fptr,"%s",n);
						toadox = atoi(n);
						fscanf(fptr,"%s",n);
						toadoy = atoi(n);
						t.x = toadox;
						t.y = toadoy;
						if(name==33) t.ten = 32;
						else
							t.ten = name;
						dsDinh[i] = t;
					}
					int k = 0;
					for(int i=0;i<num;i++){
						for(int j=0;j<num;j++){
							fscanf(fptr,"%s",n);
							trongso = atoi(n);
							MaTranTrongSo[i][j] = trongso;
							if(trongso!=MAXINT){
								dsDau[k] = dsDinh[i];
								dsNgon[k] = dsDinh[j];
								dsTrongSo[k] = trongso;
								k++;
							}
						}
					}
					sonut = num;
					VeDoThi();
					LamMoiHienThiMaTranTrongSo();
					ShowMaTranTrongSo(sonut);				
				}
			}
			fclose(fptr);
			getch();
		}
		if(chon1==7){
			FILE* fptr;
			int num,toadox,toadoy,trongso;
			char ghi[50];
			char kytu = 'Y';
			chon3 = MenuDong(thucdon3,so_item3,11,5,-1);
			if(chon3==1){
				gotoxy(5,17); Normal();
				if((fptr=fopen("demo1.txt","r"))!=NULL){
					cout<<"Ban muon ghi de?(Y/N)";
					kytu = toupper(getch());
				}
				fclose(fptr); 
				if(kytu=='Y'){
					fptr=fopen("demo1.txt","w");
					fprintf(fptr,"%d",sonut);
					fprintf(fptr,"\n");
					for(int i=0;i<sonut;i++){
						if(dsDinh[i].ten==SPACE){
							fprintf(fptr,"%c ",33);
						}else{
							fprintf(fptr,"%c ",dsDinh[i].ten);
						}				
						fprintf(fptr,"%d ",dsDinh[i].x);
						fprintf(fptr,"%d ",dsDinh[i].y);
						fprintf(fptr,"\n");
					}
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;j++){
							fprintf(fptr,"%d ",MaTranTrongSo[i][j]);
						}
						fprintf(fptr,"\n");
					}
				}
			}
			if(chon3==2){
				gotoxy(5,17); Normal();
				if((fptr=fopen("demo2.txt","r"))!=NULL){
					cout<<"Ban muon ghi de?(Y/N)";
					kytu = toupper(getch());
				}
				fclose(fptr); 
				if(kytu=='Y'){
					fptr=fopen("demo2.txt","w");
					fprintf(fptr,"%d",sonut);
					fprintf(fptr,"\n");
					for(int i=0;i<sonut;i++){
						if(dsDinh[i].ten==SPACE){
							fprintf(fptr,"%c ",33);
						}else{
							fprintf(fptr,"%c ",dsDinh[i].ten);
						}				
						fprintf(fptr,"%d ",dsDinh[i].x);
						fprintf(fptr,"%d ",dsDinh[i].y);
						fprintf(fptr,"\n");
					}
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;j++){
							fprintf(fptr,"%d ",MaTranTrongSo[i][j]);
						}
						fprintf(fptr,"\n");
					}
				}
			}
			if(chon3==3){
				gotoxy(5,17); Normal();
				if((fptr=fopen("demo3.txt","r"))!=NULL){
					cout<<"Ban muon ghi de?(Y/N)";
					kytu = toupper(getch());
				}
				fclose(fptr); 
				if(kytu=='Y'){
					fptr=fopen("demo3.txt","w");
					fprintf(fptr,"%d",sonut);
					fprintf(fptr,"\n");
					for(int i=0;i<sonut;i++){
						if(dsDinh[i].ten==SPACE){
							fprintf(fptr,"%c ",33);
						}else{
							fprintf(fptr,"%c ",dsDinh[i].ten);
						}				
						fprintf(fptr,"%d ",dsDinh[i].x);
						fprintf(fptr,"%d ",dsDinh[i].y);
						fprintf(fptr,"\n");
					}
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;j++){
							fprintf(fptr,"%d ",MaTranTrongSo[i][j]);
						}
						fprintf(fptr,"\n");
					}
				}
			}
			if(chon3==4){
				gotoxy(5,17); Normal();
				if((fptr=fopen("demo4.txt","r"))!=NULL){
					cout<<"Ban muon ghi de?(Y/N)";
					kytu = toupper(getch());
				}
				fclose(fptr); 
				if(kytu=='Y'){
					fptr=fopen("demo4.txt","w");
					fprintf(fptr,"%d",sonut);
					fprintf(fptr,"\n");
					for(int i=0;i<sonut;i++){
						if(dsDinh[i].ten==SPACE){
							fprintf(fptr,"%c ",33);
						}else{
							fprintf(fptr,"%c ",dsDinh[i].ten);
						}				
						fprintf(fptr,"%d ",dsDinh[i].x);
						fprintf(fptr,"%d ",dsDinh[i].y);
						fprintf(fptr,"\n");
					}
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;j++){
							fprintf(fptr,"%d ",MaTranTrongSo[i][j]);
						}
						fprintf(fptr,"\n");
					}
				}
			}
			if(chon3==5){
				gotoxy(5,17); Normal();
				if((fptr=fopen("demo5.txt","r"))!=NULL){
					cout<<"Ban muon ghi de?(Y/N)";
					kytu = toupper(getch());
				}
				fclose(fptr); 
				if(kytu=='Y'){
					fptr=fopen("demo5.txt","w");
					fprintf(fptr,"%d",sonut);
					fprintf(fptr,"\n");
					for(int i=0;i<sonut;i++){
						if(dsDinh[i].ten==SPACE){
							fprintf(fptr,"%c ",33);
						}else{
							fprintf(fptr,"%c ",dsDinh[i].ten);
						}				
						fprintf(fptr,"%d ",dsDinh[i].x);
						fprintf(fptr,"%d ",dsDinh[i].y);
						fprintf(fptr,"\n");
					}
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;j++){
							fprintf(fptr,"%d ",MaTranTrongSo[i][j]);
						}
						fprintf(fptr,"\n");
					}
				}
			}
			if(chon3==6){
				gotoxy(5,17); Normal();
				if((fptr=fopen("demo6.txt","r"))!=NULL){
					cout<<"Ban muon ghi de?(Y/N)";
					kytu = toupper(getch());
				}
				fclose(fptr); 
				if(kytu=='Y'){
					fptr=fopen("demo6.txt","w");
					fprintf(fptr,"%d",sonut);
					fprintf(fptr,"\n");
					for(int i=0;i<sonut;i++){
						if(dsDinh[i].ten==SPACE){
							fprintf(fptr,"%c ",33);
						}else{
							fprintf(fptr,"%c ",dsDinh[i].ten);
						}				
						fprintf(fptr,"%d ",dsDinh[i].x);
						fprintf(fptr,"%d ",dsDinh[i].y);
						fprintf(fptr,"\n");
					}
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;j++){
							fprintf(fptr,"%d ",MaTranTrongSo[i][j]);
						}
						fprintf(fptr,"\n");
					}
				}
			}
		}
		if(chon1==8&&kiemtra==0) break;
		if(chon1==8&&kiemtra==1){
			while(true){
				int vx = 1,vy=11,so,lienthong=1;
				for(int j=0;j<MAX;j++){
					if(dsDinh[j].x!=MAXINT) sonut = j + 1;
				}
				LamMoiHienThiMaTranTrongSo();
        		ShowMaTranTrongSo(sonut);
				chon2 = MenuDong(thucdon2,so_item2,1,39,0);
				if(chon2==1){
					while(true){
						delay(0.01);
		    			if (ismouseclick(WM_LBUTTONDOWN)){
                			getmouseclick(WM_LBUTTONDOWN, x, y);
                			vitri = GetViTriNut(dsDinh,x,y);
                			if(vitri!=-1){
                				Depth_traverse(MaTranTrongSo,sonut,vitri);
							}
							gotoxy(vx,vy); Normal();
							cout<<"\n An phim bat ky de thoat";
							getch();
							break;
						}
					}	
				}
				if(chon2==2){
					while(true){
						delay(0.01);
		    			if (ismouseclick(WM_LBUTTONDOWN)){
                			getmouseclick(WM_LBUTTONDOWN, x, y);
                			vitri = GetViTriNut(dsDinh,x,y);
                			if(vitri!=-1){
                				Width_traverse(MaTranTrongSo,sonut,vitri);
							}
							gotoxy(vx,vy); Normal();
							cout<<"\n An phim bat ky de thoat";
							getch();
							break;
						}
					}		
				}
				if(chon2==3){
					int nhonhat=MAXINT,vitrinhonhat;
					for(int i=0;i<sonut;i++){
						so = TinhSoThanhPhanLienThong(MaTranTrongSo,sonut,i,-1,-1,-1);
						if(nhonhat>so){
							nhonhat = so;
							vitrinhonhat = i;
						}
					}
					so = TinhSoThanhPhanLienThong(MaTranTrongSo,sonut,vitrinhonhat,-1,-1,-1);
					gotoxy(vx,vy++);
					Normal();
					cout<<"So thanh phan lien thong: "<<so;
					if(so>0){
						for(int i=1;i<=so;i++){
							vx = 1;
							gotoxy(vx,vy);
							cout<<"Lien thong "<<i<<": ";
							vy++;
							for(int j=0;j<sonut;j++){
								if(chuaxet[j]==i){
									gotoxy(vx,vy);
									cout<<dsDinh[j].ten;
									vx+=3;
								}
							}
							vy++; vx=1;
						}
					}
					gotoxy(vx,vy); Normal();
					cout<<"\n An phim bat ky de thoat";
					getch();	
				}
				if(chon2==4){
					int k=0,vitriX,vitriY,dem=0,i,vitridau,vitringon;
					vy = 9;
					int* mang = new int[sonut];
					while(true){
						delay(0.01);
		    			if (ismouseclick(WM_LBUTTONDOWN)&&k==0){
                			getmouseclick(WM_LBUTTONDOWN, x, y);
                			vitri= GetViTriNut(dsDinh,x,y);
                			if(vitri!=-1){
                				vitriX = vitri;
                				k=1;
							}
						}
	                	if (ismouseclick(WM_LBUTTONDOWN)&&k==1){
                			getmouseclick(WM_LBUTTONDOWN, x, y);
                			vitri = GetViTriNut(dsDinh,x,y);
                			if(vitri!=-1){
                				vitriY = vitri;
                				Dijkstra(MaTranTrongSo,vitriX,vitriY,sonut);
                				gotoxy(vx,vy++);
                				if(Dist[vitriY]>=MAXINT||Dist[vitriY]<0){
									Normal(); 
									gotoxy(vx,vy++);
									cout<<"\nKhong co duong di";
								}else{
									char* trongs = new char[30];
									Normal();
									gotoxy(vx,vy++);
									printf("\n Duong di ngan nhat tu %c->%c la: ", dsDinh[vitriX].ten, dsDinh[vitriY].ten);
									i = vitriY;
									mang[dem++] = i;
									gotoxy(vx,vy++);
									while(i != vitriX){ 
										i = DuongDi[i]; 
										mang[dem++] = i;
									}
									for(int j=dem-1;j>=0;j--){
										if(j>0){
											vitridau = mang[j];
											vitringon = mang[j-1];
											sprintf(trongs,"%d",MaTranTrongSo[vitridau][vitringon]);
											veCung(dsDinh[vitridau],dsDinh[vitringon],MAUCUNGMOI,trongs);
											veNut(dsDinh[mang[j]],MAUNUTMOI);
											gotoxy(vx,vy++);
											cout<<dsDinh[mang[j]].ten;
										}else{
											veNut(dsDinh[mang[j]],MAUNUTMOI);
											gotoxy(vx,vy++);
											cout<<dsDinh[mang[j]].ten;
										}
										delay(1000);
									}
									delete[] trongs;
								}
								gotoxy(vx,vy); Normal();
								cout<<"\n An phim bat ky de thoat";
								getch();
								break;
							}
							
						}
					}
					delete[] mang;		
				}
				if(chon2==5){
					int num; Normal();
					int nhonhat=MAXINT,vitrinhonhat;
					int temp[sonut],dem=0;
					for(int i=0;i<sonut;i++){
						so = TinhSoThanhPhanLienThong(MaTranTrongSo,sonut,i,-1,-1,-1);
						if(nhonhat>so){
							nhonhat = so;
							vitrinhonhat = i;
						}
					}
					so = TinhSoThanhPhanLienThong(MaTranTrongSo,sonut,vitrinhonhat,-1,-1,-1);
					if(so>0){
						gotoxy(vx,vy++);
						cout<<"Cac dinh tru la: ";
						for(int i=0;i<sonut;i++){
							nhonhat=MAXINT;
							for(int j=0;j<sonut;j++){
								if(i!=j){
									num = TinhSoThanhPhanLienThong(MaTranTrongSo,sonut,j,-1,-1,i);
									nhonhat = (nhonhat<num)?nhonhat:num;
								}
							}
							if(nhonhat>so&&nhonhat!=MAXINT){
								gotoxy(vx,vy);
								cout<<dsDinh[i].ten;
								vx+=3;
							}
							
						}
						vx = 1;vy++;
						gotoxy(vx,vy);
						cout<<"Cac dinh that la:";
						for(int i=0;i<sonut;i++){
							for(int j=0;j<sonut;j++){
								if(i!=j){
									num = TinhLienThongCua2Dinh(MaTranTrongSo,sonut,i,j,-1);
									if(num==1){
										for(int k=0;k<sonut;k++){
											if(k!=i&&k!=j){
												num = TinhLienThongCua2Dinh(MaTranTrongSo,sonut,i,j,k);
												if(num==0){
													temp[dem++] = k;
												}
											}
										}
									}
								}
							}
						}
						for(int i=1;i<dem;i++){
							for(int j=0;j<i;j++){
								if(temp[i]==temp[j]){
									for(int k=i;k<dem;k++){
										temp[k] = temp[k+1];
									}
									i--;
									dem--;
								}
							}
						}
						vy++;
						for(int i=0;i<dem;i++){
							gotoxy(vx,vy);
							cout<<dsDinh[temp[i]].ten;
							vx+=3;
						}
						vx = 1;vy++;
						gotoxy(vx,vy);
						cout<<"Cac canh cau la: ";
						for(int i=0;i<sonut;i++){
							for(int j=0;j<sonut;j++){
								if(MaTranTrongSo[i][j]!=MAXINT){
									nhonhat=MAXINT;
									for(int k=0;k<sonut;k++){
										num = TinhSoThanhPhanLienThong(MaTranTrongSo,sonut,k,i,j,-1);
										nhonhat = (nhonhat<num)?nhonhat:num;
									}
									if(nhonhat>so){
										vy++;
										gotoxy(vx,vy);
										cout<<dsDinh[i].ten<<"->"<<dsDinh[j].ten;		
									}
								}
							}
						}
					}
					gotoxy(vx,++vy); Normal();
					cout<<"\n An phim bat ky de thoat";
					getch();
				}
				if(chon2==6){
					gotoxy(vx,vy++); Normal();
					cout<<"Cac chu trinh hamilton:";
					vy--;
					for(int i=0;i<sonut;i++){
						for(int j=0;j<sonut;chuaxet[j++]=0);
						duongdi[0] = i;
						Hamilton(MaTranTrongSo,sonut,1,vy);
						vy++;
					}
					gotoxy(vx,vy); Normal();
					cout<<"\n An phim bat ky de thoat";
					getch();
				}
				if(chon2==7){
					int m;
					gotoxy(vx,vy++); Normal();
					for(m=0;m<sonut;m++){
						if(SoBacRa(m,sonut)!=SoBacVao(m,sonut)) break;
					}
					if(IsDoThiLienThongManh(MaTranTrongSo,sonut)==1&&m==sonut&&SoBacRa(0,sonut)!=0){
						cout<<"Cac chu trinh Euler:";
						for(int i=0;i<sonut;i++){
							for(int j=0;j<sonut;chuaxet[j++]=0);
							duongdi[0] = i;
							Euler(MaTranTrongSo,sonut,i,vy);
							vy+=2;
						}
					}else cout<<"Khong co chu trinh Euler";
					gotoxy(vx,vy); Normal();
					cout<<"\n An phim bat ky de thoat";
					getch();
				}
				if(chon2==8){
					KhoiTaoDSKE(MaTranTrongSo,sonut);
					Topo_Sort(DANHSACHKE,sonut,vy);
					gotoxy(vx,vy); Normal();
					cout<<"\n An phim bat ky de thoat";
					getch();
					
				}
				if(chon2==9){
					break;
				}
				VeDoThi();
				LamMoiHienThiKetQua(vy+2);
			}
		}
	}
	Normal();
	gotoxy(10,10);
	delete[] chuaxet,duongdi,Dist,DuongDi;
	return 0;
}
