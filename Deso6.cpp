#include <bits/stdc++.h>

using namespace std;

string hashName(string name)
{
	int n = name.size();
	int i = n - 1;
	while(name[i] != ' ')
	i--;
	return name.substr(i + 1, n - i - 1);	
}
class Person
{
	protected:
		string hoTen, diaChi;
	public:
		Person(string hoTen = "", string diaChi = "")
		{
			this->hoTen = hoTen;
			this->diaChi = diaChi;
		}
		
		virtual void nhap(istream& is) = 0;
		virtual void xuat(ostream& os) = 0;
		friend istream& operator>>(istream& is, Person& person)
		{
			person.nhap(is);
			return is;
		}
		friend ostream& operator<<(ostream& os, Person& person)
		{
			person.xuat(os);
			return os;
		}
		virtual void indiem()
		{
			
		}
		
		virtual int getLoai() = 0;
		virtual int diemTB()
		{
			
		}

		virtual string danhGia() = 0;
		string getHoTen()
		{
			return hoTen;
		}
		virtual double tinhLuong()
		{
			
		}
		
		string getTen()
		{
			return hoTen;
		}
};

class Student : public Person
{
	private:
		float diemMon1, diemMon2;
	public:
		Student(string hoTen = "", string diaChi = "", float diemMon1 = 0, float diemMon2 = 0):Person(hoTen, diaChi)
		{
			this->diemMon1 = diemMon1;
			this->diemMon2 = diemMon2;
		}
		
		void nhap(istream& is)
		{
			cout << "Nhap ho ten : ";
			fflush(stdin);
			getline(is, hoTen);
			cout << "Nhap dia chi : ";
			getline(is, diaChi);
			cout << "Nhap diem mon 1 : ";
			is >> diemMon1;
			cout << "Nhap diem mon 2 : ";
			is >> diemMon2;
		}
		void xuat(ostream& os)
		{
			os << left << "|" << setw(20) << hoTen << "|"
							  << setw(15) << diaChi << "|"
							  << setw(15) << diemMon1 << "|"
							  << setw(15) << diemMon2 << "|"
							  << setw(20) << danhGia() << "|\n";
		}
		string danhGia()
		{
			float diemTB = (diemMon1 + diemMon2)/2;
			if(diemTB >= 8)
				return "Hoc luc gioi";
			else if(diemTB >= 6)
				return "Hoc luc kha";
			else if(diemTB >= 4)
				return "Hoc luc trung binh ";
			else
			 	return "Hoc luc  yeu";
		}
		int getLoai()
		{
			return 1;
		}

};

class Employee : public Person
{
	private:
		float heSoLuong;
		int thamNien;
	public:
		Employee(string hoTen = "", string diaChi = "", float heSoLuong = 0, int thamNien = 0):Person(hoTen,diaChi)
		{
			this->heSoLuong = heSoLuong;
			this->thamNien = thamNien;
		}
		
		void nhap(istream& is)
		{
			cout << "Nhap ho ten : ";
			fflush(stdin);
			getline(is, hoTen);
			cout << "Nhap dia chi : ";
			getline(is, diaChi);
			cout << "Nhap he so luong  : ";
			is >> heSoLuong;
			cout << "Nhap tham nien : ";
			is >> thamNien;
		}
		
		double tinhLuong()
		{
			int luongCoBan = 5e6;
			if(danhGia() == "nhan vien cu")
				return luongCoBan * (1 + thamNien*0.05) * heSoLuong;
			else
				return luongCoBan * heSoLuong;
		}
		void xuat(ostream& os)
		{
			os << left << "|" << setw(20) << hoTen << "|"
							  << setw(15) << diaChi << "|"
							  << setw(15) << heSoLuong << "|"
							  << setw(15) << thamNien << "|"
							  << setw(20) << danhGia() << "|\n";
		}
		
		string  danhGia()
		{
			if(thamNien < 1)
				return "nhan vien moi";
			else
				return "nhan vien cu";
		}
		
		int getLoai()
		{
			return 2;
		}
};

class Customer : public Person
{
	private:
		string tenCongTy;
		double giaTri;
	public:
		Customer(string hoTen = "", string diaChi = "", string tenCongTy = "", double giaTri = 0):Person(hoTen,diaChi)
		{
			this->tenCongTy = tenCongTy;
			this->giaTri = giaTri;
		}
		
		void nhap(istream& is)
		{
			cout << "Nhap ho ten : ";
			fflush(stdin);
			getline(is, hoTen);
			cout << "Nhap dia chi : ";
			getline(is, diaChi);
			cout << "Nhap ten cong ty  : ";
			is >> tenCongTy;
			cout << "Nhap gia tri don hang : ";
			is >> giaTri;
		}
		
		void xuat(ostream& os)
		{
			os << left << "|" << setw(20) << hoTen << "|"
							  << setw(15) << diaChi << "|"
							  << setw(15) << tenCongTy << "|"
							  << setw(15) << giaTri << "|"
							  << setw(20) << danhGia() << "|\n";
		}
		string danhGia()
		{
			if(giaTri < 1e6)
				return "khach moi";
			else if(giaTri < 10e6)
				return "khach quen";
			else
				return "khach vip";
		}
		int getLoai()
		{
			return 3;
		}
};
void line()
{
	cout << left;
	cout << "+";
	for(int i = 0; i < 89; i++)
	cout << "-";
	cout << "+\n";
}
class QuanLy
{
	private:
		vector<Person*> person;
	public:
		void nhapDanhSach(int n)	
		{
			for(int i = 0; i < n; i++)
			{
				cout << "Nhap doi tuong  : \n";
				cout << "1. Hoc sinh\n";
				cout << "2. Nhan Vien\n";
				cout << "3. Khach hang\n";
				int loai;
				do
				{
					cin >> loai;
				}while(loai != 1 && loai != 2 && loai != 3) ;
				Person* nguoiMoi;
				if(loai == 1)
				{
					nguoiMoi = new Student();
					cin >> *nguoiMoi;
					person.push_back(nguoiMoi);
				}
				else if(loai == 2)
				{
					nguoiMoi = new Employee();
					cin >> *nguoiMoi;
					person.push_back(nguoiMoi);
				}
				else
				{
					nguoiMoi = new Customer();
					cin >> *nguoiMoi;
					person.push_back(nguoiMoi);
				}
			}
		}
		
		void inDanhSach()
		{
			cout << "\n\t\tDanh sach sinh vien : \n";
			line();
			cout  << left << "|" << setw(20) << "Ho ten" << "|"
							  << setw(15)<< "Dia chi"<< "|"
							  << setw(15) << "Diem mon 1" << "|"
							  << setw(15) << "Diem mon 2" << "|"
							  << setw(20) << "Danh gia" << "|\n";
			line();
			for(auto p : person)
			{
				if(p->getLoai() == 1)
				cout << *p;
			}
			line();
			
			cout << "\n\t\tDanh sach nhan vien :\n";
			line();
			cout  << left << "|" << setw(20) << "Ho ten" << "|"
							  << setw(15)<< "Dia chi"<< "|"
							  << setw(15) << "Tham nien" << "|"
							  << setw(15) << "He so lunog" << "|"
							  << setw(20) << "Danh gia" << "|\n";
			line();
			for(auto p : person)
			{
				if(p->getLoai() == 2)
				cout << *p;
			}
			line();
			
			cout << "\t\tDanh sach khach hang : \n";
			line();
			cout  << left << "|" << setw(20) << "Ho ten" << "|"
							  << setw(15)<< "Dia chi"<< "|"
							  << setw(15) << "Ten cong ty" << "|"
							  << setw(15) << "Gia tri" << "|"
							  << setw(20) << "Danh gia" << "|\n";
			line();
			for(auto p : person)
			{
				if(p->getLoai() == 3)
				cout << *p;
			}
			line();
		}
		
		
		void sapXep()
		{
			int n = person.size();
			for(int i = 0; i < n - 1; i++)
			{
				for(int j = 0; j < n - 1-i; j++)
				{
					if(hashName(person[j]->getTen()) > hashName(person[j + 1]->getTen()))
					{
						swap(person[j], person[j + 1]);
					}
				}
			}
			cout << "Sap xep thanh cong";
		}
		
		void themVaoCuoi()
		{
			cout << "Nhap doi tuong can them : \n";
				cout << "1. Hoc sinh\n";
				cout << "2. Nhan Vien\n";
				cout << "3. Khach hang\n";
				int loai;
				do
				{
					cin >> loai;
				}while(loai != 1 && loai != 2 && loai != 3) ;
				Person* nguoiMoi;
				if(loai == 1)
				{
					nguoiMoi = new Student();
					cin >> *nguoiMoi;
					person.push_back(nguoiMoi);
				}
				else if(loai == 2)
				{
					nguoiMoi = new Employee();
					cin >> *nguoiMoi;
					person.push_back(nguoiMoi);
				}
				else
				{
					nguoiMoi = new Customer();
					cin >> *nguoiMoi;
					person.push_back(nguoiMoi);
				}
				cout << "Them thanh cong";
		}
		

		void setList()
		{
			Person* list[6];
			list[0] = new Student("Nguyen Van Chien","Thai Binh",8,8);
			list[1] = new Student("Le Thu An","Hai Duong",4,3);
			list[2] = new Employee("Dinh Quoc Dat","Hoa Binh",0, 1);
			list[3] = new Employee("Dao Thu Chi","Binh Dinh",2,2);
			list[4] = new Customer("Trinh Tuan Phat","Ha Noi","An Phat" , 12e6);
			list[5] = new Customer("Dinh Thanh Binh","Son La","Viet Duc",1e5);
			for(int i = 0; i < 6; i++)
			{
				person.push_back(list[i]);	
			}
		}
		
		void xoa()
		{
			cout << "Nhap ten nguoi can xoa ";
			string ten;
			fflush(stdin);
			getline(cin, ten);
			for(int i = 0; i < person.size(); i++)
			{
				if(person[i]->getTen() == ten)
				person.erase(person.begin() + i);
			}
		}
		
		void clear()
		{
			person.clear();
		}
};
void Menu()
{
	QuanLy core;
	core.setList();
	start:
	system("cls");	
	int luaChon;
	cout << "+--------------------------------------------------------------+\n";
	cout << "|                         MENU                                 |\n";
	cout << "+--------------------------------------------------------------+\n";
	cout << "|0. Thoat chuong trinh                                         |\n";
	cout << "|1. Nhap danh nguoi                                            |\n";
	cout <<	"|2. In danh sach nguoi                                         |\n";
	cout << "|3. Them mot nguoi vao cuoi danh sach                          |\n";
	cout << "|4. Xoa mot nguoi ra khoi theo ten                             |\n";
	cout << "|5. Sap xep theo ten (a-z)                                     |\n";
	cout << "|Lua chon cua ban la :                                         |\n";
	cin >> luaChon;
	if(luaChon < 0 || luaChon > 5)
	{
		goto start;
	}
	
	switch(luaChon)
	{
		case 0:
			return;
			break;
		case 1:
			cout << "Nhap so luong nguoi: ";
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
			core.themVaoCuoi();
			break;
		case 4:
			core.xoa();
			break;
		case 5:
			core.sapXep();
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
