#ifndef _File_output_
#define _File_output_

#include  <iostream>
#include  <fstream>
#include<string>

/*------------------------------------------
����������        a=0 �����Ǽ�ÿ���ں����ۼ����  a=1 ����
                            b=0 �½�����matlab�ļ�  .m�ļ�     b=1 �½�����txt�ļ�  .txt�ļ�
Output_file1��   *p ָ�������ָ�� intial �����ٻ���ֵ����ָ�� size 
                            �������ش���̫�������ٻ���ֵ����Ϊdouble ����������1.0���
Output_file2��   size1�������뾫ȷ�����򲻶Իᴮ��
//------------------------------------------*/

using namespace std;
class Ofstream_me
{
public:
	Ofstream_me(string filename, int and_0,int mfile_0);//a 0�ļ�β׷�� ���������д   b 0 .m�ļ� ����.txt�ļ�
	~Ofstream_me();//��Ҫ����	


	void Output_file1(double *p, int size);	//*p ������ ����Ĵ�С
	void Output_file1(double *p, double inital, int size);//�����ٻ���ֵһ���� double   *p�����inital��������ļ���ֵ��Ϊ��ʵֵ
	void Output_file1(double *p, double *inital, int size);//*p�����inital���飬��Ӧ���

	void Output_file2(double *p, int size1, int size2);//size1 ��  size2 ��  ����Ҫ��ȷ�������״�λ *p��A[][]����A[]��ʾ 
	
	void Updater_file();//����ļ��������

	ofstream file;
private:

	void Open_file(int II);

	int size1_file, size2_file, control, control1;
	string file_name,name;
};
#endif