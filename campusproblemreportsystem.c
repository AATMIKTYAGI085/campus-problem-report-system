#include <stdio.h>
#include <string.h>

#define MAX 100

struct Report
{
    int id;
    char studentName[50];
    char problem[100];
    char location[50];
    int priority;
    char status[20];
};

struct Report reports[MAX];
int count = 0;

/* Add a new problem report */
void addReport()
{
    if (count >= MAX)
    {
        printf("\nReport limit reached!\n");
        return;
    }

    reports[count].id = count + 1;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", reports[count].studentName);

    printf("Enter Problem: ");
    scanf(" %[^\n]", reports[count].problem);

    printf("Enter Location: ");
    scanf(" %[^\n]", reports[count].location);

    printf("\nSelect Priority:\n");
    printf("1. Low\n");
    printf("2. Medium\n");
    printf("3. High\n");
    printf("Enter priority: ");
    scanf("%d", &reports[count].priority);

    strcpy(reports[count].status, "Pending");

    printf("\n================================\n");
    printf("Report submitted successfully!\n");
    printf("Your Report ID is: %d\n", reports[count].id);
    printf("================================\n");

    count++;
}

/* Display all reports */
void displayReports()
{
    int i;

    if (count == 0)
    {
        printf("\nNo reports available.\n");
        return;
    }

    printf("\n========== ALL CAMPUS REPORTS ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nReport ID    : %d", reports[i].id);
        printf("\nStudent Name : %s", reports[i].studentName);
        printf("\nProblem      : %s", reports[i].problem);
        printf("\nLocation     : %s", reports[i].location);

        printf("\nPriority     : ");

        if (reports[i].priority == 1)
        {
            printf("Low");
        }
        else if (reports[i].priority == 2)
        {
            printf("Medium");
        }
        else
        {
            printf("High");
        }

        printf("\nStatus       : %s\n", reports[i].status);
        printf("----------------------------------------\n");
    }
}

/* Search report by ID */
void searchReport()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Report ID: ");
    scanf("%d", &id);

    i = 0;

    while (i < count)
    {
        if (reports[i].id == id)
        {
            printf("\n========== REPORT FOUND ==========\n");
            printf("Report ID : %d\n", reports[i].id);
            printf("Student   : %s\n", reports[i].studentName);
            printf("Problem   : %s\n", reports[i].problem);
            printf("Location  : %s\n", reports[i].location);
            printf("Status    : %s\n", reports[i].status);

            found = 1;
            break;
        }

        i++;
    }

    if (found == 0)
    {
        printf("\nReport not found!\n");
    }
}

/* Update report status */
void updateStatus()
{
    int id;
    int choice;
    int i;

    printf("\nEnter Report ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (reports[i].id == id)
        {
            printf("\nSelect New Status:\n");
            printf("1. Pending\n");
            printf("2. In Progress\n");
            printf("3. Resolved\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    strcpy(reports[i].status, "Pending");
                    break;

                case 2:
                    strcpy(reports[i].status, "In Progress");
                    break;

                case 3:
                    strcpy(reports[i].status, "Resolved");
                    break;

                default:
                    printf("\nInvalid choice!\n");
                    return;
            }

            printf("\nStatus updated successfully!\n");
            return;
        }
    }

    printf("\nReport ID not found!\n");
}

/* Main function */
int main()
{
    int choice;

    do
    {
        printf("\n\n========================================");
        printf("\n       CAMPUS PROBLEM REPORT SYSTEM");
        printf("\n========================================");

        printf("\n1. Report a Problem");
        printf("\n2. View All Reports");
        printf("\n3. Search Report");
        printf("\n4. Update Report Status");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addReport();
                break;

            case 2:
                displayReports();
                break;

            case 3:
                searchReport();
                break;

            case 4:
                updateStatus();
                break;

            case 5:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}