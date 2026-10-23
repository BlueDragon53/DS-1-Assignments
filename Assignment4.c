#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Studentnode {
    int regNo;
    char name[50];
    struct Studentnode *next;
} Studentnode;

Studentnode *makeNode(Studentnode *head) {
    Studentnode *s = malloc(sizeof(Studentnode));

    printf("Registration number: ");
    scanf("%d", &s->regNo);

    printf("Name: ");
    scanf(" %s", &s->name);

    s->next = NULL;

    return s;
}

Studentnode *insertAt(Studentnode *head, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return head;
    }

    Studentnode *p = makeNode(head);

    if (pos == 1) {
        p->next = head;
        return p;
    }

    Studentnode *cur = head;

    for (int i = 1; cur != NULL && i < pos - 1; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Invalid position.\n");
        free(p);
        return head;
    }

    p->next = cur->next;
    cur->next = p;

    return head;
}

Studentnode *deleteAt(Studentnode *head, int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty list.\n");
        return head;
    }

    Studentnode *cur = head;
    Studentnode *prev = NULL;

    for (int i = 1; cur != NULL && i < pos; i++) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;

    free(cur);

    printf("Student removed.\n");
    return head;
}

void display(Studentnode *head) {
    Studentnode *s = head;
    int i = 0;

    if (s == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (s != NULL) {
        printf("RegNo: %d, Name: %s\n",
               s->regNo, s->name);

        s = s->next;
        i++;
    }

    printf("Total participants: %d\n", i);
}

int count(Studentnode *head) {
    int n = 0;
    Studentnode *p = head;

    while (p != NULL) {
        n++;
        p = p->next;
    }

    return n;
}

Studentnode *sortList(Studentnode *head) {
    Studentnode *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->regNo > j->regNo) {
                int r = i->regNo;
                i->regNo = j->regNo;
                j->regNo = r;

                char name[50];

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);
            }
        }
    }

    return head;
}

Studentnode *reverse(Studentnode *head) {
    Studentnode *prev = NULL;
    Studentnode *cur = head;
    Studentnode *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main(void) {
    Studentnode *head = NULL;
    int ch, pos;

    do {
        printf("\n1. Add student");
        printf("\n2. Delete student");
        printf("\n3. Display list");
        printf("\n4. Count students");
        printf("\n5. Sort list");
        printf("\n6. Reverse list");
        printf("\n0. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAt(head, pos);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteAt(head, pos);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Total students: %d\n", count(head));
                break;

            case 5:
                head = sortList(head);
                printf("List sorted.\n");
                break;

            case 6:
                head = reverse(head);
                printf("List reversed.\n");
                break;

            case 0:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (ch != 0);

    while (head != NULL) {
        Studentnode *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}