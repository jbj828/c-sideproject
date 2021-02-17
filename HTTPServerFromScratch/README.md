# Build HTTP Server from scratch

## Implementing TCP

We need to implement the Transport Layer of HTTP which is TCP.  
To implement TCP, we have to learn TCP socket programming.

## What is socket?

A socket is the mechanism that most popular operating system provide to give programs access to the network. It allows messages to be sent and received between applications(unrelated processes) on different networked machines.

The sockets mechanism has been created to be independent of any specific type of network. IP, however, is by far the most dominant network and the most popular use of sockets.

## Programming with TCP/IP sockets

There are a few steps involved in using sockets:

1. Create the socket
2. Identify the socket
3. On the server, wait for an incoming connection
4. Send and receive messages
5. Close the socket
