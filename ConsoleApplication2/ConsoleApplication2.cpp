// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdint.h"
#include "ida.h"
#include <stdlib.h>
#include <string.h>
#include "gemtradeDecode.h"



int main(int argc, char *argv[])
{
	char* fileUrl = "C:\\Users\\Cirno\\Documents\\apkcreak\\baoshiyan\\base\\assets\\src\\app\\init.lua";
	//��ȡ�ļ�ָ��
	FILE *pFile = fopen(fileUrl, //���ļ�������
		"rb");
	char *pBuf;  //�����ļ�ָ��
	fseek(pFile, 0, SEEK_END); //��ָ���ƶ����ļ��Ľ�β ����ȡ�ļ�����
	int len = ftell(pFile); //��ȡ�ļ�����
	pBuf = new char[len + 1]; //�������鳤��
	rewind(pFile); //��ָ���ƶ����ļ���ͷ ��Ϊ����һ��ʼ��ָ���ƶ�����β��������ƶ����� �����
	fread(pBuf, 1, len, pFile); //���ļ�
	pBuf[len] = 0; //�Ѷ������ļ����һλ дΪ0 Ҫ��Ȼϵͳ��һֱѰ�ҵ�0��Ž���
	fclose(pFile); // �ر��ļ�
	size_t outSize = 0;
	char* decoded = decodeXOR(pBuf, len, &outSize);
	printf(decoded);

	char* outfile = new char[strlen(fileUrl) + 5];
	snprintf(outfile, strlen(fileUrl) + 5, "%s.dec", fileUrl);
	//��ȡ�ļ�ָ��
	/*FILE *pFileW = fopen(outfile, //���ļ�������
		"wb"); // �ļ��򿪷�ʽ ���ԭ��������Ҳ������
			  //���ļ�д����
	//
	fwrite(decoded, //Ҫ���������
		1,//����ÿһ��Ĵ�С ��Ϊ�������ַ��͵� ������Ϊ1 ����Ǻ��־�����Ϊ4
		outSize, //��Ԫ���� ����Ҳ����ֱ��д5
		pFileW //���Ǹոջ�õ��ĵ�ַ
	);


	//fclose(pFile); //����ϵͳ�����ļ�д�������ݸ��£���������ҪҪ���´򿪲�����д
	fflush(pFileW); //����ˢ�� ������������ */
	getchar();
	return 0;
}