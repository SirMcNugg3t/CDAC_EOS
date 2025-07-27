#!/bin/bash
mkfifo myfifo
echo "Hello via FIFO" > myfifo