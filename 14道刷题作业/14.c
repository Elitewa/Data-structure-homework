1
void fun(struct xs *head)
{
	if(head==NULL||head->next==NULL)
	{
		return;
	}
	struct xs *pre,*cur,*next;
	pre=head->next;
	cur=pre->next;
	pre->next=NULL;
	while(cur!=NULL)
	{
		pre=head;
		next=cur->next;				//每次也只是遍历一个后半节点，类似于插入排序
		cur->next=NULL;		//先划分第一个元素为顺序序列，然后将后面的的逐个比较插入
		while(pre->next!=NULL&&pre->next->data<=cur->data) //在另一半链表(cur)中遇到小的就停止循环
		{
			pre=pre->next;
		}
		cur->next=pre->next;   //停止循环后将后一段插入到前一段合适的位置
		pre->next=cur;         
		cur=next;
	}
	return;
}
2
int fun(struct xs *head,int i,int *e)
{
	int x;
	struct xs *cur=head;
	struct xs *tem;
	for(x=1;x<i;x++)
	{
		cur=cur->next;
	}
	tem=cur->next;
	*e=tem->data;
	cur->next=tem->next;
	free(tem);
	return 1;	
}
3
void fun(struct xs *head,int e)
{
	struct xs *p,*pre;
	p=head->next;
	pre=head;
	while(p!=NULL)
	{
		if(p->data==e)
		{
			pre->next=p->next;
			free(p);
			p=pre->next;
		}
		else{
			pre=p;
			p=p->next;
		}
		
	}
}
4
struct xs *init()
{
	struct xs *head=(struct xs*)malloc(sizeof(struct xs));
	head->next=head;
	return head;	
}
5
void fun(struct xs *head,int n)
{
	struct xs *cur=head;
	for(int i=1;i<=n;i++)
	{
		struct xs *node;
		node=(struct xs*)malloc(sizeof(struct xs));
		node->data=i;
		cur->next=node;
		cur=node;
	}
	cur->next=head;
}
6
void fun(struct node *head)
{
	struct node *p,*pre;
	p=head->next;
	pre=head;
	while(p!=head)
	{
		if(p->data%2!=0)
		{
			pre->next=p->next;
			free(p);
			p=pre->next;
		}
		else{
			pre=p;
			p=p->next;
		}
	}
}
7
void init(struct xs **hd) {
    *hd = (struct xs *)malloc(sizeof(struct xs));
    (*hd)->next = NULL;
}
8
struct  xs  *init()
{
	struct xs *hd=(struct xs*)malloc(sizeof(struct xs))	;
	hd->next=NULL;
	return hd;
}
9
void create(struct  xs  *hd,int  a[],int  n)
{
	struct xs *tmp=hd;
	for(int i=0;i<n;i++)
	{
		struct xs *cur=(struct xs*)malloc(sizeof(struct xs));
		cur->cj=a[i];
		tmp->next=cur;
		tmp=cur;   //tep始终为最新节点的前一个
		tmp->next=NULL;
	}
}
10
int fun(struct  xs  *hd)
{
	int to=0;
	struct xs *cur=hd->next;
	while(cur!=NULL)
	{
		to+=cur->cj;
		cur=cur->next;
	}
	return to;	
}
11
int fun(struct  xs *head)
{
	int to=0;
	struct  xs *p;
	p=head->next;
	while(p!=NULL)
	{
		if(p->cj%2!=0)
		{
			to++;
		}
		p=p->next;
	}
	return to;
}
12
void create(struct xs *hd,int n)
{
	struct xs *p;
	int i;
	for(i=1;i<=n;i++)
	{
		p=(struct xs*)malloc(sizeof(struct xs));
		p->cj=i;
		p->next=hd->next;   //和尾插法区别就是，把旧的放新的前面(next),而尾插法是把新的放旧的前面
		hd->next=p;
	}
}
13
ListNode *create(int a[],int n)
{
	ListNode *p=NULL,*cur=NULL;
	int i=0;
	for(i;i<n;i++)
	{
		ListNode *newl=(ListNode*)malloc(sizeof(ListNode));
		newl->data=a[i];
		newl->next=NULL;
		if(p==NULL)
		{
			p=newl;
			cur=newl;
		}
		else
		{
			cur->next=newl;
			cur=newl;
		}
	}
	return p;
}
14
void print(ListNode* hd) 
{
    int d[10],i = 0;
    while (hd != NULL) 
    {
        d[i++] = hd->data;
        hd = hd->next;
    }
    for (--i; i>= 0;i--) 
    {
        printf("%d", d[i]); 
    }
   printf("\n");
}
