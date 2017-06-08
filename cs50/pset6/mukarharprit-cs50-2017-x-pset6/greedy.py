


import cs50

def main():
    while True:
        print(" How much change is owed?")
        amount = cs50.get_float()
        if amount >= 0:
            break
    
    c = 0
    cents = int(round(amount * 100))
    
    c += cents 
    cents %= 25
    
    c += cents 
    cents %= 10
    
    c += cents 
    cents %= 5
    
    c += cents
    
    print("{}".format(c))
    
if __name__ == "__main__":
    main()

    
