Status read(stack*s,&T)//��ʾ��ȡջ��Ԫ�� 
Status Pop(stack* s,&T)//��ʾ��ջ���������е�Ԫ��
Status Push(stack* s,T)//��ʾѹջ����Ԫ��Tѹ��ջ��
Status Visit(TNode);//��ʾ����ĳ���ڵ㣬����Ԫ���Ƿ�visit�ܱ�����
Status WithOutrecursion(BiTree* T);//û�еݹ��㷨�ı���������
{
	Push(s1,*T);
	while(s1.top !=s1.base)//ջ��Ϊ��
	{
		if(T.leftchild != NULL && T.leftchildδ������ )
		{
			T = T->leftchild;
			Push(&s1,T);
			vist(T);
		}
		else if(T.reftchild != NULL && T.reftchildδ������ )
		{
			T = T->reftchild;
			Push(&s1,T);
			vist(T);
		}
		else
		Pop(s1,T);
		read(s1,T);
	}
	

	return OK;
}
