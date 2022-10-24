#include <iostream>
#include <cmath>

#define PI 3.14159265359

using namespace std;

class complex_number
{
    public:
        double a, b;
        complex_number()
        {
            this->a=a;
            this->b=b;
        }
        complex_number(const complex_number &q)
        {
            this->a=q.a;
            this->b=q.b;
        }
        double share(bool h)
        {
            this->a=a;
            this->b=b;
            if(h)
            {
                return a;
            }
            else
            {
                return b;
            }
        }
        void output()
        {
            if(b>=0)
            {
                cout<<"z="<<a<<"+"<<b<<"i"<<endl;
            }
            else
            {
                cout<<"z="<<a<<b<<"i"<<endl;
            }
        }
        ~complex_number()
        {
            //cout<<"Destructor"<<endl;
        }
        friend ostream& operator<< (ostream& os, const complex_number& z);
        friend istream& operator>> (istream& is, complex_number& z);
        friend complex_number operator+ (const complex_number& z1, const complex_number& z2);
        friend complex_number operator- (const complex_number& z1, const complex_number& z2);
        friend complex_number operator* (const complex_number& z1, const complex_number& z2);
        friend complex_number operator/ (const complex_number& z1, const complex_number& z2);
};
class complex_numberX:complex_number
{
    public:
        double cosalfa, sinalfa, z;
        complex_numberX()
        {
            this->z=z;
            this->cosalfa=cosalfa;
            this->sinalfa=sinalfa;
            double a=share(1);
            double b=share(0);
        }
        complex_numberX(complex_number &v)
        {
            double a=v.share(1);
            double b=v.share(0);
            this->z=sqrt(pow(a,2)+pow(b,2));
            this->cosalfa=acos(a/z);
            this->sinalfa=asin(b/z);
            // |z|!=0
            if(z==0)
            {
                throw 0;
            }
        }
        complex_number power(int n)
        {
            complex_number *R=new complex_number;
            R->a=share(1);
            R->b=share(0);
            R->a=pow(z,n)*cos(n*cosalfa);
            R->b=pow(z,n)*sin(n*sinalfa);

                //sin <-1;1>
                if(sin(n*sinalfa)>1 || sin(n*sinalfa)<-1)
                {
                    throw -1;
                }
                //cos <-1;1>
                else if(cos(n*cosalfa)>1 || cos(n*cosalfa)<-1)
                {
                    throw -2;
                }
                //power > 0
                if(n<0)
                {
                throw -3;
                }

            cout<<"power of "<<n<<":"<<endl;
            return *R;
        }
        complex_number root(int n ,int k)
        {
            //power > 0
            cout<<"root of "<<n<<":"<<endl;
            if(n<0 || k<0)
            {
                throw -4;
            }
            complex_number *P=new complex_number;
            P->a=share(1);
            P->b=share(0);
            P->a=pow(z,1.0/n)*cos((cosalfa+2*PI*k)/n);
            P->b=pow(z,1.0/n)*sin((sinalfa+2*PI*k)/n);
            return *P;
        }
        ~complex_numberX()
        {
            //cout<<"Destructor"<<endl;
        }
        friend bool operator> (const complex_numberX& z1, const complex_numberX& z2);
        friend bool operator< (const complex_numberX& z1, const complex_numberX& z2);
        friend bool operator== (const complex_numberX& z1, const complex_numberX& z2);

};

//operators

ostream &operator<< (ostream& os, const complex_number& z)
{
    if(z.b>=0)
    {
        if(z.a && z.b != 0)
        {
            os<<"z="<<z.a<<"+"<<z.b<<"i"<<endl;
        }
        else if(z.b==0)
        {
           os<<"z="<<z.a<<endl;
        }

        else if(z.a==0)
        {
            os<<"z="<<z.b<<"i"<<endl;
        }
        else if(z.a && z.b == 0)
        {
           os<<"z=0"<<endl;
        }
    }
    else
    {
        if(z.a && z.b != 0)
        {
            os<<"z="<<z.a<<z.b<<"i"<<endl;
        }
        else if(z.b==0)
        {
           os<<"z="<<z.a<<endl;
        }

        else if(z.a==0)
        {
            os<<"z="<<z.b<<"i"<<endl;
        }
        else if(z.a && z.b == 0)
        {
           os<<"z=0"<<endl;
        }
    }
    cout<<endl;
    return os;
}
istream &operator>> (istream& is, complex_number& z)
{
    cout<<"Input complex number"<<endl;
    cout<<"a:";
    is>>z.a;
    cout<<"b:";
    is>>z.b;
    cout<<endl;

    return is;
}
complex_number operator+ (const complex_number& z1, const complex_number& z2)
{
    complex_number *z=new complex_number;
    z->a=z1.a+z2.a;
    z->b=z1.b+z2.b;
    return *z;
}
complex_number operator- (const complex_number& z1, const complex_number& z2)
{
    complex_number *z=new complex_number;
    z->a=z1.a-z2.a;
    z->b=z1.b-z2.b;
    return *z;
}
complex_number operator* (const complex_number& z1, const complex_number& z2)
{
    complex_number *z=new complex_number;
    z->a=(z1.a*z2.a)-(z1.b*z2.b);
    z->b=(z1.a*z2.b)+(z1.b*z2.a);
    return *z;
}
complex_number operator/ (const complex_number& z1, const complex_number& z2)
{
    complex_number *z=new complex_number;
    z->a=((z1.a*z2.a)+(z1.b*z2.b))/(pow(z2.a,2)+pow(z2.b,2));
    z->b=((z1.b*z2.a)-(z1.a*z2.b))/(pow(z2.a,2)+pow(z2.b,2));

    //divided by 0!
    if(pow(z2.a,2)+pow(z2.b,2)==0)
       {
          throw -5;
       }
    return *z;
}
bool operator> (const complex_numberX& z1, const complex_numberX& z2)
{
    if(z1.z>z2.z)
    {
        cout<<"|z1| > |z2|"<<endl;
        return true;
    }
    else
    {
        cout<<"|z1| !> |z2|"<<endl;
        return false;
    }
}
bool operator< (const complex_numberX& z1, const complex_numberX& z2)
{
    if(z1.z<z2.z)
    {
        cout<<"|z1| < |z2|"<<endl;
        return true;
    }
    else
    {
        cout<<"|z1| !< |z2|"<<endl;
        return false;
    }
}
bool operator== (const complex_numberX& z1, const complex_numberX& z2)
{
    if(z1.z==z2.z)
    {
        cout<<"|z1| == |z2|"<<endl;
        return true;
    }
    else
    {
       cout<<"|z1| != |z2|"<<endl;
       return false;
    }
}

//main

int main()
{
    int p, r;
    complex_number z1;
    complex_number z2;

    try
    {
        cin>>z1;
        cin>>z2;

    cout<<"Complex number z1:"<<endl;
    cout<<z1;
    cout<<"Complex number z2:"<<endl;
    cout<<z2;
    cout<<"Sum of complex numbers:"<<endl;
    cout<<z1+z2;
    cout<<"Complex number difference:"<<endl;
    cout<<z1-z2;
    cout<<"Product of complex numbers:"<<endl;
    cout<<z1*z2;
    cout<<"Quotient of complex numbers:"<<endl;
    cout<<z1/z2;

    complex_numberX R1(z1);
    complex_numberX R2(z2);

    R1>R2;
    R1<R2;
    R1==R2;

    cout<<endl;
    cout<<"Input power:"<<endl;
    cin>>p;

    cout<<"Complex number z1 ";
    cout<<R1.power(p);
    cout<<"Complex number z2 ";
    cout<<R2.power(p);

    cout<<endl;
    cout<<"Input power of root:"<<endl;
    cin>>r;

    cout<<"Complex number z1 "<<endl;
    for(int i=1; i<r+1 ; i++)
    {
        cout<<i<<" element "<<R1.root(r,i);
    }
    cout<<"Complex number z2 "<<endl;
    for(int i=1; i<r+1 ; i++)
    {
        cout<<i<<" element "<<R2.root(r,i);
    }

    }
    catch(int e)
    {
        cout<<"ERROR: "<<e<<endl;
    }
}

