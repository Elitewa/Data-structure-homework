#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 20
//注：第一次运行无需导入信息，直接插入题目即可，退出时请使用选项 7 保存信息，再次使用时先使用选项 8 导入上次信息
typedef struct Student {
    int id;
    int nums;
    char type[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    int score;
    struct Student* next;
} Student;
//添加题目
void add(Student** head_ptr) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    new_student->next = NULL;
    printf("请输入题目类型: ");
    scanf("%s", new_student->type);
    printf("请输入题目id: ");
    scanf("%d", &new_student->id);
    printf("请输入题目名称: ");
    scanf("%s", new_student->name);
    printf("请输入题目分值: ");
    scanf("%d", &new_student->score);
    printf("请输入题目解出人数: ");
    scanf("%d", &new_student->nums);
    if (*head_ptr == NULL) {
        *head_ptr = new_student;
    } else {
        Student* current = *head_ptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }

    printf("CTF题目添加成功.\n");
}
//排序
void sort(Student** head, int choice) {
    if (*head == NULL) {
        printf("链表为空\n");
        return;
    }

    switch (choice) {
        case 1: // 按照分值从小到大排序
            Student *current, *index;
            for (current = *head; current->next != NULL; current = current->next) {
                for (index = current->next; index != NULL; index = index->next) {
                    if (current->score > index->score) {
                        int temp_score = current->score;
                        current->score = index->score;
                        index->score = temp_score;

                        int temp_nums = current->nums;
                        current->nums = index->nums;
                        index->nums = temp_nums;

                        int temp_id = current->id;
                        current->id = index->id;
                        index->id = temp_id;

                        char temp_type[MAX_NAME_LEN];
                        strcpy(temp_type, current->type);
                        strcpy(current->type, index->type);
                        strcpy(index->type, temp_type);

                        char temp_name[MAX_NAME_LEN];
                        strcpy(temp_name, current->name);
                        strcpy(current->name, index->name);
                        strcpy(index->name, temp_name);
                    }
                }
            }
            printf("按照分值排序完成.\n");
            break;
        case 2: // 按照解出人数从小到大排序
			Student *curren1, *index1;
            for (curren1 = *head; curren1->next != NULL; curren1 = curren1->next) {
                for (index1 = curren1->next; index1 != NULL; index1 = index1->next) {
                    if (curren1->nums > index1->nums) {
                        int temp_nums = curren1->nums;
                        curren1->nums = index1->nums;
                        index1->nums = temp_nums;

                        int temp_score = curren1->score;
                        curren1->score = index1->score;
                        index1->score = temp_score;

                        int temp_id = curren1->id;
                        curren1->id = index1->id;
                        index1->id = temp_id;

                        char temp_type[MAX_NAME_LEN];
                        strcpy(temp_type, curren1->type);
                        strcpy(curren1->type, index1->type);
                        strcpy(index1->type, temp_type);

                        char temp_name[MAX_NAME_LEN];
                        strcpy(temp_name, curren1->name);
                        strcpy(curren1->name, index1->name);
                        strcpy(index1->name, temp_name);
                    }
                }
            }
            printf("按照解出人数排序完成.\n");
            break;
        default:
            printf("无效的选项\n");
    }
}

//删除题目
void delete_student(Student** head_ptr, int id) {
    if (*head_ptr == NULL) {
        printf("题目未找到.\n");
        return;
    }

    if ((*head_ptr)->id == id) {
        // The head is the student to delete
        Student* temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        free(temp);
        printf("已成功删除题目\n");
        return;
    }

    // Traverse the list to find the student to delete
    Student* prev = *head_ptr;
    Student* current = (*head_ptr)->next;
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("题目未找到\n");
        return;
    }

    // Delete the student
    prev->next = current->next;
    free(current);
    printf("已成功删除题目\n");
}

void modify_student(Student* head) {
    int id, choice,new_nums,new_score;

    printf("【输入要修改题目ID】: ");
    scanf("%d", &id);

    // Find the student to modify
    Student* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("题目未找到\n");
        return;
    }

    // Modify the student's details
    printf("1. 名称\n");
    printf("2. 分值\n");
    printf("3. 方向\n");
    printf("4. 解出人数\n");
    printf("【请输入要修改的选项】:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("【新的名称】: ");
            scanf("%s", current->name);
            break;
        case 2:
            printf("【新的分值】: ");
            scanf("%d", &new_score);
            current->score = new_score;
            break;
        case 3:
            printf("【新的方向】: ");
            scanf("%s", current->type);
            break;
        case 4:
            printf("【新的解数】: ");
            scanf("%d", &new_nums);
            current->nums = new_nums;
            break;        
        default:
            printf("**选项无效**\n");
            return;
    }

    printf("\n题目修改成功\n");
}
//查找
int find(Student* head, int id) {
    // Traverse the list to find the student
    Student* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    } else {
    	printf("您查找的题目信息为：\n");
        printf("\n类型[%s],名称[%s],分值[%d],解出人数[%d]\n", current->type, current->name, current->score,current->nums);
        return 1;
    }
}
//输出
void display(Student* head) {
    if (head == NULL) {
        printf("No students to display.\n");
    } else {
    	printf("|----------|----|----------|----------|----------|\n");
        printf("|%-10s|%-4s|%-10s|%-10s|%-10s|\n", "方向", "ID", "名称", "分数", "解出人数");
        printf("|----------|----|----------|----------|----------|\n");

        // Traverse the list and print each student
        Student* current = head;
        while (current != NULL) {
            printf("|[%-8s]|%4d|%-10s|%-10d|%-10d|\n", current->type,current->id, current->name, current->score,current->nums);
            current = current->next;
        }
        printf("|----------|----|----------|----------|----------|\n");
    }
}
void save_link(Student* head) {
    FILE* fp;
    fp = fopen("ctf.txt", "w");
    if (fp == NULL) {
        printf("File open error!\n");
        exit(1);
    }

    Student* p = head;
    while (p != NULL) {
        fwrite(p, sizeof(*p), 1, fp);
        p = p->next;
    }

    fclose(fp);
    printf("CTF题目已成功保存到文件中。\n");
}

void load_link(Student** head) {
    FILE* fp;
    fp = fopen("ctf.txt", "rb");
    if (fp == NULL) {
        printf("File open error!\n");
        exit(1);
    }

    Student temp;
    while (fread(&temp, sizeof(temp), 1, fp) != 0) {
        Student* new_node = (Student*)malloc(sizeof(Student));
        if (new_node == NULL) {
            printf("Memory allocation error!\n");
            exit(1);
        }

        memcpy(new_node, &temp, sizeof(temp));
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
        } else {
            Student* p = *head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = new_node;
        }
    }

    fclose(fp);
    printf("CTF题目已从文件中加载。\n");
}

int main() {
    Student* head = NULL;
    int choice, id,cho;

    while (1) {
    	printf("\n		******欢迎使用CTF题目管理系统******\n");
    	printf("                  	（●＾o＾●）");
    	printf("\n			***选项如下***\n");
        printf("\n			|【1】添加题目|\n");
        printf("			|【2】删除题目|\n");
        printf("			|【3】修改题目|\n");
        printf("			|【4】查找题目|\n");
        printf("			|【5】题目排序|\n");
        printf("			|【6】遍历题目|\n");
        printf("			|【7】保存信息|\n");
        printf("			|【8】读取信息|\n");
        printf("			|【9】退出程序|\n");
        printf("【请输入选项】: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(&head);
                break;
            case 2:
                printf("请输入题目id: ");
                scanf("%d", &id);
                delete_student(&head, id);
                break;
            case 3:
                modify_student(head);
                break;
            case 4:
                printf("请输入题目id: ");
                scanf("%d", &id);
                if (find(head, id)) {
                    printf("\n*****查找成功*****\n");
                } else {
                    printf("\n题目不存在哦\n");
                }
                break;
            case 6:
                display(head);
                break;
            case 5:
                printf("请输入排序方式：\n1：分值\n2：解出人数\n");
                scanf("%d",&cho);
                sort(&head,cho);
                break;
            case 7:
            	save_link(head);
            	break;
            case 8:
            	load_link(&head); 
				break;           
            case 9:
                printf("欢迎访问作者博客:https://blog.byzhb.top\n");
                return 0;
            default:
                printf("选项不存在请重新输入！\n");
        }
    }
}
