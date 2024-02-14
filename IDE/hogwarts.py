import csv
houses ={
        "Gryffindor":0,
        "Hufflepuff":0,
        "Ravenclaw":0,
        "Slytherin":0
}
    
with open("characters.csv","r") as file:
    r = csv.reader(file)
    next(r)
    for rew in r:
        houses[rew[1]]+=1
for home in houses:
    print(f"{home}:{houses[home]}")

  