import hashlib
import sys




def hash(content:str):
    return hashlib.sha256(content).hexdigest()



def hash_file(file_path:str)->(str, str):
    with open(rf'{file_path}', 'rb') as file:
        data = file.read()
        return (hash(data), data)





# main
def main():
    # read file path form the user
    options = sys.argv

    if len(options) > 1:
        result = hash_file(options[1])
        print(f"SHA256(hash={result[0]}, file={options[1]})")
    else:
        print("Pass File Path to Get SHA256 hash")
        print("Usage: python ./hash.py ./path_to_file")
    
    



# run
if __name__ == "__main__":
    main()
