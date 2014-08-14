# https://www.codeeval.com/open_challenges/1/

# Classic FizzBuzz

# All easy problems I will try with bash as a means for learning bash.

while read line; do
	read A B N <<< $line
	
	if [[ -z $line ]]; then
		continue
	fi
	
	C=$((A * B))
	
	for n in $(seq 1 $N); do
		if ! (( n % C )); then
			printf "FB "
		elif ! (( n % A )); then
			printf "F "
		elif ! (( n % B )); then 
			printf "B "
		else
			printf "$n "
		fi
	done
	echo
done < $1

# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")
# <tmp>/source.sh: line 8: cannot create temp file for here-document: Permission denied
# <tmp>/source.sh: line 17: ((: n % C : division by 0 (error token is "C ")

# OK
# Nevermind.
# Ugh.
# At least I know it works fine on my own machine.
