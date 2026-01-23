while true
do
    echo "----------------------------------------"
    echo "      MENU DRIVEN SHELL SCRIPT"
    echo "----------------------------------------"
    echo "1. Display common student names from two files"
    echo "2. List files whose 2nd character is a digit and display 'like' with context"
    echo "3. List all files in your account ending with 'seg'"
    echo "4. Print number of subdirectories in current directory"
    echo "5. Exit"
    echo "----------------------------------------"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)
            echo "Enter first file name:"
            read file1
            echo "Enter second file name:"
            read file2

            if [ -f "$file1" ] && [ -f "$file2" ]; then
                echo "Common student names:"
                sort "$file1" "$file2" | uniq -d
            else
                echo "One or both files do not exist!"
            fi
            ;;
        2)
            echo "Files whose second character is a digit:"
            ls | grep '^.[0-9]'

            echo
            echo "Displaying lines containing 'like' with 3 lines before and after:"
            echo "Enter file name to search:"
            read searchfile

            if [ -f "$searchfile" ]; then
                grep -n -C 3 "like" "$searchfile"
            else
                echo "File does not exist!"
            fi
            ;;
        3)
            echo "Files ending with 'seg' in your account:"
            find ~ -type f -name "*seg" 2>/dev/null
            ;;
        4)
            echo "Number of subdirectories in current directory:"
            find . -maxdepth 1 -type d | wc -l
            ;;
        5)
            echo "Exiting program..."
            exit 0
            ;;
        *)
            echo "Invalid choice! Please try again."
            ;;
    esac
done
