
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{

    struct node *left;

    struct node *right;

    int price;

    int ID;

    char name[100];

    char company_name[100];

    float camera_mp;

    char colour[100];

    int RAM;

    int batter_bp;

    int removable_bat;
};

int count = 0;

struct node *new_node(char mobile_name[100], int val, char company_name[100], float camera_mp, char colour[100], int ram, int battery, int removable_bat)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->price = val;

    strcpy(temp->name, mobile_name);
    strcpy(temp->company_name, company_name);
    strcpy(temp->colour, colour);

    temp->camera_mp = camera_mp;

    temp->RAM = ram;

    temp->batter_bp = battery;

    temp->removable_bat = removable_bat;

    temp->ID = count;

    temp->right = NULL;

    temp->left = NULL;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int lefth = height(root->left);
        int righth = height(root->right);

        if (lefth > righth)
        {
            return (lefth + 1);
        }
        else
        {
            return (righth + 1);
        }
    }
}
int balance_factor(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return (height(root->left) - height(root->right));
    }
}

struct node *right_rotate(struct node *root)
{
    struct node *p1 = root->left;
    struct node *t2 = p1->right;
    p1->right = root;
    root->left = t2;
    return p1;
}

struct node *left_rotate(struct node *root)
{
    struct node *y = root->right;
    struct node *T2 = y->left;
    y->left = root;
    root->right = T2;
    return y;
}

struct node *maximum_node(struct node *ptr)
{
    struct node *present = ptr;
    while (present->right != NULL)
    {
        present = present->right;
    }
    return present;
}

struct node *minimum_node(struct node *ptr)
{
    struct node *present = ptr;
    while (present->left != NULL)
    {
        present = present->left;
    }
    return present;
}

struct node *insert_name(struct node *root, char mobile_name[100], int val, char company_name[100], float camera_mp, char colour[100], int ram, int battery, int removable_bat)
{

    if (root == NULL)
    {
        return new_node(mobile_name, val, company_name, camera_mp, colour, ram, battery, removable_bat);
    }
    if (strcmp(root->name, mobile_name) > 0)
    {
        root->left = insert_name(root->left, mobile_name, val, company_name, camera_mp, colour, ram, battery, removable_bat);
    }
    if (strcmp(root->name, mobile_name) < 0)
    {
        root->right = insert_name(root->right, mobile_name, val, company_name, camera_mp, colour, ram, battery, removable_bat);
    }
    int balance_fac = balance_factor(root);

    if (balance_fac > 1 && strcmp(root->left->name, mobile_name) > 0)
    {
        return right_rotate(root);
    }
    if (balance_fac < -1 && strcmp(root->right->name, mobile_name) < 0)
    {
        return left_rotate(root);
    }
    if (balance_fac > 1 && strcmp(root->left->name, mobile_name) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance_fac < -1 && strcmp(root->right->name, mobile_name) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

struct node *delete_name(struct node *ptr, char name[100])
{
    if (ptr == NULL)
    {
        printf("Not Found");
        return NULL;
    }
    else if (strcmp(ptr->name, name) > 0)
    {

        ptr->left = delete_name(ptr->left, name);
    }
    else if (strcmp(ptr->name, name) < 0)
    {
        ptr->right = delete_name(ptr->right, name);
    }
    else
    {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            free(ptr);
            ptr = NULL;
        }
        else if (ptr->right == NULL)
        {
            struct node *temp;
            temp = ptr->left;
            free(ptr);
            return temp;
        }
        else if (ptr->left == NULL)
        {
            struct node *temp;
            temp = ptr->right;
            free(ptr);
            return temp;
        }
        else
        {

            if (ptr->left != NULL)
            {
                struct node *temp1 = maximum_node(ptr->left);
                ptr->price = temp1->price;
                ptr->ID = temp1->ID;
                strcpy(ptr->name, temp1->name);
                strcpy(ptr->company_name, temp1->company_name);
                strcpy(ptr->colour, temp1->colour);
                ptr->camera_mp = temp1->camera_mp;
                ptr->batter_bp = temp1->batter_bp;
                ptr->RAM = temp1->RAM;
                ptr->removable_bat = temp1->removable_bat;
                ptr->left = delete_name(ptr->left, temp1->name);
            }
            else if (ptr->right != NULL)
            {
                struct node *temp1 = minimum_node(ptr->right);
                ptr->price = temp1->price;
                ptr->ID = temp1->ID;
                strcpy(ptr->name, temp1->name);
                strcpy(ptr->company_name, temp1->company_name);
                strcpy(ptr->colour, temp1->colour);
                ptr->camera_mp = temp1->camera_mp;
                ptr->batter_bp = temp1->batter_bp;
                ptr->RAM = temp1->RAM;
                ptr->removable_bat = temp1->removable_bat;
                ptr->right = delete_name(ptr->right, temp1->name);
            }
        }
    }
    int bf = balance_factor(ptr);
    if (bf == 2 && balance_factor(ptr->left) >= 0)
    {
        return right_rotate(ptr);
    }
    else if (bf == 2 && balance_factor(ptr->left) == -1)
    {
        ptr->left = left_rotate(ptr->left);
        return right_rotate(ptr);
    }
    else if (bf == -2 && balance_factor(ptr->right) <= 0)
    {
        return left_rotate(ptr);
    }
    else if (bf == -2 && balance_factor(ptr->right) == 1)
    {
        ptr->right = right_rotate(ptr->right);
        return left_rotate(ptr);
    }
    return ptr;
}

struct node *search_name(struct node *root, char name[100])
{
    if (root == NULL)
    {
        return root;
    }
    if (strcmp(root->name, name) == 0)
    {
        return root;
    }
    if (strcmp(root->name, name) > 0)
    {
        return search_name(root->left, name);
    }

    if (strcmp(root->name, name) < 0)
    {
        return search_name(root->right, name);
    }
}

struct node *insert_node_price(struct node *root, char mobile_name[100], int val, char company_name[100], float camera_mp, char colour[100], int ram, int battery, int removable_bat)
{
    if (root == NULL)
    {
        return new_node(mobile_name, val, company_name, camera_mp, colour, ram, battery, removable_bat);
    }
    if (val < root->price)
    {
        root->left = insert_node_price(root->left, mobile_name, val, company_name, camera_mp, colour, ram, battery, removable_bat);
    }
    if (val > root->price)
    {
        root->right = insert_node_price(root->right, mobile_name, val, company_name, camera_mp, colour, ram, battery, removable_bat);
    }
    int balance_fac = balance_factor(root);
    if (balance_fac > 1 && val < root->left->price)
    {
        return right_rotate(root);
    }
    if (balance_fac < -1 && val > root->right->price)
    {
        return left_rotate(root);
    }
    if (balance_fac > 1 && val > root->left->price)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance_fac < -1 && val < root->right->price)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

struct node *delete_price(struct node *ptr, int val)
{

    if (ptr == NULL)
    {
        printf("Not Found");
        return NULL;
    }
    else if (val < ptr->price)
    {
        ptr->left = delete_price(ptr->left, val);
    }
    else if (val > ptr->price)
    {
        ptr->right = delete_price(ptr->right, val);
    }
    else
    {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            free(ptr);
            ptr = NULL;
        }
        else if (ptr->right == NULL)
        {
            struct node *temp;
            temp = ptr->left;
            free(ptr);
            return temp;
        }
        else if (ptr->left == NULL)
        {
            struct node *temp;
            temp = ptr->right;
            free(ptr);
            return temp;
        }
        else
        {

            if (ptr->left != NULL)
            {
                struct node *temp1 = maximum_node(ptr->left);
                ptr->price = temp1->price;
                ptr->ID = temp1->ID;
                strcpy(ptr->name, temp1->name);
                strcpy(ptr->company_name, temp1->company_name);
                strcpy(ptr->colour, temp1->colour);
                ptr->camera_mp = temp1->camera_mp;
                ptr->batter_bp = temp1->batter_bp;
                ptr->RAM = temp1->RAM;
                ptr->removable_bat = temp1->removable_bat;
                ptr->left = delete_price(ptr->left, temp1->price);
            }
            else if (ptr->right != NULL)
            {
                struct node *temp1 = minimum_node(ptr->right);
                ptr->price = temp1->price;
                ptr->ID = temp1->ID;
                strcpy(ptr->name, temp1->name);
                strcpy(ptr->company_name, temp1->company_name);
                strcpy(ptr->colour, temp1->colour);
                ptr->camera_mp = temp1->camera_mp;
                ptr->batter_bp = temp1->batter_bp;
                ptr->RAM = temp1->RAM;
                ptr->removable_bat = temp1->removable_bat;
                ptr->right = delete_price(ptr->right, temp1->price);
            }
        }
    }
    int bf = balance_factor(ptr);
    if (bf == 2 && balance_factor(ptr->left) >= 0)
    {
        return right_rotate(ptr);
    }
    else if (bf == 2 && balance_factor(ptr->left) == -1)
    {
        ptr->left = left_rotate(ptr->left);
        return right_rotate(ptr);
    }
    else if (bf == -2 && balance_factor(ptr->right) <= 0)
    {
        return left_rotate(ptr);
    }
    else if (bf == -2 && balance_factor(ptr->right) == 1)
    {
        ptr->right = right_rotate(ptr->right);
        return left_rotate(ptr);
    }
    return ptr;
}
struct node *search_price(struct node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->price == val)
    {

        return root;
    }
    if (root->price > val)
    {
        return search_price(root->left, val);
    }

    if (root->price < val)
    {
        return search_price(root->right, val);
    }
}

struct node *range_search(struct node *root, int n1, int n2)
{
    if (NULL == root)
    {
        return NULL;
    }

    if (n1 < root->price)
    {
        range_search(root->left, n1, n2);
    }

    if (n1 <= root->price && n2 >= root->price)
    {
        printf("ID: %d, %s, %d, %s,", root->ID, root->name, root->price, root->company_name);
        if (root->camera_mp == (int)root->camera_mp)
        {
            printf(" %d,", (int)root->camera_mp);
        }
        else
        {
            printf(" %0.1f,", root->camera_mp);
        }
        printf(" %s, %d, %d, %d\n", root->colour, root->RAM, root->batter_bp, root->removable_bat);
    }
    range_search(root->right, n1, n2);
}

int main()
{
    struct node *head_price = NULL;
    struct node *head_name = NULL;

    char input[100];

    while (1)
    {
        scanf("%[^\n]s ", input);
        getchar();

        char *op = strtok(input, " ");
        if (!strcmp(op, "A"))
        {
            char *mobile_name = strtok(NULL, ",");
            int price = atoi(strtok(NULL, ", "));
            char *company_name = strtok(NULL, ", ");
            float camera_mp = atof(strtok(NULL, ", "));
            char *colour = strtok(NULL, ", ");
            int ram = atoi(strtok(NULL, ", "));
            int battery_bp = atoi(strtok(NULL, ", "));
            int removable_batt = atoi(strtok(NULL, ""));
            // printf("%s\n%s\n%d\n%s\n%f\n%s\n%d\n%d\n%d\n", op, mobile_name, price, company_name, camera_mp, colour, ram, battery_bp, removable_batt);
            count += 1;
            head_price = insert_node_price(head_price, mobile_name, price, company_name, camera_mp, colour, ram, battery_bp, removable_batt);
            head_name = insert_name(head_name, mobile_name, price, company_name, camera_mp, colour, ram, battery_bp, removable_batt);
            printf("ID: %d\n", count);
        }
        if (!strcmp(op, "QP"))
        {
            int s_price = atoi(strtok(NULL, " "));
            struct node *query_p = search_price(head_price, s_price);
            if (query_p != NULL)
            {
                printf("ID: %d, %s, %d, %s,", query_p->ID, query_p->name, query_p->price, query_p->company_name);
                if (query_p->camera_mp == (int)query_p->camera_mp)
                {
                    printf(" %d,", (int)query_p->camera_mp);
                }
                else
                {
                    printf(" %0.1f,", query_p->camera_mp);
                }
                printf(" %s, %d, %d, %d\n", query_p->colour, query_p->RAM, query_p->batter_bp, query_p->removable_bat);
            }
            else
            {
                printf("Not Found\n");
            }
        }
        if (!strcmp(op, "QN"))
        {
            char *s_name = strtok(NULL, "");
            struct node *query_n = search_name(head_name, s_name);
            if (query_n != NULL)
            {
                printf("ID: %d, %s, %d, %s,", query_n->ID, query_n->name, query_n->price, query_n->company_name);
                if (query_n->camera_mp == (int)query_n->camera_mp)
                {
                    printf(" %d,", (int)query_n->camera_mp);
                }
                else
                {
                    printf(" %0.1f,", query_n->camera_mp);
                }
                printf(" %s, %d, %d, %d\n", query_n->colour, query_n->RAM, query_n->batter_bp, query_n->removable_bat);
            }
            else
            {
                printf("Not Found\n");
            }
        }
        if (!strcmp(op, "DP"))
        {
            int d_price = atoi(strtok(NULL, " "));
            struct node *query_p = search_price(head_price, d_price);
            if (query_p != NULL)
            {
                printf("Deleted ID: %d\n", query_p->ID);
                head_price = delete_price(head_price, d_price);
                head_name = delete_name(head_name, query_p->name);
            }
            else
            {
                printf("Not Found");
            }
        }
        if (!strcmp(op, "DN"))
        {
            char *d_name = (strtok(NULL, ""));
            struct node *query_n = search_name(head_name, d_name);
            if (query_n != NULL)
            {
                printf("Deleted ID: %d\n", query_n->ID);
                head_name = delete_name(head_name, d_name);
                head_price = delete_price(head_price, query_n->price);
            }
            else
            {
                printf("Not Found");
            }
        }
        if (!strcmp(op, "R"))
        {
            int start = atoi(strtok(NULL, " "));
            int end = atoi(strtok(NULL, ""));
            struct node *range = range_search(head_price, start, end);
        }
        if (!strcmp(op, "T"))
        {
            break;
        }
    }

    return 0;
}
