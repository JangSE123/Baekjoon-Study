def main():
    croatia = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
    word = input()
    
    for str in croatia:
        word = word.replace(str, "*")
    
    print(len(word))
    
if __name__ == "__main__":
    main()