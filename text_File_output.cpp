#include <stdio.h>
#include <math.h>
#include <ctime>
#include  "File_output.h"
//用于测试输出文件

void main()
{
	double A[5][5];
	Ofstream_me A_out("A_1",0,1);

	srand(time(0));//产生随机种子 0—NULL
	for (size_t i = 0; i <5 ; i++)
	for (size_t j = 0; j < 5; j++)
	{
		A[i][j] = rand() % 5;
	}
	A_out.Output_file("A", 1.1);
	A_out.file << "一维" << endl;
	A_out.Output_file1(A[1], 5);
	A_out.Output_file1(A[1], A[1], 5);
	A_out.Output_file1(A[1], 20.0, 5);
	A_out.file << "二维" << endl;
	A_out.Output_file2(A[0], 5, 5);
	A_out.Close();
	A_out.~Ofstream_me();
	//delete &A_out;
	system("pause");
}