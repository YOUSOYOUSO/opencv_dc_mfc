#include "stdafx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include<vector>
#include <fstream>//fstream�����������࣬����ʵ��c++���ļ��Ĳ���
#include <iomanip>

extern CString file_address; //ѡ��򿪵��ļ���ַ
using namespace std;
using namespace cv;

int testBJC()
{
	Mat background;
	Mat temp;
	Mat result;
	int FrameCount = 0;

	const wchar_t* wstr = (LPCTSTR)file_address;     //һ������unicode��������仰����
	char str[20] = { 0 };
	wcstombs(str, wstr, wcslen(wstr));
	//����������˴�CString �� char* ��ת������file_address��ֵ����str

	VideoCapture capture(str);
	int size;
	if (!capture.isOpened())
	{
		cout << "��ȡ��Ƶ����" << endl;
		return -1;
	}
	else
	{

		int fps = (int)capture.get(CAP_PROP_FPS);
		long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);//��ȡ��Ƶ����֡��
		capture.read(background);
		resize(background, background, Size(300, 200));//resizeΪ300*200��ͼ��ԭ����720*480
		cvtColor(background, background, CV_RGB2GRAY);//תΪ�Ҷ�ͼ

		ofstream File;//ofstream��ʵ�����ļ�д����
		File.open("test.xls", ios::_Noreplace | fstream::trunc);//ios::_Noreplace ��һ���ļ�ʱ������ļ������ڣ��������ļ�
		vector<int>ivec(totalFrameNumber);//�ɱ�����ivec����СΪ��֡

		VideoWriter writer("QJ.avi", VideoWriter::fourcc('M', 'P', '4', '2'), fps, Size(300, 200), 0);

		while (capture.read(temp))
		{

			int PixelCount = 0;

			FrameCount++;
			resize(temp, temp, Size(300, 200));//resizeΪ300*200��ͼ��ԭ����720*480
			cvtColor(temp, temp, CV_RGB2GRAY);//תΪ�Ҷ�ͼ
			absdiff(background, temp, result);//�ͱ�������,���result
			addWeighted(background, 0.98, temp, 1 - 0.98, 0, background);

			//����ͼ�񣬶�ֵ������ֵΪ50
			for (int i = 0; i < result.rows; i++) {
				for (int j = 0; j < result.cols; j++) {
					if (result.at<uchar>(i, j) < 50) {
						result.at<uchar>(i, j) = 0;
					}
					else {
						PixelCount++;
						result.at<uchar>(i, j) = 255;
					}
				}
			}
			result.convertTo(result, CV_8U);
			writer << result;
			File << PixelCount << endl;	//д��excel
		}

		File.close();//�ͷ�
	}
	return 0;
}