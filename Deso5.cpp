#include <bits/stdc++.h>

using namespace std;

struct Date
{
	int ngay, thang, nam;
	bool bang(Date date)
	{
		return  this->thang == date.thang && this->nam == date.nam;
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
		   << setw(4) << date.nam << "|";	
		return os;
	}	
	
};

Date base()
{
	Date x(1,1,1);
	return x;
}
class KhachHang
{
	protected:
		string ma, hoTen;
		Date ngayRa;
		double soLuong;
		int donGia;
	public:
		KhachHang(string ma= "", string hoTen = "", Date ngayRa = base(), double soLuong = 0, int donGia = 0)
		{
			this->ma= ma;
			this->hoTen = hoTen;
			this->ngayRa = ngayRa;
			this->soLuong = soLuong;
			this->donGia = donGia;
		}
		
		virtual void nhap(istream& is) = 0;	
		virtual void xuat(ostream& os) = 0;
		friend istream& operator>>(istream& is, KhachHang& khachHang)
		{
			khachHang.nhap(is);
			return is;
		}
		friend ostream& operator<<(ostream& os, KhachHang& khachHang)
		{
			khachHang.xuat(os);
			return os;
		}
		virtual int getLoai() = 0;		
		virtual double thanhTien() = 0;
		Date getNgayRa()
		{
			return ngayRa;
		}
		
};

enum DoiTuongKhachHang
{
	sinhHoat = 1,
	kinhDoanh = 2,
	sanXuat = 3
};
class KhachVietNam : public KhachHang
{
	private:
		DoiTuongKhachHang doiTuong;
		double dinhMuc;
	public:
		KhachVietNam(string ma= "", string hoTen = "", Date ngayRa = base(),
						DoiTuongKhachHang doiTuong = sinhHoat, double soLuong = 0,
						int donGia = 0, double dinhMuc = 0 ): KhachHang(ma,hoTen,ngayRa,soLuong,donGia)
						{
							this->doiTuong = doiTuong;
							this->dinhMuc = dinhMuc;
						}
		void nhap(istream& is)
		{
			cout << "Nhap ma khach hang : ";
			fflush(stdin);
			getline(is, ma);
			cout << "Nhap ho ten khach hang : ";
			fflush(stdin);
			getline(is,hoTen);
			is >> ngayRa;
			cout << "Nhap so luong kW dien tieu thu : ";
			is >> soLuong;
			cout << "Nhap don gia : ";
			is >> donGia;
			cout << "Chon doi tuong khach hang :\n ";
			cout << "1. Khach hang sinh hoat\n";
			cout << "2. Khach hang kinh doanh\n";
			cout << "3. Khach hang san xuat\n";
			int chon;
			do{
				is >> chon;
			}while(chon != 1 && chon != 2 && chon != 3);
			doiTuong = (DoiTuongKhachHang)chon;
		}	
		
		void xuat(ostream& os)
		{
			os << left << "|" << setw(15) << ma << "|"
							  << setw(20) << hoTen << "|"
							  << setw(15) << soLuong << "|"
							  << setw(15) << donGia << "|"
							  <<ngayRa
							  << setw(15) << thanhTien() << "|"
							  << setw(20) << "Khach Viet Nam" <<"|" << endl;
		}
			
		int getLoai()
		{
			return 1;
		}		
		
		Date getNgayRa()
		{
			return ngayRa;
		}
		double thanhTien()
		{
			if(soLuong <= dinhMuc)
			{
				return soLuong * donGia;
			}
			else
			{
				return (soLuong -dinhMuc) * donGia * 2.5 + dinhMuc * donGia;
			}
		}
};

class KhachNuocNgoai : public KhachHang
{
	private:
		string quocTich;
	public:
		KhachNuocNgoai(string ma= "", string hoTen = "", Date ngayRa = base(),
						double soLuong = 0,	int donGia = 0, string quocTich = "" ):KhachHang(ma,hoTen,ngayRa,soLuong,donGia)
						{
							this->quocTich = quocTich;
						}
		void nhap(istream& is)
		{
			cout << "Nhap ma khach hang : ";
			fflush(stdin);
			getline(is, ma);
			cout << "Nhap ho ten khach hang : ";
			fflush(stdin);
			getline(is,hoTen);
			is >> ngayRa;
			cout << "Nhap so luong kW dien tieu thu : ";
			is >> soLuong;
			cout << "Nhap don gia : ";
			is >> donGia;
		}
		void xuat(ostream& os)
		{
			os << left << "|" << setw(15) << ma << "|"
							  << setw(20) << hoTen << "|"
							  << setw(15) << soLuong << "|"
							  << setw(15) << donGia << "|"
							  <<ngayRa
							  << setw(15) << thanhTien() << "|"
							  << setw(20) << "Khach nuoc ngoai" <<"|" << endl;
		}

		int getLoai()
		{
			return 2;
		}
		double thanhTien()
		{
			return donGia * soLuong;
		}
			
};
void line()
{
	cout << "+";
	for(int i = 0; i < 116;i++)
	cout << "-";
	cout << "+" << endl;
}
class QuanLyKhachHang
{
	private:
		vector<KhachHang*> khachHang;
	public:
		void nhapDanhSach(int n)
		{
			for(int i = 0; i < n; i++)
			{
				cout << "Nhap loai khach hang : \n";
				cout << "1. Khach Viet Nam\n";
				cout << "2. Khach nuoc ngoai\n";
				int chon;
				do{
					cin >> chon;
				}while(chon != 1 && chon != 2);
				if(chon == 1)
				{
					KhachHang* khachMoi = new KhachVietNam();
					cin >> *khachMoi;
					khachHang.push_back(khachMoi);
				}
				else
				{
					KhachHang* khachMoi = new KhachNuocNgoai();
					cin >> *khachMoi;
					khachHang.push_back(khachMoi);
				}
			}
		}
		void inDanhSach()
		{
			line();
			cout << left << "|" << setw(15) << "Ma khach" << "|"
								<< setw(20) << "Ho ten" << "|"
							 	 << setw(15) << "So luong" << "|"
								  << setw(15) << "Don Gia" << "|"
								  << setw(10) << "Ngay ra " << "|"
								  << setw(15) << "Thanh tien" << "|"
							 	 << setw(20) << "Phan loai" <<"|" << endl;
			line();
			for(auto kh:khachHang)
			{
				cout << *kh;
			}
			line();
		}
		
		void setList()
		{
			KhachHang* kh[6];
			kh[1] = new KhachVietNam("001","Nguyen Van A", {2,9,2020},sinhHoat,100,3500, 10);
			kh[0] = new KhachVietNam("000","Le Thi B",{3,9,2013},sanXuat,10,3500,10);
			kh[2] = new KhachNuocNgoai("003","Chompoo Araya", {3,9,2021}, 20,5000,"Thai Lan");
			kh[3] = new KhachNuocNgoai("004","Baifern Pimchanok", {1,1,2022}, 10, 5000,"Lao");
			kh[4] = new KhachNuocNgoai("005","Singhavong",{20,9,2013},21.5,5000,"Lao");
			kh[5] = new KhachVietNam("002", "Tran Thi H", {4,4,2024},kinhDoanh,50,3500, 10);
			for(int i = 0; i < 6; i++)
			khachHang.push_back(kh[i]);
		}
		
		void tinhTongKhach()
		{
			int khachVN = 0, khachNN = 0;
			for(auto kh:khachHang)
			{
				if(kh->getLoai() == 1)
				khachVN++;
				else
				khachNN++;
			}
			
			cout << "\nSo khach hang Viet Nam la : " << khachVN;
			cout << "\nSo khach hang nuoc ngoai la : " << khachNN;
		}
		
		double trungBinh()
		{
			int khachNN = 0;
			double tong = 0;
			for(auto kh:khachHang)
			{
				if(kh->getLoai() == 2)
				{
					khachNN += 1;
					tong += kh->thanhTien();
				}
			}
			if(khachNN != 0)
			return tong / khachNN;
			else
			return 0;
		}
		
		void xuatHoaDon_9_2013()
		{
			line();
			cout << left << "|" << setw(15) << "Ma khach" << "|"
								<< setw(20) << "Ho ten" << "|"
							 	 << setw(15) << "So luong" << "|"
								  << setw(15) << "Don Gia" << "|"
								  << setw(10) << "Ngay ra " << "|"
								  << setw(15) << "Thanh tien" << "|"
							 	 << setw(20) << "Phan loai" <<"|" << endl;
			line();
			for(auto kh:khachHang)
			{
				if(kh->getNgayRa().bang({1,9,2013}))
				cout << *kh;
			}
			line();
		}
		
		clear()
		{
			khachHang.clear();
		}
};

void Menu()
{
	QuanLyKhachHang core;
	core.setList();
	start:
	system("cls");
	cout << "===================================Menu=================================\n";
	cout << "0. Thoat chuong trinh \n";
	cout << "1. Nhap danh sach khach hang tu ban phim \n";
	cout << "2. In danh sach khach hang\n";
	cout << "3. Tinh so luong khach hang cho tung loai khach hang\n";
	cout << "4. Tinh trung binh thanh tien cuar khach hang nuoc ngoai\n";
	cout << "5. Xuat ra cac hoa dong trong thang 9 nam 2013 (cua 2 loai khach hang)\n";
	cout << "Lua chon cua ban la : ";
	int luaChon;
	do{
		cin >> luaChon;
	}while(luaChon < 0 || luaChon > 5);
	
	switch(luaChon)
	{
		case 0:
			return;
			break;
		case 1:
			core.clear();
			cout << "Nhap so luong khach hang : ";
			int n;
			do{
				cin >> n;
			}while(n < 0);
			core.nhapDanhSach(n);
			break;
		case 2:
			core.inDanhSach();
			break;
		case 3:
			core.tinhTongKhach();
			break;
		case 4:
			cout << "Trung binh thanh tien cua khach hang nuoc ngoai : " << core.trungBinh();
			break;
		case 5:
			core.xuatHoaDon_9_2013();
			break;
	}
	int iscontinue;
	cout << "\nVui long nhap : \n";
	cout << "1. Tiep tuc chuong trinh\n ";
	cout << "0. Ket thuoc chuong trinh\n";
	do{
		cin >> iscontinue;
	}while(iscontinue != 1 && iscontinue != 0);
	
	if(iscontinue)
	goto start;
	else
	return;
	
	
}
int main()
{
	Menu();
}
