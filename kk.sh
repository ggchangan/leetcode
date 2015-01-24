#! /bin/sh
#echo "Enter question name to be solved:"
#read name
name=$*
#echo $name
name=$(echo "$name"|sed 's/^\w\|\s\w/\U&/g'|sed 's/\s*//g')
#echo $name
mkdir $name
cd $name
#touch $name".cpp"
cat ../leetcode.cpp > $name".cpp"
vim $name".cpp"
