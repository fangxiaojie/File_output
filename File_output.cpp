#include  "File_output.h"
#include  <iomanip>

using namespace std;

//a 0�ļ�β׷�� ���������д   b 0 .m�ļ� ����.txt�ļ�
Ofstream_me::Ofstream_me(string filename, int and_0, int mfile_0) 
{
	control = mfile_0;
	control1 = and_0;
	file_name = filename;
	name = filename+"_out";
	Open_file(1);
}

//���ļ�
void Ofstream_me::Open_file(int II)
{
	if (II == 1)
	{
		if (control == 0)
			file_name = file_name + ".m";
		else
			file_name = file_name + ".txt";
	}

	if (control1 == 0)
		file.open(file_name.c_str(), ios::app | ios::out);
	else
		file.open(file_name.c_str(), ios::ate | ios::out);

	if (!file.is_open())
	{
		cout << "\nerror on open " << file_name << " file!" << endl;
		getchar();
	}

	if (control == 0)
		file << name << "= [";
}

//дһ��һά����д�����
void Ofstream_me::Output_file1(double *p, int size)
{
	size1_file = size;
	file.setf(ios::scientific);
	for (int i = 0; i < size1_file; i++)
	{
		file << *(p + i) << ' ';//<<"\n"
	}
	file << endl;
	file.unsetf(ios::scientific);
}
void Ofstream_me::Output_file1(double *p,double inital,int size)
{
	size1_file = size;
	file.setf(ios::scientific);
	for (int i = 0; i < size1_file; i++)
	{
		file << (*(p + i))*inital<<' ';//<<"\n"
	}
	file << endl;
	file.unsetf(ios::scientific);
}
void Ofstream_me::Output_file1(double *p, double *inital, int size)
{
	size1_file = size;
	file.setf(ios::scientific);
	for (int i = 0; i < size1_file; i++)
	{
		file << (*(p + i))*(*(inital+i)) << ' ';
		//cout << *(p + i) << ' ' << *(inital+i) <<endl; //���Խ���Ƿ���ȷ
	}
	file << endl;
	file.unsetf(ios::scientific);
}


//���ļ���дһ����ά����
void Ofstream_me::Output_file2(double *p, int size1, int size2)//���������������ȷ�����λ ����Ϊ������׸�λ��
{
	//����size1��ʾ�У�size2��ʾ�С�
	size1_file = size1;
	size2_file = size2;
	file.setf(ios::scientific);
	for (int j = 0; j < size1_file; j++)
	{
		for (int i = 0; i < size2_file; i++)
		{
			file << *(p + i + j*size2) << ' ';
		}
		file << endl;
	}
	file.unsetf(ios::scientific);
}


void Ofstream_me::Updater_file()
{
	//a=0,�ļ�β׷�ӣ�a=\�������д
	int Y_N;
	file.close();
	Y_N=remove(file_name.c_str());
	if (Y_N == 1)
	{
		cout << "\n error deletion " << file_name << " file!" << endl;
		getchar();
	}
	Open_file(2);
}

Ofstream_me::~Ofstream_me()
{
	if (control == 0)
	{
		file << "];";
	}
	file.close();
	file.clear();
	cout << "close " << file_name<<endl;
}