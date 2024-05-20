#include <bits/stdc++.h>

using namespace std;

struct Date
{
	int ngay, thang, nam;
	bool bang(Date date)
	{
		return  this->ngay == date.ngay && this->thang == date.thang && this->nam == date.nam;
	}
	Date(int ngay, int thang, int nam)
	{
		this->ngay = ngay;
		this->thang = thang;
		this->nam = nam;
	}
	friend istream& operator>>(istream& is, Date& date)
	{
		cout << "Nhap ngay : ";
		is >> date.ngay;
		cout << "Nhap thang : ";
		is >> date.thang;
		cout << "Nhap nam : ";
		is >> date.nam;
		return is;
	}
	Date()
	{
		
	}
	friend ostream& operator<<(ostream& os, Date date)
	{
		os << setw(2) << date.ngay << "/"
		   << setw(2) << date.thang << "/"
		   << setw(4) << date.nam ;	
		return os;
	}	
	 bool nho(Date date)
	 {
	 	int x = date.nam * 365 + date.thang * 30 + date.ngay;
	 	int y = this->nam * 365 + this->thang * 30 + this->ngay;
	 	return y < x;
	 }
};

Date base()
{
	Date x(1,1,1);
	return x;
}

class GiaoDich
{
	protected:
		string ma;
		Date ngayGiaoDich;
		double donGia;
		int soLuong;
	public:
		GiaoDich(string ma = "", Date ngayGiaoDich = base(), double donGia = 0, int soLuong = 0)
		{
			this->ma = ma;
			this->ngayGiaoDich = ngayGiaoDich;
			this->donGia = donGia;
			this->soLuong = soLuong;
		}
		
		virtual double thanhTien() = 0;
		virtual int getLoai() = 0;
		double getDonGia()
		{
			return donGia;
		}
		Date getNgayGiaoDich()
		{
			return ngayGiaoDich;
		}
		
		virtual void nhap(istream &is) = 0;
		virtual void xuat(ostream& os) = 0;
		friend istream& operator>>(istream& is, GiaoDich& giaodich)
		{
			giaodich.nhap(is);
			return is;
		}
		friend ostream& operator<<(ostream& os, GiaoDich& giaodich)
		{
			giaodich.xuat(os);
			return os;
		}
		
};

class GiaoDichVang : public GiaoDich
{
	private:
		string loaiVang;
	public:
		GiaoDichVang(string ma = "", Date ngayGiaoDich = base(), double donGia = 0, int soLuong = 0, string loaiVang = ""):GiaoDich(ma,ngayGiaoDich,donGia,soLuong)
		{
			this->loaiVang = loaiVang;
		}
		
		void nhap(istream& is)
		{
			cout << "Nhap ma giao dich : ";
			fflush(stdin);
			getline(is, ma);
			is >> ngayGiaoDich;
			cout << "Nhap don gia : ";
			is >> donGia;
			cout << "Nhap so luong : ";
			is >> soLuong;
			cout << "Nhap loai vang : ";
			fflush(stdin);
			getline(is, loaiVang);
		}
		
		void xuat(ostream& os)
		{
			os << left << "|" << setw(15) << ma << "|"
							  << ngayGiaoDich << "|"
							  << setw(15) << donGia << "|"
							  << setw(15) << soLuong << "|"
							  << setw(20) << thanhTien() << "|"
							  << setw(20) << "Giao dich vang"<<"|" 
							  << setw(15) << loaiVang << "|\n";
		}
		double thanhTien()
		{
			return donGia * soLuong;
		}
		double getDonGia()
		{
			return donGia;
		}
		int getLoai()
		{
			return 1;
		}
};
enum LoaiTien
{
	VND = 1,
	USD = 2,
	EURO = 3	
};
class GiaoDichTien : public GiaoDich
{
	private:
		LoaiTien loaiTien;
		double tiGia;
	public:
		GiaoDichTien(string ma = "", Date ngayGiaoDich = base(), double donGia = 0, int soLuong = 0, LoaiTien loaiTien = VND, double tiGia = 0):GiaoDich(ma,ngayGiaoDich,donGia,soLuong)
		{
			this->loaiTien = loaiTien;
			this->tiGia = tiGia;
		}
		
		void nhap(istream& is)
		{
			cout << "Nhap ma giao dich : ";
			fflush(stdin);
			getline(is, ma);
			is >> ngayGiaoDich;
			cout << "Nhap don gia : ";
			is >> donGia;
			cout << "Nhap so luong : ";
			is >> soLuong;
			cout << "Nhap loai tien te : \n";
			cout << "1. VND\n";
			cout << "2. EURO\n";
			cout << "3. USD\n";
			int loai;
			do{
				is >> loai;
			}while(loai < 1 || loai > 3);
			loaiTien = (LoaiTien)loai;
			if(loai != 1)
			{
				cout << "Nhap ti gia : ";
				is >> tiGia;
			}
			else
			tiGia = 1;
		}
		
		void xuat(ostream& os)
		{
			os << left << "|" << setw(15) << ma << "|"
							  << ngayGiaoDich << "|"
							  << setw(15) << donGia << "|"
							  << setw(15) << soLuong << "|"
							  << setw(20) << thanhTien() << "|"
							  << setw(20) << "Giao dich tien"<<"|" ;
			if(loaiTien == 1)
							 cout << setw(15) <<  "VND"<< "|\n";
			if(loaiTien == 2)
							 cout << setw(15) <<  "EURO"<< "|\n";
			if(loaiTien == 3)
							 cout  << setw(15) <<  "USD"<< "|\n";
		}
		
		int getLoai()
		{
			return 2;
		}
		
		double thanhTien()
		{
			return donGia * soLuong * tiGia;
		}
};

void line()
{
	cout << "+";
	for(int i = 0; i < 116; i++)
	cout << "-";
	cout << "+\n";
}
class QuanLyGiaoDich
{
	private:
		vector<GiaoDich*> giaoDich;
	public:
		void nhapDanhSach(int n)	
		{
			for(int i = 0; i < n; i++)
			{
				cout << "Nhap loai giao dich : \n";
				cout << "1. Giao dich vang\n";
				cout << "2. Giao dich tien te\n";
				int loai;
				do
				{
					cin >> loai;
				}while(loai != 1 && loai != 2);
				GiaoDich* giaoDichMoi;
				if(loai == 1)
				{
					giaoDichMoi = new GiaoDichVang();
					cin >> *giaoDichMoi;
					giaoDich.push_back(giaoDichMoi);
				}
				else
				{
					giaoDichMoi = new GiaoDichTien();
					cin >> *giaoDichMoi;
					giaoDich.push_back(giaoDichMoi);
				}
			}
		}
		
		void inDanhSach()
		{
			cout << "\n\t\tDanh sach giao dich vang\n";
			line();
			cout  << left << "|" << setw(15) << "Ma" << "|"
							  << setw(10)<< "Ngay"<< "|"
							  << setw(15) << "Don gia" << "|"
							  << setw(15) << "So luong" << "|"
							  << setw(20) << "Thanh tien" << "|"
							  << setw(20) << "Loai giao dich" << "|" 
							  << setw(15) << "Loai vang" << "|\n";
			line();
			for(auto gd : giaoDich)
			{
				if(gd->getLoai() == 1)
				cout << *gd;
			}
			line();
			cout << "\n\t\tDanh sach giao dich tien te\n";
			line();
			cout  << left << "|" << setw(15) << "Ma" << "|"
							  << setw(10)<< "Ngay"<< "|"
							  << setw(15) << "Don gia" << "|"
							  << setw(15) << "So luong" << "|"
							  << setw(20) << "Thanh tien" << "|"
							  << setw(20) << "Loai giao dich" << "|" 
							  << setw(15) << "Loai tien" << "|\n";
			line();
			for(auto gd : giaoDich)
			{
				if(gd->getLoai() == 2)
				cout << *gd;
			}
			line();
		}
		
		void tinhTong()
		{
			int gdVang = 0, gdTien = 0;
			for(auto gd : giaoDich)
			{
				if(gd->getLoai() == 1)
				gdVang += 1;
				else
				gdTien += 1;
			}
			cout << "\nSo giao dich vang la : " << gdVang;
			cout << "\nSo giao dich tien la : " << gdTien;
		}
		
		int demGdVang()
		{
			int cnt = 0;	
			for(auto gd : giaoDich)
			{
				if(gd->getLoai() == 1 && gd->getNgayGiaoDich().bang({20, 3, 2015}))
				{
					cnt++;
				}
			}
			return cnt;
		}
		
		void sapXep()
		{
			int n = giaoDich.size();
			for(int i = 0; i < n - 1; i++)
			{
				for(int j = 0; j < n - 1-i; j++)
				{
					if(giaoDich[j]->getNgayGiaoDich().nho(giaoDich[j + 1]->getNgayGiaoDich()))
					{
						swap(giaoDich[j], giaoDich[j + 1]);
					}
				}
			}
			cout << "Sap xep thanh cong";
		}
		
		void themVaoCuoi()
		{
			cout << "Nhap loai giao dich can them: \n";
				cout << "1. Giao dich vang\n";
				cout << "2. Giao dich tien te\n";
				int loai;
				do
				{
					cin >> loai;
				}while(loai != 1 && loai != 2);
				GiaoDich* giaoDichMoi;
				if(loai == 1)
				{
					giaoDichMoi = new GiaoDichVang();
					cin >> *giaoDichMoi;
					giaoDich.push_back(giaoDichMoi);
				}
				else
				{
					giaoDichMoi = new GiaoDichTien();
					cin >> *giaoDichMoi;
					giaoDich.push_back(giaoDichMoi);
				}
			cout << "Them thanh cong ";
		}
		
		void xoaGiaoDich()
		{
			for(int i = 0; i < giaoDich.size(); i++)
			{
				if(giaoDich[i]->getLoai() == 1 && giaoDich[i]->getNgayGiaoDich().bang({20, 5, 2015}))
				{
					giaoDich.erase(giaoDich.begin() + i);
				}
			}
			cout << "Xoat thanh cong";
		}
		void setList()
		{
			GiaoDich* list[6];
			list[0] = new GiaoDichTien("000",{19,2,2000},123213,15000, EURO,21000);
			list[1] = new GiaoDichVang("001",{20,3,2015},1000000000,19, "SCJ");
			list[2] = new GiaoDichVang("002",{20,5,2015},5000000,10, "999");
			list[3] = new GiaoDichTien("003",{21,1,2019},10888888,12,VND, 1);
			list[4] = new GiaoDichVang("004",{20,5,2010}, 1987698, 5, "888");
			list[5] = new GiaoDichTien("005",{21,10,2021},10000000000,12,VND, 1);
			for(int i = 0; i < 6; i++)
			{
				giaoDich.push_back(list[i]);	
			}
		}
		void xuatGiaoDichTren1Ty()
		{
			cout << "\n\t\tDanh sach giao dich vang tren 1 ty\n";
			line();
			cout  << left << "|" << setw(15) << "Ma" << "|"
							  << setw(10)<< "Ngay"<< "|"
							  << setw(15) << "Don gia" << "|"
							  << setw(15) << "So luong" << "|"
							  << setw(20) << "Thanh tien" << "|"
							  << setw(20) << "Loai giao dich" << "|" 
							  << setw(15) << "Loai vang" << "|\n";
			line();
			for(auto gd : giaoDich)
			{
				if(gd->getLoai() == 1 && gd->getDonGia() > 1e6)
				cout << *gd;
			}
			line();
		}
		
		void clear()
		{
			giaoDich.clear();
		}
};

void Menu()
{
	QuanLyGiaoDich core;
	core.setList();
	start:
	system("cls");	
	int luaChon;
	cout << "+--------------------------------------------------------------+\n";
	cout << "|                         MENU                                 |\n";
	cout << "+--------------------------------------------------------------+\n";
	cout << "|0. Thoat chuong trinh                                         |\n";
	cout << "|1. Nhap danh sach giao dich                                   |\n";
	cout <<	"|2. In danh sach cac loai giao dich                            |\n";
	cout << "|3. Tinh tong so luong cho tung loai giao dich                 |\n";
	cout << "|4. Xuat ra cac giao dich co don gia > 1 ty                    |\n";
	cout << "|5. Dem nhung giao dich vao ngay 20/3/2015                     |\n";
	cout << "|6. Sap xep danh sach theo chieu giam cua ngay giao dich       |\n";
	cout << "|7. Them giao dich vao cuoi danh sach                          |\n";
	cout << "|8. Xoa giao dich vang ngay 20/05/2010                         |\n";
	cout << "|Lua chon cua ban la :                                         |\n";
	cin >> luaChon;
	if(luaChon < 0 || luaChon > 8)
	{
		goto start;
	}
	
	switch(luaChon)
	{
		case 0:
			return;
			break;
		case 1:
			cout << "Nhap so luong giao dich : ";
			int n;
			do{
				cin >> n;
			}while(n < 0);
			core.clear();
			core.nhapDanhSach(n);
			break;
		case 2:
			core.inDanhSach();
			break;
		case 3:
			core.tinhTong();
			break;
		case 4:
			core.xuatGiaoDichTren1Ty();
			break;
		case 5:
			cout << "So giao dich vang ngay 20/3/2015 la : " << core.demGdVang();
			break;
		case 6:
			core.sapXep();
			break;
		case 7:
			core.themVaoCuoi();
			break;
		case 8:
			core.xoaGiaoDich();
			break;
	}
	int luaChon2;
	cout << "\n1. Tiep tuc chuong trinh\n";
	cout << "2. Ket thuc chuong trinh \n";
	cout << "Lua chon cua ban la :";
	do{
		cin >> luaChon2;
	}while(luaChon2 != 1 && luaChon != 2);
	if(luaChon2 == 1)
	{
		goto start;
	}
	else
	{
		return;
	}
	
}
int main()
{
	Menu();
}
