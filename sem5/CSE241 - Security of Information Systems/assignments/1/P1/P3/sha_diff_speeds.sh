#!/bin/bash




COMPARE_FILE='ANY_FILE_USER_ENTER'



usage(){
	echo "Usage: ./sha_diff_speeds.sh file_path"
}


if [ -f "$1" ]; then
	echo "LoAdInG file $1..."
	COMPARE_FILE="$1"
else 
	echo "Sorry! We can't see any test file"
	usage
	exit 0
fi



main(){
	echo "Start Calculating Performance..."
	echo "Calculate[SHA256]"
	time sha256sum $COMPARE_FILE
	echo ""
	echo "Calculate[SHA512]"
	time sha512sum $COMPARE_FILE

	echo "DONE.. I suppose you now see the diff, man."
}


main "$@"
