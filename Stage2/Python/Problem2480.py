def main():
    dice1, dice2, dice3 = map(int, input().split())
    
    if dice1 == dice2 and dice2 == dice3:
        reward = 10000 + dice1 * 1000
    elif dice1 == dice2 or dice2 == dice3 or dice1 == dice3:
        sameValue = dice1 if (dice1 == dice2 or dice1 == dice3) else dice2
        reward = 1000 + sameValue * 100
    else:
        maxValue = max(dice1, dice2, dice3)
        reward = maxValue * 100
        
    print(reward)
    
if __name__ == "__main__":
    main()