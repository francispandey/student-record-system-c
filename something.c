#include <stdio.h>
#include <string.h>

struct something {
    int age;
    char name[50];
    char grade[10];
};

int main() {
    int n;
    char mode[5];
    FILE *fp;
    struct something s[100];

    while (1) {
        printf("\n===== File Operations Menu =====\n");
        printf("w - Write new records\n");
        printf("a - Append records\n");
        printf("r - Read records\n");
        printf("d - Delete a record\n");
        printf("e - Exit\n");
        printf("================================\n");

        printf("Enter mode (w/r/a/d/e): ");
        scanf("%s", mode);

        // EXIT
        if (strcmp(mode, "e") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        // WRITE
        else if (strcmp(mode, "w") == 0) {
            printf("Enter number of entries: ");
            scanf("%d", &n);

            fp = fopen("text.txt", "w");

            for (int i = 0; i < n; i++) {
                printf("\n--- Entry %d ---\n", i + 1);

                printf("Enter name: ");
                scanf("%s", s[i].name);

                printf("Enter grade: ");
                scanf("%s", s[i].grade);

                printf("Enter age: ");
                scanf("%d", &s[i].age);

                fprintf(fp, "%s %s %d\n", s[i].name, s[i].grade, s[i].age);
            }

            fclose(fp);
            printf("\nRecords written successfully!\n");
        }

        // APPEND
        else if (strcmp(mode, "a") == 0) {
            printf("Enter number of entries: ");
            scanf("%d", &n);

            fp = fopen("text.txt", "a");

            for (int i = 0; i < n; i++) {
                printf("\n--- Entry %d ---\n", i + 1);

                printf("Enter name: ");
                scanf("%s", s[i].name);

                printf("Enter grade: ");
                scanf("%s", s[i].grade);

                printf("Enter age: ");
                scanf("%d", &s[i].age);

                fprintf(fp, "%s %s %d\n", s[i].name, s[i].grade, s[i].age);
            }

            fclose(fp);
            printf("\nRecords appended successfully!\n");
        }

        // READ
        else if (strcmp(mode, "r") == 0) {
            char name[50], grade[10];
            int age;
            int count = 0;

            fp = fopen("text.txt", "r");

            printf("\n===== File Data =====\n");
            printf("Name                 Grade      Age\n");
            printf("=========================================\n");

            while (fscanf(fp, "%s %s %d", name, grade, &age) == 3) {
                printf("%s\t%s\t%d\n", name, grade, age);
                count++;
            }

            printf("=========================================\n");
            printf("Total records: %d\n", count);

            fclose(fp);
        }

        // DELETE
        else if (strcmp(mode, "d") == 0) {
            FILE *temp;
            char targetName[50];
            char name[50], grade[10];
            int age;

            printf("Enter name to delete: ");
            scanf("%s", targetName);

            fp = fopen("text.txt", "r");
            temp = fopen("temp.txt", "w");

            if (fp == NULL) {
                printf("Error: Could not open file\n");
                continue;
            }

            int found = 0;

            while (fscanf(fp, "%s %s %d", name, grade, &age) == 3) {
                if (strcmp(name, targetName) != 0) {
                    fprintf(temp, "%s %s %d\n", name, grade, age);
                } else {
                    found = 1;
                }
            }

            fclose(fp);
            fclose(temp);

            remove("text.txt");
            rename("temp.txt", "text.txt");

            if (found) {
                printf("%s deleted successfully!\n", targetName);
            } else {
                printf("%s not found!\n", targetName);
            }
        }

        else {
            printf("Invalid mode\n");
        }
    }

    return 0;
}