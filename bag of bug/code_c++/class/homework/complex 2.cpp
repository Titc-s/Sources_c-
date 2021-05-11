#include<iostream>
using namespace std;
class complex
{
    public:
        complex(int r = 0,int i=0)
        {
            real = r;
            imag = i;
        }
     	friend complex operator+(complex &b,complex &a)
		{
			return complex(b.real+a.real,b.imag+a.imag);
		}
		friend complex operator-(complex &b,complex &a)
		{
			return complex(b.real-a.real,b.imag-a.imag);
		}
		friend complex operator*(complex &b,complex &a)
		{
			return complex(b.real*a.real-b.imag*a.imag,b.imag*a.real+b.real*a.imag);
		}
		friend int operator==(complex &b,complex &a)
		{
			if(b.real==a.real&&b.imag==a.imag)
			return 1;
			else
			return 0;
		}
       friend complex operator++(complex &a)
        {
            a.real += 1;
            a.imag+=1;
            return complex(a.real, a.imag);
        }
        friend complex operator++(complex &a,int)
        {
            int r = a.real;
            int i = a.imag;
            a.real += 1;
            a.imag+=1;
            return complex(r, i);
        }
        friend complex operator--(complex &a)
        {
            a.real -= 1;
            a.imag-=1;
            return complex(a.real, a.imag);
        }
         friend complex operator--(complex&a,int)
        {
            int r = a.real;
            int i = a.imag;
            a.real -= 1;
            a.imag-=1;
            return complex(r, i);
        }
        friend ostream&operator<<(ostream &out,const complex &c)
        {
            if(c.imag>=0)
            out << c.real << "+" << c.imag << "i";
            else
                out << c.real << c.imag << "i";
            cout << endl;
            return out;
        }
        friend istream&operator<<(istream &in,complex&c)
        {
            in >> c.real >> c.imag;
            return in;
        }
        void show()
        {
            if(imag>=0)
            cout << real <<"+" << imag << "i" << endl;
            else
                cout << real << imag << "i" << endl;
        }
        private:
            int real, imag;
};
int main()
{
   complex a, b(1, 2), c(10, 20), d(30, 40);
   a = b + c;
   a.show();
   cout << a;
   a = b - c;
   a.show();
    cout << a;
   a = b * c;
   a.show();
    cout << a;
   ++b;
   b.show();
   cout << b;
   b++;
   b.show();
    cout << b;
   --c;
   c.show();
    cout << c;
   c--;
   c.show();
    cout << c;
   return 0;
}