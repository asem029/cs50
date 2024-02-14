class Cat:
    def __init__(self,name,age,color,kind):
        self.name = name
        self.age = age
        self.color = color
        self.kind = kind
    def meow(self):
        print(f"I am {self.kind} cat,My name is {self.name},My age is {self.age},My color is {self.color}")

cat1 =Cat("lola","3","brown","himalayan")
cat1.meow()
print()
cat2 =Cat("topey","9","white","ragdol")
cat2.meow()