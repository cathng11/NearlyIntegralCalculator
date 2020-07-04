#include <iostream>
#define MAX 100
using namespace std;

//Xu ly da thuc

float f(float x,int Bac, float *HS)
{
	float s=0;
	float t=1;
	for (int i=Bac;i>=0;i--)
	{
		s=s+(*(HS+i))*t;
		t=t*x;
	}
	return s;
}

//Cong thuc Hinh thang

float Hinhthang(int n, float a, float b,int Bac,float Heso[])
{	
	if (n<=0) throw string("Sai");
	else
	{
	float h, j = 0;
	h = (float) (b - a) / n;
	j = (f(a,Bac,Heso) + f(b,Bac,Heso)) / 2;
	for (int i = 1; i <= n - 1; i++) j += f(a + i * h,Bac,Heso);
    return h * j;
	}
}

//Cong thuc Parabol

float Parabol(int n1, float a, float b,int Bac,float *Heso)
{
	if (n1<=0) throw "Sai roi";
	else
	{
	float h, j;
	j=0;
	h =(float) (b - a) / (2 * n1);
	j = f(a,Bac,Heso) + f(b,Bac,Heso);
	for (int i=1;i<=2*n1-1;i++)
		{
			if(i % 2) j += 4 * f(a + i * h,Bac,Heso);
			else j += 2 * f(a + i * h,Bac,Heso);
		};
	return (h/3)*j;
	}
}

//Cong thuc newton-cotet

float Newton(float A[][MAX],int n2,float a,float b,int Bac,float *Heso)
{	
	if (n2<=0 || n2>6) throw 55;
	else
	{
	float h;
	h=(float) (b-a)/n2;
	float s=0;
	for(int i=0;i<=n2-1;i++)
	{	
		if(i==n2-1)
			{
				for(int j=0;j<=i+1;j++)
					s+=(b-a)*f(a+j*h,Bac,Heso)*A[i][j];
			}
	}
	return s;
	}
}

void Read(FILE *f,float A[][MAX],int &n2)
{
	if(f!=NULL)
	{
	for(int i=0;i<=n2-1;i++)
		{
			for(int j=0;j<=i+1;j++)
			fscanf(f,"%f",&A[i][j]);
		};
	}
}

//Nhap da thuc

void Input(float* HS, int Bac)
{	
	cout<<endl<<"Moi nhap he so cua da thuc: ";
	for (int i = 0; i <= Bac ; i++)
		cin >> *(HS + i);

}

void Output(float* HS, int Bac)
{	
	cout<<"He so :";
	for (int i = 0; i <= Bac; i++)
		cout << *(HS + i) << "  ";
}


//Xuat menu
void menu()
{
	int i;
	for (i = 0; i < 50; i++) cout << "=";
	cout << endl << "|   Tinh gan dung tich phan xac dinh             |";
	cout << endl << "|   1: Dung cong thuc hinh thang                 |";
	cout << endl << "|   2: Dung cong thuc parabol                    |";
	cout << endl << "|   3: Dung cong thuc newton-cotet               |";
	cout << endl << "|   4: Bang tong hop cac cach tinh tren          |";
	cout << endl << "|   5: Thoat                                     |" << endl;
	for (i = 0; i < 50; i++) cout << "=";
	cout<<endl<<"\n";
}

//Giao dien

void GD(float *Heso,int Bac,float a,float b)
{
	menu();
	cout<<endl<<"Bac   :"<<Bac<<endl;
	Output(Heso,Bac);
	cout<<endl<<"a= "<<a<<"  "<<"b= "<<b<<endl;
}

int main()
{	
	menu();
	float A[MAX][MAX],x;			              
	int Bac;
	int n=0,n1=0,n2=0;
	int chucnang;
	char tiep;
	float a,b;
	
	do
	{
		cout<<"Moi nhap bac cua da thuc  : Bac = ";
		cin>>Bac;
		while (Bac<=0)
		{
			cout<<endl<<"Sai cu phap!"<<endl;
			cout<<endl<<"Moi nhap bac cua da thuc  : Bac = ";
			cin>>Bac;
		}
		float* Heso=new float[Bac];
		Input(Heso,Bac);
	
		cout<<endl;
		cout<<"Moi nhap can duoi         : a = ";
		cin >> a;
		cout<<endl;
		cout<<"Moi nhap can tren         : b = ";
		cin >> b;
		cout<<endl;

		do
		{
			cout << "Moi nhap lua chon         : ";
			cin >> chucnang;
			switch (chucnang)
			{
				case 1:
				{
				float result;
				bool success;	
				do
				{
					success=true;
					cout<<endl<<"Moi nhap so doan chia     : n = ";
    				cin>>n;
    				try
    					{
    					result=Hinhthang(n,a,b,Bac,Heso);
						}
					catch	(string)
						{
						success=false;
						cout<<endl<<"Sai cu phap!"<<endl;
						};
				}while(success==false);
				
					system("cls");
    				GD(Heso,Bac,a,b);
    				cout<<endl;
    				cout<<"======================="<<endl;
					cout<<"|Cong thuc |Ket qua    "<<endl;
    				cout<<"======================="<<endl;
    				cout<<"|Hinh thang|"<<Hinhthang(n,a,b,Bac,Heso)<<endl;
					cout<<"======================="<<endl;
					cout<<endl;
					break;
				};


				case 2:
				{
					
				float result;
				bool success;	
				do
				{
					success=true;
					cout<<endl<<"Moi nhap so doan chia     : n = ";
    				cin>>n1;
    				try
    					{
    					result=Parabol(n1,a,b,Bac,Heso);
						}
					catch	(char const *x)
						{	
						success=false;
						cout<<endl<<"Sai cu phap!"<<endl;
						};
				}while(success==false);
				
					system("cls");
    				GD(Heso,Bac,a,b);
    				cout<<endl;
    				cout<<"====================="<<endl;
					cout<<"|Cong thuc |Ket qua"<<endl;
    				cout<<"====================="<<endl;
    				cout<<"|Parabol   |"<<Parabol(n1,a,b,Bac,Heso)<<endl;
					cout<<"====================="<<endl;
					cout<<endl;
					break;
				};

				case 3:
				{
				float result;
				bool success;	
				do
				{
					success=true;
					cout<<endl<<"Moi nhap so doan chia     : n = ";
    				cin>>n2;
    				try
    					{
    					result=Newton(A,n2,a,b,Bac,Heso);
						}
					catch	(int)
						{	
						success=false;
						cout<<endl<<"Sai cu phap!"<<endl;
						};
				}while(success==false);
				
					FILE *f;
					f=fopen("nPi.txt","r+");
					Read(f,A,n2);
					system("cls");
    				GD(Heso,Bac,a,b);
    				cout<<endl;
    				cout<<"========================="<<endl;
					cout<<"|Cong thuc     |Ket qua "<<endl;
    				cout<<"========================="<<endl;
    				cout<<"|Newton-Cotet  |"<<Newton(A,n2,a,b,Bac,Heso)<<endl;
					cout<<"========================="<<endl;
					cout<<endl;
					break;
				};

				case 4:
				{	
				do
				{				
    				if(n<=0) 
						{
					    cout<<endl<<"Moi nhap so doan chia CT Hinh thang : n = ";
						cin>>n;
						}
					if(n1<=0)
						{
					    cout<<endl<<"Moi nhap so doan chia CT Parabol    : n = ";
						cin>>n1;
						} 
					if(n2<=0||n2>6)
						{
					    cout<<endl<<"Moi nhap so doan chia CT Newton     : n = ";
						cin>>n2;
						FILE *f;
						f=fopen("nPi.txt","r+");
						Read(f,A,n2);
						}
				} while(n<=0||n1<=0||n2<=0||n2>6);
	 
					system("cls");
					GD(Heso,Bac,a,b);
					cout<<endl;
					cout <<"========================="<<endl;
					cout <<"|    Bang tong hop      |"<<endl;
					cout <<"========================="<<endl;
					cout <<"|Cong thuc     |Ket qua  "<<endl;
					cout <<"-------------------------"<<endl;
					cout <<"|Hinh Thang    |"<<Hinhthang(n,a,b,Bac,Heso)<<endl;
					cout <<"|Parabol       |"<<Parabol(n1,a,b,Bac,Heso)<<endl;
					cout <<"|Newton-Cotet  |"<<Newton(A,n2,a,b,Bac,Heso)<<endl;
					cout <<"========================="<<endl;
					cout <<endl;
					break;
		
				};
		
				case 5:
				{
					break;
				};
				
				default:
				{
					cout << endl << "Sai cu phap. Moi nhap lai! "<<endl;
					cout<<endl;
					break;
				};

		};
		
	} while (chucnang != 5);
	
	cout<<endl<<"Tiep tuc? (t/k)           : ";
	cin>>tiep;
	if(tiep=='k') exit(0);
	n=0,n1=0,n2=0;
	system("cls");
	menu();
	}while(tiep=='t' && tiep!='k');
	
	system("pause");
	return 0;
}
