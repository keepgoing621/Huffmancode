#include"header.h"



void codedecode(char a[],char *p)
{

    int *zushu;
    int *bu;
    int b,c;
    void code(int *z, int *b, char a[]);
    void decode(int *z, int *b, char save[]);

    zushu = &b;
    bu = &c;
    code(zushu, bu, a);
    decode(zushu, bu, p);


}

void code(int *z,int *b,char quan[])
{

    int calculate(char ban[],FILE *fp);
    int i,j;
    FILE *fp;
    fp=fopen("D:\\Encode.dat","wb");
    i=j=0;
    for(i = 0; i<20000; i++)
    {
        if(quan[i]=='\0')
        {
            break;
        }
    }
    printf("%d\n",i);
    if(i%8==0)
    {
        *z = i/8;
    }

    else
    {
        *z = i/8+1;
    }
    *b=8*(*z)-i;
    for(j=i; j<8*(*z); j++)
    {
        quan[j]='0';
    }
    printf("%s",quan);
    printf("zushu=%d\n",*z);
    printf("buwei=%d",*b);
    for(i=0; i<*z; i++)
    {
        calculate(quan+8*i,fp);
    }

    fclose(fp);




}
int calculate(char ban[],FILE *fp)
{
    int n;
    int i;
    char encode;

    n=0;
    for(i=0; i<8; i++)
    {
        ban[i]=ban[i]-48;
        n=n+ban[i]*pow(2,7-i);
    }
    encode=n;
    printf("\n");

    printf("%d",n);

    fwrite(&encode,1,1,fp);

    return 0;
}


void decode(int *z,int *b,char save[])
{

    unsigned char x[*z];
    int y[*z];
    char term[9]= {0};
    char er[9]= {0};

    FILE *fo;
    int i,j,k,l;

    i=j=k=l=0;


    fo = fopen("D:\\Encode.dat","rb"); //打开文件

    if(fo == NULL)
    {
        printf("can not open file");
        exit(0);
    }



    for(i=0; i<*z; i++)
    {
        fread(x+i,1,1,fo);//一个字节一个字节的读入文件里的数据，分别赋给a数组
        y[i]=x[i];//将字符数组里的数据转为整型
        printf("%d",y[i]);
        printf("\n");
    }

    for(j=0; j<i; j++) //对于b数组中的元素分别执行循环，循环的作用是得到数组元素对应的8位二进制编码
    {
        for(l=0; l<8; l++)
        {
            term[l]='0';
            er[l]='0';
        }
        for(k=0; y[j]; k++)
        {
            term[k]=y[j]%2+'0';
            y[j]=y[j]/2;

        }

        for(l=0; l<k; l++)
        {
            er[l+8-k]=term[k-1-l];

        }
        strcat(save,er);


    }
     save[8*(*z)-*b]='\0';

    printf("%s",save);
    fclose(fo);
}

