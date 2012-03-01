function jie
{
while read phrase firstChar firstPinyin lastChar lastPinyin 
do
if [  ${firstPinyin} ]
then
if [ $1 = ${firstPinyin} ]
then
echo ${phrase}
fi
#else
#echo $phrase first null
fi
done<phrase.txt
}

jie $1

