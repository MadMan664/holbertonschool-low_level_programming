#include <stdio.h>

int main(void)

{
int choice, A, B, Result;

do
{
printf("Simple Calculator\n");
printf("1) Add\n");
printf("2) Subtract\n");
printf("3) Multiply\n");
printf("4) Divide\n");
printf("0) Quit\n");

printf("Choice: ");

scanf("%d",&choice);

if (choice < 0 || choice > 4)
{
	printf("Invalid choice\n");
}
if (choice == 0)
{

printf("Bye!\n");
}


if (choice == 1)
{
printf("A: ");
	
scanf("%d",&A);

printf("B: ");

scanf("%d",&B);

Result = A + B;
printf("Result: %d\n", Result);
}

if (choice == 2)
{
printf("A: ");

scanf("%d",&A);

printf("B: ");

scanf("%d",&B);

Result = A - B;
printf("Result: %d\n", Result);
}



}
while (choice != 0);
 

return (0);
	}

