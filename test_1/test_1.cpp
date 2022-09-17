#include <stdio.h>
#include <string.h>

int main();
int input();
int output();
int loop();

int state = 1;
int salary = 0;
int duration = 0;
int topduration = 0;

double topsalary ;
double allsalary ;
double employeeamount ;

char isyes = 'y';
char employee[20];
char topemployee[20];

int main()
{
    loop();
    return 0;
}

int loop()
{
    do
    {
        printf("do you want to enter employee information(y/n): ");
        scanf(" %c", &isyes);
        switch (isyes)
        {
        case 'y':
            input();
            break;
        case 'n':
            output();
            return state = 0;
        }
    } while (state);
    return 0;
}

int input()
{
    printf("employeename: ");
    scanf("%s", &employee);

    printf("Salary (Bath/Month): ");
    scanf("%d", &salary);

    printf("Duration (Year): ");
    scanf("%d", &duration);

    while (salary >= topsalary)
    {
        strcpy(topemployee, employee);
        topsalary = (double)salary;
        topduration = duration;
        break;
    }

    allsalary = allsalary + (double)salary;
    state = 1;
    employeeamount = employeeamount + 1.0;

    return 0;
}

int output()
{
    printf("\n Aveage of Salary: %.2f Bath \n Payment of every month: %.2f Bath ", allsalary / employeeamount, allsalary);
    printf("\n ** Most duration in this business ** ");
    printf("\n Name: %s (%d years) \n Salary: %.2f Bath ", topemployee, topduration, topsalary);
    return 0;
}

