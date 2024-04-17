#include<iostream>
using namespace std;

struct nodePath
{
	int length = 0;
	int* path = new int[length];
};
//�Ȱ�ÿ��ֵ�����ڵ��·���������
nodePath nodeToRoot(int* tree, int nodeData, int parentNodeCnt, nodePath path) {
	int i;
	//���ҵ����Ԫ�ص��±�i
	for (i = 1; i < parentNodeCnt * 2 + 1; i++) {
		if (tree[i] == nodeData) {
			break;
		}
	}
	//��Ϊ���ڵ�ĸ����Ѿ�֪���ˣ��������ö�̬��������ֻ�ø��ڵ������1���ɡ�
	//int* path = new int[parentNodeCnt + 1];
	/*int path[10]{};*/
	//path[0] = nodeData;
	for (int j = 0; j < parentNodeCnt; j++) {
		//i/2���丸�ڵ��λ��
		if (i == 0) {
			break;
		}
		path.path[j] = tree[i];
		path.length++;
		i = i / 2;
	}
	return path;
}

int findSameEle(struct nodePath path1, struct nodePath path2,int parentNodeCnt) {
	int length1=0, length2=0;
	for (int i = 0; i < parentNodeCnt + 1; i++) {
		length1++;
		for (int j = 0; j < parentNodeCnt + 1; j++) {
			if (path1.path[i] != path2.path[j]) {
				if(j==0){ length2++; }
				
			}
			else {
				i = parentNodeCnt + 1;
				break;
			}
		}
    
	}
	return length1 + length2-1;
}
int main1() {
	cout << "����������������" << endl;
	int groupCount;
	cin >> groupCount;
	cout << "�����븸�ڵ�����Ͳ�ѯ����" << endl;
	int parentNodeCnt, queryCount;
	cin >> parentNodeCnt>> queryCount;
	int* tree = new int[(parentNodeCnt+1) * 2]; //tree��һ����̬����
	tree[1] = 1;
	for (int i = 2; i <= parentNodeCnt * 2; i++) {
		cin >> tree[i];
	}
	
	struct nodePath path;
	struct nodePath path2;
	//��7��������·���洢������path��
	nodeToRoot(tree, 7, 5,path);
	//��5��������·���洢������path2��
	nodeToRoot(tree, 5, 5, path2);
	int res = findSameEle(path, path2, parentNodeCnt);
	cout << res<< "___res___"<<endl;
	delete[] tree;
	return 0;
}

