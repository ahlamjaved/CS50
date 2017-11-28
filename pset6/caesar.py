import cs50
import sys

def main():

    #checks to see if user inputs only 2 arguments
    if len(sys.argv) != 2:

        print("Please give me valid key")

        exit(1)

    #once argv is checked for correct number of input, place in variable k to begin the cipher
    k = int (sys.argv[1])

    # make sure integer is not a negative value
    if k < 1:
        print("Please Try Again")
        sys.exit(1)

    print("plaintext: ", end = "")

    # ask user to input a string to cipher
    string = cs50.get_string()
    print("ciphertext: ", end = "")

    # the if- else if  condition determines if the character is upper or lower case then converts it based on k
    if string is not None:
        for i in range ( len(string)):
            c = 0

            if string[i].isupper():
                c = ((ord (string[i]) - 65 + k) % 26 )+ 65
                print(chr(c), end = "" )

            elif string[i].islower():
                c = ((ord(string[i]) - 97 + k) % 26) + 97
                print(chr(c), end = "")

            # if the character is neither upper.  or lower case i.e non letter character
            else:
                print(string[i] , end = "")

    print()

if __name__ == "__main__":
    main()