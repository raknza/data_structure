#include <stdio.h>
#include <stdlib.h>

typedef struct stu *student;
typedef struct stu{ // �`�I���c
    int score; // ���
    student next; // link
};

student makenode();
student newnode(student ,int );
student delectnode(student,int);
student invert(student);
void insert(student,int,int);

int main()
{
    student head,last,current;
    // �гy�쵲�]���`�I�^
    head = makenode();
    last = head;
    head->score = -1;
    int select,score,x;
    printf("�п�J���ϥΪ����O�G(1)�s�W�`�I (2)�R���`�I (3)���J�`�I (4)���� (5)�L�X (6)����\n");
    while(1){
        scanf("%d",&select);
        if(select == 1){
            printf("�п�Jscore:");
            scanf("%d",&score);
            last = newnode(last,score);
        }
        else if (select == 2){
            printf("�п�J��m(0���R��last):");
            scanf("%d",&x);
            last = delectnode(head,x);
        }
        else if(select == 3){
            printf("�п�J�����J����m��score:");
            scanf("%d %d",&x,&score);
            insert(head,x,score);
        }
        else if(select == 4){
            head = invert(head);
        }
        else if (select ==5){
            printf("�L�X:\n");
            current = head->next;
            while(current!=NULL){
                printf("%d ",current->score);
                current = current->next;
                if(current!=NULL)
                    printf("�� ");
            }
            printf("\n");
        }
        else if(select == 6)
            return 0;
        else
            printf("�L�ī��O�A�Э��s��J\n");

    }
    // �s�W�`�I
    current = newnode(current,70);

    return 0;
}


student makenode(){
    student temp;
    temp = malloc(sizeof(struct stu));
    temp->next = NULL;
    return temp;
}

student newnode(student last,int data){
    // �s�@�`�I
    student temp = makenode();
    temp->score = data;
    last-> next = temp;
    printf("�s�W����");
    printf("\n");
    return last -> next;
}

student delectnode(student first ,int x){
    student front,temp = first;
    if(first->next == NULL){
        printf("�w�g�L�`�I�i�R��\n");
        return first;
    }
    // �R������
    if(x==0){
        while(temp->next!=NULL){
            front = temp;
            temp = temp->next;
        }
        // �Ǧ^�s����
        front->next = NULL;
        free(temp);
        temp = NULL;
        printf("�w�R��\n");
        return front;
    }
    else{ // �R�����w��m
        int current = 0;
        while((current+1)!=x){
            first = first->next;
            if(first->next == NULL){
                printf("�W�X�쵲�d��\n");
                return first;
            }
            current++;
        }
        temp = first->next;
        first->next = temp->next;
        free(temp);
        temp = NULL;
        printf("�w�R��\n");
        // �Ǧ^�s����
        while(first->next!=NULL){
            front = first;
            first = first->next;
        }
        return front;
    }
}

void insert(student first,int x,int score){
    int start =0;
    student temp;
    while(start !=x){
        if(first->next == NULL){
            printf("�W�X�쵲�d��\n");
            return ;
        }
        first = first->next;
        start++;
    }
    temp = makenode();
    temp->score = score;
    temp->next = first->next;
    first ->next = temp;
    printf("���J����");
    printf("\n");
}

student invert(student first){
    student front=NULL,next,temp;
    temp = first;
    first = first->next;
    while(first!=NULL){
        next = first->next;
        first->next = front;
        front = first;
        first = next;
    }
    temp->next = front;
    printf("���൲��\n");
    return temp;
}

