import cs50

def main():

    # asking user for amount change due

    while True:
        print("O hai! How much change is owed?")
        change = cs50.get_float()

        # will continue to ask for amount due if change is less than zero
        if change >= 0.0:
            break

    # need to convert the change input into cents and round it
    cents = int(round(change*100))
    count = 0

    # To determine if quarters can be used
    while cents >= 25:
        count = count + 1
        cents = cents - 25
    # To determine if dimes can be used
    while cents >= 10:
        count = count + 1
        cents = cents - 10
    # To determine if nickles can be used
    while cents >= 5:
        count = count + 1
        cents = cents - 5
    # To determine if pennies can be used
    while cents > 0:
        count = count + 1
        cents = cents - 1
    print(count)
if __name__ == "__main__":
    main()