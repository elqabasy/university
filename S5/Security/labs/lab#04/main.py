#!/bin/python




import hashlib



def hash(value):
    return hashlib.sha256(value.encode()).hexdigest()



def diff(a, b):
    return sum(c1 != c2 for c1, c2 in zip(a, b))


    




def main():
    a, b = "mahros", "ali"
    
    print(f"Result(msg={a}, hash={hash(a)})")
    print(f"Result(msg={b}, hash={hash(b)})")
    print(f"Diff({diff(hash(a), hash(b))})")



if __name__ == "__main__":
    main()





# import hashlib
# 
# 
# 
# with open("file.empty", "rb") as file:
#     file_hash = hashlib.sha256(file.read()).hexdigest()
# 
#     print(file_hash)
