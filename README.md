# minitalk
A communication program in the form of a client and server
The server will start first and print out PID, and client will recieve PID and string that we want to send to the server as parameter.

## Features
- server file be able to receive signal from client file using 'signal'
- support UNICODE character

## How to run the code
```Makefile
make

./server
./client SERVER_PID STRING
```

Client can take text file as parameter by using $(cat FILENAME)

## Allowed function
Only use 'SIGUSR1' and 'SIGUSR2' for the signal
- write
- ft_printf and any equivalent YOU coded
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit
