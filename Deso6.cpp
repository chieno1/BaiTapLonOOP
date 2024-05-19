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
		
		string getHoTen()
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
							  << setw(15) << diemMon2 << "|";
		}

};
int main()
{
	cout << hashName("le Chie");
}
