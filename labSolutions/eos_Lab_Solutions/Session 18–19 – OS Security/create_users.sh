#!/bin/bash
# Creates two users and sets directory permissions.


# Create users
sudo useradd user1
sudo useradd user2

# Create a shared directory
sudo mkdir /home/shared_dir

# Set ownership and permissions
sudo chown user1:user1 /home/shared_dir
sudo chmod 770 /home/shared_dir

echo "Users and directory configured."