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

./pin word.utf8.txt $1>tmp
while read pinyin
do
jie $pinyin
done<tmp

