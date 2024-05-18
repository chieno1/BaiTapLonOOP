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
		double donGia;
	public:
		KhachHang(string ma= "", string hoTen = "", Date ngayRa = base(), double soLuong = 0, double donGiao = 0)
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
						double donGia = 0, double dinhMuc = 0 ): KhachHang(ma,hoTen,ngayRa,soLuong,donGia)
						{
							this->doiTuong = doiTuong;
							this->dinhMuc = dinhMuc;
						}
		void nhap(istream& is)
		{
			cout << "Nhap ma khac hang : ";
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
							  << setw(15) << hoTen << "|"
							  << setw(15) <<fixed << setprecision(1)<< soLuong << "|"
							  << setw(15) <<fixed << setprecision(1)<< donGia << "|"
							  <<ngayRa
							  << setw(15) <<fixed << setprecision(1)<< thanhTien() << "|"
							  << setw(20) << "Khach Viet Nam" <<"|\n";
		}
			
		int getLoai()
		{
			return 1;
		}		
		
		double thanhTien()
		{
			if(soLuong <= dinhMuc)
			{
				return soLuong * donGia;
			}
			else
			{
				return (soLuong -dinhMuc) * donGia  + dinhMuc * donGia;
			}
		}
};

class KhachNuocNgoai : public KhachHang
{
	private:
		string quocTich;
	public:
		KhachNuocNgoai(string ma= "", string hoTen = "", Date ngayRa = base(),
						double soLuong = 0,	double donGia = 0, string quocTich = "" ):KhachHang(ma,hoTen,ngayRa,soLuong,donGia)
						{
							this->quocTich = quocTich;
						}
		void nhap(istream& is)
		{
			cout << "Nhap ma khac hang : ";
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
							  << setw(15) << hoTen << "|"
							  << setw(15) <<fixed << setprecision(1)<< soLuong << "|"
							  << setw(15) <<fixed << setprecision(1)<< donGia << "|"
							  <<ngayRa
							  << setw(15) <<fixed << setprecision(1)<< thanhTien() << "|"
							  << setw(20) << "Khach nuoc ngoai" <<"|\n";
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
			for(auto kh:khachHang)
			{
				cout << *kh;
			}
		}
		
		void setList()
		{
			KhachHang* kh[6];
			kh[1] = new KhachVietNam("001","Nguyen Van A", {2,9,2020},1,3500,12, 10);
			kh[0] = new KhachVietNam("000","Le Thi B",{3,9,2013},3500,5,10);
			kh[2] = new KhachNuoc
		}
		
		
};
int main()
{
	QuanLyKhachHang a;
	a.nhapDanhSach(1);
	a.inDanhSach();
}
