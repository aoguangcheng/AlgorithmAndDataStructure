/*������һ�����⹫ʽ����ֵ��B������������ֵ��������ʽ��C��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#define MAX 50 
void panduan(int b[MAX],int f);//��ֵ����
int tkh (char S[MAX], char D[MAX], int B[MAX], int h0);//�ּ����㺯��
int fkh (char S[MAX], char D[MAX], int B[MAX], int h0);//�����㺯��

void panduan(int b[MAX],int f) // �����Ƹ�ֵ�� 
{
	int i;
	i=f;
	if(b[f]==0)
		b[f]=1;
	else
	{
		b[f]=0;
		panduan(b,--i);
	} 
}

int tkh (char S[MAX],char D[MAX],int B[MAX],int h0)//�ּ����㺯��
{
	int i,j,h,s,kh=0,wz[MAX],a; 
	char xs1[MAX],ckh[MAX]; 
	s=strlen(S);
	for(i=0;i<s;i++)
		if(S[i]=='(' || S[i]==')')
		{
			wz[kh]=i;
			ckh[kh]=S[i];
			kh++;
		}
		if(kh==0)
			return fkh(S,D,B,h0);
		else
		{
			for(i=0;i<kh;i++)
				if(ckh[i]==')')
					break;
				for(j=wz[i-1]+1,h=0;j<wz[i];j++,h++) 
					xs1[h]=S[j]; 
				xs1[h]='\0';
				a=fkh(xs1,D,B,h0);
				if(a==1)
					S[wz[i-1]]=1;
				else
					S[wz[i-1]]=-2;
				for(j=wz[i-1]+1;j<s+wz[i-1]-wz[i];j++)
					S[j]=S[j+wz[i]-wz[i-1]];
				S[j]='\0'; 
				return tkh(S,D,B,h0);
		}
}

int fkh(char S[MAX],char D[MAX],int B[MAX],int h0)//�����㺯��
{
	int i,h=0,j=0,j1=0,j2=0,j3=0,j4=0,j5=0,i1,i2,p1=-1,p2=-1,s;
	char dt[MAX];
	s=strlen(S);
	if(s==1)
		if(S[0]==-2)
			return 0;
		else
			return 1; 
		else
		{ 
			for(i=0;i<s-j;i++) //�ȴ����
				if(S[i]=='!')
				{ 
					for(i1=0;i1<h0;i1++)
						if(S[i+1]==D[i1])
							p1=B[i1];
						if(S[i+1]==-2)
							p1=0; 
						if(p1==-1)
							p1=S[i+1]; 
						dt[j+2]=!p1;
						S[i]=j+2;
						j++;
						p1=0;
						for(i1=i+1;i1<s-j;i1++)
							S[i1]=S[i1+1];
				}
				p1=-1; 
				j1=j; 
				for(i=0;i<s-j1-2*j2;i++) // ������
					if(S[i]=='&')
					{ 
						for(i1=0;i1<h0;i1++)
						{ 
							if(S[i-1]==D[i1])
								p1=B[i1];
							if(S[i+1]==D[i1])
								p2=B[i1];
						}
						for(i2=2;i2<j+2;i2++) 
						{
							if(S[i-1]==i2) 
								p1=dt[i2]; 
							if(S[i+1]==i2) 
								p2=dt[i2];
						}
						if(S[i-1]==-2)
							p1=0; 
						if(S[i+1]==-2)
							p2=0;
						if(p1==-1) 
							p1=(int)(S[i-1]);
						if(p2==-1)
							p2=(int)(S[i+1]); 
						dt[j+2]=p1 && p2;//������
						S[i-1]=j+2;
						j++;
						j2++;
						p1=-1;
						p2=-1; 
						for(i1=i;i1<s-j1-2*j2;i1++)
							S[i1]=S[i1+2];
						i=i-1;
					}
					for(i=0;i<s-j1-2*j2-2*j3;i++) // ����� 
						if(S[i]=='|')
						{
							for(i1=0;i1<h0;i1++)
							{ 
								if(S[i-1]==D[i1])
									p1=B[i1];
								if(S[i+1]==D[i1])
									p2=B[i1];
							}
							for(i2=2;i2<j+2;i2++) 
							{
								if(S[i-1]==i2) 
									p1=dt[i2];
								if(S[i+1]==i2)
									p2=dt[i2];
							}
							if(S[i-1]==-2)
								p1=0; 
							if(S[i+1]==-2)
								p2=0;
							if(p1==-1)
								p1=S[i-1];
							if(p2==-1)
								p2=S[i+1];
							dt[j+2]=p1 || p2;//������
							S[i-1]=j+2;
							j++;
							j3++;
							p1=-1;
							p2=-1; 
							for(i1=i;i1<s-j1-2*j2-2*j3;i1++)
								S[i1]=S[i1+2];
							i--; 
						}
						for(i=0;i<s-j1-2*j2-2*j3-2*j4;i++) // �����̺��� 
							if(S[i]=='^')
							{
								for(i1=0;i1<h0;i1++)
								{ 
									if(S[i-1]==D[i1])
										p1=B[i1];
									if(S[i+1]==D[i1])
										p2=B[i1];
								}
								for(i2=2;i2<j+2;i2++) 
								{
									if(S[i-1]==i2) 
										p1=dt[i2];
									if(S[i+1]==i2) 
										p2=dt[i2];
								}
								if(S[i-1]==-2)
									p1=0; 
								if(S[i+1]==-2)
									p2=0;
								if(p1==-1)
									p1=S[i-1];
								if(p2==-1)
									p2=S[i+1];
								dt[j+2]=!p1 || p2;
								S[i-1]=j+2;
								j++;
								j4++;
								p1=-1;
								p2=-1; 
								for(i1=i;i1<s-j1-2*j2-2*j3-2*j4;i1++)
									S[i1]=S[i1+2];
								i--; 
							}
							for(i=0;i<s-j1-2*j2-2*j3-2*j4-2*j5;i++)  
								if(S[i]=='~')
								{
									for(i1=0;i1<h0;i1++)
									{ 
										if(S[i-1]==D[i1])
											p1=B[i1];
										if(S[i+1]==D[i1])
											p2=B[i1];
									}
									for(i2=2;i2<j+2;i2++) 
									{
										if(S[i-1]==i2) 
											p1=dt[i2];
										if(S[i+1]==i2)
											p2=dt[i2];
									}
									if(S[i-1]==-2)
										p1=0; 
									if(S[i+1]==-2)
										p2=0;
									if(p1==-1)
										p1=S[i-1];
									if(p2==-1)
										p2=S[i+1];
									dt[j+2]=(!p1 || p2)&&(!p2 || p1);
									S[i-1]=j+2;
									j++;
									j5++;
									p1=-1;
									p2=-1; 
									for(i1=i;i1<s-j1-2*j2-2*j3-2*j4-2*j5;i1++)
										S[i1]=S[i1+2];
									i--; 
								}
								return dt[j+1];
    }
}

void display()//����
{
	printf("                                        \n");
	printf("           ! ��ʾ ��                 \n");
	printf("           & ��ʾ ��ȡ               \n");
	printf("           | ��ʾ ��ȡ               \n");
	printf("           ^ ��ʾ �̺�               \n");
	printf("           ~ ��ʾ �ȼ�               \n");
	printf("                                        \n");
}

int main()
{
	int i1,i2,d=1,B[MAX],kh=0,jg,j=0,h0;
	int bj=0,A[MAX],h=0,x=0,C[MAX];
	char S[MAX],D[MAX],S0[MAX],s;
	A[0]=-1;
	C[0]=-1;
	display();
	printf("������һ�����⹫ʽ:\n");
	gets(S);
	strcpy(S0,S);
	for(i1=0;i1<strlen(S);i1++)
	{
		if(S[i1]==')' || S[i1]=='(')
			kh++;
		if(S[i1]>='a' && S[i1]<='z' || S[i1]>='A' && S[i1]<='Z') 
		{
			for(i2=0;i2<j;i2++) 
				if(D[i2]==S[i1])
					d=0;
				if(d==1)
				{
					D[j]=S[i1];
					j++;
				}
				d=1; 
		}
	}
	h0=j; 
	printf("\n�����ֵ�����£�\n \n");
	for(i1=0;i1<h0;i1++)
		printf(" %c ",D[i1]); 
	printf(" ");
	puts(S);
	printf("\n"); 
	for(i1=0;i1<j;i1++) 
		B[i1]=0;
	for(i2=0;i2<j;i2++)
		printf(" %d ",B[i2]);
	jg=tkh(S,D,B,h0); 
	if(jg==0)
		A[h++]=bj;
	else 
		C[x++]=bj; 
	printf("    %d\n",jg);
	strcpy(S,S0); 
	for(i1=0;i1<(int)pow(2,j)-1;i1++)
	{
		++bj;
		panduan(B,j-1); 
		jg=tkh(S,D,B,h0); 
		if(jg==0)
			A[h++]=bj;
		else 
			C[x++]=bj; 
		strcpy(S,S0); 
		for(i2=0;i2<j;i2++)
			printf(" %d ",B[i2]);
		printf("    %d\n",jg);
	} 
	if(A[0]==-1)
		printf("\n�����⹫ʽ����������ȡ��ʽ��\n");
	else
	{ 
		printf("\n�����⹫ʽ������ȡ��ʽ��\n\t");
		for(i1=0;i1<h;i1++)
		{
			if (i1>0)
				printf("��");
			printf("M(%d)",A[i1]); 
		}
	}
	if(C[0]==-1)
		printf("\n�����⹫ʽ����������ȡ��ʽ��\n");
	else
	{
		printf("\n\n�����⹫ʽ������ȡ��ʽ��\n\t");
		for(i1=0;i1<x;i1++)
		{
			if (i1>0)
				printf("��");
			printf("m(%d)",C[i1]);
		}
	}
	printf("\n"); 	
}
