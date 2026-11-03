# UDP Client-Server Communication in C

## 📌 Project Description

This project demonstrates UDP (User Datagram Protocol) communication between a server and a client using socket programming in C.

The server waits for messages from a client, displays the received message, and sends a reply back to the client.

## 🚀 Features

* UDP socket communication.
* Server listens on port `5000`.
* Receives messages from clients.
* Sends replies to clients.
* Supports continuous message exchange.

## 🛠️ Technologies Used

* Programming Language: C
* Networking: UDP Socket Programming
* Libraries:

  * `stdio.h`
  * `string.h`
  * `stdlib.h`
  * `sys/socket.h`
  * `netinet/in.h`
  * `arpa/inet.h`
  * `unistd.h`

## 📂 Project Structure

text
UDP-Client-Server/
│
├── server.c
├── client.c
└── README.md


## ⚙️ How to Run

### Step 1: Compile the Server

bash
gcc server.c -o server


### Step 2: Run the Server

bash
./server


The server will start listening on port 5000.

### Step 3: Compile and Run the Client

bash
gcc client.c -o client
./client


**Note:** A separate UDP client program is required to communicate with this server.

## 💻 Example Output

### Server Side
text Socket connection successfully

Server is waiting...
Client: Hello Server
Server: Hello Client
Client: How are you?
Server: I am fine!


### Client Side

text
Client: Hello Server
Server: Hello Client
Client: How are you?
Server: I am fine!

## 📖 Concepts Learned

* UDP Socket Creation
* `socket()` system call
* `bind()` system call
* `recvfrom()` function
* `sendto()` function
* IP address and port configuration
* Client-server communication
