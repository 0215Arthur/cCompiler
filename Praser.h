#ifndef _PRASER_H_
#define _PRASER_H_
#include "block.h"
#include "tree.h"
#include "innerCode.h"
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
	InnerCode innerCode;

	void praserInit();
	void praserGramTree(struct gramTree* node);

	struct gramTree* praser_declaration(struct gramTree* node);		//����praser_declaration�Ľڵ�
	void praser_init_declarator(string, struct gramTree* );			//����praser_init_declarator�Ľڵ�,���ظñ���

	varNode praser_assignment_expression(struct gramTree*);			//��ֵ���ʽ
	varNode praser_logical_or_expression(struct gramTree*);			//�߼�����ʽ
	varNode praser_logical_and_expression(struct gramTree*);			//�߼�����ʽ
	varNode praser_inclusive_or_expression(struct gramTree*);
	varNode praser_exclusive_or_expression(struct gramTree*);
	varNode praser_and_expression(struct gramTree*);
	varNode praser_equality_expression(struct gramTree*);
	varNode praser_relational_expression(struct gramTree*);
	varNode praser_shift_expression(struct gramTree*);
	varNode praser_additive_expression(struct gramTree*);
	varNode praser_multiplicative_expression(struct gramTree*);
	varNode praser_unary_expression(struct gramTree*);
	varNode praser_postfix_expression(struct gramTree*);
	varNode praser_primary_expression(struct gramTree*);


	string lookupVar(string name);			//���ر������ͣ��Ҳ�������""
	bool lookupCurruntVar(string name);		//���ҵ�ǰ���var
	struct varNode lookupNode(string name);	//���ؿ�

	struct varNode createTempVar(string name, string type);


	void error(int line, string error);

	void print_map();
	void print_code();
};




#endif // !_PRASER_H_