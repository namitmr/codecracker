
//#include<conio.h>
//0000000000000000000000000000//
//%%%%   Archit Srivastava %%%//
//        NIT Durgapur        //
//0000000000000000000000000000//
#include<ctype.h>
#include<cstdio>
#include<stdio.h>
#include<utility>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<string>
#include<set>
#include<time.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
#define mods 1000000009
//
//inline int ri()
//{
//    int n=0;char c;
//    while(1)
//    {
//        c=getchar();//_unlocked();
//        if(c=='\n'||c==' '||c==EOF)break;
//        n=(n<<3) + (n<<1) +c-48;
//    }
//    return n;
//}
/*
inline long long rll()
{
    long long n=0;
    char c;
    while(1)
    {
        c=getchar_unlocked();
        if(c=='\n'||c==' '||c==EOF)break;
        n=(n<<3) + (n<<1) + c - 48;
    }
    return n;
}
*/
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef unsigned long long LL;

#define PI (3.141592653589793)
#include<fstream>

//vector < vector <int> > occ(100005);


int main()
{
    int t;
    si(t);
    while(t--)
    {
        vector < vector <int> > occ(100005);
            int n,m,i,j,k;
        si(n);si(m);
        rep(i,n)
        {
            int temp;
            si(temp);
            occ[temp].PB(i+1);
        }
        while(m--)
        {
            int g,x,y;
            si(g);si(x);si(y);
            if(occ[g].size()==0)
                printf("No 0");
            else
            {
                int m=upper_bound(occ[g].begin(),occ[g].end(),y)-lower_bound(occ[g].begin(),occ[g].end(),x);
                if(m>0)
                printf("Yes %d",m);
                else
                printf("No 0");

//                cout<<upper_bound(occ[i].begin(),occ[i].end(),y)-occ[i].begin();
//                cout<<lower_bound(occ[i].begin(),occ[i].end(),x)-occ[i].begin();
            }
            pn;
        }

    }
}