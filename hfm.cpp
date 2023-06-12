#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
struct head {
	unsigned char b;	//记录字符在数组里面的位置
	long count;		//字符的权值
	long parent, lch, rch;	//定义哈夫曼树指针变量
	char bits[256];	//定义存储哈夫曼编码的数组
} header[512], tmp;
void quick_sort(int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    struct head pivot = header[left];
    while (i < j) {
        while (i < j && header[j].count <= pivot.count) j--;
        header[i] = header[j];
        while (i < j && header[i].count >= pivot.count) i++;
        header[j] = header[i];
    }
    header[i] = pivot;
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}
void quick_sort2(int left, int right) {
	int i = left, j = right;
	int pivot = strlen(header[(left + right) / 2].bits);
	struct head tmp;
	while (i <= j) {
	while (strlen(header[i].bits) < pivot) i++;
	while (strlen(header[j].bits) > pivot) j--;
	if (i <= j) {
	tmp = header[i];
	header[i] = header[j];
	header[j] = tmp;
	i++; j--;
	}
}
if (left < j) quick_sort2(left, j);
if (i < right) quick_sort2(i, right);
}
void compress() {
	char filename[255], outputfile[255], buf[512];
	unsigned char c;
	long i, j, m, n, f;
	long min1, pt1, flength;
	FILE *ifp, *ofp;
	printf(" 请您输入待压缩文件路径：");
	scanf("%s", filename);
	ifp = fopen(filename, "rb");
	if (ifp == NULL) {
		printf("\n 文件打开失败!\n\n");
		return;
	}
	printf(" 请您输入压缩后的文件名：");
	scanf("%s", outputfile);
	ofp = fopen(outputfile, "wb");
	if (ofp == NULL) {
		printf("\n 压缩文件失败!\n\n");
		return;
	}
	flength = 0;
	while (!feof(ifp)) {
		fread(&c, 1, 1, ifp);
		header[c].count++;    //字符重复出现频率+1
		flength++;            //字符出现原文件长度+1
	}
	flength--;
	header[c].count--;
	for (i = 0; i < 512; i++) {
		if (header[i].count != 0) 
			header[i].b = (unsigned char)i;
		//将每个哈夫曼码值及其对应的ASCII码存放在一维数组header[i]中，且编码表中的下标和ASCII码满足顺序存放关系
		else header[i].b = 0;
		header[i].parent = -1;
		header[i].lch = header[i].rch = -1; //结点初始化
	}
	quick_sort(0, 255);//快速排序
	for (i = 0; i < 256; i++) 
		if (header[i].count == 0) 
			break;
	n = i;     //外部叶子结点数为n个时，内部结点数为n-1，整个哈夫曼树的需要的结点数为2*n-1.
	m = 2 * n - 1;
	for (i = n; i < m; i++) { //构建哈夫曼树
		min1 = 999999999; //预设的最大权值，即结点出现的最大次数
		for (j = 0; j < i; j++) {
			if (header[j].parent != -1) continue;
			//parent!=-1说明该结点已存在哈夫曼树中，跳出循环重新选择新结点*/
			if (min1 > header[j].count) {
				pt1 = j;
				min1 = header[j].count;
				continue;
			}
		}
		header[i].count = header[pt1].count;
		header[pt1].parent = i; //依据parent域值（结点层数）确定树中结点之间的关系
		header[i].lch = pt1; //计算左分支权值大小
		min1 = 999999999;
		for (j = 0; j < i; j++) {
			if (header[j].parent != -1) continue;
			if (min1 > header[j].count) {
				pt1 = j;
				min1 = header[j].count;
				continue;
			}
		}
		header[i].count += header[pt1].count;
		header[i].rch = pt1; //计算右分支权值大小
		header[pt1].parent = i;
	}
	for (i = 0; i < n; i++) { //哈夫曼无重复前缀编码
		f = i;
		header[i].bits[0] = 0; //根结点编码0
		while (header[f].parent != -1) {
			j = f;
			f = header[f].parent;
			if (header[f].lch == j) { //置左分支编码0
				j = strlen(header[i].bits);
				memmove(header[i].bits + 1, header[i].bits, j + 1);
				//依次存储连接“0”“1”编码
				header[i].bits[0] = '0';
			} else { //置右分支编码1
				j = strlen(header[i].bits);
				memmove(header[i].bits + 1, header[i].bits, j + 1);
				header[i].bits[0] = '1';
			}
		}
	}
	fseek(ifp, 0, SEEK_SET); //从文件开始位置向前移动0字节，即定位到文件开始位置
	fwrite(&flength, sizeof(int), 1, ofp);
	fseek(ofp, 8, SEEK_SET);
	buf[0] = 0; //定义缓冲区,它的二进制表示
	f = 0;
	pt1 = 8;
	while (!feof(ifp)) {
		c = fgetc(ifp);
		f++;
		for (i = 0; i < n; i++) {
			if (c == header[i].b) break;
		}
		strcat(buf, header[i].bits);
		j = strlen(buf);
		c = 0;
		while (j >= 8) { //对哈夫曼编码位操作进行压缩存储
			for (i = 0; i < 8; i++) {
				if (buf[i] == '1') c = (c << 1) | 1;
				else c = c << 1;
			}
			fwrite(&c, 1, 1, ofp);
			pt1++;   //统计压缩后文件的长度
			strcpy(buf, buf + 8); //一个字节一个字节拼接
			j = strlen(buf);
		}
		if (f == flength) break;
	}
	if (j > 0) { //对哈夫曼编码位操作进行压缩存储
		strcat(buf, "00000000");
		for (i = 0; i < 8; i++) {
			if (buf[i] == '1') c = (c << 1) | 1;
			else c = c << 1;
		}
		fwrite(&c, 1, 1, ofp);
		pt1++;
	}
	fseek(ofp, 4, SEEK_SET);
	fwrite(&pt1, sizeof(long), 1, ofp);
	fseek(ofp, pt1, SEEK_SET);
	fwrite(&n, sizeof(long), 1, ofp);
	for (i = 0; i < n; i++) {
		fwrite(&(header[i].b), 1, 1, ofp);
		c = strlen(header[i].bits);
		fwrite(&c, 1, 1, ofp);
		j = strlen(header[i].bits);
		if (j % 8 != 0) { //若存储的位数不是8的倍数，则补0
			for (f = j % 8; f < 8; f++)
				strcat(header[i].bits, "0");
		}
		while (header[i].bits[0] != 0) {
			c = 0;
			for (j = 0; j < 8; j++) { //字符的有效存储不超过8位，则对有效位数左移实现两字符编码的连接
				if (header[i].bits[j] == '1') c = (c << 1) | 1; //|1不改变原位置上的“0”“1”值
				else c = c << 1;
			}
			strcpy(header[i].bits, header[i].bits + 8); //把字符的编码按原先存储顺序连接
			fwrite(&c, 1, 1, ofp);
		}
	}
	fclose(ifp);
	fclose(ofp);
	printf("\n 压缩文件成功!\n");
	return;
}
//解压
void uncompress() {
	char filename[255], outputfile[255], buf[255], bx[255];
	unsigned char c;
	long i, j, m, n, f, p, l;
	long flength;
	FILE *ifp, *ofp;
	printf(" 请您输入需要解压缩的文件路径：");
	scanf("%s",filename);
	ifp = fopen(filename, "rb");
	if (ifp == NULL) {
		printf("\n 文件打开失败!\n");
		return;
	}
	printf(" 请您输入解压缩后的文件名：");
	scanf("%s",outputfile);
	ofp = fopen(outputfile, "wb");
	if (ofp == NULL) {
		printf("\n 解压缩文件失败!\n");
		return;
	}
	fread(&flength, sizeof(long), 1, ifp); //读取原文件长度，对文件进行定位
	fread(&f, sizeof(long), 1, ifp);
	fseek(ifp, f, SEEK_SET);
	fread(&n, sizeof(long), 1, ifp);
	for (i = 0; i < n; i++) {
		fread(&header[i].b, 1, 1, ifp);
		fread(&c, 1, 1, ifp);
		p = (long)c; //读取原文件字符的权值
		header[i].count = p;
		header[i].bits[0] = 0;
		if (p % 8 > 0) m = p / 8 + 1;
		else m = p / 8;
		for (j = 0; j < m; j++) {
			fread(&c, 1, 1, ifp);
			f = c;
			itoa(f, buf, 2); //将f转换为二进制表示的字符串
			f = strlen(buf);
			for (l = 8; l > f; l--) {
				strcat(header[i].bits, "0");
			}
			strcat(header[i].bits, buf);
		}
		header[i].bits[p] = 0;
	}
	quick_sort2(0, n - 1);
	p = strlen(header[n - 1].bits);
	fseek(ifp, 8, SEEK_SET);
	m = 0;
	bx[0] = 0;
	while (1) { //通过哈夫曼编码的长短，依次解码，从原来的位存储还原到字节存储
		while (strlen(bx) < (unsigned int)p) {
			fread(&c, 1, 1, ifp);
			f = c;
			itoa(f, buf, 2);
			f = strlen(buf);
			for (l = 8; l > f; l--) { //在单字节内对相应位置补0
				strcat(bx, "0");
			}
			strcat(bx, buf);
		}
		for (i = 0; i < n; i++) {
			if (memcmp(header[i].bits, bx, header[i].count) == 0)break;
		}
		strcpy(bx, bx + header[i].count);   /*从压缩文件中的按位存储还原到按字节存储字符，
           字符位置不改变*/
		c = header[i].b;
		fwrite(&c, 1, 1, ofp);
		m++;   //统计解压缩后文件的长度
		if (m == flength) break; //flength是原文件长度
	}
	fclose(ifp);
	fclose(ofp);
	printf("\n 解压缩文件成功!\n");
	return;
}

int main() {
	int c;
	printf("****欢迎使用基于哈夫曼编码的解压缩程序****\n");
	printf("请选择功能:\n	|1.压缩|\n	|2.解压|\n	|0.退出|\n");
	scanf("%d",&c);
	while (c) {
		if (c == 1) 
		{
			compress(); 
		}	
		else if (c == 2) 
		{
			uncompress();
		}
		else
		{
			printf("选项不存在,请重新输入:");
			scanf("%d",&c);
		}
		printf("请继续选择操作:");
		scanf("%d",&c);
	}
	printf("\n欢迎下次使用！");
	return 0;
}
