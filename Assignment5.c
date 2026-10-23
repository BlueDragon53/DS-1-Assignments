#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

void create_poly(struct node *head);
void display_poly(struct node *head);
void add_poly(struct node *head1, struct node *head2, struct node *head3);
void free_poly(struct node *head);

int main(void)
{
    struct node *head1;
    struct node *head2;
    struct node *head3;
    int ch;

    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));

    if (head1 == NULL || head2 == NULL || head3 == NULL)
    {
        printf("Memory allocation failed\n");
        free(head1);
        free(head2);
        free(head3);
        return 1;
    }

    head1->next = head1;
    head2->next = head2;
    head3->next = head3;

    do
    {
        printf("\n");
        printf(" POLYNOMIAL OPERATIONS USING CIRCULAR LINKED LIST \n");
        printf("1. Create first polynomial\n");
        printf("2. Create second polynomial\n");
        printf("3. Display first polynomial\n");
        printf("4. Display second polynomial\n");
        printf("5. Add two polynomials\n");
        printf("0. Exit\n");
        printf("Choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                free_poly(head1);
                create_poly(head1);
                break;

            case 2:
                free_poly(head2);
                create_poly(head2);
                break;

            case 3:
                display_poly(head1);
                break;

            case 4:
                display_poly(head2);
                break;

            case 5:
                free_poly(head3);
                add_poly(head1, head2, head3);
                printf("Resultant polynomial: ");
                display_poly(head3);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 0);

    free_poly(head1);
    free_poly(head2);
    free_poly(head3);

    free(head1);
    free(head2);
    free(head3);

    return 0;
}

void create_poly(struct node *head)
{
    struct node *ptr;
    struct node *temp;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of terms\n");
        return;
    }

    temp = head;

    for (i = 0; i < n; i++)
    {
        ptr = (struct node *)malloc(sizeof(struct node));

        if (ptr == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter coefficient: ");
        scanf("%d", &ptr->coeff);

        printf("Enter exponent: ");
        scanf("%d", &ptr->exp);

        ptr->next = head;
        temp->next = ptr;
        temp = ptr;
    }

    printf("Polynomial created successfully\n");
}

void display_poly(struct node *head)
{
    struct node *temp;
    int first = 1;
    int coeff;

    temp = head->next;

    if (temp == head)
    {
        printf("Polynomial is empty\n");
        return;
    }

    while (temp != head)
    {
        coeff = temp->coeff;

        if (coeff != 0)
        {
            if (!first)
            {
                if (coeff > 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            else if (coeff < 0)
            {
                printf("-");
            }

            if (coeff < 0)
                coeff = -coeff;

            if (temp->exp == 0)
            {
                printf("%d", coeff);
            }
            else if (temp->exp == 1)
            {
                if (coeff != 1)
                    printf("%d", coeff);
                printf("x");
            }
            else
            {
                if (coeff != 1)
                    printf("%d", coeff);
                printf("x^%d", temp->exp);
            }

            first = 0;
        }

        temp = temp->next;
    }

    if (first)
        printf("0");

    printf("\n");
}

void add_poly(struct node *head1, struct node *head2,
              struct node *head3)
{
    struct node *p;
    struct node *q;
    struct node *ptr;
    struct node *temp;
    int coeff;

    p = head1->next;
    q = head2->next;
    temp = head3;

    while (p != head1 && q != head2)
    {
        if (p->exp == q->exp)
        {
            coeff = p->coeff + q->coeff;

            if (coeff != 0)
            {
                ptr = (struct node *)malloc(sizeof(struct node));

                if (ptr == NULL)
                {
                    printf("Memory allocation failed\n");
                    return;
                }

                ptr->coeff = coeff;
                ptr->exp = p->exp;
                ptr->next = head3;

                temp->next = ptr;
                temp = ptr;
            }

            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            ptr = (struct node *)malloc(sizeof(struct node));

            if (ptr == NULL)
            {
                printf("Memory allocation failed\n");
                return;
            }

            ptr->coeff = p->coeff;
            ptr->exp = p->exp;
            ptr->next = head3;

            temp->next = ptr;
            temp = ptr;

            p = p->next;
        }
        else
        {
            ptr = (struct node *)malloc(sizeof(struct node));

            if (ptr == NULL)
            {
                printf("Memory allocation failed\n");
                return;
            }

            ptr->coeff = q->coeff;
            ptr->exp = q->exp;
            ptr->next = head3;

            temp->next = ptr;
            temp = ptr;

            q = q->next;
        }
    }

    while (p != head1)
    {
        ptr = (struct node *)malloc(sizeof(struct node));

        if (ptr == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        ptr->coeff = p->coeff;
        ptr->exp = p->exp;
        ptr->next = head3;

        temp->next = ptr;
        temp = ptr;

        p = p->next;
    }

    while (q != head2)
    {
        ptr = (struct node *)malloc(sizeof(struct node));

        if (ptr == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        ptr->coeff = q->coeff;
        ptr->exp = q->exp;
        ptr->next = head3;

        temp->next = ptr;
        temp = ptr;

        q = q->next;
    }

    printf("Polynomials added successfully\n");
}

void free_poly(struct node *head)
{
    struct node *temp;
    struct node *next;

    temp = head->next;

    while (temp != head)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    head->next = head;
}
