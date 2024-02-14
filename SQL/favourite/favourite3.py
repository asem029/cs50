#counting
import csv
titles = {}
with open("Favorite TV Shows - Form Responses 1.csv","r")as file:
    reader =csv.DictReader(file)
    for row in reader:
        ##canonicalized
        title =row["title"].strip().upper()      
        
        
        if title not in titles:
            titles[title] =0
            
        titles[title] += 1

## anonymous fonction"lambda"
            

for title in sorted(titles, key=lambda title: titles[title] ,reverse =True) :
    print(title,titles[title])