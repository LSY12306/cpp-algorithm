#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<string>  strVec = { };
	int n;
	cout << "��������Ѱ����󹫹�ǰ׺���ַ�������" << endl;
	cin >> n;
	cout << "�����������ַ���" << endl;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		strVec.push_back(str);
	}
	string baseStr = strVec[0];
	for (auto it = strVec.begin()+1;it != strVec.end();it++ ){
		while ((*it).find(baseStr) !=0) {
			if (!baseStr.empty()) {
				baseStr.resize(baseStr.size() - 1);
			}
		}
		if (baseStr.empty()) {
			cout << "" << endl;
			return 0;
		}
	}
	cout <<baseStr << endl;
	return 0;
}








