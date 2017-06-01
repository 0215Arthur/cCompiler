#ifndef _BLOCK_H_
#define _BLOCK_H_

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "tree.h"
using namespace std;



//�����ڵ�
struct varNode {
	string name;
	string type;
	int num = -1;
};

//�����ڵ�
struct funcNode {
	bool isdefinied = false;
	string name;				//������
	string rtype;				//������������
	vector<varNode> paralist;	//��¼�β��б�
};

//����ڵ�


//block������
class Block {
public:
	funcNode func;	//����Ǻ�������¼������
	bool isfunc = false;//��¼�Ƿ��Ǻ���
	map<string, struct varNode> varMap;	//������map

};

#endif // !_BLOCK_H_
