#!/bin/bash




hash_file=./hashes


password="password"


hasher(){
	# -1 for md5 hash

	
	openssl passwd -1 "$password" > $hash_file
}



decrypt_using_john(){
	john $hash_file # we can user 10k word list in ../assets/file_name
	
}

main(){
	hasher

	decrypt_using_john	
}


main "$@"
