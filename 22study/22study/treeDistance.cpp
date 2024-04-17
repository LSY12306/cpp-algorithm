#include<iostream>
using namespace std;

struct nodePath
{
	int length = 0;
	int* path = new int[length];
};
//先把每个值到根节点的路径输出出来
nodePath nodeToRoot(int* tree, int nodeData, int parentNodeCnt, nodePath path) {
	int i;
	//先找到这个元素的下标i
	for (i = 1; i < parentNodeCnt * 2 + 1; i++) {
		if (tree[i] == nodeData) {
			break;
		}
	}
	//因为父节点的个数已经知道了，所以设置动态数组最大就只用父节点个数加1即可。
	//int* path = new int[parentNodeCnt + 1];
	/*int path[10]{};*/
	//path[0] = nodeData;
	for (int j = 0; j < parentNodeCnt; j++) {
		//i/2是其父节点的位置
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
	cout << "请输入总输入组数" << endl;
	int groupCount;
	cin >> groupCount;
	cout << "请输入父节点个数和查询组数" << endl;
	int parentNodeCnt, queryCount;
	cin >> parentNodeCnt>> queryCount;
	int* tree = new int[(parentNodeCnt+1) * 2]; //tree是一个动态数组
	tree[1] = 1;
	for (int i = 2; i <= parentNodeCnt * 2; i++) {
		cin >> tree[i];
	}
	
	struct nodePath path;
	struct nodePath path2;
	//将7到根部的路径存储在数组path中
	nodeToRoot(tree, 7, 5,path);
	//将5到根部的路径存储在数组path2中
	nodeToRoot(tree, 5, 5, path2);
	int res = findSameEle(path, path2, parentNodeCnt);
	cout << res<< "___res___"<<endl;
	delete[] tree;
	return 0;
}

