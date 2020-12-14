#!/bin/zsh

while true
do
    Selection=$(zenity --list --radiolist --height=150 --width 300 --title="Image Editor settings" --text 'What do you want to change?' --hide-header --column "disk-cli" --column "Item" TRUE "Bright step" FALSE "Contrast step" FALSE "Frame anchor" FALSE "Circle anchor" FALSE "Rain granularity" FALSE "Kernel size")

    case $Selection in

        "Bright step")
            zenity --entry --text 'Enter bright step'
            echo b
            break
            ;;

        "Contrast step")
            zenity --entry --text 'Enter contrast step'
            echo c
            break
            ;;

        "Frame anchor")
            zenity --entry --text 'Enter frame anchor'
            echo f
            break
            ;;

        "Circle anchor")
            zenity --entry --text 'Enter circle anchor'
            echo o
            break
            ;;

        "Rain granularity")
            zenity --entry --text 'Enter rain granularity'
            echo g
            break
            ;;

        "Kernel size")
            zenity --entry --text 'Enter kernel size'
            echo k
            break
            ;;

        *)
            break;
            ;;
            
    esac
done