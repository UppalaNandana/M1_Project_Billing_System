#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include"Billing.h"
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