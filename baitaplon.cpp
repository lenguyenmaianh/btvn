#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

struct hanghoa 
{
	char mahang[10];
	char tenhang[30];
	char donvitinh[10];
	long dongia,thanhtien;
	int soluong;
};
void nhap(hanghoa hh[], int &n)
{ cout<<"Nhap vao so luong hang hoa:";
  cin>>n; 
	for(int i=0 ; i < n ; i++)
	{ 
	  cin.ignore();
		cout <<"\t\tHANG HOA THU "<<i+1<<endl;
		cout <<"---Nhap ma hang hoa :";
		cin.getline(hh[i].mahang,10);
		cout <<"---Nhap ten hang hoa:";
		cin.getline(hh[i].tenhang,30);
		cout <<"---Nhap don vi tinh hang hoa:";
		cin.getline(hh[i].donvitinh,10);
		cout << "Nhap vao don gia cua hang hoa:";
		do
		{
			cin>>hh[i].dongia;
			if(hh[i].dongia<0)
       {
       	cout <<"\nNHAP LAI THONG TIN DI BAN OI!!!";
       }
		}while(hh[i].dongia<0);
		cout << "Nhap so luong cua hang hoa :";
		do
		{
			cin>>hh[i].soluong;
			if(hh[i].soluong<0)
       {
       	cout <<"\nNHAP LAI THONG TIN DI BAN OI!!!";
       }
		}while(hh[i].soluong<0);
	}
}
void nhap1hanghoa(hanghoa &hh)
{
	  cin.ignore();
		cout <<"Nhap ma hang hoa :";
		cin.getline(hh.mahang,10);
		cout <<"Nhap ten hang hoa:";
		cin.getline(hh.tenhang,30);
		cout <<"Nhap don vi tinh hang hoa:";
		cin.getline(hh.donvitinh,10);
		cout << "\nNhap vao don gia cua hang hoa:";
		do
		{
			cin>>hh.dongia;
			if(hh.dongia<0)
       {
       	cout <<"\nNHAP LAI THONG TIN DI BAN OI!!!";
       }
		}while(hh.dongia<0);
		cout << "\nNhap lai so luong cua hang hoa:";
		do
		{
			cin>>hh.soluong;
			if(hh.soluong<0)
       {
       	cout <<"\nNHAP LAI THONG TIN DI BAN OI!!!";
       }
		}while(hh.soluong<0);
	
}
void thanhtien(hanghoa hh[], int n)
{
	for (int i=0 ; i < n ; i++)
	{
		hh[i].thanhtien=hh[i].dongia*hh[i].soluong;
		cout<<"\tThanh tien cua hang hoa la:"<<hh[i].thanhtien<<endl;
	}
}
void tieude()
{
	    cout << "+======================================================================================================+"<< endl;
 	    cout << "!" << setw(6)  << "MA "         << setw(3)
             << "!" << setw(11) << "TEN "        << setw(7)
             << "!" << setw(15) << "DON VI TINH" << setw(5) 
             << "!" << setw(11) << "DON GIA"     << setw(5) 
			 << "!" << setw(15) << "SO LUONG "   << setw(5)
			 << "!" << setw(15) << "THANH TIEN"  << setw(6)  << "!" << endl;	
      cout << "+=======================================================================================================+"<< endl;			 

}

void xuat1hanghoa(hanghoa hh)
{
	
 	    cout << "!" << setw(6)  << hh.mahang    << setw(3)
             << "!" << setw(11) << hh.tenhang   << setw(7)
             << "!" << setw(15) << hh.donvitinh << setw(5) 
             << "!" << setw(11) << hh.dongia    << setw(5) 
			 << "!" << setw(15) << hh.soluong   << setw(5)
			 << "!" << setw(15) << hh.thanhtien << setw(6)  << "!" << endl;	
      cout << "+=======================================================================================================+"<< endl;			 

}
void xuatnhieuhanghoa(hanghoa hh[], int n)
{
	for (int i =0 ; i<n ; i++)
	{
		  cout << "!" << setw(6) << hh[i].mahang     << setw(3)
               << "!" << setw(11) << hh[i].tenhang   << setw(7)
               << "!" << setw(15) << hh[i].donvitinh << setw(5) 
               << "!" << setw(11) << hh[i].dongia    << setw(5) 
		       << "!" << setw(15) << hh[i].soluong   << setw(5)
		       << "!" << setw(15) << hh[i].thanhtien << setw(6)  << "!" << endl;	
      cout << "+=======================================================================================================+"<< endl;			 
	}
}

void sapxep(hanghoa hh[], int n)
{
	for(int i =0 ; i<n -1 ; i++)
	{
		for(int j = i+1; j <n;j++)
		{
			if (hh[i].soluong>hh[j].soluong)
        {
       	         hanghoa tg=hh[i];
								 hh[i]=hh[j];
								 hh[i]=tg;	
       	}
		}
	}
}

void chenhanghoa(hanghoa hh[], int &n, hanghoa x)
{
   	x.thanhtien=x.dongia*x.soluong;
   	int vtri=0;
   	for(int i= n- 1; i>= vtri; i--)
   	   {
   	   	        hh[i+1]=hh[i];
   	   }
   	   hh[vtri]= x;
   	   n++;
     sapxep(hh,n);
}

void xoatheodonvitinh(hanghoa hh[], int &n , char donvicanxoa[10])
{ 
	for(int i=0 ; i<n;i++)
	{
		    if(strcmp(hh[i].donvitinh,donvicanxoa)==0)
		    {
    		   for(int j=i; j<n; j++){
			   hh[j]=hh[j+1];
			   }
			   cout<<"da xoa thanh cong hang hoa co dvt :\n"<<donvicanxoa;	
    		}	
	}
}
void hanghoacothanhtiencaonhat(hanghoa hh[], int n)
{   
    int max=0;
	for(int i=0;i<n;i++)
	{
		if(hh[i].thanhtien>max)
		{
			max=hh[i].thanhtien;
		}
	}
	for (int i=0;i<n;i++)
	{
		if(hh[i].thanhtien==max)
		{
			xuat1hanghoa(hh[i]);
		}
	}
}
void ghitep(hanghoa hh[], int &n)
{
	ofstream f;
	f.open("D:\\product.dat", ios::out);
	if (!f)
	{
		cout << "\nMo tep khong thanh cong!!";
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		f << hh[i].mahang << "\t" << hh[i].tenhang << "\t" << hh[i].donvitinh << "\t" <<hh[i].dongia << "\t" << hh[i].soluong<< hh[i].thanhtien<<endl;
	}
	f.close();
	cout<<"ghi tep thanh cong"<<endl;
}
void doctep(hanghoa hh[], int &n)
{
	fstream f;
	f.open("D:\\product.dat", ios::in);
	if (!f)
	{
		cout << "\nFILE khong ton tai !!";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		f >> hh[i].mahang;
		f >> hh[i].tenhang;
		f >> hh[i].donvitinh;
		f >> hh[i].soluong;
		f >> hh[i].thanhtien;
	}
	f.close();
	cout << "Xuat tep\n";
	tieude();
	for (int i = 0; i < n; i++)
	{
		  cout << "!" << setw(6) << hh[i].mahang<< setw(3)
           << "!" << setw(11) << hh[i].tenhang << setw(7)
           << "!" << setw(15) << hh[i].donvitinh << setw(5) 
           << "!" << setw(11) << hh[i].dongia << setw(5) 
					 << "!" << setw(15) << hh[i].soluong << setw(5)
					 << "!" << setw(15) << hh[i].thanhtien << setw(6)  << "!" << endl;	
      cout << "+=========================================================================================================+"<< endl;			 
	}
}

void menu(hanghoa hh[], int &n , hanghoa x)
{
	quaylai:
    cout << "\t\t\t====================================Menu================================\n";
	cout << "\t\t\t||  1. Nhap Danh Sach Hang hoa Tu Ban Phim                            ||\n";                      
	cout << "\t\t\t||  2. Tinh  Thanh tien cua hang hoa                                  ||\n";
	cout << "\t\t\t||  3. In Ra Danh Sach hang hoa                                       ||\n";
	cout << "\t\t\t||  4. In Ra danh sach hang hoa Theo Thu Tu Tang Dan                  ||\n";
	cout << "\t\t\t||  5. In Ra Thong Tin hang hoa co thanh tien Cao Nhat                ||\n";
	cout << "\t\t\t||  6. Chen Them Mot hang hoa Khong Lam Thay Doi Sap Xep              ||\n";
	cout << "\t\t\t||  7. Xoa hang hoa Dua Tren don vi tinh                              ||\n";
	cout << "\t\t\t||  8. Luu Danh Sach hang hoa Ra Tep                                  ||\n";
	cout << "\t\t\t||  9. Doc Danh Sach hang hoa Tu Tep Va In Ra Man Hinh                ||\n";
	cout << "\t\t\t||  0. ket thuc                                                       ||\n";
	cout << "\t\t\t========================================================================";
	int luachon;
        nhaplai:
     cout<< "\nMoi nhap lua chon:";
      cin>>luachon;
         switch(luachon)
           {
            case 1: 
         	 nhap(hh,n);
	           break;
	           
            case 2:
             cout<<"\t\t_TINH THAN TIEN!_"<<endl;
             thanhtien(hh,n);
               break;
               
            case 3:
             cout<<"\t\t\t_DANH SACH HANG HOA NHAP VAO!_"<<endl;
             tieude();
	         xuatnhieuhanghoa(hh ,n);
                break;
                
            case 4:
             cout<<"\t\t\t_DANH SACH SAU KHI SAP XEP!_"<<endl;
              tieude();
              sapxep(hh,n);
              xuatnhieuhanghoa(hh,n);
                break;
                
            case 5:
             cout <<"\t\t\t_HANG HOA CO THANH TIEN LON NHAT!_"<<endl;
              tieude();
              hanghoacothanhtiencaonhat(hh,n);
                break;
                
            case 6:
               cout<<"\t\t\t_THEM HANG HOA!_"<<endl;
               hanghoa x;
	           nhap1hanghoa(x);
	           chenhanghoa(hh,n,x);
               tieude();
	           xuatnhieuhanghoa(hh,n);
                 break;
                 
            case 7:
                cout<<"\t\t\t_XOA THEO DON VI TINH!_"<<endl;
			    cout<<"nhap dvt cua hang hoa can xoa:";
                cin.ignore();
				char donvicanxoa[10];
                cin.getline(donvicanxoa,10);
	            xoatheodonvitinh(hh,n,donvicanxoa);
	            n--;
                tieude();
                xuatnhieuhanghoa(hh,n);
                  break;
                  
            case 8 :
                 ghitep(hh,n);
 	              break;
 	              
   	        case 9 : 
   	             doctep(hh,n);
   	              break;
   	              
            case 0:
			     exit(1);
	              break;
	              
				default:
				cout<<"\nNHAP LAI LUA CHON\n";
				goto nhaplai;
				  break;  						
               } goto quaylai;
}
int main()
{   system("color x");
	int n;
	hanghoa hh[100],x;
	menu(hh,n,x);
	
}