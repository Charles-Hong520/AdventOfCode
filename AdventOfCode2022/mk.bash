if [ -z "$1" ] 
then
	echo "No args provided in mk.bash"
	exit
elif[[ -d "./$1" ]]
	echo "$1 already exist silly" 
else
	mkdir "$1" && cp template.cpp "$1"/"$1"a.cpp && cp template.cpp "$1"/"$1"b.cpp && touch "$1"/"$1".txt "$1"/s.txt
fi
