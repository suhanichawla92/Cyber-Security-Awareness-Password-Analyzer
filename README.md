                                    # **CYBER CAFE**
                                    
## Cyber Security Awareness System

**Your Digital Safety Starts Here!**

A menu-driven cybersecurity awareness application developed using the C programming language as a Programming Fundamentals project.


 1. **Introduction**
    
Cyber Cafe – Cyber Security Awareness System is a console-based application designed to promote cybersecurity awareness and encourage safe online practices.

It provides interactive features that help users understand password security, generate strong passwords, identify potentially suspicious messages, and learn about common cybersecurity threats.

The project combines practical cybersecurity concepts with fundamental C programming techniques.

2. **Project Objectives**

- Promote cybersecurity awareness.
- Help users understand password strength.
- Generate passwords with different character types.
- Identify potentially suspicious messages.
- Provide useful online safety tips.
- Apply C programming concepts in a practical project.

 3. **Features**

The Cyber Cafe application provides the following features:

**User Authentication:** Account registration, login, and logout with a maximum of three incorrect  password attempts.

**Password Strength Analyzer:** Evaluates passwords using six security criteria and provides improvement suggestions.

**Password Generator:** Generates random passwords between 8 and 50 characters.

**Phishing Message Checker:** Detects predefined suspicious keywords and common link patterns.

**Cybersecurity Tips:** Displays eight tips to promote online safety.

**Activity Logging:** Maintains a record of important activities in security_log.txt.

**User Logout:** Allows users to end their current session.

**Login Again:** Allows users to log in again after logging out.

**Exit Program:** Provides an option to safely close the application.

**4. Technologies and Concepts Used**

**Programming Language:** C

**Header Files:**
- `stdio.h` – Input and output.
- `stdlib.h` – Memory allocation and random functions.
- `string.h` – String operations.
- `ctype.h` – Character checking.
- `time.h` – Time-related operations.

**Programming Concepts:**
- Variables and Data Types
- Conditional Statements
- Loops
- Functions
- Arrays and Strings
- Structures
- Pointers
- Dynamic Memory Allocation
- File Handling
- Random Number Generation

 **5. Working of the Application**

1. The application starts with a welcome screen and main menu.
2. Users can register a new account or log in.
3. After successful login, the main dashboard becomes available.
4. Users select their desired cybersecurity feature.
5. The program processes the input and displays the results.
6. Important activities are recorded in the activity log.
7. Users can log out, log in again, or exit the application.


 6. **Project Structure**

```text
Cyber-Cafe/
│
├── CyberCafe.c
├── users.txt
├── security_log.txt
└── README.md
```

**File Description:**
- CyberCafe.c – Contains the main C source code.
- users.txt – Stores registered user information.
- security_log.txt – Stores activity records.
- README.md – Contains project documentation.

 7. **How to Compile and Run**

The application can be compiled using GCC.

**Compile the program:**

```bash
gcc CyberCafe.c -o cybercafe
```

**Run on Windows:**

```bash
cybercafe.exe
```

**Run on Linux/macOS:**

```bash
./cybercafe
```


## 8. Test Cases

| Feature | Test Input | Expected Result |
|---|---|---|
| Registration | New username | Account created |
| Login | Correct credentials | Login successful |
| Login | Incorrect password | Remaining attempts displayed |
| Password Analyzer | `hello` | Weak |
| Password Analyzer | `Hello123` | Medium |
| Password Analyzer | `HelloWorld123!` | Strong |
| Password Generator | Length 12 | Generates 12-character password |
| Phishing Checker | Message containing "verify account" | Suspicious phrase detected |

*Note: These test cases represent expected results and should be verified by running the application.*

 9. **Screenshots**

The following screenshots illustrate the key features and functionality of the Cyber Cafe application.

**Welcome Screen and Main Menu**
<img width="686" height="352" alt="image" src="https://github.com/user-attachments/assets/6a67f94e-2f08-439f-8f0b-af408dcdf66c" />

**User Registration and Password Security Check**
<img width="975" height="774" alt="image" src="https://github.com/user-attachments/assets/b9cdfe5d-1d70-467c-be97-b54d4bcd7631" />

**User Login And Authentication**
<img width="975" height="578" alt="image" src="https://github.com/user-attachments/assets/f16d112b-2db8-49f4-8b25-294504c36188" />

**Password Strength Analyzer**
<img width="975" height="868" alt="image" src="https://github.com/user-attachments/assets/d1421b81-9957-4436-a356-f3350a2b3e46" />

**Password Generator**
<img width="975" height="871" alt="image" src="https://github.com/user-attachments/assets/2a270f50-eacd-44fa-b10f-7147e3e55cad" />

**Phishing Message Checker**
<img width="975" height="851" alt="image" src="https://github.com/user-attachments/assets/18338341-8bd9-40d2-ac21-77ad6c2957fc" />

 **Cybersecurity Awareness Tips**
 <img width="975" height="851" alt="image" src="https://github.com/user-attachments/assets/a540f268-ac36-42b1-b4de-5ae22f7dc603" />

**Activity Log**
<img width="975" height="1091" alt="image" src="https://github.com/user-attachments/assets/63b442ff-04f1-4a04-a32d-418745d7094f" />

**User Logout**
<img width="975" height="444" alt="image" src="https://github.com/user-attachments/assets/577cedef-2540-499d-938e-22594259e26b" />

**Exit Cyber Cafe**
<img width="975" height="387" alt="image" src="https://github.com/user-attachments/assets/604b10d2-e7a9-43b2-a34e-5f8f0f4ec88b" />


 10. **Project Information**

| Detail               | Description |
|---|---|
| Project Name         | Cyber Cafe |
| Project Title        | Cyber Security Awareness System |
| Course               | Programming Fundamentals |
| Programming Language | C |
| Application Type     | Console-Based Application |
| Interface            | Command Line Interface (CLI) |

---

<p align="center">

** CYBER CAFE**

*Think Before You Click. Stay Safe Online!*

**Cyber Security Awareness System**

</p>
