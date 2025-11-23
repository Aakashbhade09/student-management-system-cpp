# student-management-system-cpp
C++ based Student Management System with login, file handling, and full CRUD operations for student records.
# 🎓 Student Management System (C++)

A simple and user-friendly **Student Management System** built in **C++**.
This project allows users to **Register, Login, and manage student records** using a console-based interface with color formatting.

---

## 📌 Features

### 🔐 **Authentication System**

* User Registration
* User Login
* Creates a separate file for each user to store student data

### 🧾 **Student Record Management**

✔ Add New Student
✔ Display All Students
✔ Search Student by Roll Number
✔ Edit Student Record
✔ Delete Student Record

### 💾 **File Handling**

* All data is saved in text files
* Automatically loads and saves records

### 🎨 **Colored Console UI**

* ANSI color codes for better visual experience

---

## 📂 Project Structure

```
student.cpp        # Main source code
username.txt       # Stores login details for each user
Full-Name01.txt    # Stores student data for that specific user
```

---

## ▶️ How to Run the Program

### **Using a C++ Compiler**

1. Open terminal / CMD
2. Navigate to project folder
3. Compile:

```
g++ student.cpp -o student
```

4. Run:

```
./student    (Linux/Mac)
student.exe  (Windows)
```

---

## 📘 User Flow

```
Start
 ├── Login
 │     ├── Correct → Main Menu
 │     └── Wrong → Try Again
 ├── Registration
 │     └── Creates user files
 └── Exit
```

---

## 🧠 Main Menu Operations

```
1 → Add Student
2 → Display Students
3 → Search Student
4 → Edit Student
5 → Delete Student
6 → Logout
```

---

## 🖥️ Console Preview (Example)

```
-------------------------------------
Enter 1 For Add Student
Enter 2 For Print all Student Records
Enter 3 For Search Student
Enter 4 For Edit Student Record
Enter 5 For Delete Student Record
Enter 6 For Logout
-------------------------------------
```

---

## 🛠️ Technologies Used

* **C++**
* File Handling
* OOP (Classes & Objects)
* STL (Vector, String)
* ANSI Color Codes

---

## 📌 Future Enhancements (Optional Ideas)

* Password hashing
* GUI version
* Database support (MySQL / SQLite)
* Export data to CSV

---

## 🙌 Author

Student Management System created by **Aakash** for academic/project purposes.

---

