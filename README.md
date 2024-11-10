# 🌐 Computer Networks Laboratory (CS39003) 🌐

Welcome to the **Computer Networks Laboratory** repository! This repository houses all the practical exercises, assignments, and projects completed as part of the Computer Networks course (**CS30003**).

## 🌟 Introduction

This repository contains the code and documentation for the laboratory sessions of the **Computer Networks** course. Each lab session focuses on different aspects of computer networking, including network protocols, simulations, and hands-on experiments.

## 💻 Lab Sessions

The lab sessions are organized into separate folders. Each folder contains:
- **Lab Instructions**: Detailed instructions for the lab session.
- **Source Code**: The code written during the lab session.
- **Documentation**: Additional documentation and notes.

<!--
## 📂 Problems Index

This section lists the problems covered in the **Computer Networks Laboratory**:

| **S.No.** | **Problem Statement**                                      | **Solution File**                      |
|-----------|-------------------------------------------------------------|----------------------------------------|
| **1**     | Understanding the OSI Model                                 | [Solution](./Lab1/problem1.md)         |
| **2**     | Basic Network Configuration                                 | [Solution](./Lab1/problem2.md)         |
| **3**     | Analyzing TCP/IP Layers                                     | [Solution](./Lab2/problem1.md)         |
| **4**     | Implementing a Simple Socket Program                        | [Solution](./Lab2/problem2.md)         |
| **5**     | Configuring Static Routing                                  | [Solution](./Lab3/problem1.md)         |
| **6**     | Exploring Dynamic Routing Protocols                         | [Solution](./Lab3/problem2.md)         |
| **7**     | Simulating Network Topology with Packet Tracer              | [Solution](./Lab4/problem1.md)         |
| **8**     | Performance Analysis of Network Links                       | [Solution](./Lab4/problem2.md)         |

> **Note**: Each problem folder contains the respective code, documentation, and detailed explanations.

---
-->
Feel free to explore the repository and get hands-on experience with computer networks. **Happy Networking!**

# Network Lab Sessions Index

## Lab Session 1 : Overview of C Programming

| **S.No.** | **Problem Statement**            | **Solution File**             |
|-----------|----------------------------------|-------------------------------|
| **1.1**     | WAP to swap 2 numbers both by call by value and call by address.                                      | [Solution](./Lab-Codes/1.1.c)|
| **1.2**     | WAP to declare a structure having data members & display its content.                                 | [Solution](./Lab-Codes/1.2.c)|
| **1.3**     | WAP to accept array of employee in structure & print them in sorted way.                              | [Solution](./Lab-Codes/1.3.c)|
| **1.4**     | WAP to accept 10 numbers using dynamic array & find sum & average of numbers.                         | [Solution](./Lab-Codes/1.4.c)|
| **1.5**     | WAP to enter a statement from console and write it to a file and read its content from the same file. | [Solution](./Lab-Codes/1.5.c)|

## Lab Session 2 : Basics of Socket Programming

| **S.No.** | **Problem Statement**            | **Solution File**             |
|-----------|----------------------------------|-------------------------------|
| **2.1**     | Write a simple datagram program to establish client server communication.        | [server](./Lab-Codes/2.1s.c) [client](./Lab-Codes/2.1c.c)|
| **2.2**     | Write a sender and receiver program in C by passing the IP address and the port number of each other through the command line arguments using connection less socket. Both of them will exchange messages with each other continuously. If any one of them will receive the “exit” message from the other end then both of them will close the connection. (Assume both the client and server are running with in the same host) ~ given in Lesson Plan           | [Receiver](./Lab-Codes/2.2r.c) <br><br> [Sender](./Lab-Codes/2.2s.c)|

## Lab Session 3 : Connection Oriented Socket Programming

| **S.No.** | **Problem Statement**            | **Solution File**             |
|-----------|----------------------------------|-------------------------------|
| **3.1**   | WRP to add two numbers & show their sum in client server model.  | [server](./Lab-Codes/3.1s.c) [client](./Lab-Codes/3.1c.c)|
| **3.2**   | WRP to swap two numbers in TCP | [server](./Lab-Codes/3.2s.c) [client](./Lab-Codes/3.2c.c)|
| **3.3**   | WRP in TCP for a number sent by the client to the server and check whether it is an Armstrong number or not. | [server](./Lab-Codes/3.3s.c) [client](./Lab-Codes/3.3c.c)|
| **3.4**   | WRP in TCP for an array of integer sent by the client to the server and return maximum, minimum, sum and average of all the numbers. | [server](./Lab-Codes/3.4s.c) [client](./Lab-Codes/3.4c.c)|
| **3.5**   | WRP in TCP to send a student structure having data members (roll,name,marks of subjets) to the server by the client and return sum of marks from the server and display on the client side. | [server](./Lab-Codes/3.5s.c) [client](./Lab-Codes/3.5c.c)|

## Lab Session 4

| **S.No.** | **Problem Statement**            | **Solution File**             |
|-----------|----------------------------------|-------------------------------|
| **7**     | Simulating Network Topology with Packet Tracer | [Solution](./Lab4/problem1.md)|
| **8**     | Performance Analysis of Network Links | [Solution](./Lab4/problem2.md)|



## ⚙️ Installation

To set up the environment for the lab exercises, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/abhinav9444/CN-Lab.git

2. Navigate to the Lab-Codes directory:

   Copy code from different Laboratory session and execute them on your local machine for implementation.
   ```sh
   cd .\CN-Lab\Lab-Codes\ 
   ```
3. Compile the sender and receiver programs using gcc:
   ```sh
   gcc sender.c -o sender
   gcc receiver.c -o receiver
   ```
4. First, run the receiver program:
   ```
   .\receiver.exe
   ```
5. Open another command prompt (cmd) or PowerShell and run the sender program:
   ```
   .\sender.exe
   ```
   
## 🤝 Contributing
Contributions are welcome! If you have any improvements or suggestions, please fork the repository, make your changes, and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.

-    Fork the Repository
-    Create your sub Branch (git checkout -b NewBranch/SubBranch)
-   Commit your Changes (git commit -m 'Add some SubBranch')
-   Push to the Branch (git push origin NewBranch/SubBranch)
-   Open a Pull Request

## 📄 License
Distributed under the MIT License. See [LICENSE](LICENSE) for more information.
