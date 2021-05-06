#include <stdio.h>
#include <stdlib.h>

void dummyfunc() {}

void printUI()
{
    system("clear");
    printf("\n\n\t  *** Friend Recommendation System ***\n");
    printf("\n");
    printf("\t\t    List of commands\n");
    printf("\t=========================================\n");
    printf("\t  [1] Register new user\n");
    printf("\t  [2] Unregister existing user\n");
    printf("\t  [3] Recommend friends to existing user\n");
    printf("\t  [4] Add friend to existing user\n");
    printf("\t  [5] Check friendship status\n");
    printf("\t  [6] Change parameters of a user\n");
    printf("\t  [0] Exit\n");
    printf("\t=========================================\n");
    //acceptinput();
}

int acceptinput()
{
    printf("\nEnter choice: ");
    int inp;
    scanf("%d", &inp);
    switch (inp)
    {
    case 1:
        printf("Register new user\n");
        dummyfunc();
        break;
    case 2:
        printf("Unregister existing user\n");
        dummyfunc();
        break;
    case 3:
        printf("Recommend friends to existing user\n");
        dummyfunc();
        break;
    case 4:
        printf("Add friend\n");
        dummyfunc();
        break;
    case 5:
        printf("Check friendship status\n");
        dummyfunc();
        break;
    case 6:
        printf("Change parameters of a user\n");
        dummyfunc();
        break;
    case 0:
        printf("Exiting!\nThank you for using this service\n");
        dummyfunc();
        break;
    default:
        printf("Invalid Input! Please try again!\n");
        inp = acceptinput();
    }
    return inp;
}

int main()
{
    int inp = 1;
    printUI();
    while (inp != 0)
    {
        inp = acceptinput();
    }
    printf("\n");
    return 0;
}