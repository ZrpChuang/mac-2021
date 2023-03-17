Status read(stack*s,&T)//表示读取栈顶元素 
Status Pop(stack* s,&T)//表示出栈，返回其中的元素
Status Push(stack* s,T)//表示压栈，把元素T压入栈中
Status Visit(TNode);//表示访问某个节点，假设元素是否被visit能被记载
Status WithOutrecursion(BiTree* T);//没有递归算法的遍历二叉树
{
	Push(s1,*T);
	while(s1.top !=s1.base)//栈不为空
	{
		if(T.leftchild != NULL && T.leftchild未被访问 )
		{
			T = T->leftchild;
			Push(&s1,T);
			vist(T);
		}
		else if(T.reftchild != NULL && T.reftchild未被访问 )
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
