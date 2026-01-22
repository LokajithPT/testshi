#!/bin/bash
# Menu driven shell script to create, copy, rename, delete a file
# and check read/write permissions on a given file.

while true
do
    echo "----------------------------------------"
    echo "      FILE OPERATIONS MENU"
    echo "----------------------------------------"
    echo "1) Create a file"
    echo "2) Copy a file"
    echo "3) Rename (move) a file"
    echo "4) Delete a file"
    echo "5) Check file permissions (read/write/both)"
    echo "6) Exit"
    echo "----------------------------------------"
    read -p "Enter your choice: " ch

    case "$ch" in
        1)
            read -p "Enter file name to create: " file
            if [ -e "$file" ]; then
                echo "File '$file' already exists."
            else
                > "$file"
                echo "File '$file' created."
            fi
            ;;
        2)
            read -p "Enter source file name: " src
            if [ ! -f "$src" ]; then
                echo "Source file '$src' does not exist."
            else
                read -p "Enter destination file name: " dest
                cp "$src" "$dest"
                echo "File copied from '$src' to '$dest'."
            fi
            ;;
        3)
            read -p "Enter current file name: " old
            if [ ! -e "$old" ]; then
                echo "File '$old' does not exist."
            else
                read -p "Enter new file name: " new
                mv "$old" "$new"
                echo "File renamed from '$old' to '$new'."
            fi
            ;;
        4)
            read -p "Enter file name to delete: " file
            if [ ! -e "$file" ]; then
                echo "File '$file' does not exist."
            else
                rm "$file"
                echo "File '$file' deleted."
            fi
            ;;
        5)
            read -p "Enter file name to check permissions: " file
            if [ ! -e "$file" ]; then
                echo "File '$file' does not exist."
            else
                readable="no"
                writable="no"

                [ -r "$file" ] && readable="yes"
                [ -w "$file" ] && writable="yes"

                if [ "$readable" = "yes" ] && [ "$writable" = "yes" ]; then
                    echo "File '$file' has BOTH read and write permissions."
                elif [ "$readable" = "yes" ]; then
                    echo "File '$file' has ONLY read permission."
                elif [ "$writable" = "yes" ]; then
                    echo "File '$file' has ONLY write permission."
                else
                    echo "File '$file' has NEITHER read nor write permission for you."
                fi
            fi
            ;;
        6)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac
    echo # blank line
done
