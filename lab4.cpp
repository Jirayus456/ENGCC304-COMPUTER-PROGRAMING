#include <stdio.h>
int main(){
    char EmployeesID[10] ;
    int working ;
    int amount ;
    printf("Input the Employees ID : ") ;
    scanf("%s",&EmployeesID) ;
    printf("Input the working hrs : ") ;
    scanf("%d",&working) ;
    printf("Salary amount/hr (Bath) : ") ;
    scanf("%d",&amount) ;
    printf("....\n") ;
    printf("Expected Output : \n") ;
    printf("Employees ID = %s \nAmount/day = %.2f  Bath(s)",EmployeesID,(float)working * amount) ;
    return 0 ;
}
