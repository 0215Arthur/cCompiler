#ifndef _PRASER_H_
#define _PRASER_H_
#include "block.h"
#include "tree.h"
#include <vector>

extern struct gramTree* root;

using namespace std;

class Praser {
public:

	Praser();	//���캯��
	~Praser();	//��������

private:
	map<string, funcNode> funcPool;			//������
	vector<Block> blockStack;				//ά����ջ

	void praserInit();
	void praserGramTree(struct gramTree* node);

	struct gramTree* praser_declaration(struct gramTree* node);		//����praser_declaration�Ľڵ�
	void praser_init_declarator(string, struct gramTree* );	//����praser_init_declarator�Ľڵ�,���ظñ���

	bool lookupVar(string name);


	void error(int line, string error);

	void print_map();
};




#endif // !_PRASER_H_