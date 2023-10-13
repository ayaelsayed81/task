#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User *users = NULL;
int userCount = 0;

void registerUser() {
    printf("Enter username: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    users = realloc(users, (userCount + 1) * sizeof(User));
    if (users == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    printf("User registered successfully.\n");
}

int loginUser() {
    printf("Enter username: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful.\n");
            return 1;  // Return 1 to indicate successful login
        }
    }

    printf("Invalid username or password. Please try again.\n");
    return 0;  // Return 0 to indicate unsuccessful login
}

void cleanup() {
    free(users);
}

int main() {
    int choice;

    atexit(cleanup);

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    // Perform actions for a logged-in user
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}