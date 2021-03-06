//write your code here#include <set>
#include <stdio.h>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b)
    {
        c=b;
        b=a%b;
        a=c;

    }

    return a;
}

#define MAX 100000

char slozen[MAX];

int prost[10000];
int brProstih;

#if 0

int djel(int n, int *a)
{
    int i,koliko=0;

    for(i=1;i*i<n;i++)
        if (n%i==0)
        {
            a[koliko++]=i;
            a[koliko++]=n/i;
        }
    if (i*i==n)
        a[koliko++]=i;

    return koliko;
}


#else

int djel(int n,int *a)
{
    int i,koliko=1;

    a[0]=1;

    for(i=0;i<brProstih && prost[i]*prost[i]<=n;i++)
    {
        int q,temp,prod;

        for(q=0;n%prost[i]==0;q++,n/=prost[i]);

        if (!q) continue;

        temp=koliko;
        prod=prost[i];

        while(q--)
        {
            int j;
            for(j=0;j<koliko;j++)
                a[temp++]=a[j]*prod;

            prod*=prost[i];
        }

        koliko=temp;
    }

    if (n>1)
    {
        int j;
        for(j=0;j<koliko;j++)
            a[j+koliko]=a[j]*n;

        koliko*=2;
    }


    return koliko;
}

#endif


void kvad(long long n)
{
    long long a[4];
    long long r[9]={0};
    int i,j,temp;

    for(i=0;i<4;i++)
    {
        a[i]=n00000;
        n/=1000000;
    }

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            r[i+j]+=a[i]*a[j];


    temp=0;
    for(i=0;i<9;i++)
    {
        r[i]+=temp;
        temp=r[i]/1000000;
        r[i]%=1000000;
    }

    for(i=8;i>0 && !r[i];i--);
    printf("%lld",r[i]);
    for(i--;i>=0;i--)
        printf("lld",r[i]);
    printf("\n");


}


int main()
{
    int t;


    int i,j;


    for(i=2;i*i<MAX;i++)
        if (!slozen[i])
            for(j=i*i;j<MAX;j+=i)
                slozen[j]=1;

    for(i=2;i<MAX;i++)
        if (!slozen[i])
            prost[brProstih++]=i;

    scanf("%d",&t);

    while(t--)
    {

        set < pair<long long,long long> > parovi;

        int n;

        long long k;

        int g;


        int u,a,b;
        long long p,q;
        int m;

        int i,j;
        int polje1[1000],polje2[1000];
        int koliko1,koliko2;






        scanf("%d %lld",&n,&k);

        if (n==0)
        {
            kvad(k-1);
            continue;
        }


        u=20;


        g=n/u;


#if 1


        for(m=1;m<=g;m++)
        {
            int i,j,r,nn,mm;

            r=gcd(m,n);
            mm=m/r;
            nn=n/r;

            koliko1=djel(nn+mm*(n-1),polje1);
            koliko2=djel(nn,polje2);

            for(i=0;i<koliko2;i++)
            {
                int nd;
                nd=nn/polje2[i];
                for(j=0;j<koliko1;j++)
                {
                    if ((nd+polje1[j])%mm==0)
                    {
                        q=(long long)(nd+polje1[j])/mm*polje2[i];
                        p=n*(q+n-1);
                        if (p%(m*q-n)==0)
                        {
                            p/=m*q-n;
                            if (p<k-n && q<k-n)
                            {
                                parovi.insert(make_pair(p,q));
                                parovi.insert(make_pair(q,p));
                            }
                        }
                    }

                    if ((nd-polje1[j])%mm==0)
                    {
                        q=(nd-polje1[j])/mm*polje2[i];
                        p=n*(q+n-1);
                        if (p%(m*q-n)==0)
                        {
                            p/=m*q-n;
                            if (p<k-n && q<k-n && p>0 && q>0)
                            {
                                parovi.insert(make_pair(p,q));
                                parovi.insert(make_pair(q,p));
                            }
                        }
                    }
                }
            }
        }


#endif



#if 1

        g=u*(n-1+u);

        for(i=1;i*i<g;i++)
        {
            int p,q,nn,pp,r;

            p=u+i;

            r=gcd(n,p);
            pp=p/r;
            nn=n/r;

            for(j=pp-(u+n-1)%pp;i*j<g;j+=pp)
            {
                q=u+j;

                if (p<k-n && q<k-n && (long long)nn*(p+q+n-1)%(pp*q)==0)
                {
                    parovi.insert(make_pair(p,q));
                    parovi.insert(make_pair(q,p));
                }
            }
        }


        for(i=1;i*i<g && i<u;i++)
        {
            int p,q,nn,pp,r;


            for(j=i;i*j<g && j<u;j++)
            {
                p=u-i;
                q=u-j;

                if(p<k-n && q<k-n && (long long)n*(p+q+n-1)%(p*q)==0)
                {
                    parovi.insert(make_pair(p,q));
                    parovi.insert(make_pair(q,p));
                }
            }
        }

#endif



#if 1
        koliko1=djel(n,polje1);

        for(q=1;q<=u && q<k-n;q++)
        {
            koliko2=djel(q+n-1,polje2);

            for(i=0;i<koliko1;i++)
                for(j=0;j<koliko2;j++)
                {
                    long long v;

                    v=(long long)polje1[i]*polje2[j];

                    if ((v+n)%q==0)
                    {
                        p=n*(q+n-1)/v;

                        if (p>0 && p<k-n)
                        {
                            parovi.insert(make_pair(p,q));
                            parovi.insert(make_pair(q,p));
                        }
                    }
                }




        }



#endif

        printf("%d\n",parovi.size());
    }

    return 0;
}