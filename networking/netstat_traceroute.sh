#!/bin/bash

echo "Pinging google.com..."
ping -c 4 google.com

echo "Tracing route to google.com..."
traceroute google.com

echo "Listing network connections..."
netstat -tuln
