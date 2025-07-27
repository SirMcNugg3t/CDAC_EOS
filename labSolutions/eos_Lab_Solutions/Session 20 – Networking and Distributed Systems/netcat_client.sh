#!/bin/bash
# TCP Client using netcat
echo "Sending message to localhost:12345"
echo "Hello from netcat client" | nc localhost 12345