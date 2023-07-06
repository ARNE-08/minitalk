# minitalk
A communication program in the form of a client and server
The server will start first and print out PID, and client will recieve PID and string that we want to send to the server as parameter.

## How to run the code
```Makefile
make

./server
./client SERVER_PID STRING

---

Client can take text file as parameter by using $(cat FILENAME)
