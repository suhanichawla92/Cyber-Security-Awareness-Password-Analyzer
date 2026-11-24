
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* ================= CONSOLE COLORS ================= */

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

/* ================= CONSTANTS ================= */

#define USER_FILE "users.txt"
#define LOG_FILE "security_log.txt"

#define MAX_USERNAME 50
#define MAX_PASSWORD 100
#define MAX_MESSAGE 500

/* ================= STRUCTURE ================= */

typedef struct
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

} User;

/* ================= FUNCTION DECLARATIONS ================= */

void printLine(void);
void printWelcome(void);
void printTitle(char title[]);
void readLine(char message[], char input[], int size);
void pauseScreen(void);
void waitBrief(void);

void registerUser(void);
int login(void);
int usernameExists(char username[]);

void displayMenu(void);
void logoutMenu(void);

int getPasswordScore(char password[]);
void passwordSuggestions(char password[]);
void passwordAnalyzer(void);

void generatePassword(void);
void phishingChecker(void);
void cyberSecurityTips(void);

void saveLog(char activity[]);
void showLog(void);

/* ================= BASIC CLI FUNCTIONS ================= */

/* Displays a colored line */
void printLine(void)
{
    printf(BLUE);
    printf("============================================================\n");
    printf(RESET);
}

/* Main welcome screen */
void printWelcome(void)
{
    printf("\n");

    printLine();

    printf(CYAN BOLD);
    printf("                    CYBER CAFE\n");
    printf(RESET);

    printf(MAGENTA);
    printf("          CYBER SECURITY AWARENESS SYSTEM\n");
    printf(RESET);

    printLine();

    printf(GREEN);
    printf("          Your Digital Safety Starts Here!\n");
    printf(RESET);

    printf("\n");
}

/* Displays feature headings */
void printTitle(char title[])
{
    printf("\n");

    printLine();

    printf(CYAN BOLD "             %s\n" RESET, title);

    printLine();
}

/* Reads input safely using fgets */
void readLine(char message[], char input[], int size)
{
    int ch;

    printf("%s", message);

    if (fgets(input, size, stdin) != NULL)
    {
        if (strchr(input, '\n') == NULL)
        {
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                /* Clear extra input */
            }
        }

        input[strcspn(input, "\n")] = '\0';
    }
    else
    {
        input[0] = '\0';
    }
}

/* Pauses the program */
void pauseScreen(void)
{
    char temp[10];

    printf("\n");
    printf(YELLOW "Press ENTER to continue..." RESET);

    fgets(temp, sizeof(temp), stdin);
}

/* Creates a short delay for the scanning animation */
void waitBrief(void)
{
    clock_t start;

    start = clock();

    while ((clock() - start) < (CLOCKS_PER_SEC / 2))
    {
        /* Wait for half a second */
    }
}

/* ================= FILE HANDLING ================= */

/* Saves application activities */
void saveLog(char activity[])
{
    FILE *file;
    time_t currentTime;

    file = fopen(LOG_FILE, "a");

    if (file == NULL)
    {
        return;
    }

    currentTime = time(NULL);

    fprintf(file, "%s | %s",
            activity, ctime(&currentTime));

    fclose(file);
}

/* Displays saved activities */
void showLog(void)
{
    FILE *file;
    char line[200];

    printTitle("SECURITY ACTIVITY HISTORY");

    file = fopen(LOG_FILE, "r");

    if (file == NULL)
    {
        printf(YELLOW "No activity history found.\n" RESET);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf(WHITE "%s" RESET, line);
    }

    fclose(file);
}

/* Checks whether a username already exists */
int usernameExists(char username[])
{
    FILE *file;
    User temp;

    file = fopen(USER_FILE, "r");

    if (file == NULL)
    {
        return 0;
    }

    while (fscanf(file, "%49s %99s",
                  temp.username,
                  temp.password) == 2)
    {
        if (strcmp(temp.username, username) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    return 0;
}

/* ================= PASSWORD SECURITY ================= */

/* Calculates password strength */
int getPasswordScore(char password[])
{
    int i;
    int score;
    int upper;
    int lower;
    int digit;
    int special;
    int length;

    score = 0;
    upper = 0;
    lower = 0;
    digit = 0;
    special = 0;

    length = strlen(password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper((unsigned char)password[i]))
        {
            upper = 1;
        }
        else if (islower((unsigned char)password[i]))
        {
            lower = 1;
        }
        else if (isdigit((unsigned char)password[i]))
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }
    }

    if (length >= 8)
        score++;

    if (length >= 12)
        score++;

    if (upper)
        score++;

    if (lower)
        score++;

    if (digit)
        score++;

    if (special)
        score++;

    return score;
}

/* Displays suggestions for improving passwords */
void passwordSuggestions(char password[])
{
    int i;
    int length;
    int upper;
    int lower;
    int digit;
    int special;
    int score;

    length = strlen(password);

    upper = 0;
    lower = 0;
    digit = 0;
    special = 0;

    score = getPasswordScore(password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper((unsigned char)password[i]))
            upper = 1;

        else if (islower((unsigned char)password[i]))
            lower = 1;

        else if (isdigit((unsigned char)password[i]))
            digit = 1;

        else
            special = 1;
    }

    printf("\n");

    printLine();

    printf(CYAN BOLD "              PASSWORD SECURITY CHECK\n" RESET);

    printLine();

    printf("Password strength: ");

    if (score <= 2)
    {
        printf(RED BOLD "WEAK\n" RESET);
    }
    else if (score <= 4)
    {
        printf(YELLOW BOLD "MEDIUM\n" RESET);
    }
    else
    {
        printf(GREEN BOLD "STRONG\n" RESET);
    }

    if (score < 6)
    {
        printf("\n");
        printf(YELLOW "Suggestions to improve your password:\n" RESET);

        if (length < 8)
            printf(RED "  [!] Use at least 8 characters.\n" RESET);

        if (length < 12)
            printf(YELLOW "  [!] Try using 12 or more characters.\n" RESET);

        if (!upper)
            printf(RED "  [!] Add uppercase letters (A-Z).\n" RESET);

        if (!lower)
            printf(RED "  [!] Add lowercase letters (a-z).\n" RESET);

        if (!digit)
            printf(RED "  [!] Add numbers (0-9).\n" RESET);

        if (!special)
            printf(RED "  [!] Add special characters (@, #, !).\n" RESET);

        printf("\n");
        printf(CYAN "Tip: Avoid using your name or birthday.\n" RESET);
    }
    else
    {
        printf(GREEN "\nGreat! Your password meets all basic checks.\n" RESET);
    }
}

/* ================= REGISTRATION ================= */

void registerUser(void)
{
    User newUser;
    FILE *file;
    char answer;
    int score;

    printTitle("CREATE YOUR ACCOUNT");

    printf("Create your username and password below.\n");

    printf(CYAN "\nUsername tip: Use at least 4 characters.\n" RESET);

    readLine("\nEnter username: ",
             newUser.username, MAX_USERNAME);

    readLine("Enter password: ",
             newUser.password, MAX_PASSWORD);

    if (strlen(newUser.username) == 0 ||
        strlen(newUser.password) == 0)
    {
        printf(RED "\nUsername and password cannot be empty.\n" RESET);
        return;
    }

    if (strpbrk(newUser.username, " \t") != NULL ||
        strpbrk(newUser.password, " \t") != NULL)
    {
        printf(RED "\nSpaces are not allowed in username or password.\n" RESET);
        return;
    }

    if (strlen(newUser.username) < 4)
    {
        printf(YELLOW "\nSuggestion: Use a username with at least 4 characters.\n" RESET);
    }

    if (usernameExists(newUser.username))
    {
        printf(RED "\nThis username already exists. Try another one.\n" RESET);
        return;
    }

    /* Check password before creating account */

    passwordSuggestions(newUser.password);

    score = getPasswordScore(newUser.password);

    if (score <= 4)
    {
        printf("\n");
        printf(YELLOW "Your password could be stronger.\n" RESET);

        printf("Would you like to enter a stronger password? (Y/N): ");

        answer = getchar();

        while (getchar() != '\n')
        {
            /* Clear input */
        }

        if (answer == 'Y' || answer == 'y')
        {
            readLine("\nEnter new password: ",
                     newUser.password, MAX_PASSWORD);

            if (strlen(newUser.password) == 0 ||
                strpbrk(newUser.password, " \t") != NULL)
            {
                printf(RED "\nInvalid password. Please register again.\n" RESET);
                return;
            }

            passwordSuggestions(newUser.password);
        }
        else
        {
            printf(YELLOW "\nYou can continue, but a stronger password is recommended.\n" RESET);
        }
    }

    file = fopen(USER_FILE, "a");

    if (file == NULL)
    {
        printf(RED "\nUnable to save account.\n" RESET);
        return;
    }

    fprintf(file, "%s %s\n",
            newUser.username,
            newUser.password);

    fclose(file);

    printf(GREEN BOLD "\nAccount created successfully!\n" RESET);

    printf(CYAN "You can now log in using your account.\n" RESET);

    saveLog("A new account was registered.");
}

/* ================= LOGIN SYSTEM ================= */

int login(void)
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char input[20];

    User temp;

    FILE *file;

    int attempts;
    int found;
    int accountChoice;

    attempts = 0;

    printTitle("LOGIN TO YOUR ACCOUNT");

    printf(CYAN "Enter the details you used during registration.\n" RESET);

    while (attempts < 3)
    {
        readLine("\nUsername: ", username, MAX_USERNAME);

        if (strlen(username) == 0)
        {
            printf(RED "\nUsername cannot be empty.\n" RESET);
            continue;
        }

        /* Check whether the username exists first */

        if (!usernameExists(username))
        {
            printf(RED "\nThis account does not exist.\n" RESET);

            printf(YELLOW "\nWould you like to create an account?\n" RESET);
            printf(GREEN "  [1] Create an account\n" RESET);
            printf(CYAN "  [2] Try login again\n" RESET);

            readLine(YELLOW "Enter your choice: " RESET, input, 20);

            accountChoice = atoi(input);

            if (accountChoice == 1)
            {
                registerUser();
                return 0;
            }
            else if (accountChoice == 2)
            {
                printf(CYAN "\nPlease enter your login details again.\n" RESET);
                continue;
            }
            else
            {
                printf(RED "\nInvalid choice.\n" RESET);
                continue;
            }
        }

        readLine("Password: ", password, MAX_PASSWORD);

        file = fopen(USER_FILE, "r");

        if (file == NULL)
        {
            printf(RED "\nUnable to open account file.\n" RESET);
            return 0;
        }

        found = 0;

        while (fscanf(file, "%49s %99s",
                      temp.username,
                      temp.password) == 2)
        {
            if (strcmp(username, temp.username) == 0 &&
                strcmp(password, temp.password) == 0)
            {
                found = 1;
                break;
            }
        }

        fclose(file);

        if (found)
        {
            printf(GREEN BOLD "\nLogin successful!\n" RESET);

            printf(CYAN "Welcome, %s!\n" RESET, username);

            saveLog("A user logged in successfully.");

            return 1;
        }

        attempts++;

        printf(RED "\nIncorrect password.\n" RESET);

        printf(YELLOW
               "Please check your spelling. Passwords are case-sensitive.\n"
               RESET);

        printf("Attempts remaining: %d\n", 3 - attempts);

        saveLog("A failed login attempt occurred.");
    }

    printf(RED BOLD "\nToo many failed attempts!\n" RESET);

    printf(YELLOW "Access blocked for this session.\n" RESET);

    saveLog("Login blocked after three failed attempts.");

    return 0;
}

/* ================= MAIN MENU ================= */

void displayMenu(void)
{
    printTitle("CYBER SECURITY DASHBOARD");

    printf(GREEN BOLD "  Welcome to Cyber Cafe!\n\n" RESET);

    printf(WHITE "  [1] " CYAN "Password Strength Analyzer\n" RESET);

    printf(WHITE "  [2] " CYAN "Generate Strong Password\n" RESET);

    printf(WHITE "  [3] " CYAN "Phishing Message Checker\n" RESET);

    printf(WHITE "  [4] " CYAN "Cybersecurity Awareness Tips\n" RESET);

    printf(WHITE "  [5] " CYAN "View Activity History\n" RESET);

    printf(WHITE "  [6] " RED "Logout\n" RESET);

    printLine();

    printf(YELLOW BOLD "  Enter your choice: " RESET);
}

/* ================= PASSWORD ANALYZER ================= */

void passwordAnalyzer(void)
{
    char password[MAX_PASSWORD];

    printTitle("PASSWORD STRENGTH ANALYZER");

    readLine("Enter password to analyze: ",
             password, MAX_PASSWORD);

    if (strlen(password) == 0)
    {
        printf(RED "\nPassword cannot be empty.\n" RESET);
        return;
    }

    passwordSuggestions(password);

    saveLog("Password analyzer was used.");
}

/* ================= PASSWORD GENERATOR ================= */

void generatePassword(void)
{
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char lower[] = "abcdefghijklmnopqrstuvwxyz";

    char numbers[] = "0123456789";

    char special[] = "!@#$%^&*()-_=+?";

    char allCharacters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+?";

    char *password;

    char input[20];

    int length;
    int i;
    int j;
    char temp;

    printTitle("STRONG PASSWORD GENERATOR");

    printf("Choose password length between 8 and 50.\n");

    readLine("\nEnter password length: ", input, 20);

    length = atoi(input);

    if (length < 8 || length > 50)
    {
        printf(RED "\nInvalid length. Please enter 8 to 50.\n" RESET);
        return;
    }

    /* Allocate memory according to the required length */

    password = (char *)malloc((length + 1) * sizeof(char));

    if (password == NULL)
    {
        printf(RED "\nMemory allocation failed.\n" RESET);
        return;
    }

    /* Ensure all four character types are included */

    password[0] = upper[rand() % 26];

    password[1] = lower[rand() % 26];

    password[2] = numbers[rand() % 10];

    password[3] = special[rand() % (sizeof(special) - 1)];

    /* Fill remaining positions */

    for (i = 4; i < length; i++)
    {
        password[i] =
            allCharacters[rand() % (sizeof(allCharacters) - 1)];
    }

    password[length] = '\0';

    /* Shuffle generated password */

    for (i = length - 1; i > 0; i--)
    {
        j = rand() % (i + 1);

        temp = password[i];

        password[i] = password[j];

        password[j] = temp;
    }

    printf("\n");

    printLine();

    printf(GREEN BOLD "          YOUR PASSWORD IS READY!\n" RESET);

    printLine();

    printf(CYAN BOLD "\nGenerated Password: " RESET);

    printf(WHITE BOLD "%s\n" RESET, password);

    printf(YELLOW "\nKeep your password safe. Never share it.\n" RESET);

    free(password);

    saveLog("Password generator was used.");
}

/* ================= PHISHING CHECKER ================= */

void phishingChecker(void)
{
    char message[MAX_MESSAGE];
    char lowerMessage[MAX_MESSAGE];

    int i;
    int found;
    int count;

    /* 2D array containing suspicious keywords */

    char suspiciousWords[10][25] = {

        "urgent",
        "verify account",
        "click here",
        "password",
        "congratulations",
        "prize",
        "bank",
        "otp",
        "claim now",
        "limited time"
    };

    printTitle("PHISHING MESSAGE CHECKER");

    printf(CYAN "Paste a message to check for suspicious words.\n" RESET);

    readLine("\nEnter message: ", message, MAX_MESSAGE);

    if (strlen(message) == 0)
    {
        printf(RED "\nMessage cannot be empty.\n" RESET);
        return;
    }

    /* Convert message into lowercase */

    for (i = 0; message[i] != '\0'; i++)
    {
        lowerMessage[i] =
            (char)tolower((unsigned char)message[i]);
    }

    lowerMessage[i] = '\0';

    found = 0;
    count = 0;

    /* Scanning animation */

    printf("\n");

    printLine();

    printf(CYAN BOLD "          STARTING SECURITY SCAN...\n" RESET);

    waitBrief();

    printf(YELLOW "\n[1/4] Scanning message content...\n" RESET);

    waitBrief();

    printf(YELLOW "[2/4] Checking suspicious keywords...\n" RESET);

    waitBrief();

    printf(YELLOW "[3/4] Analyzing website links...\n" RESET);

    waitBrief();

    printf(YELLOW "[4/4] Generating security report...\n" RESET);

    waitBrief();

    printf(GREEN "\nScan completed!\n" RESET);

    printLine();

    printf(CYAN BOLD "              SCAN RESULTS\n" RESET);

    printLine();

    /* Search suspicious words */

    for (i = 0; i < 10; i++)
    {
        if (strstr(lowerMessage, suspiciousWords[i]) != NULL)
        {
            printf(RED "[!] Suspicious phrase: %s\n" RESET,
                   suspiciousWords[i]);

            found = 1;

            count++;
        }
    }

    /* Check suspicious links */

    if (strstr(lowerMessage, "http://") != NULL ||
        strstr(lowerMessage, "https://") != NULL ||
        strstr(lowerMessage, "www.") != NULL)
    {
        printf(RED "[!] Message contains a web link.\n" RESET);

        found = 1;

        count++;
    }

    printf("\n");

    if (found)
    {
        printLine();

        printf(RED BOLD "       POTENTIAL PHISHING MESSAGE!\n" RESET);

        printf(YELLOW "Warning signs detected: %d\n" RESET, count);

        printf("\nSafety suggestions:\n");

        printf("- Do not click unknown links.\n");

        printf("- Never share your password or OTP.\n");

        printf("- Verify the sender before replying.\n");

        printLine();
    }
    else
    {
        printLine();

        printf(GREEN BOLD "       NO LISTED WARNING SIGNS FOUND\n" RESET);

        printf(CYAN "The message may still require careful checking.\n" RESET);

        printLine();
    }

    saveLog("Phishing checker was used.");
}

/* ================= CYBERSECURITY TIPS ================= */

void cyberSecurityTips(void)
{
    int i;

    /* 2D array of cybersecurity tips */

    char tips[8][100] = {

        "Use unique passwords for different accounts.",

        "Never share your OTP or password.",

        "Avoid clicking links from unknown senders.",

        "Enable two-factor authentication.",

        "Keep your software and applications updated.",

        "Verify suspicious emails before responding.",

        "Use trusted websites for online activities.",

        "Avoid downloading files from unknown sources."
    };

    printTitle("CYBERSECURITY AWARENESS TIPS");

    printf(GREEN BOLD "          STAY SAFE ONLINE!\n\n" RESET);

    for (i = 0; i < 8; i++)
    {
        printf(GREEN "  %d. " RESET, i + 1);

        printf(WHITE "%s\n" RESET, tips[i]);
    }

    printf("\n");

    printLine();

    saveLog("Cybersecurity tips were viewed.");
}

/* ================= MAIN FUNCTION ================= */

int main(void)
{
    int choice;
    int menuChoice;
    int loggedIn;
    int sessionChoice;

    char input[20];

    srand((unsigned int)time(NULL));

    printWelcome();

    /* Main application loop */

    while (1)
    {
        loggedIn = 0;

        /* Registration and login menu */

        while (!loggedIn)
        {
            printf("\n");

            printLine();

            printf(CYAN BOLD "                 MAIN MENU\n" RESET);

            printLine();

            printf(GREEN "  [1] " RESET "Create New Account\n");

            printf(CYAN "  [2] " RESET "Login to Existing Account\n");

            printf(RED "  [3] " RESET "Exit Program\n");

            printLine();

            readLine(YELLOW "  Enter your choice: " RESET, input, 20);

            choice = atoi(input);

            switch (choice)
            {
                case 1:

                    registerUser();

                    pauseScreen();

                    break;

                case 2:

                    loggedIn = login();

                    if (!loggedIn)
                    {
                        pauseScreen();
                    }

                    break;

                case 3:

                    printf(GREEN "\nThank you for using Cyber Cafe!\n" RESET);

                    printf(CYAN "Stay safe online. Goodbye!\n" RESET);

                    return 0;

                default:

                    printf(RED "\nInvalid choice. Please try again.\n" RESET);

                    pauseScreen();
            }
        }

        /* Dashboard after successful login */

        do
        {
            displayMenu();

            readLine("", input, 20);

            menuChoice = atoi(input);

            switch (menuChoice)
            {
                case 1:

                    passwordAnalyzer();

                    pauseScreen();

                    break;

                case 2:

                    generatePassword();

                    pauseScreen();

                    break;

                case 3:

                    phishingChecker();

                    pauseScreen();

                    break;

                case 4:

                    cyberSecurityTips();

                    pauseScreen();

                    break;

                case 5:

                    showLog();

                    pauseScreen();

                    break;

                case 6:

                    printf(GREEN BOLD "\nYou have logged out successfully!\n" RESET);

                    saveLog("A user logged out.");

                    break;

                default:

                    printf(RED "\nInvalid option. Please select 1 to 6.\n" RESET);

                    pauseScreen();
            }

        } while (menuChoice != 6);

        /* Ask what to do after logout */

        printf("\n");

        printLine();

        printf(CYAN BOLD "                 LOGOUT MENU\n" RESET);

        printLine();

        printf(GREEN "  [1] " RESET "Login Again\n");

        printf(RED "  [2] " RESET "Exit Cyber Cafe\n");

        printLine();

        readLine(YELLOW "  Enter your choice: " RESET, input, 20);

        sessionChoice = atoi(input);

        if (sessionChoice == 1)
        {
            printf(CYAN "\nReturning to login menu...\n" RESET);
        }
        else if (sessionChoice == 2)
        {
            printf(GREEN "\nThank you for using Cyber Cafe!\n" RESET);

            printf(CYAN "Stay protected. Stay safe. Goodbye!\n" RESET);

            return 0;
        }
        else
        {
            printf(RED "\nInvalid choice. Returning to login menu.\n" RESET);
        }
    }

    return 0;
}

