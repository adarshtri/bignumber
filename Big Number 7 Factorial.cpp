#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class BigNu
{
    char str[200];
    int len;
    int eq[200];
public:
    BigNu();
    BigNu(BigNu &x);
    BigNu(int x);
    friend istream &operator>>(istream &in,BigNu &x);
    friend ostream &operator<<(ostream &out,BigNu &x);
    BigNu operator+(BigNu &x);
    void conv2int();
    int countn();
    int countnn();
    BigNu operator*(BigNu x);
    BigNu operator-(BigNu x);
    friend BigNu fact(int x);
    void display()
    {
        for(int i=0;i<200;i++)
            cout<<eq[i];
    }
};
BigNu::BigNu()
{
    len=0;
    for(int i=0;i<200;i++)
        eq[i]=0;
}
BigNu::BigNu(int x)
{
    for(int j=0;j<200;j++)
        eq[j]=0;
    int i=0;
    while(x!=0)
    {
        eq[199-i]=x%10;
        i+=1;
        x=x/10;
    }
}
BigNu::BigNu(BigNu &x)
{
    len=strlen(x.str);
    strcpy(str,x.str);
    for(int i=0;i<200;i++)
        eq[i]=x.eq[i];
}
void BigNu::conv2int()
{
        int i=0;
        while(str[i]!='\0')
        {
            eq[200-len+i]=str[i]-48;
            i++;
        }
}
ostream &operator<<(ostream &out, BigNu &x)
{
    int i=x.countnn();
    x.len=strlen(x.str);
    while(i<200)
    {
        out<< x.eq[i];
        i++;
    }
    return out;
}
istream &operator>>(istream &in,BigNu &x)
{
    in>> x.str;
    x.len=strlen(x.str);
    x.conv2int();
    return in;
}
int BigNu::countn()
{
    int i=0;
    while(eq[i]==0)
        i+=1;
    i=200-i;
    return i;
}
int BigNu::countnn()
{
    int i=0;
    while(eq[i]==0)
        i+=1;
    return i;
}
BigNu BigNu::operator+(BigNu &x)
{
        BigNu t;
        int i=0;
        if(countn()>=x.countn())
        {
            while(i<countn())
            {
                t.eq[200-i-1]+=eq[200-i-1]+x.eq[200-i-1];
                t.str[200-i-1]=str[200-i-1]+x.str[200-i-1];
                if(t.eq[200-i-1]>=10)
                {
                    t.eq[200-i-1-1]+=((t.eq[200-i-1])/10);
                    t.str[200-i-1-1]=48+1;
                    t.eq[200-i-1]=t.eq[200-i-1]%10;
                }
                i++;
            }
        }
        else
        {
             while(i<x.countn())
            {
                t.eq[200-i-1]+=eq[200-i-1]+x.eq[200-i-1];
                t.str[200-i-1]=str[200-i-1]+x.str[200-i-1];
                if(t.eq[200-i-1]>=10)
                {
                    t.eq[200-i-1-1]+=1;
                    t.str[200-i-1-1]=48+1;
                    t.eq[200-i-1]=t.eq[200-i-1]-10;
                }
                i++;
            }
        }
        t.len=t.countn();
        return t;
}
BigNu BigNu::operator*(BigNu x)
{
        int i=0,j;
        BigNu b;
        while(i<x.countn())
        {
            BigNu c;
            for(j=0;j<countn();j++)
            {
                c.eq[199-j-i]+=((eq[199-j])*(x.eq[199-i]));
                   if(c.eq[199-j-i]>=10)
                   {
                       c.eq[199-j-i-1]=c.eq[199-j-i]/10;
                       c.eq[199-j-i]=c.eq[199-j-i]%10;
                   }
            }
            b=b+c;
            i++;
        }
        return b;
}
BigNu BigNu::operator-(BigNu x)
{
   BigNu c;
   if(countn()>x.countn())
   {
       int i,j;
       i=0;
       while(i<countn())
       {
           if(eq[199-i]>=x.eq[199-i])
            {
                c.eq[199-i]=eq[199-i]-x.eq[199-i];
                i++;
                continue;
            }
            if(eq[199-i]<x.eq[199-i]||eq[199-i]==0)
            {
                for(j=i+1;j<countn();j++)
                {
                    if(eq[199-j]!=0)
                    {
                        eq[199-j]=eq[199-j]-1;
                        goto start;
                    }
                }
                start:;
                j=j-1;
                while(j>i)
                {
                    eq[199-j]=9;
                    c.eq[199-j]=eq[199-j]-x.eq[199-j];
                    j--;
                }
                eq[199-i]=eq[199-i]+10;
                c.eq[199-i]=eq[199-i]-x.eq[199-i];
            }
            i++;
        }
        cout<<"\n   Difference is:";
   }
   else if(countn()==x.countn())
   {
        int m;
        for(m=countn()-1;m>=0;m--)
        {
            if(eq[199-m]==x.eq[199-m])
                continue;
            else
                goto en;
        }
        en:;
        if(m==-1)
            cout<<"The numbers are equal";
        if(eq[199-m]>x.eq[199-m])
        {
            int i,j;
            i=0;
            while(i<countn())
            {
                if(eq[199-i]>=x.eq[199-i])
                {
                    c.eq[199-i]=eq[199-i]-x.eq[199-i];
                    i++;
                    continue;
                }
                if(eq[199-i]<x.eq[199-i]||eq[199-i]==0)
                {
                    for(j=i+1;j<countn();j++)
                    {
                        if(eq[199-j]!=0)
                        {
                            eq[199-j]=eq[199-j]-1;
                            goto start2;
                        }
                    }
                    start2:;
                    j=j-1;
                    while(j>i)
                    {
                        eq[199-j]=9;
                        c.eq[199-j]=eq[199-j]-x.eq[199-j];
                        j--;
                    }
                    eq[199-i]=eq[199-i]+10;
                    c.eq[199-i]=eq[199-i]-x.eq[199-i];
                }
                i++;
            }
            cout<<"\n   Difference is:";
        }
        else
        {
            int i,j;
            i=0;
            while(i<x.countn())
            {
                if(x.eq[199-i]>=eq[199-i])
                {
                    c.eq[199-i]=x.eq[199-i]-eq[199-i];
                    i++;
                    continue;
                }
                if(x.eq[199-i]<eq[199-i]||x.eq[199-i]==0)
                {
                    for(j=i+1;j<x.countn();j++)
                    {
                        if(x.eq[199-j]!=0)
                        {
                            x.eq[199-j]=x.eq[199-j]-1;
                            goto start3;
                        }
                    }
                    start3:;
                    j=j-1;
                    while(j>i)
                    {
                        x.eq[199-j]=9;
                        c.eq[199-j]=x.eq[199-j]-eq[199-j];
                        j--;
                    }
                    x.eq[199-i]=x.eq[199-i]+10;
                    c.eq[199-i]=x.eq[199-i]-eq[199-i];
                }
                i++;
            }
            cout<<"\n   Difference is:-";
        }
   }
   else
   {
        int i,j;
       i=0;
       while(i<x.countn())
       {
           if(x.eq[199-i]>=eq[199-i])
            {
                c.eq[199-i]=x.eq[199-i]-eq[199-i];
                i++;
                continue;
            }
            if(x.eq[199-i]<eq[199-i]||x.eq[199-i]==0)
            {
                for(j=i+1;j<x.countn();j++)
                {
                    if(x.eq[199-j]!=0)
                    {
                        x.eq[199-j]=x.eq[199-j]-1;
                        goto start1;
                    }
                }
                start1:;
                j=j-1;
                while(j>i)
                {
                    x.eq[199-j]=9;
                    c.eq[199-j]=x.eq[199-j]-eq[199-j];
                    j--;
                }
                x.eq[199-i]=x.eq[199-i]+10;
                c.eq[199-i]=x.eq[199-i]-eq[199-i];
            }
            i++;
        }
        cout<<"\n   Difference is:-";
   }
return c;
}
BigNu fact(int n)
{
    BigNu res(n);
    while(n!=0)
    {
        BigNu c(n-1);
        if(n==1)
            return res;
        res=res*c;
        n-=1;
    }

}
main()
{
    int n;
    cout<<"\t\t"<<"Menu\n";
    cout<<"\t1. Add two big numbers\n";
    cout<<"\t2. Subtract two big numbers\n";
    cout<<"\t3. Multiply two big numbers\n";
    cout<<"\t4. Factorial of a big number<=120\n";
    cout<<"\t   Enter your choice:";
    cin>>n;
    switch(n)
    {
    case 1:
        {
            BigNu b1,b2,b3;
            cout<<"\n   Enter the first big number:";
            cin>>b1;
            cout<<"\n   Enter the second big number:";
            cin>>b2;
            b3=b1+b2;
            cout<<"\n   Sum is:";
            cout<<b3;
        }
        break;
    case 2:
        {
            BigNu b1,b2,b3;
            cout<<"\n   Enter the first big number:";
            cin>>b1;
            cout<<"\n   Enter the second big number:";
            cin>>b2;
            b3=b1-b2;
            cout<<b3;
        }
        break;
    case 3:
        {
            BigNu b1,b2,b3;
            cout<<"\n   Enter the first big number:";
            cin>>b1;
            cout<<"\n   Enter the second big number:";
            cin>>b2;
            b3=b1*b2;
            cout<<"\n   Product is:";
            cout<<b3;
        }
        break;
    case 4:
        {
            BigNu b2;
            int n;
            cout<<"\n   Enter the big number:";
            cin>>n;
            b2=fact(n);
            cout<<"\n   Factorial is:";
            cout<<b2;
        }
        break;
    default:
        cout<<"\n   \t   Wrong Input";
    }
}
