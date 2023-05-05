int qcs(bitree t,int n,int cc)
{
	if(t!=NULL)
	{
		if(t->data==n)
			return cc;
		else
		{
			int c1=qcs(t->lchild,n,cc+1);
			int c2=qcs(t->rchild,n,cc+1);
			return c1>c2?c1:c2;
		}
	}
	else return 0;
}
