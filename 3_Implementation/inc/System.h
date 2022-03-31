#ifndef __System_H__
#define __System_H__
void Bill(char date[100], char customer[100]);
void BillBody(char item[50], int quantity, float price);
void BillFooter(float total);
#endif