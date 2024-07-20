#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *rray(string array, int length) {
	int *NUM=new int[length];
	for (int i = 0; i < length; i++) {	
		NUM[i]=array[i] - '0';
	}
	return NUM;
}

int XOR(int length, string number)
{
	for (int i = 0; i < length; i++) {
		if (number[i] == '1'&&i!=length-1) { break; }//0000001 ���� �������� 1�� �ƴ� �߰��� 1��������� �������
		else if(number[length-1]=='1') {
			return 1;
		}
		return 0;
	}
	
	int *NUM=rray(number, length);
	
	int i = 0;
	while (NUM[i]==0 && i != length - 1) {
		i++;
	}
	
	int NumOneLength = length - i;
	int* NUM1=new int[NumOneLength];
	for (int k = 0; k < NumOneLength; k++)
	{
		NUM1[k] = NUM[i + k];//1�� �����ϴ� ���� �� �迭 �ϳ� ã��
	}
	int j = 0;
	while (NUM1[j] == 1&&j!=NumOneLength-1) {
		j++;
	}
	int NumOne1Length = NumOneLength - j;
	int* NUM1_1 = new int[NumOne1Length];
	for (int t = 0; t <NumOneLength-j; t++)//NUM1-1 �����
	{
		NUM1_1[t] = NUM1[j+t];
	}
	int max=-1;
	int y = 0;
	int* NUM2 = new int[NumOne1Length];
	int* NUMC = new int [NumOneLength];
	
	while (y < j) {
		for (int u = 0; u < NumOne1Length; u++) {
			NUM2[u] = NUM1[u+y];
		}
		//NUM1_1 ���� ��ŭ �ݺ��Ǵ� �ݺ���( NUM2�� ���� ����
		for (int u = 0; u < NumOne1Length; u++) {
			NUM2[u] = NUM2[u] ^ NUM1_1[u];
		}//������� NUM2�� NUM1_1�� ������
		int h = 0;
		while (h < j) {
			NUMC[h] = 1;
			h++;
		}
		for (int u = 0; u < NumOne1Length; u++) {
			NUMC[h + u] = NUM2[u];
		}
		string strNUM="";
		for (int i = 0; i < NumOneLength; i++) 
		{
			strNUM += to_string(NUMC[i]);
		}
		int result = stoi(strNUM);
		if (max < result) { max = result; }
		// MAX���� ���Ͽ� Ŭ��� MAX���� �ִ´�
		y++;
	}//j �� �ݺ��ϴ� �ݺ���
	delete[] NUM;
	delete[] NUM1;
	delete[] NUM1_1;
	delete[] NUM2;
	delete[] NUMC;
	return max;
}
int main()
{
	int a;
	int length;//����
	string number;//2����
	cin >> a;
	vector<int> result;
	for (int i = 0; i < a; i++)
	{
		cin >> length;
		cin >> number;
		result.push_back(XOR(length, number));
	}
	for (int i = 0; i < a; i++)
	{
		cout << result[i] << endl;
	}
	
}