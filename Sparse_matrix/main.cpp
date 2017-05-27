#include <stdio.h>
#define smax 100
#define left 100
#define light 100
#include <malloc.h>
typedef int datatype;
using namespace std;

typedef struct
{
    int i,j;
    datatype v;
}node;

typedef struct
{
    int m,n,t;
    node data[smax];
}spmatrix;

void creat (spmatrix *a)
{
    printf("");
    scanf("%d%d%d",&a->m,&a->n,&a->t);
    printf("");
    for(int i=0;i<a->t;i++)
    {
        printf("\t");
        scanf("%d%d%d",&a->data[i].i,&a->data[i].j,&a->data[i].v);
    }
}

void printjuzhen(spmatrix *a)
{
    int pa,pb;
    int juzhen[left][light];
    for(pa=0;pa<left;pa++)
    {
        for(pb=0;pb<light;pb++)
            juzhen[pa][pb]=0;
    }
    for(int k=0;k<a->t;k++)//
        juzhen[a->data[k].i][a->data[k].j]=a->data[k].v;

    for(int l=1;l<=(a->m);l++)
    {
        printf("\t");
        for(int j=1;j<=(a->n);j++)
            printf("%d  ",juzhen[l][j]);
        printf("\n");
    }
}

spmatrix* zhuanzhi(spmatrix *a)
{
    spmatrix *b;
    b=(spmatrix *)malloc(sizeof(spmatrix));
    b->m=a->n;
    b->n=a->m;
    b->t=a->t;
    if(a->t>0)
    {
        int q=0;
        for(int col=0;col<=a->n;col++)
            for(int p=0;p<a->t;p++)
                if(a->data[p].j==col)
                {
                    b->data[q].i=a->data[q].j;
                    b->data[q].j=a->data[q].i;
                    b->data[q].v=a->data[q].v;
                    q++;
                }
    }
    return b;
}

spmatrix* multiplication(spmatrix *a,spmatrix *b)
{
    spmatrix *c;
    c=(spmatrix *)malloc(sizeof(spmatrix));
    c->m=a->m;
    c->n=b->n;
    c->t=0;
    for(int l=0;l<smax;l++)
        c->data[l].i=c->data[l].j=c->data[l].v=0;

    for(int m=0;m<a->t;m++)
    {
        for(int n=0;n<b->t;n++)
        {
            if(a->data[m].j==b->data[n].i)
            {
                for(int h=0;h<smax;h++)
                {
                    if(c->data[h].i==a->data[m].i)
                    {
                        if(c->data[h].j==b->data[n].j)
                        {
                            c->data[h].v=c->data[h].v+a->data[m].v*b->data[n].v;
                            break;
                        }
                    }
                    if(c->data[h].i==0||c->data[h].j==0)
                    {
                        c->data[h].i=a->data[m].i;
                        c->data[h].j=b->data[n].j;
                        c->data[h].v=c->data[h].v+a->data[m].v*b->data[n].v;
                        c->t=c->t+1;
                        break;
                    }
                }

            }
        }
    }
    return c;
}

int main(void)
{
    spmatrix *a,*b,*c;
    a=(spmatrix *)malloc(sizeof(spmatrix));
    b=(spmatrix *)malloc(sizeof(spmatrix));
    c=(spmatrix *)malloc(sizeof(spmatrix));
    printf("");
    creat(a);
    printf("");
    creat(b);

    if(a->n==b->m)
    {
        if(a->t*b->t==0)
        {
            printf("");
        }
        else
        {
            c->m=a->m;
            c->n=b->n;
            c->t=0;
            for(int l=0;l<smax;l++)
                c->data[l].i=c->data[l].j=c->data[l].v=0;

            printjuzhen(multiplication(a,b));
        }
    }
    else
        printf("");

    return 0;
}

