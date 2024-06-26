#include  "File_output.h"
#include  <iomanip>

using namespace std;

//a 0文件尾追加 其他清空再写   b 0 .m文件 其他.txt文件
Ofstream_me::Ofstream_me(string filename, int and_0, int mfile_0) 
{
	control = mfile_0;
	control1 = and_0;
	file_name = filename;
	name = filename+"_out";
	Open_file(1);
}

//打开文件
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

//写一个一维数组写完后换行
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
		//cout << *(p + i) << ' ' << *(inital+i) <<endl; //测试结果是否正确
	}
	file << endl;
	file.unsetf(ios::scientific);
}


//在文件中写一个二维数组
void Ofstream_me::Output_file2(double *p, int size1, int size2)//这里的行数必须正确否则错位 输入为数组的首个位置
{
	//这里size1表示行，size2表示列。
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
	//a=0,文件尾追加，a=\，清空再写
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