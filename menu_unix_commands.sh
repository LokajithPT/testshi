
while true
do
    echo "----------------------------------------"
    echo "      UNIX COMMANDS MENU"
    echo "----------------------------------------"
    echo "1) Show current date and time (date)"
    echo "2) List files in current directory (ls -l)"
    echo "3) Show current working directory (pwd)"
    echo "4) Display contents of a file (cat)"
    echo "5) Show first 10 lines of a file (head)"
    echo "6) Show last 10 lines of a file (tail)"
    echo "7) Search for a pattern in a file (grep)"
    echo "8) Show currently logged in users (who)"
    echo "9) Show current processes (ps)"
    echo "10) Send a message to all users (wall)"
    echo "11) Exit"
    echo "----------------------------------------"
    read -p "Enter your choice: " ch

    case "$ch" in
        1)
            echo "Current date and time:"
            date
            ;;
        2)
            echo "Listing files (long format):"
            ls -l
            ;;
        3)
            echo "Current working directory:"
            pwd
            ;;
        4)
            read -p "Enter file name: " file
            if [ -f "$file" ]; then
                echo "Contents of $file:"
                cat "$file"
            else
                echo "File does not exist."
            fi
            ;;
        5)
            read -p "Enter file name: " file
            if [ -f "$file" ]; then
                echo "First 10 lines of $file:"
                head "$file"
            else
                echo "File does not exist."
            fi
            ;;
        6)
            read -p "Enter file name: " file
            if [ -f "$file" ]; then
                echo "Last 10 lines of $file:"
                tail "$file"
            else
                echo "File does not exist."
            fi
            ;;
        7)
            read -p "Enter file name: " file
            if [ -f "$file" ]; then
                read -p "Enter pattern to search: " pattern
                echo "Lines containing '$pattern' in $file:"
                grep "$pattern" "$file"
            else
                echo "File does not exist."
            fi
            ;;
        8)
            echo "Users currently logged in:"
            who
            ;;
        9)
            echo "Current processes:"
            ps
            ;;
        10)
            read -p "Enter message to broadcast: " msg
            echo "$msg" | wall
            ;;
        11)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac
    echo # blank line
done
