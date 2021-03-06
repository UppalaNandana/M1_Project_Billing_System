#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct items
{
    char item[20];
    float price;
    int quantity;
};
struct orders
{
    char customer[100];

    char date[50];
    int numOfItems;
    struct items itm[20];
};
void Bill(char date[100], char customer[100])
{
    printf("\t ***** RESTAURANT *****\n");
    printf("\nDate: %s", date);
    printf("\n Invoice to: %s", customer);
    printf("\n\n");
    printf("\t\t\t--------------------\n");
    printf("Item");
    printf("\t\t Quantity");
    printf("\t\t Price");
    printf("\n");
    printf("\t-------------------------------------------\n");
}
void BillBody(char item[50], int quantity, float price)
{ printf("\n");
    printf("%s", item);
    printf("\t\t%d", quantity);
    printf("\t\t%.2f", quantity * price);
    printf("\n");
}
void BillFooter(float total)
{
    printf("\n");
    float discount = 0.1 * total;
    float NetTotal = total - discount;
    float CGST = 0.09 * NetTotal;
    float GrandTotal = NetTotal + (2 * CGST);
    printf("\n");
    printf("\nSubTotal\t\t\t %.2f", total);
    printf("\nDiscount @10 \t\t\t %.2f", discount);
    printf("\n\t\t\t\t-----");
    printf("\n Net Total\t\t\t %.2f", NetTotal);
    printf("\n CGST @9\t\t\t %.2f", CGST);
    printf("\n SGST @9\t\t\t %.2f", CGST);
    printf("\n");
    printf("\nGrand Total\t\t\t%.2f", GrandTotal);
    printf("\n");
}
int main()
{
    int opt, n;

    struct orders ord;
    struct orders order;
    char BillSave = 'y', contFlag = 'y';
    char names[50];
    FILE *fp;
    while (contFlag == 'y')
    {
        float total = 0;
        int invoiceFound = 0;
        printf("\n\t\t\t ***** RESTAURANT ***** \n");
        printf("\nPlease Select Your Option:");
        printf("\n1.Invoice");
        printf("\n2.Show all Invoices");
        printf("\n3.Search Invoice");
        printf("\n4.Exit");
        printf("\nYou have choosen:");
        scanf("%d", &opt);
        fgetc(stdin);
        switch (opt)
        {
        case 1:
            system("clear");
            printf("\nPlease enter the name of the customer:");
            fgets(ord.customer, 100, stdin);
            strcpy(ord.date, __DATE__);
            printf("\nPlease enter the number of items:");
            scanf("%d", &n);
            if(typeof(n) != int)
            {
            printf("please enter numbers only");
            }
            else
            {
            ord.numOfItems = n;
            for (int i = 0; i < n; i++)
            {
                fgetc(stdin);
                printf("\n\n");
                printf("Please enter Item- %d:", i + 1);
                fgets(ord.itm[i].item, 10, stdin);
                printf("\nPlease enter the Quantity of Item:");
                scanf("%d", &ord.itm[i].quantity);
                printf("\nPrice of the Item %d:", i + 1);
                scanf("%f", &ord.itm[i].price);
                total += (ord.itm[i].quantity * ord.itm[i].price);
            }
            Bill(ord.date, ord.customer);
            for (int i = 0; i < ord.numOfItems; i++)
            {
                BillBody(ord.itm[i].item, ord.itm[i].quantity, ord.itm[i].price);
            }
            BillFooter(total);
            printf("Do you want to save the Bill[y/n]:");
            scanf("%c", &BillSave);
            if (BillSave == 'y')
            {
                fp = fopen("RestaurantBill.dat", "a+");
                fwrite(&ord, sizeof(struct orders), 1, fp);
                if (fwrite != 0)
                    printf("Successfully saved!!!");
                else
                    printf("Error saving");
                fclose(fp);
            }
          }
        }
            break;

        case 2:
            system("clear");
            fp = fopen("RestaurantBill.dat", "r");
            printf("\n *****Your Previous Invoices*****\n");
            while (fread(&order, sizeof(struct orders), 1, fp))
            {
               float tot=0;
                Bill(order.date, order.customer);
                for (int i = 0; i < order.numOfItems; i++)
                {
                    BillBody(order.itm[i].item, order.itm[i].quantity, order.itm[i].price);
                    tot += order.itm[i].quantity * order.itm[i].price;
                }
                BillFooter(tot);
            }
            fclose(fp);
            break;

        case 3:
            printf("\n Enter the name of the customer:");
            // fgetc(stdin);
            fgets(names, 40, stdin);
            system("clear");
            fp = fopen("RestaurantBill.dat", "r");
            printf("\n *****Your Previous Invoices*****");
            while (fread(&ord, sizeof(struct orders), 1, fp))
            {
                float tots = 0;
                if (!strcmp(ord.customer, names))
                {
                  
                Bill(ord.date, ord.customer);
                for (int i = 0; i < n; i++)
                {
                    BillBody(ord.itm[i].item, ord.itm[i].quantity, ord.itm[i].price);
                    tots += ord.itm[i].quantity * ord.itm[i].price;
                }
                BillFooter(tots);
                invoiceFound = 1;
            }
            }
            if (!invoiceFound)
            {
                printf("\nSorry the name of customer not found\n");
            }
            fclose(fp);
            break;
        case 4:
            printf("\n\t\t\t !!!!!!Bye Bye!!!!! \n\n");
            exit(0);
            break;

        default:
            printf("\nsorry invalid option");
            break;
        }
        printf("\nDo you want to continue Billing[y/n]:");
        scanf("%c", &contFlag);
    }
    return 0;
}
