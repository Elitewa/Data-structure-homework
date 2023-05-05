#include "stdio.h"
#include "stdlib.h"
struct xs{
	int cj;
	struct xs *next;
};
void main()
{
	int i;
	struct xs *p,*head=(struct xs *)malloc(sizeof(struct xs));
	head->next=NULL;
	
	for(i=1;i<=10;i++){
		p=(struct xs *)malloc(sizeof(struct xs));
		p->cj=i;
		p->next=head->next;
		head->next=p;
	}
	p=head->next;
	while(p!=NULL)
	{
		printf("%d\n",p->cj);
		p=p->next;
	}
	p=head->next;
	while(p!=NULL){
		head->next=p->next;
		free(p);
		p=head->next;
	}
	free(head);
}
